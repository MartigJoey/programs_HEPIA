from cmath import sqrt, exp
from operator import truediv
from stat import SF_APPEND
import sunau
from unicodedata import name
import matplotlib.pyplot as plt
from matplotlib.pyplot import subplots, show
import numpy as np
import csv
from colorama import Fore, Back
from scipy.stats import norm
import statistics

DICE_TYPE = 6

def import_csv(file):
    data = []
    with open(file, newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        i = 0
        for row in spamreader:
            if i == 0:
                i += 1
            else:
                res = list(map(int, row[0].split(',')))
                data.append(res)
    return data

def display_cumulative(values, ax, average, title):
    start = np.where(values != 0)[0][0]
    stop = len(values)
    yf = values.copy()
    yf = yf[yf != 0]
    xf = np.linspace(start, stop, len(yf), True)
    sum = 0
    for i in range(0, len(yf)):
        sum += yf[i] 
        yf[i] = sum / average

    ax.set_xlabel("valeur dé(s)")
    ax.set_ylabel("probabilité")
    ax.grid(True)
    ax.set_title(title)
    ax.plot(xf, yf, 'ro')

def display_gauss(values, ax, average): 
    yf = values.copy()
    
    min_val = max(yf)
    mid = len(yf) / 2

    for i in range(len(yf)):
        if min_val > yf[i] and yf[i] != 0:
            min_val = yf[i]

    # Plot between -10 and 10 with .001 steps.
    x_axis = np.arange(min_val, len(yf), 1)
    
    ax.plot(x_axis, norm.pdf(x_axis, mid, average), 'r-')

def display_distributive(values, ax, title): 
    yf = values.copy()
    xf = np.linspace(0, len(values), len(yf))

    ax.set_xlabel("valeur dé(s)")
    ax.set_ylabel("probabilité")
    ax.grid(True)
    ax.set_ylim([0, max(yf)+max(yf)/100*10])
    ax.set_title(title)
    ax.plot(xf, yf, 'bs')

def display_distributive_hist(values, ax, title):
    yf = values.copy()
    yf = yf[yf != 0]
    xf = np.linspace(0, len(values), len(yf))
    
    ax.set_xlabel("valeur dé(s)")
    ax.set_ylabel("probabilité")
    ax.grid(True)
    ax.set_ylim([0, max(yf)+max(yf)/100*10])
    ax.set_title(title)
    ax.bar(xf, yf)

def histogramme(values, nb_die, ax, title):
    yf = values.copy()
    bar_width = 0.2
    for i in range(len(yf)):
        yf[i] = (2 * yf[i])  / (nb_die+1)
    vmin = min(yf)
    vmax = max(yf)
    interval = 20
    int_width = (vmax - vmin) / interval
    nb_bins = 33
    bins_interval_x = [0]*nb_bins
    count_smaller = [0]*nb_bins
    bins_val_y = [0]*nb_bins

    for i in range(0, nb_bins):
        if i == 0:
            bins_interval_x[i] = vmin
        else:
            bins_interval_x[i] = round(bins_interval_x[i-1] + int_width, 2)

        count_smaller[i] = sum(j <= bins_interval_x[i] for j in yf)
        bins_val_y[i] = count_smaller[i] - count_smaller[i - 1] if i > 0 else count_smaller[i]
   
    limit_x_max = nb_bins
    for i in reversed(range(0, len(bins_interval_x))):
        if bins_val_y[i] != 0:
            limit_x_max = bins_interval_x[i] + bar_width
            break

    limit_x_min = nb_bins
    for i in range(0, len(bins_interval_x)):
        if bins_val_y[i] != 0:
            limit_x_min = bins_interval_x[i] - bar_width
            break
    
    ax.grid(True)
    ax.set_xlim([limit_x_min, limit_x_max])
    ax.set_title(title)
    ax.bar(bins_interval_x, bins_val_y, width=bar_width)

def display(name, stats, average, variance, mediane, ecart_type):
    print(f"{Fore.GREEN}{name}{Fore.WHITE} \n")

    if len(stats) < 10:
        print("-" * len(stats)*22)
        for i in range(0, len(stats)):
            print("{: >14}{}{: >15} |".format(Back.BLACK, i+1, Back.BLACK), end="")
        print("\n" + "-" * len(stats)*22)
        for stat in stats:
            print("{: >20} |".format(stat), end="")
        print("\n" + "-" * len(stats)*22 + "\n")
    else:
        print("-"*25)
        for i in range(0, len(stats)):
            print("{: >5} | {: >5}".format(i+1, stats[i]))
            print("-"*15)

    print(f"avg: {average}\n")
    print(f"médiane: {mediane}\n")
    print(f"variance: {variance}\n")
    print(f"écart-type: {ecart_type}\n")

def throw_proba(nb_die, values, name, ax_dis, ax_cum, ax_hist, ax_dis_hist):
    # INIT
    # REGULAR
    stats = np.zeros((nb_die, DICE_TYPE))
    average = np.zeros((nb_die))
    variance = np.zeros((nb_die))
    yf = np.array([[values[i][0] for i in range(len(values))]])
    yf_size = np.size(yf, 1)
    mediane = np.zeros((nb_die))
    ecart_type = np.zeros((nb_die))

    # SUM
    yf_sum = np.zeros((yf_size))
    stats_sum = np.zeros((nb_die*DICE_TYPE))
    average_sum = 0
    variance_sum = 0
    mediane_sum = 0
    ecart_type_sum = 0

    # Récupère les valeurs de values et retire la première colonne
    for j in range(1, nb_die + 1):
        yf_tmp = [values[i][j] for i in range(len(values))]
        yf = np.vstack([yf, yf_tmp])

    # Calcul les statistiques pour chaque valeur du dé et la moyenne
    
    for i in range(1, nb_die + 1):
        for j in range(0, yf_size):
            stats[i-1][yf[i][j]-1] += yf[i][j]
            yf_sum[j] += yf[i][j]
        yf[i-1].sort()
        stats[i-1] = [(stats[i-1][k] / yf_size) / (k + 1) for k in range(DICE_TYPE)]
        average[i-1] = np.sum(yf, 1)[i] / yf_size

    stats = np.sum(stats, 0) / nb_die
    for i in range(0, yf_size):
        stats_sum[int(yf_sum[i]-1)] += 1

    stats_sum = stats_sum / yf_size

    # AVERAGE
    average = np.sum(average, 0) / nb_die
    average_sum = np.sum(yf_sum, 0) / np.size(yf, 1)
    
    # Variance
    for i in range(1, nb_die + 1):
        for j in range(0, len(yf[i])):
            variance[i-1] += pow(yf[i][j] - average, 2)
    
    for i in range(0, len(yf_sum)):
        variance_sum += pow(yf_sum[i] - average_sum, 2)

    variance /= np.size(yf, 1)
    variance_sum /= np.size(yf, 1)

    # Médiane
    for i in range(0, nb_die):
        if yf_size % 2 == 0:
            mediane[i] = (yf[i+1][yf_size // 2] + yf[i+1][yf_size // 2]) / 2
            mediane_sum = (yf_sum[yf_size // 2] + yf_sum[yf_size // 2]) / 2
        else:
            mediane[i] = yf[i+1][yf_size // 2]
            mediane_sum = yf_sum[yf_size // 2]
    
    # Écart-type
    for i in range(0, nb_die):
        ecart_type[i] = sqrt(variance[i]).real
    
    ecart_type_sum = sqrt(variance_sum).real

    # Affichage
    display(name, stats, average, variance, mediane, ecart_type)
    display(name + " somme", stats_sum, average_sum, variance_sum, mediane_sum, ecart_type_sum)

    display_distributive_hist(stats, ax_dis_hist, name + " distributive")
    display_distributive(stats_sum, ax_dis, name + " distributive")
    display_gauss(stats_sum, ax_dis, average)
    display_cumulative(stats_sum, ax_cum, average, name + " cumulative")
    histogramme(yf_sum, nb_die, ax_hist, name + " histogramme")

def get_nb_occurences(die_value, res_value, nb_die, sum_for, has_value):
    sum_has_both = 0
    sum_has_value = 0
    sum = 0
    for i in range(1, DICE_TYPE + 1):
        if nb_die > 1:
            res_shv, res_shb, res_s = get_nb_occurences(die_value, res_value, nb_die - 1, sum_for + i, i == die_value or has_value)
            sum_has_value = sum_has_value + res_shv
            sum_has_both = sum_has_both + res_shb
            sum = sum + res_s
        else:
            if (has_value or i == die_value):
                if (sum_for + i) == res_value:
                    sum_has_both = sum_has_both + 1
                sum_has_value = sum_has_value + 1
            sum = sum + 1

    return sum_has_value, sum_has_both, sum

def proba_to_get_if_one_die(die_value, res_value):
    sum_has_value, sum_has_both, sum = get_nb_occurences(die_value, res_value, 4, 0, False)
    print(f"{sum_has_both}/{sum} / {sum_has_value}/{sum}")
    return (sum_has_both / sum) / (sum_has_value / sum) * 100

def stats_to_get_if_one_die(values, res_value, die_value):
    nb_die = np.size(values, 1)
    sum_has_res_and_value = 0
    sum_has_res = 0
    sum_has_value = 0
    for j in range(0, np.size(values, 0)):
        sum = 0
        has_die_value = False
        for i in range(1, nb_die):
            if values[j][i] == die_value:
                has_die_value = True
            sum = sum + values[j][i]
        if sum == res_value and has_die_value:
            sum_has_res_and_value = sum_has_res_and_value + 1
        
        if sum == res_value and not has_die_value:
            sum_has_res = sum_has_res + 1
        
        if has_die_value:
            sum_has_value = sum_has_value + 1
    
    if sum_has_res == 0:
        return sum_has_res_and_value

    return sum_has_res_and_value / sum_has_value * 100

            

values1 = import_csv('lance1.csv')
values2 = import_csv('lance2.csv')
values3 = import_csv('lance3.csv')
values4 = import_csv('lance4.csv')

fig1, (ax1, ax2) = subplots(2, 2)
throw_proba(1, values1, "lancé 1", ax1[0], ax2[0], ax1[1], ax2[1])

fig2, (ax1, ax2) = subplots(2, 2)
throw_proba(2, values2, "lancé 2", ax1[0], ax2[0], ax1[1], ax2[1])

fig3, (ax1, ax2) = subplots(2, 2)
throw_proba(3, values3, "lancé 3", ax1[0], ax2[0], ax1[1], ax2[1])

fig4, (ax1, ax2) = subplots(2, 2)
throw_proba(4, values4, "lancé 4", ax1[0], ax2[0], ax1[1], ax2[1])

die_value = 5
sum = 17
print(f"Statistics to get {sum} if one die equals {die_value} {stats_to_get_if_one_die(values4, sum, die_value)} %")
print(f"Probability to get {sum} if one die equals {die_value} {proba_to_get_if_one_die(die_value, sum)} %")

show()
from cmath import sqrt
from unicodedata import name
import matplotlib.pyplot as plt
from matplotlib.pyplot import subplots, show
import numpy as np
import csv
from colorama import Fore, Back

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

    ax.grid(True)
    ax.set_title(title)
    ax.plot(xf, yf, 'ro')

def display_distributive(values, ax, title): 
    yf = values.copy()
    xf = np.linspace(0, len(values), len(yf))

    ax.grid(True)
    ax.set_ylim([0, max(yf)+max(yf)/100*10])
    ax.set_title(title)
    ax.plot(xf, yf, 'bs')

def display_distributive_hist(values, ax, title):
    yf = values.copy()
    yf = yf[yf != 0]
    xf = np.linspace(0, len(values), len(yf))
    
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

def throw_proba(nb_die, values, name, ax_dis, ax_cum, ax_hist):
    # INIT
    # REGULAR
    stats = np.zeros((nb_die, 6))
    average = np.zeros((nb_die))
    variance = np.zeros((nb_die))
    yf = np.array([[values[i][0] for i in range(len(values))]])
    yf_size = np.size(yf, 1)
    mediane = np.zeros((nb_die))
    ecart_type = np.zeros((nb_die))

    # SUM
    yf_sum = np.zeros((yf_size))
    stats_sum = np.zeros((nb_die*6))
    average_sum = 0
    variance_sum = 0
    mediane_sum = 0
    ecart_type_sum = 0

    # Récupère les valeurs de values et retire la première colonne
    for j in range(1, nb_die + 1):
        yf_tmp = [values[i][j] for i in range(len(values))]
        yf = np.vstack([yf, yf_tmp])

    # Calcul les sttatistiques pour chaque valeur du dé et la moyenne
    
    for i in range(1, nb_die + 1):
        for j in range(0, yf_size):
            stats[i-1][yf[i][j]-1] += yf[i][j]
            yf_sum[j] += yf[i][j]
        yf[i-1].sort()
        stats[i-1] = [(stats[i-1][k] / yf_size) / (k + 1) for k in range(6)]
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

    display_distributive(stats_sum, ax_dis, name + " distributive")
    display_cumulative(stats_sum, ax_cum, average, name + " cumulative")
    histogramme(yf_sum, nb_die, ax_hist, name + " histogramme")

values1 = import_csv('lance1.csv')
values2 = import_csv('lance2.csv')
values3 = import_csv('lance3.csv')
values4 = import_csv('lance4.csv')

fig, (ax1, ax2, ax3) = subplots(3, 4)

throw_proba(1, values1, "lancé 1", ax1[0], ax2[0], ax3[0])
throw_proba(2, values2, "lancé 2", ax1[1], ax2[1], ax3[1])
throw_proba(3, values3, "lancé 3", ax1[2], ax2[2], ax3[2])
throw_proba(4, values4, "lancé 4", ax1[3], ax2[3], ax3[3])

show()
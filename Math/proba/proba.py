import matplotlib.pyplot as plt
from matplotlib.pyplot import subplots, show
import numpy as np
import csv

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

def display_cumulative(nb_die, values, ax, average, title):
    yf = values.copy()
    xf = np.linspace(0, 6, len(yf))
    sum = 0
    for i in range(0, len(yf)):
        sum += yf[i] 
        yf[i] = sum / average

    ax.set_title(title)
    ax.plot(xf, yf)

def display_distributive(nb_die, values, ax, title): 
    yf = values.copy()
    xf = np.linspace(0, 6, len(yf))

    
    ax.set_ylim([0, max(yf)+0.1])
    ax.set_title(title)
    ax.plot(xf, yf)

def throw_proba(nb_die, values, name, ax_dis, ax_cum):
    yf = np.array([[values[i][0] for i in range(len(values))]])
    for j in range(1, nb_die + 1):
        yf_tmp = [values[i][j] for i in range(len(values))]
        yf = np.vstack([yf, yf_tmp])

    proba = np.zeros((nb_die, 6))
    average = np.zeros((nb_die))
    for i in range(1, nb_die + 1):
        for j in range(0, len(yf[i])):
            proba[i-1][yf[i][j]-1] += yf[i][j]

        proba[i-1] = [(proba[i-1][k] / np.size(yf, 1)) / (k + 1) for k in range(6)]
        average[i-1] = np.sum(yf, 1)[i] / np.size(yf, 1)

    proba = np.sum(proba, 0) / nb_die
    average = np.sum(average, 0) / nb_die

    print(f"{name} \nproba:{proba}   \navg:{average}\n")
    display_distributive(nb_die, proba, ax_dis, name + " distributive")
    display_cumulative(nb_die, proba, ax_cum, average, name + " cumulative")

values1 = import_csv('lance1.csv')
values2 = import_csv('lance2.csv')
values3 = import_csv('lance3.csv')
values4 = import_csv('lance4.csv')

fig, (ax1, ax2) = subplots(2, 4)

throw_proba(1, values1, "lancé 1", ax1[0], ax2[0])
throw_proba(2, values2, "lancé 2", ax1[1], ax2[1])
throw_proba(3, values3, "lancé 3", ax1[2], ax2[2])
throw_proba(2, values4, "lancé 4", ax1[3], ax2[3])


#display_fourier(yf, ax1[1], "menfou")
#display_fourier(yf, ax2[1], "plus palu")

#x = np.linspace(0, 2 * np.pi, 200)
#y = np.sin(x)
#
#fig, ax = plt.subplots()
#ax.plot(x, y)
#plt.show()
show()
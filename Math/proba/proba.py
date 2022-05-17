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

def display_cumulative(values, ax, average, title):
    yf = values.copy()
    xf = np.linspace(0, 6, len(yf))
    sum = 0
    for i in range(0, len(yf)):
        sum += yf[i] 
        yf[i] = sum / average

    ax.set_title(title)
    ax.plot(xf, yf)

def display_distributive(values, ax, title): 
    yf = values.copy()
    xf = np.linspace(0, 6, len(yf))

    ax.set_title(title)
    ax.plot(xf, yf)

values1 = import_csv('lance1.csv')
values2 = import_csv('lance2.csv')
values3 = import_csv('lance3.csv')
values4 = import_csv('lance4.csv')

fig, (ax1, ax2) = subplots(2, 2)

yf = [values1[i][1] for i in range(len(values1))]
proba = [0]*(6)
for i in range(0, len(yf)):
    proba[yf[i]-1] += yf[i]

proba = [proba[i] / len(yf) for i in range(len(proba))]

average = sum(yf) / len(yf)

display_distributive(proba, ax1[0], "lancé 1 distributive")
display_cumulative(proba, ax2[0], average, "lancé 1 cumulative")
#display_fourier(yf, ax1[1], "menfou")
#display_fourier(yf, ax2[1], "plus palu")

#x = np.linspace(0, 2 * np.pi, 200)
#y = np.sin(x)
#
#fig, ax = plt.subplots()
#ax.plot(x, y)
#plt.show()
show()
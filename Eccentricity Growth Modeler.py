import numpy as np
import csv
import matplotlib.pyplot as plt

t7=[]
e7=[]; K=[];a7=[];res_a7=[]; e_f7=[]
with open('E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-Count-0.3_results_COM/bh-Count-0.3_results_combined-eccentr.dat','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = '\t')
    for row in plots:
        if float(row[0]) >= 20.0:
            t7.append(float(row[0]))
            e7.append(float(row[6]))
            a7.append(1/float(row[7]))
            res_a7.append(float(row[7]))

m, b = np.polyfit(t7, res_a7, 1)

e_f7.append(e7[0])

for i in range(1,len(t7)):
    de = (e_f7[i-1] * ((1 - e_f7[i-1]**2)**0.731) * (0.265+0.230*e_f7[i-1]))*a7[i-1]*m*(t7[i]-t7[i-1])
    e_f7.append(e_f7[i-1]+de)


t6=[];e6=[];a6=[];res_a6=[]; e_f6=[]
with open ('E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-Co-0.3_results_COM/bh-Co-0.3_results_combined-eccentr.dat','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = '\t')
    for row in plots:
        if float(row[0]) >= 20:
            t6.append(float(row[0]))
            e6.append(float(row[6]))
            a6.append(1/float(row[7]))
            res_a6.append(float(row[7]))

m,b = np.polyfit(t6,res_a6,1)
  
e_f6.append(e6[0])

for i in range(1,len(t6)):
    de = (e_f6[i-1] * ((1 - e_f6[i-1]**2)**0.731) * (0.265+0.230*e_f6[i-1]))*a6[i-1]*m*(t6[i]-t6[i-1])
    e_f6.append(e_f6[i-1]+de)

    
t2=[];e2=[];a2=[];res_a2=[]; e_f2=[]
with open ('E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-60-count_results.dat','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = '\t')
    for row in plots:
        if float(row[0]) >= 20:
            t2.append(float(row[0]))
            e2.append(float(row[6]))
            a2.append(1/float(row[7]))
            res_a2.append(float(row[7]))

m,b = np.polyfit(t2,res_a2,1)
  
e_f2.append(e2[0])

for i in range(1,len(t2)):
    de = (e_f2[i-1] * ((1 - e_f2[i-1]**2)**0.731) * (0.265+0.230*e_f6[i-1]))*a2[i-1]*m*(t2[i]-t2[i-1])
    e_f2.append(e_f2[i-1]+de)
                          
plt.ylim(0,1)
plt.ylabel('$eccentricity$',fontsize=20)
plt.xlabel('$time$',fontsize=20)

plt.plot(t6,e6, 'g',lw = 3, label ="$B_{0}$ - N-body")
plt.plot(t6,e_f6,'m',lw = 3, label ="$B_{0}$ - Semi-analytical model")

plt.plot(t2,e2, 'navy',lw = 3, label ="$A_{120}$ - N-body")
plt.plot(t2,e_f2,'maroon',lw = 3, label ="$A_{120}$ - Semi-analytical model")

plt.plot(t7,e7, 'b',lw = 3, label ="$B_{180}$ - N-body")
plt.plot(t7,e_f7,'r',lw = 3, label ="$B_{180}$ - Semi-analytical model")



plt.legend(loc='center right', fontsize = 15)
plt.show()

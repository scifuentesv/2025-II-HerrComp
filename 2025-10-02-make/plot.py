import matplotlib.pyplot as plt 
import numpy as np 

n,sumup,sumdown,diff = np.loadtxt("data.txt", unpack=True)
fig, ax = plt.subplots()
ax.plot(n,diff,"-o",label="RelDiff")
ax.legend()
ax.set_xscale('log')
ax.set_yscale('log')
fig.savefig("fig.pdf")
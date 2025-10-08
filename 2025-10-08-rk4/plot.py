import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D 

t,x,y,z = np.loadtxt("data.txt", delimiter=",", unpack=True)
fig = plt.figure(figsize=(14, 10))
ax = fig.add_subplot(111, projection='3d')
ax.plot(x, y, z, linewidth=0.6, color="red")
ax.set_xlabel('x', fontsize=14)
ax.set_ylabel('y', fontsize=14)
ax.set_zlabel('z', fontsize=14)
ax.set_title(r'Lorentz attractor ($\sigma=10,\ \rho=28,\ \beta=8/3$)', fontsize=18, pad=20)
fig.savefig("fig.pdf", format="pdf")

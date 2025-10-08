import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401

t,x,y,z = np.loadtxt("data.txt", delimiter=",", unpack=True)
print(x,y,z)
fig = plt.figure(figsize=(7, 5))
ax = fig.add_subplot(111, projection='3d')
ax.plot(x, y, z, linewidth=0.6)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title(r'Lorenz attractor ($\sigma=10,\ \rho=28,\ \beta=8/3$)')
fig.savefig("fig.pdf", format="pdf")
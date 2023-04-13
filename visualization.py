import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

filename = "ray.txt"

origins = []
directions = []

def plt_sphere(list_center, list_radius, ax):
  for c, r in zip(list_center, list_radius):

    # draw sphere
    u, v = np.mgrid[0:2*np.pi:50j, 0:np.pi:50j]
    x = r*np.cos(u)*np.sin(v)
    y = r*np.sin(u)*np.sin(v)
    z = r*np.cos(v)
    ax.plot_surface(x-c[0], y-c[1], z-c[2], color=np.random.choice(['g','b']), alpha=0.5*np.random.random()+0.5)

with open(filename, "r") as f:
    for line in f:
        parts = line.strip().split(" -- ")
        origin = parts[1].strip("()").split(", ")
        direction = parts[2].strip("direction: ()").split(", ")
        origin = [float(x) for x in origin]
        direction = [float(x) for x in direction]
        origins.append(origin)
        directions.append(direction)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# plt_sphere([(0, 3, 0)], [3], ax)

for i in range(len(origins)):
    origin = origins[i]
    direction = directions[i]
    ax.quiver(origin[0], origin[1], origin[2], direction[0], direction[1], direction[2], length=1, normalize=True)

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Vectors')
plt.show()

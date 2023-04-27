import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Read in the text file
data = np.loadtxt('delme.txt')

# Split the data into separate arrays for x, y, z coordinates and origins
x_coords, y_coords, z_coords, x_origins, y_origins, z_origins = np.split(data, 6, axis=1)

# Create a new figure and set up a 3D axis
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the vectors as lines from their origins to their endpoints
ax.quiver(x_origins, y_origins, z_origins, x_coords, y_coords, z_coords, length=1)

# Set the axis labels and limits
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_xlim([-1, 1])
ax.set_ylim([-1, 1])
ax.set_zlim([-1, 1])

# Save the figure
plt.savefig('3d_vectors.png')

# Create two new figures and set up 2D axes for each of the x-y and x-z planes
fig_xy = plt.figure()
ax_xy = fig_xy.add_subplot(111)
fig_xz = plt.figure()
ax_xz = fig_xz.add_subplot(111)

# Plot the x-y and x-z projections of the vectors as lines
ax_xy.quiver(x_origins[:,0], y_origins[:,0], x_coords[:,0], y_coords[:,0], angles='xy', scale_units='xy', scale=1)
ax_xz.quiver(x_origins[:,0], z_origins[:,0], x_coords[:,0], z_coords[:,0], angles='xy', scale_units='xy', scale=1)

# Set the axis labels and limits
ax_xy.set_xlabel('X')
ax_xy.set_ylabel('Y')
ax_xy.set_xlim([-1, 1])
ax_xy.set_ylim([-1, 1])
ax_xz.set_xlabel('X')
ax_xz.set_ylabel('Z')
ax_xz.set_xlim([-1, 1])
ax_xz.set_ylim([-1, 1])

# Save the figures
fig_xy.savefig('x-y_vectors.png')
fig_xz.savefig('x-z_vectors.png')

# Show the plots
plt.show()

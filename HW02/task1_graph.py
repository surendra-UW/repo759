import matplotlib.pyplot as plt

# Initialize empty lists to store x and y values
t = []
time = []

# Open the file and read line by line
with open('task1c.out', 'r') as file:
    for line in file:
        
        x, y = line.split()
        # Convert x and y to float and append to the lists
        t.append(1<<int(x))
        time.append(float(y))

# Plot the graph
plt.plot(t, time, marker='o', linestyle='-')
plt.xlabel('n')
plt.ylabel('Time in ms')
plt.title('array length vs time in ms')
plt.grid(True)
plt.show()
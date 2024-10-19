import matplotlib.pyplot as plt

def extract_values_from_file(file_path):
    values = []
    with open(file_path, 'r') as file:
        lines = file.readlines()
        
        # Extract every third line (index starts from 0, so 2 means the third line)
        for i in range(2, len(lines), 3):  # Start at index 2, step by 3
            try:
                # Assuming each third line contains a numeric value
                value = float(lines[i].strip())  # Convert the line to a float (or int if needed)
                values.append(value)
            except ValueError:
                print(f"Skipping line {i+1}: {lines[i].strip()} (not a valid number)")
    
    return values

def plot_values(values):
    # Create a plot for the extracted values
    plt.plot(values, marker='o')
    plt.title("Time Taken by msort vs Threshold")
    plt.xlabel("Threshold in power of 2")
    plt.ylabel("Execution Time (ms) of msort function")
    plt.grid(True)
    plt.show()

values = extract_values_from_file('task3a.out')
plot_values(values)
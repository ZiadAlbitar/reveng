import pandas as pd
import matplotlib.pyplot as plt

# Replace 'data.txt' with your file path
file_path = 'reading-data/data.txt'

# Read the data (assuming it's comma-separated)
df = pd.read_csv(file_path)

# Plotting
plt.figure(figsize=(8,5))
plt.plot(df['Wavenumber'], df['Intensity'], marker='o', linestyle='-')
plt.xlabel('Wavenumber')
plt.ylabel('Intensity')
plt.title('Intensity vs Wavenumber')
plt.grid(True)
plt.show()
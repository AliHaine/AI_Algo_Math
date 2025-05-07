import matplotlib.pyplot as plt
import numpy as np
import csv

rows = []

try:
    with open('./data.csv') as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            convert_rows = [int(values) for values in row]
            rows.append(convert_rows)
        m = len(rows)
except FileNotFoundError:
    print("File not found")
    exit(1)

points = np.array(rows)
plt.plot(points[:, 1], points[:, 0], 'o')
plt.ylabel('milleage')
plt.xlabel('price')

#plt.plot(np.array([1, 20]), np.array([4000, 1000]), 'r')



plt.show()
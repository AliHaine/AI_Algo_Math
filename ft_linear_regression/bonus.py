import matplotlib.pyplot as plt
import numpy as np
import csv

rows = []
t0 = 0
t1 = 0
max_km = 0
max_price = 0
precision = 0

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

try:
    with open('./result.txt') as file:
        line = file.readline().split(',')
        try:
            t0 = float(line[0])
            t1 = float(line[1])
            max_km = float(line[2])
            max_price = float(line[3])
            precision = float(line[4])
        except:
            print('Invalid results')
            exit(1)
except FileNotFoundError:
    print("File not found")
    exit(1)

points = np.array(rows)
plt.scatter(points[:, 0], points[:, 1], label='Data')
plt.xlabel('milleage')
plt.ylabel('price')

x_vals = [row[0] for row in rows]
predicted_y = [(t0 + t1 * (x / max_km)) * max_price for x in x_vals]
plt.plot(x_vals, predicted_y, color='red', label='Regression line')

plt.legend()
plt.show()

print(f"Precision (RMSE) percentage error: {precision}%")

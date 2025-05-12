import matplotlib.pyplot as plt
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
            mae = line[4]
            rmse = line[5]
            rmse_percent = float(line[6])
            r_squared = float(line[7])
        except:
            print('Invalid results')
            exit(1)
except FileNotFoundError:
    print("File not found")
    exit(1)

print(f"Default precision result: {mae}")
print(f"Precision with the formula Root mean square deviation (RMSE) error: {rmse}")
print(f"Precision with the formula Root mean square deviation (RMSE) percentage error: {rmse_percent}%")
print(f"Precision with the formula Coefficient of Determination (R²) : {r_squared}")

x_vals = [row[0] for row in rows]
y_vals = [row[1] for row in rows]

plt.scatter(x_vals, y_vals, label='Data')
plt.xlabel('milleage')
plt.ylabel('price')

predicted_y = [(t0 + t1 * (x / max_km)) * max_price for x in x_vals]
plt.plot(x_vals, predicted_y, color='red', label='Regression line')

plt.legend()
plt.show()

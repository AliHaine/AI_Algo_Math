import csv

rows = []

m = 0
theta0 = 0.0
theta1 = 0.0
learning_rate = 0.01
iterations = 10000
max_km = 0
max_price = 0
precision = 0.0

try:
    with open('./data.csv') as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            convert_rows = [int(values) for values in row]
            rows.append(convert_rows)
        max_km = max(row[0] for row in rows)
        max_price = max(row[1] for row in rows)
        rows = [[km / max_km, price / max_price] for km, price in rows]
        m = len(rows)
except FileNotFoundError:
    print("File not found")
    exit(1)

def estimatePrice(milleage):
    return theta0 + theta1 * milleage

for i in range(iterations):
    error_t0 = 0
    error_t1 = 0
    for row in rows:
        predict_error = estimatePrice(row[0]) - row[1]
        error_t0 += predict_error
        error_t1 += predict_error * row[0]
    theta0 -= learning_rate * (1 / m) * error_t0
    theta1 -= learning_rate * (1 / m) * error_t1

for row in rows:
    predict_error = row[1] - estimatePrice(row[0])
    precision += (predict_error ** 2) / m

mse_denormalized = precision * (max_price ** 2)
rmse = mse_denormalized ** 0.5
rmse_percentage = (rmse / max_price) * 100

try:
    with open('./result.txt', 'w') as file:
        file.write(f"{theta0},{theta1},{max_km},{max_price},{rmse_percentage:.2f}")
except:
    print("Result cant be saved")
    exit(1)

print("Process finished, result computed in result.txt")
import csv
import utils

rows = []

m = 0
theta0 = 0.0
theta1 = 0.0
learning_rate = 0.01
iterations = 10000
max_km = 0
max_price = 0
precision = 0.0
mae = 0.0
mse = 0.0
ss_total = 0
ss_res = 0

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


print(f"\n{utils.LINE}")
print(f"{utils.BOLD}{utils.CYAN}⚙️  Training Configuration{utils.RESET}")
print(f"{utils.LINE}")
print(f"{utils.YELLOW}➤ Learning Rate:           {utils.RESET}{learning_rate}")
print(f"{utils.YELLOW}➤ Iterations:              {utils.RESET}{iterations}")
print(f"{utils.YELLOW}➤ Total Values to Compute: {utils.RESET}{m}")
print(f"{utils.GREEN}➤ Max Mileage (km):        {utils.RESET}{max_km} 🌟")
print(f"{utils.GREEN}➤ Max Price (€):           {utils.RESET}{max_price} 🌟")
print(f"{utils.LINE}")

def estimatePrice(milleage):
    return theta0 + theta1 * milleage

for i in range(iterations):
    error_t0 = 0
    error_t1 = 0
    for row in rows:
        mae += abs(row[1] - estimatePrice(row[0]))
        predict_error = estimatePrice(row[0]) - row[1]
        error_t0 += predict_error
        error_t1 += predict_error * row[0]
    theta0 -= learning_rate * (1 / m) * error_t0
    theta1 -= learning_rate * (1 / m) * error_t1

mae /= m
mean_price = sum(row[1] for row in rows) / m
for row in rows:
    mse += (((row[1] - estimatePrice(row[0])) ** 2) / m)
    y = row[1]
    y_hat = estimatePrice(row[0])
    ss_res += (y - y_hat) ** 2
    ss_total += (y - mean_price) ** 2

r_squared = 1 - (ss_res / ss_total)
mse_denormalized = mse * (max_price ** 2)
rmse = mse_denormalized ** 0.5
rmse_percentage = (rmse / max_price) * 100

try:
    with open('./result.txt', 'w') as file:
        file.write(f"{theta0},{theta1},{max_km},{max_price},{mae:.0f},{rmse:.0f},{rmse_percentage:.2f},{r_squared:.2f}")
except:
    print("Result cant be saved")
    exit(1)
print(f"{utils.BOLD}{utils.GREEN}Process finished, result computed in {utils.YELLOW}result.txt")
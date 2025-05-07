import csv

rows = []

m = 0
theta0 = 0.0
theta1 = 0.0
learning_rate = 0.001
iterations = 1000

try:
    with open('./data.csv') as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            convert_rows = [int(values) for values in row]
            convert_rows[0] /= 1000000
            rows.append(convert_rows)
        #max_km = max(row[0] for row in rows)
        # normalized_rows = [(km / max_km, price) for km, price in rows]
        #rows = normalized_rows
        m = len(rows)
except FileNotFoundError:
    print("File not found")
    exit(1)

def prediction(milleage):
    return theta0 + theta1 * milleage

for i in range(iterations):
    error_t0 = 0
    error_t1 = 0

    for row in rows:
        predict_error = prediction(row[0]) - row[1]
        error_t0 += predict_error
        error_t1 += predict_error * row[0]

    theta0 -= learning_rate * (1 / m) * error_t0
    theta1 -= learning_rate * (1 / m) * error_t1


try:
    with open('./result.txt', 'w') as file:
        file.write(f"{theta0},{theta1}")
except:
    print("Result cant be saved")
t0 = 0
t1 = 0
max_km = 0
max_price = 0

try:
    km_input = int(input('Enter a milleage (KM): '))
    if km_input > 1000000:
        exit(1)
except:
    print('Invalid input')
    exit(1)

try:
    with open('./result.txt') as file:
        line = file.readline().split(',')
        try:
            t0 = float(line[0])
            t1 = float(line[1])
            max_km = float(line[2])
            max_price = float(line[3])
        except:
            print('Invalid results')
            exit(1)
except FileNotFoundError:
    print("File not found")
    exit(1)

normalized_km = km_input / max_km
normalized_price = t0 + t1 * normalized_km
predicted_price = normalized_price * max_price

print(f"Estimated price: {predicted_price:.2f}")
import utils

t0 = 0
t1 = 0
max_km = 0
max_price = 0
rmse_percent = 0.0

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
            rmse_percent = float(line[6])
        except:
            print('0')
            exit(1)
except FileNotFoundError:
    print("File not found")
    exit(1)

normalized_km = km_input / max_km
normalized_price = t0 + t1 * normalized_km
predicted_price = round(normalized_price * max_price, 2)
percent_price = predicted_price * rmse_percent / 100
low_estimate = round(predicted_price - percent_price, 2)
high_estimate = round(predicted_price + percent_price, 2)

print(f"\n{utils.CYAN}{'-' * 50}{utils.RESET}")
print(f"{utils.BOLD}{utils.CYAN}🚗  Price Estimation Result{utils.RESET}")
print(f"{utils.CYAN}{'-' * 50}{utils.RESET}")

print(f"{utils.GREEN}➤ Estimated Price:{utils.RESET} {predicted_price:.2f}")
print(f"{utils.YELLOW}➤ Confidence Range:{utils.RESET} {low_estimate} - {high_estimate} 🌟")

print(f"{utils.CYAN}{'-' * 50}{utils.RESET}\n")
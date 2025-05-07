t0 = 0
t1 = 0

try:
    with open('./result.txt') as file:
        line = file.readline().split(',')
        t0 = float(line[0])
        t1 = float(line[1])
except FileNotFoundError:
    print("File not found")
    exit(1)


print(t0 + (t1 * (61789 / 1000000)))
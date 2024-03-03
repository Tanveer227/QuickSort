import matplotlib.pyplot as plt

exp = []
time = []
input = open("input.txt", 'r')
#print(input.read())
with open("input.txt", 'r') as input_file:
    for i in range(1, 10001):
        exp.append(i)
        time_line = input_file.readline().strip()  # Read the line and remove leading/trailing whitespaces
        time.append(float(time_line))

plt.hist(time, range=[0.000, 0.002], bins=200)
plt.show()
#print(time)
#print(len(time))
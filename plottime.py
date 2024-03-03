import matplotlib.pyplot as plt;
from math import log

size = []
time = []
z = []

for i in range(0, 9):
    a = int(input())
    b = float(input())
    size.append(a)
    time.append(b)
    
for i in size:
    temp = time[8]*i*log(i)/92103.40372
    z.append(temp)
plt.plot(size, time)
plt.plot(size, z)
plt.xlabel("Size of Array")
plt.ylabel("Running Time")
plt.show()


print(size)
print(time)
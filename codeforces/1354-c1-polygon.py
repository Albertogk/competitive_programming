import math

t = int(input())

for i in range(t):
    n = int(input())
    angulo = math.pi/n
    print(2*math.cos(angulo/2)*math.sqrt((0.5**2)/(1-math.cos(angulo/2)**2)))

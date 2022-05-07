import random

P = int(input("Enter the value of P: "))
alpha = 2

def checkalpha(alpha):
    used = set()
    for i in range(1, P):
        if (alpha**i % P) in used:
            return -1
        used.add(alpha**i % P)
    return alpha

while checkalpha(alpha) == -1:
    alpha+=1
print("alpha: ", alpha)

xA = random.randint(1, P-1)
xB = random.randint(1, P-1)
print("Private keys:")
print("xA: ", xA)
print("xB: ", xB)

kA = (alpha**xA) % P
kB = (alpha**xB) % P
print("Public keys:")
print("kA: ", kA)
print("kB: ", kB)

k1 = (kB**xA) % P
k2 = (kA**xB) % P
print("Secret keys:")
print("k1: ", k1)
print("k2: ", k2)
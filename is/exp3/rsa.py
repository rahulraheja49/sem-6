import math

p, q = 7, 11
n = p*q
z = (p-1)*(q-1)
e, d = 2, 2

while math.gcd(e, z) != 1:
    e+=1

while (e*d)%z != 1:
    d+=1

def encrypt(e, n):
    plaintext = input("Enter plaintext: ")
    ciphertext = []
    for i in plaintext:
        i = ord(i)-96
        ciphertext.append((i**e) % n)
    return ciphertext

def decrypt(d, n):
    ciphertext = input("Enter ciphertext: ")
    ciphertext = ciphertext.split(", ")
    plaintext = []
    for i in ciphertext:
        i = (int(i)**d)%n
        plaintext.append(chr((i % 26) + 96))
    return "".join(plaintext)

option=0
while(option != -1):
    print("""\nMenu:
    1.  Encrypt
    2.  Decrypt
    -1. Exit""")
    option = int(input("Enter your choice: "))
 
    if option == 1:
        print("\n--- Encryption selected ---")
        ciphertext = encrypt(e, n)
        print(ciphertext)
    elif option == 2:
        print("\n--- Decryption selected ---")
        plaintext = decrypt(d, n)
        print(plaintext)
    elif option == -1:
        print("Exiting...")
    else:
        print("Enter valid option")
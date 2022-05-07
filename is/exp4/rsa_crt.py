import math

p, q = 7, 11
n = p*q
z = (p-1)*(q-1)
e, dp, dq, qinv = 2, 2, 2, 2

while math.gcd(e, z) != 1:
    e+=1

while (e*dp)%(p-1) != 1:
    dp+=1

while (e*dq)%(q-1) != 1:
    dq+=1

while (qinv*q)%(p) != 1:
    qinv+=1

def encrypt(e, n):
    plaintext = input("Enter plaintext: ")
    ciphertext = []
    for i in plaintext:
        i = ord(i)-96
        ciphertext.append((i**e) % n)
    return ciphertext


def decrypt():
    ciphertext = input("Enter ciphertext: ")
    ciphertext = ciphertext.split(", ")
    plaintext = []
    for i in ciphertext:
        m1 = (int(i)**dp) % p
        m2 = (int(i)**dq) % q
        h = (qinv*(m1-m2)) % p
        m = m2 + h*q
        plaintext.append(chr(int((m % 26) + 96)))
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
        plaintext = decrypt()
        print(plaintext)
    elif option == -1:
        print("Exiting...")
    else:
        print("Enter valid option")
import collections

def encrypt(key):
    plaintext = input("Enter plaintext: ")
    res=[]
    cols = {}
    for ind, i in enumerate(key):
        cols[i] = []
    diff = len(plaintext) % len(key)
    plaintext += "#"*diff
    sorted_key = "".join(sorted(key))
    for ind, i in enumerate(plaintext):
        cols[sorted_key[ind%len(key)]].append(i)
    for i in key:
        res += cols[i]
    print("".join(res))


def decrypt(key):
    ciphertext = input("Enter ciphertext: ")
    cols = {}
    sorted_key = "".join(sorted(key))
    res, plaintext=[], []
    for ind, i in enumerate(key):
        cols[i] = []
    vals_per_col = len(ciphertext)//len(key)
    for i in range(0, len(key)):
        cols[key[i]] = list(ciphertext[i*vals_per_col:i*vals_per_col+vals_per_col])
    for i in range(vals_per_col):
        for j in sorted_key:
            res.append(cols[j][i])
    print("".join(res))

option=0
while(option != -1):
    print("""\nMenu:
    1.  Encrypt
    2.  Decrypt
    -1. Exit""")
    option = int(input("Enter your choice: "))

    if option == 1:
        print("\n--- Encryption selected ---")
        key = input("Enter the key: ")
        encrypt(key)
    elif option == 2:
        print("\n--- Decryption selected ---")
        key = input("Enter the key: ")
        decrypt(key)
    elif option == -1:
        print("Exiting...")
    else:
        print("Enter valid option")
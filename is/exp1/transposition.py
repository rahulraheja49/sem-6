def encrypt(col):
    plaintext = input("Enter plaintext: ")
    res=[]
    if len(plaintext)%col !=0:
        r = col - len(plaintext)%col 
        plaintext += ' '*r
    for i in range(col):
        for j in range(i, len(plaintext), col):
            res.append(plaintext[j])
    print(f"Ciphertext: '{''.join(res)}'")


def decrypt(col):
    ciphertext = input("Enter ciphertext: ")
    length_part = len(ciphertext)/col
    res, plaintext=[], []
    for i in range(col):
        res.append(ciphertext[int(i*col):int(i*col+length_part)])
    for i in range(len(res[0])):
        for j in range(col):
            if res[j][i] != " ":
                plaintext.append(res[j][i])
    print(f"Plaintext: '{''.join(plaintext)}'")


option=0
while(option != -1):
    print("""\nMenu:
    1.  Encrypt
    2.  Decrypt
    -1. Exit""")
    option = int(input("Enter your choice: "))

    if option == 1:
        print("\n--- Encryption selected ---")
        col = len(input("Enter the key: "))
        encrypt(col)
    elif option == 2:
        print("\n--- Decryption selected ---")
        col = len(input("Enter the key: "))
        decrypt(col)
    elif option == -1:
        print("Exiting...")
    else:
        print("Enter valid option")
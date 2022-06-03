import math
import hashlib

rec_p, rec_q = 7, 11
rec_n = rec_p*rec_q
rec_z = (rec_p-1)*(rec_q-1)
rec_e, rec_d = 2, 2

sen_p, sen_q = 5, 13
sen_n = sen_p*sen_q
sen_z = (sen_p-1)*(sen_q-1)
sen_e, sen_d = 2, 2

while math.gcd(rec_e, rec_z) != 1:
    rec_e+=1

while (rec_e*rec_d)%rec_z != 1:
    rec_d+=1

while math.gcd(sen_e, sen_z) != 1:
    sen_e+=1

while (sen_e*sen_d)%sen_z != 1:
    sen_d+=1

def encrypt_and_sign(rec_e):
    plaintext = input("Enter plaintext: ")
    ciphertext = []
    for i in plaintext:
        i = ord(i)-96
        ciphertext.append((i**rec_e) % rec_n)
    hashtext = "".join(str(i) for i in ciphertext)
    hashtext = bytes(hashtext, encoding= 'utf-8')
    hash_obj = hashlib.sha1(hashtext)
    digest1 = hash_obj.digest()
    # digest1 = len(pbhash)
    signature = []
    for i in digest1:
        i = ord(chr(i))
        signature.append((i**sen_d) % sen_n)
    return ciphertext, signature

def decrypt_and_unsign(rec_d, rec_n):
    ciphertext = input("Enter ciphertext: ")
    signature = input("Enter digital signature: ")
    ciphertext = ciphertext.split(", ")
    signature = signature.split(", ")
    hashtext = "".join(str(i) for i in ciphertext)
    hashtext = bytes(hashtext, encoding= 'utf-8')
    hash_obj = hashlib.sha1(hashtext)
    digest2 = hash_obj.digest()
    digest1 = []
    for i in signature:
        i = (int(i)**sen_e) % sen_n
        digest1.append(chr(i))

    print(digest1)
    print(digest2)
    # digest2 = len(pbhash)
    if digest2 == "".join(digest1):
        plaintext = []
        for i in ciphertext:
            i = (int(i)**rec_d)%rec_n
            plaintext.append(chr((i % 26) + 96))
        return "".join(plaintext)
    else:
        return "Digital signature not matching... discarding message"

option=0
while(option != -1):
    print("""\nMenu:
    1.  Encrypt
    2.  Decrypt
    -1. Exit""")
    option = int(input("Enter your choice: "))
 
    if option == 1:
        print("\n--- Encryption selected ---")
        ciphertext, d1 = encrypt_and_sign(rec_e)
        print("Ciphertext: ", ciphertext)
        print("digital signature: ", d1)
    elif option == 2:
        print("\n--- Decryption selected ---")
        plaintext = decrypt_and_unsign(rec_d, rec_n)
        print("Plaintext: ", plaintext)
    elif option == -1:
        print("Exiting...")
    else:
        print("Enter valid option")
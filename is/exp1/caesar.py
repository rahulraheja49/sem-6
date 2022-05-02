def ceaser(txt ,key):
    res=[]
    for ele in txt:
        if ele == " ":
            res.append('_')
        elif ele == '_' and key<0:
            res.append(' ')
        else:
           res.append(chr((ord(ele)-97+key)%26+97))
    return res
    

def encrypt(key):
    txt = input("Enter plaintext: ").lower()
    val = "".join(ceaser(txt, key))
    print(f"Ciphertext: {val}")


def decrypt(key):
    txt = input("Enter ciphertext: ").lower()
    val = "".join(ceaser(txt, (-1)*key))
    print(f"Plaintext: {val}")


key=1
option=0
while(option!=-1):
    print("""\nMenu(Ceaser Cipher):
    1.  Encrypt
    2.  Decrypt
    -1. Exit""")
    option = int(input("Enter your choice: "))

    if option ==1:
        print("\n--- Encryption selected ---")
        key = int(input("Enter key: "))
        encrypt(key)
    elif option ==2:
        print("\n--- Decryption Selected ---")
        key = int(input("Enter key: "))
        decrypt(key)
    elif option == -1:
        print("Exiting...")
    else:
        print("Enter valid option")
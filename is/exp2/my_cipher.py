def encrypt(key, m):
    plaintext = input("Enter plaintext: ")
    if (len(plaintext)%len(key)) != 0:
        plaintext += "#" * (len(plaintext)%len(key))
    x = []
    col = {}
    order = []
    order_copy = []
    ciphertext = []
    offset = int(len(plaintext)/len(key))
    for index, char in enumerate(plaintext):
        if index%3 == m%3:
            x.append((ord(char)-96) + m + 1 + m%3)
        else:
            x.append((ord(char)-96) + m)
    for i in key:
        col[ord(i)-96] = []
        order.append(ord(i)-96)
        order_copy.append(ord(i)-96)
    order_copy.sort()
    for ind, item in enumerate(reversed(order_copy)):
        col[item] = x[(ind*offset):(ind*offset+offset)]
    for i in range(len(order)):
        if i%3 == m%3:
            col[order[i]] = col[order[i]][::-1]
    for j in range(len(col[order[0]])):
        for i in order:
            ciphertext.append(col[i][j])
    return ','.join([str(i) for i in ciphertext])
 
def decrypt(key, m):
    ciphertext = input("Enter ciphertext: ").split(",")
    col = {}
    order = []
    order_copy = []
    plaintext = []
    x = []
    for i in key:
        col[ord(i)-96] = []
        order.append(ord(i)-96)
        order_copy.append(ord(i)-96)
    j = 0
    order_copy.sort()
    while j<len(ciphertext):
        for i in order:
            col[i].append(ciphertext[j])
            j += 1
    for i in range(len(order)):
        if i%3 == m%3:
            col[order[i]] = col[order[i]][::-1]
    for i in reversed(order_copy):
        x += col[i]
    for index, num in enumerate(x):
        if index%3 == m%3:
            plaintext.append(int(num) - (m + 1 + m%3))
        else:
            plaintext.append(int(num) - m)
    for ind, item in enumerate(plaintext):
        char = chr(item+96)
        if char != "#":
            plaintext[ind] = char
        else:
            plaintext.remove(item)
    return "".join(plaintext)
 
def getM(key):
    c = {0: 1, 1: 1, 2: 1}
    for i in range(len(key)):
        c[i%3] *= (ord(key[i])-96)
    return c[0] + c[1] + c[2]
 
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
        m = getM(key)
        ciphertext = encrypt(key, m)
        print(f"Ciphertext is: {ciphertext}")
    elif option == 2:
        print("\n--- Decryption selected ---")
        key = input("Enter the key: ")
        m = getM(key)
        plaintext = decrypt(key, m)
        print(f"Plaintext is: {plaintext}")
    elif option == -1:
        print("Exiting...")
    else:
        print("Enter valid option")
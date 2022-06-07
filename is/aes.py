from Crypto.Cipher import AES
key = b'Sixteen byte key'
cipher = AES.new(key, AES.MODE_EAX)
nonce = cipher.nonce
data = b"Data to be encrypted"
ciphertext, tag = cipher.encrypt_and_digest(data)

cipher = AES.new(key, AES.MODE_EAX, nonce=nonce)
plaintext = cipher.decrypt(ciphertext)
try:
    cipher.verify(tag)
    print("The message is authentic:", plaintext)
except ValueError:
    print("Key incorrect or message corrupted")
from Crypto.Cipher import DES3
from secrets import token_bytes

key = token_bytes(16)

def encryption(msg):
  cipher = DES3.new(key, DES3.MODE_EAX)
  nonce = cipher.nonce
  ciphertext, tag = cipher.encrypt_and_digest(msg.encode('ascii'))
  return ciphertext, tag, nonce

def decryption(ciphertext, tag, nonce):
    cipher = DES3.new(key, DES3.MODE_EAX, nonce = nonce)
    plaintext = cipher.decrypt(ciphertext)
    try:
        cipher.verify(tag)
        print("The message is authentic:", plaintext)
        return plaintext.decode('ascii')
    except ValueError:
        return "Key incorrect or message corrupted"

plain = "Test plaintext"
ciphertext, tag, nonce = encryption(plain)
print("Cipher Text: ",ciphertext)
n_plain = decryption(ciphertext, tag, nonce)
print("New Plain Text: ", n_plain)
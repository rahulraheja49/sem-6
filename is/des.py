from des import DesKey

key0 = DesKey(b"some key")

ciphertext = key0.encrypt(b"abc", padding=True)

plaintext = key0.decrypt(ciphertext, padding=True)

print(plaintext)
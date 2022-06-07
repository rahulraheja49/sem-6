import random
import string
import hashlib

def encryption(plain, key):
  cipher = ""
  for i in range (0, len(plain)):
    if (plain[i] == " "):
      cipher += " "
    else:
      temp = ord(plain[i])
      temp -= 65
      temp += key
      temp = temp % 57
      cipher += chr(temp + 65)
  return cipher

message = input("Enter message: ")
key = random.randint(0, 100)
encrypted_message = encryption(message, key)
print(encrypted_message)

# Hashing using sha512

result = hashlib.sha512(encrypted_message.encode())
hash = result.hexdigest()

print("To be sent over network: Message", message, "; Hash: ", hash)

print("Message recieved: ", message)
print("Hash received: ", hash)

encrypted_message_2 = encryption(message, key)
print("Message encrypted: ",encrypted_message_2)

result = hashlib.sha512(encrypted_message_2.encode())
hash2 = result.hexdigest()
print("Hash created for check: ", hash)

if (hash == hash2):
  print("Integrity achieved!!")
else:
  print("Some alterations done in the network!!")
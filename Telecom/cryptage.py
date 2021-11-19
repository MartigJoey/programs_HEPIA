import random
from math import *
# fonction de lecture d'un fichier

def read_file_binary(file):  
    return open(file, "rb")

#afficher la taille du fichier

file_size = 0
input_file = read_file_binary("input.txt")
file_byte = input_file.read()
file_size = len(file_byte)

print("File size {}".format(file_size))

def generate_key(seed, file_size):
    random.seed(seed)
    key_int = random.getrandbits(file_size*8)
    key_bytes = (key_int).to_bytes(file_size, byteorder='big')

    return key_bytes

def save_key(key):
    key_bin = open("key.bin", "wb")
    key_bin.write(key)
    key_bin.close()

save_key

def file_encrypt(file, key, size):
    encrypted_file = bytearray(size)
    for byte_i in range(0, size):
        encrypted_file[byte_i] = file[byte_i] ^ key[byte_i]

    return encrypted_file

def save_encrypted_file(file):
    file_bin = open("crypted.bin", "wb")
    file_bin.write(file)
    file_bin.close()

key = generate_key(10, file_size)
save_key(key)
encrypted_file = file_encrypt(file_byte, key, file_size)
save_encrypted_file(encrypted_file)

def file_Decrypt(file, key, size):
    return file_encrypt(file, key, size)

assert(file_byte == file_Decrypt(encrypted_file, key, file_size))
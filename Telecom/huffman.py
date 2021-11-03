import math

input_file = open("input.txt", "r", encoding="UTF-8")
binary_file = open("binary_input.txt", "w+b")

file_text = input_file.read()
char_dictionnary = {}
sum_char = len(file_text)
output_text = ""

for character in file_text:
    if character in char_dictionnary:
        char_dictionnary[character] += 1
    else:
        char_dictionnary[character] = 1

char_dictionnary = dict(sorted(char_dictionnary.items(), key=lambda item: item[1], reverse=True))

huffman_done = []
char_dict_cpy = char_dictionnary.copy()
dict_huffman = {}
count_char = 0

def get_min_value_key(dict_huffman):
    min_value = 255
    min_key = ''
    for key in dict_huffman:
        if dict_huffman[key] < min_value and key not in huffman_done:
            min_value = dict_huffman[key]
            min_key = key

    huffman_done.append(min_key)
    return min_key

while count_char < len(char_dictionnary)-1:
    # Prends les deux clés les plus petites
    min_key_0 = get_min_value_key(char_dict_cpy)
    min_key_1 = get_min_value_key(char_dict_cpy)

    for char_key_0 in min_key_0:
        if char_key_0 in dict_huffman:
            dict_huffman[char_key_0] = "0" + dict_huffman[char_key_0]
        else:
            dict_huffman[char_key_0] = "0"
    
    for char_key_1 in min_key_1:
        if char_key_1 in dict_huffman:
            dict_huffman[char_key_1] = "1" + dict_huffman[char_key_1]
        else:
            dict_huffman[char_key_1] = "1"

    count_char += 1
    char_dict_cpy[min_key_0+min_key_1] = char_dict_cpy[min_key_0] + char_dict_cpy[min_key_1]

# écriture du fichier compressé
compressed_text = ""
for character in file_text:
    compressed_text += dict_huffman[character]

byte_arr = bytearray()
while len(compressed_text) > 0:
    byte_str = compressed_text[0:8]
    while len(byte_str) < 8:
        byte_str += "0"

    compressed_text = compressed_text[8:]
    print(byte_str)
    byte_arr.append(int(byte_str, 2))

binary_file.write(byte_arr)

## Affichage
for key in char_dictionnary:
    print("0x{} {:.5f}".format(ord(key), (char_dictionnary[key]) / sum_char))

sum_bits = 0
for key in char_dictionnary:
    sum_bits += len(dict_huffman[key]) * char_dictionnary[key]

print("{}".format(sum_bits / sum_char))

#Calculer entropie H
H = 0
for key in char_dictionnary:
    prob = char_dictionnary[key] / sum_char
    H += prob * math.log2(prob)
    
H = H * -1
print("Entropie du fichier H = {:.5f}".format(H))

#La quantité de décision D?
D = math.log2(len(char_dictionnary))
print("Quantité de décision D = {:.5f}".format(D))

#La redondance R
R = D-H
print("Redondance R = {:.5f}".format(R))

#Taux de compression maximum du fichier
L = 1 - H / D
#for key in char_dictionnary:
#    prob = char_dictionnary[key] / sum_char
#    L += prob * len(str(ord(key)))

#print("Taux de compression maximum du fichier = {:.5f}".format(1-((L-H)/D)))
print("Taux de compression maximum du fichier = {:.5f} {} {}".format(L))

input_file.close()
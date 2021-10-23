import math

input_file = open("input.txt", "r", encoding="UTF-8")
out_file1 = open("out1.txt", "w+")
out_file2 = open("out2.txt", "w+")

# Exercice 1.a
file_text = input_file.read()
out_text1 = ""
ascii_text = []

for character in file_text:
    ascii_text.append(ord(character))

ascii_text.sort()

for acii_character in ascii_text:
    out_text1 += chr(acii_character)

out_file1.write(out_text1)

# Exercice 1.b
char_dictionnary = {}
sum_char = len(file_text)
out_text2 = ""

for character in file_text:
    if character in char_dictionnary:
        char_dictionnary[character] += 1
    else:
        char_dictionnary[character] = 1

char_dictionnary = dict(sorted(char_dictionnary.items(), key=lambda item: item[1], reverse=True))

for key in char_dictionnary:
    print("0x{} {:.10f}".format(ord(key), (char_dictionnary[key]) / sum_char))


for key in char_dictionnary:
    out_text2 += ''.join([char*char_dictionnary[key] for char in key]) 

out_file2.write(out_text2)

# Exercice 1.c

#Calculer entropie H
H = 0
for key in char_dictionnary:
    prob = char_dictionnary[key] / sum_char
    H += prob * math.log2(prob)
    
H = H * -1
print("Entropie du fichier H = {:.6f}".format(H))

#La quantité de décision D?
D = math.log2(len(char_dictionnary))
print("Quantité de décision D = {:.6f}".format(D))

#La redondance R
R = D-H
print("Redondance R = {:.6f}".format(R))
#Taux de compression maximum du fichier
L = 0
for key in char_dictionnary:
    prob = char_dictionnary[key] / sum_char
    L += prob * len(str(ord(key)))

print("Taux de compression maximum du fichier = {:.6f}".format(1-((L-H)/D)))

input_file.close()
out_file1.close()
out_file2.close()
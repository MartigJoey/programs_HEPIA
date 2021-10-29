def et(A, B):
    return A and B

def ou(A, B):
    return A or B

def non(A):
    return not A

def implique(A, B):
    return bool(A) <= bool(B)

def equiv(A, B):
    return A == B

is_tautologie_1 = True

# nb var = 3
for i in range(0, pow(2, 3)):
    str_bit = "{0:03b}".format(i)
    str_len = len(str_bit)
    A = str_bit[str_len-1]
    B = str_bit[str_len-2]
    C = str_bit[str_len-3]
    if not non(ou(implique(A, B), C)):
        is_tautologie_1 = False
        break

is_tautologie_2 = True
for i in range(0, pow(2, 3)):
    str_bit = "{0:03b}".format(i)
    str_len = len(str_bit)
    A = str_bit[str_len-1]
    B = str_bit[str_len-2]
    C = str_bit[str_len-3]
    if not implique(implique(A, B), equiv(non(B), non(A))):
        is_tautologie_2 = False
        break

is_tautologie_3 = True
for i in range(0, pow(2, 7)):
    str_bit = "{0:07b}".format(i)
    str_len = len(str_bit)
    A = str_bit[str_len-1]
    B = str_bit[str_len-2]
    C = str_bit[str_len-3]
    D = str_bit[str_len-4]
    E = str_bit[str_len-5]
    F = str_bit[str_len-6]
    G = str_bit[str_len-7]
    if not implique(implique(ou(A, non(B)), ou(implique(C, D), implique(D, C))), equiv(et(non(A), B), implique(et(E, F), ou(non(G), F)))):
        is_tautologie_3 = False
        break

print(is_tautologie_1)
print(is_tautologie_2)
print(is_tautologie_3)
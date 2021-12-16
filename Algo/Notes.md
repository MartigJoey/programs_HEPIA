# Mantisse
0111 1100,01<br>
Exposant = 124-127 = -3<br>
Mantisse = 1+2^-2 = 1.25<br>
2^⁻3 * 1.25 = 0.15625<br>
## float
1 bit de signe <br>
8 bit d'exposant<br>
23 bit de mantisse<br>
7 chiffres significatifs

## double
1 bit de signe<br>
11 bit d'exposant<br>
52 bit de mantisse<br>
16 chiffres significatifs

## Mesurer précision matisse (float)
```c
float eps = 1.0;
while((float)1.0 + (float)0.5 * eps != (float)1.0){
    eps = (float)0.5 * eps;
}
printf("eps = %g\n", eps)
```

# trie insertion
[`5`, `-2`, 1, 3, 10]

[-2, `5`, `1`, 3, 10]

[-2, 1, `5`, `3`, 10]

[-2, 1, 3, 5, 10]

# trie rapide

[5, -2, 1, 3, 10, 15, 7, 4] P = 4<br>
[`3`, -2, 1, `5`, 10, 15, 7, 4]<br>
[3, -2, 1, `4`, 10, 15, 7, `5`]<br>

|   |   |   |
|---|---|---|
|[3, -2, 1] P = 1|[10, 15, 7, 5] P = 5   ||
|[`-2`, `3`, 1] |[10, 15, 7, 5]||
|[-2, `1`, `3`] |[`5`, 15, 7, `10`]||
|[-2, 1, 3]     ||[15, 7, 10] P = 10|
|               ||[`7`, `15`, 10]|
|               ||[7, `10`, `15`]|


[-2, 1, 3, 4, 5, 7, 10, 15]<br>

# Assert
## Afficher un message dans le assert
```c
assert(condition && "Commentaire sur l'assert");
```

# Realloc
```c
void *realloc(void *ptr, int size);

int *data = malloc(5*sizeof(int));

data = realloc(data, 10*sizeof(int));
```
Taille de data = 5, puis après realloc = 10.

# Git
git branch -a
git checkout Nom_Branch
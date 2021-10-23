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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fromBaseTen(int value_base_ten, int value, int base_a, int base){
    int new_value;
    int divided_value = value_base_ten;
    int rests[1024];
    int nb_digit = floor(log10(abs(base)))+1;
    int rest_i = 0;
    while (divided_value != 0)
    {
        rests[rest_i] = divided_value % base;
        divided_value /= base;
        rest_i++;
    }
    
    printf("%d en base %d vaut ", value, base_a);
    for(int i = rest_i-1; i >= 0; i--){
        printf("%.*d", nb_digit, rests[i]);
    }
    printf(" en base %d\n", base);
}

int toBaseTen(int value_base, int base){
    int value_base_array[1024];
    int array_i = 0;
    int nb_digit = floor(log10(abs(base)))+1;
    int value_base_ten = 0;

    while (value_base != 0)
    {
        value_base_array[array_i] = value_base % (int)pow(10, nb_digit);
        value_base /= pow(10, nb_digit);
        array_i++;
    }
   
    for(int i = array_i-1; i >= 0; i--){
        if(value_base_array[i])
            value_base_ten += pow(base, i) * value_base_array[i];
    }
    return value_base_ten;
}

int convertBase(char value_base_array[], int base_a, int base_b){
    int value_base = 0;
    if (base_a >= 16 && base_a <= 35){
        int array_size;
        int power = 0;
        for (array_size = 0; value_base_array[array_size] != '\0'; array_size++){}
        for (int i = array_size-1; i >= 0; i--)
        {
            int substraction;
            if(value_base_array[i] >= 65 && value_base_array[i] <= 90)
                substraction = 55;
            else if(value_base_array[i] >= 48 && value_base_array[i] <= 57)
                substraction = 48;

            value_base += (value_base_array[i] - substraction) * pow(100, power);
            power++;
        }
    }else
        value_base = atoi(value_base_array);
    
    int value_base_ten = value_base;
    int value_base_b;    

    if (base_a != 10)
        value_base_ten = toBaseTen(value_base, base_a);

    if (base_b != 10)
        fromBaseTen(value_base_ten, value_base, base_a, base_b);
    else
        printf("%d en base %d vaut %d en base 10\n", value_base, base_a, value_base_ten);
}

int main(){
    convertBase("A709", 35, 2);
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    char *str1 = "tutut";
    bool is_palindrome = true;
    int str_len = strlen(str1)-1;
    for (int i_inc = 0, i_dec = str_len; i_inc < str_len; i_inc++, i_dec--){
        if(str1[i_inc] != str1[i_dec])
            is_palindrome = false;
    }
    printf("%s is palindrome ? %s\n", str1, is_palindrome ? "yes" : "no");

    return 0;
}
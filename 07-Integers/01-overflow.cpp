// an example illustrating the basics of integer overflows

#include <climits>
#include <stdio.h>

int main() {
    int i = INT_MAX;
    printf("i = %d\n", i);
    i++;
    printf("i = %d\n", i);          

    i = INT_MIN;
    printf("i = %d\n", i);
    i--;
    printf("i = %d\n", i);          


    unsigned int j = UINT_MAX;
    printf("j = %u\n", j);
    j++;
    printf("j = %u\n", j);    

    unsigned int uintk = 0; // Hungarian notation might help spotting potential problems later 
                            // see https://en.wikipedia.org/wiki/Hungarian_notation
    printf("uintk = %u\n", uintk);
    uintk --;
    printf("uintk = %u\n", uintk);

    // It is very difficult to spot a problem, outside of the context where the variables are declared
    // Using variable names with prefixes (Hungarian notation) may help
    uintk = 0;
    printf("j = %u\n", uintk);
    uintk--;
    printf("j = %u\n", uintk);
}
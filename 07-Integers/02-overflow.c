// a practical example of integer overflows 

#include <stdio.h>

int main(){
    short sintExample = 0x0100; // 256
    const long MAX_LEN = 0x7fff; // 32767
    long lintExample = (long) sintExample;

    printf("short (%d bytes): %x \n", (int)sizeof(sintExample), sintExample);
    printf("long (%d bytes): %lx \n", (int)sizeof(lintExample), lintExample);

    if(sintExample < MAX_LEN) // comparing long to int results in implicit typecasting
                              // i.e. upcasting sintExample from a signed 16-bit integer to a signed 32-bit integer
        printf("PASSED: %x (%d)\n", sintExample,sintExample);
    else
        printf("FAILED: %x (%d)\n", sintExample,sintExample);
    

    sintExample = 0xffff; // 65535
    lintExample = (long) sintExample;

    printf("short (%d bytes): %x \n", (int)sizeof(sintExample), sintExample);
    printf("long (%d bytes): %lx \n", (int)sizeof(lintExample), lintExample);

    if(sintExample < MAX_LEN)
        printf("PASSED: %x (%d)\n", sintExample,sintExample);
    else
        printf("FAILED: %x (%d)\n", sintExample,sintExample);
    
       
}
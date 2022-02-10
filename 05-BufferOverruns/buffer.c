// a simple example of buffer overflow used in class

#include <string.h>
#include <stdio.h>

int isPasswordOK(){
    char password[12];
    gets(password);     // unsafe due to lack of bounds checking on the input size
    return(strcmp(password,"goodpass")==0);
}

int main(){
    int pwStatus;
    printf("Enter password: ");
    pwStatus=isPasswordOK();
    if(!pwStatus) {
        printf("Access denied!\n");
        return -1;
    }
    else {
        printf("Access granted!\n");
        return 0;
    }
}
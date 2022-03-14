// this is an example of misinterpreting the return values of fgets()

#include <stdio.h>
#include <iostream>
using namespace std;

enum returnValues {SUCCESS, ERR_FILE_NOT_FOUND, ERR_IO_ERROR};

int test_fgets(const char* fileName) {
    // add error checking
    // if(!fileName || strlen(fileName)<3) return ERR_BAD_ARGUMENTS;

    FILE *f = fopen(fileName, "r");
    // add error checking
    if(!f) return ERR_FILE_NOT_FOUND;

    bool done=false;
    setbuf(f,0);
    while(!done) {
        const int charsToGet = 5;
        char buffer[charsToGet]; 
        char *test=fgets(buffer,charsToGet,f);
        if(!test) //if(test==0)
            done=true;
        // use "shred -zvu test.txt" from another terminal to remove the file while it's being processed
        else 
            cout << "buffer:" << buffer;
            
        // fgets() returns 0 if there's an IO error
        // it also returns 0 if at EOF (must use feof()/ferror() to tell the difference)
        cout << " feof()=" << feof(f) << " ferror()=" << ferror(f);
        if(ferror(f)) return ERR_IO_ERROR; 
        cin.get();
    }
    return SUCCESS;
}

int main(){
    test_fgets("test.txt");
}
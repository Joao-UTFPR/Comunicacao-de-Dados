//Simple C program to encrypt and decrypt a string

#include "cryptography.h"

char* encrypt(char* str){
    for(int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3; //the key for encryption is 3 that is added to ASCII value
    return str;
}

char* decrypt(char* str){
    for(int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3; //the key for encryption is 3 that is subtracted to ASCII value
    return str;
}
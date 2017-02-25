
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Encode(char password[], int length){
    
    FILE *ptr_read;
    FILE *ptr_write;
    
    char path_read[1000] = "/Users/laizhiyu/Desktop/Program/Password_Coding/Password_Coding/Text.txt";
    char path_write[1000] = "/Users/laizhiyu/Desktop/Program/Password_Coding/Password_Coding/EncodeText.txt";
    
    ptr_read = fopen(path_read, "rb");
    ptr_write = fopen(path_write, "wb");
    
    if(ptr_read == NULL || ptr_write == NULL){
        printf("Failed!!");
        return;
    }
    
    int i = 0;
    while(!feof(ptr_read)){
        char ch = fgetc(ptr_read);
        if(i < length-1){
            i=0;
        }
        ch = ch + password[i]; // Encode
        fputc(ch, ptr_write);
    }
    
    fclose(ptr_write);
    fclose(ptr_read);
}

void Decode(char password[], int length){
    
    FILE *ptr_read;
    FILE *ptr_write;
    
    char path_read[1000] = "/Users/laizhiyu/Desktop/Program/Password_Coding/Password_Coding/EecodeText.txt";
    char path_write[1000] = "/Users/laizhiyu/Desktop/Program/Password_Coding/Password_Coding/DecodeText.txt";
    
    ptr_read = fopen(path_read, "rb");
    ptr_write = fopen(path_write, "wb");
    
    if(ptr_read == NULL || ptr_write == NULL){
        printf("Failed!!");
        return;
    }
    
    int i = 0;
    while(!feof(ptr_read)){
        char ch = fgetc(ptr_read);
        if(i < length-1){
            i=0;
        }
        ch = ch - password[i]; // Decode
        fputc(ch, ptr_write);
    }
    
    fclose(ptr_write);
    fclose(ptr_read);
}

int main() {
    char password[] = "chihyulai";
    int n = strlen(password);
    Encode(password, n);
    Decode(password, n);
    return 0;
}

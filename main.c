// This is free and unencumbered software released into the public domain (The Unlicense).
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(int key, int argc, char** arr)
{
    int shift = key;
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < strlen(arr[i]); j++ ) {
            if (arr[i][j] >= 48 && arr[i][j] <= 57) {
                shift = arr[i][j] + key;
                if (shift > 57) {
                    shift %= 57; shift--;
                    arr[i][j] = 48 + shift;
                }
                else arr[i][j] = shift;
            } 
            else if (arr[i][j] >= 65 && arr[i][j] <= 90) { 
                shift = arr[i][j] + key;
                if (shift > 90) {
                    shift %= 90; shift--;
                    arr[i][j] = 65 + shift;
                }
                else arr[i][j] = shift;
            }
            else if (arr[i][j] >= 97 && arr[i][j] <= 122) { 
                shift = arr[i][j] + key;
                if (shift > 122) {
                    shift %= 122; shift--;
                    arr[i][j] = 97 + shift;
                }
                else arr[i][j] = shift;
            }
            else {
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) fprintf(stderr, "error: no arguements\n");
    else if (argc == 2) fprintf(stderr, "error: your arguements should include both the key and the message you want to encrypt\n");
    else {
        int key = atoi(argv[1]);
        argv+=2; argc-=2;
        if (key == 0) fprintf(stderr, "error: either your key is zero or you havent specified the key in the first arguement\n");
        else {
            encrypt(key, argc, argv);
            for (int i = 0; i < argc; i++) {
                printf("%s ", argv[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

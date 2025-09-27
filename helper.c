#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "helper.h"

void flush_input_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void string_to_upper(char *str){
    int i = 0;
    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
}
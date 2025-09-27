#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "output.h"

int main(){
    Edi *edi;
    inserir_edi(edi);
    write_to_file(edi);
    printf("Arquivo \"ediOutput.txt\" criado neste diretório\n");
    return 0;
}
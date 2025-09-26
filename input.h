#ifndef INPUT_H
#define INPUT_H
#include "listas.h"

#define STRING_SIZE 100

typedef struct Dados{
    char nome[STRING_SIZE], endereco[STRING_SIZE];
    char cidade[STRING_SIZE], telefone[STRING_SIZE];
    char cpf[STRING_SIZE], cnpj[STRING_SIZE];
}Dados;

typedef struct Edi{
    int codigoEstrutura, codigoTipo;
    char numeroNotaFiscal[STRING_SIZE], data[STRING_SIZE];
    Dados *dadosEmissor, *dadosReceptor;
    ListaProdutos linha;
    int numeroItens;
    float valorTotalNotas;
}Edi;

void string_to_upper(char *str);
void preencher_dados(Dados *dadosEmissor, Dados *dadosReceptor);
void inserir_edi(Edi *edi);

#endif
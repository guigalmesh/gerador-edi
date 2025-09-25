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
    int numeroNotaFiscal, data;
    Dados dadosEmissor, dadosEmissario;
    ListaProdutos linha;
    int numeroItens;
    float valorTotalNotas;
}Edi;

void inserir_edi();

#endif
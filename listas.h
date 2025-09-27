#ifndef LISTAS_H
#define LISTAS_H
#define STRING_SIZE 100

typedef struct ListaProdutos{
    char descricao[STRING_SIZE];
    int quantidade;
    float valorUnitario, valorTotal;
    struct ListaProdutos* prox;
}ListaProdutos;

struct Edi;
typedef struct Edi Edi;

ListaProdutos* cria_lista();
ListaProdutos* insere_lista(Edi *edi, ListaProdutos* l, char desc[STRING_SIZE], int q, float val);

#endif
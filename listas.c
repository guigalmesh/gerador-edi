#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "input.h"

ListaProdutos* cria_lista(){
    return NULL;
}

ListaProdutos* insere_lista(ListaProdutos* l, char desc[STRING_SIZE], int q, float val){
    ListaProdutos* novoNode = (ListaProdutos*)malloc(sizeof(ListaProdutos));
    if(novoNode == NULL){
        printf("Erro na alocação de novoNode\n");
        exit(1);
    }

    strcpy(novoNode->descricao, desc);
    novoNode->quantidade = q;
    novoNode->valorUnitario = val;
    novoNode->valorTotal = q * val;

    novoNode->prox = NULL;

    if (l == NULL) {
        return novoNode;
    } else {
        ListaProdutos* p_atual = l;
        while(p_atual->prox != NULL)
            p_atual = p_atual->prox;

        p_atual->prox = novoNode;
        return l;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "listas.h"

void write_to_file(Edi *edi){
    char *arquivoNome = "ediOutput.txt";
    FILE *arquivo = fopen(arquivoNome, "w");

    if(arquivo == NULL){
        printf("Falha ao abrir arquivo\n");
        exit(1);
    }

    fprintf(arquivo, "ST*%d*%d\n", edi->codigoTipo, edi->codigoEstrutura);
    fprintf(arquivo, "BG*%s*%s\n", edi->numeroNotaFiscal, edi->data);
    fprintf(arquivo, "N1*%s*%s*%s*%s*%s\n", 
        edi->dadosEmissor->nome, edi->dadosEmissor->endereco, 
        edi->dadosEmissor->cidade,edi->dadosEmissor->telefone, 
        edi->dadosEmissor->cpfCnpj);
    fprintf(arquivo, "N2*%s*%s*%s*%s*%s\n", 
        edi->dadosReceptor->nome, edi->dadosReceptor->endereco, 
        edi->dadosReceptor->cidade,edi->dadosReceptor->telefone, 
        edi->dadosReceptor->cpfCnpj);
    ListaProdutos* p = edi->linha;
    int cont = 0;
    while(p != NULL){
        cont++;
        fprintf(arquivo, "PO%d*%d*%s*%.2f*%.2f\n", cont, p->quantidade, 
            p->descricao, p->valorUnitario, 
            p->valorTotal);
        p = p->prox;
    }
    fprintf(arquivo, "CTT*%d*%.2f\n", edi->numeroItens, edi->valorTotalNotas);
    fprintf(arquivo, "SE*%s\n", edi->numeroNotaFiscal);
}
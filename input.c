#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "listas.h"

void string_to_upper(char *str){
    int i = 0;
    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
}

void preencher_dados(Dados *dadosEmissor, Dados *dadosReceptor){
    //Preenche dados da empresa que esta emitindo o EDI
    printf("Inserindo dados do emissor...\n");
    strcpy(dadosEmissor->nome, "EMPRESA NAVIO PIRATA LTDA");
    strcpy(dadosEmissor->endereco, "RUA MARIANO PROCOPIO, N347");
    strcpy(dadosEmissor->cidade, "SANTA MARIA");
    strcpy(dadosEmissor->telefone, "55991111111");
    strcpy(dadosEmissor->cnpj, "001010100-0001");
    strcpy(dadosEmissor->cpf, "056.456.500-42");
    printf("Dados do emissor inseridos\n");

    //Preenche dados da empresa que esta recebendo o EDI
    printf("Iniciando inserção de dados da empresa receptora...\n");
    char cpfOuCnpj;

    printf("Insira o nome da empresa: \n");
    fgets(dadosReceptor->nome, STRING_SIZE, stdin);
    string_to_upper(dadosReceptor->nome);

    printf("Insira o endereço da empresa: \n");
    fgets(dadosReceptor->endereco, STRING_SIZE, stdin);
    string_to_upper(dadosReceptor->endereco);

    printf("Insira cidade da empresa: \n");
    fgets(dadosReceptor->cidade, STRING_SIZE, stdin);
    string_to_upper(dadosReceptor->cidade);

    printf("Insira o telefone da empresa: \n");
    fgets(dadosReceptor->telefone, STRING_SIZE, stdin);
    string_to_upper(dadosReceptor->telefone);

    printf("Deseja inserir o CPF ou o CNPJ?\n['o' para CPF]\n['x' para CNPJ]\n");
    cpfOuCnpj = getchar();

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if(cpfOuCnpj == 'x'){
        printf("Insira o CNPJ: \n");
        fgets(dadosReceptor->cnpj, STRING_SIZE, stdin);
    }
    else{
        printf("Insira o CPF: \n");
        fgets(dadosReceptor->cpf, STRING_SIZE, stdin);
    }
    
    printf("\nInserção de dados do receptor concluída\n");
}

void inserir_edi(Edi *edi){
    char codigoTipo;
    edi->codigoEstrutura = 850;
    printf("A nota é de venda ou compra?\n['v' para venda]\n['c' para compra]\n");
    codigoTipo = getchar();
    edi->codigoTipo = codigoTipo == 'v' ? 5400 : 5700;
    printf("Digite o número da nota fiscal: \n");
    scanf("%99s", edi->numeroNotaFiscal);
    printf("Digite a data [EX: 09102020]\n");
    scanf("%99s", edi->data);

    edi->dadosEmissor = (Dados *)malloc(sizeof(Dados));
    edi->dadosReceptor = malloc(sizeof(Dados));

    preencher_dados(edi->dadosEmissor, edi->dadosReceptor);
}
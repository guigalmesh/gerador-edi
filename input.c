#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "listas.h"
#include "helper.h"

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

    flush_input_buffer();

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
    edi->dadosReceptor = (Dados *)malloc(sizeof(Dados));

    flush_input_buffer();
    preencher_dados(edi->dadosEmissor, edi->dadosReceptor);

    printf("Começando a inserção da descrição\n");

    edi->linha = cria_lista();

    int quantidade;
    float valorUnitario;
    char buffer[STRING_SIZE], inserir = 's';
    do{
        printf("Insira a quantidade: \n");
        scanf("%d", &quantidade);
        printf("Insira o valor unitario: \n");
        scanf("%f", &valorUnitario);
        printf("Insira a descrição sobre o produto: \n");
        flush_input_buffer();
        fgets(buffer, STRING_SIZE, stdin);
        printf("inserindo na lista\n");
        insere_lista(edi->linha, buffer, quantidade, valorUnitario);

        printf("Deseja inserir outra linha de produtos?\n['s' para continuar]\n['n' para parar]\n");
        inserir = getchar();
        flush_input_buffer();
        if(inserir == 'n')
            printf("Descrições inseridas\n");
        else
            printf("Inserindo nova descrição\n");
    }while(inserir != 'n');
}
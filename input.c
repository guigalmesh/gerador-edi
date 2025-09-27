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
    strcpy(dadosEmissor->cpfCnpj, "001010100-0001");
    printf("Dados do emissor inseridos\n");

    //Preenche dados da empresa que esta recebendo o EDI
    printf("Iniciando inserção de dados da empresa receptora...\n");
    char cpfOuCnpj;
    char buffer[100];

    printf("Insira o nome da empresa: \n");
    fgets(buffer, STRING_SIZE, stdin);
    string_to_upper(buffer);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(dadosReceptor->nome, buffer);

    printf("Insira o endereço da empresa: \n");
    fgets(buffer, STRING_SIZE, stdin);
    string_to_upper(buffer);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(dadosReceptor->endereco, buffer);

    printf("Insira cidade da empresa: \n");
    fgets(buffer, STRING_SIZE, stdin);
    string_to_upper(buffer);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(dadosReceptor->cidade, buffer);

    printf("Insira o telefone da empresa: \n");
    fgets(buffer, STRING_SIZE, stdin);
    string_to_upper(buffer);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(dadosReceptor->telefone, buffer);

    printf("Deseja inserir o CPF ou o CNPJ?\n['o' para CPF]\n['x' para CNPJ]\n");
    cpfOuCnpj = getchar();

    flush_input_buffer();

    if(cpfOuCnpj == 'x')
        printf("Insira o CNPJ: \n");
    else
        printf("Insira o CPF: \n");
    
    fgets(buffer, STRING_SIZE, stdin);
    string_to_upper(buffer);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(dadosReceptor->cpfCnpj, buffer);

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
    edi->numeroItens = 0;
    edi->valorTotalNotas = 0;
    int quantidade;
    float valorUnitario;
    char buffer[STRING_SIZE], inserir = 's';
    do{
        printf("Insira a quantidade: \n");
        scanf("%d", &quantidade);
        printf("Insira o valor unitario: \n");
        scanf("%f", &valorUnitario);
        edi->numeroItens += quantidade;
        edi->valorTotalNotas += valorUnitario * quantidade;

        printf("Insira a descrição sobre o produto: \n");
        flush_input_buffer();
        fgets(buffer, STRING_SIZE, stdin);
        string_to_upper(buffer);
        buffer[strcspn(buffer, "\n")] = '\0';
        insere_lista(edi, edi->linha, buffer, quantidade, valorUnitario);

        printf("Deseja inserir outra linha de produtos?\n['s' para continuar]\n['n' para parar]\n");
        inserir = getchar();
        flush_input_buffer();
        if(inserir == 'n')
            printf("Descrições inseridas\n");
        else
            printf("Inserindo nova descrição\n");
    }while(inserir != 'n');
}
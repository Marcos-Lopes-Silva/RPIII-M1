#include "clientes.h"
#include "locacao.h"
#include <stdio.h>
#include <stdlib.h>

void lerclientes(){
    FILE *arquivocliente;
    if((arquivocliente = fopen("cliente.txt","r")) == NULL) {
        printf("Erro de abertura! \n"); //tratamento de exceção para o arquivo
        printf("Retornando ao menu! \n");
    } else {
    fscanf(arquivocliente, "%d\n", &qtdcliente);
    clientes[qtdcliente];
    for(int i = 0; i < qtdcliente; i++){ //laço para leitura dos dados e atribuição nas variáveis
        fgets(c1.nome, 15, arquivocliente);//atribuição de nome
        fscanf(arquivocliente, "%li\n", &c1.cnh);//atribuição de cnh
        fscanf(arquivocliente, "%d\n", &c1.pontos);//atribuição de pontos
        clientes[i] = c1;
    }
    fclose(arquivocliente);
    }
};


void Clientes(){
    for(int i = 0; i < qtdcliente; i++){
        printf("Nome: %s", clientes[i].nome); //retorna o nome do cliente na tela
        printf("CNH: %li\n", clientes[i].cnh); //retorna a cnh na tela
        printf("Pontos: %d\n\n", clientes[i].pontos); //retorna os pontos do cliente na tela
    }
}

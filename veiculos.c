#include "veiculos.h"
#include "locacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerVeiculosDoArquivo(){
    FILE *arq = fopen("veiculos.txt", "r"); // abre arquivo para leitura
    //int i;
    if(arq){ // verifica se o arquivo foi aberto corretamente
        fscanf(arq, "%d\n", &qtdVeiculos); // lê a quantidade de veiculos existente no arquivo
        Vveiculos[qtdVeiculos];
        for(int i = 0; i < qtdVeiculos; i++){
            struct veiculo v; // cria uma variável do tipo veiculo
            fgets(v.placa, 15, arq); // lê uma string com tamanho máximo 15 e armazena em v.placa
            fgets(v.marca, 15, arq); // lê uma string com tamanho máximo 15 e armazena em v.marca
            fgets(v.modelo, 15, arq); // lê uma string com tamanho máximo 15 e armazena em v.modelo
            fscanf(arq, "%d\n", &v.ano); // lê o ano e uma quebra de linha e armazena em v.ano
            fscanf(arq, "%f\n", &v.km); // lê a quilometragem e uma quebra de linha e armazena em v.km
            fgets(v.categoria, 15, arq); // lê uma string com tamanho máximo 15 e armazena em v.categoria
            fscanf(arq, "%d\n", &v.situacao); // lê um um inteiro e armazena em v.situacao
            Vveiculos[i] = v; // insere no vetor de veiculos
        }
        fclose(arq); // fecha o arquivo
    }
    else{
        printf("ERRO: nao foi possivel abrir o arquivo.\n\n"); //exibe o erro na tela
    }

}


void imprimirVeiculos(int i){
    //int i;

        //printf("Qtd: %d\n", qtdVeiculo);
        printf("Placa: %s", Vveiculos[i].placa); //mostra a placa de um veiculo na tela
        printf("Marca: %s", Vveiculos[i].marca); //mostra a marca de um veiculo na tela
        printf("Modelo: %s", Vveiculos[i].modelo); //mostra o modelo de um veiculo na tela
        printf("Ano: %d\n", Vveiculos[i].ano); //mostra o ano de um veiculo na tela
        printf("Km: %f\n", Vveiculos[i].km); //mostra a quilometragem de um veiculo na tela
        printf("Categoria: %s", Vveiculos[i].categoria); //mostra a categoria de um veiculo na tela
        printf("Situacao: %d\n\n", Vveiculos[i].situacao); //mostra a situacao de um veiculo na tela

}

void cem(){
    system("cls");
    qtdCat = 0;
    int i;
    char cat[15] = "hatch\n";
    for(i = 0; i < qtdVeiculos; i++){
        int resultado = strcmp(Vveiculos[i].categoria, cat);
        if(resultado==0 && Vveiculos[i].situacao == 0){
            qtdCat++;
            imprimirVeiculosCat("hatch\n");
        }
    }
    if(qtdCat > 0){
        Locarplaca(2);
    }
}

void maiscem(){
    system("cls");
    qtdCat = 0;
    int i;
    char cat[15] = "sedan\n";
    for(i = 0; i < qtdVeiculos; i++){
        int resultado = strcmp(Vveiculos[i].categoria, cat);
        if(resultado==0 && Vveiculos[i].situacao == 0){
            qtdCat++;
            imprimirVeiculosCat("sedan\n");
            imprimirVeiculosCat("hatch\n");
          }
    }
    if(qtdCat > 0){
        Locarplaca(2);
    }
}

void maisquinhentos(){
    system("cls");
    qtdCat = 0;
    int i;
    char cat[15] = "suv\n";
    for(i = 0; i < qtdVeiculos; i++){
        int resultado = strcmp(Vveiculos[i].categoria, cat);
        if(resultado == 0 && Vveiculos[i].situacao == 0){
            qtdCat++;
            imprimirVeiculosCat("suv\n");
            imprimirVeiculosCat("sedan\n");
            imprimirVeiculosCat("hatch\n");
        }
    }
    if(qtdCat > 0){
        Locarplaca(2);
    }
}




void imprimirVeiculosCat(char cat[15]){
    if(qtdCat > 0){
        for(int i = 0; i < qtdVeiculos; i++){
            if(!strcmp(Vveiculos[i].categoria, cat) && Vveiculos[i].situacao != 1){

                //printf("Veiculo: %d\n", i+1);
                //printf("Qtd: %d\n", qtdVeiculosCat);
                printf("Placa: %s", Vveiculos[i].placa); //mostra a placa de um veiculo na tela
                printf("Marca: %s", Vveiculos[i].marca); //mostra a marca de um veiculo na tela
                printf("Modelo: %s", Vveiculos[i].modelo); //mostra o modelo de um veiculo na tela
                printf("Ano: %d\n", Vveiculos[i].ano); //mostra o ano de um veiculo na tela
                printf("Km: %f\n", Vveiculos[i].km); //mostra a quilometragem de um veiculo na tela
                printf("Categoria: %s", Vveiculos[i].categoria); //mostra a categoria de um veiculo na tela
                printf("Situacao: %d\n\n", Vveiculos[i].situacao); //mostra a situacao de um veiculo na tela
            }
        }
    }else{
        printf("Não tem nenhum veiculo disponível para sua pontuacao no momento.\n\n");
        qtdCat = 0;
    }
}

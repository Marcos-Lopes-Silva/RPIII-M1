#include "menu.h"
#include "veiculos.h"
#include "clientes.h"
#include "locacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(){

    int op=0;
    do{
        system("cls");
        printf("Bem vindo a LOCADORA PAMPA!\n");
        printf("Digite o número correspondente a opcao desejada.\n");
        printf("1-Locacao de Veiculo.\n");
        printf("2-Entrega de Veiculo.\n");
        printf("3-Busca Veiculo.\n");
        printf("4-Relatorio.\n");
        printf("5-SAIR\n");

        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            case 1:
                locarVeiculo();
            break;
            case 2:
                finalizaLocacao();

            break;
            case 3:
                buscaveiculo();
            break;
            case 4:
                imprimirRelatorio();
                //imprimirLocacoes();
                system("pause");
            break;
            case 5:
                exit(0);
            break;
            default:
                system("cls");
                printf("Opcao invalida selecionada.\n");
            break;
        }

    }while(op!=5);

}

void buscaveiculo(){
    char plc[15];
    printf("Insira a placa do veiculo que deseja consultar: ");
    scanf("%s", plc);
    system("cls");
    if(!buscalinear(Vveiculos, strcat(plc, "\n"), 1))
        system("pause");
}

void imprimirRelatorio(){
    //int i;

    printf("\nVeiculos Disponiveis:\n");
    for(int i = 0; i < qtdVeiculos; i++){
        if(Vveiculos[i].situacao==0){
            printf("Placa: %s", Vveiculos[i].placa); //mostra a placa de um veiculo na tela
            printf("Marca: %s", Vveiculos[i].marca); //mostra a marca de um veiculo na tela
            printf("Modelo: %s", Vveiculos[i].modelo); //mostra o modelo de um veiculo na tela
            printf("Ano: %d\n", Vveiculos[i].ano); //mostra o ano de um veiculo na tela
            printf("Km: %f\n", Vveiculos[i].km); //mostra a quilometragem de um veiculo na tela
            printf("Categoria: %s", Vveiculos[i].categoria); //mostra a categoria de um veiculo na tela
            printf("Situacao: Disponível\n\n");
        }
    }

    printf("\nVeiculos Alugados:\n");
    for(int i = 0; i < qtdVeiculos; i++){
        if(Vveiculos[i].situacao==1){
            printf("Placa: %s", Vveiculos[i].placa); //mostra a placa de um veiculo na tela
            printf("Marca: %s", Vveiculos[i].marca); //mostra a marca de um veiculo na tela
            printf("Modelo: %s", Vveiculos[i].modelo); //mostra o modelo de um veiculo na tela
            printf("Ano: %d\n", Vveiculos[i].ano); //mostra o ano de um veiculo na tela
            printf("Km: %f\n", Vveiculos[i].km); //mostra a quilometragem de um veiculo na tela
            printf("Categoria: %s", Vveiculos[i].categoria); //mostra a categoria de um veiculo na tela
            printf("Situacao: Alugado\n\n");
        }
    }

    printf("\nClientes:\n"); //exibe clientes
    Clientes();
}

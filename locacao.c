#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "locacao.h"
#include "veiculos.h"
#include "clientes.h"

#define KMHATCH 1.50
#define KMSEDAN 2.00;
#define KMSUV 2.50;
#define DHATCH 100.0;
#define DSEDAN 150.0;
#define DSUV 175.0;

struct locacao l;
int t, j, e;
float diarias;
char cat[15];
int antp;
char plca[15];

void locarVeiculo(){
    int doc;
    int i;
    int validaDoc=0; //usada como boolean para validar documento

    printf("Digite a CNH do cliente: ");
    scanf("%d", &doc);
    for(i = 0; i < qtdcliente; i++){
        if(doc == clientes[i].cnh){ //Percorre o vetor para ver se encontra o documento
            t = i;
            validaDoc = 1; //
            printf("O cliente pode escolher os seguintes carros de acordo com a pontuacao:\n");

            if(clientes[i].pontos <= 100){ //mostra na tela os veiculos disponíveis de acordo com a pontuação do cliente
                cem();

            }else if(clientes[i].pontos > 100 && clientes[i].pontos <= 500){
                maiscem();

            }else if(clientes[i].pontos > 500){
                maisquinhentos();
            }
        }
    }
    if(validaDoc == 0){
        printf("CNH nao encontrada");
    }
}

void calcularvalor(float newkm, float kmexc){
    float valorkm, valort, valord;
    int newp, antp;
    char sedan[15] = "sedan\n";
    char hatch[15] = "hatch\n";
    char suv[15] = "suv\n";

    if(!strcmp(hatch, cat)){
        valorkm = kmexc * KMHATCH;
        valord = diarias * DHATCH;
        valort = valorkm + valord;
    }
    if(!strcmp(sedan, cat)){
        valorkm = kmexc * KMSEDAN;
        valord = diarias * DSEDAN;
        valort = valorkm + valord;
    }
    if(!strcmp(suv, cat)){
        valorkm = kmexc * KMSUV;
        valord = diarias * DSUV;
        valort = valorkm + valord;
    }

    printf("O valor a pagar e de: R$ %.2f\n", valort);

    antp = clientes[t].pontos;
    newp = antp + kmexc;
    clientes[t].pontos = newp;

}

int buscalinear(struct veiculo* Veiculos, char* plc, int op){
    int s = 1;
    int i;
    int elem = 0;
    for(i = 0; i < qtdVeiculos; i++){
        elem = strcmp(Veiculos[i].placa, plc);

        if(elem == 0 && op == 1){
            imprimirVeiculos(i);
            return 0;
        }

        if(elem == 0 && op == 2){
            Vveiculos[i].situacao = s;
            j = i;
            return 0;
        }
        if(elem == 0 && op == 3){
            s = 0;
            Vveiculos[i].situacao = s;
            j = i;
            return 0;
        }
    }
    return -1;
}

int buscalocacao(struct locacao* L, char plc[15]){

    for(int i = 0; i < qtdLocacoes; i++){

        int elem = strcmp(L[i].placa, plc);
        if(elem == 0){
            strcpy(cat, L[i].categoria);
            j = i;
            return j;
        }
    }
    return -1;
}


void Locarplaca(int i){ //cria uma locação
    int x;

    do{
        printf("Insira a placa do veículo: \n");
        scanf("%s", plca);
        x = 2;
    }while(buscalinear(Vveiculos, strcat(plca, "\n"), x) == -1);//do while para ficar repetindo até a placa correta ser preenchida
    preencherLocacao();
}

void preencherLocacao(){
    int validaData = 0;
    int dia, mes, ano = 0;
    int s = 2;

    strcpy(l.nome, clientes[t].nome); //atribui o nome a struct locacao
    l.cnh = clientes[t].cnh; //atribui a cnh a struct locacao

    strcpy(l.categoria, Vveiculos[j].categoria);
    strcpy(l.placa, Vveiculos[j].placa);     //atribuicao do elementos do veiculo a locacao
    l.km = Vveiculos[j].km;
    l.situacao = Vveiculos[j].situacao;


    do{
        printf("Entre com a data da retirada do veiculo no formato dd/mm/aaaa: ");
        fflush (NULL);
        scanf("%d/%d/%d", &dia, &mes, &ano);
        validaData=dia_do_ano(dia, mes, ano);
        if(validaData==0){
            printf("\n******\nData inválida!\n******\n");
        }
    }while(validaData==0);
    l.dia=dia;
    l.mes=mes;
    l.ano=ano;

    buscalinear(Vveiculos, plca, s);//altera a situação para alugado
    Locacao[qtdLocacoes] = l; //adiciona a locação ao vetor de locações
    qtdLocacoes++;
}

void imprimirLocacoes(){ //exibe histórico de locações feitas
    int i;
    for(i = 0; i < qtdLocacoes; i++){
        printf("Nome: %s\n", Locacao[i].nome);
        printf("CNH: %li\n", Locacao[i].cnh);
        printf("Categoria: %s", Locacao[i].categoria);
        printf("Placa: %s", Locacao[i].placa);
        printf("Km: %f\n", Locacao[i].km);
        printf("Data: %d/%d/%d\n\n", Locacao[i].dia, Locacao[i].mes, Locacao[i].ano);
    }
}

void finalizaLocacao(){ //finalizar locacao
    imprimirLocacoes();
    int op = 3;
    char plc[15];
    float newkm;
    float kmexc;
    float antkm;


    printf("Informe a placa do veiculo que deseja remover: \n");
    scanf("%s", plc);
    fflush(stdin); // procura a placa na struct locacao

    if(buscalocacao(Locacao, strcat(plc, "\n")) != -1){//se a posição é valida

        if (j >= 0 && j < qtdLocacoes){ //se a posição é valida
            antkm = Locacao[j].km; //atribui a quilometragem antiga
            Locacao[j] = Locacao[--qtdLocacoes];//insere a ultima posição do vetor no lugar da remoção.
            p = realloc(p, qtdLocacoes * sizeof(locacao));//limpa a memoria
        }


        if(buscalinear(Vveiculos, plc, op) != -1){//busca a placa no vetor Veiculos para alterar a quilometragem
            printf("Insira a nova quilometragem: ");
            scanf("%f", &newkm);
            fflush(stdin);
            printf("Insira a quantidade de dias locados: "); // atribucao de variaveis para entrega
            scanf("%f", &diarias);
            fflush(stdin);

            Vveiculos[j].km = newkm;//insere a nova quilometragem no veiculo entregue
            kmexc = newkm - antkm;
            calcularvalor(newkm, kmexc); //funcao para calcular o valor da locacao
        }
        system("pause");
     }else{
        printf("Não foi possível localizar a locacao.\n"); //tratamento de exceção
    }
}




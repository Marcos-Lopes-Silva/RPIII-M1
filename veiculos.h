#ifndef VEICULOS_H_INCLUDED
#define VEICULOS_H_INCLUDED

int qtdVeiculos; //variavel global usada para ler a quantidade de veiculos no arquivo

typedef struct veiculo{ //cria um tipo de variavel (classe) chamada veiculo
    char placa[15]; //atributo da struct
    char marca[15]; //atributo da struct
    char modelo[15]; //atributo da struct
    int ano; //atributo da struct
    float km; //atributo da struct
    char categoria[15]; //atributo da struct
    int situacao; //0=disponível, 1=alugado
}veiculo;


struct veiculo Vveiculos[100];

void lerVeiculosDoArquivo();
void imprimirVeiculos();

void veiculosHatch();
void veiculosSedan();
void veiculosSuv();
void imprimirVeiculosCat();




#endif // VEICULOS_H_INCLUDED

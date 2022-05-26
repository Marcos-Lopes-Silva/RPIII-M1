#ifndef LOCACAO_H_INCLUDED
#define LOCACAO_H_INCLUDED

int qtdLocacoes;
int qtdCat;


typedef struct locacao{ //cria um tipo de variavel chamada locacao
    char nome[30]; //atributo do método
    long int cnh; //atributo do método
    char categoria[15]; //atributo do método
    char placa[15]; //atributo do método
    float km; //atributo do método
    int dia; //atributo do método
    int mes; //atributo do método
    int ano; //atributo do método
    int situacao;
}locacao;
struct locacao *p;
struct locacao Locacao[100]; //cria um vetor de locacao

void locarVeiculo();
void calcularvalor(float newkm, float kmexc);
//int buscalinear(struct veiculo* Veiculos, char* plc, int op);
int buscalocacao(struct locacao* L, char plc[15]);
void Locarplaca(int i);
void preencherLocacao();
void imprimirLocacoes();
void finalizaLocacao();

#endif // LOCACAO_H_INCLUDED

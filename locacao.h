#ifndef LOCACAO_H_INCLUDED
#define LOCACAO_H_INCLUDED

int qtdLocacoes;
int qtdCat;


typedef struct locacao{ //cria um tipo de variavel chamada locacao
    char nome[30]; //atributo do m�todo
    long int cnh; //atributo do m�todo
    char categoria[15]; //atributo do m�todo
    char placa[15]; //atributo do m�todo
    float km; //atributo do m�todo
    int dia; //atributo do m�todo
    int mes; //atributo do m�todo
    int ano; //atributo do m�todo
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

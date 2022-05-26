#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

int qtdcliente; //variavel para a contagem de clientes

typedef struct cliente{
    char nome[15]; //atributos do typedef cliente
    long int cnh;
    int pontos;
}cliente;

struct cliente clientes[5]; //vetor struct para clientes
struct cliente c1;

void lerclientes();
void nomecliente(char nome[40]);
void Clientes();

#endif // CLIENTES_H_INCLUDED

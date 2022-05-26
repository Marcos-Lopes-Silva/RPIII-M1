#include <stdio.h>
#include <stdlib.h>
#include "veiculos.h"
#include "clientes.h"
#include "menu.h"
#include "locacao.h"
#include "main.h"
#include "dias.h"

int main()
{
    lerVeiculosDoArquivo();
    lerclientes();

    menu();
}

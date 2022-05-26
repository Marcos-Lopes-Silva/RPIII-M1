#include "dias.h"
#include "veiculos.h"
#include "clientes.h"
#include "menu.h"
#include "locacao.h"
#include <stdio.h>
#include <stdlib.h>



//@fonte: https://www.pucsp.br/~so-comp/cursoc/gab3.html, Exercício 6: Página c480.html
//@autor: Curso de C do CPDEE/UFMG - 1996-1999

int dia_do_ano (int dia, int mes, int ano) {

   int ano_bissexto, data_valida = 0;  // Usadas como variaveis booleanas
   int total_dias = 0;

   /* Na atribuicao abaixo, se as condicoes forem satisfeitas, a variavel
      recebera' um valor maior do que 0. Esta variavel sera' usada para
      testes booleanos, mais abaixo... */

   ano_bissexto = ( ((ano % 4 == 0) && (ano % 100 > 0)) || (ano % 400 == 0) );

   if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 &&
       ano >= 1900 && ano <= 2100)     // Todos os dados nas faixas validas?
     if (mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
         mes == 8 || mes == 10 || mes == 12)
        data_valida = (dia <= 31);     // Estes meses tem 31 dias
     else
        if (mes == 2)                  // Fevereiro e' um caso a parte...
          if (ano_bissexto)            // Se o ano for bissexto
            data_valida = (dia <= 29); // o dia pode ir ate' 29
          else
            data_valida = (dia <= 28); // Senao, so' ate' 28
        else
          data_valida = (dia <= 30);   // Se chegou aqui, e' um mes de 30 dias


   if (data_valida) {

     /* O switch abaixo totaliza os dias decorridos dos meses anteriores
        ao digitado. Notem a ordem decrescente dos meses e a falta do
        comando "break" nos cases, fazendo com que todos os meses anteriores
        sejam somados... */

     switch (mes) {
        case 12: total_dias += 30;                  // do mes de novembro
        case 11: total_dias += 31;                  // do mes de outubro
        case 10: total_dias += 30;                  // do mes de setembro
        case  9: total_dias += 31;                  // do mes de agosto
        case  8: total_dias += 31;                  // do mes de julho
        case  7: total_dias += 30;                  // do mes de junho
        case  6: total_dias += 31;                  // do mes de maio
        case  5: total_dias += 30;                  // do mes de abril
        case  4: total_dias += 31;                  // do mes de marco
        case  3: total_dias += ano_bissexto?29:28;  // do mes de fevereiro
        case  2: total_dias += 31;                  // do mes de janeiro
     }

     total_dias += dia;  // Agora adicionamos os dias decorridos no mes atual
   }

   return (total_dias);  // E retornamos o valor; retorna 0 se data invalida
}

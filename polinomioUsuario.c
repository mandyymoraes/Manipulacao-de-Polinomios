#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"

int main()
{
    // abre para leitura os arquivos passados como parametro

    FILE *arq1 = fopen("polinomio1.txt", "r");
    FILE *arq2 = fopen("polinomio2.txt", "r");

    /*Verifica se o conteudo dos 2 arquivos não são nulos*/

    if (arq1 == NULL || arq2 == NULL)
    {
        printf("Arquivos com valor NULL \n");
        return 1;
    }

    // inicializa o contador de linhas dos arquivos com 1

    int linhasTxt1 = 1;
    int linhasTxt2 = 1;

    // Conta o número de linhas no arquivo txt do 1º polinomio
    /* o laço vai até o final do arquivo contando quantas linhas há no arquivo,
     quando ele encontra o final de uma linha ele soma 1 a quantidade de linhas*/

    char elemento;
    while ((elemento = fgetc(arq1)) != EOF)
    {
        if (elemento == '\n')
        {
            linhasTxt1++;
        }
    }
    // volta para o começo do arquivo
    rewind(arq1);

    // Conta o número de linhas no arquivo do 2º polinomio
    /* o laço vai até o final do arquivo contando quantas linhas há no arquivo,
     quando ele encontra o final de uma linha ele soma 1 a quantidade de linhas*/

    while ((elemento = fgetc(arq2)) != EOF)
    {
        if (elemento == '\n')
        {
            linhasTxt2++;
        }
    }
    // volta para o começo do arquivo
    rewind(arq2);

    // cria e aloca memoria para vetores (int) para receber os valores do arquivo (char)

    int *int_polinomio1 = malloc(linhasTxt1 * sizeof(int));
    int *int_polinomio2 = malloc(linhasTxt2 * sizeof(int));

    // le os coeficientes dos txt's

    /*Vai linha por linha no arquivo e pega o valor escrito*/

    for (int i = 0; i <= linhasTxt1; i++)
    {
        fscanf(arq1, "%d", &int_polinomio1[i]);
    }

    for (int i = 0; i <= linhasTxt2; i++)
    {
        fscanf(arq2, "%d", &int_polinomio2[i]);
    }

    // cria a estrutura dos polinomios a ser usados nas funções

    polinomio *polinomio1 = criar_polinomio(linhasTxt1, 0);
    polinomio *polinomio2 = criar_polinomio(linhasTxt2, 0);

    // le os valores pegos do arquivo e insere nos polinomios vazios

    ler_valores(polinomio1, int_polinomio1);
    ler_valores(polinomio2, int_polinomio2);

    // imprime os polinômios
    printf("Polinômio 1: ");
    mostrar_polinomio(*polinomio1);

    printf("Polinômio 2: ");
    mostrar_polinomio(*polinomio2);

    // fecha os arquivos
    fclose(arq1);
    fclose(arq2);

    /*----------------------------------------------------------------*/

    // agora que os elementos do arquivo foram pegos pode se começar a aplicar as funções

    // aplicação das funções

    // função de Substituição  e sua interação com o usuário que pede para selecionar qual polinomio é desejado para a substituição

    printf("Escolha o polinomio a ser substituido: [1] Polinomio 1 | [2] Polinomio 2: ");
    int escolhido;
    scanf("%d", &escolhido);

    printf("Digite um numero para ser aplicado a x:");
    int x;
    scanf("%d", &x);
    if (escolhido == 1)
    {
        substituir(*polinomio1, x);
    }
    else
    {
        substituir(*polinomio2, x);
    }

    // função que soma os polinomios

    printf("\n");
    printf("Soma dos 2 polinomios \n");
    soma_polinomios(*polinomio1, *polinomio2);
    printf("\n");

    // função que subtrai os polinomios e sua interação com o usuário que pede para selecionar a ordem desejada

    printf("Subtracao dos 2 polinomios \n");
    int escolha;
    printf("Como sera a operacao? \n");
    printf("[1] Polinomio 1 - Polinomio 2 \n");
    printf("[2] Polinomio 2 - Polinomio 1 \n");
    scanf("%d", &escolha);
    printf("\n");
    sub_polinomios(*polinomio1, *polinomio2, escolha);
    printf("\n");

    // função de multiplicação dos polinomios

    printf("Multiplicação dos 2 polinomios");
    printf("\n");
    mult_polinomios(*polinomio1, *polinomio2);

    // função de derivada e sua interação com o usuário que pede para selecionar qual o polinomio desejado

    printf("Derivada \n");
    printf("Qual polinomio será derivado? \n");
    printf("[1] Polinomio 1\n");
    printf("[2] Polinomio 2\n");
    int escolha_derivada;
    scanf("%d", &escolha_derivada);
    escolha_derivada == 1 ? derivada(*polinomio1) : derivada(*polinomio2);
    printf("\n");

    // função de integral indefinida e sua interação com o usuário para selecionar qual o polinomio desejado

    printf("Integral Indefinida \n");
    printf("Qual polinomio será integrado? \n");
    printf("[1] Polinomio 1\n");
    printf("[2] Polinomio 2\n");
    int escolha_integral;
    scanf("%d", &escolha_integral);
    int constante;
    printf("Qual vai ser o valor da constante: ");
    scanf("%d", &constante);
    escolha_integral == 1 ? integral_indefinida(*polinomio1, constante) : integral_indefinida(*polinomio2, constante);

    // função de integral definida e sua interação com o usuário para selecionar qual vai ser o polinomio utilizado

    printf("Integral Definida");
    printf("\n");
    printf("Qual polinomio para ser integrado da forma definida? \n");
    printf("[1] Polinomio 1\n");
    printf("[2] Polinomio 2\n");
    int escolha_integral_definida;
    scanf("%d", &escolha_integral_definida);
    int limiteSuperior;
    int limiteInferior;
    printf("Limite Superior: ");
    scanf("%d", &limiteSuperior);
    printf("Limite Inferior: ");
    scanf("%d", &limiteInferior);
    printf("Integral definida:\nIntervalo: [%d, %d]\n", limiteInferior, limiteSuperior);
    escolha_integral_definida == 1 ? 
    integral_definida(*polinomio1, limiteInferior, limiteSuperior) 
    : integral_definida(*polinomio2, limiteInferior, limiteSuperior);

    // função que realiza o metodo de newton-raphson e sua interação com o usuário para selecionar qual polinomio será utilizado

    printf("Newton-Rapson");
    printf("\n");
    int iteracao;
    float x_inicial;
    float tolerancia;
    printf("Digite o numero de iteracoes: ");
    scanf("%d",&iteracao);
    printf("Inicio: x ");
    scanf("%d",&x_inicial);
    printf("Valor da tolerancia: ");
    scanf("%d",&tolerancia);
     printf("Qual polinomio para ser realizado o metodo de newton-raphson? \n");
    printf("[1] Polinomio 1\n");
    printf("[2] Polinomio 2\n");
    int escolha_newton_raphson;
    scanf("%d", &escolha_newton_raphson);
    escolha_newton_raphson == 1 ? 
    newton_raphson(*polinomio1, iteracao, x_inicial, tolerancia) 
    : newton_raphson(*polinomio2, iteracao, x_inicial, tolerancia);


    // depois de todas as funções realizadas é feito o free dos polinomios criados 
    // libera os mallocs feitos para cada polinomio criado

    // libera a memoria dos polinomios convertidos de char para int para assim realizar as contas
    free(int_polinomio1);
    free(int_polinomio2);

    // 
    free(polinomio1->coeficientes);
    free(polinomio1);
    free(polinomio2->coeficientes);
    free(polinomio2);

    return 0;
}

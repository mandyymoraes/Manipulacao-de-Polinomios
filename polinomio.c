#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"

/*estrutura da função que cria a estruturação do polinomio*/
polinomio* criar_polinomio(int linhasTxt, int primeiro)
{
    // aloca dinamicamente a memoria do polinomio e verifica se o conteudo do ponteiro dele não é nulo

    polinomio *p = malloc(sizeof(polinomio));
    if (p == NULL)
    {
        printf("Valor NULL para o ponteiro do polinomio, memoria não alocada");
        return NULL;
    }

    // a quantidade de linhas do txt do struct recebe o valor passado na função
    p->linhasTxt = linhasTxt;

    // verifica se o arquivo txt passado tem conteudo ou é vazio
    if (linhasTxt <= 0)
    {
        p->coeficientes = NULL;
    }
    else
    {
        /* aloca memoria para o vetor de coeficientes do struct, utiliza como parametro de alocação a 
        quantidade de linhas obtidas do arquivo - como é 1 coeficiente por linha - a quantidade de linhas equivale 
        a quantidade de coeficientes
        */
        p->coeficientes = malloc(linhasTxt * sizeof(int));
        if (p->coeficientes == NULL)
        {
            printf("O vetor de coeficientes do polinomio não foi alocado");
            free(p);
            return NULL;
        }

        // inicialização das posições do array de coeficientes do struct com um valor inicial passado

        for (int i = 0; i <= p->linhasTxt; i++)
        {
            p->coeficientes[i] = primeiro;
        }
    }

    return p;
}

/*estrutura da função que le os valores do polinomio pelo arquivo*/
void ler_valores(polinomio *p, int *arrayCoeficientes)
{
    /* alocação dinamica de memoria para o array que possui os coeficientes do polinomio
    com base na quantidade de linhas do arquivo*/
    p->coeficientes = malloc(p->linhasTxt * sizeof(int));
    for (int i = 0; i <= p->linhasTxt; i++)
    {
        p->coeficientes[i] = arrayCoeficientes[i];
    }
}

/*estrutura da função que printa o polinomio formatado*/
void mostrar_polinomio(polinomio p)
{
    /*Printa os valores do polinomio formatados para a estrutura matemática*/

    for (int i = 0; i < p.linhasTxt; i++)
    {
        // verifica se o valor é maior que 0 para pode atribuir o valor de + na frente
        if (p.coeficientes[i] >= 0)
        {
            printf("+%dx^%d ", p.coeficientes[i], i);
        }
        else
        // se o valor for negativo ele já vem com o sinal negativo do arquivo txt
        {
            printf("%dx^%d ", p.coeficientes[i], i);
        }
    }
    printf("\n");
}

/*estrutura da função que substitui um valor passado no polinomio */
int substituir(polinomio p, int x)
{
    // substitui no polinomio passado o valor de "x"
    int soma = 0;
    for (int i = 0; i < p.linhasTxt; i++)
    {
        soma += p.coeficientes[i] * pow(x, i);
    }
    printf("O polinomio com x = %d : %d \n", x, soma);
    // retorna a soma para ela futuramente ser usada na funçaõ de newton-raphson
    return soma;
}

/*estrutura da função que faz a soma dos 2 polinomios*/
void soma_polinomios(polinomio p1, polinomio p2)
{

    /*verifica se os polinomios são de tamanhos compativeis, se não forem é adicionado "0"
     ao final do menor para igualar, 0 é elemento neutro da soma então não vai alterar o resultado final*/

    if (p1.linhasTxt != p2.linhasTxt)
    {
        if (p1.linhasTxt > p2.linhasTxt)
        {
            for (int i = p2.linhasTxt; i < p1.linhasTxt; i++)
            {
                p2.coeficientes[i] = 0;
                p2.linhasTxt++;
            }
        }
        if (p1.linhasTxt < p2.linhasTxt)
        {
            for (int i = p1.linhasTxt; i < p2.linhasTxt; i++)
            {
                p1.coeficientes[i] = 0;
                p1.linhasTxt++;
            }
        }
    }

    /* cria o polinomio soma, como agora depois de igualados os valores de p1 e p2 são iguais é usado como 
    tamanho do polinomio soma o tamanho de um deles*/

    polinomio *soma = criar_polinomio(p1.linhasTxt, 0);
    for (int i = 0; i < p1.linhasTxt; i++)
    {
        soma->coeficientes[i] = p1.coeficientes[i] + p2.coeficientes[i];
    }
    mostrar_polinomio(*soma);
}

/*estrutura da função que faz a substração dos 2 polinomios*/
void sub_polinomios(polinomio p1, polinomio p2, int escolha)
{

    /* verifica se eles são de tamanhos compativeis, se não forem
     é adicionado "0" para igualar -> mesmo processo da função soma*/

    // o parametro escolha -> mostra qual polinomio vai ser subtraido (varia o resultado se mudar de posição)

    if (p1.linhasTxt != p2.linhasTxt)
    {
        if (p1.linhasTxt > p2.linhasTxt)
        {
            for (int i = p2.linhasTxt; i < p1.linhasTxt; i++)
            {
                p2.coeficientes[i] = 0;
                p2.linhasTxt++;
            }
        }
        if (p1.linhasTxt < p2.linhasTxt)
        {
            for (int i = p1.linhasTxt; i < p2.linhasTxt; i++)
            {
                p1.coeficientes[i] = 0;
                p1.linhasTxt++;
            }
        }
    }

    /*cria o polinomio subrtracao para armazenar a subtracao entre os dois */

    polinomio *subtracao = criar_polinomio(p1.linhasTxt, 0);
    if (escolha == 1)
    {
        for (int i = 0; i < p1.linhasTxt; i++)
        {
            subtracao->coeficientes[i] = p1.coeficientes[i] - p2.coeficientes[i];
        }
    }
    else
    {
        for (int i = 0; i < p1.linhasTxt; i++)
        {
            subtracao->coeficientes[i] = p2.coeficientes[i] - p1.coeficientes[i];
        }
    }

    mostrar_polinomio(*subtracao);
}

/*estrutura da função que multiplica os 2 polinomios*/
void mult_polinomios(polinomio p1, polinomio p2)
{

    /* verifica se eles são de tamanhos compativeis, se não forem é adicionado "1" para igualar
    mesmo processo das funções de soma e subtração, apenas que agora se é adicionado 1 ao final

    1 é elemento neutro da multiplicação */

    if (p1.linhasTxt != p2.linhasTxt)
    {
        if (p1.linhasTxt > p2.linhasTxt)
        {
            for (int i = p2.linhasTxt; i < p1.linhasTxt; i++)
            {
                p2.coeficientes[i] = 1;
                p2.linhasTxt++;
            }
        }
        if (p1.linhasTxt < p2.linhasTxt)
        {
            for (int i = p1.linhasTxt; i < p2.linhasTxt; i++)
            {
                p1.coeficientes[i] = 1;
                p1.linhasTxt++;
            }
        }
    }

    /*cria o polinomio multiplicacao para armazenar a multiplicação entre os 2 polinomios*/

    polinomio *multiplicacao = criar_polinomio(p1.linhasTxt, 0);

    for (int i = 0; i < p1.linhasTxt; i++)
    {
        multiplicacao->coeficientes[i] = p1.coeficientes[i] * p2.coeficientes[i];
    }

    mostrar_polinomio(*multiplicacao);
}

/*estrutura da função que calcula a derivada do polinomio passado*/
polinomio derivada(polinomio p)
{

    /*criar um polinomio para guardar o polinomio derivado -> o polinomio tem o tamanho menor que o polinomio passado
    porque a derivada retira a constante, que no caso é o x^0*/
    polinomio *polinomio_derivado = criar_polinomio(p.linhasTxt - 1, 0);
    for (int i = 1; i < p.linhasTxt; i++)
    {
        polinomio_derivado->coeficientes[i - 1] = p.coeficientes[i] * i;
    }
    printf("\n");
    mostrar_polinomio(*polinomio_derivado);
    //retorna o polinomio para futuramente ele ser usado na função de newton-raphson
    return *polinomio_derivado;
}

/*estrutura da função que printa o polinomio da integral indefinida formatado*/
void print_polinomio_integrado(polinomio p, int k)
{
    // printa o polinomio integrado da forma indefinida formatado -> soma o expoente com + 1

    for (int i = 0; i < p.linhasTxt; i++)
    {
        if (p.coeficientes[i] >= 0)
        {
            printf("+%d x^%d ", p.coeficientes[i], i + 1);
        }
        else
        {
            printf("%d x^%d ", p.coeficientes[i], i + 1);
        }
    }
    printf("+ %d", k);
    printf("\n");
}

/*estrutura da função que calcula a integral indefinida do polinomio passado*/
polinomio integral_indefinida(polinomio p, int k)
{

    /*cria um polinomio novo para guardar o polinomio integrado */
    polinomio *polinomio_integrado = criar_polinomio(p.linhasTxt, 0);
    
    // realiza a conta da integração indefinida
    for (int i = 0; i < p.linhasTxt; i++)
    {
        polinomio_integrado->coeficientes[i] = p.coeficientes[i] / (i + 1);
    }
    printf("\n");
    // chama a função que vai realizar o print formatado para esse polinomio
    print_polinomio_integrado(*polinomio_integrado, k);
    // retorna ele para futuramente ele ser usado na função de integral definida
    return *polinomio_integrado;
}

/*estrutura da função que calcula a integral definida do polinomio passado*/
void integral_definida(polinomio p, int limiteSuperior, int limiteInferior)
{
    
    polinomio *polinomio_integrado_definido = criar_polinomio(p.linhasTxt, 0);
    /* no polinomio criado ele recebe o valor do polinomio passado integrado da forma indefinida realizado pela chamada 
    da função intergral_indefinida */
    *polinomio_integrado_definido = integral_indefinida(p, 0);

    int soma = 0;
    for (int i = 0; i < p.linhasTxt; i++)
    {
        soma += (polinomio_integrado_definido->coeficientes[i] * pow(limiteSuperior, i + 1)) - (polinomio_integrado_definido->coeficientes[i] * pow(limiteInferior, i + 1));
    }
    printf("\n");
    printf("Resultado: %d\n", soma);
}

/*estrutura da função que calcula  o metodo de newton raphson do polinomio passado*/
void newton_raphson(polinomio p, int iteracao, float x_inicial, float tolerancia)
{
    int i = 0;
    float x0 = x_inicial;
    float margem = tolerancia + 1;

    while (margem >= tolerancia && i <= iteracao)
    {
        int polinomioSubstituido = substituir(p, x0);
        polinomio *polinomio_derivado = criar_polinomio(p.linhasTxt - 1, 0);
        *polinomio_derivado = derivada(p);
        int derivadaSubstituida = substituir(*polinomio_derivado, x0);

        if (derivadaSubstituida == 0)
        {
            printf("Derivada igual a zero\n");
            return;
        }

        float x1 = x0 - (float)polinomioSubstituido / derivadaSubstituida;
        margem = fabs(x1 - x0);
        x0 = x1;
        i++;
    }

    if (i == iteracao)
    {
        printf("Raiz não encontrada a partir do valor de tolerancia passado\n");
    }
    else
    {
        printf("A raiz do polinomio eh: %f\n", x0);
    }
}

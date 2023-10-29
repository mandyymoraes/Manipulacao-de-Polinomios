
/*Struct de criação do polinomio, os dados do polinomio serão armazenados em um array, e a quantidade de linhas do arquivo
txt correspondente ao polinomio 

- O valor das linhas são usados para realizar os loops para passar pelos valores do polinomio 

*/
typedef struct {
    int *coeficientes;
    int linhasTxt;
} polinomio;

/*Cria a estrutura de um polinomio novo, recebe como parametro a quantidade de linhas do txt e um valor inicial para 
inicializar o vetor dos dados*/
polinomio* criar_polinomio(int linhasTxt, int primeiro);

/*le os valores que foram retirados do arquivo txt e armazenados em um array -> por laço "for" eles são lidos e armazenados
na estrutura definida do polinomio */

void ler_valores(polinomio *p, int *arrayCoeficientes);

// por meio de um loop "for" da um print formatado no coeficiente do polinomio
void mostrar_polinomio(polinomio p);

// substitui no polinomio passado como parametro o valor que deve ser substituido o "x"
int substituir(polinomio p, int x);

//soma os dois polinomios passados 
void soma_polinomios(polinomio p1, polinomio p2);

/* subtrai os dois polinomios passados -> o parametro de escolha é para determinar qual vai ser 
o subtraido, se muda a ordem o valor fica diferente*/
void sub_polinomios(polinomio p1, polinomio p2, int escolha);

// multiplica os dois polinomios 
void mult_polinomios(polinomio p1, polinomio p2);

// faz a derivada do polinomio passado 
polinomio derivada(polinomio p);

// faz a integral indefinida do polinomio passado, tem como parametro tambem a constante 
polinomio integral_indefinida(polinomio p, int k);

/*faz a integral definida com base na indefinida do polinomio - a indefinida é chamada dentro dessa função 
recebe tambem os valores do limites inferior e superior */
void integral_definida(polinomio p, int limiteSuperior, int limiteInferior);

/* faz a aproximação da raiz por meio do metodo de newton-raphson, ela recebe o polinomio
a ser achada a raiz, a quantidade de vezes que deve ser tentada a aproximação, o valor inicial
 do x e o valor da tolerancia do valor*/
void newton_raphson(polinomio p, int iteracao, float x_inicial, float tolerancia);


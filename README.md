# Biblioteca de Manipulação de Polinômios

## Sobre

### Projeto realizado para a aula de Algoritmos e Técnicas de Programação II

Consiste na criação de uma biblioteca que manipula e realiza operações matemáticas com dois polinômios passados via arquivo .txt

Operaçãoes desenvolvidas: 

* Soma 
* Subtração
* Multiplicação 
* Substituição da incógnita por um valor qualquer
* Derivada
* Integral Indefinida
* Integral Definida 
* Método de aproximação de raízes de Newton-Raphson

## Estrutura

O código consiste na leitura de dois arquivos passados que contem os valores dos coeficientes dos polinômios (o primeiro valor do arquivo consiste no coeficiente de menor expoente), e a partir da leitura dos valores eles são inseridos via `struct` em um vetor que é utilizado como parâmetro nas funções das operações, e com base na escolha do usuário o vetor do polinômio selecionado é utilizado. 

<code>polinomio.h</code> -> arquivo de refencia para os métodos implementados

<code>polinommio.c</code> -> implementação dos métodos

<code>polinomioUsuario.c</code> -> interação com o usuário e chamada dos métodos

<code> polinomio1.txt </code> e <code>polinomio2.txt</code> -> contém os valores dos coeficientes dos polinômios, os valores podem ser alterados ou adicionados conforme a vontade do usuário, apenas modifique os valores no próprio arquivo <code>.txt</code>


## Run

### Pré - Requisitos

* Compilador [MinGW](https://www.mingw-w64.org/)
* Download [MinGW](https://sourceforge.net/projects/mingw/)

### Como rodar o projeto?

  ```sh
  gcc polinomio.c polinomioUsuario.c -o polinomio
  ```

  ```sh
  ./polinomio 
  ```
se o uso do ./ não executar o arquivo, retire o ./ e apenas use no terminal

  ```sh
  polinomio
  ```

### Habilidades Desenvolvidas 

* Structs
* Estruturação de métodos
* Ponteiros
* Processamento e Leitura de Arquivos





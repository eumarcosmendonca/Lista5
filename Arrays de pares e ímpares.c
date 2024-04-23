/*
Neste problema você deverá ler 15 valores colocá-los em 2 arrays conforme estes valores forem pares ou ímpares. Só que o tamanho de cada um dos dois arrays é de 5 posições. Então, cada vez que um dos dois arrays encher, você deverá imprimir todo o array e utilizá-lo novamente para os próximos números que forem lidos. Terminada a leitura, deve-se imprimir o conteúdo que restou em cada um dos dois arrays, imprimindo primeiro os valores do array ímpar. Cada array pode ser preenchido tantas vezes quantas for necessário.
*/

#include <stdio.h>

void printNegativo(int arrayNegativo[], int inicio, int final) {
    if (inicio == final) {
        return;
    }
    else {
        printf("impar[%d] = %d", inicio, arrayNegativo[inicio]);
        printf("\n");
        printNegativo(arrayNegativo, inicio + 1, final);
    }
}

void printPositivo(int arrayPositivo[], int inicio, int final) {
    if (inicio == final) {
        return;
    }
    else {
        printf("par[%d] = %d", inicio, arrayPositivo[inicio]);
        printf("\n");
        printPositivo(arrayPositivo, inicio + 1, final);
    }
}

void entradaDados(int arrayPositivo[], int arrayNegativo[], int inicio, int final, int posicaoPositivo, int posicaoNegativo) {

    int numero;
    if (inicio == final) {
        printNegativo(arrayNegativo, 0, posicaoNegativo);
        printPositivo(arrayPositivo, 0, posicaoPositivo);
        return;
    }
    else {
        scanf("%d", &numero);
        if (numero % 2 == 0) {
            arrayPositivo[posicaoPositivo] = numero;
            posicaoPositivo = posicaoPositivo + 1;
        }
        if (numero % 2 != 0) {
            arrayNegativo[posicaoNegativo] = numero;
            posicaoNegativo = posicaoNegativo + 1;
        }
        if (posicaoPositivo == 5) {
            printPositivo(arrayPositivo, 0, 5);
            posicaoPositivo = 0;
        }
        if (posicaoNegativo == 5) {
            printNegativo(arrayNegativo, 0, 5);
            posicaoNegativo = 0;
        }
        entradaDados(arrayPositivo, arrayNegativo, inicio + 1, final, posicaoPositivo, posicaoNegativo);
    }

}

int main() {

    int numeros = 15;
    int arrayPositivo[5];
    int arrayNegativo[5];

    entradaDados(arrayPositivo, arrayNegativo, 0, 15, 0, 0);

    return 0;

}
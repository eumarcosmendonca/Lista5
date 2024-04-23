/*
O professor pythonildo é viciado em ordenação e tem o desejo de ordenar tudo que encontrar logo faz isso com as notas de seus alunos, todo fim de semana ele corrige as provas passadas e as coloca em ordem, entretanto sua mania de ordenação tem uma necessidade de ordenar de ambas maneiras, crescente e decrescente.
OBS.1: O número da turma inicia em 1
OBS.2: Todos os números são inteiros
OBS.3: Na saída não tem espaço antes da quebra de linha
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(int array[], int inicio, int final) {
    if (inicio == final - 1) {
        printf("%d", array[inicio]);
        return;
    }
    printf("%d ", array[inicio]);
    return print(array, inicio + 1, final);
}

void bubbleDecrescente(int array[], int i, int tamanho) {

    if (i == tamanho - 1) {
        return;
    }
    else {
        if (array[i] < array[i + 1]) {
            int aux = array[i];
            array[i] = array[i + 1];
            array[i + 1] = aux;
        }
        bubbleDecrescente(array, i + 1, tamanho);
    }

}

void bubbleSortDecrescente(int array[], int tamanho) {

    if (tamanho == 0) {
        return;
    }
    else {
        bubbleDecrescente(array, 0, tamanho);
        bubbleSortDecrescente(array, tamanho - 1);
    }

}

void bubbleCrescente(int array[], int i, int tamanho) {

    if (i == tamanho - 1) {
        return;
    }
    else {
        if (array[i] > array[i + 1]) {
            int aux = array[i];
            array[i] = array[i + 1];
            array[i + 1] = aux;
        }
        bubbleCrescente(array, i + 1, tamanho);
    }

}

void bubbleSortCrescente(int array[], int tamanho) {

    if (tamanho == 0) {
        return;
    }
    else {
        bubbleCrescente(array, 0, tamanho);
        bubbleSortCrescente(array, tamanho - 1);
    }

}

void lancamentoNotas(int array[], int inicio, int final) {
    int nota;
    if (inicio == final) {
        return;
    }
    else {
        scanf("%d", &nota);
        array[inicio] = nota;
        lancamentoNotas(array, inicio + 1, final);
    }
}

void entradaDados(int array[], int inicio, int final) {
    if (inicio == final) {
        return;
    }
    else {
        printf("turma %d:", inicio + 1);
        printf("\n");
        lancamentoNotas(array, 0, 10);
        bubbleSortCrescente(array, 10);
        print(array, 0, 10);
        printf("\n");
        bubbleSortDecrescente(array, 10);
        print(array, 0, 10);
        printf("\n");
        entradaDados(array, inicio + 1, final);
    }
}

int main() {
    
    int numero;
    int array[10];

    scanf("%d", &numero);

    entradaDados(array, 0, numero);

    return 0;

}
/*
Você vai receber uma lista com n valores e deve retornar o i-essímo maior valor.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(int array[], int posicao) {
    printf("%d", array[posicao - 1]);
    return;
}

void scan(int array[], int inicio, int final) {
    if (inicio == final) {
        return;
    }
    else {
        scanf("%d", &array[inicio]);
        scan(array, inicio + 1, final);
    }
}

void bubble(int array[], int i, int tamanho) {
    if (i == tamanho - 1) {
        return;
    }
    else {
        if (array[i] < array[i + 1]) {
            int aux = array[i];
            array[i] = array[i + 1];
            array[i + 1] = aux;
        }
        bubble(array, i + 1, tamanho);
    }
}

void bubbleSort(int array[], int tamanho) {
    if (tamanho == 0) {
        return;
    }
    else {
        bubble(array, 0, tamanho);
        bubbleSort(array, tamanho - 1);
    }
}

int main() {
    
    int tamanho, parametro;

    scanf("%d", &tamanho);
    scanf("%d", &parametro);

    int array[tamanho];

    scan(array, 0, tamanho);
    bubbleSort(array, tamanho);
    print(array, parametro);

    return 0;

}
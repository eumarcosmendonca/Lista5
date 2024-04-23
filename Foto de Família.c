/*
Ambrosina é uma fotógrafa muito peculiar. Ela só aceita tirar fotos de pessoas se as pessoas estiverem em grupos de exatamente 04 pessoas. Tudo isso porque Ambrosina tem uma mania esquisita de ordenação. Para ela, a pessoa mais baixa deve ficar sempre do lado esquerdo, a segunda mais baixa do lado direito, no meio, logo após a mais baixa, fica a terceira mais baixa e em seguida a mais alta.
*/

#include <stdio.h>

void bubble(double array[], int i, int tamanho) {

    if (i == tamanho - 1) {
        return;
    }
    else {
        if (array[i] > array[i + 1]) {
            double aux = array[i];
            array[i] = array[i + 1];
            array[i + 1] = aux;
        }
        bubble(array, i + 1, tamanho);
    }

}

void bubbleSort(double array[], int tamanho) {

    if (tamanho == 0) {
        return;
    }
    else {
        bubble(array, 0, tamanho);
        bubbleSort(array, tamanho - 1);
    }

}

void entradaDados(double array[], int inicio, int final) {

    if (inicio == final) {
        bubbleSort(array, 4);
        printf("%.2lf\n", array[0]);
        printf("%.2lf\n", array[2]);
        printf("%.2lf\n", array[3]);
        printf("%.2lf\n", array[1]);
        return;
    }
    else {
        double numero;
        scanf("%lf", &numero);
        array[inicio] = numero;
        entradaDados(array, inicio + 1, final);
    }

}

int main() {

    double array[4];

    entradaDados(array, 0, 4);

    return 0;

}
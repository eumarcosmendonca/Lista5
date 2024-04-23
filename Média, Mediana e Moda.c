/*
Você vai receber uma lista com n inteiros e deverá retornar a média aritmética, a moda e a mediana dessa lista.
Obs: Caso haja duas modas, informe aquela com o maior valor.
*/

#include <stdio.h>

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

double calcularModa(int array[], int inicio, int final, double moda, int contador, int auxiliar, double resultadoModa) {

    if (inicio == final) {
        return resultadoModa;
    }
    if (array[inicio] == array[inicio - 1]) {
        contador = contador + 1;
    }
    else {
        contador = 1;
    }
    if (contador > auxiliar) {
        resultadoModa = array[inicio];
        auxiliar = contador;
    }
    else if (contador == auxiliar && array[inicio] > resultadoModa) {
        resultadoModa = array[inicio];
    }
    return calcularModa(array, inicio + 1, final, moda, contador, auxiliar, resultadoModa);

}

double calcularMediana(int array[], int numero, double resultadoMediana) {

    int posicao, posicao1, posicao2;
    if (numero % 2 == 0) {
        posicao1 = (numero / 2);
        posicao2 = ((numero / 2) - 1);
        resultadoMediana = ((array[posicao1] + array[posicao2]) / 2.0);
        return resultadoMediana;
    }
    if (numero % 2 != 0) {
        posicao = (numero) / 2;
        resultadoMediana = array[posicao];
        return resultadoMediana;
    }

}

double calcularMedia(int array[], int contador, int final, int numero, double resultadoMedia) {

    if (contador == final) {
        return resultadoMedia / numero;
    }
    else {
        resultadoMedia = resultadoMedia + array[contador];
        calcularMedia(array, contador + 1, final, numero, resultadoMedia);
    }

}

void lista(int array[], int contador, int final) {

    int n;
    if (contador == final) {
        return;
    }
    else {
        scanf("%d", &n);
        array[contador] = n;
        lista(array, contador + 1, final);
    }

}

int main() {

    int numero;
    scanf("%d", &numero);
    int array[numero];

    lista(array, 0, numero);
    bubbleSort(array, numero);
    double resultadoMedia = calcularMedia(array, 0, numero, numero, 0);
    double resultadoMediana = calcularMediana(array, numero, 0);
    double resultadoModa = calcularModa(array, 1, numero, array[0], 1, 1, array[0]);

    printf("%.2lf ", resultadoMedia);
    printf("%.2lf ", resultadoMediana);
    printf("%.2lf", resultadoModa);

    return 0;

}
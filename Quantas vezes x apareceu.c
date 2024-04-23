/*
Leia 10 números inteiros.
Depois leia mais um número inteiro x.
Sua missão é imprimir quantas vezes x apareceu entre os 10 primeiros inteiros lidos.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int leituraDados(int arrayNumeros[], int posicao, int contador, int parametro, int resultado) {
    if (contador == 0) {
        return resultado;
    }
    else {
        if (arrayNumeros[posicao] == parametro) {
            resultado++;
        }
        leituraDados(arrayNumeros, posicao + 1, contador - 1, parametro, resultado);
    }
}

void entradaDados(int arrayNumeros[], int posicao, int contador) {
    int numero, parametro;
    if (contador == 0) {
        scanf("%d", &parametro);
        int resultado = leituraDados(arrayNumeros, 0, 10, parametro, 0);
        printf("%d", resultado);
        return;
    }
    else {
        scanf("%d", &numero);
        arrayNumeros[posicao] = numero;
        entradaDados(arrayNumeros, posicao + 1, contador - 1);
    }
}

int main() {
    
    int arrayNumeros[10];

    entradaDados(arrayNumeros, 0, 10);

    return 0;

}
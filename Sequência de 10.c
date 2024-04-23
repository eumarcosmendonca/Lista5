/*
Faça um programa que leia uma sequência de 10 números e informe o total de ocorrências do último número lido.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int verificador(int arrayNumeros[], int parametro, int contador, int final, int quantidade) {
    if (contador == final) {
        return quantidade;
    }
    else {
        if (arrayNumeros[contador] == parametro) {
            quantidade = quantidade + 1;
        }
        verificador(arrayNumeros, parametro, contador + 1, final, quantidade);
    }
}

void entradaDados(int arrayNumeros[], int contador, int final) {
    int numero, parametro, resultado;
    if (contador == final) {
        parametro = arrayNumeros[final - 1];
        resultado = verificador(arrayNumeros, parametro, 0, 10, 0);
        printf("O numero %d apareceu %d vezes", parametro, resultado);
        return;
    }
    else {
        scanf("%d", &numero);
        arrayNumeros[contador] = numero;
        entradaDados(arrayNumeros, contador + 1, final);
    }
}

int main() {
    
    int arrayNumeros[10];

    entradaDados(arrayNumeros, 0, 10);

    return 0;

}
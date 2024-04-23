/*
É o seguinte:
Preciso de um código em C que receba 10 pares de entrada, dos quais serão sempre um número seguido de um caractere.
Deixe-me explicar melhor.
Eu preciso colocar, em ordem decrescente, as notas de 10 alunos de P1, das turmas de Engenharia e Ciência da Computação. Para isso, vou te passar 10 pares de valores, onde o primeiro valor de cada par será a nota de um aluno, de 0 a 10, e o segundo valor será um caractere para representar o curso do aluno em questão, sendo "e" para Engenharia e "c" para Ciência.
Lido todos os valores, printe-os em duas linhas, sendo
na primeira linha: "EC: (notas, em ordem decrescente e com espaços entre elas, dos alunos de Engenharia)"
na segunda linha: "CC: (notas, em ordem decrescente e com espaços entre elas, dos alunos de Ciência)"
Se você conseguir - antes do término da prova =D - te dou 5 pontos.
OBS.: Assuma que em todos os casos testes, terão pelo menos uma nota de ambos os cursos (Engenharia e Ciência), ou seja, nunca vão ter notas APENAS de um curso.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(double array[], int inicio, int final) {
    if (inicio == final - 1) {
        printf("%.2lf", array[inicio]);
        return;
    }
    printf("%.2lf ", array[inicio]);
    return print(array, inicio + 1, final);
}

void bubble(double array[], int i, int tamanho) {
    if (i == tamanho - 1) {
        return;
    }
    else {
        if (array[i] < array[i + 1]) {
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

void entradaDados(double arrayCC[], double arrayEC[], int inicio, int final, int iCC, int iEC) {
    if (inicio == final) {
        bubbleSort(arrayEC, iEC);
        bubbleSort(arrayCC, iCC);
        printf("EC: ");
        print(arrayEC, 0, iEC);
        printf("\n");
        printf("CC: ");
        print(arrayCC, 0, iCC);
        return;
    }
    else {
        char curso;
        double nota;
        scanf("%lf", &nota);
        scanf(" %c", &curso);
        if (curso == 'c') {
            arrayCC[iCC] = nota;
            entradaDados(arrayCC, arrayEC, inicio + 1, final, iCC + 1, iEC);
        }
        if (curso == 'e') {
            arrayEC[iEC] = nota;
            entradaDados(arrayCC, arrayEC, inicio + 1, final, iCC, iEC + 1);
        }
    }
}

int main() {

    double arrayCC[10], arrayEC[10];

    entradaDados(arrayCC, arrayEC, 0, 10, 0, 0);

    return 0;

}
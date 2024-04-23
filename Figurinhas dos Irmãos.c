/*
João e Maria são dois irmãos muito briguentos. Um belo dia, o pai deles, o Sr. Carlos, comprou várias figurinhas do álbum da copa. João disse que por ser menino tinha direito a mais figurinhas. Obviamente, Maria não concordou e propôs um acordo de risco. Eles iriam dividir as figurinhas da seguinte maneira:
João ficaria com todas as figurinhas cujo número de série for par e Maria com as ímpares. O Sr. Carlos gostou da idéia e propôs um pequeno bônus:
- Aquele que obtivesse o maior valor somando os números de séries das figurinhas ganharia como bônus mais R$10,00 reais para comprar figurinhas só para ele.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int verificador(int arrayFigurinhas[], int parametro, int contador, int tamanho, int resultado) {
    if (contador == tamanho) {
        return resultado;
    }
    else {
        if (arrayFigurinhas[contador] == parametro) {
            resultado = 1;
            return resultado;
        }
        verificador(arrayFigurinhas, parametro, contador + 1, tamanho, resultado);
    }
}

void leituraDados(int arrayFigurinhas[], int contador, int quantidadeFigurinhas, int joaoQuantidade, int joaoSomaTotal, int mariaQuantidade, int mariaSomaTotal) {
    int numero, resultado;
    if (contador == quantidadeFigurinhas) {
        printf("%d\n", joaoQuantidade);
        printf("%d\n", mariaQuantidade);
        if (joaoSomaTotal > mariaSomaTotal) {
            printf("%d\n", joaoSomaTotal);
        }
        if (mariaSomaTotal > joaoSomaTotal) {
            printf("%d\n", mariaSomaTotal);
        }
        return;
    }
    else {
        scanf("%d", &numero);
        arrayFigurinhas[contador] = numero;
        if (numero % 2 == 0) {
            joaoQuantidade = joaoQuantidade + 1;
            resultado = verificador(arrayFigurinhas, numero, 0, contador, 0);
            if (resultado != 1) {
                joaoSomaTotal = joaoSomaTotal + numero;
            }
        }
        else if (numero % 2 != 0) {
            mariaQuantidade = mariaQuantidade + 1;
            resultado = verificador(arrayFigurinhas, numero, 0, contador, 0);
            if (resultado != 1) {
                mariaSomaTotal = mariaSomaTotal + numero;
            }
        }
        leituraDados(arrayFigurinhas, contador + 1, quantidadeFigurinhas, joaoQuantidade, joaoSomaTotal, mariaQuantidade, mariaSomaTotal);
    }
}

int main() {
    
    int quantidadeFigurinhas;
    scanf("%d", &quantidadeFigurinhas);

    int arrayFigurinhas[quantidadeFigurinhas];
    leituraDados(arrayFigurinhas, 0, quantidadeFigurinhas, 0, 0, 0, 0);

    return 0;

}
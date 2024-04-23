/*
Oguh e seus amigos estavam jogando Dungeons and Dragons, um RPG de mesa em que quase tudo é decidido com dados. Os personagens desse jogo precisam atravessar uma grande floresta, então todos os jogadores rolam N dados que precisam ser maiores ou iguais ao nível de dificuldade da floresta.
Sempre serão 5 jogadores, todos rodarão um d20 (dado de 20 lados), e somarão o resultado do dado com o bônus que varia de personagem para personagem.
Se o resultado for maior ou igual ao nível de dificuldade da floresta, o jogador passa, caso contrário ele se perde na floresta.
Exiba na tela a quantidade de jogadores que passaram da floresta, o maior valor total e o menor valor total.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void menorValor(int valorTotal[], int inicio, int final, int menor) {
    if (inicio == final) {
        printf("Menor valor: %d", menor);
        return;
    }
    else {
        if (valorTotal[inicio] <= menor) {
            menor = valorTotal[inicio];
        }
        menorValor(valorTotal, inicio + 1, final, menor);
    }
}

void maiorValor(int valorTotal[], int inicio, int final, int maior) {
    if (inicio == final) {
        printf("Maior valor: %d\n", maior);
        return;
    }
    else {
        if (valorTotal[inicio] >= maior) {
            maior = valorTotal[inicio];
        }
        maiorValor(valorTotal, inicio + 1, final, maior);
    }
}

void jogadoresAcimaDificuldade(int valorTotal[], int nivelDificuldade, int inicio, int final, int quantidade) {
    if (inicio == final) {
        printf("Jogadores que passaram: %d\n", quantidade);
        return;
    }
    else {
        if (valorTotal[inicio] >= nivelDificuldade) {
            quantidade = quantidade + 1;
        }
        jogadoresAcimaDificuldade(valorTotal, nivelDificuldade, inicio + 1, final, quantidade);
    }
}

void somatorio(int registroValorJogador[], int registroValorExtra[], int valorTotal[], int inicio, int final) {
    if (inicio == final) {
        return;
    }
    else {
        valorTotal[inicio] = registroValorJogador[inicio] + registroValorExtra[inicio];
        somatorio(registroValorJogador, registroValorExtra, valorTotal, inicio + 1, final);
    }
}

void registroValorExtra(int valorExtra[], int inicio, int final) {
    int numero;
    if (inicio == final) {
        return;
    }
    else {
        scanf("%d", &numero);
        valorExtra[inicio] = numero;
        registroValorExtra(valorExtra, inicio + 1, final);
    }
}

void registroValorJogador(int valorJogador[], int inicio, int final) {
    int numero;
    if (inicio == final) {
        return; 
    }
    else {
        scanf("%d", &numero);
        valorJogador[inicio] = numero;
        registroValorJogador(valorJogador, inicio + 1, final);
    }
}

int main() {
    
    int nivelDificuldade;

    scanf("%d", &nivelDificuldade);

    int valorJogador[5];
    registroValorJogador(valorJogador, 0, 5);
    int valorExtra[5];
    registroValorExtra(valorExtra, 0, 5);
    int valorTotal[5];
    somatorio(valorJogador, valorExtra, valorTotal, 0, 5);
    jogadoresAcimaDificuldade(valorTotal, nivelDificuldade, 0, 5, 0);
    maiorValor(valorTotal, 0, 5, 0);
    menorValor(valorTotal, 0, 5, 999);

    return 0;

}
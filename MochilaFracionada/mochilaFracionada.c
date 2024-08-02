#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int numero, peso, valor;
}TObjeto;

int compara(const void *a, const void *b ){

    return (double)(((TObjeto*)b)->valor/((TObjeto*)b)->peso) - (double)(((TObjeto*)a)->valor/((TObjeto*)a)->peso);
}

int mochilaFracionada(TObjeto *v, int tamanho, int capacidade){
    int espacoLivre, // espaco livre na mochila
        valorObj, //valor dos objetos colocados na mochila
        numObj; // numero de objetos colocados na mochila
       

    qsort(v, tamanho, sizeof(TObjeto), compara);
    numObj = 0;
    valorObj=0;
    espacoLivre = capacidade;
  
    while(espacoLivre > 0 && numObj < tamanho){
        if (v[numObj].peso <= espacoLivre){
            espacoLivre -= v[numObj].peso;
            valorObj += v[numObj].valor;
        }
        else {
            valorObj += v[numObj].valor * espacoLivre/v[numObj].peso;
            espacoLivre = 0;
        }
        numObj++;
    }
    
    return valorObj;
}

int main(){
    TObjeto v[] = {{1, 10, 60}, {2, 20, 100}, {3, 30, 120}};
    int capacidade = 50;

    printf("\nValor dos objetos colocados na mochila: %d\n\n", mochilaFracionada(v, 3, capacidade));
    return 0;
}
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int numero, inicio, fim;
}TAtividade;

int compara(const void *a, const void *b ){

    return ((TAtividade*)a)->fim - ((TAtividade*)b)->fim;
}

int selecaoAtividades(TAtividade *v, int tamanho){
    int na, // numero de atividades atendidas
        fimAtual, // horario de termino da atividade corrente
        i;

    qsort(v, tamanho, sizeof(TAtividade), compara);
    na = 1;
    fimAtual = v[0].fim;
    for(i = 1; i <tamanho; i++){
        if (v[i].inicio > fimAtual){
            na++;
            fimAtual = v[i].fim;
        }
    }
    return na;
}

int main(){
    TAtividade v[] = {{1, 2, 10}, {2, 5, 7}, {3, 8,11}};
    
    printf("\nNúmero de atividades atendidas: %d\n\n", selecaoAtividades(v, 3));
    return 0;
}
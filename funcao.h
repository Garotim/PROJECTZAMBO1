#include "Listasequecial.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCAO_H
#define FUNCAO_H

#include "Listasequecial.h"

void imprime_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int remove_lista_final(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);


struct lista {
    int qtd;
    struct aluno dados[MAX];
};

void imprime_lista(Lista* li) {
    if (li == NULL) return;

    printf("----------------------------------------\n");
    for (int i = 0; i < li->qtd; i++) {
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Nome: %s\n", li->dados[i].nome);
        printf("Notas: %.2f %.2f %.2f\n", li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
        printf("------------------------------------\n");
    }
}

int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL || li->qtd == MAX) return 0;

    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL || li->qtd == 0) return 0;

    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos < 0 || pos >= li->qtd) return 0;

    *al = li->dados[pos];
    return 1;

void libera_lista(Lista* li) {
    free(li);
}
}

#endif /* FUNCAO_H */


#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H

#define MAX 10

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int remove_lista_final(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

#endif /* LISTASEQUENCIAL_H */

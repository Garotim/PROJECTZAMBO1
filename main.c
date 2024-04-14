#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Funcao.h"
#include "Listasequecial.h"

void menu(Lista *li);

int main() {
    Lista* li = cria_lista();
    menu(li);
    libera_lista(li);
    return 0;
}

void menu(Lista *li) {
    int valor;
    bool repeat = true;

    do {
        printf("*************   Trabalho de Ordenacao     **************\n");
        printf(" Academicos  :   \n");
        printf("_____________________________________________________\n");
        printf("|1 - Inserir Elemento no Final                       |\n");
        printf("|2 - Remover Elemento do Final                       |\n");
        printf("|3 - Consultar Elemento Pela Posicao                 |\n");
        printf("|4 - Exibir Tamanho da Lista                         |\n");
        printf("|5 - Sair                                            |\n");
        printf("|____________________________________________________|\n");

        printf("Escolha a acao: \n");
        scanf("%d", &valor);

        switch(valor) {
            case 1: {
                struct aluno novoAluno;
                printf("Informe a matricula do novo aluno: ");
                scanf("%d", &novoAluno.matricula);
                if(insere_lista_final(li, novoAluno))
                    printf("Aluno inserido com sucesso!\n");
                else
                    printf("Erro ao inserir aluno.\n");
                break;
            }
            case 2:
                if(remove_lista_final(li))
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro ao remover elemento.\n");
                break;
            case 3: {
                int pos;
                printf("Informe a posicao do elemento a ser consultado: ");
                scanf("%d", &pos);
                struct aluno alunoConsultado;
                if(consulta_lista_pos(li, pos, &alunoConsultado))
                    printf("Aluno na posicao %d: Matricula: %d, Nome: %s\n", pos, alunoConsultado.matricula, alunoConsultado.nome);
                else
                    printf("Elemento nao encontrado.\n");
                break;
            }
            case 4: {
                int tamanho = tamanho_lista(li);
                printf("Tamanho da lista: %d\n", tamanho);
                break;
            }
            case 5:
                repeat = false;
                break;
            default:
                printf("Valor invalido\n");
                break;
        }
        system("pause");
    } while (repeat);
}

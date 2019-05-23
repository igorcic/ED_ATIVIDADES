#include<stdio.h>
#include<stdlib.h>


struct aluno{
    int matri;
    char nome[30];
};
typedef struct elemento * Lista;
struct aluno al_max;

Lista * criar_lista();
void liberar_lista(Lista*li);
int tamanho_lista(Lista*li);
int lista_cheia(Lista*li);
int lista_vazia(Lista*li);
int inicio_lista(Lista*li, struct aluno al);
int final_lista(Lista*li, struct aluno al);
int ordem_lista(Lista*li,struct aluno al);
int removini_lista(Lista*li);
int removfim_lista(Lista*li);
int remov_list(Lista*li, int mat);
int consulta_pos(Lista*li,int pos, struct aluno *al);
int consulta_matri(Lista*li,int mat, struct aluno *al);
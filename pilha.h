#include<stdio.h>
#include<stdlib.h>

struct conteudo{
    int num;
};
typedef struct elemento *pilha;
struct conteudo cont_max;

pilha*criar_pilha();
void destruir_pilha(pilha*pi);
int empilhar(pilha*pi, struct conteudo cont);
int desempilhar(pilha*pi, struct conteudo cont);
int consultar_topo(pilha*pi, struct conteudo *cont);
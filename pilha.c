#include"pilha.h"

struct elemento{
    struct conteudo dados;
    struct elemento *prox;
};
typedef struct elemento elem;

pilha*criar_pilha(){
    pilha *pi = (pilha*) malloc(sizeof(pilha));
    if(pi != NULL)  *pi = NULL;
    return pi;
}

void destruir_pilha(pilha*pi){
    //if(pi != NULL)  return -1;
    elem * no;
    while((*pi)!= NULL){
        no = *pi;
        *pi = (*pi)->prox;
        free(no);
    }
    free(pi);
}
int tamanho_pilha(pilha*pi){
    if(pi == NULL)  return -1;
    int cont = 0;
    elem *no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}
int pilha_vazia(pilha*pi){
    if(pi == NULL)  return -1;
    if((*pi) == NULL)   return 0;
    return 1;
}

int empilhar(pilha*pi, struct conteudo cont){
    if(pi == NULL)  return -1;
    elem * no = (elem*) malloc(sizeof(elem));
    no->dados = cont;
    no->prox = (*pi);
    *pi = no;
    return 1;
}
int desempilhar(pilha*pi, struct conteudo cont){
    if(pi == NULL)  return -1;
    if((*pi) == NULL)   return 0;
    elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}
int consultar_topo(pilha *pi, struct conteudo *cont){
    if(pi == NULL)  return -1;
    if((*pi) == NULL)   return 0;
    *cont = (*pi)->dados;
    return 1;
}
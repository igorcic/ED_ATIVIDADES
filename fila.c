#include"fila.h"
struct fila{
    struct elemento *inicio;
    struct elemento *final;
};
struct elemento{
    struct conteudo dados;
    struct elemento *prox;
};
typedef struct elemento elem;

fila* criar_fila(){
    fila* fi = (fila*) malloc(sizeof(fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}
void liberar_fila(fila*fi){
    if(fi != NULL){
        elem*no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}
int tamanho_fila(fila*fi){
    if(fi == NULL)  return -1;
    elem*no = fi->inicio;
    int cont = 0;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}
int fila_vazia(fila*fi){
    if(fi == NULL)  return -1;
    if(fi->inicio == NULL)   return 0;
    return 1;
}
int inserir_fim(fila*fi, struct conteudo contM){
    if(fi == NULL)  return -1;
    elem *no = (elem*)malloc(sizeof(elem));
    if(no == NULL)  return 0;
    no->dados = contM;
    no->prox = NULL;
    if(fi->final == NULL){
        fi->inicio = no;
    }
    else{
        fi->final->prox = no;
    }
    fi->final = no;
    return 1;
}
int remov_fila(fila*fi){
    if(fi == NULL)  return -1;
    if(fi->inicio == NULL){
        return 0;
    }
    elem*no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){
        fi->final = NULL;
    }
    free(no);
    return 1;
}
int consulta_fila(fila*fi, struct conteudo *contM){
    if(fi == NULL)  return -1;
    if(fi->inicio == NULL){
        return 0;
    }
    *contM = fi->inicio->dados;
    return 1;
}
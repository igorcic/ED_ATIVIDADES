#include"Dlista.h"


struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
Lista * criar_lista(){
    Lista * li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
void liberar_lista(Lista*li){
    if(li != NULL){
        Elem * no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
int tamanho_lista(Lista*li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem * no = *li;
    while(no = NULL){
        cont ++;
        no = no->prox;
    }
    return cont;
}
int lista_cheia(Lista*li){
    return 0;
}
int lista_vazia(Lista*li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}
int inicio_lista(Lista*li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem*no = (Elem*)malloc(sizeof(Elem));
    if(no==NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}
int final_lista(Lista*li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem*no = (Elem*)malloc(sizeof(Elem));
    if(no==NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li)== NULL){
        *li = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
    
}
int ordem_lista(Lista*li,struct aluno al){
    if(li == NULL)
        return 0;
    Elem*no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        Elem*ant, *atual = *li;
        while(atual != NULL && atual->dados.matri < al.matri){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
    
}
int removini_lista(Lista*li){
    if(li == NULL){
        return 0;
    }
    if((*li) == NULL){
        return -1;
    }
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}
int removfim_lista(Lista*li){
    if(li == NULL)
        return 0;
    if(*li == NULL){
        return -1;
    }
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
    
}
int remov_list(Lista*li, int mat){
    if(li == NULL) return 0;
    Elem *ant, *no = *li;
    while(no!=NULL && no->dados.matri != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0;
    if(no == *li)
        *li = no->prox;
    else
    {
        ant->prox = no->prox;
    }
    free(no);
    return 1;
    
}
int consulta_pos(Lista*li,int pos, struct aluno *al){
    if(li == NULL || pos <= 0) return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}
int consulta_matri(Lista*li,int mat, struct aluno *al){
    if(li == NULL) return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.matri != mat)
    {
        no = no->prox;
    }
    if(no == NULL)
        return -1;
    else{
        *al = no->dados;
        return 1;
    }
    
}
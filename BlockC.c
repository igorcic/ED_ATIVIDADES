#include"BlockC.h"

struct blockchain{
    struct blockchain *Hash_pai;
    struct cadastro dados;
    struct blockchain *Hash_b;
};
typedef struct blockchain bloc;

lista*criar_lista(){
    lista*li = (lista*)malloc(sizeof(lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
void liberar_lista(lista*li){
    if(li != NULL){
        bloc*no;
        while((*li)!= NULL){
            no = *li;
            *li= (*li)->Hash_b;
            free(no);
        }
        free(li);
    }
}
int tamanho_lista(lista*li){
    if(li == NULL)  return -1;
    int cont = 0;
    bloc *no = *li;
    while(no != NULL){
        cont ++;
        no = no->Hash_b;
    }
    return cont;
}
int lista_vazia(lista*li){
    if(li==NULL){
        return -1;
    }
    if(*li == NULL){
        return 0;
    }
    return 0;

}
int inserir_ordenado(lista*li, struct cadastro al){
    if(li == NULL)  return -1;
    bloc*no = (bloc*)malloc(sizeof(bloc));
    if(no == NULL)  return 0;
    no->dados = al;
    if(lista_vazia(li)){
        no->Hash_b = NULL;
        no->Hash_pai = NULL;
        *li = no;
        return 1;
    }
    else{
        bloc*antes, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            antes = atual;
            atual = atual->Hash_b;
        }
        if(atual == *li){
            no->Hash_pai= NULL;
            (*li)->Hash_pai = no;
            no->Hash_b =(*li);
            *li = no;
        }else{
            no->Hash_b =antes->Hash_b;
            no->Hash_pai = antes;
            antes->Hash_b = no;
            if(atual != NULL){
                atual->Hash_pai = no;
            }
            
        }
        return 1;
    }

}
int consulta_matricula(lista*li, int mat, struct cadastro *al){
    if(li == NULL){
        return -1;
    }
    bloc*no = *li;
    while(no != NULL && no->dados.matricula!= mat){
        no = no->Hash_b;
    }
    if(no == NULL){
        return 0;
    }else{
        *al = no->dados;
        return 1;
    }

}

int consulta_nome(lista*li, char nome, struct cadastro *al){
    if(li == NULL){
        return -1;
    }
    bloc*no = *li;
    while(no != NULL && no->dados.nome != nome){
        no = no->Hash_b;
    }
    if(no == NULL){
        return 0;
    }else{
        *al = no->dados;
        return 1;
    }

}
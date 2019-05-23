#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

struct lista{
    int qtd;
    struct aluno dados [MAX];
};

List * criar_lista(){
    List *li;
    li = (List*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }
    return li;
}

void libe_lista(List*li){
    free(li);
}
int tamanho_lista(List*li){
    if(li == NULL){
        return -1;
    }else{
        return li->qtd;
    }
}
int lista_cheia(List*li){
    if(li == NULL){
        return -1;
    }
    return(li->qtd == MAX);
    
}
int lista_vazia(List*li){
    if(li == NULL){
        return -1;
    } 
    return(li->qtd == 0);
    
}
int inserir_fim(List*li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;

}
int inserir_inicio(List*li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    int i;
    for(i = li->qtd -1; i>= 0; i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}
int remov_fim(List*li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return -1;
    }
    li->qtd--;
    return 1;
}
int remov_inicio(List*li){
    if(li==NULL){
        return 0;
    }
    if(li->qtd == 0){
        return -1;
    }
    int k;
    for(k = 0; k < li->qtd -1;k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}
void mostrar_al(List*li, struct aluno al){
    int i;
    for(i = 0; i < li->qtd; i++){
        printf("%s \n", al.nome);
        printf("%d \n", al.matricula);

    }
}
int consulta_pos(List * li, int pos, struct aluno *al){
    if(li==NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }
    *al = li->dados[pos-1];
    return 1;
}
int consulta_matri(List * li, int matri, struct aluno *al){
    if(li == NULL)
        return -1;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != matri){
        i++;
        
    }
    if(i == li->qtd){
        
        return 0;

    }
     
    *al = li->dados[i]; 
    return 1;  

}
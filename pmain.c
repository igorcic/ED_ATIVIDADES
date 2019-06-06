#include"pilha.h"

int main(){
    pilha *pi;
    int x,opt;
    opt = 0;
    pi = NULL;

    do{
        printf("Digite 1 para criar pilha\n");
        printf("Digite 2 para empilhar\n");
        printf("Digite 3 desempilhar\n");
        printf("Digite 4 acessar\n");
        
        printf("Digite 5 para sair\n");
        scanf("%d", &opt);
        switch (opt){
            case 1:
                pi = criar_pilha();
                if(pi == NULL){
                    printf("ERRO na criacao\n");

                }else{
                    printf("Lista criada com sucesso\n");
                }
                break;
                
            
            case 2:
                if(pi == NULL){
                    printf("Lista nao existe \n");
                }else{
                    printf("Digite o numero \n");
                    scanf("%d", &cont_max.num); 
                    x = empilhar(pi, cont_max);         
                }
                break;
                    break;
                    
            case 3:
                if(pi == NULL){
                    printf("Lista nao existe \n");
                }else{
                    x = desempilhar(pi,cont_max);         
                }
                break;

            case 4:
                if(pi == NULL){
                    printf("Pilha nao existe \n");
                }else{
                    x = consultar_topo(pi, &cont_max);
                    if(x == 1){
                        printf("%d \n", cont_max.num);
                    } else{
                        printf("ERRO! \n");
                    }
                }
                break;   
        }
    }while(opt != 5);
    
   // pi = criar_pilha();
   // pilha_cheia(pi);
   // x = pilha_vazia(pi);
   // x = empilhar(pi, cont_max);
   //x = desempilhar(pi, cont_max);
}
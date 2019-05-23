#include"Lista.h"
#include<stdio.h>
#include<stdlib.h>


int main(){
    int x, opt = 0;
    List * li;
    int posicao, matricula;
    li = NULL;
    do{
        printf("Digite 1 para criar lista\n");
        printf("Digite 2 para Inserir no inicio da lista\n");
        printf("Digite 3 para inserir no final da lista\n");
        printf("Digite 4 para Pesquisar por posicao\n");
        printf("Digite 5 Mostrar conteudo por matricula\n");
        printf("Digite 6 remover do inicio\n");
        printf("Digite 7 para verificar lista cheia\n");
        printf("Digite 8 para verificar tamanho da lista\n");
        printf("Digite 9 para verificar lista cheia \n");
        printf("Digite 10 para verificar lista vazia \n");
        printf("Digite 11 para sair\n");
        scanf("%d", &opt);
        switch (opt){
            case 1:
                li = criar_lista();
                if(li == NULL){
                    printf("ERRO na criacao\n");

                }else{
                    printf("Lista criada com sucesso\n");
                }
                break;
            case 2:
                if(li == NULL){
                    printf("Lista nao existe\n");
                }else{
                    printf("Digite o nome do aluno \n");
                    scanf("%s", al_max.nome);
                    printf("Digite o numero de matricula: \n");
                    scanf("%d", &al_max.matricula);
                    printf("\n");
                    x = inserir_inicio(li,al_max);
                }
                    break;
            case 3:
                if(li == NULL){
                    printf("Lista nao existe \n");
                }else{
                    printf("Digite o nome do aluno \n");
                    scanf("%s", al_max.nome);
                    printf("Digite o numero de matricula: \n");
                    scanf("%d", &al_max.matricula);
                    printf("\n");
                    x = inserir_fim(li,al_max);
                }
                    
                    break;
            case 4:
                if(li == NULL){
                    printf("Lista nao existe \n");
                }else{
                    printf("digite a posicao procurada: \n");
                    scanf("%d", &posicao);
                    x = consulta_pos(li,posicao, &al_max);
                    printf("%d", x);
                    if(x == 1){
                        printf("\n");
                        printf("nome %s \n", al_max.nome);
                        printf("matricula %d \n", al_max.matricula);
                    } else{
                        printf("ERRO! \n");
                    }
                }
                    break;
            case 5:
                printf("digite o numero da matricula: \n");
                scanf("%d", &matricula);
                int z;
                z = consulta_matri(li,matricula, &al_max);
                printf("%d\n",z);
                if(z == 1){
                    printf("\n");
                    printf("Nome: %s \n", al_max.nome);
                    printf("matricula: %d \n", al_max.matricula);
                    
                }else{
                    if(z == -1)
                        printf("Erro!\n");
                    if(z == 0){
                        printf("Aluno não encontrado\n");
                    }
                }                
                break;
            case 6:
                x = remov_inicio(li);
                if(x == 0){
                    printf("Lista nao existe \n");
                }
                if(x == -1){
                    printf("Lista vazia \n");
                }
                if(x == 1){
                    printf("remocao concluida \n");
                }
                break;
            case 7:
                x = remov_fim(li);
                if(x == 0){
                    printf("Lista nao existe \n");
                }
                if(x == -1){
                    printf("Lista vazia \n");
                }
                if(x == 1){
                    printf("remocao concluida \n");
                }

                break;
               
            case 8:
                x = tamanho_lista(li);
                if(x == -1)
                    printf("lista sem tamanho \n");
                printf("%d", x);

        }
        

    }while(opt != 11);
    
    
    x = lista_cheia(li);
    x = lista_vazia(li);
    libe_lista(li);
    


    return 0;
}
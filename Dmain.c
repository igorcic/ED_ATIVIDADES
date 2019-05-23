#include"Dlista.h"


int main(){
    int x,matri,pos, opt;
    opt = 0;
    Lista * li;
    li = NULL;
    do{
        printf("Digite 1 para criar lista\n");
        printf("Digite 2 para Inserir no inicio da lista\n");
        printf("Digite 3 para inserir no final da lista\n");
        printf("Digite 4 para Pesquisar por posicao\n");
        printf("Digite 5 Mostrar conteudo por matricula\n");
        printf("Digite 6 remover do inicio\n");
        printf("Digite 7 para remover do final\n");
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
                    scanf("%d", &al_max.matri);
                    printf("\n");
                    x = inicio_lista(li, al_max);
                }
                    break;
                    
            case 3:
                if(li == NULL){
                    printf("Lista nao existe \n");
                }else{
                    printf("Digite o nome do aluno \n");
                    scanf("%s", al_max.nome);
                    printf("Digite o numero de matricula: \n");
                    scanf("%d", &al_max.matri);
                    printf("\n");
                    x = final_lista(li, al_max);
                    
                }
                break;

            case 4:
                if(li == NULL){
                    printf("Lista nao existe \n");
                }else{
                    printf("digite a posicao procurada: \n");
                    scanf("%d", &pos);
                    x = consulta_pos(li, pos, &al_max);
                    printf("%d", x);
                    if(x == 1){
                        printf("\n");
                        printf("nome %s \n", al_max.nome);
                        printf("matricula %d \n", al_max.matri);
                    } else{
                        printf("ERRO! \n");
                    }
                }

                    break;
        
            case 5:
                printf("digite o numero da matricula: \n");
                scanf("%d", &matri);
                int z;
                z = consulta_matri(li, matri, &al_max);
                printf("%d\n",z);
                if(z == 1){
                    printf("\n");
                    printf("Nome: %s \n", al_max.nome);
                    printf("matricula: %d \n", al_max.matri);
                    
                }else{
                    if(z == -1)
                        printf("Aluno não encontrado\n");
                    if(z == 0){
                        printf("ERRO\n");
                    }
                }                
                break;
        
            case 6:
                x = removini_lista(li);
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
                x = removfim_lista(li);
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
                if(x == 0)
                    printf("lista sem tamanho \n");
                printf("%d", x);

        }
        

    }while(opt != 11);
    
    //li = criar_lista();
    liberar_lista(li);
 //   x = tamanho_lista(li);
/* x = lista_cheia(li);
    x = lista_vazia(li);
    x = inicio_lista(li, al_max);
    x = final_lista(li, al_max);
    x = ordem_lista(li, al_max);
    x = removini_lista(li);
    x = removfim_lista(li);
    x = remov_list(li, matri);
    x = consulta_pos(li, pos, &al_max);
    x = consulta_matri(li, matri, &al_max);
    */
}
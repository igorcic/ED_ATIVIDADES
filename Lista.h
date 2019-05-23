#define MAX 4
struct aluno{
    int matricula;
    char nome[30];
    //float n1,n2,n3;

};
typedef struct lista List;
struct aluno al_max;





List * criar_lista();
void libe_lista(List*li);
int tamanho_lista(List*li);
int lista_cheia(List*li);
int lista_vazia(List*li);
int inserir_fim(List*li, struct aluno al);
int inserir_inicio(List*li, struct aluno al);
int remov_fim(List*li);
int remov_inicio(List*li);
void mostrar_al(List*li, struct aluno al);
int consulta_pos(List * li, int pos, struct aluno *al);
int consulta_matri(List * li, int matri, struct aluno *al);


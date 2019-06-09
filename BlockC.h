#include<stdio.h>
#include<stdlib.h>

struct materia{
    char dissiplina[30];
    float n1,n2,n3,nf;
};

struct cadastro{
    char nome[30];
    struct materia materia;
    int matricula;
};
typedef struct blockchain * lista;
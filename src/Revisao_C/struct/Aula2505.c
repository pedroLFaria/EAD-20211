#include <stdio.h>
#include <conio.h>

struct AulaStruct{
    int CampoA;
    struct AulaStruct *aulaStruct;
};

const double sizeofAulaStruct = sizeof(struct AulaStruct);
typedef struct AulaStruct *ptAulaStruct;

void main(){
    
    printf("Aula EDA 25/05 - Revisao C - Structs: \n\n");

    AlocandoMemoria();
    
    EncadeandoInstanciasStructs();
    
    ArrayStructs();
}

void AlocandoMemoria(){
    printf("Alocando memoria de structs e setando valores: \n");
    struct AulaStruct *p=NULL;

    p = (struct AulaStruct*) malloc(sizeof(struct AulaStruct));
    
    struct AulaStruct d;
    printf("Tamnho de p: %d\n", sizeof(p));
    printf("Tamnho de *p: %d\n", sizeof(*p));
    printf("Tamnho de d: %d\n", sizeof(d));
    
    p->CampoA = 9;
    
    printf("p -> Campo A: %d\n", p->CampoA);

    d.CampoA = 12;
    printf("d -> Campo d: %d\n", d.CampoA);
    printf("..............................\n\n");
}

void EncadeandoInstanciasStructs(){
    printf("Encadeando intancias de structs: \n");
    
    ptAulaStruct p=NULL;
    p = (ptAulaStruct) malloc(sizeofAulaStruct);
    ptAulaStruct aux;

    aux = p;

    for(int i = 0; i < 3; i++){
        aux->CampoA = i;
        aux->aulaStruct = (ptAulaStruct)malloc(sizeofAulaStruct);
        aux = aux->aulaStruct;
    }
    printf("p -> campo A: %d\n", p->CampoA);
    printf("p -> aulaStruct -> campo A: %d\n", p->aulaStruct->CampoA);
    printf("p -> aulaStruct -> aulaStruct -> campo A: %d\n", p->aulaStruct->aulaStruct->CampoA);
    printf("p -> aulaStruct -> aulaStruct -> aulaStruct -> campo A: %d (Lixo)\n", p->aulaStruct->aulaStruct->aulaStruct->CampoA);
    printf("..............................\n\n");
}

void ArrayStructs(){
    printf("Encadeando usando um array de Structs:\n");
    int tamanhoVetor = 3;

    ptAulaStruct p = (ptAulaStruct)malloc(sizeofAulaStruct * tamanhoVetor);
    
    for(int i = 0; i < tamanhoVetor; i++){
        p[i].CampoA = i;
    }
    printf("p[0].campo A: %d\n", p[0].CampoA);
    printf("p[1].campo A: %d\n", p[1].CampoA);
    printf("p[2].campo A: %d\n", p[2].CampoA);
    printf("p[3].campo A: %d (Lixo)\n", p[3].CampoA);
    printf("..............................\n\n");
}
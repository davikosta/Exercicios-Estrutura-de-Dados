#include <stdio.h>

#define MAX 100

typedef struct{
    int chave;
} tipo_item;

typedef struct{
    tipo_item item[MAX];
    int tamanho;
} tipo_lista;

int obtemN() {
    int n;
    scanf("%d", &n);
    return n;
}

void inicializaLista(tipo_lista *lista, int tamanho) {

    lista->tamanho = tamanho;

    for (int i = 0; i < tamanho; i++) {scanf("%d", &lista->item[i].chave);}
}

int comparaLista(tipo_lista *lista1, tipo_lista *lista2) {
   
    if (lista1->tamanho != lista2->tamanho) {return 1;}
    
    if (lista1->tamanho == lista2->tamanho) {

        for (int i = 0; i < lista1->tamanho; i++) {
            if (lista1->item[i].chave != lista2->item[i].chave) {return 1;}
        }
    }

    return 0;
}

int main() {

    int n1, n2;

    tipo_lista l1;
    n1 = obtemN();
    inicializaLista(&l1, n1);

    tipo_lista l2;
    n2 = obtemN();
    inicializaLista(&l2, n2);

    switch (comparaLista(&l1, &l2)) {

        case 0:
            printf("LISTAS IGUAIS\n");
            break;
        case 1:
            printf("LISTAS DIFERENTES\n");
            break;  
        default:
            printf("Erro no retorno da função");
            break;
    }

    return 0;
}
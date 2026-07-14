#include <stdio.h>


#define MAX 100

typedef struct {
    int chave;
} TipoItem;

typedef struct {
    int tamanho;
    TipoItem item[MAX];
} TipoLista;


int obtem_n() {

    int n;
    scanf("%d", &n);
    if(n <= MAX) {return n;}
}

void incializa_lista(TipoLista *lista, int tamanho) {

    lista->tamanho = tamanho;

    for (int i = 0; i < lista->tamanho; i++) {
        scanf("%d", &lista->item[i].chave);
    }
}

void duplica_lista(TipoLista *lista_origem, TipoLista *lista_destino) {
    for (int i = 0; i < lista_origem->tamanho; i++) {
        lista_destino->item[i].chave = lista_origem->item[i].chave;
    }
    lista_destino->tamanho = lista_origem->tamanho;
}

void imprime_Lista(TipoLista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d\n", lista->item[i].chave);
    }
}

int main() {

    TipoLista l1;
    int n = obtem_n();
    incializa_lista(&l1, n);

    TipoLista l2;

    duplica_lista(&l1, &l2);
    imprime_Lista(&l2);
 
    return 0;
}
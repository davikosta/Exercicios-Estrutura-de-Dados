#include <stdio.h>

#define MAX 1000

typedef struct {
    int chave;
} TipoItem;

typedef struct {
    TipoItem item[MAX];
    int tamanho;
} TipoLista;

int obtem_n() {
    int n;
    scanf("%d", &n);
    return n;
}

void inicializa_lista(TipoLista *lista, int tamanho) {
    lista->tamanho = tamanho;
    for (int i = 0; i < lista->tamanho; i++) {
        scanf("%d", &lista->item[i].chave);
    }
}

void inverte_lista(TipoLista *lista_entrada, TipoLista *lista_saida) {
    lista_saida->tamanho = lista_entrada->tamanho;
    int cont_lista_2 = 0;
    for (int i = lista_entrada->tamanho-1; i > -1; i--) {
        lista_saida->item[cont_lista_2].chave = lista_entrada->item[i].chave;
        cont_lista_2++;
    }
}

void imprime_lista(TipoLista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d\n", lista->item[i].chave);
    }
}

int main() {

    TipoLista l1;
    int n = obtem_n();
    inicializa_lista(&l1, n);

    TipoLista l2;

    inverte_lista(&l1, &l2);
    imprime_lista(&l2);

    return 0;
}
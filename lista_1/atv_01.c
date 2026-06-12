#include <stdio.h>
#include <locale.h>

#define MAX 100

typedef struct {
    int chave;
} tipoItem;

typedef struct {
    tipoItem item[MAX];
    int tamanho;
} tipoLista;

int obtemN() {
    int n;
    scanf("%d", &n);
    return n;
    
}

int obtemP() {
    int p;
    scanf("%d", &p);
    return p;
}

int obtemX() {
    int x;
    scanf("%d", &x);
    return x;
}

void inicializaLista(tipoLista *lista, int n) {
    lista->tamanho = n;

    for (int i = 0; i < lista->tamanho; i++)
    {
        scanf("%d", &lista->item[i].chave);
    }
    
}

void insereLista(tipoLista *lista, int p, int x) {

    if(lista->tamanho < 100 && p <= lista->tamanho + 1 && p > 0) {
        for(int i = lista->tamanho; i >= p; i--) {
            lista->item[i].chave = lista->item[i-1].chave;
        }
        lista->item[p-1].chave = x;
        lista->tamanho++;

        for(int i = 0; i < lista->tamanho; i++) {
            printf("%d\n", lista->item[i].chave);
        }
    } else {
        printf("Lista esta cheia ou posicao inválida\n");
    }
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    
    tipoLista lista;

    inicializaLista(&lista, obtemN());
    
	int x = obtemX();
	int p = obtemP();
    insereLista(&lista, p, x);

    return 0;
}
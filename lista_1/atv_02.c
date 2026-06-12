#include <stdio.h>
#include <locale.h>

#define MAX 100

typedef struct
{
    int chave;
} tipoItem;

typedef struct
{
    tipoItem item[MAX];
    int tamanho;
} tipoLista;

int obtemN()
{
    int n;
    scanf("%d", &n);
    return n;
}

int obtemP()
{
    int p;
    scanf("%d", &p);
    return p;
}

int obtemX()
{
    int x;
    scanf("%d", &x);
    return x;
}

void inicializaLista(tipoLista *lista, int n)
{
    lista->tamanho = n;

    for (int i = 0; i < lista->tamanho; i++)
    {
        scanf("%d", &lista->item[i].chave);
    }
}

void insereLista(tipoLista *lista, int p, int x)
{

    if (lista->tamanho < 100 && p <= lista->tamanho + 1 && p > 0)
    {
        for (int i = lista->tamanho; i >= p; i--)
        {
            lista->item[i].chave = lista->item[i - 1].chave;
        }
        lista->item[p - 1].chave = x;
        lista->tamanho++;

        for (int i = 0; i < lista->tamanho; i++)
        {
            printf("%d\n", lista->item[i].chave);
        }
    }
    else
    {
        printf("Lista esta cheia ou posicao inválida\n");
    }
}

int verificaOrdenado(tipoLista *lista) {

    int crescente = 0, decrescente = 0;
    if (lista->tamanho > 0) {
        for (int i = 0; i < lista->tamanho - 1; i++){
            if (lista->item[i].chave < lista->item[i+1].chave) {
                crescente = 1;
            } else if(lista->item[i].chave > lista->item[i+1].chave) {
                decrescente = 2;
            }
        }
        if (crescente == 1 && decrescente == 0) {
            return crescente;
        } else if (crescente == 0 && decrescente == 2) {
            return decrescente;
        } else {
            return -1;
        }
    }

    return 0;
}

void exibeOdernacao(tipoLista *lista) {
    switch (verificaOrdenado(lista)) {
        case 0:
            printf("LISTA VAZIA\n");
            break;
        case 1:
            printf("CRESCENTE\n");
            break;
        case 2:
            printf("DECRESCENTE\n");
            break;
        case -1:
            printf("NAO ORDENADA\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    tipoLista lista;

    inicializaLista(&lista, obtemN());

    exibeOdernacao(&lista);

    return 0;
}
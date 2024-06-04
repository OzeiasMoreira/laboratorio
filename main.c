#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista Lista;

struct lista
{
    int data;
    Lista* prox;
};

Lista* cria_lista(void)
{

    return NULL;
}

Lista* inserir_ordenado(Lista* lst,int valor)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->data = valor;
    Lista* p = lst;
    Lista* ant = NULL;
    while (p != NULL && p->data > valor)
    {
        ant = p;
        p = p->prox;

    }
    // Lista vazia , então vai ser o primeiro elemento
    if(p == NULL)
    {
        novo->prox = lst;
        return novo;

    }
    if (ant == NULL)
    {
        novo->prox = lst;
        lst = novo;
        return lst;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
        return novo;
    }
}

void liberar_list(Lista* lst)
{
    Lista* t;
    Lista* p = lst;
    while(p != NULL)
    {
        t = p->prox; /* guarda a referencia p/ prox elemento */
        free(p);
        p = t; /* faz p apontar p/ prox */
    }

}
int main()
{
    FILE *f = fopen("Tempos.txt","a");
    Lista *lst;
    clock_t tempoI, tempoF;

    for(int o = 0; o < 11; o++)
    {
        for(int g = 0; g < 30; g++)
        {
            lst = cria_lista();
            tempoI = clock();
            for (int i = 5000 + (o * 1000); i > 0; i--)
            {
                lst = inserir_ordenado(lst, i);

            }

            tempoF = clock();
            fprintf(f," %lf,", (double)(tempoF - tempoI) / CLOCKS_PER_SEC);
            liberar_list(lst);
        }

        fprintf(f, "\n");

    }

    fclose(f);
    return 0;
}

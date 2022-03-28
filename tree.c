#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;


Arvore*  cria_arv_vazia (void);
Arvore*  arv_constroi (char c, Arvore* e, Arvore* d);
int      verifica_arv_vazia (Arvore* a);
Arvore*  arv_libera (Arvore* a);
int eh_espelho(Arvore * arv_a, Arvore * arv_b);
Arvore * cria_espelho(Arvore * arv_a);

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* arv_constroi (char c, Arvore* e, Arvore* d) {
  Arvore* a = (Arvore*)malloc(sizeof(Arvore));
  a->info = c;
  a->esq = e;
  a->dir = d;
  return a;
}

int verifica_arv_vazia (Arvore* a) {
  return (a == NULL);
}

Arvore* arv_libera (Arvore* a) {
  if (!verifica_arv_vazia(a)) {
    arv_libera (a->esq);
    arv_libera (a->dir);
    free(a);
  }
  return NULL;
}

int eh_espelho(Arvore * arv_a, Arvore * arv_b) {
  if (arv_a == NULL && arv_b == NULL)
    return 0;

  if(arv_a->info != arv_b->info)
        return 0;

  if (arv_a->info == arv_b->info &&
      eh_espelho(arv_a->esq, arv_b->dir) &&
      eh_espelho(arv_a->dir, arv_b->esq))
    return 1;
}

Arvore * cria_espelho(Arvore * arv_a) {
  if(arv_a == NULL)
        return cria_arv_vazia();
    
    if(arv_a->dir == NULL && arv_a->esq == NULL)
        return arv_a;
    Arvore * novo = (Arvore*)malloc(sizeof(Arvore));
    novo->info = arv_a->info;
    novo->dir = cria_espelho(arv_a->esq);
    novo->esq = cria_espelho(arv_a->dir);

    return novo;
}


int main (int argc, char *argv[]) {
  Arvore *t, *t1, *t2, *t3, *t4, *t5;

  t1 = arv_constroi('d', cria_arv_vazia(), cria_arv_vazia());
  t2 = arv_constroi('b', t1, cria_arv_vazia());
  t3 = arv_constroi('e', cria_arv_vazia(), cria_arv_vazia());
  t4 = arv_constroi('f', cria_arv_vazia(), cria_arv_vazia());
  t5 = arv_constroi('c', t3, t4);
  t  = arv_constroi('a', t2, t5);

  //espelho
  f1 = arv_constroi('f', cria_arv_vazia(), cria_arv_vazia());
  e1 = arv_constroi('e', cria_arv_vazia(), cria_arv_vazia());
  d1 = arv_constroi('d', cria_arv_vazia(), cria_arv_vazia());
  c1 = arv_constroi('c', f1, e1);
  b1 = arv_constroi('b', cria_arv_vazia(), d1);
  a1 = arv_constroi('a', c1, b1);

    f(eh_espelho(a, a1) == 0)
    printf("eh espelho\n");
    else
    printf("nao eh espelho\n");

    if(eh_espelho(a, cria_espelho(a)) == 0)
        printf("criou um espelho\n");
    else
        printf("nao criou um espelho\n");

    arv_libera(a);
    arv_libera(a1);
    return 0;
}
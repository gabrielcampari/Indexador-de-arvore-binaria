#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

// Estrutura do nó da árvore binária
typedef struct No {
    char palavra[100];
    struct No* esquerda;
    struct No* direito;
} No;

// Declaração de funções
No* criaNo(char* palavra);
No* inseriNo(No* raiz, char* palavra);
int inserirUnico(No** raiz, char* palavra);
bool busca(No* raiz, char* palavra);
void buscaEspecializada(No* raiz, char* trecho);
void removeNo(No** raiz, char* palavra);
void imprimeResultado(No* raiz);
void liberaNo(No* raiz);
int contarNos(No* raiz);
void padronizacao(char* palavra);
void calcularTempoBusca(No* raiz);

#endif
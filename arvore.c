#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Cria um novo nó
No* criaNo(char* palavra) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo) {
        strcpy(novo->palavra, palavra);
        novo->esquerda = NULL;
        novo->direito = NULL;
    }
    return novo;
}

// Insere uma palavra na árvore
No* inseriNo(No* raiz, char* palavra) {
    if (raiz == NULL) {
        return criaNo(palavra);
    }
    if (strcmp(palavra, raiz->palavra) < 0) {
        raiz->esquerda = inseriNo(raiz->esquerda, palavra);
    } else if (strcmp(palavra, raiz->palavra) > 0) {
        raiz->direito = inseriNo(raiz->direito, palavra);
    }
    return raiz;
}

// Insere apenas palavras únicas
int inserirUnico(No** raiz, char* palavra) {
    if (*raiz == NULL) {
        *raiz = criaNo(palavra);
        return 1;
    }

    int cmp = strcmp(palavra, (*raiz)->palavra);
    if (cmp < 0) {
        return inserirUnico(&(*raiz)->esquerda, palavra);
    } else if (cmp > 0) {
        return inserirUnico(&(*raiz)->direito, palavra);
    }

    return 0; // Palavra duplicada
}

// Busca uma palavra na árvore
bool busca(No* raiz, char* palavra) {
    if (raiz == NULL) {
        return false;
    }
    int cmp = strcmp(palavra, raiz->palavra);
    if (cmp == 0) {
        return true;
    } else if (cmp < 0) {
        return busca(raiz->esquerda, palavra);
    } else {
        return busca(raiz->direito, palavra);
    }
}

// Busca especializada (por trecho)
void buscaEspecializada(No* raiz, char* trecho) {
    if (raiz != NULL) {
        buscaEspecializada(raiz->esquerda, trecho);
        if (strstr(raiz->palavra, trecho) != NULL) {
            printf("- %s\n", raiz->palavra);
        }
        buscaEspecializada(raiz->direito, trecho);
    }
}

// Remove uma palavra da árvore
void removeNo(No** raiz, char* palavra) {
    if (*raiz == NULL) return;

    int cmp = strcmp(palavra, (*raiz)->palavra);
    if (cmp < 0) {
        removeNo(&(*raiz)->esquerda, palavra);
    } else if (cmp > 0) {
        removeNo(&(*raiz)->direito, palavra);
    } else {
        if ((*raiz)->esquerda == NULL) {
            No* temp = (*raiz)->direito;
            free(*raiz);
            *raiz = temp;
        } else if ((*raiz)->direito == NULL) {
            No* temp = (*raiz)->esquerda;
            free(*raiz);
            *raiz = temp;
        } else {
            No* temp = (*raiz)->direito;
            while (temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            strcpy((*raiz)->palavra, temp->palavra);
            removeNo(&(*raiz)->direito, temp->palavra);
        }
    }
}

// Imprime as palavras em ordem
void imprimeResultado(No* raiz) {
    if (raiz != NULL) {
        imprimeResultado(raiz->esquerda);
        printf("- %s\n", raiz->palavra);
        imprimeResultado(raiz->direito);
    }
}

// Libera a memória da árvore
void liberaNo(No* raiz) {
    if (raiz != NULL) {
        liberaNo(raiz->esquerda);
        liberaNo(raiz->direito);
        free(raiz);
    }
}

// Conta o número total de palavras na árvore
int contarNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direito);
}

// Padroniza uma palavra
void padronizacao(char* palavra) {
    int i, j = 0;
    char temp[strlen(palavra) + 1];
    for (i = 0; palavra[i] != '\0'; i++) {
        char c = palavra[i];
        if (strchr("áàâãä", c)) c = 'a';
        else if (strchr("éèêë", c)) c = 'e';
        else if (strchr("íìîï", c)) c = 'i';
        else if (strchr("óòôõö", c)) c = 'o';
        else if (strchr("úùûü", c)) c = 'u';
        else if (c == '\xE7') c = 'c'; // Unicode para 'ç'
        if (isalnum(c)) { // Verifica se é letra ou dígito
            temp[j++] = tolower(c);
        }
    }
    temp[j] = '\0';
    strcpy(palavra, temp);
}

// Calcula o tempo de busca
void calcularTempoBusca(No* raiz) {
    char palavra[100];
    printf("Digite a palavra para medir o tempo de busca: ");
    scanf("%s", palavra);
    padronizacao(palavra);

    clock_t inicio = clock();
    bool resultado = busca(raiz, palavra);
    clock_t fim = clock();

    double tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    if (resultado) {
        printf("Palavra '%s' encontrada em %.6f segundos.\n", palavra, tempoGasto);
    } else {
        printf("Palavra '%s' não encontrada (tempo: %.6f segundos).\n", palavra, tempoGasto);
    }
}
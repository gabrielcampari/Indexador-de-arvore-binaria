#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void exibeMenu() {
    printf("\n=========================================\n");
    printf("   🌳 Bem-vindo ao Projeto C 🌳\n");
    printf("   ⌨ Indexador de Texto ⌨ \n");
    printf("=========================================\n\n");
    printf("1️⃣  Inserir uma palavra\n");
    printf("2️⃣  Buscar uma palavra\n");
    printf("3️⃣  Exibir palavras\n");
    printf("4️⃣  Remover uma palavra\n");
    printf("5️⃣  Busca especializada\n");
    printf("6️⃣  Calcular tempo de busca\n");
    printf("7️⃣  Carregar palavras de arquivo\n");
    printf("8️⃣  Sair\n");
    printf("\n");
    printf("=========================================\n");
    printf("👉 Escolha uma opção: ");
}

void carregarArquivo(No** raiz, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("❌ Erro ao abrir o arquivo '%s'. Verifique se ele existe.\n", nomeArquivo);
        return;
    }

    char palavra[100];
    int palavrasInseridas = 0;

    printf("\n📂 Carregando palavras do arquivo '%s':\n", nomeArquivo);
    while (fgets(palavra, sizeof(palavra), arquivo)) {
        // Remove newline e espaços extras
        palavra[strcspn(palavra, "\r\n")] = '\0';
        padronizacao(palavra);
        if (strlen(palavra) > 0) {
            if (inserirUnico(raiz, palavra)) {
                palavrasInseridas++;
            }
        }
    }

    fclose(arquivo);
    printf("✅ Carregamento concluído! %d palavras foram inseridas.\n", palavrasInseridas);
    printf("📊 Total de palavras na árvore: %d\n", contarNos(*raiz));
}

int main() {
    No* raiz = NULL;
    int opcao;
    char palavra[100];

    do {
        exibeMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n📝 Digite a palavra: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                if (strlen(palavra) == 0) {
                    printf("⚠ Palavra inválida! Certifique-se de que ela contém apenas letras ou números.\n");
                } else if (inserirUnico(&raiz, palavra)) {
                    printf("✅ Palavra '%s' inserida com sucesso!\n", palavra);
                } else {
                    printf("⚠ Palavra '%s' já existe na árvore!\n");
                }
                printf("📊 Total de palavras na árvore: %d\n", contarNos(raiz));
                break;
            case 2:
                printf("\n🔍 Digite a palavra que deseja buscar: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                if (busca(raiz, palavra)) {
                    printf("✅ Palavra '%s' encontrada!\n", palavra);
                } else {
                    printf("❌ Palavra '%s' não encontrada!\n", palavra);
                }
                break;
            case 3:
                printf("\n📂 Palavras armazenadas (ordem alfabética):\n");
                if (raiz == NULL) {
                    printf("🌱 Árvore vazia.\n");
                } else {
                    imprimeResultado(raiz);
                }
                break;
            case 4:
                printf("\n🗑 Digite a palavra que deseja remover: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                removeNo(&raiz, palavra);
                printf("✅ Palavra '%s' removida (se existia)!\n", palavra);
                printf("📊 Total de palavras na árvore: %d\n", contarNos(raiz));
                break;
            case 5:
                printf("\n🔍 Digite o trecho que deseja buscar: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                printf("\n📂 Palavras contendo o trecho '%s':\n", palavra);
                buscaEspecializada(raiz, palavra);
                break;
            case 6:
                calcularTempoBusca(raiz);
                break;
            case 7:
                carregarArquivo(&raiz, "arquivo.txt");
                break;
            case 8:
                printf("\n👋 Saindo... Obrigado por usar o programa!\n");
                break;
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 8);

    liberaNo(raiz);
    return 0;
}
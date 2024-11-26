# Indexador de Texto com Árvores Binárias de Pesquisa

Este é um software em C que utiliza árvores binárias de pesquisa para armazenar palavras e realizar operações específicas, como inserção, busca e exibição em ordem alfabética. Foi desenvolvido para fins educacionais, demonstrando conceitos de estrutura de dados e organização modular em C.

## Funcionalidades

- Inserir palavras na árvore binária.
- Verificar se uma palavra já está presente na árvore.
- Exibir todas as palavras em ordem alfabética.
- Armazenar palavras em um arquivo para persistência.

## Estrutura do Projeto

O projeto é dividido em quatro arquivos principais:

1. **`main.c`**: Arquivo principal que gerencia o fluxo do programa e a interação com o usuário.
2. **`arvore.c`**: Implementação das funções que manipulam a árvore binária de pesquisa.
3. **`arvore.h`**: Definição da interface para as funções relacionadas à árvore binária.
4. **`arquivo.txt`**: Arquivo utilizado para persistir os dados da árvore.

## Pré-requisitos

- **Compilador C** (como GCC)
- **IDE ou Editor de Texto** (recomendado: Visual Studio Code)
- Sistema operacional compatível (Linux, macOS ou Windows)

## Executando no OnlineGDB

1. Acesse os links do código-fonte para os arquivos: `main.c`, `arvore.c`, `arvore.h` e `arquivo.txt`.
2. Cole cada arquivo na respectiva aba do [OnlineGDB](https://www.onlinegdb.com/).
3. No canto superior direito, selecione a linguagem como "C".
4. Clique no botão **Run** para compilar e executar o programa.
5. Interaja com o terminal para testar as funcionalidades.

## Configuração no Visual Studio Code

1. **Instale o Visual Studio Code** e as seguintes extensões:
   - **C/C++** da Microsoft.
2. **Configure o ambiente**:
   - Instale o GCC ou MinGW (no Windows).
   - Adicione o GCC ao `PATH` do sistema.
3. **Abra a pasta do projeto** no VS Code.
4. Crie um arquivo `tasks.json` na pasta `.vscode` com o seguinte conteúdo:

   ```json
   {
     "version": "2.0.0",
     "tasks": [
       {
         "label": "Compilar",
         "type": "shell",
         "command": "gcc",
         "args": ["main.c", "arvore.c", "-o", "indexador"],
         "group": {
           "kind": "build",
           "isDefault": true
         }
       }
     ]
   }
   ```

## Contribuidores:
Desenvolvedor: Gabriel Campari Correia, Gabriel Henrique Imolene Vieira, Glenda Borges Ferreira de Carvalho, Stefano Moretti.

## Licença
Este projeto é licenciado sob a MIT License.

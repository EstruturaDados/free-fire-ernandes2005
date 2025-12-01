#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Estrutura Item:
    Representa qualquer objeto armazenado na mochila do jogador.
    Cada item possui um nome, um tipo e uma quantidade associada.
*/
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Protótipos das funções
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);

int main() {
    Item mochila[10];   // Vetor que armazena até 10 itens
    int total = 0;      // Quantidade atual de itens cadastrados
    int opcao;

    do {
        printf("\n======= SISTEMA DE INVENTARIO =======\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        switch(opcao) {
            case 1:
                inserirItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 3:
                listarItens(mochila, total);
                break;

            case 4:
                buscarItem(mochila, total);
                break;

            case 5:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 5);

    return 0;
}

/*
    Função inserirItem:
    Adiciona um novo item ao vetor mochila.
*/
void inserirItem(Item mochila[], int *total) {
    if (*total >= 10) {
        printf("\nA mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\n--- Cadastro de Novo Item ---\n");

    printf("Nome do item: ");
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // remove \n

    printf("Tipo do item (arma, municao, cura...): ");
    fgets(novo.tipo, 20, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar();

    mochila[*total] = novo;
    (*total)++;

    printf("\nItem adicionado com sucesso!\n");
}

/*
    Função removerItem:
    Remove um item da mochila com base no nome.
*/
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("\nA mochila esta vazia! Nada para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            // Move os itens seguintes uma posição para trás
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }

    printf("Item nao encontrado!\n");
}

/*
    Função listarItens:
    Exibe todos os itens da mochila.
*/
void listarItens(Item mochila[], int total) {
    printf("\n===== Itens na Mochila =====\n");

    if (total == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Item %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
        printf("-----------------------------\n");
    }
}

/*
    Função buscarItem:
    Realiza uma busca sequencial pelo nome do item.
*/
void buscarItem(Item mochila[], int total) {
    if (total == 0) {
        printf("\nA mochila esta vazia! Nada para buscar.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado!\n");
}
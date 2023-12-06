#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_PRODUTOS 100


struct Produto {
    int codigo;
    char descricao[100];
    int quantidade;
    float valor;
};


struct Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;


void inicializarEstoque() {
    totalProdutos = 0;
}


void cadastrarProduto() {
    if (totalProdutos < MAX_PRODUTOS) {
        printf("Digite o código do produto: ");
        scanf("%d", &estoque[totalProdutos].codigo);
        printf("Digite a descrição do produto: ");
        scanf(" %[^\n]s", estoque[totalProdutos].descricao);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &estoque[totalProdutos].quantidade);
        printf("Digite o valor do produto: ");
        scanf("%f", &estoque[totalProdutos].valor);


        totalProdutos++;
        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("Estoque cheio. Não é possível adicionar mais produtos.\n");
    }
}


void listarProdutos() {
    printf("\n=== Relatório de Produtos ===\n");
    printf("Código\tDescrição\tQuantidade\tValor\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("%d\t%s\t\t%d\t\tR$ %.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
    }
    printf("=============================\n");
}


void pesquisarProduto() {
    int codigo;
    printf("Digite o código do produto que deseja pesquisar: ");
    scanf("%d", &codigo);


    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d\nDescrição: %s\nQuantidade: %d\nValor: R$ %.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}


void removerProduto() {
    int codigo;
    printf("Digite o código do produto que deseja remover: ");
    scanf("%d", &codigo);


    int encontrado = 0;
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            encontrado = 1;
            for (int j = i; j < totalProdutos - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            totalProdutos--;
            printf("Produto removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}


int main() {
    int opcao;


    while (1) {
        printf("\n=== Sistema de Controle de Estoque ===\n");
        printf("1. Inicializar Estoque\n");
        printf("2. Cadastrar Produto\n");
        printf("3. Listar Produtos\n");
        printf("4. Pesquisar Produto\n");
        printf("5. Remover Produto\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                inicializarEstoque();
                printf("Estoque inicializado.\n");
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                pesquisarProduto();
                break;
            case 5:
                removerProduto();
                break;
            case 6:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }


    return 0;
}

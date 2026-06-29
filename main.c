#include <stdio.h>
#include "sistema.h"

// Vetor principal onde os produtos são armazenados
Produto produtos[MAX];
Cliente clientes[MAX];
Venda vendas[MAX];

// Contadores
int qtdProdutos = 0;
int qtdClientes = 0;
int qtdVendas = 0;

// Próximo ID disponível
int idProduto = 1;
int idVenda = 1;

int main()
{
    int menuPrincipal;
    int opcao;

    // Carrega todos os dados txt quando o programa inicia
    carregarDados();

    do
    {
        printf("\n=================================\n");
        printf("        SISTEMA DE ESTOQUE\n");
        printf("=================================\n");
        printf("1 - Produtos\n");
        printf("2 - Clientes\n");
        printf("3 - Vendas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menuPrincipal);

        switch (menuPrincipal)
        {
        case 1:
            do
            {
                printf("\n========== PRODUTOS ==========\n");
                printf("1 - Incluir Produto\n");
                printf("2 - Excluir Produto\n");
                printf("3 - Listar Produtos\n");
                printf("4 - Atualizar Estoque\n");
                printf("5 - Buscar Produto\n");
                printf("6 - Buscar Produto por Nome\n");
                printf("7 - Valor Total Estoque\n");
                printf("8 - Relatorio Estoque Baixo\n");
                printf("0 - Voltar\n");
                printf("Opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    incluirProduto();
                    break;

                case 2:
                    excluirProduto();
                    break;

                case 3:
                    listarProdutos();
                    break;

                case 4:
                    atualizarEstoque();
                    break;

                case 5:
                    buscarProduto();
                    break;

                case 6:
                    buscarProdutoPorNome();
                    break;

                case 7:
                    valorTotalEstoque();
                    break;

                case 8:
                    relatorioEstoqueBaixo();
                    break;

                case 0:
                    printf("Voltando ao menu principal...\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                }

                if (opcao != 0)
                {
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getchar() != '\n');
                    getchar();
                }

            } while (opcao != 0);
            break;

        case 2:
            do
            {
                printf("\n========== CLIENTES ==========\n");
                printf("1 - Incluir Cliente\n");
                printf("2 - Listar Clientes\n");
                printf("0 - Voltar\n");
                printf("Opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    incluirCliente();
                    break;

                case 2:
                    listarClientes();
                    break;

                case 0:
                    printf("Voltando ao menu principal...\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                }

                if (opcao != 0)
                {
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getchar() != '\n');
                    getchar();
                }

            } while (opcao != 0);
            break;

        case 3:
            do
            {
                printf("\n=========== VENDAS ===========\n");
                printf("1 - Incluir Venda\n");
                printf("2 - Listar Vendas\n");
                printf("0 - Voltar\n");
                printf("Opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    incluirVenda();
                    break;

                case 2:
                    listarVendas();
                    break;

                case 0:
                    printf("Voltando ao menu principal...\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                }

                if (opcao != 0)
                {
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getchar() != '\n');
                    getchar();
                }

            } while (opcao != 0);
            break;

        case 0:
            salvarDados();
            printf("Encerrando sistema...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (menuPrincipal != 0);

    return 0;
}
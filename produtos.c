#include <stdio.h>
#include <string.h>
#include "sistema.h"

// Função para cadastrar um novo produto
void incluirProduto()
{

    // Verifica se o vetor está cheio impossibilitando de colocar mais um produto
    if (qtdProdutos >= MAX)
    {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;

    // Gerar ID
    p.id = idProduto++; // Aqui ele gera o id de forma automatica começando em 1 para ser mais fácil a pesquisa e a cada produto adicionado aumenta 1

    printf("Nome do produto: ");
    getchar(); // Usamos para remover o Enter que fica de outro scanf, estava dando problema, precisamos da ajuda da IA

    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    // Verifica se já existe produto com o mesmo nome
    for (int i = 0; i < qtdProdutos; i++)
    {

        if (strcmp(produtos[i].nome, p.nome) == 0)
        { // Comparação de nomes usando o strcmp para strings
            printf("Produto ja cadastrado!\n");
            return;
        }
    }

    printf("Quantidade em estoque: ");
    scanf("%d", &p.quantidade);

    printf("Preco unitario: ");
    scanf("%f", &p.preco);

    p.deletado = 0; // mostra se esta delatado ou não
    p.possuiVenda = 0; //mostra se há venda registrada desse produto.

    // Salva o produto no vetor
    produtos[qtdProdutos] = p; // Copia os dados do P para a posição do vetor que está livre

    qtdProdutos++; // Incremento da quantidade de produto

    salvarDados(); // chama a função que vai incrementar dados no txt

    printf("Produto cadastrado com sucesso!\n");
    printf("ID gerado: %d\n", p.id);
}

// Lista todos os produtos cadastrados
void listarProdutos()
{

    if (qtdProdutos == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE PRODUTOS =====\n");

    for (int i = 0; i < qtdProdutos; i++)  //vetor para exibir todos os produtos cadastrados
    {

        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preco: R$ %.2f\n", produtos[i].preco);

        if (produtos[i].deletado)
            printf("[DELETADO]\n");

        if (produtos[i].quantidade == 0)
            printf("[SEM ESTOQUE]\n");

        printf("------------------------\n");
    }
}

// Marca o produto como excluido, mas não o retira do vetor conforme o professr pediu
void excluirProduto()
{

    int id;

    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    for (int i = 0; i < qtdProdutos; i++)
    {

        if (produtos[i].id == id)
        { // Comparo o id que coloquei como variavel nessa função com o id que está no vetor para encontrar o produto

            if (produtos[i].possuiVenda)
            {
                printf("Produto possui vendas registradas.\n"); // Aqui é para quando um produto já teve alguma venda ele não poder ser excluido porque senão o sistema mostraria a venda de um produto que meio que não existe mais
                return;
            }

            produtos[i].deletado = 1;
            salvarDados(); // salva os dados no txt

            printf("Produto deletado com sucesso.\n");
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

// Atualiza o estoque do produto
void atualizarEstoque()
{

    int id;
    int opcao;
    int quantidade;

    printf("ID do produto: ");
    scanf("%d", &id);

    for (int i = 0; i < qtdProdutos; i++)
    {

        if (produtos[i].id == id && !produtos[i].deletado) //mesma lógica da exclusão, só que aqui tem a condição de não ser um produto deletado
        {

            printf("1 - Entrada\n");
            printf("2 - Saida\n");
            scanf("%d", &opcao);

            printf("Quantidade: ");
            scanf("%d", &quantidade);

            if (opcao == 1)
            {

                produtos[i].quantidade += quantidade; // Aqui vai aumentar a quantidade de certo produto, apenas abreviei o codigo dessa fomra
            }
            else
            {

                if (produtos[i].quantidade < quantidade)
                {
                    printf("Estoque insuficiente.\n");
                    return;
                }

                produtos[i].quantidade -= quantidade;
            }

            salvarDados(); // salva os dados no txt

            printf("Estoque atualizado.\n");
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

// Busca um produto pelo ID
void buscarProduto()
{

    int id;

    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    for (int i = 0; i < qtdProdutos; i++)
    {

        if (produtos[i].id == id)
        { // Comparo o id que coloquei como variavel nessa função com o id que está no vetor para encontrar o produto, mesma lógica da exclusão

            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preco: %.2f\n", produtos[i].preco);

            return;
        }
    }

    printf("PRODUTO NAO LOCALIZADO\n");
}

// Busca produtos por parte do nome 
void buscarProdutoPorNome()
{
    char nome[50];
    int encontrou = 0;

    getchar(); // Limpa o ENTER que ficou do scanf

    printf("Digite o nome ou parte do nome do produto: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("\n===== PRODUTOS ENCONTRADOS =====\n");

    for(int i = 0; i < qtdProdutos; i++)
    {
        // strstr procura se o que o usuario escreveu está dentro de algum nome
        if(strstr(produtos[i].nome, nome) != NULL && !produtos[i].deletado)
        {
            printf("ID: %d\n", produtos[i].id);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preco: R$ %.2f\n", produtos[i].preco);
            printf("------------------------\n");

            encontrou = 1;
        }
    }

    if(!encontrou)
    {
        printf("Nenhum produto encontrado.\n");
    }
}

// Calcula o valor total dos produtos em estoque
void valorTotalEstoque()
{

    float total = 0;

    for (int i = 0; i < qtdProdutos; i++)
    {

        if (!produtos[i].deletado)// calcula o valor de produtos diferentes de deletados.
        {

            total += produtos[i].quantidade * produtos[i].preco; 
        }
    }

    printf("Valor total do estoque: R$ %.2f\n", total);
}

// Mostra os produtos abaixo de um limite informado
void relatorioEstoqueBaixo()
{

    int limite;

    printf("Informe o limite minimo de estoque: ");
    scanf("%d", &limite);

    printf("\nProdutos com estoque baixo:\n");

    for (int i = 0; i < qtdProdutos; i++) // mostra os produtos com estoque baixo, mesmo que esteja deletado
    {

        if (produtos[i].quantidade <= limite)
        {

            printf("%s - %d unidades\n",
                   produtos[i].nome,
                   produtos[i].quantidade);
        }
    }
}
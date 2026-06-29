#include <stdio.h>
#include <string.h>
#include "sistema.h"

// Verifica se a data digitada e valida
int dataValida(int dia, int mes, int ano)
{

    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano < 1900 || mes < 1 || mes > 12 || dia < 1)
    {
        return 0;
    }

    // Verifica ano bissexto
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        diasMes[1] = 29;
    }

    if (dia > diasMes[mes - 1])
    {
        return 0;
    }

    return 1;
}

// Registra uma nova venda
void incluirVenda()
{

    if (qtdVendas >= MAX)
    {
        printf("Limite de vendas atingido!\n");
        return;
    }

    Venda v;
    int posCliente = -1, posProduto = -1;

    v.idVenda = idVenda++;

    printf("Dia: ");
    scanf("%d", &v.dia);

    printf("Mes: ");
    scanf("%d", &v.mes);

    printf("Ano: ");
    scanf("%d", &v.ano);

    if (!dataValida(v.dia, v.mes, v.ano))
    {
        printf("Data invalida.\n");
        idVenda--;
        return;
    }

    printf("CPF do cliente: ");
    scanf("%s", v.cpf);

    // Procura o cliente pelo CPF
    for (int i = 0; i < qtdClientes; i++)
    {

        if (strcmp(clientes[i].cpf, v.cpf) == 0)
        {
            posCliente = i;
        }
    }

    if (posCliente == -1)
    {
        printf("Cliente nao encontrado.\n");
        idVenda--;
        return;
    }

    printf("ID do produto: ");
    scanf("%d", &v.idProduto);

    // Procura o produto pelo ID
    for (int i = 0; i < qtdProdutos; i++)
    {

        if (produtos[i].id == v.idProduto && !produtos[i].deletado)
        {
            posProduto = i;
        }
    }

    if (posProduto == -1)
    {
        printf("Produto nao encontrado ou deletado.\n");
        idVenda--;
        return;
    }

    printf("Quantidade vendida: ");
    scanf("%d", &v.quantidade);

    if (v.quantidade <= 0)
    {
        printf("Quantidade invalida.\n");
        idVenda--;
        return;
    }

    if (v.quantidade > produtos[posProduto].quantidade)
    {
        printf("Estoque insuficiente.\n");
        idVenda--;
        return;
    }

    // Baixa automatica do estoque e soma venda do cliente
    produtos[posProduto].quantidade -= v.quantidade;
    produtos[posProduto].possuiVenda = 1;
    clientes[posCliente].totalVendas++;

    vendas[qtdVendas] = v;
    qtdVendas++;

    salvarDados();

    printf("Venda cadastrada com sucesso!\n");
    printf("ID da venda: %d\n", v.idVenda);
}

// Lista o historico de vendas
void listarVendas()
{

    if (qtdVendas == 0)
    {
        printf("Nenhuma venda cadastrada.\n");
        return;
    }

    printf("\n===== LISTA DE VENDAS =====\n");

    for (int i = 0; i < qtdVendas; i++)
    {

        char nomeCliente[80] = "Cliente nao encontrado";
        char nomeProduto[50] = "Produto nao encontrado";

        for (int j = 0; j < qtdClientes; j++)
        {
            if (strcmp(clientes[j].cpf, vendas[i].cpf) == 0)
            {
                strcpy(nomeCliente, clientes[j].nome);
            }
        }

        for (int j = 0; j < qtdProdutos; j++)
        {
            if (produtos[j].id == vendas[i].idProduto)
            {
                strcpy(nomeProduto, produtos[j].nome);
            }
        }

        printf("ID Venda: %d\n", vendas[i].idVenda);
        printf("Data: %02d/%02d/%d\n", vendas[i].dia, vendas[i].mes, vendas[i].ano);
        printf("Cliente: %s - %s\n", vendas[i].cpf, nomeCliente);
        printf("Produto: %d - %s\n", vendas[i].idProduto, nomeProduto);
        printf("Quantidade: %d\n", vendas[i].quantidade);
        printf("------------------------\n");
    }
}

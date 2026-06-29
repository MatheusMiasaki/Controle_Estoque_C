#include <stdio.h>
#include <string.h>
#include "sistema.h"


//salva todos os dados dos produtos, clientes e vendas em txt.
void salvarDados()
{
 
    FILE *arquivo; // Ponteiro para o arquivo (atua como uma ponte entre o sistema e o arquivo no disco)

    arquivo = fopen("dados/produtos.txt", "w"); // Abre o arquivo para escrita (write), se o arquivo não existir, ele será criado, Se já existir o conteúdo será sobrescrito.
    fprintf(arquivo, "%d %d\n", qtdProdutos, idProduto);

    for (int i = 0; i < qtdProdutos; i++) // Escreve os dados de cada produto no arquivo
    {
        fprintf(arquivo, "%d;%s;%d;%f;%d;%d\n ", produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].deletado, produtos[i].possuiVenda);
    }           // id, nome, quantidade, preco, deletado, possuiVenda

    fclose(arquivo); 

    arquivo = fopen("dados/clientes.txt", "w");
    fprintf(arquivo, "%d\n", qtdClientes);

    for (int i = 0; i < qtdClientes; i++)      
    {
        fprintf(arquivo, "%s;%s;%d\n", clientes[i].nome, clientes[i].cpf, clientes[i].totalVendas);
    }

    fclose(arquivo);

    arquivo = fopen("dados/vendas.txt", "w");
    fprintf(arquivo, "%d %d\n", qtdVendas, idVenda);

    for (int i = 0; i < qtdVendas; i++)
    {
        fprintf(arquivo, "%d;%d;%d;%d;%s;%d;%d\n", vendas[i].idVenda, vendas[i].dia, vendas[i].mes, vendas[i].ano, vendas[i].cpf, vendas[i].idProduto, vendas[i].quantidade);
    }

    fclose(arquivo);
}

// Carrega os dados dos arquivos txt
void carregarDados()
{

    FILE *arquivo; //Ponteiro para o arquivo

    arquivo = fopen("dados/produtos.txt", "r"); // Abre o arquivo para leitura

    if (arquivo != NULL) // Verifica se o arquivo foi aberto com sucesso
    {
        fscanf(arquivo, "%d %d\n", &qtdProdutos, &idProduto);

        for (int i = 0; i < qtdProdutos; i++)
        {
            fscanf(arquivo, "%d;%49[^;];%d;%f;%d;%d\n", &produtos[i].id, produtos[i].nome, &produtos[i].quantidade, &produtos[i].preco, &produtos[i].deletado, &produtos[i].possuiVenda);
        }

        fclose(arquivo);
    }

    arquivo = fopen("dados/clientes.txt", "r"); // Abre o arquivo para leitura

    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d\n", &qtdClientes); // Lê a quantidade de clientes cadastrados

        for (int i = 0; i < qtdClientes; i++)
        {
            fscanf(arquivo, "%79[^;];%14[^;];%d\n", clientes[i].nome, clientes[i].cpf, &clientes[i].totalVendas); 
                            //%79[^;] lê até 79 caracteres ou até encontrar um ;
        }

        fclose(arquivo);
    }

    arquivo = fopen("dados/vendas.txt", "r");

    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d %d\n", &qtdVendas, &idVenda); // Le a quantidade de vendas cadastradas e o próximo id de venda disponível

        for (int i = 0; i < qtdVendas; i++)
        {
            fscanf(arquivo, "%d;%d;%d;%d;%14[^;];%d;%d\n", &vendas[i].idVenda, &vendas[i].dia, &vendas[i].mes, &vendas[i].ano, vendas[i].cpf, &vendas[i].idProduto, &vendas[i].quantidade); // Lê os dados de cada venda cadastrada
        }

        fclose(arquivo);
    }
}

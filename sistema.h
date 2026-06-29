#ifndef SISTEMA_H
#define SISTEMA_H


// Quantidade máxima de produtos
#define MAX 10

// Estrutura para armazenar os dados de um produto
typedef struct
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
    int deletado;
    int possuiVenda;
} Produto;

// Estrutura para armazenar os dados do cliente
typedef struct
{
    char nome[80];
    char cpf[15];
    int totalVendas;
} Cliente;

// Estrutura para armazenar os dados de Vendas
typedef struct
{
    int idVenda;
    int dia;
    int mes;
    int ano;
    char cpf[15];
    int idProduto;
    int quantidade;
} Venda;

// Vetor de produtos e variáveis de controle
extern Produto produtos[MAX]; //extern para tornar a variável global e acessível em outros arquivos .c
extern Cliente clientes[MAX];
extern Venda vendas[MAX];

extern int qtdProdutos;
extern int qtdClientes;
extern int qtdVendas;
extern int idProduto;
extern int idVenda;

// Funcoes de produtos
//variaveis global para serem usadas em produtos.c, clientes.c e vendas.c
void incluirProduto(); 
void listarProdutos(); 
void excluirProduto();
void atualizarEstoque();
void buscarProduto();
void buscarProdutoPorNome();
void valorTotalEstoque();
void relatorioEstoqueBaixo();

// Funcoes de clientes
void incluirCliente();
void listarClientes();

// Funcoes de vendas
void incluirVenda();
void listarVendas();

//========================
// Funcoes de arquivo
void carregarDados();
void salvarDados();

#endif
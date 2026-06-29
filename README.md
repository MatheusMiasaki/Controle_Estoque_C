# Sistema de Controle de Estoque em C

Este projeto é um sistema simplificado de controle de estoque desenvolvido em linguagem C. Ele foi criado com o objetivo de aplicar conceitos de programação estruturada, modularização, manipulação de arquivos, structs e vetores.

## Objetivo

O sistema tem como finalidade auxiliar no gerenciamento básico de uma loja, permitindo controlar produtos, clientes e vendas por meio de um menu interativo via console.

## Funcionalidades

### Produtos

* Cadastrar novos produtos
* Listar produtos cadastrados
* Buscar produtos por ID ou nome
* Atualizar quantidade em estoque
* Excluir produtos de forma lógica
* Calcular o valor total do estoque
* Gerar relatório de produtos com estoque baixo

### Clientes

* Cadastrar clientes
* Validar CPF
* Impedir cadastro de CPFs duplicados
* Listar clientes cadastrados
* Exibir o número de vendas realizadas por cliente

### Vendas

* Registrar vendas
* Validar cliente, produto, data e quantidade em estoque
* Baixar automaticamente a quantidade vendida do estoque
* Listar histórico de vendas realizadas

## Tecnologias Utilizadas

* Linguagem C
* Programação estruturada
* Structs
* Vetores
* Manipulação de strings
* Leitura e gravação em arquivos


## Estruturas Principais

O sistema utiliza estruturas personalizadas para representar os dados principais:

* Produto
* Cliente
* Venda

Essas estruturas permitem armazenar e organizar as informações necessárias para o funcionamento do sistema.

## Persistência de Dados

Os dados do sistema são salvos em arquivos, permitindo que produtos, clientes e vendas sejam recuperados automaticamente ao iniciar uma nova execução do programa.

## Regras de Negócio

O sistema possui algumas validações importantes, como:

* Não permitir produtos com nomes duplicados
* Não permitir estoque negativo
* Não permitir CPF inválido ou duplicado
* Não permitir venda de produto inexistente ou deletado
* Não permitir venda com quantidade maior que o estoque disponível
* Não permitir exclusão de produto que já possui venda vinculada

## Autor

Desenvolvido por Matheus Miasaki E Rodrigo Furlaneto como projeto acadêmico para prática de programação estruturada em linguagem C.

#include <stdio.h>
#include <string.h>
#include "sistema.h"

// Valida CPF usando a regra dos digitos verificadores (https://dicasdeprogramacao.com.br/algoritmo-para-validar-cpf)
int validarCpf(char cpf[]) {

    int numeros[11];
    int soma = 0, resto, digito1, digito2;
    
    // Verifica se o CPF tem 11 caracteres e se todos são dígitos
    if(strlen(cpf) != 11) {
        return 0;
    }

    for(int i = 0; i < 11; i++) {

        if(cpf[i] < '0' || cpf[i] > '9') {
            return 0;
        }

        numeros[i] = cpf[i] - '0';
    }

    //Impede CPFs com todos os numeros iguais
    int iguais = 1;

    for(int i = 1; i < 11; i++) {
        if(numeros[i] != numeros[0]) {
            iguais = 0;
        }
    }

    if(iguais) {
        return 0;
    }

    for(int i = 0; i < 9; i++) {
        soma += numeros[i] * (10 - i);
    }

    resto = soma % 11;

    if(resto < 2) {
        digito1 = 0;
    } else {
        digito1 = 11 - resto;
    }

    soma = 0;

    for(int i = 0; i < 10; i++) {
        soma += numeros[i] * (11 - i);
    }

    resto = soma % 11;

    if(resto < 2) {
        digito2 = 0;
    } else {
        digito2 = 11 - resto;
    }

    if(digito1 == numeros[9] && digito2 == numeros[10]) {
        return 1;
    }

    return 0;
}

// Cadastra um novo cliente
void incluirCliente() {


    //clientes maximos são 10, MAX=10.
    if(qtdClientes >= MAX) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente c; // cria a variavel c do tipo Cliente para armazenar os dados do cliente a ser cadastrado

    printf("Nome completo: ");
    getchar();
    fgets(c.nome, 80, stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0'; // Remove o caractere de nova linha adicionado pelo fgets

    if(strlen(c.nome) == 0) {
        printf("Nome nao pode ficar em branco.\n"); 
        return;
    }

    printf("CPF somente numeros: ");
    fgets(c.cpf, 15, stdin);
    c.cpf[strcspn(c.cpf, "\n")] = '\0';

    if(!validarCpf(c.cpf)) {
        printf("CPF invalido.\n");
        return;
    }

    // Verifica se o CPF ja existe
    for(int i = 0; i < qtdClientes; i++) {

        if(strcmp(clientes[i].cpf, c.cpf) == 0) {
            printf("CPF ja cadastrado.\n");
            return;
        }
    }

    c.totalVendas = 0;

    clientes[qtdClientes] = c;
    qtdClientes++;

    salvarDados();

    printf("Cliente cadastrado com sucesso!\n");
}

// Lista todos os clientes cadastrados
void listarClientes() {

    if(qtdClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE CLIENTES =====\n");

    for(int i = 0; i < qtdClientes; i++) {
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Total de vendas: %d\n", clientes[i].totalVendas);
        printf("------------------------\n");
    }
}

#include <stdio.h>
#include <string.h>
#include "evento.h"
#define MAX_EVENTS 50 // maximo de eventos 50

struct evento n;
int contador = 0,edit;
float resultado_capacidade, resultado_inscritos;
int soma_capacidade = 0, soma_inscritos = 0, soma_pagamento = 0;

void limpar_buffer()
{ // evitando que a leitura pule uma entrada.
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int ler_inteiro() {
    int numero;
    while (scanf("%d", &numero) != 1) {
        limpar_buffer(); 
        printf("Entrada invalida. Por favor, insira um número inteiro: ");
    }
    return numero;
}

float ler_float() {
    float numero;
    while (scanf("%f", &numero) != 1) {
        limpar_buffer(); 
        printf("Entrada inválida. Por favor, insira um número válido: ");
    }
    return numero;
}

void create_event()
{ // funcao criar evento
    int opcao = 1;
    int opcao_x;

    while (opcao == 1)
    {
        limpar_buffer();
        printf("\nEscreva o nome do evento:");
        fgets(n.nome[contador], 50, stdin);

        int opcao_data = 1;

        while (opcao_data == 1) {

        printf("Dia:");
        scanf("%d", &n.dia[contador]);
        printf("Mes:");
        scanf("%d", &n.mes[contador]);
        printf("Ano:");
        scanf("%d", &n.ano[contador]);

        if(n.dia[contador] > 31 ||  n.mes[contador] > 12 || n.ano[contador] < 2025) {
            printf("\n========DATA INVALIDA======\n");
            return;
            } else { 
                opcao_data = 0;
            }
        }

        limpar_buffer(); // Criamos a funcao limpar buffer para resolver o problema de pular um comando
        printf("Hora do evento:");
        fgets(n.hora[contador], 10, stdin);
        printf("Local:");
        fgets(n.local[contador], 50, stdin);

        printf("Capacidade:\n");
        n.capacidade[contador] = ler_inteiro();
        printf("Quanto vai custar o evento?(0 - Gratis)");
        n.pagamento[contador] = ler_float(); 
        contador++;
        n.id[contador] = contador;
        limpar_buffer();

        printf("Deseja inserir outro evento? (sim  = 1, Nao = 0): ");
        scanf(" %d", &opcao);

        // limpar_buffer();
    }

    printf("\nEVENTO CRIADO COM SUCESSO\n");

    printf("******1 - Editar Evento*********\n"); // menu
    printf("******2 - Criar Evento**********\n");
    printf("******3 - Listar Evento**********\n");
    printf("******4 - Menu Principal**********\n");
    printf("Opcao:");
    scanf("%d", &opcao_x);

    switch (opcao_x)
    {
    case 1:
        listar_eventos();
        editar_evento();
        break;
    case 2:
        create_event();
        break;
    case 3:
        listar_eventos();
        break;
    case 4:
        // Não chame main() dentro de funções, apenas retorne ao menu principal
        break;
    }

    return;
}

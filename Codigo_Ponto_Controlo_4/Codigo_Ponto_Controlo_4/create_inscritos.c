#include <stdio.h>
#include <string.h>
#include "create_inscritos.h"
#include "evento.h"
#define MAX_EVENTS 50
#define MAX_PERFIS 50

struct evento n;
struct inscritos m;
int contador_inscrever = 0;
char fila_espera[MAX_EVENTS][MAX_FILA][50]; // Fila de espera por evento
int tamanho_fila[MAX_EVENTS] = {0};

void create_perfil()
{
    int n_1 = 1;
    int id_event;

    if(contador == 0) {
        printf("=============Nao existe eventos para se inscrever!===============\n");

        return;
    }

    while (n_1 == 1)
    {
         listar_eventos();
        int valido = 0; // Variável para controle da entrada válida
        while (!valido)
        {
            printf("Insira o id do evento que pretende se inscrever: ");
            if (scanf("%d", &id_event) != 1) // Verifica se a entrada é um número
            {
                printf("\n============== Entrada invalida! ==============\n");
                printf("Por favor, insira um numero entre 1 e %d.\n", contador);
                limpar_buffer(); // Limpa o buffer para evitar loops infinitos
            }
            else if (id_event < 1 || id_event > contador) // ID fora do intervalo
            {
                printf("\n============== ID invalido! ==============\n");
                printf("Por favor, insira um numero entre 1 e %d.\n", contador);
            }
            else
            {
                valido = 1; // Entrada válida
            }
        }

        id_event--;
        limpar_buffer();
        printf("Escreva seu nome:");
        fgets(m.nome[contador_inscrever], 50, stdin);
        m.nome[contador_inscrever][strcspn(m.nome[contador_inscrever], "\n")] = '\0'; // Remove o '\n'

        strcpy(n.participantes[id_event][n.inscritos[id_event]], m.nome[contador_inscrever]);
        
        printf("Escreva seu email:");
        fgets(m.email[contador_inscrever], 50, stdin);

        if (id_event >= 0 && id_event < contador)
        {
            if (n.inscritos[id_event] < n.capacidade[id_event])
            {
                strcpy(n.participantes[id_event][n.inscritos[id_event]], m.nome[contador_inscrever]);
                n.inscritos[id_event]++;
                printf("Inscrito com sucesso no evento!\n");
            }
            else
            {
                // Adiciona à fila de espera se o evento estiver cheio
                strcpy(fila_espera[id_event][tamanho_fila[id_event]], m.nome[contador_inscrever]);
                tamanho_fila[id_event]++;
                printf("\n\n============O evento  esta cheio participante foi adicionado a fila de espera.============\n", m.nome[contador_inscrever]);
                for (int i = 0; i < MAX_EVENTS; i++)
                {
                    if (tamanho_fila[i] > 0)
                    {
                        printf("Fila de espera para o evento: %s", n.nome[i]);
                        for (int j = 0; j < tamanho_fila[i]; j++)
                        {
                            printf("Participante %d: %s\n", j + 1, fila_espera[i][j]);
                        }
                    }
                }
            }
        }

        printf("Deseja se inscrever em outro evento ?\n1 - sim;\n0 - Nao\nR:");
        scanf("%d", &n_1);
        contador_inscrever++;
    }

    for (int i = 0; i < contador_inscrever; i++)
    {
        printf("\n****************INSCRITO COM SUCESSO****************\n");
        printf("id do inscrito: %d\n", i + 1);
        printf("Nome dos Participantes: %s", m.nome[i]);
        printf("Email do Participante: %s", m.email[i]);
        printf("Id do evento que se inscreveu: %d\n\n", id_event + 1);
    }
    return;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Create_event.c"
#include "main.h"
#include "create_inscritos.c"

#define TAM_CODIGO 13
#define ALTURA_BARRAS 6

void ordenar_participantes(int evento_id)
{
    // Ordenar os nomes dos participantes de um evento específico
    qsort(
        n.participantes[evento_id],                 // Ponteiro para o início da lista de participantes
        n.inscritos[evento_id],                     // Número de participantes inscritos
        sizeof(n.participantes[evento_id][0]),      // Tamanho de cada nome
        (int (*)(const void *, const void *))strcmp // Comparação alfabética
    );
}
void listar_eventos()
{
    if (contador == 0)
    {
        printf("==============Nenhum evento criado==============\n");

        return;
    }
    printf("\n=============================================\n");
    printf("****************LISTA DE EVENTOS***************\n");
    printf("=============================================\n");

    for (int i = 0; i < contador; i++)
    { // mostra os eventos criados
        printf("id: %d\n", n.id[i + 1]);
        printf("Nome do evento: %s", n.nome[i]);
        printf("Data: %d-%d-%d\n", n.dia[i], n.mes[i], n.ano[i]);
        printf("Hora:%s", n.hora[i]);
        printf("Local:%s", n.local[i]);
        printf("Capacidade:%d\n", n.capacidade[i]);
        printf("Valor do Evento: %.2f\n", n.pagamento[i]);
        printf("Quantidade de inscritos no evento %d\n", n.inscritos[i]);
        if (n.inscritos[i] > 0)
        {
            ordenar_participantes(i);

            printf("Nome dos Participantes:\n");
            for (int j = 0; j < n.inscritos[i]; j++)
            {
                printf("%d- %s\n", j + 1, n.participantes[i][j]);
            }
            printf("\n");
        }
        else
        {
            printf("Sem participantes no momento.\n\n");
        }
    }
}

void estatisticas()
{
    soma_capacidade = 0;
    for (int i = 0; i < contador; i++)
    { // for para percorrer array e fazer a soma e media das capacidades
        soma_capacidade += n.capacidade[i];
        resultado_capacidade = soma_capacidade / contador;
    }
    soma_inscritos = 0;
    for (int i = 0; i < contador; i++)
    { // for para percorrer array e fazer a media dos inscritos por evento
        soma_inscritos += n.inscritos[i];
        resultado_inscritos = soma_inscritos / contador;
    }
    soma_pagamento = 0;
    for (int i = 0; i < contador; i++)
    {
        soma_pagamento += n.pagamento[i]; // for percorrer array e fazer a soma dos pagamentos
    }
    printf("\n****************ESTATISTICAS**************\n"); // mostra as estatisticas
    printf("Numero total de eventos criados: %d\n", contador);
    printf("Media das capacidad4es: %.2f\n", resultado_capacidade);
    printf("Media de inscritos por evento %.2f\n", resultado_inscritos);
    if (contador > 0)
    {
        int maior = n.inscritos[0];
        int id_maior = 0; // Armazena o índice do evento com mais inscritos

        for (int i = 1; i < contador; i++)
        { // Começa do índice 1 para evitar repetir o valor inicial
            if (n.inscritos[i] > maior)
            {
                maior = n.inscritos[i];
                id_maior = i;
            }
        }

        printf("Id do evento com maior numero de inscritos: %d\n", n.id[id_maior] + 1);
    }
    else
    {
        printf("Nao ha eventos para calcular o maior numero de inscritos.\n");
    }
    for (int i = 0; i < contador; i++)
    {
        if (n.inscritos[i] >= n.capacidade[i])
        {
            printf("Id dos eventos que atingiram a capacidade Maxima: %d\n", n.id[i + 1]);
        }
    }
    printf("Total de receitas: %d\n\n", soma_pagamento);
}

#define TAM_CODIGO 13 // Número de dígitos de um código de barras padrão EAN-13

void gerarCodigoDeBarras()
{
    int i, digitos[TAM_CODIGO];

    // Gera os números do código de barras
    for (i = 0; i < TAM_CODIGO; i++)
    {
        digitos[i] = rand() % 10; // Gera um número aleatório entre 0 e 9
    }

    // Imprime as barras verticais
    printf("Codigo de barras:\n\n");
    for (int linha = 0; linha < ALTURA_BARRAS; linha++)
    { // Linhas para criar a altura das barras
        for (i = 0; i < TAM_CODIGO; i++)
        {
            if (digitos[i] % 2 == 0)
            {
                printf("| "); // Barras largas para dígitos pares
            }
            else
            {
                printf("||"); // Barras estreitas para dígitos ímpares
            }
        }
        printf("\n");
    }

    // Imprime os números do código de barras abaixo das barras
    for (i = 0; i < TAM_CODIGO; i++)
    {
        printf("%d ", digitos[i]);
    }
    printf("\n");
}

void bilhetes()
{
    if (contador == 0)
    {
        printf("============= Nenhum evento criado =============\n");
        return;
    }

    int bilhete_id = 1; // Contador de bilhetes
    printf("\n=================== LISTA DE BILHETES ===================\n");

    // Percorrer todos os eventos
    for (int i = 0; i < contador; i++)
    {
        if (n.inscritos[i] > 0)
        {
            printf("\n==== Bilhetes para o Evento: %s ====\n", n.nome[i]);
            for (int j = 0; j < n.inscritos[i]; j++)
            { // Percorrer participantes inscritos no evento
                printf("Bilhete ID: %d\n", bilhete_id++);
                printf("Participante: %s\n", n.participantes[i][j]);
                printf("Evento: %s", n.nome[i]);
                printf("Data: %02d-%02d-%04d\n", n.dia[i], n.mes[i], n.ano[i]);
                printf("Hora: %s", n.hora[i]);
                printf("Local: %s", n.local[i]);

                // Gerar e exibir código de barras
                gerarCodigoDeBarras();

                printf("\n--------------------------------------------------------\n");
            }
        }
        else
        {
            printf("\nEvento: %s", n.nome[i]);
            printf("Nenhum participante inscrito para gerar bilhetes.\n");
            printf("--------------------------------------------------------\n");
        }
    }

    if (bilhete_id == 1)
    {
        printf("============= Nenhum bilhete gerado ainda! =============\n");
    }
}

void remover_evento()
{
    int idParaRemover;
    int encontrado = 0;

    if (contador == 0)
    {
        printf("================== Nenhum evento criado ==================\n");
        return;
    }

    printf("Digite o ID do evento a ser removido: ");
    scanf("%d", &idParaRemover);

    idParaRemover -= 1;

    // Procurar o evento a ser removido
    for (int i = 0; i < contador; i++)
    {
        if (n.id[i] == idParaRemover)
        {
            encontrado = 1;

            // Remover o evento deslocando os elementos subsequentes
            for (int j = i; j < contador - 1; j++)
            {
                n.id[j] = n.id[j + 1];
                strcpy(n.nome[j], n.nome[j + 1]);
                n.dia[j] = n.dia[j + 1];
                n.mes[j] = n.mes[j + 1];
                n.ano[j] = n.ano[j + 1];
                strcpy(n.hora[j], n.hora[j + 1]);
                strcpy(n.local[j], n.local[j + 1]);
                n.capacidade[j] = n.capacidade[j + 1];
                n.pagamento[j] = n.pagamento[j + 1];
                n.inscritos[j] = n.inscritos[j + 1];
                // Copiar todos os participantes do evento
                for (int k = 0; k < MAX_PARTICIPANTES; k++) {
                    strcpy(n.participantes[j][k], n.participantes[j + 1][k]);
                }
            }

            contador--; // Reduz o número de eventos
            printf("Evento removido com sucesso.\n");
            return;
        }
    }

    if (!encontrado)
    {
        printf("ID do evento nao encontrado. Tente novamente.\n");
    }
}

void remover_inscrito()
{
    int id_event;
    int encontrado_participante = 0;
    char nome_remover[50];

    if (contador == 0)
    {
        printf("================== Nenhum evento criado ==================\n");
        return;
    }
    listar_eventos();
    printf("Escolha o evento do qual deseja remover um inscrito:\n");

    printf("Insira o id do evento que deseja remover o participante: ");
    scanf("%d", &id_event);

    id_event--; // Ajustar para o índice correto do evento

    // Verificar se o evento existe
    if (id_event < 0 || id_event >= contador)
    {
        printf("Evento nao encontrado!\n");
        return;
    }

    printf("Digite o nome do participante a ser removido: ");
    limpar_buffer();
    fgets(nome_remover, 50, stdin);
    nome_remover[strcspn(nome_remover, "\n")] = '\0'; // Remove o '\n'

    // Procurar o participante pelo nome no evento
    for (int i = 0; i < n.inscritos[id_event]; i++)
    {
        if (strcmp(n.participantes[id_event][i], nome_remover) == 0)
        {
            // Encontrou o participante, removendo-o
            encontrado_participante = 1;
            for (int j = i; j < n.inscritos[id_event] - 1; j++)
            {
                // Desloca os participantes para a esquerda
                strcpy(n.participantes[id_event][j], n.participantes[id_event][j + 1]);
            }
            n.inscritos[id_event]--; // Reduz o número de inscritos
            printf("Participante %s removido com sucesso!\n", nome_remover);
            break;
        }
    }

    if (!encontrado_participante)
    {
        printf("Participante nao encontrado no evento.\n");
        return;
    }
    // Verificar se há alguém na fila de espera
    if (tamanho_fila[id_event] > 0)
    {
        // Adicionar o primeiro da fila de espera ao evento
        strcpy(n.participantes[id_event][n.inscritos[id_event]], fila_espera[id_event][0]);
        n.inscritos[id_event]++; // Aumenta o número de inscritos no evento

        // Remover o primeiro da fila de espera (deslocando todos os outros para a esquerda)
        for (int i = 0; i < tamanho_fila[id_event] - 1; i++)
        {
            strcpy(fila_espera[id_event][i], fila_espera[id_event][i + 1]);
        }

        tamanho_fila[id_event]--; // Reduz o tamanho da fila de espera
        printf("O participante %s foi adicionado ao evento %s, substituindo o participante removido.\n",
               n.participantes[id_event][n.inscritos[id_event] - 1], n.nome[id_event]);
    }
    else
    {
        printf("Nao ha participantes na fila de espera para este evento.\n");
    }
}

void editar_evento()
{
    if (contador == 0)
    {
        printf("==============Nenhum evento criado==============\n");

        return;
    }
    listar_eventos();
    int valido = 0; // Variável para controlar a validação da entrada do ID do evento

    while (!valido)
    {
        printf("Selecione o id do evento que pretende editar: ");
        if (scanf("%d", &edit) != 1) // Verifica se o input é um número inteiro
        {
            printf("Entrada invalida, insira um numero.\n");
            limpar_buffer(); // Limpa o buffer para evitar loops infinitos
        }
        else
        {
            valido = 1; // Marca como válido se o ID for um número
        }
    }

    edit--; // O utilizador escolhe um evento pelo ID. O índice edit é ajustado para corresponder ao índice no array (edit--).

    if (edit >= 0 && edit < contador)
    {
        int opcao_editar = 1;
        
        while (opcao_editar != 0)
        {
            printf("Editando evento id: %d\n", edit + 1);
            printf("1 - Nome do Evento:\n");
            printf("2 - Data\n");
            printf("3 - Hora\n");
            printf("4 - Local\n");
            printf("5 - Capacidade\n");
            printf("6 - Valor\n");
            printf("0 - Sair\n");
            printf("Selecione o campo que deseja editar: ");
            scanf("%d", &opcao_editar);
            limpar_buffer();

            switch (opcao_editar)
            {
            case 1:
                printf("Novo nome do evento: ");
                fgets(n.nome[edit], 50, stdin);
                break;
           case 2: // Editar Data
            {
                int data_valida = 0; // Variável para controle da validação da data
                while (!data_valida)
                {
                    printf("Novo dia: ");
                    scanf("%d", &n.dia[edit]);
                    printf("Novo mes: ");
                    scanf("%d", &n.mes[edit]);
                    printf("Novo ano: ");
                    scanf("%d", &n.ano[edit]);
                    limpar_buffer();

                    // Verifica se a data é válida
                    if (n.dia[edit] < 1 || n.dia[edit] > 31 || n.mes[edit] < 1 || n.mes[edit] > 12 || n.ano[edit] < 2025)
                    {
                        printf("\n======== DATA INVALIDA ========\n");
                        printf("Por favor, insira uma data va  lida.\n");
                    }
                    else
                    {
                        data_valida = 1; // Data válida, sai do loop
                        printf("Data atualizada com sucesso!\n");
                    }
                }
                break;
            }
            case 3:
                printf("Nova hora do evento: ");
                fgets(n.hora[edit], 10, stdin);
                break;
            case 4:
                printf("Novo local: ");
                fgets(n.local[edit], 50, stdin);
                break;
            case 5:
                printf("Nova capacidade: ");
                scanf("%d", &n.capacidade[edit]);
                limpar_buffer();
                break;
            case 6:
                printf("Novo valor:");
                scanf("%f", &n.pagamento[edit]);
                break;
            case 0:
                printf("Saindo do menu de edicao.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
            }
        }

        printf("\nEvento atualizado com sucesso!\n");
        printf("id: %d\n", edit + 1);
        printf("Nome do evento: %s", n.nome[edit]);
        printf("Data: %d-%d-%d\n", n.dia[edit], n.mes[edit], n.ano[edit]);
        printf("Hora: %s", n.hora[edit]);
        printf("Local: %s", n.local[edit]);
        printf("Capacidade: %d\n", n.capacidade[edit]);
        printf("Valor Evento: %.2f\n", n.pagamento[edit]);
    }
    else
    {
        printf("ID invalido.\n");
    }
}
/*Notas:
-verificar que insiram uma problemas na data, hora etc mais simples
-Atualizar dados no menu;
*/
int main()
{
    int opcao; // Menu do codigo
    srand((unsigned int)time(NULL)); // Inicializa o gerador de números aleatórios

    do
    {

        printf("=============================================\n");
        printf("**********BEM VINDO AO HUBEVENTOS************\n");
        printf("=============================================\n");
        printf("1 - Criar Evento\n");
        printf("2 - Remover Evento\n");
        printf("3 - Listar proximos Eventos\n");
        printf("4 - Editar Evento\n");
        printf("5 - Inscrever no Evento\n");
        printf("6 - Remover Inscrito de um evento\n");
        printf("7 - Estatisticas\n");
        printf("8 - Mostrar Bilhetes\n");
        printf("9 - Sair\n");
        printf("Escolha uma opcao:\n");
        scanf("%d", &opcao);

        switch (opcao)
        { // escolher opcao
        case 1:
            create_event();
            break;
        case 2:
            listar_eventos();
            remover_evento();
            break;
        case 3:
            listar_eventos();
            break;
        case 4:
            editar_evento();
            // create_perfil();
            break;
        case 5:
            listar_eventos();
            create_perfil();
            break;
        case 6:
            // listar_eventos();
            remover_inscrito();
            break;
        case 7:
            estatisticas();
            break;
        case 8:
            bilhetes();
            break;
        }
    } while (opcao != 9);
    return 0;
}
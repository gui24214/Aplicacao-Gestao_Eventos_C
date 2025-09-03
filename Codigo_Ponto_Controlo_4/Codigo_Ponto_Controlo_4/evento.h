#ifndef CREATE_EVENT_H
#define CREATE_EVENT_H
#define MAX_EVENTS 50
#define MAX_PARTICIPANTES 50 

struct  evento{
    int id[MAX_EVENTS];
    char nome[MAX_EVENTS][50];
    int dia[MAX_EVENTS];
    int mes[MAX_EVENTS];
    int ano[MAX_EVENTS];
    char hora[MAX_EVENTS][10];
    char local[MAX_EVENTS][50];
    int capacidade[MAX_EVENTS];
    float pagamento[MAX_EVENTS];
    int inscritos[MAX_EVENTS];
    char participantes[MAX_EVENTS][MAX_PARTICIPANTES][50];
    };

void create_event() ;
void listar_eventos();
void remover_evento ();
void estatisticas();
void bilhetes();
void gerarCodigoDeBarras();
void editar_evento();
#endif

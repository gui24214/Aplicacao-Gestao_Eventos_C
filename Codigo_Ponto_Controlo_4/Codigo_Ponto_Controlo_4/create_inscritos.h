#ifndef CREATE_PERFIL_H
#define CREATE_PERFIL_H
#define MAX_PERFIS 50
#define MAX_FILA 50
struct  inscritos{
    int id_perfis[MAX_PERFIS];
    char nome[MAX_PERFIS][50];
    char email[MAX_PERFIS][50];
   // int id_evento [MAX_PERFIS];
    };

void create_perfil ();
void remover_inscrito();
#endif

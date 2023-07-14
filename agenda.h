#ifndef AGENDA_H
#define AGENDA_H

struct _data {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};
typedef struct _data Data;

struct _evento {
    int codigo;
    Data dataEvento;
    float duracao;
    char descricao[100];
    struct _evento *proximo;
};
typedef struct _evento Evento;

void incluirEvento();
void consultarPorData();
void consultarPorDataEHora();
void alterarEvento();
void excluirEvento();
void listarTodos();

#endif
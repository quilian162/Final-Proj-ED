#ifndef AGENDA_H
#define AGENDA_H

typedef struct evento {
    int cod;
    float duracao;
    char descricao[100];
    Data dataEvento;
    struct evento *next;
} Evento;

typedef struct data {
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
} Data;

void incluir();
void consultar();
void alterar();
void excluir();
void listar();

#endif

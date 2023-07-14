#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

Evento *agenda = NULL;

void incluirEvento() {
    int dia, mes, ano, hora, minuto;

    printf("Informe a data e hora do evento (dia mes ano hora minuto): ");
    scanf("%d %d %d %d %d", &dia, &mes, &ano, &hora, &minuto);

    Evento *novoEvento = (Evento *)malloc(sizeof(Evento));
    novoEvento->codigo = rand();  // Gera um código aleatório
    novoEvento->dataEvento.dia = dia;
    novoEvento->dataEvento.mes = mes;
    novoEvento->dataEvento.ano = ano;
    novoEvento->dataEvento.hora = hora;
    novoEvento->dataEvento.minuto = minuto;
    printf("Informe a descrição do evento: ");
    scanf(" %[^\n]", novoEvento->descricao);
    printf("Informe a duração do evento: ");
    scanf("%f", &(novoEvento->duracao));
    novoEvento->proximo = NULL;

    // Verifica se já existe um evento agendado para a mesma data e horário
    Evento *temp = agenda;
    while (temp != NULL) {
        if (temp->dataEvento.dia == dia && temp->dataEvento.mes == mes && temp->dataEvento.ano == ano &&
            temp->dataEvento.hora == hora && temp->dataEvento.minuto == minuto) {
            printf("Já existe um evento agendado para a mesma data e horário.\n");
            free(novoEvento);
            return;
        }
        temp = temp->proximo;
    }

    // Insere o novo evento na agenda
    if (agenda == NULL) {
        agenda = novoEvento;
    } else {
        temp = agenda;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoEvento;
    }

    printf("Evento incluído com sucesso!\n");
}

void consultarPorData() {
    int dia, mes, ano;

    printf("Informe a data para consulta (dia mes ano): ");
    scanf("%d %d %d", &dia, &mes, &ano);

    Evento *temp = agenda;
    int encontrou = 0;

    printf("Eventos na data informada:\n");

    while (temp != NULL) {
        if (temp->dataEvento.dia == dia && temp->dataEvento.mes == mes && temp->dataEvento.ano == ano) {
            printf("Código: %d\n", temp->codigo);
            printf("Data: %d/%d/%d\n", temp->dataEvento.dia, temp->dataEvento.mes, temp->dataEvento.ano);
            printf("Hora: %d:%d\n", temp->dataEvento.hora, temp->dataEvento.minuto);
            printf("Duração: %.2f\n", temp->duracao);
            printf("Descrição: %s\n", temp->descricao);
            printf("\n");
            encontrou = 1;
        }
        temp = temp->proximo;
    }

    if (!encontrou) {
        printf("Nenhum evento encontrado para a data informada.\n");
    }
}

void consultarPorDataEHora() {
    int dia, mes, ano, hora, minuto;

    printf("Informe a data e hora para consulta (dia mes ano hora minuto): ");
    scanf("%d %d %d %d %d", &dia, &mes, &ano, &hora, &minuto);

    Evento *temp = agenda;
    int encontrou = 0;

    printf("Eventos na data e hora informadas:\n");

    while (temp != NULL) {
        if (temp->dataEvento.dia == dia && temp->dataEvento.mes == mes && temp->dataEvento.ano == ano &&
            temp->dataEvento.hora == hora && temp->dataEvento.minuto == minuto) {
            printf("Código: %d\n", temp->codigo);
            printf("Data: %d/%d/%d\n", temp->dataEvento.dia, temp->dataEvento.mes, temp->dataEvento.ano);
            printf("Hora: %d:%d\n", temp->dataEvento.hora, temp->dataEvento.minuto);
            printf("Duração: %.2f\n", temp->duracao);
            printf("Descrição: %s\n", temp->descricao);
            printf("\n");
            encontrou = 1;
            break;
        }
        temp = temp->proximo;
    }

    if (!encontrou) {
        printf("Nenhum evento encontrado para a data e hora informadas.\n");
    }
}

void alterarEvento() {
    int dia, mes, ano, hora, minuto;

    printf("Informe a data e hora do evento a ser alterado (dia mes ano hora minuto): ");
    scanf("%d %d %d %d %d", &dia, &mes, &ano, &hora, &minuto);

    Evento *temp = agenda;
    int encontrou = 0;

    while (temp != NULL) {
        if (temp->dataEvento.dia == dia && temp->dataEvento.mes == mes && temp->dataEvento.ano == ano &&
            temp->dataEvento.hora == hora && temp->dataEvento.minuto == minuto) {
            printf("Informe a nova descrição do evento: ");
            scanf(" %[^\n]", temp->descricao);
            printf("Informe a nova duração do evento: ");
            scanf("%f", &(temp->duracao));
            printf("Evento alterado com sucesso!\n");
            encontrou = 1;
            break;
        }
        temp = temp->proximo;
    }

    if (!encontrou) {
        printf("Nenhum evento encontrado para a data e hora informadas.\n");
    }
}

void excluirEvento() {
    int dia, mes, ano, hora, minuto;

    printf("Informe a data e hora do evento a ser excluído (dia mes ano hora minuto): ");
    scanf("%d %d %d %d %d", &dia, &mes, &ano, &hora, &minuto);

    Evento *temp = agenda;
    Evento *anterior = NULL;
    int encontrou = 0;

    while (temp != NULL) {
        if (temp->dataEvento.dia == dia && temp->dataEvento.mes == mes && temp->dataEvento.ano == ano &&
            temp->dataEvento.hora == hora && temp->dataEvento.minuto == minuto) {
            if (anterior == NULL) {
                agenda = temp->proximo;
            } else {
                anterior->proximo = temp->proximo;
            }
            free(temp);
            printf("Evento excluído com sucesso!\n");
            encontrou = 1;
            break;
        }
        anterior = temp;
        temp = temp->proximo;
    }

    if (!encontrou) {
        printf("Nenhum evento encontrado para a data e hora informadas.\n");
    }
}

void listarTodos() {
    Evento *temp = agenda;

    if (temp == NULL) {
        printf("Agenda vazia.\n");
        return;
    }

    printf("Lista de eventos:\n");

    while (temp != NULL) {
        printf("Código: %d\n", temp->codigo);
        printf("Data: %d/%d/%d\n", temp->dataEvento.dia, temp->dataEvento.mes, temp->dataEvento.ano);
        printf("Hora: %d:%d\n", temp->dataEvento.hora, temp->dataEvento.minuto);
        printf("Duração: %.2f\n", temp->duracao);
        printf("Descrição: %s\n", temp->descricao);
        printf("\n");
        temp = temp->proximo;
    }
}
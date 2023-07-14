#include <stdio.h>
#include "agenda.h"

int main() {
    int op;

    do {
        printf("UFFSAgenda - Menu\n");
        printf("1. Incluir evento\n");
        printf("2. Consultar por data\n");
        printf("3. Consultar por data e hora\n");
        printf("4. Alterar evento\n");
        printf("5. Excluir evento\n");
        printf("6. Listar todos\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                incluirEvento();
                break;
            case 2:
                consultarPorData();
                break;
            case 3:
                consultarPorDataEHora();
                break;
            case 4:
                alterarEvento();
                break;
            case 5:
                excluirEvento();
                break;
            case 6:
                listarTodos();
                break;
            case 7:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
        printf("\n");
    } while (op != 7);

    // Libera a memória alocada para os eventos na agenda
    Evento *temp = agenda;
    while (temp != NULL) {
        Evento *prox = temp->proximo;
        free(temp);
        temp = prox;
    }

    return 0;
}
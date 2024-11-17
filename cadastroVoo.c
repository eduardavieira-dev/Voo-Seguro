#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_VOOS 100

typedef struct Voo {
    int codigoAviao;
    int codigoPiloto;
    int codigoCopiloto;
    int codigoComissario;
    int codigoVoo;
    int status;
    int tarifa;
    char data[11];
    char hora[6];
    char origem[100];
    char destino[100];
} Voo;

Voo voos[MAX_VOOS];
int contagemvoo = 0;

void cadastroVoo() {
    if (contagemvoo >= MAX_VOOS) {
        printf("Limite de voos cadastrados atingido!\n");
        return;
    }

    Voo voo;
    contagemvoo++;
    voo.codigoVoo = contagemvoo;

    printf("Informe a origem do voo:\n");
    fgets(voo.origem, 100, stdin);
    fflush(stdin);

    printf("Informe o destino do voo:\n");
    fgets(voo.destino, 100, stdin);
    fflush(stdin);

    printf("Informe a data do voo (DD/MM/AAAA):\n");
    fgets(voo.data, 11, stdin);
    fflush(stdin);

    printf("Informe a hora do voo (HH:MM):\n");
    fgets(voo.hora, 6, stdin);
    fflush(stdin);

    printf("Informe o código do avião:\n");
    scanf("%d", &voo.codigoAviao);

    printf("Informe o código do Piloto:\n");
    scanf("%d", &voo.codigoPiloto);

    printf("Informe o código do Copiloto:\n");
    scanf("%d", &voo.codigoCopiloto);

    printf("Informe o código do comissário:\n");
    scanf("%d", &voo.codigoComissario);

    printf("Informe a tarifa:\n");
    scanf("%d", &voo.tarifa);

    if (voo.codigoPiloto != 0 && voo.codigoCopiloto != 0) {
        printf("Voo ativo\n");
        voo.status = 1;
    } else {
        printf("Voo inativo, falta piloto ou copiloto\n");
        voo.status = 0;
    }

    voos[contagemvoo - 1] = voo;
    printf("Voo cadastrado com sucesso!\n");
    menuVoos();
}

void listarVoos() {
    if (contagemvoo == 0) {
        printf("Nenhum voo cadastrado.\n");
    } else {
        for (int i = 0; i < contagemvoo; i++) {
            printf("\nInformações de Voo %d:\n", voos[i].codigoVoo);
            printf("Código de voo: %d\n", voos[i].codigoVoo);
            printf("Local de origem: %s\n", voos[i].origem);
            printf("Local de destino: %s\n", voos[i].destino);
            printf("Data: %s\n", voos[i].data);
            printf("Horário: %s\n", voos[i].hora);
            printf("Piloto: %d\n", voos[i].codigoPiloto);
            printf("Copiloto: %d\n", voos[i].codigoCopiloto);
            printf("Comissário: %d\n", voos[i].codigoComissario);
        }
    }
    menuVoos();
}

void menuVoos() {
    setlocale(LC_ALL, "portuguese");

    int opcao;
    printf("\nMenu de Cadastro de Voos\n");
    printf("1 - Cadastrar voo\n");
    printf("2 - Listar voos\n");
    printf("3 - Sair\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao) {
        case 1:
            cadastroVoo();
            break;

        case 2:
            listarVoos();
            break;

        case 3:
            printf("Saindo do sistema.\n");
            exit(0);
            break;

        default:
            printf("Opção inválida.\n");
            menuVoos();
            break;
    }
}

int main() {
    menuVoos();
    return 0;
}

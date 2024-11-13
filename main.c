#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

int main(){
setlocale(LC_ALL, "portuguese");
    int escolha;

    do{
    printf("Escolha o que deseja fazer:\n");
    printf("1 - Cadastrar passageiro\n");
    printf("2 - Cadastrar tripulação\n");
    printf("3 - Cadastrar voo\n");
    printf("4 - Cadastrar assento\n");
    printf("5 - Cadastrar reserva\n");
    printf("6 - Baixa em reservas\n");
    printf("7 - Pesquisa\n");
    printf("8 - Consulta ao programa de fidelidade\n");
    printf("0 - Sair\n");
    scanf("%d", &escolha);
    switch(escolha){

    case 1:
        system("cls");
        printf("escolha 1");
        break;

    case 2:
        system("cls");
        printf("escolha 2");
        break;

    case 3:
        system("cls");
        printf("escolha 3");
        break;

    case 4:
        system("cls");
        printf("escolha 4");
        break;

    case 5:
        system("cls");
        printf("escolha 5");
        break;

    case 6:
        system("cls");
        printf("escolha 6");
        break;

    case 7:
        system("cls");
        printf("escolha 7");
        break;

    case 8:
        system("cls");
        printf("escolha 9");
        break;

    case 0:
        system("cls");
        printf("Programa encerrado\n");
        exit(0);
        break;

    default:
        system("cls");
        printf("Escolha invalida!\n");
        break;
    }
    }while(escolha !=0);

    return 0;
}

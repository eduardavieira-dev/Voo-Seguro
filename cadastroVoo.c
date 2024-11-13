#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Voo{
    int codigoAviao;
    int codigoPiloto;
    int codigoCopiloto;
    int codigoComissario;
    int codigoVoo;
    int data;
    int hora;
    int status;
    int tarifa;
    char origem[100];
    char destino[100];
}Voo;

int main(){
setlocale(LC_ALL, "portuguese");

    return 0;
}

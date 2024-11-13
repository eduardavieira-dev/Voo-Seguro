#include <stdio.h>
#include <locale.h>


 typedef struct Passageiro{
    int id;


    int fidelidade;
    int pontuacao;
    char nome[];
    }Passageiro;


int main(){
    setlocale(LC_ALL, "portuguese");
    Passageiro pass[1];
    scanf("%s", pass.nome);
    printf("%s", pass.nome);
    return 0;
}

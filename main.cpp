#include <iostream>
#include <cstdlib>
#include <locale.h>
#include "Voo.h"

using namespace std;

    void menuVoos (Voo& voo){
    
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int opcao;
    cout << "Menu de Cadastro de Voos" << endl;
    cout << "1 - Cadastrar voo" << endl;
    cout << "2 - Listar voos" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch(opcao){
        case 1:
            voo.cadastroVoo();
            break;

        case 2:
            voo.listarVoo();
            system("cls");
            break;

        case 3:
            break;

        default:
            menuVoos(voo);
            break;
    }

}

int main() {
    setlocale(LC_ALL, "portuguese");
    int escolha;
    Voo voo;
    voo.carregarVoos();
    do {
        cout << "Escolha o que deseja fazer:" << endl;
        cout << "1 - Cadastrar passageiro" << endl;
        cout << "2 - Cadastrar tripulação" << endl;
        cout << "3 - Cadastrar voo" << endl;
        cout << "4 - Cadastrar assento" << endl;
        cout << "5 - Cadastrar reserva" << endl;
        cout << "6 - Baixa em reservas" << endl;
        cout << "7 - Pesquisa" << endl;
        cout << "8 - Consulta ao programa de fidelidade" << endl;
        cout << "0 - Sair" << endl;
        cin >> escolha;

        switch (escolha) {
        case 1:
            system("cls");
            break;

        case 2:
            system("cls");
            cout << "escolha 2" << endl;
            break;

        case 3:
            system("cls");
            menuVoos(voo);
            break;

        case 4:
            system("cls");
            cout << "escolha 4" << endl;
            break;

        case 5:
            system("cls");
            cout << "escolha 5" << endl;
            break;

        case 6:
            system("cls");
            cout << "escolha 6" << endl;
            break;

        case 7:
            system("cls");
            cout << "escolha 7" << endl;
            break;

        case 8:
            system("cls");
            cout << "escolha 9" << endl;
            break;

        case 0:
            system("cls");
            cout << "Programa encerrado" << endl;
            exit(0);
            break;

        default:
            system("cls");
            cout << "Escolha invalida!" << endl;
            break;
        }
    } while (escolha != 0);

    return 0;
}


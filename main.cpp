#include <iostream>
#include <cstdlib>
#include <locale.h>
#include "Laura/Endereco.h"
#include "Laura/Passageiro.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "portuguese");
    int escolha;

    do {
        cout << "Escolha o que deseja fazer:\n";
        cout << "1 - Cadastrar passageiro\n";
        cout << "2 - Cadastrar tripulação\n";
        cout << "3 - Cadastrar voo\n";
        cout << "4 - Cadastrar assento\n";
        cout << "5 - Cadastrar reserva\n";
        cout << "6 - Baixa em reservas\n";
        cout << "7 - Pesquisa\n";
        cout << "8 - Consulta ao programa de fidelidade\n";
        cout << "0 - Sair\n";
        cin >> escolha;

        switch (escolha) {
        case 1:
            {
            system("cls");
            int numero;
            string cidade;
            string rua;

            cout << "Cadastrar passageiro\n";
            cout << "Digite o número residencial:" << endl;
            cin >> numero;
            cout << "Informe a cidade do passageiro: " << endl;
            cin >> cidade;
            cout << "Informe a rua do endereço: " << endl;
            cin >> rua;

            Endereco enderecoN(numero, cidade, rua);
            enderecoN.imprimeEndereco();
            break;
        }


        case 2:
            system("cls");
            cout << "escolha 2\n" << endl;
            break;

        case 3:
            system("cls");
            cout << "escolha 3\n" << endl;
            break;

        case 4:
            system("cls");
            cout << "escolha 4\n" << endl;
            break;

        case 5:
            system("cls");
            cout << "escolha 5\n" << endl;
            break;

        case 6:
            system("cls");
            cout << "escolha 6\n" << endl;
            break;

        case 7:
            system("cls");
            cout << "escolha 7\n" << endl;
            break;

        case 8:
            system("cls");
            cout << "escolha 9\n" << endl;
            break;

        case 0:
            system("cls");
            cout << "Programa encerrado\n" << endl;
            exit(0);
            break;

        default:
            system("cls");
            cout << "Escolha invalida!\n" << endl;
            break;
        }
    } while (escolha != 0);

    return 0;
}

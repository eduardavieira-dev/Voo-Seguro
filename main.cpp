#include <iostream>
#include <cstdlib>
#include <locale.h>
#include "Voo.h"
#include "tripulacao.h"
#include "Passageiro.h"

using namespace std;

// Função para gerar o menu de ações para passageiros
void menuPassageiro(Passageiro& pass)
{
    system("cls");

    int opcao;
    cout << "Menu de Cadastro de Passageiros:" << endl;
    cout << "1 - Cadastrar novo passageiro" << endl;
    cout << "2 - Listar passageiros cadastrados" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch (opcao)
    {
    case 1:
        cadastroPassageiro();
        break;

    case 2:
        listarPassageiros();
        break;

    case 3:
        break;

    default:
        cout << "Opcção inválida. Tente novamente!" << endl;
        menuPassageiro(pass);
        break;
    }
}

// Funcao para gerenciar o menu de tripulantes
void menuTripulacao(Tripulacao& tripulacao) {
    int opt;
    do {
        system("cls");
        cout << "Menu de Cadastro de Tripulantes\n";
        cout << "1 - Cadastrar tripulante\n";
        cout << "2 - Listar tripulantes\n";
        cout << "3 - Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >>opt;

        switch (opt) {
            case 1:
                tripulacao.cadastrarTripulante();
                break;
            case 2:
                tripulacao.listarTripulantes();
                system("pause");
                break;
            case 3:
                return; 
            default:
                cout << "Opcao inválida! Tente novamente.\n";
        }
    } while (opt != 3);

}
    void menuVoos (Voo& voo){
    
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int opcao;
    cout << "Menu de Cadastro de Voos" << endl;
    cout << "1 - Cadastrar voo" << endl;
    cout << "2 - Listar voos" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opcao:" << endl;
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
    Tripulacao tripulacao;
    Passageiro pass;

    pass.carregarPassageiros();
    voo.carregarVoos();
    do {
        cout << "Escolha o que deseja fazer:" << endl;
        cout << "1 - Cadastrar passageiro" << endl;
        cout << "2 - Cadastrar tripulacao" << endl;
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
            menuPassageiro(pass);
            break;

        case 2:
            system("cls");
            menuTripulacao(tripulacao);
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


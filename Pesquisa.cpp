#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Pesquisa.h"
#include "Passageiro.h"
#include "Tripulacao.h"


using namespace std;

Pesquisa pesquisa;

void Pesquisa::pesquisarPassageiro() {
    int opcao;
    cout << "Pesquisa de passageiro" << endl;
        cout << "1 - Pesquisar passageiros por nome" << endl;
        cout << "2 - Pesquisar passageiros por ID" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
}

void Pesquisa::pesquisarTripulacao() {
    int opcao;
    cout << "Pesquisa de membro da tripulação" << endl;
        cout << "1 - Pesquisar tripulante por nome" << endl;
        cout << "2 - Pesquisar tripulante por código" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                pesquisa.pesquisarPassageiro();
                break;
            case 2:
                pesquisa.pesquisarTripulacao();
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
}








void menuPesquisa() {
    system("cls");
    
    int opcao;

    while (true) {
        cout << "Menu de Pesquisa de passageiros e membros da tripulação" << endl;
        cout << "1 - Pesquisar Passageiros" << endl;
        cout << "2 - Pesquisar Membro da Tripulação" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                pesquisa.pesquisarPassageiro();
                break;
            case 2:
                pesquisa.pesquisarTripulacao();
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    }
}

int main() {
    menuPesquisa();
    return 0;
}

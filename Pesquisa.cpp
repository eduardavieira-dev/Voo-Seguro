#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Pesquisa.h"
#include "Passageiro.h"
#include "Tripulacao.h"
#include "Reserva.h"


using namespace std;

extern vector<Reserva> reservas;
extern vector<Passageiro> passageiros;
extern vector<Tripulacao> tripulacaoVet;

// Implementação do método de pesquisa de passageiros
void pesquisarPassageiro() {
    system("chcp 65001");
    int opcao, codPassageiro;
   // string nomePassageiro;
    cout << "Pesquisa de passageiro" << endl;
        cout << "1 - Pesquisar passageiros por nome" << endl;
        cout << "2 - Pesquisar passageiros por ID" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        cin.ignore();
        switch (opcao) {
            case 1:
                  pesquisarNomePassageiro();
              
                break;
            case 2:
                  pesquisarIdPassageiro();
                
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
}
// Implementação do método de pesquisa de tripulação
void pesquisarTripulacao() {
    system("chcp 65001");
    int opcao, codTripulante;
   // string nomeTripulante;
    cout << "Pesquisa de membro da tripulação" << endl;
        cout << "1 - Pesquisar tripulante por nome" << endl;
        cout << "2 - Pesquisar tripulante por código" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
 cin.ignore();
        switch (opcao) {
            case 1:
                pesquisarNomeTripulante();
              
                break;
            case 2:
                pesquisarIdTripulante();
              
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
}

void pesquisarIdTripulante(){
     system("cls");
     int codTripulante;
     bool verificaExistenciaTripulante = false;

    cout<<"Pesquisa id tripulante\n";
      cout << "Informe o código do Tripulannte:" << endl;
        cin >> codTripulante;
        cin.ignore();

 for (int i = 0; i < tripulacaoVet.size(); i++) {
    vector<Tripulacao>& tripulantes = tripulacaoVet[i].getTripulantes();  // Acessa a tripulação específica

    for (int j = 0; j < tripulantes.size(); j++) {

        if (tripulantes[j].getCodigoTripulante() == codTripulante) {
            verificaExistenciaTripulante = true;
            cout << "Existe" << endl;
        }

    }

    cout<<"\n";
}
}



void pesquisarNomeTripulante(){
     system("cls");
     string nomeTripulante;
     bool verificaExistenciaTripulante = false;

    cout<<"Pesquisa nome tripulante\n";
       cout << "Informe o nome do Tripulannte:" << endl;
       getline(cin, nomeTripulante);

    cout<<"\n";
}
void pesquisarIdPassageiro(){
     system("cls");
    cout<<"Pesquisa id passageiro\n";
    bool verificaExistenciaPassageiro = false;
    int codPassageiro;

      cout << "Informe o código do Passageiro:" << endl;
      cin >> codPassageiro;
        

    cout<<"\n";
}
void pesquisarNomePassageiro(){
     system("cls");
     string NomePassageiro;
     bool verificaExistenciaPassageiro = false;

    cout<<"Pesquisa nome passageiro\n";
    cout << "Informe o nome do Passageiro:" << endl;
     getline(cin, NomePassageiro);

    cout<<"\n";

}
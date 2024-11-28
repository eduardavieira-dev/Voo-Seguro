/*
 * ============================================================
 * Nome do Código: Pesquisa por ID e por nome de passageiros e tripulantes
 * Desenvolvedora: Eduarda Vieira Gonçalves
 * Descrição: Este código implementa um sistema para pesquisar passageiros e membros da tripulação,
 *            oferecendo opções para buscar por nome ou ID. As funções permitem consultar informações detalhadas
 *            dos passageiros e tripulantes, como nome, telefone, cargo, cidade, e histórico de voos.
 *            Também verifica a existência dos registros e fornece dados adicionais, como pontos de fidelidade para passageiros.
 *
 * Funcionalidades:
 * - Pesquisar passageiros por nome ou ID.
 * - Pesquisar tripulantes por nome ou ID.
 * - Exibir detalhes sobre passageiros e tripulantes, incluindo informações de voo e fidelidade.
 *
 *
 * Objetivo: Facilitar a consulta e gerenciamento de informações de passageiros e tripulantes em um sistema de reservas.
 *
 * Data de Criação: 25/11/2024
 * Última Atualização: 28/11/2024
 * ============================================================
 */

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


    if(tripulantes[j].getCodigoTripulante()==codTripulante){
        verificaExistenciaTripulante = true;
    }

    if(verificaExistenciaTripulante==true && tripulantes[j].getCodigoTripulante()==codTripulante){
            cout << "ID "<<tripulantes[j].getCodigoTripulante() << endl;
            cout << "Nome:"<<tripulantes[j].getNome() << endl;
            cout << "Telefone: "<<tripulantes[j].getTelefone() << endl;
            cout << "Cargo: "<< tripulantes[j].getCargo() << endl;

    }

}


    cout<<"\n";
}
}

void pesquisarNomeTripulante(){
     system("cls");
     string nomeTripulante;


    cout<<"Pesquisa nome tripulante\n";
       cout << "Informe o nome do Tripulannte:" << endl;
       getline(cin, nomeTripulante);
        for (int i = 0; i < tripulacaoVet.size(); i++) {
    vector<Tripulacao>& tripulantes = tripulacaoVet[i].getTripulantes();  // Acessa a tripulação específica

    for (int j = 0; j < tripulantes.size(); j++) {


    if(tripulantes[j].getNome()==nomeTripulante){
            cout << "ID "<<tripulantes[j].getCodigoTripulante() << endl;
            cout << "Nome:"<<tripulantes[j].getNome() << endl;
            cout << "Telefone: "<<tripulantes[j].getTelefone() << endl;
            cout << "Cargo: "<< tripulantes[j].getCargo() << endl;

    }


}
    cout<<"\n";
}
}


void pesquisarIdPassageiro(){
     system("cls");
    cout<<"Pesquisa id passageiro\n";
    bool verificaExistenciaPassageiro = false;
    int codPassageiro;
    int contadorVoos=0;

      cout << "Informe o código do Passageiro:" << endl;
      cin >> codPassageiro;

      for (size_t i = 0; i < passageiros.size(); i++)
      {
        if(passageiros[i].getID()==codPassageiro){
            verificaExistenciaPassageiro = true;

            cout<<"Informações do passageiro "<<passageiros[i].getID()<<endl;
            cout<<"Nome: "<<passageiros[i].getNome()<<endl;
            cout << "Cidade: " << passageiros[i].getCidade() << endl;
            cout << "Número residencial: " << passageiros[i].getNumResidencia() << endl;
            cout << "Rua: " << passageiros[i].getRua() << endl;
            cout << "Telefone: " << passageiros[i].getTelefone() << endl;
            cout << "Fidelidade: " << (passageiros[i].getFidelidade() ? "Sim" : "Não") << endl;
            cout << "Pontos de fidelidade: " << passageiros[i].getPontuacao() << endl;


            for (size_t j = 0; j < reservas.size(); j++)
            {
                if(reservas[j].getCodPassageiroReserva()==codPassageiro){
                    contadorVoos++;
                }
            }


            if(contadorVoos!=0){
                cout<<"O Passageiro "<<codPassageiro<<" tem "<< contadorVoos<<" voos."<<endl;
            }else{
                cout<<"O passageiro não possui voos."<<endl;
            }
        }

      }

      if(verificaExistenciaPassageiro==false){
        cout<<"Passageiro inexistente!";
      }



    cout<<"\n";
}


void pesquisarNomePassageiro(){
     system("cls");
     string NomePassageiro;
     int contadorVoos=0;
     bool verificaExistenciaPassageiro = false;

    cout<<"Pesquisa nome passageiro\n";
    cout << "Informe o nome do Passageiro:" << endl;
     getline(cin, NomePassageiro);

      for (size_t i = 0; i < passageiros.size(); i++)
      {
        if(passageiros[i].getNome()==NomePassageiro){
            verificaExistenciaPassageiro = true;

            cout<<"Informações do passageiro "<<passageiros[i].getID()<<endl;
            cout<<"Nome: "<<passageiros[i].getNome()<<endl;
            cout << "Cidade: " << passageiros[i].getCidade() << endl;
            cout << "Número residencial: " << passageiros[i].getNumResidencia() << endl;
            cout << "Rua: " << passageiros[i].getRua() << endl;
            cout << "Telefone: " << passageiros[i].getTelefone() << endl;
            cout << "Fidelidade: " << (passageiros[i].getFidelidade() ? "Sim" : "Não") << endl;
            cout << "Pontos de fidelidade: " << passageiros[i].getPontuacao() << endl;


            for (size_t j = 0; j < reservas.size(); j++)
            {
                if(reservas[j].getCodPassageiroReserva()==passageiros[i].getID()){
                    contadorVoos++;
                }
            }


            if(contadorVoos!=0){
                cout<<"O Passageiro "<<NomePassageiro<<" tem "<< contadorVoos<<" voos."<<endl;
            }else{
                cout<<"O passageiro não possui voos."<<endl;
            }
        }

      }

      if(verificaExistenciaPassageiro==false){
        cout<<"Passageiro inexistente!";
      }

    cout<<"\n";

}

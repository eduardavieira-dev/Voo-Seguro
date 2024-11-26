#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Tripulacao.h"

using namespace std;

vector<Tripulacao>tripulacao;
void menuTripulacao();
int contagemTripulacao = 0;


string Tripulacao::getNome(){
    return nome;
}

int Tripulacao::getTelefone(){
    return telefone;
}

int Tripulacao::getCargo(){
    return cargo;
}

int Tripulacao::getCodigoTripulante(){
    return codigoTripulante;
}

int Tripulacao::getCodigoTripulacao(){
    return codigoTripulacao;
}


void  Tripulacao::setNome(string nome){
    this->nome = nome;
}

void  Tripulacao::setTelefone(int telefone){
    this->telefone = telefone;
}

void  Tripulacao::setCargo(int cargo){
    this->cargo = cargo;
}

void  Tripulacao::setCodigoTripulante(int codigoTripulante){
    this->codigoTripulante = codigoTripulante;
}

void  Tripulacao::setCodigoTripulacao(int codigoTripulacao){
    this->codigoTripulacao = codigoTripulacao;
}


void Tripulacao::cadastrarTripulacao(){
    system("cls");
    Tripulacao tripulacao;

    string nome;
    int telefone, codigoTripulante, codigoTripulacao, cargo;

    cout << "Informe o nome do tripulante:" << endl;
    getline(cin, nome);
    tripulacao.setNome(nome);

    cout << "Informe o telefone do tripulante:" << endl;
    cin >> telefone;
    cin.ignore();
    tripulacao.setTelefone(telefone);

    cout << "Informe o cargo tripulante:" << endl;
    cout << "1- Piloto" << endl;
    cout << "2- Copiloto" << endl;
    cout << "3- Comissário" << endl;
    cin >> cargo;
    cin.ignore();
    tripulacao.setCargo(cargo);

}

void Tripulacao::listarTripulacao(){

}

void menuTripulacao(){
    Tripulacao tripulacao;
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int opcao;
    cout << "Menu de Cadastro de Tripulação" << endl;
    cout << "1 - Cadastrar tripulação" << endl;
    cout << "2 - Listar tripulação" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch(opcao){
        case 1:
            tripulacao.cadastrarTripulacao();
            break;

        case 2:
            tripulacao.listarTripulacao();
            system("cls");
            break;

        case 3:
            break;

        default:
            menuTripulacao();
            break;
    }

}

int main(){

    menuTripulacao();

}
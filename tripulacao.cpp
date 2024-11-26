#include <iostream>
#include <string>
#include <vector>
#include "Tripulacao.h"

using namespace std;

vector<Tripulacao>tripulacaoVet;
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
    system("chcp 65001");
    system("cls");
    Tripulacao tripulacao;

    string nome;
    int telefone, codigoTripulante, cargo;

    for(int i =0; i < 3; i++){
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
    codigoTripulante++;
    tripulacao.setCodigoTripulante(codigoTripulante);

    tripulacao.tripulantes.push_back(tripulacao);
    }

    contagemTripulacao++;
    tripulacao.setCodigoTripulacao(contagemTripulacao);

    tripulacaoVet.push_back(tripulacao);

    
    
    menuTripulacao();
}

void Tripulacao::listarTripulacao(){

    if(contagemTripulacao == 0){
        cout << "Nenhuma tripulação cadastrada." << endl;
    }else{

    
    for(int i = 0; i< contagemTripulacao; i++){
        cout << "Tripulação: " << tripulacaoVet[i].getCodigoTripulacao() << endl;
        
        for(int j =0; j<3; j++ ){
            
            cout << "Nome: " << tripulacaoVet[i].tripulantes[j].getNome() << endl;
            cout << "Telefone: " << tripulacaoVet[i].tripulantes[j].getTelefone() << endl;
            cout << "Cargo: " << tripulacaoVet[i].tripulantes[j].getCargo() << endl;
            cout << "Código do tripulante: " << tripulacaoVet[i].tripulantes[j].getCodigoTripulante() << endl;
        }
        }
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    menuTripulacao();
}

void menuTripulacao(){
    
    Tripulacao tripulacao;
    system("cls");

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
            break;

        case 3:
            break;

        default:
            menuTripulacao();
            break;
    }

}

 int main(){
    system("chcp 65001");
    menuTripulacao();

} 
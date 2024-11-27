#include <iostream>
#include <vector>
#include <fstream>
#include "Assento.h"
#include "Voo.h"

using namespace std;

extern vector<Voo> voos;

vector<Assento> assentos;

Assento::Assento()
{
    codVoo = 0;
    numAssento = 0;
    status = false;
}

Assento::Assento(int codVoo, int numAssento)
{
    this->codVoo = codVoo;
    this->numAssento = numAssento;
    this->status = false;
}

void Assento::setCodVoo(int codVoo)
{
    this->codVoo = codVoo;
}

void Assento::setNumAssento(int numAssento)
{
    this->numAssento = numAssento;
}

void Assento::setStatusAssento(bool status)
{
    this->status = status;
}

int Assento::getCodVoo()
{
    return codVoo;
}

int Assento::getNumAssento()
{
    return numAssento;
}

bool Assento::getStatusAssento()
{
    return status;
}

void Assento:: salvarAssento(){
    ofstream arquivo("assentos.dat", ios::app | ios::binary);

    if (arquivo.is_open()) {
        // Salva apenas os dados do objeto atual (this)
        arquivo.write(reinterpret_cast<char*>(&numAssento), sizeof(numAssento));
        arquivo.write(reinterpret_cast<char*>(&codVoo), sizeof(codVoo));
        arquivo.write(reinterpret_cast<char*>(&status), sizeof(status));
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para salvar os assentos." << endl;
    }
}

void Assento:: carregarAssentos(){
    ifstream arquivo("assentos.dat", ios::binary);

    if (arquivo.is_open()) {
        assentos.clear(); // Limpa o vetor

        int numAssentoTemp;
        int codVooTemp;
        bool statusTemp;

        while (arquivo.read(reinterpret_cast<char*>(&numAssentoTemp), sizeof(numAssentoTemp))) {
            arquivo.read(reinterpret_cast<char*>(&codVooTemp), sizeof(codVooTemp));
            arquivo.read(reinterpret_cast<char*>(&statusTemp), sizeof(statusTemp));

            Assento novoAssento(codVooTemp, numAssentoTemp);

            assentos.push_back(novoAssento);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para carregar os assentos." << endl;
    }
}

void Assento::cadastroAssento()
{
    system("cls");
    
    int codVoo, numAssento;
    bool verificaExistenciaVoo = false;

    cout << "Digite o código do voo: \n";
    cin >> codVoo;
    cin.ignore();

    cout << "Digite o número do assento: \n";
    cin >> numAssento;
    cin.ignore();

    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigoVoo() == codVoo)
        {
            Assento NovoAssento(codVoo, numAssento);
            cout << "Assento cadastrado com sucesso: \n";
            cout << "Número do assento: " << NovoAssento.getNumAssento() << "\n";
            cout << "Código do Voo: " << NovoAssento.getCodVoo() << "\n";
            cout << "Status: " << (NovoAssento.getStatusAssento() ? "Ocupado" : "Livre") << "\n";
            assentos.push_back(NovoAssento);  // Adiciona ao vetor
            NovoAssento.salvarAssento(); // Salva apenas o novo assento
            verificaExistenciaVoo = true;
        }
    }

    if (verificaExistenciaVoo == false)
    {
        cout << "O voo informado não existe. Escolha outro voo ou faça o cadastro de um novo antes." << endl;
    }
}

void Assento::ExibirAssentos(){
    system("cls");   
    if(assentos.size() == 0){
        cout << "Nenhum assento cadastrado." << endl;
    }else{
        for (size_t i = 0; i < assentos.size(); i++) {
            cout << "\nInformações do assento " << i + 1 << ":" << endl;
            cout << "Número: " << assentos[i].getNumAssento() << endl;
            cout << "Código do voo: " << assentos[i].getCodVoo() << endl;
            cout << "Status: " << (assentos[i].getStatusAssento() ? "Ocupado" : "Livre") << endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
}
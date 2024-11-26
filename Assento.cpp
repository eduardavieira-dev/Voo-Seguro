#include <iostream>
#include <vector>
#include <fstream>
#include "Assento.h"
#include "Voo.cpp"

using namespace std;

int Assento::contadorNumAssento = 0;
vector<Assento> assentos;

Assento::Assento()
{
    codVoo = 0;
    numAssento = 0;
    status = false;
}

Assento::Assento(int codVoo)
{
    this->codVoo = codVoo;
    this->numAssento = ++contadorNumAssento;
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

void Assento::setStatusAssento()
{
    status = !status;
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
        contadorNumAssento = 0; // Reinicia o contador de assentos

        int numAssentoTemp;
        int codVooTemp;
        bool statusTemp;

        while (arquivo.read(reinterpret_cast<char*>(&numAssentoTemp), sizeof(numAssentoTemp))) {
            arquivo.read(reinterpret_cast<char*>(&codVooTemp), sizeof(codVooTemp));
            arquivo.read(reinterpret_cast<char*>(&statusTemp), sizeof(statusTemp));

            Assento novoAssento(codVooTemp);
            novoAssento.setNumAssento(numAssentoTemp);
            novoAssento.setStatusAssento();
            if (statusTemp) novoAssento.setStatusAssento(); // Define o status correto

            assentos.push_back(novoAssento);

            if (numAssento > contadorNumAssento) {
                contadorNumAssento = numAssento;
            }
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para carregar os passageiros." << endl;
    }
}

void Assento::cadastroAssento()
{
    system("cls");
    int codVoo;
    bool verificaExistenciaVoo = false;

    cout << "Digite o código do voo: \n";
    cin >> codVoo;
    cin.ignore();

    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigoVoo() == codVoo)
        {
            Assento NovoAssento(codVoo);
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

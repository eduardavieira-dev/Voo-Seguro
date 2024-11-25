#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Passageiro.h"
#include <fstream>

using namespace std;

int Passageiro:: contadorID = 0;
vector<Passageiro>passageiros;

// CONSTRUTOR------------------------------------------------------------------------------------------------
Passageiro::Passageiro(){
    this->id = 0;
    this->nome = ' ';
    this->numResidencia = 0;
    this->cidade = ' ';
    this->telefone = ' ';
    this->rua = ' ';
    this->fidelidade = false;
    this->pontuacao = 0;
}

Passageiro::Passageiro(string nome, string telefone, int numResidencia, string cidade, string rua)
{
    this->id = ++contadorID; // Atribui o ID atual e incrementa para o próximo
    this->nome = nome;
    this->numResidencia = numResidencia;
    this->cidade = cidade;
    this->telefone = telefone;
    this->rua = rua;
    this->fidelidade = false;
    this->pontuacao = 0;
};

// Gets e Sets_______________________________________________________________________________________________
void Passageiro::setNome(string nome)
{
    this->nome = nome;
};

void Passageiro::setPontuacao()
{
    if (fidelidade == false)
    {
        fidelidade = true;
    }
    pontuacao += 10;
};

void Passageiro:: setTelefone(string telefone){
    this->telefone = telefone;
}

int Passageiro::getID(){
    return id;
}

string Passageiro::getNome()
{
    return nome;
};

bool Passageiro::getFidelidade()
{
    return fidelidade;
};

int Passageiro::getPontuacao()
{
    return pontuacao;
};

string Passageiro:: getTelefone(){
    return telefone;
}

void Passageiro::setNumResidencia(int numResidencia)
{
    this->numResidencia = numResidencia;
};

void Passageiro::setCidade(string cidade)
{
    this->cidade = cidade;
};

void Passageiro::setRua(string rua)
{
    this->rua = rua;
};

int Passageiro::getNumResidencia()
{
    return numResidencia;
};

string Passageiro::getCidade()
{
    return cidade;
};

string Passageiro::getRua()
{
    return rua;
};

// Gets e Sets_______________________________________________________________________________________________

// Função para cadastro______________________________________________________________________________________

void cadastroPassageiro() {
    system("cls");
    string nome, cidade, rua, telefone;
    int numResidencia;

    cout << "Digite o nome do passageiro:\n";
    getline(cin, nome);

    cout << "Digite a cidade onde o passageiro mora:\n";
    getline(cin, cidade);

    cout << "Digite o número residencial:\n";
    cin >> numResidencia;
    cin.ignore();

    cout << "Digite o nome da rua:\n";
    getline(cin, rua);

    cout << "Digite o número de telefone (DDD) XXXXX-XXXX:\n";
    getline(cin, telefone);

    // Criação do novo passageiro
    Passageiro NovoPassageiro(nome, telefone, numResidencia, cidade, rua);

    cout << "Dados informados para o cadastro:\n";
    cout << "Nome: " << NovoPassageiro.getNome() << "\n";
    cout << "Cidade: " << NovoPassageiro.getCidade() << "\n";
    cout << "Número Residencial: " << NovoPassageiro.getNumResidencia() << "\n";
    cout << "Rua: " << NovoPassageiro.getRua() << "\n";
    cout << "Telefone: " << NovoPassageiro.getTelefone() << "\n";

    passageiros.push_back(NovoPassageiro); // Adiciona ao vetor
    NovoPassageiro.salvarDadosPassageiro(); // Salva apenas o novo passageiro
}

void listarPassageiros()
{
    system("cls");
    if(passageiros.size() == 0){
        cout << "Nenhum passageiro cadastrado." << endl;
    }else{
        for (size_t i = 0; i < passageiros.size(); i++) {
            cout << "\nInformações do Passageiro " << i + 1 << ":" << endl;
            cout << "ID: " << passageiros[i].getID() << endl;
            cout << "Nome: " << passageiros[i].getNome() << endl;
            cout << "Cidade: " << passageiros[i].getCidade() << endl;
            cout << "Número residencial: " << passageiros[i].getNumResidencia() << endl;
            cout << "Rua: " << passageiros[i].getRua() << endl;
            cout << "Telefone: " << passageiros[i].getTelefone() << endl;
            cout << "Fidelidade: " << (passageiros[i].getFidelidade() ? "Sim" : "Não") << endl;
            cout << "Pontos de fidelidade: " << passageiros[i].getPontuacao() << endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
}

// Métodos da classe para salvar os dados no arquivo e ler -____________________________________________________
void Passageiro::salvarDadosPassageiro() {
    ofstream arquivo("passageiros.dat", ios::app | ios::binary);

    if (arquivo.is_open()) {
        // Salva apenas os dados do objeto atual (this)
        arquivo.write(reinterpret_cast<char*>(&id), sizeof(id));
        arquivo.write(nome.c_str(), nome.size() + 1);
        arquivo.write(telefone.c_str(), telefone.size() + 1);
        arquivo.write(cidade.c_str(), cidade.size() + 1);
        arquivo.write(rua.c_str(), rua.size() + 1);
        arquivo.write(reinterpret_cast<char*>(&numResidencia), sizeof(numResidencia));
        arquivo.write(reinterpret_cast<char*>(&fidelidade), sizeof(fidelidade));
        arquivo.write(reinterpret_cast<char*>(&pontuacao), sizeof(pontuacao));

        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para salvar os passageiros." << endl;
    }
}

void Passageiro::carregarPassageiros() {
    ifstream arquivo("passageiros.dat", ios::binary);

    if (arquivo.is_open()) {
        passageiros.clear(); // Limpa o vetor
        contadorID = 0; // Reinicia o contador de ID

        while (arquivo.read(reinterpret_cast<char*>(&id), sizeof(id))) {
            getline(arquivo, nome, '\0');
            getline(arquivo, telefone, '\0');
            getline(arquivo, cidade, '\0');
            getline(arquivo, rua, '\0');
            arquivo.read(reinterpret_cast<char*>(&numResidencia), sizeof(numResidencia));
            arquivo.read(reinterpret_cast<char*>(&fidelidade), sizeof(fidelidade));
            arquivo.read(reinterpret_cast<char*>(&pontuacao), sizeof(pontuacao));

            Passageiro novoPassageiro(nome, telefone, numResidencia, cidade, rua);
            novoPassageiro.id = id;
            novoPassageiro.pontuacao = pontuacao;
            novoPassageiro.fidelidade = fidelidade;

            passageiros.push_back(novoPassageiro);

            if (id > contadorID) {
                contadorID = id;
            }
        }

        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para carregar os passageiros." << endl;
    }
}


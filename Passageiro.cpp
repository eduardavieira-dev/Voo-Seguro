/********************************************************
 * FILENAME : Passageiro.cpp
 * DESCRIPTION : Implementação de cadastro, salvamento,
 *               carregamento e listagem de passageiros.
 * PUBLIC FUNCTIONS :
 *   void Passageiro::cadastroPassageiro()    - Realiza o cadastro de um novo passageiro.
 *   void Passageiro::listarPassageiros()     - Lista todos os passageiros cadastrados.
 *   void Passageiro::salvarDadosPassageiro() - Salva os dados de um passageiro em arquivo binário.
 *   void Passageiro::carregarPassageiros()   - Carrega os dados dos passageiros a partir de um arquivo binário.
 *
 * NOTES :
 * Essas funções fazem parte de um sistema de cadastro e listagem de passageiros.
 * O código realiza o armazenamento e a leitura de informações dos passageiros
 * em um arquivo binário, além de realizar o cadastro e a listagem de passageiros.
 *
 * AUTHOR : Laura
 * START DATE : 22 Nov 24
 ********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Passageiro.h"
#include <fstream>

using namespace std;

int Passageiro::contadorID = 0;
vector<Passageiro> passageiros;

// CONSTRUTOR------------------------------------------------------------------------------------------------
Passageiro::Passageiro()
{
    id = 0;
    nome = ' ';
    numResidencia = 0;
    cidade = ' ';
    telefone = ' ';
    rua = ' ';
    fidelidade = false;
    pontuacao = 0;
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

void Passageiro::setPontuacao(int pontuacao)
{
    this->pontuacao += pontuacao;
};

void Passageiro::setFidelidade(bool fidelidade)
{
    this->fidelidade = fidelidade;
}

void Passageiro::setTelefone(string telefone)
{
    this->telefone = telefone;
}

int Passageiro::getID()
{
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

string Passageiro::getTelefone()
{
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

/********************************************************
 * NAME : void Passageiro::cadastroPassageiro()
 * DESCRIPTION : Realiza o cadastro de um novo passageiro.
 * INPUTS :
 * PARAMETERS : Nenhum
 * RETURN :
 * Type : void
 * Error code :
 * Values : Nenhum
 *******************************************************/
void Passageiro::cadastroPassageiro()
{
    system("chcp 65001 > nul");
    system("cls");
    string nome, cidade, rua, telefone;
    int numResidencia;

    cout << "Digite o nome do passageiro:" << endl;
    getline(cin, nome);

    if (passageiros.size() > 0)
    {
        for (size_t i = 0; i < passageiros.size(); i++)
        {
            while (passageiros[i].getNome() == nome)
            {
                cout << "Este nome já está sendo utilizado em outro cadastro. Complemente com um sobrenome." << endl;
                cout << "Digite novamente o nome do passageiro:" << endl;
                getline(cin, nome);
                i = 0;
            }
        }
    }

    cout << "Digite a cidade onde o passageiro mora:" << endl;
    getline(cin, cidade);

    cout << "Digite o número residencial:" << endl;
    while (!(cin >> numResidencia))
    {
        cout << "Entrada inválida, insira um número." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    cout << "Digite o nome da rua:" << endl;
    getline(cin, rua);

    cout << "Digite o número de telefone (DDD) XXXXX-XXXX:" << endl;
    getline(cin, telefone);

    // Criação do novo passageiro
    Passageiro NovoPassageiro(nome, telefone, numResidencia, cidade, rua);
    cout << "+---------------------------------+" << endl;
    cout << "| Dados informados para o cadastro:" << endl;
    cout << "| Nome: " << NovoPassageiro.getNome() << endl;
    cout << "| Cidade: " << NovoPassageiro.getCidade() << endl;
    cout << "| Número Residencial: " << NovoPassageiro.getNumResidencia() << endl;
    cout << "| Rua: " << NovoPassageiro.getRua() << endl;
    cout << "| Telefone: " << NovoPassageiro.getTelefone() << endl;
    cout << "+---------------------------------+" << endl;
    passageiros.push_back(NovoPassageiro);
    NovoPassageiro.salvarDadosPassageiro();
    cout << "Pressione 'ENTER' para voltar" << endl;

    cin.get();
    system("cls");
}

/********************************************************
 * NAME : void Passageiro::listarPassageiros()
 * DESCRIPTION : Lista todos os passageiros cadastrados.
 * INPUTS :
 * PARAMETERS : Nenhum
 * RETURN :
 * Type : void
 * Error code :
 * Values : Nenhum
 *******************************************************/
void Passageiro::listarPassageiros()
{
    system("cls");
    if (passageiros.size() == 0)
    {
        cout << "Nenhum passageiro cadastrado." << endl;
    }
    else
    {
        for (size_t i = 0; i < passageiros.size(); i++)
        {

            cout << endl;
            cout << "    Informações do Passageiro " << i + 1 << ":" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| ID: " << passageiros[i].getID() << endl;
            cout << "| Nome: " << passageiros[i].getNome() << endl;
            cout << "| Cidade: " << passageiros[i].getCidade() << endl;
            cout << "| Número residencial: " << passageiros[i].getNumResidencia() << endl;
            cout << "| Rua: " << passageiros[i].getRua() << endl;
            cout << "| Telefone: " << passageiros[i].getTelefone() << endl;
            cout << "| Fidelidade: " << (passageiros[i].getFidelidade() ? "Sim" : "Não") << endl;
            cout << "| Pontos de fidelidade: " << passageiros[i].getPontuacao() << endl;
            cout << "+---------------------------------+" << endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

// Métodos da classe para salvar os dados no arquivo e ler -____________________________________________________
/********************************************************
 * NAME : void Passageiro::salvarPassageiros()
 * DESCRIPTION : Salva os passageiros cadastrados em um arquivo binário.
 * INPUTS :
 * PARAMETERS : Nenhum
 * RETURN :
 * Type : void
 * Error code :
 * Values : Nenhum
 *******************************************************/
void Passageiro::salvarDadosPassageiro()
{
    ofstream arquivo("passageiros.dat", ios::app | ios::binary);

    if (arquivo.is_open())
    {
        // Salva apenas os dados do objeto atual (this)
        arquivo.write(reinterpret_cast<char *>(&id), sizeof(id));
        arquivo.write(nome.c_str(), nome.size() + 1);
        arquivo.write(telefone.c_str(), telefone.size() + 1);
        arquivo.write(cidade.c_str(), cidade.size() + 1);
        arquivo.write(rua.c_str(), rua.size() + 1);
        arquivo.write(reinterpret_cast<char *>(&numResidencia), sizeof(numResidencia));
        arquivo.write(reinterpret_cast<char *>(&fidelidade), sizeof(fidelidade));
        arquivo.write(reinterpret_cast<char *>(&pontuacao), sizeof(pontuacao));

        arquivo.close();
    }
}

/********************************************************
 * NAME : void Passageiro::carregarPassageiros()
 * DESCRIPTION : Carrega os passageiros a partir de um arquivo binário.
 * INPUTS :
 * PARAMETERS : Nenhum
 * RETURN :
 * Type : void
 * Error code :
 * Values : Nenhum
 *******************************************************/
void Passageiro::carregarPassageiros()
{
    ifstream arquivo("passageiros.dat", ios::binary);

    if (arquivo.is_open())
    {
        passageiros.clear(); // Limpa o vetor
        contadorID = 0;      // Reinicia o contador de ID

        while (arquivo.read(reinterpret_cast<char *>(&id), sizeof(id)))
        {
            getline(arquivo, nome, '\0');
            getline(arquivo, telefone, '\0');
            getline(arquivo, cidade, '\0');
            getline(arquivo, rua, '\0');
            arquivo.read(reinterpret_cast<char *>(&numResidencia), sizeof(numResidencia));
            arquivo.read(reinterpret_cast<char *>(&fidelidade), sizeof(fidelidade));
            arquivo.read(reinterpret_cast<char *>(&pontuacao), sizeof(pontuacao));

            Passageiro novoPassageiro(nome, telefone, numResidencia, cidade, rua);
            novoPassageiro.id = id;
            novoPassageiro.pontuacao = pontuacao;
            novoPassageiro.fidelidade = fidelidade;

            passageiros.push_back(novoPassageiro);

            if (id > contadorID)
            {
                contadorID = id;
            }
        }

        arquivo.close();
    }
}

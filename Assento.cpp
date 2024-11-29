/********************************************************
 * FILENAME : Assento.cpp
 * DESCRIPTION : Implementação de cadastro, exibição e
 *               gerenciamento de assentos de voos. A classe
 *               permite registrar novos assentos, exibir as
 *               informações dos assentos cadastrados e
 *               gerenciar o status de ocupação (livre/ocupado).
 * PUBLIC FUNCTIONS :
 *
 *   void salvarAssento()                    - Salva os dados do assento em um arquivo binário.
 *   void carregarAssentos()                 - Carrega os dados dos assentos de um arquivo binário.
 *   void cadastroAssento()                  - Realiza o cadastro de um novo assento para um voo.
 *   void ExibirAssentos()                   - Exibe todos os assentos cadastrados com seus status.
 *
 * NOTES :
 * Esta classe gerencia os assentos de voos, incluindo a funcionalidade de cadastro,
 * exibição e controle de status (livre ou ocupado). Os dados dos assentos são salvos
 * em um arquivo binário para persistência e podem ser carregados novamente ao iniciar o programa.
 *
 * AUTHOR : Laura
 * START DATE : 22 Nov 24
 ********************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Assento.h"
#include "Voo.h"

using namespace std;

#define MAX_ASSENTOS 100

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

/********************************************************
 * NAME : salvarAssento()
 * DESCRIPTION : Salva os dados do assento em um arquivo binário.
 * INPUTS :
 * PARAMETERS : Nenhum.
 * RETURN :
 * Type : void
 ********************************************************/
void Assento::salvarAssento()
{
    ofstream arquivo("assentos.dat", ios::app | ios::binary);

    if (arquivo.is_open())
    {
        // Salva apenas os dados do objeto atual (this)
        arquivo.write(reinterpret_cast<char *>(&numAssento), sizeof(numAssento));
        arquivo.write(reinterpret_cast<char *>(&codVoo), sizeof(codVoo));
        arquivo.write(reinterpret_cast<char *>(&status), sizeof(status));
        arquivo.close();
    }
}

/********************************************************
 * NAME : carregarAssentos()
 * DESCRIPTION : Carrega os dados dos assentos de um arquivo binário para o vetor de assentos.
 * INPUTS :
 * PARAMETERS : Nenhum.
 * RETURN :
 * Type : void
 ********************************************************/
void Assento::carregarAssentos()
{
    ifstream arquivo("assentos.dat", ios::binary);

    if (arquivo.is_open())
    {
        assentos.clear(); // Limpa o vetor

        int numAssentoTemp;
        int codVooTemp;
        bool statusTemp;

        while (arquivo.read(reinterpret_cast<char *>(&numAssentoTemp), sizeof(numAssentoTemp)))
        {
            arquivo.read(reinterpret_cast<char *>(&codVooTemp), sizeof(codVooTemp));
            arquivo.read(reinterpret_cast<char *>(&statusTemp), sizeof(statusTemp));

            Assento novoAssento(codVooTemp, numAssentoTemp);

            assentos.push_back(novoAssento);
        }
        arquivo.close();
    }
}

/********************************************************
 * NAME : cadastroAssento()
 * DESCRIPTION : Realiza o cadastro de um novo assento para um voo, verificando se o voo existe.
 * INPUTS :
 * PARAMETERS : Nenhum.
 * RETURN :
 * Type : void
 ********************************************************/
void Assento::cadastroAssento()
{
    system("cls");

    int codVoo = 0, numAssento = 0;
    bool verificaExistenciaVoo = false;

    cout << "Digite o código do voo: \n";
    while (!(cin >> codVoo))
    {
        cout << "Entrada inválida, insira um número." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigoVoo() == codVoo)
        {
            verificaExistenciaVoo = true;

            // Conta os assentos já cadastrados para este voo
            int totalAssentos = 0;
            for (size_t j = 0; j < assentos.size(); j++)
            {
                if (assentos[j].getCodVoo() == codVoo)
                {
                    totalAssentos++;
                }
            }

            // Verifica se ainda há espaço para mais assentos
            if (totalAssentos == MAX_ASSENTOS)
            {
                cout << "Erro: O voo já atingiu o limite máximo de 100 assentos cadastrados." << endl;
            }
            else if (totalAssentos < MAX_ASSENTOS)
            {
                // Define o número do próximo assento
                numAssento = totalAssentos + 1;

                // Cria e cadastra o novo assento
                Assento NovoAssento(codVoo, numAssento);
                assentos.push_back(NovoAssento); // Adiciona ao vetor
                NovoAssento.salvarAssento();     // Salva apenas o novo assento

                cout << "Assento cadastrado com sucesso." << endl;
                cout << "+---------------------------------+" << endl;
                cout << "| Número do assento: " << NovoAssento.getNumAssento() << "\n";
                cout << "| Código do Voo: " << NovoAssento.getCodVoo() << "\n";
                cout << "| Status: " << (NovoAssento.getStatusAssento() ? "Ocupado" : "Livre") << "\n";
                cout << "+---------------------------------+" << endl;
            }
        }
    }

    if (verificaExistenciaVoo == false)
    {
        cout << "Erro: o voo informado não existe." << endl;
    }
}

/********************************************************
 * NAME : ExibirAssentos()
 * DESCRIPTION : Exibe as informações de todos os assentos cadastrados, mostrando seu status (livre ou ocupado).
 * INPUTS :
 * PARAMETERS : Nenhum.
 * RETURN :
 * Type : void
 ********************************************************/
void Assento::ExibirAssentos()
{
    system("cls");
    if (assentos.size() == 0)
    {
        cout << "Nenhum assento cadastrado." << endl;
    }
    else
    {
        for (size_t i = 0; i < assentos.size(); i++)
        {
            cout << endl;
            cout << "     Informações do assento " << i + 1 << ":" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| Número: " << assentos[i].getNumAssento() << endl;
            cout << "| Código do voo: " << assentos[i].getCodVoo() << endl;
            cout << "| Status: " << (assentos[i].getStatusAssento() ? "Ocupado" : "Livre") << endl;
            cout << "+---------------------------------+" << endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
}
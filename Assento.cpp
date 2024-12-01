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
 * AUTHOR : Laura Campos Pontara Lopes
 * START DATE : 22 Nov 24
 ********************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <iomanip>
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
 * PARAMETERS :
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
 * PARAMETERS :
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

/********************************************************************************************************
 * NAME : cadastroAssento()
 * DESCRIPTION : Realiza o cadastro de um novo assento para um voo, verificando se o voo existe.
 * INPUTS : int codVoo - Código do voo ao qual o assento será atribuído.
 *          int numAssento - Número do assento que está sendo cadastrado.
 * PARAMETERS :
 * RETURN :
 * Type : void
 * Error: Código de voo invalido: O voo selecionado não existe ou o valor digitado não é um número
 *        Número de assento invalido: O assento selecionado não existe ou o valor digitado não é um número
 *********************************************************************************************************/
void Assento::cadastroAssento()
{
    system("cls");

    int codVoo = 0, numAssento = 0;
    bool verificaExistenciaVoo = false;

    cout << "Digite o código do voo: \n";
    while (!(cin >> codVoo) || codVoo <= 0)
    {
        cin.clear();                                         // Limpa o estado de erro do cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove o restante da entrada inválida do buffer

        if (codVoo && codVoo <= 0)
        {
            cout << "Entrada inválida, insira um número maior que zero." << endl;
        }
        else
        {
            cout << "Entrada inválida, insira um número." << endl;
        }
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
                cin.get();
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
                cin.get();
            }
        }
    }

    if (verificaExistenciaVoo == false)
    {
        cout << "Erro: o voo informado não existe." << endl;
        cin.get();
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

/*****************************************************************************************************************
 * NAME : ExibirAssentos()
 * DESCRIPTION : Exibe as informações de todos os assentos cadastrados, mostrando seu status (livre ou ocupado).
 * INPUTS :
 * PARAMETERS :
 * RETURN :
 * Type : void
 * Values :  Se houver assentos cadastrados, exibe as informações detalhadas
 *           de cada assento: Número, código do voo selecionado e status ('Ocupado', 'Livre')
 *           Caso não possua assentos cadastrados,
 *           exibe uma mensagem informando que não há assentos cadastrados.
 *****************************************************************************************************************/
void Assento::ExibirAssentos()
{
    system("cls");
    if (assentos.size() == 0)
    {
        cout << "Nenhum assento cadastrado." << endl;
    }
    else
    {
        // Encontrar o menor e o maior código de voo no vetor de assentos
        int menorCodigo = 100;
        int maiorCodigo = 0;

        for (size_t i = 0; i < assentos.size(); i++)
        {
            if (assentos[i].getCodVoo() < menorCodigo)
            {
                menorCodigo = assentos[i].getCodVoo();
            }
            if (assentos[i].getCodVoo() > maiorCodigo)
            {
                maiorCodigo = assentos[i].getCodVoo();
            }
        }

        // Exibir os assentos agrupados por voo, de menor para maior código
        for (int codigoAtual = menorCodigo; codigoAtual <= maiorCodigo; codigoAtual++)
        {
            bool vooEncontrado = false;

            // Verifica se há algum assento para o código de voo atual
            for (size_t j = 0; j < assentos.size(); j++)
            {
                if (assentos[j].getCodVoo() == codigoAtual)
                {
                    if (!vooEncontrado)
                    {
                        // Exibe o cabeçalho do voo na primeira vez que encontrar
                        cout << "\n   Voo " << codigoAtual << endl;
                        cout << "+---------------------------------+" << endl;
                        cout << "|  Número do assento |   Status   |" << endl;
                        cout << "+---------------------------------+" << endl;
                        vooEncontrado = true;
                    }

                    // Exibe os detalhes do assento
                    cout << "| " << setw(18) << assentos[j].getNumAssento()
                        << " | " << setw(10)
                        << (assentos[j].getStatusAssento() ? "Ocupado" : "Livre")
                        << " |" << endl;
                }
            }

            if (vooEncontrado)
            {
                cout << "+---------------------------------+" << endl;
            }
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
}
/********************************************************
 * FILENAME : Pesquisa.cpp
 * DESCRIPTION : Pesquisa de passageiros e tripulantes.
 * PUBLIC FUNCTIONS :
 *   void pesquisarPassageiro()
 *   void pesquisarTripulacao()
 *   void pesquisarIdTripulante()
 *   void pesquisarNomeTripulante()
 *   void pesquisarIdPassageiro()
 *   void pesquisarNomePassageiro()
 * NOTES :
 *   As funções permitem realizar pesquisas de passageiros e tripulantes
 *   com base no nome ou ID.
 *   Essas funções acessam e exibem informações de passageiros e tripulantes
 *   armazenadas em vetores.
 * AUTHOR : Eduarda
 * START DATE : 28 Nov 2024
 ********************************************************/

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
/********************************************************
 * NAME : void pesquisarPassageiro()
 * DESCRIPTION : Pesquisa de passageiros por nome ou ID.
 * INPUTS :
 * PARAMETERS :
 * Nenhum.
 * RETURN :
 * Type : void
 * Error code :
 ********************************************************/
void pesquisarPassageiro()
{
    system("chcp 65001 > nul");
    system("cls");
    int opcao, codPassageiro;
    // string nomePassageiro;
    cout << "         Pesquisa de passageiro        " << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "| 1 - Pesquisar passageiros por nome  |" << endl;
    cout << "| 2 - Pesquisar passageiros por ID    |" << endl;
    cout << "| 3 - Voltar                          |" << endl;
    cout << "+-------------------------------------+" << endl;
    cin >> opcao;

    cin.ignore();
    switch (opcao)
    {
    case 1:
        pesquisarNomePassageiro();

        break;
    case 2:
        pesquisarIdPassageiro();

        break;
    case 3:
        return;
        break;
    default:
        cout << "Opção inválida! Tente novamente." << endl;
        break;
    }
}
// Implementação do método de pesquisa de tripulação
/********************************************************
 * NAME : void pesquisarTripulacao()
 * DESCRIPTION : Pesquisa de tripulantes por nome ou código.
 * INPUTS :
 * PARAMETERS :
 * Nenhum.
 * RETURN :
 * Type : void
 * Error code :
 ********************************************************/
void pesquisarTripulacao()
{
    system("chcp 65001 > nul");
    system("cls");
    int opcao, codTripulante;
    // string nomeTripulante;
    cout << "   Pesquisa de membro da tripulação    " << endl;
    cout << "+------------------------------------+" << endl;
    cout << "| 1 - Pesquisar tripulante por nome  |" << endl;
    cout << "| 2 - Pesquisar tripulante por ID    |" << endl;
    cout << "| 3 - Voltar                         |" << endl;
    cout << "+------------------------------------+" << endl;
    cin >> opcao;
    cin.ignore();
    switch (opcao)
    {
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

/********************************************************
 * NAME : void pesquisarIdTripulante()
 * DESCRIPTION : Pesquisa um tripulante através de seu ID.
 * INPUTS :
 * PARAMETERS :
 * Nenhum.
 * RETURN :
 * Type : void
 * Error code :
 ********************************************************/
void pesquisarIdTripulante()
{
    system("cls");
    int codTripulante;
    bool verificaExistenciaTripulante = false;

    cout << "Pesquisa id tripulante" << endl;
    cout << "Informe o código do Tripulante:" << endl;
    cin >> codTripulante;
    cin.ignore();
    system("cls");

    for (int i = 0; i < tripulacaoVet.size(); i++)
    {
        vector<Tripulacao> &tripulantes = tripulacaoVet[i].getTripulantes(); // Acessa a tripulação específica

        for (int j = 0; j < tripulantes.size(); j++)
        {

            if (tripulantes[j].getCodigoTripulante() == codTripulante)
            {
                verificaExistenciaTripulante = true;
            }

            if (verificaExistenciaTripulante == true && tripulantes[j].getCodigoTripulante() == codTripulante)
            {
                cout << "     Informações do tripulante     " << endl;
                cout << "+---------------------------------+" << endl;
                cout << "| ID " << tripulantes[j].getCodigoTripulante() << endl;
                cout << "| Nome:" << tripulantes[j].getNome() << endl;
                cout << "| Telefone: " << tripulantes[j].getTelefone() << endl;
                cout << "| Cargo: " << tripulantes[j].getCargo() << endl;
                cout << "+---------------------------------+" << endl;
            }
        }
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

/********************************************************
 * NAME : void pesquisarNomeTripulante()
 * DESCRIPTION : Pesquisa um tripulante através de seu nome.
 * INPUTS :
 * PARAMETERS :
 * Nenhum.
 * RETURN :
 * Type : void
 * Error code :
 ********************************************************/
void pesquisarNomeTripulante()
{
    system("cls");
    string nomeTripulante;

    cout << "Pesquisa nome tripulante" << endl;
    cout << "Informe o nome do Tripulante:" << endl;
    getline(cin, nomeTripulante);
    system("cls");
    for (int i = 0; i < tripulacaoVet.size(); i++)
    {
        vector<Tripulacao> &tripulantes = tripulacaoVet[i].getTripulantes(); // Acessa a tripulação específica

        for (int j = 0; j < tripulantes.size(); j++)
        {

            if (tripulantes[j].getNome() == nomeTripulante)
            {
                cout << "     Informações do tripulante     " << endl;
                cout << "+---------------------------------+" << endl;
                cout << "| ID " << tripulantes[j].getCodigoTripulante() << endl;
                cout << "| Nome:" << tripulantes[j].getNome() << endl;
                cout << "| Telefone: " << tripulantes[j].getTelefone() << endl;
                cout << "| Cargo: " << tripulantes[j].getCargo() << endl;
                cout << "+---------------------------------+" << endl;
            }
        }
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

/********************************************************
 * NAME : void pesquisarIdPassageiro()
 * DESCRIPTION : Pesquisa um passageiro através de seu ID.
 * INPUTS :
 * PARAMETERS :
 * Nenhum.
 * RETURN :
 * Type : void
 * Error code :
 ********************************************************/
void pesquisarIdPassageiro()
{
    system("cls");
    cout << "Pesquisa id passageiro" << endl;
    bool verificaExistenciaPassageiro = false;
    int codPassageiro;
    int contadorVoos = 0;

    cout << "Informe o código do Passageiro:" << endl;
    cin >> codPassageiro;
    cin.ignore();
    system("cls");
    for (size_t i = 0; i < passageiros.size(); i++)
    {
        if (passageiros[i].getID() == codPassageiro)
        {
            verificaExistenciaPassageiro = true;

            cout << "     Informações do passageiro     " << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| Nome: " << passageiros[i].getNome() << endl;
            cout << "| Cidade: " << passageiros[i].getCidade() << endl;
            cout << "| Número residencial: " << passageiros[i].getNumResidencia() << endl;
            cout << "| Rua: " << passageiros[i].getRua() << endl;
            cout << "| Telefone: " << passageiros[i].getTelefone() << endl;
            cout << "| Fidelidade: " << (passageiros[i].getFidelidade() ? "Sim" : "Não") << endl;
            cout << "| Pontos de fidelidade: " << passageiros[i].getPontuacao() << endl;
            cout << "+---------------------------------+" << endl;

            int contaVoosDiferentes = 1;
            for (size_t j = 0; j < reservas.size(); j++)
            {
                if (reservas[j].getCodPassageiroReserva() == codPassageiro && reservas[j].getcodigVooReserva() == contaVoosDiferentes)
                {
                    contadorVoos++;
                    contaVoosDiferentes++;
                    j = 0;
                }
            }

            if (contadorVoos != 0)
            {
                cout << "\n"
                     << passageiros[i].getNome() << " possue " << contadorVoos << " voos agendados." << endl;
            }
            else
            {
                cout << "\n"
                     << passageiros[i].getNome() << " não possui voos." << endl;
            }
        }
    }
    if (verificaExistenciaPassageiro == false)
    {
        cout << "Passageiro inexistente!" << endl;
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

/********************************************************
 * NAME : void pesquisarNomePassageiro()
 * DESCRIPTION : Pesquisa um passageiro através de seu nome.
 * INPUTS :
 * PARAMETERS :
 * Nenhum.
 * RETURN :
 * Type : void
 * Error code :
 ********************************************************/
void pesquisarNomePassageiro()
{
    system("cls");
    string NomePassageiro;
    int contadorVoos = 0;
    bool verificaExistenciaPassageiro = false;

    cout << "Pesquisa nome passageiro" << endl;
    cout << "Informe o nome do Passageiro:" << endl;
    getline(cin, NomePassageiro);
    system("cls");

    for (size_t i = 0; i < passageiros.size(); i++)
    {
        if (passageiros[i].getNome() == NomePassageiro)
        {
            verificaExistenciaPassageiro = true;

            cout << "     Informações do passageiro     " << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| Nome: " << passageiros[i].getNome() << endl;
            cout << "| Cidade: " << passageiros[i].getCidade() << endl;
            cout << "| Número residencial: " << passageiros[i].getNumResidencia() << endl;
            cout << "| Rua: " << passageiros[i].getRua() << endl;
            cout << "| Telefone: " << passageiros[i].getTelefone() << endl;
            cout << "| Fidelidade: " << (passageiros[i].getFidelidade() ? "Sim" : "Não") << endl;
            cout << "| Pontos de fidelidade: " << passageiros[i].getPontuacao() << endl;
            cout << "+---------------------------------+" << endl;

            int contaVoosDiferentes = 1;
            for (size_t j = 0; j < reservas.size(); j++)
            {
                if (reservas[j].getCodPassageiroReserva() == passageiros[i].getID() && reservas[j].getcodigVooReserva() == contaVoosDiferentes)
                {
                    contadorVoos++;
                    contaVoosDiferentes++;
                    j = 0;
                }
            }

            if (contadorVoos != 0)
            {
                cout << NomePassageiro << " possue " << contadorVoos << " voos agendados." << endl;
            }
            else
            {
                cout << NomePassageiro << " não possui voos." << endl;
            }
        }
    }

    if (verificaExistenciaPassageiro == false)
    {
        cout << "Passageiro inexistente!" << endl;
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

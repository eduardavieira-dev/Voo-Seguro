/********************************************************
 * FILENAME : Pesquisa.cpp
 * DESCRIPTION : Pesquisa de passageiros e tripulantes.
 * PUBLIC FUNCTIONS :
 *   void pesquisarPassageiro()             - Permite selecionar o como deseja pesquisar um passageiro
 *   void pesquisarTripulacao()             - Permite selecionar o como deseja pesquisar um tripulante.
 *   void pesquisarIdTripulante()           - Pesquisa por um tripulante por meio do seu código.
 *   void pesquisarNomeTripulante()         - Pesquisa por um tripulante por meio do seu nome.
 *   void pesquisarIdPassageiro()           - Pesquisa por um passageiro por meio do seu código.
 *   void pesquisarNomePassageiro()         - Pesquisa por um passageiro por meio do seu nome.
 * 
 * NOTES :
 *   As funções permitem realizar pesquisas de passageiros e tripulantes
 *   com base no nome ou ID.
 *   Essas funções acessam e exibem informações de passageiros e tripulantes
 *   armazenadas em vetores.
 * 
 * AUTHOR : Eduarda
 * START DATE : 28 Nov 2024
 ********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
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
 * DESCRIPTION : Menu para selecionar método de pesquisa de passageiro (ID ou Nome);
 * INPUTS :
 * PARAMETERS :
 *
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
 * DESCRIPTION : Menu para selecionar método de pesquisa de tripulante (ID ou Nome);
 * INPUTS :
 * PARAMETERS :
 *
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
 * INPUTS : int codTripulante - Código do tripulante para pesquisa
 * PARAMETERS :
 *
 * RETURN :
 * Type : void
 * Error : Tripulante inexistente: O tripulante selecionado não existe ou o valor informado não é um número.
 ********************************************************/
void pesquisarIdTripulante()
{
    system("cls");
    int codTripulante;
    bool verificaExistenciaTripulante = false;

    cout << "Pesquisa id tripulante" << endl;
    cout << "Informe o código do Tripulante:" << endl;
       while (true)
    {
        if (cin.peek() == '\n') 
        {
            cout << "Entrada inválida, insira um número." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
            continue; // Volta para solicitar a entrada
        }

        if (!(cin >> codTripulante) || codTripulante <= 0) // Valida a entrada
        {
            cout << "Entrada inválida, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o restante da linha
            break; // Sai do loop se a entrada for válida
        }
    }



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
    if (verificaExistenciaTripulante == false)
    {
        cout << "Tripulante inexistente!" << endl;
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

/********************************************************
 * NAME : void pesquisarNomeTripulante()
 * DESCRIPTION : Pesquisa um tripulante através de seu nome.
* INPUTS : string nomeTripulante - Nome do tripulante para pesquisa
 * PARAMETERS :
 *
 * RETURN :
 * Type : void
 * Error : tripulante inexistente: O tripulante selecionado não existe.
 ********************************************************/
void pesquisarNomeTripulante()
{
    system("cls");
    string nomeTripulante;
    bool verificaExistenciaTripulante = false;
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
                verificaExistenciaTripulante = true;
            }

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
    if (verificaExistenciaTripulante == false)
    {
        cout << "Tripulante inexistente!" << endl;
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

/********************************************************
 * NAME : void pesquisarIdPassageiro()
 * DESCRIPTION : Pesquisa um passageiro através de seu ID e mostra suas informações.
 * INPUTS : int codPassageiro - Código do passageiro para pesquisa
 * PARAMETERS :
 *
 * RETURN :
 * Type : void
 * Error : Pasageiro inexistente: O passageiro selecionado não existe ou o valor informado não é um número.
 ********************************************************/
void pesquisarIdPassageiro()
{
    system("cls");
    cout << "Pesquisa id passageiro" << endl;
    bool verificaExistenciaPassageiro = false;
    int codPassageiro;
    int contadorVoos = 0;

    cout << "Informe o código do Passageiro:" << endl;
        while (true)
    {
        if (cin.peek() == '\n') 
        {
            cout << "Entrada inválida, insira um número." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
            continue; // Volta para solicitar a entrada
        }

        if (!(cin >> codPassageiro) || codPassageiro <= 0) // Valida a entrada
        {
            cout << "Entrada inválida, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o restante da linha
            break; // Sai do loop se a entrada for válida
        }
    }
  
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
    // Mensagem caso o passageiro não exista
    if (!verificaExistenciaPassageiro)
    {
        cout << "Passageiro inexistente!" << endl;
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    system("cls");
}

/********************************************************
 * NAME : void pesquisarNomePassageiro()
 * DESCRIPTION : Pesquisa um passageiro através de seu nome e mostra suas informações.
 * INPUTS : string NomePassageiro - Nome do passageiro para pesquisa
 * PARAMETERS :
 *
 * RETURN :
 * Type : void
 * Error : Pasageiro inexistente: O passageiro selecionado não existe.
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

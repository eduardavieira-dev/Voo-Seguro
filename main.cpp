#include <iostream>
#include <cstdlib>
#include <limits>
#include "Voo.h"
#include "Tripulacao.h"
#include "Passageiro.h"
#include "Assento.h"
#include "Reserva.h"
#include "Pesquisa.h"

using namespace std;

// Função para gerar o menu de ações para Baixa de Reservas
void menuBaixa(Reserva &reserva)
{   

    int opcao;
    cout << "    Menu de Baixa de Reservas:    " << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "| 1 - Realizar baixa em reserva     |" << endl;
    cout << "| 2 - Voltar                        |" << endl;
    cout << "+-----------------------------------+" << endl;
    while(!(cin >> opcao)){
    cout << "Entrada inválida, insira um número." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore();

    switch (opcao)
    {
    case 1:
        system("cls");
        reserva.baixaReserva();
        break;

    case 2:
        system("cls");
        break;

    default:
        system("cls");
        cout << "   Opção inválida. Tente novamente!" << endl;
        menuBaixa(reserva);
        break;
    }
}

// Função para gerar o menu de ações para reservas
void menuReserva(Reserva &reserva)
{

    int opcao;
    cout << "    Menu de Cadastro de Reservas:    " << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "| 1 - Cadastrar nova reserva        |" << endl;
    cout << "| 2 - Listar reservas cadastradas   |" << endl;
    cout << "| 3 - Voltar                        |" << endl;
    cout << "+-----------------------------------+" << endl;
    while(!(cin >> opcao)){
    cout << "Entrada inválida, insira um número." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore();

    switch (opcao)
    {
    case 1:
        system("cls");
        reserva.cadastroReserva();
        break;

    case 2:
        system("cls");
        reserva.listaReservas();
        break;

    case 3:
        system("cls");
        break;

    default:
        system("cls");
        cout << "   Opção inválida. Tente novamente!" << endl;
        menuReserva(reserva);
        break;
    }
}

// Função para gerar o menu de ações para assentos
void menuAssento(Assento &assento)
{

    int opcao;
    cout << "    Menu de Cadastro de Assento    " << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| 1 - Cadastrar novo assento      |" << endl;
    cout << "| 2 - Listar assentos cadastrados |" << endl;
    cout << "| 3 - Voltar                      |" << endl;
    cout << "+---------------------------------+" << endl;
    while(!(cin >> opcao)){
    cout << "Entrada inválida, insira um número." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore();

    switch (opcao)
    {
    case 1:
        system("cls");
        assento.cadastroAssento();
        break;

    case 2:
        system("cls");
        assento.ExibirAssentos();
        break;

    case 3:
        system("cls");
        break;

    default:
        system("cls");
        cout << "   Opção inválida. Tente novamente!" << endl;
        menuAssento(assento);
        break;
    }
}

// Função para gerar o menu de ações para passageiros
void menuPassageiro(Passageiro &pass)
{

    int opcao;
    cout << "   Menu de Cadastro de Passageiros:   " << endl;
    cout << "+------------------------------------+" << endl;
    cout << "| 1 - Cadastrar novo passageiro      |" << endl;
    cout << "| 2 - Listar passageiros cadastrados |" << endl;
    cout << "| 3 - Voltar                         |" << endl;
    cout << "+------------------------------------+" << endl;
    while(!(cin >> opcao)){
    cout << "Entrada inválida, insira um número." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore();

    switch (opcao)
    {
    case 1:
        system("cls");
        pass.cadastroPassageiro();
        break;

    case 2:
        system("cls");
        pass.listarPassageiros();
        break;

    case 3:
        system("cls");
        break;

    default:
        system("cls");
        cout << "   Opção inválida. Tente novamente!" << endl;
        menuPassageiro(pass);
        break;
    }
}

void menuTripulacao(Tripulacao &tripulacao)
{

    int opcao;
    cout << "   Menu de Cadastro de Tripulação   " << endl;
    cout << "+----------------------------------+" << endl;
    cout << "| 1 - Cadastrar tripulação         |" << endl;
    cout << "| 2 - Listar tripulação            |" << endl;
    cout << "| 3 - Voltar                       |" << endl;
    cout << "+----------------------------------+" << endl;
    while(!(cin >> opcao)){
    cout << "Entrada inválida, insira um número." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore();

    switch (opcao)
    {
    case 1:
        system("cls");
        tripulacao.cadastrarTripulacao();
        break;

    case 2:
        system("cls");
        tripulacao.listarTripulacao();
        break;

    case 3:
        system("cls");
        break;

    default:
        system("cls");
        cout << "   Opção inválida. Tente novamente!" << endl;
        menuTripulacao(tripulacao);
        break;
    }
}
void menuVoos(Voo &voo)
{

    int opcao;
    cout << "   Menu de Cadastro de Voos   " << endl;
    cout << "+----------------------------+" << endl;
    cout << "| 1 - Cadastrar voo          |" << endl;
    cout << "| 2 - Listar voos            |" << endl;
    cout << "| 3 - Voltar                 |" << endl;
    cout << "+----------------------------+" << endl;
    while(!(cin >> opcao)){
    cout << "Entrada inválida, insira um número." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore();

    switch (opcao)
    {
    case 1:
        voo.cadastroVoo();
        break;

    case 2:
        voo.listarVoo();
        system("cls");
        break;

    case 3:
        system("cls");
        break;

    default:
        system("cls");
        cout << "   Opção inválida. Tente novamente!" << endl;
        menuVoos(voo);
        break;
    }
}
void menuPesquisa()
{
    system("chcp 65001 > nul");

    int opcao;

    cout << "Menu de Pesquisa de passageiros e membros da tripulação" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "| 1 - Pesquisar Passageiros           |" << endl;
    cout << "| 2 - Pesquisar Membro da Tripulação  |" << endl;
    cout << "| 3 - Voltar                          |" << endl;
    cout << "+-------------------------------------+" << endl;
    while(!(cin >> opcao)){
    cout << "Entrada inválida, insira um número." << endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore();
    switch (opcao)
    {
    case 1:
        system("cls");
        pesquisarPassageiro();
        break;
    case 2:
        system("cls");
        pesquisarTripulacao();
        break;
    case 3:
        system("cls");
        return;
    default:
        system("cls");
        cout << "Opção inválida! Tente novamente." << endl;
        menuPesquisa();
        break;
    }
}

int main()
{
    system("chcp 65001 > nul");
    int escolha;
    Voo voo;
    Tripulacao tripulacao;
    Passageiro pass;
    Assento assento;
    Reserva reserva;

    tripulacao.carregarTripulacao();
    assento.carregarAssentos();
    pass.carregarPassageiros();
    voo.carregarVoos();
    reserva.carregarReservas();

    do
    {
        cout << "\n+-------------------------------------+" << endl;
        cout << "|            __                       |" << endl;
        cout << "|            \\ \\ _______________      |" << endl;
        cout << "|     VOO     \\   O O O O O O |_|\\    |" << endl;
        cout << "|    SEGURO   /_______|  |________|>  |" << endl;
        cout << "|                     |  |            |" << endl;
        cout << "|                      \\/             |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|     Escolha o que deseja fazer      |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "| 1 - Cadastrar passageiro            |" << endl;
        cout << "| 2 - Cadastrar tripulação            |" << endl;
        cout << "| 3 - Cadastrar voo                   |" << endl;
        cout << "| 4 - Cadastrar assento               |" << endl;
        cout << "| 5 - Cadastrar reserva               |" << endl;
        cout << "| 6 - Baixa em reservas               |" << endl;
        cout << "| 7 - Pesquisa                        |" << endl;
        cout << "| 0 - Sair                            |" << endl;
        cout << "+-------------------------------------+" << endl;
        while(!(cin >> escolha)){
        cout << "Entrada inválida, insira um número." << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        switch (escolha)
        {
        case 1:
            system("cls");
            menuPassageiro(pass);
            break;

        case 2:
            system("cls");
            menuTripulacao(tripulacao);
            break;

        case 3:
            system("cls");
            menuVoos(voo);
            break;

        case 4:
            system("cls");
            menuAssento(assento);
            break;

        case 5:
            system("cls");
            menuReserva(reserva);
            break;

        case 6:
            system("cls");
            menuBaixa(reserva);
            break;

        case 7:
            system("cls");
            menuPesquisa();
            break;

        case 0:
            system("cls");
            cout << "Programa encerrado" << endl;
            exit(0);
            break;

        default:
            system("cls");
            cout << "Escolha invalida!" << endl;
            break;
        }
    } while (escolha != 0);

    return 0;
}

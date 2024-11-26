#include <iostream>
#include <cstdlib>
#include "Voo.h"
#include "Tripulacao.h"
#include "Passageiro.h"
#include "Assento.h"

using namespace std;

// Função para gerar o menu de ações para assentos
void menuAssento(Assento& assento)
{
    system("cls");

    int opcao;
    cout << "Menu de Cadastro de Assento:" << endl;
    cout << "1 - Cadastrar novo assento" << endl;
    cout << "2 - Listar assentos cadastrados" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch (opcao)
    {
    case 1:
        assento.cadastroAssento();
        break;

    case 2:
        assento.ExibirAssentos();
        break;

    case 3:
        break;

    default:
        cout << "Opcção inválida. Tente novamente!" << endl;
        menuAssento(assento);
        break;
    }
}

// Função para gerar o menu de ações para passageiros
void menuPassageiro(Passageiro& pass)
{
    system("cls");

    int opcao;
    cout << "Menu de Cadastro de Passageiros:" << endl;
    cout << "1 - Cadastrar novo passageiro" << endl;
    cout << "2 - Listar passageiros cadastrados" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch (opcao)
    {
    case 1:
        pass.cadastroPassageiro();
        break;

    case 2:
        pass.listarPassageiros();
        break;

    case 3:
        break;

    default:
        cout << "Opcção inválida. Tente novamente!" << endl;
        menuPassageiro(pass);
        break;
    }
}

void menuTripulacao(Tripulacao& tripulacao)
{
    system("cls");

    int opcao;
    cout << "Menu de Cadastro de Tripulação" << endl;
    cout << "1 - Cadastrar tripulação" << endl;
    cout << "2 - Listar tripulação" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch (opcao)
    {
    case 1:
        tripulacao.cadastrarTripulacao();
        break;

    case 2:
        tripulacao.listarTripulacao();
        break;

    case 3:
        break;

    default:
        menuTripulacao(tripulacao);
        break;
    }
}
    void menuVoos (Voo& voo){
    
    system("cls");

    int opcao;
    cout << "Menu de Cadastro de Voos" << endl;
    cout << "1 - Cadastrar voo" << endl;
    cout << "2 - Listar voos" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch(opcao){
        case 1:
        
            voo.cadastroVoo();
            break;

        case 2:
            voo.listarVoo();
            system("cls");
            break;

        case 3:
            break;

        default:
            menuVoos(voo);
            break;
    }

}

int main() {
    system("chcp 65001");
    int escolha;
    Voo voo;
    Tripulacao tripulacao;
    Passageiro pass;
    Assento assento; 

    pass.carregarPassageiros();
    voo.carregarVoos();
    assento.cadastroAssento(); 
    do {
        cout << "Escolha o que deseja fazer:" << endl;
        cout << "1 - Cadastrar passageiro" << endl;
        cout << "2 - Cadastrar tripulação" << endl;
        cout << "3 - Cadastrar voo" << endl;
        cout << "4 - Cadastrar assento" << endl;
        cout << "5 - Cadastrar reserva" << endl;
        cout << "6 - Baixa em reservas" << endl;
        cout << "7 - Pesquisa" << endl;
        cout << "8 - Consulta ao programa de fidelidade" << endl;
        cout << "0 - Sair" << endl;
        cin >> escolha;

        switch (escolha) {
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
            cout << "escolha 5" << endl;
            break;

        case 6:
            system("cls");
            cout << "escolha 6" << endl;
            break;

        case 7:
            system("cls");
            cout << "escolha 7" << endl;
            break;

        case 8:
            system("cls");
            cout << "escolha 9" << endl;
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


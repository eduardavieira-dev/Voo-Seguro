#include <iostream>
#include <string>
#include <locale>
#include "atributosPassageiro.h"

using namespace std;
void menuPassageiro();

void cadastroPassageiro()
{
    Endereco enderecoPass;
    int numero;
    string cidade;
    string rua;

    cout << "Digite o número residencial:" << endl;
    getline(cin, numero);
    enderecoPass.setNumero(numero);

    cout << "Informe a cidade do passageiro: " << endl;
    getline(cin, cidade);
    enderecoPass.setCidade(cidade);

    cout << "Informe a rua do endereço: " << endl;
    getline(cin, rua);
    enderecoPass.setRua(rua);

    Passageiro Pass;

    
}

void menuPassageiro()
{
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int opcao;
    cout << "Menu de Cadastro de Passageiros:" << endl;
    cout << "1 - Cadastrar voo" << endl;
    cout << "2 - Listar voos" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch (opcao)
    {
    case 1:
        cadastroPassageiro();
        break;

    case 2:
        listarPassageirosCadastrados();
        break;

    case 3:
        break;

    default:
        cout << "Opcção inválida" << endl;
        menuPassageiro();
        break;
    }
}
// void imprimeDadosPassageiro()
// {
//     cout << "ID: " << id << endl;
//     cout << "Nome: " << nome << endl;
//     cout << "Endereço: " << endl;
//     cout << "Fidelidade: " << (fidelidade ? "Sim" : "Não") << endl;
//     cout << "Pontuação: " << pontuacao << endl;
// };

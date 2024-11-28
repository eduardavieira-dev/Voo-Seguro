#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Pesquisa.h"
#include "Passageiro.h"
#include "Tripulacao.h"


using namespace std;
// Criação de um objeto global da classe Pesquisa
Pesquisa pesquisa;
void 

// Métodos da classe Pesquisa para definir os valores dos atributos (Setters)
// Define o código do passageiro
Pesquisa::setCodPassageiro(int codPassageiro)
{
    IdPassageiro = codPassageiro;
}
// Define o código do tripulante
void Pesquisa::setCodTripulacao(int codTripulante)
{
    IdTripulante = codTripulante;
}
// Define o nome do tripulante
void Pesquisa::setNomeTripulacao(string nomeTripulante)
{
    this->NomeTripulante = nomeTripulante;
}
// Define o nome do passageiro
void Pesquisa::setNomePassageiro(string nomePassageiro) {
    this->NomePassageiro = nomePassageiro;
}

// Implementação do método de pesquisa de passageiros
void Pesquisa::pesquisarPassageiro() {
    system("chcp 65001");
    int opcao, codPassageiro;
    string nomePassageiro;
    cout << "Pesquisa de passageiro" << endl;
        cout << "1 - Pesquisar passageiros por nome" << endl;
        cout << "2 - Pesquisar passageiros por ID" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        cin.ignore();
        switch (opcao) {
            case 1:
                  cout << "Informe o nome do Passageiro:" << endl;
                    getline(cin, nomePassageiro);
                    pesquisa.setNomePassageiro(nomePassageiro);             
                break;
            case 2:
                  cout << "Informe o código do Passageiro:" << endl;
                    cin >> codPassageiro;
                    pesquisa.setCodPassageiro(codPassageiro);
                    cin.ignore();
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
}
// Implementação do método de pesquisa de tripulação
void Pesquisa::pesquisarTripulacao() {
    system("chcp 65001");
    int opcao, codTripulante;
    string nomeTripulante;
    cout << "Pesquisa de membro da tripulação" << endl;
        cout << "1 - Pesquisar tripulante por nome" << endl;
        cout << "2 - Pesquisar tripulante por código" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
 cin.ignore();
        switch (opcao) {
            case 1:
                  cout << "Informe o nome do Tripulannte:" << endl;
                    getline(cin, nomeTripulante);
                    pesquisa.setNomeTripulacao(nomeTripulante);             
                break;
            case 2:
                  cout << "Informe o código do Tripulannte:" << endl;
                    cin >> codTripulante;
                    pesquisa.setCodTripulacao(codTripulante);
                    cin.ignore();
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
}

// Função para exibir o menu principal de pesquisa
void menuPesquisa() {
    system("chcp 65001");
    system("cls");
    
    int opcao;

    while (true) {
        cout << "Menu de Pesquisa de passageiros e membros da tripulação" << endl;
        cout << "1 - Pesquisar Passageiros" << endl;
        cout << "2 - Pesquisar Membro da Tripulação" << endl;
        cout << "3 - Voltar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                pesquisa.pesquisarPassageiro();
                break;
            case 2:
                pesquisa.pesquisarTripulacao();
                break;
            case 3:
                return;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    }
}

int main() {
    menuPesquisa();
    return 0;
}

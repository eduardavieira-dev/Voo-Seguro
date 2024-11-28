/********************************************************
* FILENAME : Tripulacao.cpp
* DESCRIPTION : Implementação de cadastro, listagem, salvamento e carregamento de tripulações  e tripulantes.
*                          
* PUBLIC FUNCTIONS :
*   void Tripulacao::salvarTripulacao()     - Salva a tripulação cadastrada em um arquivo binário.
*   void Tripulacao::carregarTripulacao()   - Carrega os dados das tripulações a partir de um arquivo binário.
*   void Tripulacao::cadastrarTripulacao()  - Realiza o cadastro de uma nova tripulação.
*   void Tripulacao::listarTripulacao()     - Lista todas as tripulações cadastradas.
*
* NOTES :
* Esse código gerencia informações sobre tripulações e tripulantes, 
* incluindo funcionalidades para cadastrar, listar, salvar e carregar os dados 
* de tripulação a partir de arquivos binários. Cada tripulação pode ter até 
* 3 tripulantes (piloto, copiloto e comissário).
*
* AUTHOR : Eric
* START DATE : 22 Nov 24
********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
#include "Tripulacao.h"

using namespace std;

vector<Tripulacao> tripulacaoVet;

/* vector<Tripulacao> tripulantes; */

/* void menuTripulacao(); */

int contagemTripulacao = 0;
int contagemTripulante = 0;

/********************************************************
* NAME : void Tripulacao::salvarTripulacao()
* DESCRIPTION : Salva os tripulacao cadastrados em um arquivo binário.
* INPUTS :
* PARAMETERS : Nenhum
* RETURN :
* Type : void
* Error code :
* Values : Nenhum
*******************************************************/
void Tripulacao::salvarTripulacao()
{
    ofstream arquivo("tripulacao.dat", ios::binary);

    if (arquivo.is_open())
    {
        // Salvar a contagem de tripulações e tripulantes antes de salvar as tripulações
        arquivo.write(reinterpret_cast<char *>(&contagemTripulacao), sizeof(contagemTripulacao));
        arquivo.write(reinterpret_cast<char *>(&contagemTripulante), sizeof(contagemTripulante));

        for (int i = 0; i < contagemTripulacao; i++)
        {
            // Escrever código da tripulação
            arquivo.write(reinterpret_cast<char *>(&tripulacaoVet[i].codigoTripulacao), sizeof(tripulacaoVet[i].codigoTripulacao));

            // Iterar sobre os tripulantes da tripulação e salvar seus dados
            for (int j = 0; j < 3; j++)
            {
                arquivo.write(tripulacaoVet[i].tripulantes[j].getNome().c_str(), tripulacaoVet[i].tripulantes[j].getNome().size() + 1);
                arquivo.write(reinterpret_cast<char *>(&tripulacaoVet[i].tripulantes[j].telefone), sizeof(tripulacaoVet[i].tripulantes[j].telefone));
                arquivo.write(tripulacaoVet[i].tripulantes[j].getCargo().c_str(), tripulacaoVet[i].tripulantes[j].getCargo().size() + 1);
                arquivo.write(reinterpret_cast<char *>(&tripulacaoVet[i].tripulantes[j].codigoTripulante), sizeof(tripulacaoVet[i].tripulantes[j].codigoTripulante));
            }
        }
        arquivo.close();
    }
}



/********************************************************
* NAME : void Tripulacao::carregarTripulacao()
* DESCRIPTION : Carrega a tripulacao a partir de um arquivo binário.
* INPUTS :
* PARAMETERS : Nenhum
* RETURN :
* Type : void
* Error code :
* Values : Nenhum
*******************************************************/
void Tripulacao::carregarTripulacao()
{
    ifstream arquivo("tripulacao.dat", ios::binary);

    if (arquivo.is_open())
    {
        // Ler a contagem de tripulações e tripulantes do arquivo
        arquivo.read(reinterpret_cast<char *>(&contagemTripulacao), sizeof(contagemTripulacao));
        arquivo.read(reinterpret_cast<char *>(&contagemTripulante), sizeof(contagemTripulante));

        while (arquivo.read(reinterpret_cast<char *>(&codigoTripulacao), sizeof(codigoTripulacao)))
        {
            Tripulacao novaTripulacao;
            novaTripulacao.setCodigoTripulacao(codigoTripulacao);

            for (int j = 0; j < 3; j++)
            {
                string nome;
                int telefone, codigoTripulante;
                string cargo;

                getline(arquivo, nome, '\0');
                arquivo.read(reinterpret_cast<char *>(&telefone), sizeof(telefone));
                getline(arquivo, cargo, '\0');
                arquivo.read(reinterpret_cast<char *>(&codigoTripulante), sizeof(codigoTripulante));

                Tripulacao tripulante;
                tripulante.setNome(nome);
                tripulante.setTelefone(telefone);
                tripulante.setCargo(cargo == "Piloto" ? 1 : (cargo == "Copiloto" ? 2 : 3));
                tripulante.setCodigoTripulante(codigoTripulante);

                novaTripulacao.tripulantes.push_back(tripulante);  // Adicionando ao vetor tripulantes da tripulação
            }

            tripulacaoVet.push_back(novaTripulacao);
        }
        arquivo.close();
    }
}



string Tripulacao::getNome()
{
    return nome;
}

int Tripulacao::getTelefone()
{
    return telefone;
}

string Tripulacao::getCargo()
{
    return cargo;
}

int Tripulacao::getCodigoTripulante()
{
    return codigoTripulante;
}

int Tripulacao::getCodigoTripulacao()
{
    return codigoTripulacao;
}

void Tripulacao::setNome(string nome)
{
    this->nome = nome;
}

void Tripulacao::setTelefone(int telefone)
{
    this->telefone = telefone;
}

void Tripulacao::setCargo(int cargo)
{
    switch (cargo)
    {
    case 1:
        this->cargo = "Piloto";
        break;

    case 2:
        this->cargo = "Copiloto";
        break;

    case 3:
        this->cargo = "Comissario";
        break;

    default:
        cout << "Insira um valor válido. ";
        break;
    }
}

void Tripulacao::setCodigoTripulante(int codigoTripulante)
{
    this->codigoTripulante = codigoTripulante;
}

void Tripulacao::setCodigoTripulacao(int codigoTripulacao)
{
    this->codigoTripulacao = codigoTripulacao;
}

/********************************************************
* NAME : void Tripulacao::cadastroTripulacao()
* DESCRIPTION : Realiza o cadastro de uma nova tripulação.
* INPUTS :
* PARAMETERS : Nenhum
* RETURN :
* Type : void
* Error code :
* Values : Nenhum
*******************************************************/
void Tripulacao::cadastrarTripulacao()
{
    system("chcp 65001 > nul");
    system("cls");
    Tripulacao tripulacao;

    string nome;
    int telefone, codigoTripulante, codigoTripulacao, cargo;
    bool cargoValido = false;
    
    for (int i = 0; i < 3; i++)
    {
        system("cls");
        cargoValido = false;
        cout << "Informe o nome do tripulante " << i + 1 <<"."<< endl; 
        cout << "Nome: ";
        getline(cin, nome);
        tripulacao.setNome(nome);
        
        cout << "Informe o telefone do tripulante " << i + 1 <<"."<< endl; 
        cout << "Telefone: ";
        while (!(cin >> telefone)) {
        cout << "Entrada inválida, insira um número." << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        
        tripulacao.setTelefone(telefone);

        while (!cargoValido)
        {
            
            cout << "Informe o cargo tripulante " << i + 1 <<"."<< endl; 
            cout << "1- Piloto" << endl;
            cout << "2- Copiloto" << endl;
            cout << "3- Comissário" << endl;

            while(!(cin >> cargo)){
            cout << "Entrada inválida, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            tripulacao.setCargo(cargo);
            cargoValido = (cargo >= 1 && cargo <= 3);
        }

        contagemTripulante++;
        codigoTripulante = contagemTripulante;

        tripulacao.setCodigoTripulante(codigoTripulante);

        tripulacao.tripulantes.push_back(tripulacao);
        cout << "cotnage"<<contagemTripulante;
    }

    contagemTripulacao++;
    codigoTripulacao = contagemTripulacao;
    tripulacao.setCodigoTripulacao(codigoTripulacao);

    tripulacaoVet.push_back(tripulacao);

    tripulacao.salvarTripulacao();
}

void Tripulacao::listarTripulacao()
{
    system("cls");
    if (contagemTripulacao == 0)
    {
        cout << "Nenhuma tripulação cadastrada." << endl;
    }
    else
    {

        for (int i = 0; i < contagemTripulacao; i++)
        {
                cout << endl;
                cout << "           Tripulação: " << tripulacaoVet[i].getCodigoTripulacao() << endl;
                cout << "+---------------------------------+"<<endl;
            for (int j = 0; j < 3; j++)
            {
                cout << "| Nome: " << tripulacaoVet[i].tripulantes[j].getNome()<< endl;
                cout << "| Telefone: " << tripulacaoVet[i].tripulantes[j].getTelefone()<< endl;
                cout << "| Cargo: " << tripulacaoVet[i].tripulantes[j].getCargo()<< endl;
                cout << "| Código do tripulante: " << tripulacaoVet[i].tripulantes[j].getCodigoTripulante()<< endl;
                cout << "+---------------------------------+"<<endl;
            }
        }
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();

}
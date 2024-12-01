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
#include <algorithm>
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
 * PARAMETERS :
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
                arquivo.write(tripulacaoVet[i].tripulantes[j].getTelefone().c_str(), tripulacaoVet[i].tripulantes[j].getTelefone().size() + 1);
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
 * PARAMETERS :
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
                string telefone;
                string cargo;
                int codigoTripulante;

                getline(arquivo, nome, '\0');
                getline(arquivo, telefone, '\0');
                getline(arquivo, cargo, '\0');
                arquivo.read(reinterpret_cast<char *>(&codigoTripulante), sizeof(codigoTripulante));

                Tripulacao tripulante;
                tripulante.setNome(nome);
                tripulante.setTelefone(telefone);
                tripulante.setCargo(cargo == "Piloto" ? 1 : (cargo == "Copiloto" ? 2 : 3));
                tripulante.setCodigoTripulante(codigoTripulante);

                novaTripulacao.tripulantes.push_back(tripulante); // Adicionando ao vetor tripulantes da tripulação
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

string Tripulacao::getTelefone()
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

void Tripulacao::setTelefone(string telefone)
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
string removerEspacos(const string &str)
{
    string resultado = str;
    resultado.erase(remove(resultado.begin(), resultado.end(), ' '), resultado.end());
    resultado.erase(remove(resultado.begin(), resultado.end(), '-'), resultado.end());
    return resultado;
}

/************************************************************************************************
 * NAME : void Tripulacao::cadastrarTripulacao()
 * DESCRIPTION : Carrega a tripulacao a partir de um arquivo binário.
 * INPUTS :  string nome - Nome do tripulante
 *           int telefone - Telefone do tripulante
 *           int cargo - Cargo do tripulante (1 para Piloto, 2 para Copiloto, 3 para Comissário)
 *           int codigoTripulante - Código único do tripulante
 * PARAMETERS :
 * RETURN :
 * Type : void
 * Error:  Telefone inválido: Deve ser inserido um número
 *         Cargo inválido: Cargo inserido seja um numero invalido ou não seja um número
 *
 *************************************************************************************************/
void Tripulacao::cadastrarTripulacao()
{
    system("chcp 65001 > nul");
    system("cls");
    Tripulacao tripulacao;

    string nome, telefone;
    int codigoTripulante, codigoTripulacao, cargo;
    bool cargoValido = false;
    bool telefoneDuplicado;

    for (int i = 0; i < 3; i++)
    {
        system("cls");
        telefoneDuplicado = false;
        cargoValido = false;
        cout << "Informe o nome do tripulante " << i + 1 << "." << endl;
        cout << "Nome: ";
        getline(cin, nome);
        while (nome == "")
        {
            cout << "Erro: espaço em branco. Digite o nome do tripulante para prosseguir." << endl;
            getline(cin, nome);
        }
        tripulacao.setNome(nome);

        cout << "Informe o telefone do tripulante " << i + 1 << "." << endl;
        cout << "Telefone: ";
        getline(cin, telefone);
        while (telefone.empty())
        {
            cout << "Erro: O telefone não pode ser vazio. Insira o telefone corretamente." << endl;
            getline(cin, telefone);
        }

        telefone = removerEspacos(telefone);

         while (telefone.length() < 8) 
        {
            cout << "Erro: O telefone deve ter pelo menos 8 dígitos. Digite um valor válido." << endl;
            getline(cin, telefone);
            telefone = removerEspacos(telefone);
        }

        for (int j = 0; j < i; j++) {
            if (removerEspacos(tripulacao.tripulantes[j].getTelefone()) == telefone) {
                telefoneDuplicado = true;
            }
        }

        for (int k = 0; k < contagemTripulacao && !telefoneDuplicado; k++) {
            for (int l = 0; l < 3 && !telefoneDuplicado; l++) {
                if (removerEspacos(tripulacaoVet[k].tripulantes[l].getTelefone()) == telefone) {
                    telefoneDuplicado = true;
                }
            }
        }

        while (telefoneDuplicado) {
            cout << "Erro: Este telefone já está cadastrado. Insira um telefone diferente." << endl;
            getline(cin, telefone);

            telefone = removerEspacos(telefone);
            telefoneDuplicado = false; 

            for (int j = 0; j < i; j++) {
                if (removerEspacos(tripulacao.tripulantes[j].getTelefone()) == telefone) {
                    telefoneDuplicado = true;
                }
            }

            for (int k = 0; k < contagemTripulacao && !telefoneDuplicado; k++) {
                for (int l = 0; l < 3 && !telefoneDuplicado; l++) {
                    if (removerEspacos(tripulacaoVet[k].tripulantes[l].getTelefone()) == telefone) {
                        telefoneDuplicado = true;
                    }
                }
            }
        }
        tripulacao.setTelefone(telefone);

        while (!cargoValido)
        {

            cout << "Informe o cargo tripulante " << i + 1 << "." << endl;
            cout << "1- Piloto" << endl;
            cout << "2- Copiloto" << endl;
            cout << "3- Comissário" << endl;

            while (!(cin >> cargo))
            {
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
    }

    contagemTripulacao++;
    codigoTripulacao = contagemTripulacao;
    tripulacao.setCodigoTripulacao(codigoTripulacao);

    tripulacaoVet.push_back(tripulacao);

    tripulacao.salvarTripulacao();
    
    cout << "Tripulação cadastrada com sucesso!"<<endl;
    cout << "Pressione 'ENTER' para voltar" << endl;

    cin.get();
    system("cls");
}

/***********************************************************************
 * NAME : void Voo::listarVoo()
 * DESCRIPTION : Lista todas as tripulações e tripulantes cadastrados
 *               e exibe suas informações detalhadas.
 * INPUTS :
 * PARAMETERS :
 * RETURN :
 * Type : void
 * Error code :
 * Values : Se houver tripulção cadastrada, exibe as informações detalhadas
 *          de cada tripulação: O nome do tripulante, o telefone, seu cargo e seu código
 *          Caso não possua tripulação cadastrada,
 *          exibe uma mensagem informando que não há tripulações cadastradas.
 ************************************************************************/
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
            cout << "+---------------------------------+" << endl;
            for (int j = 0; j < 3; j++)
            {
                cout << "| Nome: " << tripulacaoVet[i].tripulantes[j].getNome() << endl;
                cout << "| Telefone: " << tripulacaoVet[i].tripulantes[j].getTelefone() << endl;
                cout << "| Cargo: " << tripulacaoVet[i].tripulantes[j].getCargo() << endl;
                cout << "| Código do tripulante: " << tripulacaoVet[i].tripulantes[j].getCodigoTripulante() << endl;
                cout << "+---------------------------------+" << endl;
            }
        }
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
}
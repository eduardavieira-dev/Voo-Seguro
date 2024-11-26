#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Tripulacao.h"

using namespace std;

vector<Tripulacao> tripulacaoVet;


int contagemTripulacao = 0;
int contagemTripulante = 0;

void Tripulacao::salvarTripulacao()
{
    ofstream arquivo("tripulacao.dat", ios::binary);

    if (arquivo.is_open())
    {
        for (int i = 0; i < contagemTripulacao; i++)
        {

            arquivo.write(reinterpret_cast<char *>(&tripulacaoVet[i].codigoTripulacao), sizeof(tripulacaoVet[i].codigoTripulacao));

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
    else
    {
        cout << "Erro ao abrir o arquivo para salvar a tripulação." << endl;
    }
}

void Tripulacao::carregarTripulacao()
{
    ifstream arquivo("tripulacao.dat", ios::binary);

    if (arquivo.is_open())
    {
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

                novaTripulacao.tripulantes.push_back(tripulante);
            }

            tripulacaoVet.push_back(novaTripulacao);
            contagemTripulacao++;
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo para carregar a tripulação." << endl;
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

void Tripulacao::cadastrarTripulacao()
{
    system("chcp 65001");
    system("cls");
    Tripulacao tripulacao;

    string nome;
    int telefone, codigoTripulante, codigoTripulacao, cargo;
    bool cargoValido = false;

    for (int i = 0; i < 3; i++)
    {
        cargoValido = false;
        cout << "Informe o nome do tripulante:" << i + 1 << endl;
        getline(cin, nome);
        tripulacao.setNome(nome);

        cout << "Informe o telefone do tripulante:" << i + 1 << endl;
        cin >> telefone;
        cin.ignore();
        tripulacao.setTelefone(telefone);

        while (!cargoValido)
        {
            cout << "Informe o cargo tripulante:" << i + 1 << endl;
            cout << "1- Piloto" << endl;
            cout << "2- Copiloto" << endl;
            cout << "3- Comissário" << endl;
            cin >> cargo;
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
}

void Tripulacao::listarTripulacao()
{

    if (contagemTripulacao == 0)
    {
        cout << "Nenhuma tripulação cadastrada." << endl;
    }
    else
    {

        for (int i = 0; i < contagemTripulacao; i++)
        {
            cout << "Tripulação: " << tripulacaoVet[i].getCodigoTripulacao() << endl;

            for (int j = 0; j < 3; j++)
            {
                cout << "Nome: " << tripulacaoVet[i].tripulantes[j].getNome() << endl;
                cout << "Telefone: " << tripulacaoVet[i].tripulantes[j].getTelefone() << endl;
                cout << "Cargo: " << tripulacaoVet[i].tripulantes[j].getCargo() << endl;
                cout << "Código do tripulante: " << tripulacaoVet[i].tripulantes[j].getCodigoTripulante() << endl;
            }
        }
    }
    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();

}

/* int Tripulacao::getTotalTripulacao(){
    return contagemTripulacao;
}

Tripulacao* Tripulacao::getTripulacaoPorCodigo(int codigoTripulacao)
{
   for (int i = 0; i < contagemTripulacao; i++) 
   {
        if(tripulacaoVet[i].codigoTripulacao == codigoTripulacao) 
        {
            return &tripulacaoVet[i];
        }
   }

   return nullptr;
} */

/* bool Tripulacao::elegivelVoo(int codigoTripulacao){
       Tripulacao* tripulacao = this->getTripulacaoPorCodigo(codigoTripulacao);

        bool pilotoEncontrado = false;
        bool copilotoEncontrado = false;

        for (int i = 0; i < tripulacao->tripulantes.capacity(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                pilotoEncontrado = tripulacaoVet[i].tripulantes[j].getCargo() == "Piloto";
                copilotoEncontrado = tripulacaoVet[i].tripulantes[j].getCargo() == "Copiloto";
            }
        }

        return pilotoEncontrado && copilotoEncontrado;
} */

/* 
void menuTripulacao()
{

    Tripulacao tripulacao;
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
        menuTripulacao();
        break;
    }
}

int main()
{
    Tripulacao tripu;
    tripu.carregarTripulacao();
    system("chcp 65001");
    menuTripulacao();
} */
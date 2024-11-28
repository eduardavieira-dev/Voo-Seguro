#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Reserva.h"
#include "Assento.h"
#include "Voo.h"
#include "Passageiro.h"

using namespace std;

extern vector<Voo> voos;
extern vector<Assento> assentos;
extern vector<Passageiro> passageiros;

vector<Reserva> reservas;

void alteraDadosAssento(vector<Assento> &assentos)
{
    // Abrindo o arquivo em modo binário e truncando o conteúdo
    ofstream arquivo("assentos.dat", ios::out | ios::binary);

    if (arquivo.is_open())
    {
        // Escrevendo os dados do vetor no arquivo
        for (size_t i = 0; i < assentos.size(); i++)
        {
            int numAssento = assentos[i].getNumAssento();
            int codVoo = assentos[i].getCodVoo();
            bool status = assentos[i].getStatusAssento();

            arquivo.write(reinterpret_cast<char *>(&numAssento), sizeof(numAssento));
            arquivo.write(reinterpret_cast<char *>(&codVoo), sizeof(codVoo));
            arquivo.write(reinterpret_cast<char *>(&status), sizeof(status));
        }
        arquivo.close();
    }
    else
    {
        cerr << "Erro ao abrir o arquivo assentos.dat!" << endl;
    }
}

void alteraDadosPassageiro(vector<Passageiro> &passageiros)
{
    // Abrindo o arquivo em modo binário e truncando o conteúdo
    ofstream arquivo("passageiros.dat", ios::out | ios::binary);

    if (arquivo.is_open())
    {
        // Escrevendo os dados do vetor no arquivo
        for (size_t i = 0; i < passageiros.size(); i++)
        {
            int id = passageiros[i].getID();
            string nome = passageiros[i].getNome();
            string telefone = passageiros[i].getTelefone();
            bool fidelidade = passageiros[i].getFidelidade();
            int pontuacao = passageiros[i].getPontuacao();
            int numResidencia = passageiros[i].getNumResidencia();
            string cidade = passageiros[i].getCidade();
            string rua = passageiros[i].getRua();

            arquivo.write(reinterpret_cast<char *>(&id), sizeof(id));
            arquivo.write(nome.c_str(), nome.size() + 1);
            arquivo.write(telefone.c_str(), telefone.size() + 1);
            arquivo.write(cidade.c_str(), cidade.size() + 1);
            arquivo.write(rua.c_str(), rua.size() + 1);
            arquivo.write(reinterpret_cast<char *>(&numResidencia), sizeof(numResidencia));
            arquivo.write(reinterpret_cast<char *>(&fidelidade), sizeof(fidelidade));
            arquivo.write(reinterpret_cast<char *>(&pontuacao), sizeof(pontuacao));
        }
        arquivo.close();
    }
    else
    {
        cerr << "Erro ao abrir o arquivo passageiros.dat!" << endl;
    }
}

Reserva::Reserva()
{
    codigVooReserva = 0;
    numeroAssentoReserva = 0;
    codPassageiroReserva = 0;
}

Reserva::Reserva(int codigVooReserva, int numeroAssentoReserva, int codPassageiroReserva)
{
    this->codigVooReserva = codigVooReserva;
    this->numeroAssentoReserva = numeroAssentoReserva;
    this->codPassageiroReserva = codPassageiroReserva;
}

int Reserva::getcodigVooReserva()
{
    return codigVooReserva;
}

int Reserva::getNumAssentoReserva()
{
    return numeroAssentoReserva;
}
int Reserva::getCodPassageiroReserva()
{
    return codPassageiroReserva;
}

void Reserva::cadastroReserva()
{
    system("cls");

    int codVoo = 0, numAssento = 0, codPassageiro = 0;
    bool verificaExistenciaVoo = false;

    cout << "Digite o código do voo: \n";
    cin >> codVoo;
    cin.ignore();

    for (size_t i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigoVoo() == codVoo)
        {
            verificaExistenciaVoo = true;
            if (voos[i].getStatus() == "Ativo")
            {
                bool verificaExistenciaAssento = false;
                cout << "Digite o número do assento: \n";
                while (!(cin >> numAssento))
                {
                    cout << "Entrada inválida, insira um número." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                for (size_t j = 0; j < assentos.size(); j++)
                {
                    if (assentos[j].getCodVoo() == codVoo && assentos[j].getNumAssento() == numAssento)
                    {
                        verificaExistenciaAssento = true;
                        if (assentos[j].getStatusAssento() == false)
                        {
                            bool verificaExistenciaPassageiro = false;
                            cout << "Digite o id do passageiro: \n";
                            while (!(cin >> codPassageiro))
                            {
                                cout << "Entrada inválida, insira um número." << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }

                            for (size_t a = 0; a < passageiros.size(); a++)
                            {
                                if (passageiros[a].getID() == codPassageiro)
                                {
                                    verificaExistenciaPassageiro = true;
                                    Reserva NovaReserva(codVoo, numAssento, codPassageiro);
                                    cout << "Reserva cadastrada com sucesso: \n";
                                    cout << "Número do assento: " << NovaReserva.getNumAssentoReserva() << "\n";
                                    cout << "Código do voo: " << NovaReserva.getcodigVooReserva() << "\n";
                                    cout << "Código do passageiro: " << NovaReserva.getCodPassageiroReserva() << "\n";
                                    reservas.push_back(NovaReserva); // Adiciona ao vetor
                                    NovaReserva.salvarReserva();     // Salva apenas o novo assento

                                    bool fide = true;
                                    bool statusAssento = true;
                                    passageiros[a].setFidelidade(fide);
                                    passageiros[a].setPontuacao(10);
                                    alteraDadosPassageiro(passageiros);

                                    assentos[j].setStatusAssento(statusAssento);
                                    alteraDadosAssento(assentos);
                                }
                            }
                            if (verificaExistenciaPassageiro == false)
                            {
                                cout << "Erro: Nenhum passageiro encontrado com o código fornecido." << endl;
                            }
                        }
                        else
                        {
                            cout << "Erro: Assento informado está ocupado" << endl;
                        }
                    }
                }

                if (verificaExistenciaAssento == false)
                {
                    cout << "Erro: Não existe assento cadastrado no voo " << codVoo << " com o código fornecido." << endl;
                }
            }
            else
            {
                cout << "Erro: O voo informado não está ativo." << endl;
            }
        }
    }

    if (verificaExistenciaVoo == false)
    {
        cout << "Erro: Nenhum voo encontrado com o código fornecido." << endl;
    }
}

void Reserva::salvarReserva()
{
    ofstream arquivo("reservas.dat", ios::app | ios::binary);

    if (arquivo.is_open())
    {
        // Salva apenas os dados do objeto atual (this)
        arquivo.write(reinterpret_cast<char *>(&codigVooReserva), sizeof(codigVooReserva));
        arquivo.write(reinterpret_cast<char *>(&numeroAssentoReserva), sizeof(numeroAssentoReserva));
        arquivo.write(reinterpret_cast<char *>(&codPassageiroReserva), sizeof(codPassageiroReserva));
        arquivo.close();
    }
}

void Reserva::carregarReservas()
{
    ifstream arquivo("reservas.dat", ios::binary);

    if (arquivo.is_open())
    {
        reservas.clear(); // Limpa o vetor

        int numAssentoTemp;
        int codVooTemp;
        int codPassTemp;

        while (arquivo.read(reinterpret_cast<char *>(&numAssentoTemp), sizeof(numAssentoTemp)))
        {
            arquivo.read(reinterpret_cast<char *>(&codVooTemp), sizeof(codVooTemp));
            arquivo.read(reinterpret_cast<char *>(&codPassTemp), sizeof(codPassTemp));

            Reserva novaReserva(codVooTemp, numAssentoTemp, codPassTemp);
            reservas.push_back(novaReserva);
        }
        arquivo.close();
    }
}

void Reserva::listaReservas()
{
    system("cls");
    if (reservas.size() == 0)
    {
        cout << "Nenhuma reserva cadastrada." << endl;
    }
    else
    {
        for (size_t i = 0; i < reservas.size(); i++)
        {
            cout << "Informações da reserva " << i + 1 << ":" << endl;
            cout << "Número do assento: " << reservas[i].getNumAssentoReserva() << endl;
            cout << "Código do voo: " << reservas[i].getcodigVooReserva() << endl;
            cout << "Código do passageiro: " << reservas[i].getCodPassageiroReserva() << endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
}
#include <iostream>
#include <vector>
#include <fstream>
#include "Reserva.h"
#include "Assento.h"
#include "Voo.h"
#include "Passageiro.h"

using namespace std;

extern vector<Voo> voos;
extern vector<Assento> assentos;
extern vector<Passageiro> passageiros;

vector<Reserva> reservas;

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
    bool verificaExistenciaAssento = false;
    bool verificaExistenciaPassageiro = false;
    bool verificaVooAtivo = false;

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
                verificaVooAtivo = true;
                cout << "Digite o número do assento: \n";
                cin >> numAssento;
                cin.ignore();

                for (size_t j = 0; j < assentos.size(); j++)
                {
                    if (assentos[j].getCodVoo() == codVoo && assentos[j].getNumAssento() == numAssento)
                    {
                        verificaExistenciaAssento = true;
                        cout << "Digite o id do passageiro: \n";
                        cin >> codPassageiro;
                        cin.ignore();

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
                                passageiros[a].salvarDadosPassageiro();

                                assentos[j].setStatusAssento(statusAssento);
                                assentos[j].salvarAssento();
                            }
                        }
                    }
                }
            }
        }
    }

    if (verificaExistenciaVoo == false)
    {
        cout << "Erro: Nenhum voo encontrado com o código fornecido." << endl;
    }

    if (verificaVooAtivo == false)
    {
        cout << "Erro: O voo informado não está ativo." << endl;
    }

    if (verificaExistenciaAssento == false)
    {
        cout << "O assento informado não existe no Voo " << codVoo << "\nEscolha outro assento ou cadastre o assento no voo antes." << endl;
    }

    if (verificaExistenciaPassageiro == false)
    {
        cout << "Erro: Nenhum passageiro encontrado com o código fornecido." << endl;
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
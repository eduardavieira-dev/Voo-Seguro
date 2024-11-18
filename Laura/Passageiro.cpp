#include <iostream>
#include "Passageiro.h"

// Inicialize a variável estática
int Passageiro::contadorID = 1;

Passageiro::Passageiro(string nome, bool fidelidade, Endereco endereco)
{
    this->id = contadorID++; // Atribui o ID atual e incrementa para o próximo
    this->nome = nome;
    this->fidelidade = fidelidade;
    this->endereco = endereco;
    this->pontuacao = 0;
};

void Passageiro::setNome(string nome)
{
    this->nome = nome;
};

void Passageiro::setFidelidade(bool fidelidade)
{
    this->fidelidade = fidelidade;
};

void Passageiro::setPontuacao()
{
    this->pontuacao += 10;
};

string Passageiro::getNome()
{
    return nome;
};

bool Passageiro::getFidelidade()
{
    return fidelidade;
};

int Passageiro::getPontuacao()
{
    return pontuacao;
};

void Passageiro::imprimeDadosPassageiro()
{
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Endereço: " << endl;
    endereco.imprimeEndereco();
    cout << "Fidelidade: " << (fidelidade ? "Sim" : "Não") << endl;
    cout << "Pontuação: " << pontuacao << endl;
};

#include <iostream>
#include "Endereco.h"

using namespace std;

Endereco::Endereco(int numero, string cidade, string rua)
{
    this->numero = numero;
    this->cidade = cidade;
    this->rua = rua;
};

void Endereco::setNumero(int numero)
{
    this->numero = numero;
};

void Endereco::setCidade(string cidade)
{
    this->cidade = cidade;
}

void Endereco::setRua(string rua)
{
    this->rua = rua;
};

int Endereco::getNumero()
{
    return numero;
};

string Endereco:: getCidade(){
    return cidade;
}

string Endereco:: getRua(){
    return rua;
}

void Endereco:: imprimeEndereco(){
    cout << rua << ", " << numero << " - " << cidade << endl;
}
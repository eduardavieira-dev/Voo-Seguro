#ifndef ATRIBUTOSPASSAGEIRO_H
#define ATRIBUTOSPASSAGEIRO_H

#include <string>

using namespace std;

class Endereco
{
private:
    int numero;
    string cidade;
    string rua;

public:
    Endereco(int numero, string cidade, string rua)
    {
        this->numero = numero;
        this->cidade = cidade;
        this->rua = rua;
    };

    void setNumero(int numero)
    {
        this->numero = numero;
    };

    void setCidade(string cidade)
    {
        this->cidade = cidade;
    };

    void setRua(string rua)
    {
        this->rua = rua;
    };

    int getNumero()
    {
        return numero;
    };

    string getCidade()
    {
        return cidade;
    };

    string getRua()
    {
        return rua;
    };
};

class Passageiro
{
private:
    static int contadorID; // variável estática para controlar o ID
    int id;
    string nome;
    bool fidelidade;
    int pontuacao;
    Endereco endereco;

public:
    // Inicialize a variável estática
    int contadorID = 1;

    Passageiro(string nome, bool fidelidade, Endereco endereco) : endereco(endereco)
    {
        this->id = contadorID++; // Atribui o ID atual e incrementa para o próximo
        this->nome = nome;
        this->fidelidade = fidelidade;
        this->endereco = endereco;
        this->pontuacao = 0;
    };

    void setNome(string nome)
    {
        this->nome = nome;
    };

    void setFidelidade(bool fidelidade)
    {
        this->fidelidade = fidelidade;
    };

    void setPontuacao()
    {
        this->pontuacao += 10;
    };

    string getNome()
    {
        return nome;
    };

    bool getFidelidade()
    {
        return fidelidade;
    };

    int getPontuacao()
    {
        return pontuacao;
    };
};

#endif // PASSAGEIRO_H
#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>

using namespace std;

class Passageiro
{
private:
    static int contadorID; // variável estática para controlar o ID
    int id;
    string nome;
    string telefone;
    bool fidelidade;
    int pontuacao;
    int numResidencia;
    string cidade;
    string rua;

public:

    Passageiro();

    Passageiro(string nome, string telefone, int numResidencia, string cidade, string rua);

    void setNome(string nome);

    void setTelefone(string telefone);

    void setPontuacao();

    int getID();

    string getNome();

    bool getFidelidade();

    int getPontuacao();

    string getTelefone();

    void setNumResidencia(int numResidencia);

    void setCidade(string cidade);

    void setRua(string rua);

    int getNumResidencia();

    string getCidade();

    string getRua();

    void salvarDadosPassageiro();

    void carregarPassageiros();
};

void cadastroPassageiro();
void listarPassageiros();

#endif 
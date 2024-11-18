#include "Endereco.h"
#include <string>

using namespace std;

class Passageiro{
    private:
        static int contadorID; // variável estática para controlar o ID
        int id;
        string nome;
        bool fidelidade;
        int pontuacao;
        Endereco endereco;

    public:
        Passageiro(string nome, bool fidelidade, Endereco endereco);
        void setNome(string nome);
        void setFidelidade(bool fidelidade);
        void setPontuacao();
        string getNome();
        bool getFidelidade();
        int getPontuacao();
        void imprimeDadosPassageiro();
};
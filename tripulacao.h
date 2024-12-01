#ifndef TRIPULACAO2_H
#define TRIPULACAO2_H
#include <string>
#include <vector>

using namespace std;


class Tripulacao{
    private:
    string nome;
    string telefone;
    string cargo;
    int codigoTripulante;
    int codigoTripulacao;
    bool tripulacaoEmUso = false;
    vector<Tripulacao> tripulantes;

    public:
    string getNome();
    string getTelefone();
    string getCargo();
    int getCodigoTripulante();
    int getCodigoTripulacao();
    bool getTripulacaoEmUso();
    vector<Tripulacao>& getTripulantes();

    void setNome(string nome);
    void setTelefone(string telefone);
    void setCargo(int cargo);
    void setCodigoTripulante(int codigoTripulante);
    void setCodigoTripulacao(int codigoTripulacao);
    void setTripulacaoEmUso(bool tripulacaoEmUso);

    void cadastrarTripulacao();
    void listarTripulacao();
    
    void salvarTripulacao();
    void carregarTripulacao();

};



#endif // TRIPULACAO2_H

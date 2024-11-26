#ifndef TRIPULACAO2_H
#define TRIPULACAO2_H
#include <string>
#include <vector>

using namespace std;
class Tripulacao{
    private:
    string nome;
    int telefone;
    int cargo;
    int codigoTripulante;
    int codigoTripulacao;

    public:
    string getNome();
    int getTelefone();
    int getCargo();
    int getCodigoTripulante();
    int getCodigoTripulacao();

    void setNome(string nome);
    void setTelefone(int telefone);
    void setCargo(int cargo);
    void setCodigoTripulante(int codigoTripulante);
    void setCodigoTripulacao(int codigoTripulacao);

    void cadastrarTripulacao();
    void listarTripulacao();

    void salvarDados();
    void carregarDados();

};


#endif // TRIPULACAO2_H

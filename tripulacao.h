#ifndef TRIPULACAO2_H
#define TRIPULACAO2_H
#include <string>
#include <vector>

using namespace std;
class Tripulacao{
    private:
    string nome;
    int telefone;
    string cargo;
    int codigoTripulante;
    int codigoTripulacao;
    vector<Tripulacao> tripulantes;
    

    public:
    string getNome();
    int getTelefone();
    string getCargo();
    int getCodigoTripulante();
    int getCodigoTripulacao();
    /* int getTotalTripulacao(); */
    

    void setNome(string nome);
    void setTelefone(int telefone);
    void setCargo(int cargo);
    void setCodigoTripulante(int codigoTripulante);
    void setCodigoTripulacao(int codigoTripulacao);

    void cadastrarTripulacao();
    void listarTripulacao();
    
    void salvarTripulacao();
    void carregarTripulacao();

    /* Tripulacao* getTripulacaoPorCodigo(int codigoTripulacao);
    bool Tripulacao::elegivelVoo(int codigoTripulacao); */
};



#endif // TRIPULACAO2_H

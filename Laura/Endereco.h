#include <string>

using namespace std;

class Endereco{
    private:
    int numero;
    string cidade;
    string rua;

    public:
    Endereco(int numero, string cidade, string rua);
    void setNumero(int numero);
    void setCidade(string cidade);
    void setRua(string rua);
    int getNumero();
    string getCidade();
    string getRua();
    void imprimeEndereco();
};
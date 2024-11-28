#ifndef RESERVA_H
#define RESERVA_H

using namespace std;

class Reserva{
    private:
    int codigVooReserva;
    int numeroAssentoReserva;
    int codPassageiroReserva;

    public:

    Reserva();
    Reserva(int codigVooReserva, int numeroAssentoReserva, int codPassageiroReserva);

    int getcodigVooReserva();
    int getNumAssentoReserva();
    int getCodPassageiroReserva();

    void cadastroReserva();
    void listaReservas();
    void salvarReserva();
    void carregarReservas();
    void baixaReserva();
};

#endif //ASSENTO.H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Tripulacao.h"
#include "Voo.h"

using namespace std;

#define MAX_VOOS 100



/* Tripulacao tripulacaoDoVoo; */
vector<Voo> voos;
extern vector<Tripulacao> tripulacaoVet;

int contagemVoo = 0;

void Voo::salvarVoos()
{
    ofstream arquivo("voos.dat", ios::binary);

    if (arquivo.is_open())
    {

        for (int i = 0; i < contagemVoo; i++)
        {

            arquivo.write(reinterpret_cast<char *>(&voos[i].codigoVoo), sizeof(voos[i].codigoVoo));
            arquivo.write(reinterpret_cast<char *>(&voos[i].codigoAviao), sizeof(voos[i].codigoAviao));
            arquivo.write(voos[i].origem.c_str(), voos[i].origem.size() + 1);
            arquivo.write(voos[i].destino.c_str(), voos[i].destino.size() + 1);
            arquivo.write(reinterpret_cast<char *>(&voos[i].dia), sizeof(voos[i].dia));
            arquivo.write(reinterpret_cast<char *>(&voos[i].mes), sizeof(voos[i].mes));
            arquivo.write(reinterpret_cast<char *>(&voos[i].ano), sizeof(voos[i].ano));
            arquivo.write(reinterpret_cast<char *>(&voos[i].hora), sizeof(voos[i].hora));
            arquivo.write(reinterpret_cast<char *>(&voos[i].minuto), sizeof(voos[i].minuto));
            arquivo.write(reinterpret_cast<char *>(&voos[i].tarifa), sizeof(voos[i].tarifa));
            arquivo.write(voos[i].status.c_str(), voos[i].status.size() + 1);
        }
        arquivo.close();
    }

}

void Voo::carregarVoos()
{
    ifstream arquivo("voos.dat", ios::binary);

    if (arquivo.is_open())
    {
        while (arquivo.read(reinterpret_cast<char *>(&codigoVoo), sizeof(codigoVoo)))
        {
            arquivo.read(reinterpret_cast<char *>(&codigoAviao), sizeof(codigoAviao));
            getline(arquivo, origem, '\0');
            getline(arquivo, destino, '\0');
            arquivo.read(reinterpret_cast<char *>(&dia), sizeof(dia));
            arquivo.read(reinterpret_cast<char *>(&mes), sizeof(mes));
            arquivo.read(reinterpret_cast<char *>(&ano), sizeof(ano));
            arquivo.read(reinterpret_cast<char *>(&hora), sizeof(hora));
            arquivo.read(reinterpret_cast<char *>(&minuto), sizeof(minuto));
            arquivo.read(reinterpret_cast<char *>(&tarifa), sizeof(tarifa));
            getline(arquivo, status, '\0');

            Voo novoVoo;
            novoVoo.setCodigoVoo(codigoVoo);
            novoVoo.setCodigoAviao(codigoAviao);
            novoVoo.setOrigem(origem);
            novoVoo.setDestino(destino);
            novoVoo.setDia(dia);
            novoVoo.setMes(mes);
            novoVoo.setAno(ano);
            novoVoo.setHora(hora);
            novoVoo.setMinuto(minuto);
            novoVoo.setTarifa(tarifa);
            novoVoo.setStatus(status == "Ativo" ? 1 : 2);

            voos.push_back(novoVoo);
            contagemVoo++;
        }
        arquivo.close();
    }
}

int Voo::getCodigoAviao()
{
    return codigoAviao;
}

int Voo::getCodigoVoo()
{
    return codigoVoo;
}

int Voo::getTarifa()
{
    return tarifa;
}

int Voo::getDia()
{
    return dia;
}

int Voo::getMes()
{
    return mes;
}

int Voo::getAno()
{
    return ano;
}

int Voo::getHora()
{
    return hora;
}

int Voo::getMinuto()
{
    return minuto;
}

string Voo::getOrigem()
{
    return origem;
}

string Voo::getStatus(){
    return status;
}

string Voo::getDestino()
{
    return destino;
}

bool Tripulacao::getTripulacaoEmUso(){
    return tripulacaoEmUso;
}

vector<Tripulacao>& Tripulacao::getTripulantes() {
    return tripulantes;
}

void Voo::setCodigoAviao(int codigoAviao)
{
    this->codigoAviao = codigoAviao;
}

void Voo::setCodigoVoo(int codigoVoo)
{
    this->codigoVoo = codigoVoo;
}

void Voo::setTarifa(int tarifa)
{
    this->tarifa = tarifa;
}

void Tripulacao::setTripulacaoEmUso(bool tripualacaoEmUso){
    this->tripulacaoEmUso = tripualacaoEmUso;

} 

void Voo::setStatus(int status){
    switch (status)
    {
    case 1:
        this->status = "Ativo";
        break;

    case 2:
        this->status = "Inativo";
        break;

    }
}

void Voo::setDia(int dia)
{
    if (dia > 0 && dia <= 31)
    {
        this->dia = dia;
    }
    else
    {
        cout << "Dia inválido" << endl;
    }
}

void Voo::setMes(int mes)
{
    if (mes > 0 && mes <= 12)
    {
        this->mes = mes;
    }
    else
    {
        cout << "Mês inválido" << endl;
    }
}

void Voo::setAno(int ano)
{
    if (ano >= 2024 && ano <= 2030)
    {
        this->ano = ano;
    }
    else
    {
        cout << "Deve ser cadastrado voos entre 2024 e 2030" << endl;
    }
}

void Voo::setHora(int hora)
{
    if (hora >= 0 && hora <= 23)
    {
        this->hora = hora;
    }
    else
    {
        cout << "Hora invalida" << endl;
    }
}

void Voo::setMinuto(int minuto)
{
    if (minuto >= 0 && minuto <= 59)
    {
        this->minuto = minuto;
    }
    else
    {
        cout << "Minuto invalido" << endl;
    }
}

void Voo::setOrigem(string origem)
{
    this->origem = origem;
}

void Voo::setDestino(string destino)
{
    this->destino = destino;
}

void Voo::cadastroVoo()
{
    system("chcp 65001 > nul");
    system("cls");
    Voo voo;
    if (contagemVoo >= MAX_VOOS)
    {
        cout << "Limite de voos cadastrados atingido!" << endl;
        return;
    };

    string origem, destino;
    int codigoAviao, tarifa, status, dia, mes, ano, hora, minuto, codigoTripulacao;
    bool diaValido = false, mesValido = false, anoValido = false, horaValida = false, minutoValido = false, tripulacaoValida = false;
    bool temPiloto = false;
    bool temCopiloto = false;
    bool tripulacaoEmUso = false;
    

    if (tripulacaoVet.empty()) {
        cout << "Não há tripulação cadastrada. Cadastre uma tripulação antes de cadastrar um voo." << endl;
        return; 
    }
    cout << "Informe a origem do voo." << endl;
    cout <<"Origem: ";
    getline(cin, origem);
    voo.setOrigem(origem);

    cout << "Informe o destino do voo." << endl;
    cout << "Destino: ";
    getline(cin, destino);
    voo.setDestino(destino);

    cout << "Informe a data do voo." << endl;

    while (!diaValido)
    {
        cout << "Dia (1-31): ";
        cin >> dia;
        cin.ignore();
        voo.setDia(dia);
        diaValido = (dia > 0 && dia <= 31);
    }

    while (!mesValido)
    {
        cout << "Mes (1-12): ";
        cin >> mes;
        cin.ignore();
        voo.setMes(mes);
        mesValido = (mes > 0 && mes <= 12);
    }

    while (!anoValido)
    {
        cout << "Ano: (2024-2030): ";
        cin >> ano;
        cin.ignore();
        voo.setAno(ano);
        anoValido = (ano > 2023 && ano <= 2030);
    }

    while (!horaValida || !minutoValido)
    {
        cout << "Digite o horário do voo (HH:MM): ";
        char doisPontos;
        cin >> hora >> doisPontos >> minuto;
        cin.ignore();
        if (doisPontos == ':')
        {
            voo.setHora(hora);
            voo.setMinuto(minuto);
            horaValida = (hora >= 0 && hora <= 23);
            minutoValido = (minuto >= 0 && minuto <= 59);
        }
    }

    while (!tripulacaoValida) {
    cout << "Informe o código da tripulação: ";
    cin >> codigoTripulacao; 
    cin.ignore();
    
    tripulacaoValida = false;
    
    for (int i = 0; i < tripulacaoVet.size(); i++) {
    if (tripulacaoVet[i].getCodigoTripulacao() == codigoTripulacao) {
        if (tripulacaoVet[i].getTripulacaoEmUso()) {
            cout << "Tripulação já está em uso. Tente usar outro código" << endl;
            return;
        }
        tripulacaoVet[i].setTripulacaoEmUso(true);
        tripulacaoValida = true;
    }
}
    
    if (!tripulacaoValida) {
        cout << "Código de tripulação inválido. Tente novamente." << endl;
        }
    }

    cout << "Informe o código do avião: ";
    cin >> codigoAviao;
    cin.ignore();
    voo.setCodigoAviao(codigoAviao);

    cout << "Informe a tarifa: ";
    cin >> tarifa;
    cin.ignore();
    voo.setTarifa(tarifa);

    vector<Tripulacao>& tripulantes = tripulacaoVet[codigoTripulacao - 1].getTripulantes();  // Acessa a tripulação específica

    for (int j = 0; j < tripulantes.size(); j++) {
    
        if (tripulantes[j].getCargo() == "Piloto") {
            temPiloto = true;
        }
        
        if (tripulantes[j].getCargo() == "Copiloto") {
            temCopiloto = true;
        }
        
    }

    if (temPiloto && temCopiloto) {
        cout << "Voo ativo" << endl;
        status = 1;
        voo.setStatus(status);
    } else {
        cout << "Voo inativo, falta piloto ou copiloto" << endl;
        status = 2;
        voo.setStatus(status);
    }

    contagemVoo++;
    voo.setCodigoVoo(contagemVoo);

    voos.push_back(voo);

    voo.salvarVoos();
}

void Voo::listarVoo()
{
    system("cls");
    if (contagemVoo == 0)
    {
        cout << "Nenhum voo cadastrado" << endl;
    }
    else
    {
        for (int i = 0; i < contagemVoo; i++)
        {
            cout << endl;
            cout << "       Informações do Voo:" << voos[i].getCodigoVoo() << endl;
            cout << "+---------------------------------+"<<endl;
            cout << "Código de voo: " << voos[i].getCodigoVoo() << endl;
            cout << "Código do avião: " << voos[i].getCodigoAviao() << endl;
            cout << "Local de origem: " << voos[i].getOrigem() << endl;
            cout << "Local de destino: " << voos[i].getDestino() << endl;
            cout << "Data: " << setfill('0') << setw(2) << voos[i].getDia() << "/" << setfill('0') << setw(2) << voos[i].getMes() << "/" << voos[i].getAno() << endl;
            cout << "Horário: " << setfill('0') << setw(2) << voos[i].getHora() << ":" << setfill('0') << setw(2) << voos[i].getMinuto() << endl;
            cout << "Tarifa: " << voos[i].getTarifa() << endl;
            cout << "Status: " <<voos[i].getStatus() << endl;
            cout << "+---------------------------------+"<<endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
}

/* void menuVoos (){
    Voo voo;
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int opcao;
    cout << "Menu de Cadastro de Voos" << endl;
    cout << "1 - Cadastrar voo" << endl;
    cout << "2 - Listar voos" << endl;
    cout << "3 - Voltar" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cin.ignore();

    switch(opcao){
        case 1:
            voo.cadastroVoo();
            break;

        case 2:
            voo.listarVoo();
            system("cls");
            break;

        case 3:
            break;

        default:
            menuVoos();
            break;
    }

}*/

/* int main(){

}

 */
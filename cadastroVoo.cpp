#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "atributosVoo.h"

using namespace std;

#define MAX_VOOS 100

void menuVoos();

vector<atributosVoo>voos;

int contagemVoo = 0;
void cadastroVoo (){
    system("cls");

    if(contagemVoo >= MAX_VOOS){
        cout << "Limite de voos cadastrados atingido!" << endl;
        return;
    };

    atributosVoo voo;

    string origem, destino, data, hora;
    int codigoAviao, codigoComissario, codigoCopiloto, codigoVoo, codigoPiloto, tarifa, status;

    cout << "Informe a origem do voo:" << endl;
    getline(cin, origem);
    voo.setOrigem(origem);

    cout << "Informe o destino do voo:" << endl;
    getline(cin, destino);
    voo.setDestino(destino);

    cout << "Informe a data do voo (DD/MM/AAAA):" << endl;
    getline(cin, data);
    voo.setData(data);

    cout << "Informe horário do voo (HH:MM):" << endl;
    getline(cin, hora);
    voo.setHora(hora);

    cout << "Informe o código do avião:" << endl;
    cin >> codigoAviao;
    cin.ignore();
    voo.setCodigoAviao(codigoAviao);

    cout << "Informe o código do Piloto:" << endl;
    cin >> codigoPiloto;
    cin.ignore();
    voo.setCodigoPiloto(codigoPiloto);

    cout << "Informe o código do Copiloto:" << endl;
    cin >> codigoCopiloto;
    cin.ignore();
    voo.setCodigoCopiloto(codigoCopiloto);

    cout << "Informe o código do Comissário:" << endl;
    cin >> codigoComissario;
    cin.ignore();
    voo.setCodigoComissario(codigoComissario);

    cout << "Informe a tarifa:" << endl;
    cin >> tarifa;
    cin.ignore();
    voo.setTarifa(tarifa);

    if(codigoPiloto !=0 && codigoCopiloto !=0){
        cout << "Voo ativo" << endl;
        status = 1;
        voo.setStatus(status);
    }else{
        cout << "Voo inativo, falta piloto ou copiloto" << endl;
        status = 0;
        voo.setStatus(status);
    }

    contagemVoo++;
    voo.setCodigoVoo(contagemVoo);

    voos.push_back(voo);
    menuVoos();
}

void listarVoo(){
    system("cls");
    int opcao;
    if(contagemVoo == 0){
        cout << "Nenhum voo cadastrado" << endl;
    }else{
        for(int i = 0; i<contagemVoo; i++){
            cout << "\nInformações de Voo:" << endl;
            cout << "Código de voo: " << voos[i].getCodigoVoo() << endl;
            cout << "Local de origem: " << voos[i].getOrigem() << endl;
            cout << "Local de destino: " << voos[i].getDestino() << endl;
            cout << "Data: " << voos[i].getData() << endl;
            cout << "Horário: " << voos[i].getHora() << endl;
            cout << "Piloto: " << voos[i].getCodigoPiloto() << endl;
            cout << "Copiloto: " << voos[i].getCodigoCopiloto() << endl;
            cout << "Comissário: " << voos[i].getCodigoComissario() << endl;
        }
    }

    cout << "Pressione 'ENTER' para voltar" << endl;
    cin.get();
    menuVoos();
}

void menuVoos (){
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
            cadastroVoo();
            break;

        case 2:
            listarVoo();
            break;

        case 3:
            break;

        default:
            cout << "Opcção inválida" << endl;
            menuVoos();
            break;
    }

}

/*  int main(){
    menuVoos();
    return 0;
}*/

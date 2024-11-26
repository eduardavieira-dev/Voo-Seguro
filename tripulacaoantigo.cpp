#include "tripulacaoantigo.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


// Construtor de Tripulante
//rode no terminal: g++ -o Eduarda main.cpp tripulacao.cpp voo.cpp

Tripulante::Tripulante(const string& id_tripulante, const string& nome, const string& telefone, const string& cargo)
    : id_tripulante(id_tripulante), nome(nome), telefone(telefone), cargo(cargo) {}

// Construtor de Tripulacao
Tripulacao::Tripulacao() : contadorPiloto(1), contadorCopiloto(1), contadorComissario(1) {
    carregarDados();
}

// Método para gerar IDs únicos com base no cargo
string Tripulacao::gerarId(const string& cargo) {
    if (cargo == "Piloto") {
        return "codigoPiloto" + to_string(contadorPiloto++);
    } else if (cargo == "Copiloto") {
        return "codigoCopiloto" + to_string(contadorCopiloto++);
    } else if (cargo == "Comissario") {
        return "codigoComissario" + to_string(contadorComissario++);
    }
    return "codigoIndefinido";
}

// Método para salvar os dados no arquivo binário
void Tripulacao::salvarDados() {
    ofstream arquivo(arquivoBinario, ios::binary);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para salvar os dados.\n";
        return;
    }

    arquivo.write((char*)&contadorPiloto, sizeof(contadorPiloto));
    arquivo.write((char*)&contadorCopiloto, sizeof(contadorCopiloto));
    arquivo.write((char*)&contadorComissario, sizeof(contadorComissario));

    int tamanho = tripulantes.size();
    arquivo.write((char*)&tamanho, sizeof(tamanho));

    for (const auto& t : tripulantes) {
        size_t tamanhoId = t.id_tripulante.size();
        arquivo.write((char*)&tamanhoId, sizeof(tamanhoId));
        arquivo.write(t.id_tripulante.c_str(), tamanhoId);

        size_t tamanhoNome = t.nome.size();
        arquivo.write((char*)&tamanhoNome, sizeof(tamanhoNome));
        arquivo.write(t.nome.c_str(), tamanhoNome);

        size_t tamanhoTelefone = t.telefone.size();
        arquivo.write((char*)&tamanhoTelefone, sizeof(tamanhoTelefone));
        arquivo.write(t.telefone.c_str(), tamanhoTelefone);

        size_t tamanhoCargo = t.cargo.size();
        arquivo.write((char*)&tamanhoCargo, sizeof(tamanhoCargo));
        arquivo.write(t.cargo.c_str(), tamanhoCargo);
    }

    cout << "Dados salvos com sucesso!\n";
}

// Método para carregar os dados do arquivo binário
void Tripulacao::carregarDados() {
    ifstream arquivo(arquivoBinario, ios::binary);
    if (!arquivo) {
        cout << "Nenhum arquivo encontrado. Começando com dados vazios.\n";
        return;
    }

    arquivo.read((char*)&contadorPiloto, sizeof(contadorPiloto));
    arquivo.read((char*)&contadorCopiloto, sizeof(contadorCopiloto));
    arquivo.read((char*)&contadorComissario, sizeof(contadorComissario));

    int tamanho = 0;
    arquivo.read((char*)&tamanho, sizeof(tamanho));

    tripulantes.clear();
    for (int i = 0; i < tamanho; i++) {
        Tripulante t("", "", "", "");

        size_t tamanhoId;
        arquivo.read((char*)&tamanhoId, sizeof(tamanhoId));
        if (arquivo.eof() || tamanhoId > 1000) { // Verificação adicional para evitar excessos
            cout << "Erro ao carregar o ID do tripulante.\n";
            return;
        }
        t.id_tripulante.resize(tamanhoId);
        arquivo.read(&t.id_tripulante[0], tamanhoId);

        size_t tamanhoNome;
        arquivo.read((char*)&tamanhoNome, sizeof(tamanhoNome));
        if (arquivo.eof() || tamanhoNome > 1000) {
            cout << "Erro ao carregar o nome do tripulante.\n";
            return;
        }
        t.nome.resize(tamanhoNome);
        arquivo.read(&t.nome[0], tamanhoNome);

        size_t tamanhoTelefone;
        arquivo.read((char*)&tamanhoTelefone, sizeof(tamanhoTelefone));
        if (arquivo.eof() || tamanhoTelefone > 1000) {
            cout << "Erro ao carregar o telefone do tripulante.\n";
            return;
        }
        t.telefone.resize(tamanhoTelefone);
        arquivo.read(&t.telefone[0], tamanhoTelefone);

        size_t tamanhoCargo;
        arquivo.read((char*)&tamanhoCargo, sizeof(tamanhoCargo));
        if (arquivo.eof() || tamanhoCargo > 1000) {
            cout << "Erro ao carregar o cargo do tripulante.\n";
            return;
        }
        t.cargo.resize(tamanhoCargo);
        arquivo.read(&t.cargo[0], tamanhoCargo);

        tripulantes.push_back(t);
    }

    cout << "Dados carregados com sucesso!\n";
}


// Método para cadastrar um novo tripulante
void Tripulacao::cadastrarTripulante() {
    string nome, telefone, cargo;
    int opcao_cargo;

    cin.ignore();
    cout << "Digite o nome do tripulante: ";
    getline(cin, nome);

    cout << "Digite o telefone do tripulante: ";
    getline(cin, telefone);

    cout << "Escolha o cargo:\n1 - Piloto\n2 - Copiloto\n3 - Comissario\nOpcao: ";
    cin >> opcao_cargo;

    switch (opcao_cargo) {
        case 1: cargo = "Piloto"; break;
        case 2: cargo = "Copiloto"; break;
        case 3: cargo = "Comissario"; break;
        default: cargo = "Indefinido"; break;
    }

    Tripulante novo(gerarId(cargo), nome, telefone, cargo);
    tripulantes.push_back(novo);

    salvarDados();
    cout << "Tripulante cadastrado com sucesso! ID: " << novo.id_tripulante << endl;
}

// Método para listar todos os tripulantes
void Tripulacao::listarTripulantes() {
    if (tripulantes.empty()) {
        cout << "Nenhum tripulante cadastrado.\n";
        return;
    }

    cout << left << setw(20) << "ID"
        << setw(20) << "Nome"
        << setw(15) << "Telefone"
        << setw(15) << "Cargo" << endl;

    cout << string(20 + 20 + 15 + 15, '-') << endl;

    for (const auto& t : tripulantes) {
        cout << left << setw(20) << t.id_tripulante
             << setw(20) << t.nome
             << setw(15) << t.telefone
             << setw(15) << t.cargo << endl;
    }
}

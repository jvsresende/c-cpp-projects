#include <iostream>
#include <locale>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Funcionario {
    int id;
    string nome;
    string cargo;
    float salario;
};

void carregarDados(vector<Funcionario>& funcionarios) {
    ifstream arq("funcionarios.txt");
    if (arq.is_open()) {
        funcionarios.clear();
        string linha;
        while (getline(arq, linha)) {
            Funcionario f;
            size_t pos1 = linha.find(';');
            size_t pos2 = linha.find(';', pos1 + 1);
            size_t pos3 = linha.find(';', pos2 + 1);

            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
                continue;  // Pula linhas mal formatadas
            }

            istringstream cod(linha.substr(0, pos1));
            cod >> f.id;
            f.nome = linha.substr(pos1 + 1, pos2 - pos1 - 1);
            f.cargo = linha.substr(pos2 + 1, pos3 - pos2 - 1);
            istringstream sal(linha.substr(pos3 + 1));
            sal >> f.salario;

            funcionarios.push_back(f);
        }
        arq.close();
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}

void salvarDados(vector<Funcionario>& funcionario) {
    ofstream arq("funcionarios.txt");
    if (arq.is_open()) {
        for(int i=0;i<funcionario.size();i++){
		arq<<funcionario[i].id<<";";
		arq << funcionario[i].nome <<";";
		arq << funcionario[i].cargo << ";";
		arq << funcionario[i].salario << "\n";
	}
        arq.close();
    } else {
        cout << "Erro ao salvar funcion�rios" << endl;
    }
}

void listarFuncionarios(const vector<Funcionario>& funcionario) {
    if (funcionario.empty()) {
        cout << "Nenhum funcion�rio cadastrado!" << endl;
    } else {
        cout << "Funcion�rios Cadastrados" << endl;
        for(int i=0;i<funcionario.size();i++){
			cout<<"--------------------"<<endl;
			cout<<"ID: "<<funcionario[i].id<<endl<<endl;
			cout<<"Nome: "<<funcionario[i].nome<<endl;
			cout<<"Cargo: "<<funcionario[i].cargo<<endl;
			cout<<"Sal�rio: "<<funcionario[i].salario<<endl;
			cout<<"--------------------"<<endl;
		};
    }
}

void cadastrarFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario f;
    cout << "------Cadastrar Funcion�rio------" << endl;
    cout << "Digite o ID: ";
    cin >> f.id;
    cin.ignore();
    cout << "Digite o Nome: ";
    getline(cin, f.nome);
    cout << "Digite o Cargo: ";
    getline(cin, f.cargo);
    cout << "Digite o Sal�rio: ";
    cin >> f.salario;
    funcionarios.push_back(f);
    cout << "Cadastro realizado com sucesso!" << endl;
}

void aumentarSalario(vector<Funcionario>& funcionarios) {
    if (funcionarios.empty()) {
        cout << "Sem funcion�rios cadastrados!" << endl;
        return;
    }

    int codigo;
    float percentual;
    bool encontrado = false;

    cout << "Digite o ID do funcion�rio que deseja aumentar o sal�rio: ";
    cin >> codigo;

    for (int i=0;i<funcionarios.size();i++) {
        if (funcionarios[i].id == codigo) {
            encontrado = true;
            cout << "Digite o percentual de aumento (Sal�rio atual: $" << funcionarios[i].salario << "): ";
            cin >> percentual;
            funcionarios[i].salario += funcionarios[i].salario * (percentual / 100);
            salvarDados(funcionarios);
            cout << "Novo sal�rio registrado!" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Funcion�rio n�o encontrado!" << endl;
    }
}

void cargoDefinido(const vector<Funcionario>& funcionarios) {
    if (funcionarios.empty()) {
        cout << "Nenhum funcion�rio cadastrado!" << endl;
        return;
    }

    string cargo;
    cout << "Digite o cargo que deseja consultar: ";
    cin.ignore();
    getline(cin, cargo);

    cout << "Funcion�rios com cargo: " << cargo << endl;
    for (int i=0;i<funcionarios.size();i++) {
        if (funcionarios[i].cargo == cargo) {
            cout << "--------------------" << endl;
            cout << "ID: " << funcionarios[i].id << endl;
            cout << "Nome: " << funcionarios[i].nome << endl;
            cout << "Sal�rio: " << funcionarios[i].salario << endl;
            cout << "--------------------" << endl;
        }
    }
}

void maiorSalario(const vector<Funcionario>& funcionarios) {
    if (funcionarios.empty()) {
        cout << "Nenhum funcion�rio cadastrado!" << endl;
        return;
    }

   float valor = -1;
	int codigo;
	if(funcionarios.empty()){
		cout<<"Nenhum funcion�rio cadastradi!"<<endl;
	}else
	{
		for(int i=0;i<funcionarios.size();i++){
			if(funcionarios[i].salario>valor){
				valor=funcionarios[i].salario;
				codigo = funcionarios[i].id;
			}
		}
		cout<<"O funcion�rio com Maior Sal�rio �:"<<endl;
		cout<<"--------------------"<<endl;
			cout<<"ID: "<<funcionarios[codigo].id<<endl<<endl;
			cout<<"Nome: "<<funcionarios[codigo].nome<<endl;
			cout<<"CarcargoDefinidogo: "<<funcionarios[codigo].cargo<<endl;
			cout<<"Sal�rio: "<<funcionarios[codigo].salario<<endl;
			cout<<"--------------------"<<endl;
}
}

void mediaSalario(const vector<Funcionario>& funcionario) {
    if (funcionario.empty()) {
        cout << "Nenhum funcion�rio cadastrado!" << endl;
        return;
    }

    float total = 0;
    for (int i=0;i<funcionario.size();i++) {
        total += funcionario[i].salario;
    }

    cout << "A m�dia salarial dos funcion�rios �: $" << total / funcionario.size() << endl;
}

void menu2() {
    cout << "-------Consultas---------" << endl;
    cout << "1 - Listar funcion�rios por cargo" << endl;
    cout << "2 - Exibir funcion�rio com maior sal�rio" << endl;
    cout << "3 - Exibir m�dia salarial de todos os funcion�rios" << endl;
    cout << "4 - Voltar ao menu principal" << endl;
    cout << "Qual consulta gostaria de realizar? ";
}

int main() {
    setlocale(LC_ALL, "portuguese");
    vector<Funcionario> funcionarios;
    carregarDados(funcionarios);
    int opc, opc2;

    do {
        cout << "------ MENU --------" << endl;
        cout << "1 - Cadastrar Funcion�rio" << endl;
        cout << "2 - Listar Funcion�rios" << endl;
        cout << "3 - Aumentar sal�rio" << endl;
        cout << "4 - Consultas" << endl;
        cout << "5 - Salvar e Sair" << endl;
        cout << "Digite sua op��o: ";
        cin >> opc;

        switch (opc) {
            case 1: cadastrarFuncionario(funcionarios); break;
            case 2: listarFuncionarios(funcionarios); break;
            case 3: aumentarSalario(funcionarios); break;
            case 4: menu2(); cin >> opc2;
                if (opc2 == 1) cargoDefinido(funcionarios);
                else if (opc2 == 2) maiorSalario(funcionarios);
                else if (opc2 == 3) mediaSalario(funcionarios);
                break;
            case 5: salvarDados(funcionarios); break;
        }
    } while (opc != 5);

    return 0;
}

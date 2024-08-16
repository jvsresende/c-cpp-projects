/*
Trabalho de C++ feito por Jo�o V�ctor Souza Resende e Gustavo Amaral.
Este c�digo emula um sistema de padaria sem banco de dados, contando com as fun��es de 
cadastrar, pesquisar, alterar, excluir e visualizar todos os dados alocados nos vetores.
Possui as cores roxo e branco como padr�o e mensagens de erro em vermelho e preto.
Al�m disso, tamb�m possui alguns metodos de verifica��o para evitar cadastramento repetido de c�digo e exclus�o errada
de dados.
*/
#include <iostream>//biblioteca padr�o
using namespace std;//facilitar o uso de cout, cin e vetores
#include <locale>//usa para configurar a regi�o e linguagem
#include <windows.h>//usado para acessar as fun��es do windows
#include <cctype>//manipula��o de caracteres, para conversao de minusculas
#include <algorithm>//fun��es genericas tipo trasnform

struct Produto//estrutura dos dados do produto
{
	int codigo;//codigo do produto
	int estoque;//estoque do produto
	float preco;//pre�o do produto
	string nome, descricao;//nome e descri��o do produto
};

void setColor(int textColor, int backgroundColor)   // void para mudar cor do texto e fundo
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}
string toLowerCase(const string& str)//fun��o para transformar o texto em letras minusculas
{
	string result = str;
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

int main()
{
	setlocale(LC_ALL, "portuguese");
	int opc = 0;
//   codigo pesquisa, codigo altera��o, estoque altera��o, codigo do produto a ser alterado, codigo para exclus�o e codigo para cadastro
	int codigop, codigoa, estoquea, alterar, codigoe, codigo;
	//valor para altera��o
	float valora;
	//nome para pesquisa, altera��o e descri��o altera��o
	string nomep, nomea, descricaoa;
	//escolha do tipo de pesquisa, escolha do que deseja alterar
	char tipo, desejado;
	//usado para definir se ir� ou n�o mostrar que algo n�o foi encontrado
	bool encontrado = false;
	//valor das cores
	int textColor = 0;       // Preto
	int backgroundColor = 4; // Vermelho
	//tamanho do vetor
	int qtd = 5;
	Produto produtos[qtd];//vetor com base no struct Produto

	//dados pr�-cadastrados
	
	produtos[0] = {1, 3, 5.4, "Pao de Queijo", "P�o de Queijo feito com amor e carinho e queijo canastra"};
	produtos[1] = {3, 6, 10.8, "Bolo de Chocolate", "Delicioso e Macio Bolo de Chocolate"};
	produtos[2] = {6, 9, 16.2, "Combo Coxinhas com Coca", "Combo com 10 coxinhas e uma lata de coca-cola de 350ml"};
	
	do//Menu e inicio da repeti��o
	{
		system("cls");//limpa a tela a cada nova repeti��o
		system("color 5f");
		cout << "\n\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|\tBEM-VINDO a PadPadaria!!!   |\n";
		cout << "\t\t\t\t|---ONDE A SUA FOME, A GENTE MATA---|\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   1) Cadastrar Produto/Servi�o    |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   2) Pesquisar Produto/Servi�o    |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   3) Alterar Produto/Servi�o      |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   4) Excluir Produto/Servi�o      |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   5) Mostrar Produtos/Servi�o     |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   0) Sair                         |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t";
		cin >> opc;
		cout << endl;
		switch (opc)
		{
		case 1: //Cadastro
			for(int i = 0; i < qtd; i++)
			{
				if(produtos[i].nome == "")//verifica��o se o vetor est� vazio
				{
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-------CADASTRO DE PRODUTOS:-------|\n";
					cout << "\t\t\t\t|-----------------------------------|\n\n";
					bool codigoExistente = false;
					do
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|---------INFORME O C�DIGO:---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> codigo;

						codigoExistente = false; // Presume que o c�digo n�o existe

						// Verifica se o c�digo j� foi cadastrado
						for (int j = 0; j < qtd; j++)
						{
							if (codigo == produtos[j].codigo)//verifica se o c�digo existe
							{
								cout << "\t\t\t\t|-----------------------------------|\n";
								cout << "\t\t\t\t|C�DIGO J� EXISTE! Digite Novamente:|\n";
								cout << "\t\t\t\t|-----------------------------------|\n";
								codigoExistente = true;
								// Interrompe o loop interno e pede um novo c�digo
								break;
							}
						}
					}
					while(codigoExistente);
					produtos[i].codigo = codigo;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|----------INFORME O NOME:----------|\n";
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin.ignore();
					getline(cin, produtos[i].nome);
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|--------INFORME A DESCRI��O:-------|\n";
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin.ignore();
					getline(cin, produtos[i].descricao);
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|---------INFORME O PRE�O:----------|\n";
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin >> produtos[i].preco;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|--INFORME A QUANTIDADE NO ESTOQUE:-|\n";
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin >> produtos[i].estoque;
					break;
				}
			}
			break;
		case 2://Pesquisa
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|--SELECIONE O M�TODO DE PESQUISA:--|\n";//escolha do tipo de pesquisa
			cout << "\t\t\t\t|------(N - NOME, C - CODIGO)-------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t";
			cin >> tipo;
			if(tipo == 'c' || tipo == 'C')//vers�o c�digo
			{
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|---QUAL O C�DIGO PARA PESQUISA:----|\n";//Digite o c�digo de pesquisa
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t";
				cin >> codigop;
				for(int i = 0; i < qtd; i++)
				{
					if(codigop == produtos[i].codigo)//verifica��o se o c�digo est� cadastrado
					{
						encontrado = true;//define que o c�digo foi cadastrado
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|---------C�DIGO ENCONTRADO---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   C�DIGO: " << produtos[i].codigo << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;//mostra o c�digo
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   DESCRI��O: " << produtos[i].descricao << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   PRE�O: " << produtos[i].preco << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						Sleep(2000);
						break;
					}
				};
				if(!encontrado)//vers�o que o c�digo n�o foi encontrado
				{
					setColor(textColor, backgroundColor);
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-------C�DIGO N�O ENCONTRADO=------|\n" ;
					cout << "\t\t\t\t|-----------------------------------|\n" << endl;
					Sleep(1000);
				}
				encontrado = false;
				break;
			}
			else if(tipo == 'n' || tipo == 'N')//vers�o nome
			{
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|----QUAL O NOME PARA PESQUISA:-----|\n";//Digite o nome para pesquisa
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t";
				cin.ignore();
				getline(cin, nomep);
				string nomepLower = toLowerCase(nomep);//transforma para letras minusculas
				for(int i = 0; i < qtd; i++)
				{
					string nomeProdutoLower = toLowerCase(produtos[i].nome);//transforma o nome alocado para letras minusculas
					if(nomepLower == nomeProdutoLower)//verifica se existe o nome
					{
						encontrado = true;//define que o nome foi cadastrado
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|----------NOME ENCONTRADO----------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   C�DIGO: " << produtos[i].codigo << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";//mostra o nome
						cout << "\t\t\t\t   DESCRI��O: " << produtos[i].descricao << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   PRE�O: " << produtos[i].preco << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";

					}
				}
				if(!encontrado)//vers�o que o nome n�o foi encontrado
				{
					setColor(textColor, backgroundColor);
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|--------NOME N�O ENCONTRADO--------|\n" ;
					cout << "\t\t\t\t|-----------------------------------|\n" << endl;
					Sleep(1000);
				}
				encontrado = false;
				break;
			}
			else//vers�o em que outra letra foi digitada
			{
				setColor(textColor, backgroundColor);//muda cor do fundo e texto
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|----------Letra Inv�lida-----------|" ;
				cout << "\t\t\t\t|-----------------------------------|\n" << endl;
				Sleep(1000);//espera um segundo at� aparecer o menu novamente
			}
			break;

		case 3://Altera��o
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|-------------ALTERA��O-------------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|----INSIRA O C�DIGO DO PRODUTO:----|\n";
			cout << "\t\t\t\t";
			cin >> alterar;
			for(int i = 0; i < qtd; i++)
			{
				if(alterar == produtos[i].codigo)
				{
					encontrado = true;//define que o c�digo existe
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-------O QUE DESEJA ALTERAR?-------|\n";
					cout << "\t\t\t\t|N - Nome, C - C�digo, D - Descri��o|\n";//seleciona o que ir� ser alterado
					cout << "\t\t\t\t|-----Q - Quantidade, P - Pre�o-----|\n";
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin >> desejado;
					if(desejado == 'N' || desejado == 'n')//altera��o do nome
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|---------QUAL O NOVO NOME?---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin.ignore();
						getline(cin, produtos[i].nome);
						break;
					}
					else if(desejado == 'C' || desejado == 'c')//altera��o do c�digo
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|--------QUAL O NOVO C�DIGO?--------| \n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> produtos[i].codigo;
						break;
					}
					else if(desejado == 'D' || desejado == 'd')//altera��o da descri��o
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|------QUAL A NOVA DESCRI��O?-------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin.ignore();
						getline(cin, produtos[i].descricao);
						break;
					}
					else if(desejado == 'Q' || desejado == 'q')//altera��o do estoque
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|------QUAL A NOVA QUANTIDADE?------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> produtos[i].estoque;
						break;
					}
					else if(desejado == 'P' || desejado == 'p')//altera��o do pre�o
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|--------QUAL O NOVO VALOR?---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> produtos[i].preco;
						break;
					}
					else
					{
						setColor(textColor, backgroundColor);//muda cor do fundo e texto
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|---------OP��O INV�LIDA!!!---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						Sleep(1000);//espera um segundo at� o menu ser mostrado novamente
						break;
					}
				}

			}
			if(!encontrado)//c�digo n�o foi encontrado
			{
				setColor(textColor, backgroundColor);
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|-------C�DIGO N�O ENCONTRADO=------|\n" ;
				cout << "\t\t\t\t|-----------------------------------|\n" << endl;
				Sleep(1000);
			}
			encontrado = false;
			break;
		case 4://Exclus�o
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|----QUAL O C�DIGO PARA REALIZAR----|\n";//digite o codigo para exclusao do produto
			cout << "\t\t\t\t|-------A EXCLUS�O DOS DADOS?-------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t";
			cin >> codigoe;
			char escolha;
			for(int i = 0; i < qtd; i++)
			{
				if(codigoe == produtos[i].codigo)//compara se o c�digo existe
				{
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   C�DIGO: " << produtos[i].codigo << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   DESCRI��O: " << produtos[i].descricao << endl;//mostra as informa��es que est�o no c�digo
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   PRE�O: " << produtos[i].preco << endl << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-DESEJA EXCLUIR ESTAS INFORMA��ES?-|\n";
					cout << "\t\t\t\t|---------S - SIM e N - N�O---------|\n";//confirma a exclus�o
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin >> escolha;

					if(escolha == 's' || escolha == 'S')//compara se o usuario confirmou
					{
						encontrado = true;///define que foi encontrado
						produtos[i].codigo = 0;
						produtos[i].descricao = "";
						produtos[i].nome = "";
						produtos[i].preco = 0;
						produtos[i].estoque = 0;
						setColor(textColor, backgroundColor);//muda cor do fundo e texto
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|-EXCLUS�O REALIZADA COM SUCESSO!!!-|\n";//mostra a mensagem
						cout << "\t\t\t\t|-----------------------------------|\n";
						Sleep(1000);//espera um segundo at� aparecer novamente o menu
						break;
					}
					else if(escolha == 'n' || escolha == 'N')//compara se o usuario negou
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|-----DIGITE O C�DIGO NOVAMENTE:----|\n";//pede para digitar novamente
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> codigoe;
						i = -1;
					}
				}
				encontrado = false;
			}
			if(!encontrado)
			{
				setColor(textColor, backgroundColor);//muda cor do texto e fundo
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|----CADASTRO N�O ENCONTRADO!!!-----|\n";
				cout << "\t\t\t\t|-----------------------------------|\n";
			}
			Sleep(1000);//espera um segundo at� o menu ser mostrado novamente

			break;
		case 5://Mostra Todos os Dados Cadastrados
			for(int i = 0; i < qtd; i++)
			{
				if(produtos[i].nome != "")//confere se o vetor n�o est� vazio
				{
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   C�DIGO: " << produtos[i].codigo << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   DESCRI��O: " << produtos[i].descricao << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   PRE�O: " << produtos[i].preco << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << endl << endl;
					encontrado = true;
				}

			};
			if(!encontrado)
			{
				setColor(textColor, backgroundColor);//muda cor do texto e fundo
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|----CADASTRO N�O ENCONTRADO!!!-----|\n";
				cout << "\t\t\t\t|-----------------------------------|\n";
			}else{
				Sleep(5000);
			}
			Sleep(1000);//espera um segundo at� o menu ser mostrado novamente
			encontrado=false;
			break;
		case 0://Sair do Programa
			setColor(textColor, backgroundColor);
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|-------Saindo do Programa!!!-------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n"<< endl;
			break;
		default://Op��o Inv�lida caso a pessoa digite qualquer n�mero que n�o seja entre 0 e 5
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 236);
			setColor(textColor, backgroundColor);//muda cor do fundo e texto
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|---------Op��o Inv�lida!!!---------|\n" ;
			cout << "\t\t\t\t|-----------------------------------|\n" << endl;
			Sleep(1000);//espera um segundo para aparecer o menu novamente
			break;
		}
	}
	while(opc != 0);//finaliza a repeti��o se o n�mero digitado for igual a zero

	return 0;
}

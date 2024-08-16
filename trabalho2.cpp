/*
Trabalho de C++ feito por João Víctor Souza Resende e Gustavo Amaral.
Este código emula um sistema de padaria sem banco de dados, contando com as funções de 
cadastrar, pesquisar, alterar, excluir e visualizar todos os dados alocados nos vetores.
Possui as cores roxo e branco como padrão e mensagens de erro em vermelho e preto.
Além disso, também possui alguns metodos de verificação para evitar cadastramento repetido de código e exclusão errada
de dados.
*/
#include <iostream>//biblioteca padrão
using namespace std;//facilitar o uso de cout, cin e vetores
#include <locale>//usa para configurar a região e linguagem
#include <windows.h>//usado para acessar as funções do windows
#include <cctype>//manipulação de caracteres, para conversao de minusculas
#include <algorithm>//funções genericas tipo trasnform

struct Produto//estrutura dos dados do produto
{
	int codigo;//codigo do produto
	int estoque;//estoque do produto
	float preco;//preço do produto
	string nome, descricao;//nome e descrição do produto
};

void setColor(int textColor, int backgroundColor)   // void para mudar cor do texto e fundo
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}
string toLowerCase(const string& str)//função para transformar o texto em letras minusculas
{
	string result = str;
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

int main()
{
	setlocale(LC_ALL, "portuguese");
	int opc = 0;
//   codigo pesquisa, codigo alteração, estoque alteração, codigo do produto a ser alterado, codigo para exclusão e codigo para cadastro
	int codigop, codigoa, estoquea, alterar, codigoe, codigo;
	//valor para alteração
	float valora;
	//nome para pesquisa, alteração e descrição alteração
	string nomep, nomea, descricaoa;
	//escolha do tipo de pesquisa, escolha do que deseja alterar
	char tipo, desejado;
	//usado para definir se irá ou não mostrar que algo não foi encontrado
	bool encontrado = false;
	//valor das cores
	int textColor = 0;       // Preto
	int backgroundColor = 4; // Vermelho
	//tamanho do vetor
	int qtd = 5;
	Produto produtos[qtd];//vetor com base no struct Produto

	//dados pré-cadastrados
	
	produtos[0] = {1, 3, 5.4, "Pao de Queijo", "Pão de Queijo feito com amor e carinho e queijo canastra"};
	produtos[1] = {3, 6, 10.8, "Bolo de Chocolate", "Delicioso e Macio Bolo de Chocolate"};
	produtos[2] = {6, 9, 16.2, "Combo Coxinhas com Coca", "Combo com 10 coxinhas e uma lata de coca-cola de 350ml"};
	
	do//Menu e inicio da repetição
	{
		system("cls");//limpa a tela a cada nova repetição
		system("color 5f");
		cout << "\n\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|\tBEM-VINDO a PadPadaria!!!   |\n";
		cout << "\t\t\t\t|---ONDE A SUA FOME, A GENTE MATA---|\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   1) Cadastrar Produto/Serviço    |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   2) Pesquisar Produto/Serviço    |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   3) Alterar Produto/Serviço      |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   4) Excluir Produto/Serviço      |\n";
		cout << "\t\t\t\t|-----------------------------------|\n";
		cout << "\t\t\t\t|   5) Mostrar Produtos/Serviço     |\n";
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
				if(produtos[i].nome == "")//verificação se o vetor está vazio
				{
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-------CADASTRO DE PRODUTOS:-------|\n";
					cout << "\t\t\t\t|-----------------------------------|\n\n";
					bool codigoExistente = false;
					do
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|---------INFORME O CÓDIGO:---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> codigo;

						codigoExistente = false; // Presume que o código não existe

						// Verifica se o código já foi cadastrado
						for (int j = 0; j < qtd; j++)
						{
							if (codigo == produtos[j].codigo)//verifica se o código existe
							{
								cout << "\t\t\t\t|-----------------------------------|\n";
								cout << "\t\t\t\t|CÓDIGO JÁ EXISTE! Digite Novamente:|\n";
								cout << "\t\t\t\t|-----------------------------------|\n";
								codigoExistente = true;
								// Interrompe o loop interno e pede um novo código
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
					cout << "\t\t\t\t|--------INFORME A DESCRIÇÃO:-------|\n";
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin.ignore();
					getline(cin, produtos[i].descricao);
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|---------INFORME O PREÇO:----------|\n";
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
			cout << "\t\t\t\t|--SELECIONE O MÉTODO DE PESQUISA:--|\n";//escolha do tipo de pesquisa
			cout << "\t\t\t\t|------(N - NOME, C - CODIGO)-------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t";
			cin >> tipo;
			if(tipo == 'c' || tipo == 'C')//versão código
			{
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|---QUAL O CÓDIGO PARA PESQUISA:----|\n";//Digite o código de pesquisa
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t";
				cin >> codigop;
				for(int i = 0; i < qtd; i++)
				{
					if(codigop == produtos[i].codigo)//verificação se o código está cadastrado
					{
						encontrado = true;//define que o código foi cadastrado
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|---------CÓDIGO ENCONTRADO---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   CÓDIGO: " << produtos[i].codigo << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;//mostra o código
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   DESCRIÇÃO: " << produtos[i].descricao << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   PREÇO: " << produtos[i].preco << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						Sleep(2000);
						break;
					}
				};
				if(!encontrado)//versão que o código não foi encontrado
				{
					setColor(textColor, backgroundColor);
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-------CÓDIGO NÃO ENCONTRADO=------|\n" ;
					cout << "\t\t\t\t|-----------------------------------|\n" << endl;
					Sleep(1000);
				}
				encontrado = false;
				break;
			}
			else if(tipo == 'n' || tipo == 'N')//versão nome
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
						cout << "\t\t\t\t   CÓDIGO: " << produtos[i].codigo << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";//mostra o nome
						cout << "\t\t\t\t   DESCRIÇÃO: " << produtos[i].descricao << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t   PREÇO: " << produtos[i].preco << endl;
						cout << "\t\t\t\t|-----------------------------------|\n";

					}
				}
				if(!encontrado)//versão que o nome não foi encontrado
				{
					setColor(textColor, backgroundColor);
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|--------NOME NÃO ENCONTRADO--------|\n" ;
					cout << "\t\t\t\t|-----------------------------------|\n" << endl;
					Sleep(1000);
				}
				encontrado = false;
				break;
			}
			else//versão em que outra letra foi digitada
			{
				setColor(textColor, backgroundColor);//muda cor do fundo e texto
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|----------Letra Inválida-----------|" ;
				cout << "\t\t\t\t|-----------------------------------|\n" << endl;
				Sleep(1000);//espera um segundo até aparecer o menu novamente
			}
			break;

		case 3://Alteração
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|-------------ALTERAÇÃO-------------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|----INSIRA O CÓDIGO DO PRODUTO:----|\n";
			cout << "\t\t\t\t";
			cin >> alterar;
			for(int i = 0; i < qtd; i++)
			{
				if(alterar == produtos[i].codigo)
				{
					encontrado = true;//define que o código existe
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-------O QUE DESEJA ALTERAR?-------|\n";
					cout << "\t\t\t\t|N - Nome, C - Código, D - Descrição|\n";//seleciona o que irá ser alterado
					cout << "\t\t\t\t|-----Q - Quantidade, P - Preço-----|\n";
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t";
					cin >> desejado;
					if(desejado == 'N' || desejado == 'n')//alteração do nome
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|---------QUAL O NOVO NOME?---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin.ignore();
						getline(cin, produtos[i].nome);
						break;
					}
					else if(desejado == 'C' || desejado == 'c')//alteração do código
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|--------QUAL O NOVO CÓDIGO?--------| \n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> produtos[i].codigo;
						break;
					}
					else if(desejado == 'D' || desejado == 'd')//alteração da descrição
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|------QUAL A NOVA DESCRIÇÃO?-------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin.ignore();
						getline(cin, produtos[i].descricao);
						break;
					}
					else if(desejado == 'Q' || desejado == 'q')//alteração do estoque
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|------QUAL A NOVA QUANTIDADE?------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t";
						cin >> produtos[i].estoque;
						break;
					}
					else if(desejado == 'P' || desejado == 'p')//alteração do preço
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
						cout << "\t\t\t\t|---------OPÇÃO INVÁLIDA!!!---------|\n";
						cout << "\t\t\t\t|-----------------------------------|\n";
						Sleep(1000);//espera um segundo até o menu ser mostrado novamente
						break;
					}
				}

			}
			if(!encontrado)//código não foi encontrado
			{
				setColor(textColor, backgroundColor);
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|-------CÓDIGO NÃO ENCONTRADO=------|\n" ;
				cout << "\t\t\t\t|-----------------------------------|\n" << endl;
				Sleep(1000);
			}
			encontrado = false;
			break;
		case 4://Exclusão
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|----QUAL O CÓDIGO PARA REALIZAR----|\n";//digite o codigo para exclusao do produto
			cout << "\t\t\t\t|-------A EXCLUSÃO DOS DADOS?-------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t";
			cin >> codigoe;
			char escolha;
			for(int i = 0; i < qtd; i++)
			{
				if(codigoe == produtos[i].codigo)//compara se o código existe
				{
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   CÓDIGO: " << produtos[i].codigo << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   DESCRIÇÃO: " << produtos[i].descricao << endl;//mostra as informações que estão no código
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   PREÇO: " << produtos[i].preco << endl << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t|-DESEJA EXCLUIR ESTAS INFORMAÇÕES?-|\n";
					cout << "\t\t\t\t|---------S - SIM e N - NÃO---------|\n";//confirma a exclusão
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
						cout << "\t\t\t\t|-EXCLUSÃO REALIZADA COM SUCESSO!!!-|\n";//mostra a mensagem
						cout << "\t\t\t\t|-----------------------------------|\n";
						Sleep(1000);//espera um segundo até aparecer novamente o menu
						break;
					}
					else if(escolha == 'n' || escolha == 'N')//compara se o usuario negou
					{
						cout << "\t\t\t\t|-----------------------------------|\n";
						cout << "\t\t\t\t|-----DIGITE O CÓDIGO NOVAMENTE:----|\n";//pede para digitar novamente
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
				cout << "\t\t\t\t|----CADASTRO NÃO ENCONTRADO!!!-----|\n";
				cout << "\t\t\t\t|-----------------------------------|\n";
			}
			Sleep(1000);//espera um segundo até o menu ser mostrado novamente

			break;
		case 5://Mostra Todos os Dados Cadastrados
			for(int i = 0; i < qtd; i++)
			{
				if(produtos[i].nome != "")//confere se o vetor não está vazio
				{
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   CÓDIGO: " << produtos[i].codigo << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   NOME: " << produtos[i].nome << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   DESCRIÇÃO: " << produtos[i].descricao << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   QUANTIDADE NO ESTOQUE: " << produtos[i].estoque << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << "\t\t\t\t   PREÇO: " << produtos[i].preco << endl;
					cout << "\t\t\t\t|-----------------------------------|\n";
					cout << endl << endl;
					encontrado = true;
				}

			};
			if(!encontrado)
			{
				setColor(textColor, backgroundColor);//muda cor do texto e fundo
				cout << "\t\t\t\t|-----------------------------------|\n";
				cout << "\t\t\t\t|----CADASTRO NÃO ENCONTRADO!!!-----|\n";
				cout << "\t\t\t\t|-----------------------------------|\n";
			}else{
				Sleep(5000);
			}
			Sleep(1000);//espera um segundo até o menu ser mostrado novamente
			encontrado=false;
			break;
		case 0://Sair do Programa
			setColor(textColor, backgroundColor);
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|-------Saindo do Programa!!!-------|\n";
			cout << "\t\t\t\t|-----------------------------------|\n"<< endl;
			break;
		default://Opção Inválida caso a pessoa digite qualquer número que não seja entre 0 e 5
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 236);
			setColor(textColor, backgroundColor);//muda cor do fundo e texto
			cout << "\t\t\t\t|-----------------------------------|\n";
			cout << "\t\t\t\t|---------Opção Inválida!!!---------|\n" ;
			cout << "\t\t\t\t|-----------------------------------|\n" << endl;
			Sleep(1000);//espera um segundo para aparecer o menu novamente
			break;
		}
	}
	while(opc != 0);//finaliza a repetição se o número digitado for igual a zero

	return 0;
}

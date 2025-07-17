#include <stdio.h>
#include <stdlib.h>
#define colunas 51
#define nProvas 3
struct tipoAluno
{
	char nome[colunas];
	float notas[nProvas];
	struct tipoAluno *ptrProximo;
};

int compara(char *, char *);
char * funcao2(char *, char *);
struct tipoAluno * funcao(struct tipoAluno *);
struct tipoAluno * limpa(struct tipoAluno *);
void imprime(struct tipoAluno *);
struct tipoAluno * excluir(struct tipoAluno *);

char * funcao2(char *s1,char *s2)//copia
{
	char *enderecoInicial=s1;
	while(*s2!='\0')
	{
		*s1=*s2;
		++s1;
		++s2;
	}
	return(enderecoInicial);
}

struct tipoAluno *funcao(struct tipoAluno *aluno)// ordem alfabetica
{
	char nome[colunas];
	int i;
	struct tipoAluno *novo;
	printf("\nDIGITE O NOME:");
	fgets(nome, colunas, stdin);
	setbuf(stdin,'\0');
	struct tipoAluno *anterior=NULL;
	struct tipoAluno *percorrer=aluno;
	while(percorrer!=NULL && compara(percorrer->nome, nome)<0)
	{
		anterior=percorrer;
		percorrer=percorrer->ptrProximo;
	}
	novo=(struct tipoAluno *)malloc(sizeof(struct tipoAluno));
	funcao2(novo->nome, nome);
	for(i=0; i<nProvas; i++) {
		printf("Nota %d: ", i + 1);
		scanf("%f",&novo->notas[i]);
	}
	setbuf(stdin,NULL);
	if(anterior==NULL)
	{
		novo->ptrProximo=aluno;
		aluno=novo;
	}
	else
	{
		novo->ptrProximo=anterior->ptrProximo;
		anterior->ptrProximo=novo;
	}
	return(aluno);
}


int compara(char *s1, char *s2)
{
	int i=0;
	while(*(s1+i)==*(s2+i))
	{
		if(*(s1+i)=='\0')
			return(0);
		i++;
	}
	return(s1[i]-s2[i]);
}

//funcao de limpar que mostra a mensagem de lista vazia
struct tipoAluno *limpa(struct tipoAluno *aluno) {
	aluno=NULL;
	printf("\nLista Limpa com Sucesso!!!");
	return aluno;
}

void imprime(struct tipoAluno *al) {
	int i;
	if(al==NULL) {
		printf("\nLista Vazia!!!");
	}
	while(al!=NULL) {
		printf("\nNome do Aluno: %s",al->nome);
		for(i=0; i<nProvas; i++) {
			printf("\nNota da Prova %i: %.2f\n",i+1,al->notas[i]);
		}
		al=al->ptrProximo;
	}
}

struct tipoAluno * excluir(struct tipoAluno *aluno) {
	char busca[colunas];
	printf("\nDigite o nome do aluno que queira excluir:");
	fgets(busca,colunas,stdin);
	setbuf(stdin,NULL);
	struct tipoAluno *atual = aluno;
	struct tipoAluno  *anterior = NULL;
	while(atual!=NULL) {//verifica se alu nao esta vazio
		if(compara(atual->nome,busca)==0) {
			if(anterior==NULL){
			    aluno = atual->ptrProximo;
			}else{
			    anterior->ptrProximo=atual->ptrProximo;
			}
			free(atual);
			printf("\n Aluno excluido com Sucesso!!!");
			return (aluno);
		}
		anterior=atual;
		atual=atual->ptrProximo;
	}
	
	printf("\nAluno Nao Cadastrado");
	return(aluno);
}

int main()
{
	int opc;
	struct tipoAluno *lAluno;
	lAluno = NULL;
	while(opc!=5) {
		printf("\n---Bem-Vindo ao Menu---");
		printf("\n1- Inserir Aluno");
		printf("\n2- Imprimir Lista");
		printf("\n3- Esvaziar Lista");
		printf("\n4- Excluir Aluno");
		printf("\n5- Sair");
		printf("\nDigite sua opcao:\n");
		scanf("%d",&opc);
		setbuf(stdin,NULL);
		switch(opc) {
		case 1:
			lAluno=funcao(lAluno);
			break;
		case 2:
			imprime(lAluno);
			break;
		case 3:
			lAluno=limpa(lAluno);
			break;
		case 4:
			lAluno=excluir(lAluno);
			break;
		case 5:
			printf("\n---Sair do Programa!!!---\n");
			break;
		default:
			printf("\nOpcao Invalida!!!");
			break;
		}
	}


	return 0;
}

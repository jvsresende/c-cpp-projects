#include <stdio.h>
#include <stdlib.h>
#define nProvas 3
#define nColunas 51

typedef struct tAluno {
	char nome[nColunas];
	float notas[nProvas];
	struct tAluno *proximo;
} tAluno;

typedef struct {
	tAluno *topo;
} Pilha;

void inicializarPilha(Pilha *p);
int pilhaVazia(Pilha *p);
void empilhar(Pilha *p);
tAluno * desempilhar(Pilha *p);
void consultarTopo(Pilha *p);
void esvaziarPilha(Pilha *p);
void imprimirPilha(Pilha *p);
char * funcao2(char *,char *);

int main()
{
	int opc;
	Pilha p;
	inicializarPilha(&p);
	while(opc!=6) {
		printf("\n---Bem-Vindo ao Menu---");
		printf("\n1- Inserir Aluno");
		printf("\n2- Imprimir Pilha");
		printf("\n3- Esvaziar Pilha");
		printf("\n4- Excluir Primeiro Aluno Adicionado");
		printf("\n5- Consultar Topo da Pilha");
		printf("\n6- Sair");
		printf("\nDigite sua opcao:\n");
		scanf("%d",&opc);
		setbuf(stdin,NULL);
		switch(opc) {
		case 1:
			empilhar(&p);
			break;
		case 2:
			imprimirPilha(&p);
			break;
		case 3:
			esvaziarPilha(&p);
			break;
		case 4:
			desempilhar(&p);
			break;
		case 5:
			consultarTopo(&p);
			break;
		case 6:
			printf("\n---Sair do Programa!!!---\n");
			break;
		default:
			printf("\nOpcao Invalida!!!");
			break;
		}
	}
	return 0;
}

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

void inicializarPilha(Pilha *p) {
	p->topo=NULL;
}

int pilhaVazia(Pilha *p) {
	return p->topo==NULL;
}

void empilhar(Pilha *p) {
	tAluno *novo=(tAluno*)malloc(sizeof(tAluno));
	if(novo==NULL) {
		printf("Erro de alocacao de memoria!");
		exit(1);
	}
	printf("\nDigite o nome: ");
	fgets(novo->nome,nColunas,stdin);
	setbuf(stdin,NULL);
	for(int i=0; i<nProvas; i++) {
		printf("\nDigite a nota da prova %d:",i+1);
		scanf("%f",&novo->notas[i]);
		setbuf(stdin,NULL);
	}
	novo->proximo = p->topo;
	p->topo=novo;
}

tAluno * desempilhar(Pilha *p) {
	if(pilhaVazia(p)) {
		printf("Pilha Vazia!\n");
	}
	tAluno *temp=p->topo;
	tAluno *removido=(tAluno*)malloc(sizeof(tAluno));
	funcao2(removido->nome,temp->nome);
	for(int i=0; i<nProvas; i++) {
		removido->notas[i]=temp->notas[i];
	}
	p->topo = temp->proximo;
	free(temp);
	return removido;
}

void consultarTopo(Pilha *p) {
	if(pilhaVazia(p)) {
		printf("Erro: Pilha Vazia!");
		exit(1);
	}
	tAluno *topo=p->topo;
	printf("\nNome do Aluno no Topo: %s",topo->nome);
	for(int i=0; i<nProvas; i++) {
		printf("\nNota %d: %.2f",i+1,topo->notas[i]);
	}
	printf("\n");
}
void esvaziarPilha(Pilha *p) {
	while(!pilhaVazia(p)) {
		desempilhar(p);
	}
}

void imprimirPilha(Pilha *p) {
	printf("\n Lista de Alunos: \n");
	if(pilhaVazia(p)) {
		printf("\nA pilha esta vazia!!!\n");
	}
	tAluno *atual = p->topo;
	int num=1;
	while(atual!=NULL) {
		printf("\n\nNome do Aluno %d: %s",num++,atual->nome);
		for(int i=0; i<nProvas; i++) {
			printf("\nNota %d: %.2f",i+1,atual->notas[i]);
		}
		atual = atual->proximo;
	}
}

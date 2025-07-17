#include <stdlib.h>
#include <stdio.h>
#define nProvas 3
#define nColunas 51

typedef struct tAluno {
	char nome[nColunas];
	float notas[nProvas];
	struct tAluno* proximo;
} tAluno;

typedef struct {
	tAluno* frente;
	tAluno* tras;
} Fila;

void inicializarFila(Fila *);
int filaVazia(Fila *);
void enfileirar(Fila *);
tAluno *desenfileirar(Fila *);
char * funcao2(char *,char *);
int frenteFila(Fila *);
void esvaziarFila(Fila *);
void imprimirFila(Fila *);

int main()
{
	int opc;
	Fila f;
	inicializarFila(&f);
	while(opc!=6) {
		printf("\n---Bem-Vindo ao Menu---");
		printf("\n1- Inserir Aluno");
		printf("\n2- Imprimir Alunos");
		printf("\n3- Remover Primeiro da Fila");
		printf("\n4- Esvaziar Fila");
		printf("\n5- Mostrar Primeiro da Fila")
		printf("\n6- Sair");
		printf("\nDigite sua opcao:\n");
		scanf("%d",&opc);
		setbuf(stdin,NULL);
		switch(opc) {
		case 1:
			enfileirar(&f);
			break;
		case 2:
			imprimirFila(&f);
			break;
		case 3:
			tAluno *temp = desenfileirar(&f);
			if(temp!=NULL) {
				printf("O nome do aluno: %s\n",temp->nome);
				for(int i=0; i<nProvas; i++) {
					printf("Nota da %dB0: %.2f\n",i+1,temp->notas[i]);
				}
			}
			free(temp);
			break;
		case 4:
			esvaziarFila(&f);
			break;
		case 5:frenteFila(&f);
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

void inicializarFila(Fila *f) {
	f->frente = NULL;
	f->tras=NULL;
}
int filaVazia(Fila *f) {
	return f->frente==NULL;
}

void imprimirFila(Fila *f) {
	printf("\n Lista de Alunos: \n");
	if(filaVazia(f)) {
		printf("\nA fila esta vazia!!!\n");
	}
	tAluno *atual = f->frente;
	int num=1;
	while(atual!=NULL) {
		printf("\n\nNome do Aluno %d: %s",num++,atual->nome);
		for(int i=0; i<nProvas; i++) {
			printf("\nNota %d: %.2f",i+1,atual->notas[i]);
		}
		atual = atual->proximo;
	}
}

void enfileirar(Fila *f) {
	tAluno *novo = (tAluno*) malloc (sizeof(tAluno));
	if (novo==NULL) {
		printf("Erro de alocacao de memoria!!!");
		exit(1);
	}
	int i;
	printf("\nDIGITE O NOME:");
	fgets(novo->nome, nColunas, stdin);
	setbuf(stdin,NULL);
	for(i=0; i<nProvas; i++) {
		printf("Nota %d: ", i + 1);
		scanf("%f",&novo->notas[i]);
	}
	novo->proximo=NULL;
	if(filaVazia(f)) {
		f->frente =novo;
		f->tras=novo;
	} else {
		f->tras->proximo=novo;
		f->tras=novo;
	}
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
tAluno *desenfileirar(Fila *f) {
	if(filaVazia(f)) {
		printf("Fila Vazia!");
	}
	tAluno *temp = f->frente;
	tAluno *removido=(tAluno*)malloc(sizeof(tAluno));
	funcao2(removido->nome,temp->nome);
	for(int i=0; i<nProvas; i++) {
		removido->notas[i]=temp->notas[i];
	}
	f->frente = temp->proximo;
	if(f->frente==NULL) {
		f->tras=NULL;
	}
	free(temp);
	return removido;
}

void frenteFila(Fila *f){
    if(filaVazia(f)){
        printf("Fila Vazia!\n");
        exit(1);
    }
    tAluno *primeiro=f->frente;
    printf("\nNome do Primeiro da Fila: %s",primeiro->nome);
    for(int i=0;i<nProvas;i++){
        printf("Nota %d: %.2f",i+1,primeiro->notas[i]);
    }
    printf("\n");
}

void esvaziarFila(Fila *f) {
	while(!filaVazia(f)) {
		desenfileirar(f);
	}
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#define MAX 3 //10
int a = -1, b = -1, c = -1, ad = -1, bd = -1, cd = -1;

/* Trabalho PORTO */

//Código inicial CONTEINER
typedef struct no_c {
    int id; 
    int destino;
    char origem[10];
    struct no_c *prox;
} NO_Conteiner;

typedef struct {
    NO_Conteiner *inicio;
    NO_Conteiner *fim;
    int tam;
} Fila;

//Código inicial CONTEINER_AUX
typedef struct no_c_aux {
    int id_aux; 
    int destino_aux;
    char origem_aux[10];
    struct no_c_aux *prox_aux; 
} NO_ConteinerAux;

typedef struct {
    NO_ConteinerAux *inicio_aux;
    NO_ConteinerAux *fim_aux;
    int tam_aux;
} FilaAux;

//Código inicial EMBARCACAO
typedef struct no_e {
    char nome[7]; 
    int Lista_de_Destinos;
	NO_Conteiner Lista_de_Conteiners[3][10];
    //char Status[20];
	struct no_e *seg;
} NO_Embarcacao;

typedef struct {
    NO_Embarcacao *frente;
    NO_Embarcacao *tras;
    int qtde;
} Fila_e;

//lista de embarcacao
typedef struct LE {
	char EmbarcacaoEspera[7];
	struct LE *seg;
}NO_LE;

typedef struct {
	NO_LE *comeco;
	NO_LE *final;
	int qtdl;
} Lista_E;

//Inicializando filas
void inicializaFilaConteiner(Fila *fi) {
    fi->inicio = fi->fim = NULL;
    fi->tam = 0;
}

void inicializaFilaConteinerAux(FilaAux *fi_aux) {
    fi_aux->inicio_aux = fi_aux->fim_aux = NULL;
    fi_aux->tam_aux = 0;
}

void inicializaFilaEmbarcacao(Fila_e *fi_e) {
    fi_e->frente = fi_e->tras = NULL;
    fi_e->qtde = 0;
}

void IniciaListaEmbarcacao(Lista_E *l) {
	l->comeco = l->final = NULL;
	l->qtdl = 0;
}

//Esvaziando filas
void FilaConteinerDestrutor (Fila *fi) {
	NO_Conteiner *temp, *tempValor;
	while(fi->inicio != NULL) {
		temp = fi->inicio;
		tempValor = temp;
		fi->inicio = fi->inicio->prox;
		fi->tam--;
		free(tempValor);
	}
	fi->fim = NULL;
	//printf("\n\n\n Fila de Conteiner vazia!\n\n\n");
}

void FilaConteinerAuxDestrutor (FilaAux *fi_aux) {
	NO_ConteinerAux *temp, *tempValor;
	while(fi_aux->inicio_aux != NULL) {
		temp = fi_aux->inicio_aux;
		tempValor = temp;
		fi_aux->inicio_aux = fi_aux->inicio_aux->prox_aux;
		fi_aux->tam_aux--;
		free(tempValor);
	}
	fi_aux->fim_aux = NULL;
	//printf("\n\n\n Fila Auxiliar de Conteiners vazia!\n\n\n");
}

void FilaEmbarcacaoDestrutor (Fila_e *fi_e) {
	NO_Embarcacao *temp, *tempValor;
	while(fi_e->frente != NULL) {
		temp = fi_e->frente;
		tempValor = temp;
		fi_e->frente = fi_e->frente->seg;
		fi_e->qtde--;
		free(tempValor);
	}
	fi_e->tras = NULL;
	//printf("\n\n\n Embarcacao vazia!\n\n\n");
}

void ListaEmbarcacaoDestrutor(Lista_E *l) {
	NO_LE *temp, *tempValor;
	while(l->comeco != NULL) {
		temp = l->comeco;
		tempValor = temp;
		l->comeco = l->comeco->seg;
		l->qtdl--;
		free(tempValor);
	}
	l->final = NULL;
	//printf("\n\n\n Lista de embarcacao vazia!\n\n\n");
}

//Trocar nome embarcacao espaço por anderline
void TrocaEspacoTrocaAnderline(char Linha[7], char encontra, char troca){
    for(int i=0;i<7;i++){
        if(Linha[i] == encontra){
            Linha[i] = troca;
        }
    }
}

int VerificaCaseEmbarcacao (char lx[7]) {
	int embarc = 0;
	if ( (strcasecmp(lx,"LINHA_1") == 0 ) ) {  //strcasecmp: nao compara maiusculas e minusculas | strcmp: compara maiusculas e minusculas;
			embarc = 1;
	} else {
		if ( (strcasecmp(lx,"LINHA_2") == 0 ) ) {
			embarc = 2;
		} else {
			if ( (strcasecmp(lx,"LINHA_3") == 0 ) ) {
				embarc = 3;
			} else {
				if ( (strcasecmp(lx,"LINHA_4") == 0 ) ) {
					embarc = 4;
				}
			}
		}
	}
	return embarc;
}

int AlocaPosicaoDestino (int &x, int &d) {
	switch (x) {
		case 1:
			if(d == 4) {
				d = 0;
			} else {
				if(d == 5) {
					d = 1;
				} else {
					if(d == 6) {
						d = 2;
					}
				}
			}
			break;
		case 2:
			if(d == 2) {
				d = 0;
			} else {
				if(d == 3) {
					d = 1;
				} else {
					if(d == 5) {
						d = 2;
					}
				}
			}
			break;
		case 3:
			if(d == 1) {
				d = 0;
			} else {
				if(d == 6) {
					d = 1;
				} else {
					if(d == 7) {
						d = 2;
					}
				}
			}
			break;
		case 4:
			if(d == 1) {
				d = 0;
			} else {
				if(d == 2) {
					d = 1;
				} else {
					if(d == 3) {
						d = 2;
					}
				}
			}
			break;	
	}
	return d;
}

int AlocaPosicaoConteiner (int p) {
	switch (p) {
		case 0:
			a++;
			p = a;
			break;
		case 1:
			b++;
			p = b;
			break;
		case 2:
			c++;
			p = c;
			break;	
	}
	return p;
}

//Enfileirando conteiner
NO_Conteiner EnfileiraConteinerFila (Fila *fi, int &id, int &destino, char origem[10]) {
    NO_Conteiner *Novo_Conteiner = (NO_Conteiner*)malloc(sizeof(NO_Conteiner));
    if(Novo_Conteiner != NULL) {
        Novo_Conteiner->id = id;
        Novo_Conteiner->destino = destino;
        strcpy(Novo_Conteiner->origem,origem);
        Novo_Conteiner->prox = NULL;
        fi->tam++;
    }
    if (fi->inicio == NULL) { //se lista não estiver vazia
        fi->inicio = Novo_Conteiner; // novo_conteiner será o primeiro elemento da lista
//        printf("\n Primeiro conteiner enfileirado:");
//        printf("\n Primeiro conteiner enfileirado: Id [%d] | Destino [%d] | Origem [%s]!\n\n", id, destino, origem);
    } 
	else { //se lista não estiver vazia o ultimo nó aponta para novo nó
        fi->fim->prox = Novo_Conteiner;
//        printf("\n Conteiner enfileirado no fim da fila: Id [%d] | Destino [%d] | Origem [%s]!\n\n", id, destino, origem);
//        printf("\n Conteiner enfileirado no fim da fila:");
    }
    fi->fim = Novo_Conteiner; // fim indica um novo nó
}

//Desenfileirando conteiner
NO_Conteiner DesenfileiraConteinerFila(Fila *fi, NO_Conteiner c) {
	NO_Conteiner *aux, *auxValor;
	aux = fi->inicio;
	auxValor = aux;
	strcpy(auxValor->origem, aux->origem);
	fi->inicio = fi->inicio->prox;
    fi->tam--;
//	printf("\n Conteiner desenfileirado da fila de conteiners:\nId [%d] | Destino [%d] | Origem [%s]!\n\n", aux->id, aux->destino, aux->origem); 
    return *aux; //se nao retornar nao precisa do *auxValor;
    free(auxValor); // -> se dar o free antes de retornar imprime lixo;
}

//Desenfileirando ConteinerFilaAux
NO_ConteinerAux DesenfileiraConteinerFilaAux(FilaAux *fi_aux, NO_ConteinerAux c_aux) {
	NO_ConteinerAux *aux, *auxValor;
	aux = fi_aux->inicio_aux;
	auxValor = aux;
	strcpy(auxValor->origem_aux, aux->origem_aux);
	fi_aux->inicio_aux = fi_aux->inicio_aux->prox_aux;
    fi_aux->tam_aux--;
//	printf("\n Conteiner desenfileirado da fila aux: Id [%d] | Destino [%d] | Origem [%s]!\n\n", aux->id_aux, aux->destino_aux, aux->origem_aux);
    return *aux;
    free(auxValor); //-> se dar o free antes de retornar imprime lixo
}

///Desenfileirando Embarcacao da lista de Espera
NO_LE DesenfileiraEmbarcacaoEmEspera(Lista_E *l) {
	NO_LE *aux, *auxValor;
	aux = l->comeco;
	auxValor = aux;
	//strcpy(auxValor->EmbarcacaoEspera, aux->EmbarcacaoEspera);
	l->comeco = l->comeco->seg;
    l->qtdl--;
//	printf("\n Embarcacao desenfileirada da lista de espera: [%s]!\n\n", aux->EmbarcacaoEspera);
    return *aux;
    free(auxValor); //-> se dar o free antes de retornar imprime lixo
}

//Enfileirando conteiner na embarcacao
void EnfileiraConteinerEmbarcacao(Fila_e *fi_e, NO_Conteiner c, NO_Embarcacao e, char lx[7]) {	//pegando os valores desenfileirados e enfileirando na embarcacao
    NO_Embarcacao *Conteiner_embarcacao = (NO_Embarcacao*)malloc(sizeof(NO_Embarcacao));
    NO_Conteiner *aux;
    int d, x, p, i;
    d = aux->destino;
    x = VerificaCaseEmbarcacao (lx);
    p = AlocaPosicaoDestino (x, d);
    i = AlocaPosicaoConteiner (p);
    //printf("\nx.e. = %d\n",x); printf("\np = %d\ni = %d\n",p, i); printf("\nd = %d\n",d);
	//printf("\n Conteiner com destino compativel com embarcacao %s:\nId [%d] | Destino [%d] | Origem [%s]!\n\n\n\n",lx, aux->id, aux->destino, aux->origem);
	if(Conteiner_embarcacao != NULL) {
		strcpy(Conteiner_embarcacao->nome, lx); //copia de um vetor de string para outro, já que naõ é possível fazer uma atribuição de igual //strcpy(onde será copiado, o que será copiado);
		Conteiner_embarcacao->Lista_de_Destinos = aux->destino;
		Conteiner_embarcacao->Lista_de_Conteiners[p][i].id = aux->id;
		Conteiner_embarcacao->Lista_de_Conteiners[p][i].destino = aux->destino;
		strcpy(Conteiner_embarcacao->Lista_de_Conteiners[p][i].origem, aux->origem); 
		//printf("\n Conteiner enfileirado na embarcacao %s:\nId [%d] | L. Destino [%d] \n\n", Conteiner_embarcacao->nome, Conteiner_embarcacao->Lista_de_Conteiners.id, Conteiner_embarcacao->Lista_de_Conteiners.destino);
		//printf("| L. Origem [%s]!\n\n", Conteiner_embarcacao->Lista_de_Conteiners.origem);
	    Conteiner_embarcacao->seg = NULL;
		fi_e->qtde++;
	    //printf("qtd sim: [%d] !\n",fi_e->qtde);	
		//strcpy(Conteiner_embarcacao->Status,"Carregando");
	}
	if (fi_e->frente == NULL) {
		fi_e->frente = Conteiner_embarcacao; // novo no será o primeiro elemento da lista
        //printf("\n Primeiro conteiner enfileirado na embarcacao %s:\n Id [%d] | L. Destino [%d] ", Conteiner_embarcacao->nome, Conteiner_embarcacao->Lista_de_Conteiners[p][i].id, Conteiner_embarcacao->Lista_de_Conteiners[p][i].destino);
        //printf("| L. Origem [%s]!\n\n", Conteiner_embarcacao->Lista_de_Conteiners[p][i].origem); //não imprime junto com id e conteiner pois da erro;
    } 
	else {   // se lista não estiver vazia o ultimo nó aponta para novo nó
        fi_e->tras->seg = Conteiner_embarcacao;
       // printf("\n Conteiner enfileirado no fim da embarcacao %s:\n Id [%d] | L. Destino [%d] ", Conteiner_embarcacao->nome, Conteiner_embarcacao->Lista_de_Conteiners[p][i].id, Conteiner_embarcacao->Lista_de_Conteiners[p][i].destino);
        //printf("| L. Origem [%s]!\n\n", Conteiner_embarcacao->Lista_de_Conteiners[p][i].origem);
	}
	fi_e->tras = Conteiner_embarcacao; // fim indica um novo nó
}

//Pega conteiner  não enfileirado e enfileria na fila aux
void FilaConteinerNaoEmbarcado (Fila *fi, FilaAux *fi_aux, NO_Conteiner c, NO_ConteinerAux c_aux) {
	NO_ConteinerAux *NE_Conteiner = (NO_ConteinerAux*)malloc(sizeof(NO_ConteinerAux));
	NO_Conteiner *usa;
	//printf("\n Conteiner com destino incompativel com embarcacao:\nId [%d] | Destino [%d] | Origem [%s]!\n\n\n\n", usa->id, usa->destino, usa->origem);
	if(NE_Conteiner != NULL) {
	    NE_Conteiner->id_aux = usa->id;
		NE_Conteiner->destino_aux = usa->destino;
	    strcpy(NE_Conteiner->origem_aux,usa->origem);
	    NE_Conteiner->prox_aux = NULL;
	    fi_aux->tam_aux++;
	}
    if (fi_aux->inicio_aux == NULL) { //se lista não estiver vazia
        fi_aux->inicio_aux = NE_Conteiner; // novo_conteiner será o primeiro elemento da lista
        //printf("\n Primeiro conteiner enfileirado na fila aux: Id [%d] | Destino [%d] | Origem [%s]!\n\n", usa->id, usa->destino, usa->origem);
    } 
	else { //se lista não estiver vazia ultimo nó aponta para novo nó
        fi_aux->fim_aux->prox_aux = NE_Conteiner;
        //printf("\n Conteiner enfileirado no fim da fila aux: Id [%d] | Destino [%d] | Origem [%s]!\n\n", usa->id, usa->destino, usa->origem);
    }
    fi_aux->fim_aux = NE_Conteiner; // fim indica um novo nó									
}

//Nao enfileirando conteiner na embarcacao
void NaoEnfileiraConteinerEmbarcacao(Fila *fi, FilaAux *fi_aux, Fila_e *fi_e, NO_Conteiner c, NO_ConteinerAux c_aux, NO_Embarcacao e, char lx[7]) {
	NO_Embarcacao *Conteiner_embarcacao;
	//printf("\n Conteiner com destino incompativel com embarcacao %s:\nId [%d] | Destino [%d] | Origem [%s]!\n\n\n\n", lx, fi->inicio->id, fi->inicio->destino, fi->inicio->origem);
	DesenfileiraConteinerFila(fi, c);
	FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
}

void ListarEmbarcaoEmEspera (Lista_E *l, char lx[7]) {
	NO_LE *ListaEmbarcacao = (NO_LE*)malloc(sizeof(NO_LE));
//	if((Buscar embarcacao na lista de espera e encontrar)) {
//		//nao enfileira lx;
//	} else{
//		//enfileira lx;
//	}
	if(ListaEmbarcacao != NULL) {
        strcpy(ListaEmbarcacao->EmbarcacaoEspera, lx);
		ListaEmbarcacao->seg = NULL;
        l->qtdl++;
    }
    if (l->comeco == NULL) { //se lista não estiver vazia
        l->comeco = ListaEmbarcacao;
        //printf("\n Primeira embarcacao em espera enfileirada: [%s]!\n\n", lx);
    } 
	else { //se lista não estiver vazia o ultimo nó aponta para novo nó
        l->final->seg = ListaEmbarcacao;
        //printf("\n Embarcacao em espera enfileirada no fim da fila: [%s]!\n\n", lx);
    }
    l->final = ListaEmbarcacao; 
}

//Redefinindo FilaConteiner e FilaConteinerAux
NO_ConteinerAux Redefine (Fila *fi, FilaAux *fi_aux, NO_Conteiner c, NO_ConteinerAux c_aux) {
	NO_Conteiner *a;
	NO_ConteinerAux *b;
	while(fi->inicio != NULL){ //passa todos os conteiners da fila de conteiners;
		*a = DesenfileiraConteinerFila(fi, c);
		FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
	}
	while( fi_aux->inicio_aux != NULL){ //passa todos os conteiners da fila de conteiners auxiliar;
		*b = DesenfileiraConteinerFilaAux(fi_aux, c_aux); //erro nessa função //questão NULL
		EnfileiraConteinerFila (fi, b->id_aux, b->destino_aux, b->origem_aux);
	}
	return *b;
}

///Status
void Status (Fila *fi, Lista_E *l, int &status, char lx[7]) { //na funcao desenfileira e retornar o int status
	if(status == 2) {
			//printf("\n Status:\n NAVEGANDO!\n\n");
			//strcpy(e->Status,"Navegando");
			printf("\n\n ---------------------------");
			TrocaEspacoTrocaAnderline(lx,'_',' ');
			strupr(lx);
			printf("\n  EMBARCACAO   [%s]", lx); //depois que enche dar o destrutor e nao imprime o nome
			TrocaEspacoTrocaAnderline(lx,' ','_');
			printf("\n ---------------------------\n"); 
			printf("  STATUS    |   NAVEGANDO\n");
			printf(" ---------------------------\n\n\n"); 
	} else {
			if(status == 1) { //fi_e->qtde == 0
				//printf("\n Status:\n APORTOU!\n\n");
				//strcpy(e->Status,"Aportou");
				printf("\n\n ---------------------------");
				TrocaEspacoTrocaAnderline(lx,'_',' ');
				strupr(lx);
				printf("\n  EMBARCACAO   [%s]", lx);
				TrocaEspacoTrocaAnderline(lx,' ','_');
				printf("\n ---------------------------\n"); 
				printf("  STATUS    |   APORTOU\n");
				printf(" ---------------------------\n\n\n"); 
			} else {
				if(status = 3) {
					//printf("\n Status:\n EM ESPERA!\n\n");
					//strcpy(e->Status,"Em espera");
					printf("\n\n ---------------------------");
					TrocaEspacoTrocaAnderline(lx,'_',' ');
					strupr(lx);
					printf("\n  EMBARCACAO   [%s]", lx);
					TrocaEspacoTrocaAnderline(lx,' ','_');
					printf("\n ---------------------------\n"); 
    				printf("  STATUS    |   EM ESPERA\n");
    				printf(" ---------------------------\n\n\n"); 
					ListarEmbarcaoEmEspera (l, lx);
				}
			}
	}
}

//Desenfileirando conteiner e enfileirando na embarcacao
int DesemfileirarConteinerLista(Fila *fi, FilaAux *fi_aux, Fila_e *fi_e, Lista_E *l, NO_Conteiner c, NO_ConteinerAux c_aux, NO_Embarcacao e, char lx[7], int &status) {
    NO_Conteiner *aux, *auxValor;
    NO_ConteinerAux *d;
    NO_Embarcacao *Conteiner_embarcacao = (NO_Embarcacao*)malloc(sizeof(NO_Embarcacao));
    int cont = 0, embarc = 0;
	//printf("\nstatus - Aportou <- 1 -> : %d\n", status);
	Status (fi, l, status, lx);
    if(fi->inicio != NULL) {
    //Remove até 10 conteiners da fila e põe-os na embarcação de acordo com seus destinos compatíveis com a embarcação
		//printf("\nDestino a desenfileirar da fila: [%d] !\n\n",fi->inicio->destino);
	    embarc = VerificaCaseEmbarcacao (lx);
	    //printf("Embarcacao verificada = %d\n\n", embarc); //printf("\n MAX = %d\n\n", MAX);
		switch(embarc) {
			case 1: // 'LINHA 1'
				//printf("\nDestino a desenfileirar case: [%d] !\n\n",fi->inicio->destino);
				while(fi->inicio != NULL && fi_e->qtde <= MAX-1) { // fi_e->qtde <= 9) //contar com posicao 0
					if(fi->inicio->destino >= 4 && fi->inicio->destino <= 6) {	//Se destino do conteiner for compatível enfileira
						DesenfileiraConteinerFila(fi, c);
	    				EnfileiraConteinerEmbarcacao(fi_e, c, e, lx);
					}
					else { // Conteiner fica aguandando na fila até a próxima embarcação com vaga e destino compatível
						NaoEnfileiraConteinerEmbarcacao(fi, fi_aux, fi_e, c, c_aux, e, lx);
						cont++;
						//printf("\ntam fi -nfe- %d\n", fi->tam); printf("\ntam cont fi -nfe- %d\n", cont); printf("\ntam fi -aux- %d\n", fi_aux->tam_aux);
						if(cont == fi_aux->tam_aux) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila
							status = 3; // 3 - EM ESPERA
							printf(" \n"); // se tirar dar error!
							//printf("\n Status -f- :\n EM ESPERA: nao ha nenhum conteiner para seus destino.\n\n");
						}
					}
				}
				//printf("Qtd embarcacao: %d", fi_e->qtde);
				if(fi_e->qtde <= MAX-1) { //joga na fila de conteiners
					Redefine (fi, fi_aux, c, c_aux); //dar certo nesse if
					//printf("\ntam fi = %d\n", fi_e->qtde);
					if( fi_e->qtde != 0) {
						status = 2; // 2 - Navegando
					}
				} else { //joga na fila de conteiners
					//printf("Embarcação %s cheia!\n\n", lx);
					status = 2; // 2 - Navegando
					//Redefine (fi, fi_aux, c, c_aux); //se tiver conteiner dps de cheia da problema
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners
						DesenfileiraConteinerFila(fi, c); //sem questao null
						FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); //sem questao null
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}		
				}
				//system ("pause");
				break;
			case 2: // 'LINHA 2'
				while(fi->inicio != NULL && fi_e->qtde <= MAX-1) {
					if(fi->inicio->destino == 2 || fi->inicio->destino == 3 ||fi->inicio->destino == 5) {	
						DesenfileiraConteinerFila(fi, c);
	    				EnfileiraConteinerEmbarcacao(fi_e, c, e, lx);
					} else { // Conteiner fica aguandando na fila até a próxima embarcação com vaga e destino compatível
						NaoEnfileiraConteinerEmbarcacao(fi, fi_aux, fi_e, c, c_aux, e, lx);	
						cont++;
						if(cont == fi_aux->tam_aux) {
							status = 3; // 3 - EM ESPERA
							printf(" \n"); // se tirar dar error em 1 e 4!
							//printf("\n Status -f- :\n EM ESPERA: nao ha nenhum conteiner para seus destino.\n\n");
						}
					}
				}
				if(fi_e->qtde <= MAX-1) {
					Redefine (fi, fi_aux, c, c_aux);
					if( fi_e->qtde != 0) {
						status = 2; // 2 - Navegando
					}
				} else { // Embarcação cheia
					status = 2; // 2 - Navegando
					//Redefine (fi, fi_aux, c, c_aux);
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners;
							DesenfileiraConteinerFila(fi, c);
							FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar;
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}	
				}
				//system ("pause");
				break;
			case 3: // 'LINHA 3'
				while(fi->inicio != NULL && fi_e->qtde <= MAX-1) {
					if(fi->inicio->destino == 1 || fi->inicio->destino == 7 ||fi->inicio->destino == 6) {
						DesenfileiraConteinerFila(fi, c);
	    				EnfileiraConteinerEmbarcacao(fi_e, c, e, lx);
					} else { // Conteiner fica aguandando na fila até a próxima embarcação com vaga e destino compatível
						NaoEnfileiraConteinerEmbarcacao(fi, fi_aux, fi_e, c, c_aux, e, lx);	
						cont++;
						if(cont == fi_aux->tam_aux) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila aux
							status = 3; // 3 - EM ESPERA
							printf(" \n"); // se tirar dar error!
							//printf("\nStatus -f- :\n EM ESPERA: nao ha nenhum conteiner para seus destino.\n\n");
						}
					}
				}
				if(fi_e->qtde <= MAX-1) {
					Redefine (fi, fi_aux, c, c_aux);
					if( fi_e->qtde != 0) {
						status = 2; // 2 - Navegando
					}
				} else { // Embarcação cheia
					status = 2; // 2 - Navegando
					//Redefine (fi, fi_aux, c, c_aux);
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners;
							DesenfileiraConteinerFila(fi, c);
							FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar;
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}		
				}
				//system ("pause");
				break;
			case 4: // 'LINHA 4'
				while(fi->inicio != NULL && fi_e->qtde <= MAX-1) {
					if(fi->inicio->destino >= 1 && fi->inicio->destino <= 3) {
						DesenfileiraConteinerFila(fi, c);
	    				EnfileiraConteinerEmbarcacao(fi_e, c, e, lx);
					} else { // Conteiner fica aguandando na fila até a próxima embarcação com vaga e destino compatível
						NaoEnfileiraConteinerEmbarcacao(fi, fi_aux, fi_e, c, c_aux, e, lx);	
						cont++;
						if(cont == fi_aux->tam_aux) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila aux
							status = 3; // 3 - EM ESPERA
							printf(" \n"); // se tirar dar error em 1 e 4!
							//printf("\nStatus -f- :\n EM ESPERA: nao ha nenhum conteiner para seus destino.\n\n");
						}	
					}
				}
				if(fi_e->qtde <= MAX-1) {
					Redefine (fi, fi_aux, c, c_aux);
					if( fi_e->qtde != 0) {
						status = 2; // 2 - Navegando
					}
				} else { // Embarcação cheia
					status = 2; // 2 - Navegando
					//Redefine (fi, fi_aux, c, c_aux);
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners;
						DesenfileiraConteinerFila(fi, c);
						FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar;
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}		
				}
				//system ("pause");
				break;
		}
		//printf("Embarcação cheia!\n\n");
		//FilaEmbarcacaoDestrutor(fi_e);
    } else {
    	fi->fim=NULL; // Caso o inicio esteja vazio então o fim também ficará
        //printf("\n Fila de conteiners vazia!\n\n");
        status = 3;
    }
    return status;
}

int verificaABC (int p, int a, int b, int c) {
	if(a != -1 || b != -1 || c != -1) {
		if( p == 0)
			p = a;
		else
			if( p == 1)
				p = b;
			else
				p = c;
	} else 
		p = -1;
	return p;
}

int AlocaPConteiner (int p) {
	switch (p) {
		case 0:
			ad++;
			p = ad;
			break;
		case 1:
			bd++;
			p = bd;
			break;
		case 2:
			cd++;
			p = cd;
			break;	
	}
	return p;
}

//Imprimindo
void ImprimeFilaConteiner (Fila *fi) {
    NO_Conteiner *atual;
    atual = fi->inicio;
    //printf("| %d ° Id [%d] | Destino [%d] |  Origem [%s]  |\n", enu, atual->id, atual->destino, atual->origem);
    if(atual == NULL) {
    	printf("\n\n\n --------------------------------\n");
		printf("         FILA CONTEINER\n");
		printf(" --------------------------------");
        printf("\n 0 Conteiners na fila\n");
        printf("\n --------------------------------\n\n\n");
    }
    else {
    	printf("\n -----------------------------------------\n");
		printf("               FILA CONTEINER            \n");
    	printf(" -----------------------------------------\n");
	    while (atual != NULL) {
	        printf("  Id [%d]  |  Destino [%d]  |  Origem [%s]  \n", atual->id, atual->destino, atual->origem);
	        atual = atual->prox;
	    }
	   	printf(" -----------------------------------------\n\n");
    }
}

void ImprimeFilaConteinerAux (FilaAux *fi_aux) {
    NO_ConteinerAux *atual_aux;
    atual_aux = fi_aux->inicio_aux;
    //printf("| %d ° Id [%d] | Destino [%d] |  Origem [%s]  |\n", enu, atual->id, atual->destino, atual->origem);
	//printf("\n tam = %d\n", fi_aux->tam_aux);
    if(atual_aux == NULL)  {
    	printf("\n\n -------- FILA CONTEINER AUX --------\n");
        printf("\n 0 Conteiners na fila auxiliar\n\n\n");
    }
    else {
    	printf("\n\n -----------------------------------------\n");
		printf("            FILA CONTEINER AUX           \n");
    	printf(" -----------------------------------------\n");
	    while (atual_aux != NULL) {
	        printf(" Id [%d] | Destino [%d] |  Origem [%s]  \n", atual_aux->id_aux, atual_aux->destino_aux, atual_aux->origem_aux);
	        atual_aux = atual_aux->prox_aux;
	    }
	   	printf(" -----------------------------------------\n\n\n");
    }
}

void ImprimeFilaEmbarcacao (Fila_e *fi_e) {
	NO_Embarcacao *atual_e;
	atual_e = fi_e->frente;
	int d, x, p, i, q;
	//printf("\n\n  %d ° Nome [%s] | L. Destino [%d] | L. Conteiner [%d] | Status [%s]!\n\n  ", enu_e, atual_e->nome, atual_e->Lista_de_Destinos, atual_e->Lista_de_Conteiners, atual_e->Status);
	if(atual_e == NULL) {
		printf("\n --------------------------------\n");
		printf("          EMBARCACAO\n");
		printf(" --------------------------------");
	    printf("\n   Nao ha embarcacao no porto\n");
	    printf("\n --------------------------------\n\n\n");
	}
	else {
		TrocaEspacoTrocaAnderline(atual_e->nome,'_',' '); // para imprimir sem o anderline, agora troca-se o anderline pelo espaço
		strupr(atual_e->nome);
		printf("\n ------------------------------------------------------------------\n");
		printf("                            EMBARCACAO\n");
		printf(" ------------------------------------------------------------------\n");
		printf("    NOME    |   L. DESTINOS   |           L. CONTEINERS     \n");
		printf(" ------------------------------------------------------------------\n");
		printf("  [%s] ", atual_e->nome);
		TrocaEspacoTrocaAnderline(atual_e->nome,' ','_');
		while(atual_e != NULL) {
        	//TrocaEspacoTrocaAnderline(atual_e->nome,'_',' '); // para imprimir sem o anderline, agora troca-se o anderline pelo espaço
			//strupr(atual_e->nome); //strupr - transforma a string em caixa alta
        	printf("|        [%d]      |", atual_e->Lista_de_Destinos);
        	//TrocaEspacoTrocaAnderline(atual_e->nome,' ','_');
		    d = atual_e->Lista_de_Destinos;
		    x = VerificaCaseEmbarcacao (atual_e->nome);
		    p = AlocaPosicaoDestino (x, d);
		    i = verificaABC (p, a, b, c);
		    q = AlocaPConteiner(p);
		    //printf("\nx.e. = %d\n",x); printf("\np = %d\ni = %d\n",p, i); printf("\nq = %d\n",q);
    		printf("  Id [%d] | Destino [%d] ", atual_e->Lista_de_Conteiners[p][q].id, atual_e->Lista_de_Conteiners[p][q].destino);
    		printf("| Origem [%s]\n", atual_e->Lista_de_Conteiners[p][q].origem);
        	atual_e = atual_e->seg;
        	printf("            ");
        }
        if( fi_e->qtde == MAX) {
        	//Status (fi, l, i, lx);
    		printf("\n ------------------------------------------------------------------\n"); 
    		printf("  STATUS    |   Navegando");
    		FilaEmbarcacaoDestrutor (fi_e);
    	}
    	printf("\n ------------------------------------------------------------------\n\n\n\n"); 
	}
}

int ImprimeEmbarcaoEmEspera (Lista_E *l) {
	NO_LE *ListaEmbarcacao = (NO_LE*)malloc(sizeof(NO_LE));
	ListaEmbarcacao = l->comeco;
	if(ListaEmbarcacao == NULL) {
		printf("\n\n\n Nao ha embarcacao em espera!\n\n\n");
		return 0;
	} else {
		printf("\n\n\n ---------------------------\n");
		printf("     EMBARCACAO EM ESPERA    ");
		printf("\n ---------------------------\n");
		while(ListaEmbarcacao != NULL) {
			TrocaEspacoTrocaAnderline(ListaEmbarcacao->EmbarcacaoEspera,'_',' '); // para imprimir sem o anderline, agora troca-se o anderline pelo espaço
			strupr(ListaEmbarcacao->EmbarcacaoEspera);
			printf(" %s\n", ListaEmbarcacao->EmbarcacaoEspera);
			TrocaEspacoTrocaAnderline(ListaEmbarcacao->EmbarcacaoEspera,' ','_');
			ListaEmbarcacao = ListaEmbarcacao->seg;
		}
		printf("\n ---------------------------\n\n");
		return 1;
	}
}

//Tamanho
void TamanhoFilaConteiner(Fila *fi) {
    if(fi->tam == 0) {
    	printf("\n\n\n Fila de Conteiners vazia!\n\n\n");
    }
	else {
		printf("\n Exitem %d Conteiners na fila!\n\n\n",fi->tam);
	}
}

void TamanhoFilaConteinerAux(FilaAux *fi_aux) {
    if(fi_aux->tam_aux == 0) {
    	printf("\n Fila aux de Conteiners vazia!\n\n\n");
    }
	else {
		printf("\n Exitem %d Conteiners na fila aux!\n\n\n",fi_aux->tam_aux);
	}
}

void TamanhoFilaEmbarcacao(Fila_e *fi_e) {
    if(fi_e->qtde == 0) {
    	printf("\n Embarcacao vazia!\n\n\n");
    }
	else {
		printf("\n Exitem %d Conteiners na embarcacao!\n\n\n",fi_e->qtde);
	}
}

void TamanhoListaEmbarcacao(Lista_E *l) {
    if(l->qtdl == 0) {
    	printf("\n Lista de espera vazia!\n\n\n");
    }
	else {
		printf("\n Exitem %d embarcacoes em espera!\n\n\n",l->qtdl);
	}
}

//Buscando
void BuscaFilaConteiner(Fila *fi, int i, int d, char o[10]) {
    NO_Conteiner *aux = fi->inicio;
    int achou = 0;
	while(aux != NULL && !achou) {
        if(i == aux->id && d == aux->destino && (strcasecmp(o,aux->origem) == 0 ) ) {
            printf("\n Conteiner encontrado na fila: Id [%d] | Destino [%d] | Origem [%s]!\n\n", aux->id, aux->destino, aux->origem);
            achou = 1;
        }
        aux = aux->prox;
    }
	if(achou == 0) {
    	 printf("\n Conteiner inexistente na fila: Id [%d] | Destino [%d] | Origem [%s]!\n\n", i, d, o);
    }
}

void BuscaFilaConteinerEmbarcacao(Fila_e *fi_e, int x_e) {
    NO_Embarcacao *aux_e = fi_e->frente;
    int encontrou = 0;
	while(aux_e != NULL && !encontrou) {
        if(x_e == aux_e->Lista_de_Destinos) {
            printf("\n\n\n Conteiner com destino [%d] encontrado na embarcacao!\n\n\n",aux_e->Lista_de_Destinos);
            encontrou = 1;
        }
        aux_e = aux_e->seg;
    }
	if(encontrou == 0) {
    	 printf("\n\n\n Conteiner com destino [%d] inexistente na embarcacao!\n\n\n", x_e);
    }
}

void BuscaListaEmbarcacao(Lista_E *l, char x_l[7]) {
    NO_LE *aux_l = l->comeco;
    int encontrou = 0;
	while(aux_l != NULL && !encontrou) {
        if((strcasecmp(x_l,aux_l->EmbarcacaoEspera) == 0 )) {
        	TrocaEspacoTrocaAnderline(aux_l->EmbarcacaoEspera,'_',' ');
        	strupr(aux_l->EmbarcacaoEspera);
            printf("\n Embarcacao [%s] encontrada na lista de espera!\n\n\n",aux_l->EmbarcacaoEspera);
            encontrou = 1;
        }
        TrocaEspacoTrocaAnderline(aux_l->EmbarcacaoEspera,' ','_');
        aux_l = aux_l->seg;
    }
	if(encontrou == 0) {
		TrocaEspacoTrocaAnderline(x_l,'_',' ');
        strupr(x_l);
    	printf("\n Embarcacao [%s] nao encontra-se em espera!\n\n\n", x_l);
    }
}

//Verificacões
//Verificacões
int VerificaId(int &x) { //Verifica se foram digitados somente numeros
	int i, flag = -1;
    for(i=0; i<=9; i++){
        if(x == i || x == -i){
            flag = 0;
        }
    }
    if( flag == -1) {
    	printf ("\n\n\n Id invalido!\n");
    }
    return flag;
}

int VerificaDestino (int &y) { //Destino válido de 1 a 6;
	int flag;
    if(y<1 || y>6) {
        printf("\n\n Destino indisponivel no porto!\n");
        flag = -1;
    } else{
    	flag = 0;
    }
    return flag;
}
//int VerificaOrigem (char z[10]) {
//	int conta = 0, i; 
//   	for(i=0;i<10;i++) {
//    	//printf("\n\n\n %d -> O caractere: \"%c\" tem o valor ASCII %d\n\n\n", i, z[i] ,(int)z[i]);
//        if(z[i] == 13 || z[i] == 10 || z[i] == 0) { //possibilidades ENTER tabela ASCII;
//        	conta++;
//        }
//    } //printf("\n Conta = %d", conta);
//    if(conta == 6){
//        	printf("\n\n Origem nao informada!\n"); //apenas ENTER digitado;
//        	return 1;
//    }
//}

int VerificaEnfileira (int &x, int&y, char z[10]) {
	int id = 0, dest = 0, orig = 0, e;
	id = VerificaId (x);
	dest = VerificaDestino (y);
//	orig = VerificaOrigem (z);
	if( id == -1 || dest == -1) {
		//printf("\n Conteiner nao enfileira!\n\n");
		e = -1;
	} else {
		e = 0;
	}
	return e;
}

void EscolheBusca (Fila *fi, Fila_e *fi_e, Lista_E *l, int &b) {
	int i, d, v;
	char n[7], o[10];
	switch (b) {
		case 1:	
            printf("\n Conteiner a buscar na lista:\n");
            printf("\n Id: ");
            while(getchar()!='\n'){};
            scanf(" %d",&i);
            printf("\n Destino: ");
            while(getchar()!='\n'){};
            scanf(" %d",&d);
            printf("\n Origem: ");
            while(getchar()!='\n'){};
            gets(o);
            if( (v = VerificaEnfileira(i,d,o)) == 0) {
	            	printf("\n\n Busca nao prossegue!\n\n\n");
            } else {
				BuscaFilaConteiner(fi, i, d, o);
            }
	        break;
	    case 2:
	    	printf("\n Destino do conteiner a buscar na embarcacao: ");
	    	while(getchar()!='\n'){};
            scanf(" %d",&d);
            if( (v = VerificaDestino(d) == 1)) {
	            	printf("\n\n Busca nao prossegue!\n\n\n");
            } else {
					BuscaFilaConteinerEmbarcacao(fi_e, d);
            }
	    	break;
	    case 3:
	    	printf("\n Embarcacao a buscar na lista de espera: ");
	    	setbuf(stdin, NULL);
            gets(n);
            TrocaEspacoTrocaAnderline(n,' ','_');
            BuscaListaEmbarcacao(l, n);
	    	break;
	    default:
	    	printf("\n Opcao invalida!\n\n\n");
	    	break;
	}
}


void CABECALHO () {
	printf("\n\n\tUNIVERSIDADE FEDERAL DO TOCANTINS\n \tCAMPUS UNIVERSITARIO DE PALMAS\n \tCURSO DE CIENCIA DA COMPUTACAO\n\n\n\n"); // /t - dar 7 espaços seguidos
	printf("\tDiscentes:\n \tKEYZE MIRELLE RODRIGUES ALMEIDA\n \tARTHUR LUZ DE CARVALHO\n\n");
	printf("\tDisciplina: ESTRUTURA DE DADOS I\n \tDocente: JULIANA LEITAO DUTRA\n\n\n\n");
	system("pause");
	system("cls");
	printf("\n\t\t===== ===== ===== PROBLEMA PORTO ===== ===== =====\n\n");
	printf("\t  Conteiner:\n \t\t-id: inteiro;\n \t\t-destino: inteiro;\n \t\t-origem: string;\n\n");
	printf("\t  Embarcacao:\n \t\t-nome: string;\n \t\t-lista de destinos;\n \t\t-lista de conteiners (uma lista para cada destino);\n \t\t-status (aportou, navegando ou em espera);\n\n");
	printf("\t  Implementar de forma dinamica uma fila de conteiners.\n\n \t  Um conteiner, ao chegar ao porto, sera enfileirado se e compativel\n\tcom os destinos disponiveis.\n\n \t  Ao chegar uma embarcacao, os conteiners serao removidos da fila de\n\tacordo com seus destinos, e sao colocados na embarcacao, ate o\n\tnumero maximo de 10 conteieners por embarcacao.\n\n");
	printf("\t  Status da embarcacao:\n \t-Aportou:  esta vazia e sera carregada.\n \t-Navegando: esta cheia ou nao ha mais conteiners para seus destinos.\n \t-Em espera: nao ha nenhum conteiner para seus destino.\n\n");
	printf("\t  Destinos disponiveis: 1, 2, 3, 4, 5 e 6.\n");
	printf("\t  Embarcacoes disponiveis:\n \t     NOME      |    DESTINOS\n \t------------------------------\n \t LINHA 1       |   4 - 5 - 6\n \t LINHA 2       |   2 - 3 - 5\n \t LINHA 3       |   1 - 7 - 6\n \t LINHA 4       |   1 - 2 - 3\n\n\n");
	printf("\t ===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n\n");
	system("pause");
}

void MENU() {
	printf("\n -------- MENU --------\n [1] Chega conteiner\n [2] Chega embarcacao\n [3] Verifica embarcacao em espera\n [4] Mostra\n [5] Tamanho\n [6] Busca\n [0] Sair\n\n");		
}

int main (int argc, char** argv) {
    Fila fi;
    FilaAux fi_aux;
    Fila_e fi_e;
    Lista_E l;
    NO_Conteiner c;
    NO_ConteinerAux c_aux;
    NO_Embarcacao e;
    NO_LE f;
    int op, x, y, w, s, status = 0, i, j, k, v, busca;
    char z[10], lx[7];

//	CABECALHO();	
    inicializaFilaConteiner(&fi);
    inicializaFilaConteinerAux(&fi_aux);
    inicializaFilaEmbarcacao(&fi_e);
    IniciaListaEmbarcacao(&l);
    	
    do {
		system("cls");
		MENU();
        printf(" Opcao: ");
        setbuf(stdin, NULL);
		scanf("%d",&op);
        switch(op) {
	        case 1:
	        	setbuf(stdin, NULL); 
	            printf("\n Id do conteiner: ");
	            scanf(" %d",&x);
	            while(getchar()!='\n'){};     
	            printf("\n Destino do conteiner: ");
	            setbuf(stdin, NULL);
	            scanf(" %d",&y);
				while(getchar()!='\n'){}; 
	            printf("\n Origem do conteiner: ");
	            setbuf(stdin, NULL);
	            gets(z);
	            if( (v = VerificaEnfileira(x,y,z)) == 1) {
	            	printf("\n\n Conteiner nao enfileira!\n\n\n");
	            } else {
					EnfileiraConteinerFila(&fi, x, y, z);
	            }
	            printf("\n\n\n");
	            system("pause");
	            break;
	        case 2:
	        	setbuf(stdin, NULL); 
	            printf("\n Nome da embarcacao: ");
	            setbuf(stdin, NULL);
	            gets(lx);
	            TrocaEspacoTrocaAnderline(lx,' ','_');  // strcasecmp ou strcmp só comparara até o espaço digitado, troca-se o espaço pro anderline então para ler o char completo;
	            if((strcasecmp(lx,"LINHA_1") != 0 ) && (strcasecmp(lx,"LINHA_2") != 0 ) && (strcasecmp(lx,"LINHA_3") != 0 ) && (strcasecmp(lx,"LINHA_4") != 0 )) {//strcasecmp: nao compara maiusculas e minusculas | strcmp: compara maiusculas e minusculas ///Valor 0 é verdadeiro - vetores são iguais
	            	TrocaEspacoTrocaAnderline(lx,'_',' ');
					printf("\n\n\n Embarcacao %s inexistente no porto!\n\n\n", lx);
					//system("pause");
	            } else {
	            	status = 1; // 1 - Aportou
//	            	Status (&fi, &l, status, lx); //status dar error aqui em lx
	            	i = DesemfileirarConteinerLista(&fi, &fi_aux, &fi_e, &l, c, c_aux, e, lx, status);
	            	Status (&fi, &l, i, lx);
	            }
	            system("pause");
	            break;
	        case 3:
	        	setbuf(stdin, NULL); 
				j = ImprimeEmbarcaoEmEspera (&l);
				if(j == 1) {
					f = DesenfileiraEmbarcacaoEmEspera(&l); //desenfileira a embarcacao da fila de espera e chama a funcao DesemfileirarConteinerLista();
					TrocaEspacoTrocaAnderline(f.EmbarcacaoEspera,'_',' ');
					strcpy(lx,f.EmbarcacaoEspera);
					printf("\n Verificando embarcacao em espera: %s\n", f.EmbarcacaoEspera);
					TrocaEspacoTrocaAnderline(f.EmbarcacaoEspera,' ','_'); 
					k = DesemfileirarConteinerLista(&fi, &fi_aux, &fi_e, &l, c, c_aux, e, lx, status);
					Status (&fi, &l, k, lx);
				}
	            system("pause");
	            break;
	        case 4:
	            ImprimeFilaConteiner(&fi);
	            ImprimeFilaEmbarcacao(&fi_e);
	            system("pause");
	            break;
	        case 5:
	            TamanhoFilaConteiner(&fi);
	            TamanhoFilaEmbarcacao(&fi_e);
	            TamanhoListaEmbarcacao(&l);
	            system("pause");
	            break;
	        case 6:
	        	setbuf(stdin, NULL);
	        	printf("\n -------- BUSCAR --------\n [1] Fila de conteiners\n [2] Fila de embarcacao\n [3] Embarcacao em espera\n\n");
	        	printf(" Buscar: ");
	        	scanf("%d", &busca);
	        	EscolheBusca (&fi, &fi_e, &l, busca);
	        	system("pause");
	        	break;
	        case 7:
	        	ImprimeFilaConteinerAux (&fi_aux);
	        	system("pause");
	            break;
	        case 0:
	        	printf("\n\n\n Encerrado!\n\n\n");
	        	exit(0);
	        	system("pause");
	            break;
	        default:
	        	while(getchar()!='\n'){};
				printf("\n\n\n Opcao Inexistente!\n\n\n");
				system("pause");
				break;
		}
    } while(op != 0);
	
	system("pause");
    return 0;
}

/*
FUNCOES:
	strcpy(onde será copiado, o que será copiado) //copia de um vetor de string para outro, já que naõ é possível fazer uma atribuição de igual em string;
	strupr(string); //strupr - transforma a string em caixa alta
	while(getchar()!='\n'){}; /*Limpa o buffer do teclado
	setbuf(stdin, NULL); //Limpa o buf do teclado
	system("cls"); //Limpa janela
*/  

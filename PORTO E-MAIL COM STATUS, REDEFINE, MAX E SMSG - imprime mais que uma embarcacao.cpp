#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 3 //10

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
	NO_Conteiner Lista_de_Conteiners;
    char Status[25];
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
	//char Status[25];
	struct LE *seg;
}NO_LE;

typedef struct {
	NO_LE *comeco;
	NO_LE *final;
	int qtd;
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
	l->qtd = 0;
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
	printf("\n\n\n Fila de Conteiner vazia!\n\n\n");
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
	printf("\n\n\n Fila Auxiliar de Conteiners vazia!\n\n\n");
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

//Trocar nome embarcacao espaço por anderline
void TrocaEspaco(char Linha[7], char encontra, char troca){
    for(int i=0;i<7;i++){
        if(Linha[i] == encontra){
            Linha[i] = troca;
        }
    }
}

//Trocar nome embarcacao anderline por espaço
void TrocaAnderline(char Linha[7], char encontra, char troca){
    for(int i=0;i<7;i++){
        if(Linha[i] == encontra){
            Linha[i] = troca;
        }
    }
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
    //return  *Novo_Conteiner;
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
    l->qtd--;
//	printf("\n Embarcacao desenfileirada da lista de espera: [%s]!\n\n", aux->EmbarcacaoEspera);
    return *aux;
    free(auxValor); //-> se dar o free antes de retornar imprime lixo
}

//Enfileirando conteiner na embarcacao
void EnfileiraConteinerEmbarcacao(Fila_e *fi_e, NO_Conteiner c, NO_Embarcacao e, char lx[7]) {	//pegando os valores desenfileirados e enfileirando na embarcacao
    NO_Embarcacao *Conteiner_embarcacao = (NO_Embarcacao*)malloc(sizeof(NO_Embarcacao));
    NO_Conteiner *aux;
//	printf("\n Conteiner com destino compativel com embarcacao %s:\nId [%d] | Destino [%d] | Origem [%s]!\n\n\n\n",lx, aux->id, aux->destino, aux->origem);
	if(Conteiner_embarcacao != NULL) {
		strcpy(Conteiner_embarcacao->nome, lx); //copia de um vetor de string para outro, já que naõ é possível fazer uma atribuição de igual //strcpy(onde será copiado, o que será copiado);
		Conteiner_embarcacao->Lista_de_Destinos = aux->destino;
		Conteiner_embarcacao->Lista_de_Conteiners.id = aux->id;
		Conteiner_embarcacao->Lista_de_Conteiners.destino = aux->destino;
		strcpy(Conteiner_embarcacao->Lista_de_Conteiners.origem, aux->origem); 
//		printf("\n Conteiner enfileirado na embarcacao %s:\nId [%d] | L. Destino [%d] | L. Origem [%s]!\n\n", Conteiner_embarcacao->nome, Conteiner_embarcacao->Lista_de_Conteiners.id, Conteiner_embarcacao->Lista_de_Conteiners.destino, Conteiner_embarcacao->Lista_de_Conteiners.origem);
	    Conteiner_embarcacao->seg = NULL;
		fi_e->qtde++;
	    //printf("qtd sim: [%d] !\n",fi_e->qtde);	
		//strcpy(Conteiner_embarcacao->Status,"Carregando");
	}
	if (fi_e->frente == NULL) {
		fi_e->frente = Conteiner_embarcacao; // novo no será o primeiro elemento da lista
//        printf("\n Primeiro conteiner enfileirado na embarcacao %s:\nId [%d] | L. Destino [%d] | L. Origem [%s]!\n\n", Conteiner_embarcacao->nome, Conteiner_embarcacao->Lista_de_Conteiners.id, Conteiner_embarcacao->Lista_de_Conteiners.destino, Conteiner_embarcacao->Lista_de_Conteiners.origem);
    } 
	else {   // se lista não estiver vazia o ultimo nó aponta para novo nó
        fi_e->tras->seg = Conteiner_embarcacao;
        //printf("\n Conteiner [%d] enfileirado no fim da embarcacao!\n\n", Conteiner_embarcacao->Lista_de_Destinos);
//        printf("\n Conteiner enfileirado no fim da embarcacao %s:\nId [%d] | L. Destino [%d] | L. Origem [%s]!\n\n", Conteiner_embarcacao->nome, Conteiner_embarcacao->Lista_de_Conteiners.id, Conteiner_embarcacao->Lista_de_Conteiners.destino, Conteiner_embarcacao->Lista_de_Conteiners.origem);
	}
	fi_e->tras = Conteiner_embarcacao; // fim indica um novo nó
}

//Pega conteiner  não enfileirado e enfileria na fila aux
NO_Conteiner FilaConteinerNaoEmbarcado (Fila *fi, FilaAux *fi_aux, NO_Conteiner c, NO_ConteinerAux c_aux) {
	NO_ConteinerAux *NE_Conteiner = (NO_ConteinerAux*)malloc(sizeof(NO_ConteinerAux));
	NO_Conteiner *usa;
//	printf("\n Conteiner com destino incompativel com embarcacao:\nId [%d] | Destino [%d] | Origem [%s]!\n\n\n\n", usa->id, usa->destino, usa->origem);
	if(NE_Conteiner != NULL) {
	    NE_Conteiner->id_aux = usa->id;
		NE_Conteiner->destino_aux = usa->destino;
	    strcpy(NE_Conteiner->origem_aux,usa->origem);
	    NE_Conteiner->prox_aux = NULL;
	    fi_aux->tam_aux++;
//	    printf("tam NE: [%d] !\n",fi_aux->tam_aux);
	}
    if (fi_aux->inicio_aux == NULL) { //se lista não estiver vazia
        fi_aux->inicio_aux = NE_Conteiner; // novo_conteiner será o primeiro elemento da lista
//        printf("\n Primeiro conteiner enfileirado na fila aux: Id [%d] | Destino [%d] | Origem [%s]!\n\n", usa->id, usa->destino, usa->origem);
    } 
	else { //se lista não estiver vazia
        // ultimo nó aponta para novo nó
        fi_aux->fim_aux->prox_aux = NE_Conteiner;
//        printf("\n Conteiner enfileirado no fim da fila aux: Id [%d] | Destino [%d] | Origem [%s]!\n\n", usa->id, usa->destino, usa->origem);
    }
    fi_aux->fim_aux = NE_Conteiner; // fim indica um novo nó									
}

//Nao enfileirando conteiner na embarcacao
void NaoEnfileiraConteinerEmbarcacao(Fila *fi, FilaAux *fi_aux, Fila_e *fi_e, NO_Conteiner c, NO_ConteinerAux c_aux, NO_Embarcacao e, char lx[7]) {
	NO_Embarcacao *Conteiner_embarcacao;
//	printf("\n Conteiner com destino incompativel com embarcacao %s:\nId [%d] | Destino [%d] | Origem [%s]!\n\n\n\n", lx, fi->inicio->id, fi->inicio->destino, fi->inicio->origem);
	DesenfileiraConteinerFila(fi, c);
	FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
}

char ListarEmbarcaoEmEspera (Lista_E *l, char lx[7]) {
	NO_LE *ListaEmbarcacao = (NO_LE*)malloc(sizeof(NO_LE));
//	printf("Comeco: %s\n",l->comeco->EmbarcacaoEspera);
//	printf("Final: %s\n",l->final->EmbarcacaoEspera);
//	printf("Seg: %s\n",ListaEmbarcacao->seg->EmbarcacaoEspera);
//	printf("Embarc list: %s\n",lx);
//	if((strcasecmp(lx,l->comeco->EmbarcacaoEspera) == 0 ) || strcasecmp(lx,ll->final->EmbarcacaoEspera)) == 0 )) {
//		//nao enfileira lx;
//	} else{
//		//enfileira lx;
//	}
	if(ListaEmbarcacao != NULL) {
//		printf("Seg: %s\n",ListaEmbarcacao->seg->EmbarcacaoEspera);
		//	printf("Embarc list: %s\n",lx);
        strcpy(ListaEmbarcacao->EmbarcacaoEspera, lx);
		ListaEmbarcacao->seg = NULL;
        l->qtd++;
    }
    if (l->comeco == NULL) { //se lista não estiver vazia
        l->comeco = ListaEmbarcacao; // novo_conteiner será o primeiro elemento da lista
//        printf("\nPrimeiro conteiner enfileirado:");
//        printf("\n Primeira embarcacao em espera enfileirada: [%s]!\n\n", lx);
    } 
	else { //se lista não estiver vazia o ultimo nó aponta para novo nó
        l->final->seg = ListaEmbarcacao;
//        printf("\n Embarcacao em espera enfileirada no fim da fila: [%s]!\n\n", lx);
//        printf("\n Conteiner enfileirado no fim da fila:");
    }
    l->final = ListaEmbarcacao; 
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

//Redefinindo FilaConteiner e FilaConteinerAux
NO_ConteinerAux Redefine (Fila *fi, FilaAux *fi_aux, NO_Conteiner c, NO_ConteinerAux c_aux) {
	NO_Conteiner *a;
	NO_ConteinerAux *b;
	while(fi->inicio != NULL){ //passa todos os conteiners da fila de conteiners //pode ser dentro da DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
		*a = DesenfileiraConteinerFila(fi, c);
		FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
	}
	while( fi_aux->inicio_aux != NULL){ //passa todos os conteiners da fila de conteiners auxiliar //pode ser dentro da DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
		*b = DesenfileiraConteinerFilaAux(fi_aux, c_aux); //erro nessa função //questão NULL
		EnfileiraConteinerFila (fi, b->id_aux, b->destino_aux, b->origem_aux);
	}
	return *b;
}

///Status
void Status (Fila *fi, Lista_E *l, int &status, char lx[7]) { //na funcao desenfileira e retornar o int status
//	printf("\n STATUS: %d\n", status);
	if(status == 2) {
			//printf("\n Status:\n NAVEGANDO!\n\n");
			//printf("\n Status:\n NAVEGANDO: esta cheia ou nao ha mais conteiners para seus destinos.\n\n");
			//strcpy(e->Status,"Navegando");
			printf("\n\n ---------------------------");
			TrocaAnderline(lx,'_',' ');
			strupr(lx);
			printf("\n  EMBARCACAO   [ %s]", lx);
			TrocaAnderline(lx,'_',' ');
			printf("\n ---------------------------\n"); 
			printf("  STATUS    |   NAVEGANDO\n");
			printf(" ---------------------------\n\n\n"); 
	} else {
			if(status == 1) { //fi_e->qtde == 0
				//printf("\n Status:\n APORTOU!\n\n");
				//printf("\n Status:\n APORTOU: esta vazia e sera carregada.\n\n");
				//strcpy(e->Status,"Aportou");
				printf("\n\n ---------------------------");
				TrocaAnderline(lx,'_',' ');
				strupr(lx);
				printf("\n  EMBARCACAO   [ %s]", lx);
				TrocaAnderline(lx,'_',' ');
				printf("\n ---------------------------\n"); 
				printf("  STATUS    |   APORTOU\n");
				printf(" ---------------------------\n\n\n"); 
			} else {
				if(status = 3) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila
					//printf("\n Status:\n EM ESPERA!\n\n");
					//printf("\n Status:\n EM ESPERA: nao ha nenhum conteiner para seus destino.\n\n");
					//strcpy(e->Status,"Em espera");
					printf("\n\n ---------------------------");
					TrocaAnderline(lx,'_',' ');
					strupr(lx);
					printf("\n  EMBARCACAO   [ %s]", lx);
					TrocaAnderline(lx,'_',' ');
					printf("\n ---------------------------\n"); 
    				printf("  STATUS    |   EM ESPERA\n");
    				printf(" ---------------------------\n\n\n"); 
					ListarEmbarcaoEmEspera (l, lx);
				}
			}
	} 
//	printf("\n STATUS: %d\n", status);
	//fila destrutor embarcacao -> status == 2;
	//return status;
}

//Desenfileirando conteiner e enfileirando na embarcacao
int DesemfileirarConteinerLista(Fila *fi, FilaAux *fi_aux, Fila_e *fi_e, Lista_E *l, NO_Conteiner c, NO_ConteinerAux c_aux, NO_Embarcacao e, char lx[7], int &status) {
    NO_Conteiner *aux, *auxValor;
    NO_ConteinerAux *d;
    NO_Embarcacao *Conteiner_embarcacao = (NO_Embarcacao*)malloc(sizeof(NO_Embarcacao));
    int cont = 0, embarc = 0;
//	printf("\nstatus - Aportou <- 1 -> : %d\n", status);
    if(fi->inicio != NULL) {  // Caso todos os elementos forem removidos da fila e o inicio for igual a NULL
    // cont <= 9 // Remove até 10 conteiners da fila e põe-os na embarcação de acordo com seus destinos compatíveis com a embarcação
		//printf("\nDestino a desenfileirar da fila: [%d] !\n\n",fi->inicio->destino);
	    embarc = VerificaCaseEmbarcacao (lx);
//	    printf("Embarcacao verificada = %d\n\n", embarc);
//		printf("\n MAX = %d\n\n", MAX);
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
//						printf("\ntam fi -nfe- %d\n", fi->tam);
//						printf("\ntam cont fi -nfe- %d\n", cont);
//						printf("\ntam fi -aux- %d\n", fi_aux->tam_aux);
						if(cont == fi_aux->tam_aux) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila
							status = 3;
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
					//printf("status - navegando <- 2 -> : %d\n", status);
					//Redefine (fi, fi_aux, c, c_aux); //se tiver conteiner dps de cheia da problema
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						DesenfileiraConteinerFila(fi, c); //sem questao null
						FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); //sem questao null
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}		
				}
				//system ("pause");
				break;
			case 2: // 'LINHA 2'
				while(fi->inicio != NULL && fi_e->qtde <= MAX-1) { // || fi_e->qtde <= 2) // && cont <= 3 //contar com posicao 0
					if(fi->inicio->destino == 2 || fi->inicio->destino == 3 ||fi->inicio->destino == 5) {	
						DesenfileiraConteinerFila(fi, c);
	    				EnfileiraConteinerEmbarcacao(fi_e, c, e, lx);
					} else { // Conteiner fica aguandando na fila até a próxima embarcação com vaga e destino compatível
						NaoEnfileiraConteinerEmbarcacao(fi, fi_aux, fi_e, c, c_aux, e, lx);	
						cont++;
						if(cont == fi_aux->tam_aux) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila aux
							status = 3;
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
//					Redefine (fi, fi_aux, c, c_aux);
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
							DesenfileiraConteinerFila(fi, c);
							FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}	
				}
				//system ("pause");
				break;
			case 3: // 'LINHA 3'
				while(fi->inicio != NULL && fi_e->qtde <= MAX-1) { // || fi_e->qtde <= 2) // && cont <= 3 //contar com posicao 0
					if(fi->inicio->destino == 1 || fi->inicio->destino == 7 ||fi->inicio->destino == 6) {
						DesenfileiraConteinerFila(fi, c);
	    				EnfileiraConteinerEmbarcacao(fi_e, c, e, lx);
					} else { // Conteiner fica aguandando na fila até a próxima embarcação com vaga e destino compatível
						NaoEnfileiraConteinerEmbarcacao(fi, fi_aux, fi_e, c, c_aux, e, lx);	
						cont++;
						if(cont == fi_aux->tam_aux) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila aux
							status = 3; 
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
//					Redefine (fi, fi_aux, c, c_aux);
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
							DesenfileiraConteinerFila(fi, c);
							FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}		
				}
//				system ("pause");
				break;
			case 4: // 'LINHA 4'
				while(fi->inicio != NULL && fi_e->qtde <= MAX-1) { // || fi_e->qtde <= 2) // && cont <= 3 //contar com posicao 0
					if(fi->inicio->destino >= 1 && fi->inicio->destino <= 3) {
						DesenfileiraConteinerFila(fi, c);
	    				EnfileiraConteinerEmbarcacao(fi_e, c, e, lx);
					} else { // Conteiner fica aguandando na fila até a próxima embarcação com vaga e destino compatível
						NaoEnfileiraConteinerEmbarcacao(fi, fi_aux, fi_e, c, c_aux, e, lx);	
						cont++;
						if(cont == fi_aux->tam_aux) { //qtd conteiner nao enfileirados == qtd de conteiners existentes na fila aux
							status = 3;
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
//					Redefine (fi, fi_aux, c, c_aux);
					while(fi->inicio != NULL){ //para passar todos os conteiners da fila de conteiners //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						DesenfileiraConteinerFila(fi, c);
						FilaConteinerNaoEmbarcado (fi, fi_aux, c, c_aux);
					}	
					while(fi_aux->inicio_aux != NULL){ //para passar todos os conteiners da fila de conteiners auxiliar //pode ser dentro da desenfileriaDesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						*d = DesenfileiraConteinerFilaAux(fi_aux, c_aux); 
						EnfileiraConteinerFila (fi, d->id_aux, d->destino_aux, d->origem_aux);
					}		
				}
//				system ("pause");
				break;
		}
//		printf("\nstatus - fim case - : %d\n", status);
//		} else { // Alcançou o limite de 10 conteiners
//			printf("Embarcação cheia!\n\n");
//			//FilaEmbarcacaoDestrutor(fi_e);
//		}
    } else {
    	fi->fim=NULL; // Caso o inicio esteja vazio então o fim também ficará
        //printf("Inicio = %s\nFim = %s",fi->inicio,fi->fim);
//        printf("\n Fila de conteiners vazia!\n\n");
        //se VerificaEmbarcacao() e stutus for igual a embarcacao navegando da um FilaDestrutorEmbarcacao();
        status = 3;
    } 
    //status = Status (fi, l, status, lx); // passar cont
    //printf("\nEMBARCACAO: %s\n", lx);
    //printf("\nQtd conteiner nao enfileirado - fim funcao  - : %d\n", cont);
//    printf("\nstatus - fim funcao - : %d\n", status);
    //system ("pause");
    return status;
}

//Imprimindo
void ImprimeFilaConteiner (Fila *fi) {
    NO_Conteiner *atual; // ponteiro para ImprimeFilaConteiner a fila
    atual = fi->inicio;
    int enu = 1;
//    printf("| %d ° Id [%d] | Destino [%d] |  Origem [%s]  |\n", enu, atual->id, atual->destino, atual->origem);
//	printf("\n tam = %d\n", fi->tam);
    if(atual == NULL) {
    	printf("\n --------------------------------\n");
		printf("         FILA CONTEINER\n");
		printf(" --------------------------------");
        printf("\n 0 Conteiners na fila\n");
        printf("\n --------------------------------\n\n\n");
    }
    else {
    	printf("\n -----------------------------------------\n");
		printf("               FILA CONTEINER            \n"); //40 char
    	printf(" -----------------------------------------\n"); //43 char - 41 - e 2 colunas
	    while (atual != NULL) {
	        printf("  %d ° Id [%d] | Destino [%d] |  Origem [%s]  \n", enu, atual->id, atual->destino, atual->origem);
	        atual = atual->prox;
	        enu++;
	    }
	   	printf(" -----------------------------------------\n\n");
    }
}

void ImprimeFilaConteinerAux (FilaAux *fi_aux) {
    NO_ConteinerAux *atual_aux; // ponteiro para ImprimeFilaConteinerAux a fila
    atual_aux = fi_aux->inicio_aux;
    int enu_aux = 1;
//    printf("| %d ° Id [%d] | Destino [%d] |  Origem [%s]  |\n", enu, atual->id, atual->destino, atual->origem);
//	printf("\n tam = %d\n", fi_aux->tam_aux);
    if(atual_aux == NULL)  {  //fi->tam == 0 : nao deu certo
    	printf("\n -------- FILA CONTEINER AUX --------\n");
        printf("\n 0 Conteiners na fila auxiliar\n\n\n");
    }
    else {
    	printf("\n -----------------------------------------\n");
		printf("            FILA CONTEINER AUX           \n");
    	printf(" -----------------------------------------\n");
	    while (atual_aux != NULL) {
	        printf("  %d ° Id [%d] | Destino [%d] |  Origem [%s]  \n", enu_aux, atual_aux->id_aux, atual_aux->destino_aux, atual_aux->origem_aux);
	        atual_aux = atual_aux->prox_aux;
	        enu_aux++;
	    }
	   	printf(" -----------------------------------------\n\n\n");
    }
}

void ImprimeFilaEmbarcacao (Fila_e *fi_e) {
	NO_Embarcacao *atual_e; // ponteiro para ImprimeFilaEmbarcacao a fila
	atual_e = fi_e->frente;
	//printf("\n\n  %d ° Nome [%s] | L. Destino [%d] | L. Conteiner [%d] | Status [%s]!\n\n  ", enu_e, atual_e->nome, atual_e->Lista_de_Destinos, atual_e->Lista_de_Conteiners, atual_e->Status);
//	printf(" qtd = %d\n", fi_e->qtde);
	if(atual_e == NULL) { //fi_e->qtde
		printf("\n --------------------------------\n");
		printf("          EMBARCACAO\n");
		printf(" --------------------------------");
	    printf("\n 0 Conteiners na embarcacao\n");
	    printf("\n --------------------------------\n\n\n");
	}
	else {
//		printf("\n frente = %d\n", fi_e->frente->Lista_de_Destinos);
//		printf(" tras = %d\n", fi_e->tras->Lista_de_Destinos);
		TrocaAnderline(atual_e->nome,'_',' '); // para imprimir sem o anderline, agora troca-se o anderline pelo espaço
		strupr(atual_e->nome); //strupr - transforma a string em caixa alta
		printf("\n ------------------------------------------------------------------\n");
		printf("                            EMBARCACAO\n");
		printf(" ------------------------------------------------------------------\n");
		printf("    NOME    |   L. DESTINOS   |           L. CONTEINERS     \n");
		printf(" ------------------------------------------------------------------\n");
		printf("  [%s] ", atual_e->nome);
        while(atual_e != NULL) {
//        	TrocaAnderline(atual_e->nome,'_',' '); // para imprimir sem o anderline, agora troca-se o anderline pelo espaço
//			strupr(atual_e->nome); //strupr - transforma a string em caixa alta
        	printf("|        [%d]      |", atual_e->Lista_de_Destinos);
        	printf(" Id [%d] - Destino [%d] - Origem [%s]\n", atual_e->Lista_de_Conteiners.id, atual_e->Lista_de_Conteiners.destino, atual_e->Lista_de_Conteiners.origem); //Id [%d] | Destino [%d] |  Origem [%s]  |\n!
        	//printf(" Status [%s]\n", atual_e->Status);
			TrocaAnderline(atual_e->nome,'_',' '); 
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
			TrocaAnderline(ListaEmbarcacao->EmbarcacaoEspera,'_',' '); // para imprimir sem o anderline, agora troca-se o anderline pelo espaço
			strupr(ListaEmbarcacao->EmbarcacaoEspera); //strupr - transforma a string em caixa alta
			printf(" %s\n", ListaEmbarcacao->EmbarcacaoEspera);
			TrocaAnderline(ListaEmbarcacao->EmbarcacaoEspera,'_',' ');
			ListaEmbarcacao = ListaEmbarcacao->seg;
		}
		printf("\n ---------------------------\n\n");
		return 1;
	}
}

//Tamanho
void TamanhoFilaConteiner(Fila *fi) {
    if(fi->tam == 0) {
    	printf("\n Fila de Conteiners vazia!\n\n\n");
    }
	else {
		printf("\n Exitem %d Conteiners na fila!\n\n\n",fi->tam);
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

//Buscando
void BuscaFilaConteiner(Fila *fi, int x) {
    NO_Conteiner *aux = fi->inicio;
    int achou = 0;
	while(aux != NULL && !achou) {
        if(x == aux->id) {
            printf("\n Conteiner [%d] encontrado na fila!\n\n\n",aux->id);
            achou = 1;
        }
        aux = aux->prox;
    }
	if(achou == 0) {
    	 printf("\n Conteiner [%d] inexistente na fila!\n\n\n", x);
    }
}

void BuscaFilaConteinerEmbarcacao(Fila_e *fi_e, int x_e) {
    NO_Embarcacao *aux_e = fi_e->frente;
    int encontrou = 0;
	while(aux_e != NULL && !encontrou) {
        if(x_e == aux_e->Lista_de_Destinos) {//aux_e->nome // x tem q ser string {
            printf("\n Conteiner [%d] encontrado na fila!\n\n\n",aux_e->nome);
            encontrou = 1;
        }
        aux_e = aux_e->seg;
    }
	if(encontrou == 0) {
    	 printf("\n Conteiner [%d] inexistente na fila!\n\n\n", x_e);
    }
}

bool VerificaId (int &x) { //
	if(x < -1000000|| x > 1000000) { //Tratar string em if //inteiro suporta até qntos?
    	printf("\n Id invalido!\n\n");
    	return false;
    } else {
    	return true;
    }
}

bool VerificaDestino (int &y) { //Destino válido de 1 a 6;
    if(y<1 || y>6) {
        printf("\n Destino indisponivel no porto!\n\n");
        return false;
    } else {
    	return true;
    }
}

bool VerificaEnfileira (int &x) { //int (VerificaId) (int x), bool (VerificaDestino) (int y)
	bool id;
	id = VerificaId (x);
	if( id == false) { //VerificaDestino (y) != 0 || VerificaDestino (y) != 0) {
		printf("\n Conteiner nao enfileira!\n\n");
		return false;
	}
}

void VerificaEncerrar () { //Verifica se o usuário realmente deseja sair do programa
	int op;
	printf("\n Deseja realmente sair?\n\n [1] Sim\n [2] Nao\n");
	scanf(" %d",&op);
	if(op == 1) {
		printf("\n Encerrado!\n\n\n");
		exit(0);
	} else {
		printf("\n Opcao invalida!\n\n\n");
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
	printf("\n -------- MENU --------\n [1] Chega conteiner\n [2] Chega embarcacao\n [3] Verifica embarcacao em espera\n [4] Mostra\n [5] Tamanho\n [0] Sair\n\n");		
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
    int op, x, y, w, s, status = 0, i, j, k;
    char z[10], lx[7];

//	CABECALHO();	
    inicializaFilaConteiner(&fi);
    inicializaFilaConteinerAux(&fi_aux);
    inicializaFilaEmbarcacao(&fi_e);
    IniciaListaEmbarcacao(&l);
    	
    do {
		system("cls"); //Limpa janela
		MENU();
        printf(" Opcao: ");
        setbuf(stdin, NULL); //Limpa o buf do teclado  // while(getchar()!='\n'){}; /*Limpar o buffer do teclado*/
		scanf(" %d", &op);
        switch(op) {
	        case 1:
	           printf("\n Id do conteiner: ");
	            scanf(" %d",&x);
	            while(getchar()!='\n'){};        
	            printf("\n Destino do conteiner: ");
	            setbuf(stdin, NULL);
	            scanf(" %d",&y);
				while(getchar()!='\n'){}; 
	            printf("\n Origem do conteiner: "); //verifica com teclado...; // usar a tabela ASCII. Se o numero correspondente as letras forem digitados, e so colocar um laço de valor invalido.
	            setbuf(stdin, NULL); //Limpa o buf do teclado para ler o char
	            gets(z);
//	            if((VerificaId (x) != 0) || (VerificaDestino (y) != 0)) { //true == 0;
//	            	printf("\nConteiner nao enfileira!\n\n");
//	            }
	            if(y<1 || y>6 || x < 0 || x > 1000000) {
	            	if(x < 0 || x > 1000000) { //Tratar string em if
		            	printf("\nId invalido!\n\n");
		            }
		            if(y<1 || y>6) {
		            	printf("\n\n\n Destino indisponivel no porto!\n");
		            }
	            	printf("\n Conteiner nao enfileira!\n\n");
	            	
	            }
	            else {
					EnfileiraConteinerFila(&fi, x, y, z);
	            }
	            printf("\n\n\n");
	            system("pause");
	            break;
	        case 2:
//	        	printf("\n --------------\n   Embarcacoes\n --------------\n   LINHA 1\n   LINHA 2\n   LINHA 3\n   LINHA 4\n --------------\n\n");
	            printf("\n Nome da embarcacao: ");
	            setbuf(stdin, NULL); //Limpa o buf do teclado para ler o char
	            gets(lx);
	            TrocaEspaco(lx,' ','_');  // strcasecmp ou strcmp só comparara até o espaço digitado, troca-se o espaço pro anderline então para ler ochar completo
	            //printf("\n Embarcacao digitada: %s\n", lx);
	            if((strcasecmp(lx,"LINHA_1") != 0 ) && (strcasecmp(lx,"LINHA_2") != 0 ) && (strcasecmp(lx,"LINHA_3") != 0 ) && (strcasecmp(lx,"LINHA_4") != 0 )) {//strcasecmp: nao compara maiusculas e minusculas | strcmp: compara maiusculas e minusculas ///Valor 0 é verdadeiro - vetores são iguais
	            	TrocaAnderline(lx,'_',' ');
					printf("\n\n\n Embarcacao %s inexistente!\n\n\n", lx);
					system("pause");
	            } else {
	            	status = 1; // 1 - Aportou
//	            	Status (&fi, &l, status, lx);
	            	//DesemfileirarConteinerLista(&fi, &fi_aux, &fi_e, &l, c, c_aux, e, lx, status);
	            	i = DesemfileirarConteinerLista(&fi, &fi_aux, &fi_e, &l, c, c_aux, e, lx, status);
	            	Status (&fi, &l, i, lx);
	            }
	            system("pause"); //repeti duas vezes contando com o break, caso emfileirena embarcacao;
	            break;
	        case 3:
//	        	printf("\n ---- STATUS ----\n\n [1] Aportou\n [2] Navegando\n [3] Em espera\n\n");
				j = ImprimeEmbarcaoEmEspera (&l);
//				desenfileira a embarcacao da fila de espera e joga na funcao DesemfileirarConteinerLista(&fi, &fi_aux, &fi_e, &l, c, c_aux, e, lx, status);
				if(j == 1) {
					f = DesenfileiraEmbarcacaoEmEspera(&l);
//					printf("\nEmb. des. main: %s\n\n", f.EmbarcacaoEspera);
					printf("\n Verificando embarcacao em espera: %s\n", f.EmbarcacaoEspera);
					strcpy(lx,f.EmbarcacaoEspera);
					k = DesemfileirarConteinerLista(&fi, &fi_aux, &fi_e, &l, c, c_aux, e, lx, status);
					Status (&fi, &l, i, lx);
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
	            printf("\n\n\n");
	            TamanhoFilaEmbarcacao(&fi_e);
	            system("pause");
	            break;
	        case 6:
	        	ImprimeFilaConteinerAux (&fi_aux);
	        	system("pause");
	            break;
	        case 0:
	        	printf("\nEncerrado!\n\n");
	        	exit(0);
	        	system("pause");
	            break;
	        default:
	        	while(getchar()!='\n'){}; /*Limpar o buffer do teclado*/
				printf("\nOpcao Inexistente!\n\n");
				system("pause");
				break;
		}
    } while(op != 0);
	
	system("pause");
    return 0;
}

/*
OBS:
	Ver se pode ser qualquer origem;
	Ver se é necessario guardar embarcacaoes em espera;
	
*/

//embarcacao chega : verifica e passa toda a fila de conteiner, dps proxima embarcacao;  

/*
FUNCOES:
	strcpy(onde será copiado, o que será copiado) //copia de um vetor de string para outro, já que naõ é possível fazer uma atribuição de igual em string;

*/  

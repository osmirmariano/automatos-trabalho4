#include <iostream>
#include <string>

using namespace std;

class Fila{
	public:
		typedef struct{
			string estado;
			char simbolo;
		}TRANS;

		typedef struct no{
			TRANS conteudo;
			struct no *prox;
		}NO_FILA;

		typedef struct {
			NO_FILA *inicio;
			NO_FILA *fim;
		}FILA;

	public:
		Fila(){
			FILA *fila;
			fila = NULL;
			fila->inicio = NULL;
			fila->fim = NULL;
		}

		~Fila();

		//INÍCIO DA FUNÇÃO ENFILEIRAR FILA
		void enfileirar(FILA *fila, TRANS dados){
			//NO_FILA *novo = (NO_FILA*) malloc(sizeof(NO_FILA));
			NO_FILA *novo = new NO_FILA();
			if(novo == NULL)
				cout << "Nada" << endl;
			else{
				novo->conteudo = dados;
				novo->prox = NULL;

				if(fila->fim == NULL)
					fila->inicio = novo;
				else
					fila->fim->prox = novo;
				fila->fim = novo;
			}
		};


		//INÍCIO DA FUNÇÃO DESENFILEIRAR
		void desenfileirar(FILA *fila){
			//NO_FILA *novo = (NO_FILA*) malloc(sizeof(NO_FILA));
			NO_FILA *aux = new NO_FILA();
			if(aux == NULL)
				cout << "Nada" << endl;
			else{
				fila->inicio = fila->inicio->prox;
				if(fila->inicio == NULL){
					fila->inicio = NULL;
					delete[] aux;
				}
				else
					fila->fim = fila->fim->prox;
			}
		}

	
};
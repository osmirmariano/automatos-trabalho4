#include <iostream>
#include <string>

using namespace std;

class Fila{
	public:
		typedef struct {
            int indice[];//Para armazenar os estados
            int quantidade;
        }TRANS;

        typedef struct no{
        	//TRANS conteudo;
            struct no *prox;
        }NO_FILA;

        typedef struct {
            NO_FILA *inicio;
            NO_FILA *fim;
        }FILA;

    public:
		Fila(){

		};

		~Fila();

		void enfileirar (FILA *fila){ // Enfileirar // queue
            NO_FILA *novo = new NO_FILA();


            if(novo == NULL)
                cout << "Não existe nada cadastrado" << endl;
            else{
                //novo->conteudo = dados;
                novo->prox = NULL;

                if(fila->fim == NULL)
                    fila->inicio = novo;
                else
                    fila->fim->prox = novo;
                fila->fim = novo;
                //novo->conteudo.quantidade++;
            }
        };

        void desenfileirar (FILA *fila){ //Desenfileirar
	        NO_FILA *aux = new NO_FILA();

	        if(aux == NULL)
	            cout << "Fila Vazia" << endl;
	        else{
	            fila->inicio = fila->inicio->prox;

	            if(fila->inicio == NULL){
	                fila->inicio = NULL;
	                delete(aux);
	            }
	            else
	                fila->fim = fila->fim->prox;
        	}
        };

};

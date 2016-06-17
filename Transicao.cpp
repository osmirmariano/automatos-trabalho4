#include <iostream>
#include <string>

using namespace std;

class Transicao{
    public:
        typedef struct {
            int indice[];//Para armazenar os estados
            int quantidade;
        }TRANS;

        typedef struct no{
            struct no *prox;
        }NO_FILA;

        typedef struct {
            NO_FILA *inicio;
            NO_FILA *fim;
        }FILA;

    public:
        Transicao(){

        };

        ~Transicao();

        void queue(FILA *fila){ // Enfileirar
            NO_FILA *novo = new NO_FILA();
            if(novo == NULL)
                cout << "Não existe memória" << endl;
            else{
                //novo->conteudo = dados;
                novo->prox = NULL;

                if(fila->fim == NULL)
                    fila->inicio = novo;
                else
                    fila->fim->prox = novo;
                fila->fim = novo;
            }
        }

        void dequeue (FILA *fila){ //Desenfileirar
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
        }

        void transicaoEstendida(FILA *fila, string palavra){
            NO_FILA *retorno = NULL;
            NO_FILA *aux =  palavra;
            int tam = palavra.length();
            for(int x = 0; x < tam-1; x++){
                 cout << "PALAVRA: " << palavra[x] << endl;
            }
        }

};

#include <iostream>
#include <istream>
#include <string>
//#include "Transicao.cpp"
using namespace std;

    typedef struct{
        string nomeEstados;
        string palavra;
        int qtdEstados;
        string funTransicao;
        string estadoInicial;
        string estadoFinal;
    }ESTADO;

    typedef struct {
        ESTADO estados;
        int indice[];//Para armazenar os estados
        int quantidade;
    }TRANS;

    typedef struct no{
        TRANS conteudo;
        struct no *prox;
    }NO_FILA;

    typedef struct {
        NO_FILA *inicio;
        NO_FILA *fim;
    }FILA;

    void criaFila (FILA *fila){
        fila = NULL;
    }

    void enfileirar(FILA *fila, TRANS dados, string estado){ // Enfileirar // queue
        cout << " aqui " << endl;
        NO_FILA *novo = new NO_FILA();
        if(novo == NULL)
            cout << "Não existe memória" << endl;
        else{
            novo->conteudo = dados;
            novo->prox = NULL;
            cout << " aqui1 " << endl;
            if(fila->fim == NULL){
                cout << " aqui1i " << endl;
                fila->inicio = novo;
                cout << " aqui2 " << endl;
            }
            else{
                cout << " aquiesle " << endl;
                fila->fim->prox = novo;
                cout << " aqui3 " << endl;
                }
            fila->fim = novo;
            novo->conteudo.quantidade++;
        }
    }

    void dequeue(FILA *fila){ //Desenfileirar
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

        /*void transicaoEstendida(FILA *fila, string palavra){
            NO_FILA *retorno = NULL;
            NO_FILA *aux =  palavra;
            int tam = palavra.length();
            for(int x = 0; x < tam-1; x++){
                 cout << "PALAVRA: " << palavra[x] << endl;
            }
        }*/

    void funcaoTransicaoEstendida(TRANS d, string palavra){
        FILA *f = NULL;
        int tam = 0, pertence = 0;
        string q0, q1, q2, q3, estado="q0";
        tam = palavra.length();

        for(int x = 0; x < tam; x++){
            if(palavra[x] != 'a' && palavra[x] != 'b'){
                pertence = 1;
            }
            else{
                if(estado == "q0"){
                    if(palavra[x] == 'a'){
                        enfileirar(f,d,"q0");
                        enfileirar(f,d,"q1");
                    }
                    else{
                        if(palavra[x] == 'b')
                            estado == "q0";
                    }
                }
                else{
                    if(estado == "q1"){
                        if(palavra[x] == 'a'){
                            estado = "q2";
                        }
                        else if(palavra[x] == 'b'){
                            estado = "q2";
                        }
                    }
                    else{
                        if(estado == "q2"){
                            if(palavra[x] == 'a'){
                                estado = "q3";
                            }
                            else if(palavra[x] == 'b'){
                                estado = "q3";
                            }
                        }
                        else{
                            if(estado == "q3"){
                                if(palavra[x] == 'a'){
                                    estado = "vazio";
                                }
                                else if(palavra[x] == 'b'){
                                    estado = "vazio";
                                }
                            }
                        }

                    }
                }
        }

        if(pertence == 0){
            cout << endl << " ESTADO RETORNADO: " << estado << endl;
            if (estado == "q3"){
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                cout << " \tESTADO " << estado << " É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
            else{
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA NÃO É ACEITA PELO O AUTÔMATO!" << endl;
                cout << "\tESTADO " << estado << " NÃO É FINAL" << endl;
                cout << "---------------------------------------------" << endl;
            }
        }
        else{
            cout << " A PALAVRA NÃO PERTENCE AO ALFABETO" << endl;
        }

    };
}



int main(){
    int opcao;
	string palavra;

	FILA *fila = NULL;
	TRANS d;
	ESTADO e;
	criaFila(fila);

    do{
        cout << endl << "---------------------------------------------" << endl;
        cout << "\t MENU PRINCIPAL" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 1 -- VISUALIZAR AFN" << endl;
        cout << " 2 -- FUNCAO DE TRANSICAO ESTENDIDA" << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OPCAO: ";
        cin >> opcao;
        cout << "---------------------------------------------" << endl << endl;

        switch(opcao){
            case 1:
                cout << endl << "----------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DE AUTÔMATOS" << endl;
                cout << "----------------------------------------------" << endl;
                break;
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t FUNÇÃO DE TRANSICAO ESTENDIDA " << endl;
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA: ";
                cin >> palavra;
                cout << "---------------------------------------------" << endl << endl;
                funcaoTransicaoEstendida(d,palavra);
                break;
            case 0:
                cout << "PROGRAMA ENCERRADO COM SUCESSO!" << endl;
                break;
            default:
                cout << "\tOPÇÃO INVÁLIDA. POR FAVOR, INFORME UMA VÁLIDA" << endl;
        };

    }while(opcao != 0);
    return 0;
};

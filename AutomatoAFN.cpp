#include <iostream>
#include <string>
#include <queue>
#include "Fila.cpp"

using namespace std;

class AutomatoAFN{
	public:
		typedef struct{
            string estados;
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
		AutomatoAFN(){
			FILA *fila;
			fila = NULL;
			fila->inicio = NULL;
			fila->fim = NULL;
		}
		~AutomatoAFN();
		Fila *fila = new Fila();
		//FUNÇÃO PARA MOSTRAR AFN
		void AFN(){
	        cout << " FUNÇÃO TRANSIÇÃO  |      a     |      b      " << endl;
	        cout << "----------------------------------------------" << endl;
	        cout << "      ->qo         |  {q0, q1}  |    {qo}     " << endl;
	        cout << "----------------------------------------------" << endl;
	        cout << "        q1         |    {q2}    |    {q2}     " << endl;
	        cout << "----------------------------------------------" << endl;
	        cout << "        q2         |    {q3}    |    {q3}     " << endl;
	        cout << "----------------------------------------------" << endl;
	        cout << "       *q3         |      &     |      &      " << endl;
	        cout << "----------------------------------------------" << endl;
	        cout << "\t& --> Conjunto vazio" << endl << endl;
	    };

	    //FUNAÇÃO DE TRANSIÇÃO
		FILA *funcaoTransicao(string estado, char simbolo){
            NO_FILA  *retorno = NULL;
            if(estado == "q0"){
            	retorno->conteudo.estado = "q0";
            	if(simbolo == 'a'){
            		retorno->conteudo.estado = "q1";
            	}
            }
            else if(estado == "q1"){
            	if(simbolo == 'a'){
            		retorno->conteudo.estado = "q2";
            	}
            }
            else if(estado == "q2"){
            	if(simbolo == 'a'){
            		retorno->conteudo.estado = "q3";
            	}
            }
        };

        //FUNÇÃO DE TRANSIÇÃO ESTENDIDA
        FILA  *funcaoTransicaoEstendida(string estado, string palavra){
        	string resto = "&";
        	char simbolo;
        	FILA *retorno = NULL;
        	int tamanho = palavra.length();
        	simbolo = palavra[tamanho-1];

        	if(palavra == "&")
        		return retorno;
        	//AQUI QUEBRAR resto
        	for(int x = 0; x < tamanho-2; x++){
        		resto = resto + "&";
        	}

        	for(int x = 0; x < tamanho-1; x++){
        		resto[x] = palavra[x];
        	}
        	FILA  *aux = funcaoTransicao(estado, resto);
        	while(aux != NULL){
        		FILA *temp = funcaoTransicao(fila->desenfileirar(aux), simbolo);
        		while(temp != NULL){
        			fila->enfileirar(retorno, fila->desenfileirar(temp));
        		}
        	}
        	return retorno;
        };

		//VERIFICAR SE PALAVRA PERTENCE ALFABETO
		int verificaPalavraPertence(string palavraInformada){
            int tamanho =  palavraInformada.length();
            int pertence = 0;
            for(int x = 0; x < tamanho; x++){
                if(palavraInformada[x] != 'a' && palavraInformada[x] != 'b'){
                    return 1;
                }
            }
            return 0;

        };

};

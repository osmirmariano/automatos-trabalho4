#include <iostream>
#include <string>

using namespace std;

class AutomatoAFN{
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
		AutomatoAFN(){
			FILA *fila;
			fila = NULL;
			fila->inicio = NULL;
			fila->fim = NULL;
		}
		~AutomatoAFN();

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

	    void criaFila (FILA *fila){
			fila = NULL;
		}

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

	    //FUNAÇÃO DE TRANSIÇÃO
		FILA *funcaoTransicao(string estado, char simbolo){
            FILA  *retorno = NULL;
            if(estado == "q0"){
            	retorno.estado = "q0";
            	if(simbolo == 'a'){
            		retorno.estado = "q1";
            	}
            }
            else if(estado == "q1"){
            	if(simbolo == 'a'){
            		retorno.estado = "q2";
            	}
            }
            else if(estado == "q2"){
            	if(simbolo == 'a'){
            		retorno.estado = "q3";
            	}
            }
        };

        //FUNÇÃO DE TRANSIÇÃO ESTENDIDA
        FILA  *funcaoTransicaoEstendida(string estado, string palavra, FILA *fila){
        	string resto = "&";
        	char simbolo;
        	FILA *retorno = NULL;
        	int tamanho = palavra.length();
        	simbolo = palavra[tamanho-1];
        	
        	if(palavra == "&")
        		return retorno;
        	//aQUI QUEBRAR resto
        	for(int x = 0; x < tamanho-2; x++){
        		resto = resto + "&";
        	}

        	for(int x = 0; x < tamanho-1; x++){
        		resto[x] = palavra[x];
        	}
        	fila  *aux = funcaoTransicao(estado, resto);
        	while(aux != NULL){
        		fila *temp = funcaoTransicao(fila->desenfileirar(aux), simbolo);
        		while(temp != NULL){
        			fila ->enfileirar(retorno, fila->desenfileirar(temp));
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

        int main(){
		    int opcao;
		    string *estado, palavraInformada;
		    FILA *fila = NULL;
		    
		    criaFila(&fila);

		    do{
		        cout << endl << "---------------------------------------------" << endl;
		        cout << "\t MENU PRINCIPAL" << endl;
		        cout << "---------------------------------------------" << endl;
		        cout << " 1 -- VISUALIZAR AUTÔMATO" << endl;
		        cout << " 2 -- FUNCAO DE TRANSICAO ESTENDIDA" << endl;
		        cout << " 0 -- SAIR " << endl;
		        cout << "---------------------------------------------" << endl;
		        cout << "OPCAO: ";
		        cin >> opcao;
		        cout << "---------------------------------------------" << endl << endl;

		        switch(opcao){
		            case 1:
		                cout << endl << "---------------------------------------------" << endl;
		                cout << "\t VISUALIZAÇÃO AUTÔMATO" << endl;
		                cout << "---------------------------------------------" << endl;
		                afn->AFN();
		                break;
		            case 2:
		                cout << endl << "---------------------------------------------" << endl;
		                cout << "\t FUNCAO DE TRANSICAO ESTENDIDA AFN " << endl;
		                cout << "---------------------------------------------" << endl;
		                cout << " INFORME PALAVRA: ";
		                cin >> palavraInformada;
		                cout << "---------------------------------------------" << endl;
		                estado = "q0";
		                if(verificaPalavraPertence(palavraInformada) == 0){
		                    estado = funcaoTransicaoEstendida(&estado, palavraInformada, fila);
		                    if (estado == "q3"){
		                        cout << "---------------------------------------------" << endl;
		                        cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
		                        cout << " \tESTADOS " << estado << " É FINAL" << endl;
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
		                    cout << " A PALAVRA NÃO PERTENCE AO ALFABETO {a,b}" << endl;
		                }
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
	
};
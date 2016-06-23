#include <iostream>
#include <istream>
#include <string>
using namespace std;


typedef struct{
    string nomeEstadoAtual;
    string simbolo;
    string estadosRetornados[];
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

void enfileirar(FILA *fila, TRANS dados){ // Enfileirar // queue
    cout << " aqui " << endl;
    NO_FILA *novo = new NO_FILA();
    if(novo == NULL)
        cout << "Não existe memória" << endl;
    else{
        novo->conteudo = dados;
        //novo->conteudo.estados.simbolo = simbolo;
       // novo->conteudo.estados.estadosRetornados = estado;
       //novo->conteudo.estados.estadosRetornados
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

void funcaoTransicaoEstendidaAFN(TRANS d,string palavra) {
    FILA *f = NULL;
	int tam = 0, cont = 0, pertence = 0, conta=0, contador=0;
	string ultSimbolo, vetor[10], estado = "q0", aux;
	tam = palavra.length();
	cout << "Tamanho: " << tam << endl;

	//Encontrando o último símbolo da palavra
    for(int x = tam-1; x >= 0; x--){
		cont++;
        for(int y = 0; y < tam-cont; y++){
        	ultSimbolo += palavra[y];
	    }
        cout << " PALAVRA: " << ultSimbolo << " | ÚLTIMO SÍMBOLO: " << palavra[x] << endl;
        cout << "---------------------------------------------" << endl;
        ultSimbolo ="";
    }


    for(int x = 0; x < tam; x++){
            aux = estado;
            if(palavra[x] != 'a' && palavra[x] != 'b'){
                pertence = 1;
            }
            else{
                cout << " estado q0" << endl;
                if(estado == "q0"){
                    if(palavra[x] == 'a'){
                        //cout << "qo";
                        estado = "q0";
                        vetor[conta] = estado;
                        //strcpy(vetor[conta],'q0');
                        cout << " V " << vetor[conta] << endl;
                        cout << "q1";
                        estado = "q1";
                        conta++;
                        vetor[conta] = estado;
                        cout <<  " V " << vetor[conta] << endl;

                        d.estados.nomeEstadoAtual = aux;
                        d.estados.simbolo = palavra[x];
                        estado = "q0";
                        d.estados.estadosRetornados[contador] = estado;
                        estado = "q1";
                        contador++;
                        d.estados.estadosRetornados[contador] = estado;
                        enfileirar(f,d);
                        //enfileirar(f,d,palavra[x],"q1");
                    }
                    else{
                        if(palavra[x] == 'b')
                            estado = "q0";
                            vetor[conta] = estado;

                    }
                }
                else{
                    cout << " estado q1" << endl;
                    if(estado == "q1"){
                        if(palavra[x] == 'a'){
                            estado = "q2";
                            vetor[conta] = estado;
                        }
                        else if(palavra[x] == 'b'){
                            estado = "q2";
                            vetor[conta] = estado;

                        }
                    }
                    else{ cout << " estado q2" << endl;

                        if(estado == "q2"){
                            if(palavra[x] == 'a'){
                                estado = "q3";
                                vetor[conta] = estado;
                            }
                            else if(palavra[x] == 'b'){
                                estado = "q3";
                                vetor[conta] = estado;
                            }
                        }
                        else{
                            cout << " estado q3" << endl;
                            if(estado == "q3"){
                                if(palavra[x] == 'a'){
                                    estado = "conjunto vazio";
                                    vetor[conta] = estado;
                                }
                                else if(palavra[x] == 'b'){
                                    estado = " conjunto vazio";
                                    vetor[conta] = estado;
                                }
                            }
                        }

                    }
                }
            }
            conta++;
            cout << "conta" << conta << endl;
        }


        cout << " vetor " << endl;
        for(int x = 0; x < conta; x++){
            cout << vetor[x] << endl;
        }

        if(pertence == 0){
            cout << endl << " ESTADO RETORNADO: " << estado << endl;
            if (estado == "q3" || estado == "vazio"){
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
                AFN();
                break;
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t FUNÇÃO DE TRANSICAO ESTENDIDA " << endl;
                cout << "---------------------------------------------" << endl;
                cout << " PALAVRA: ";
                cin >> palavra;
                cout << "---------------------------------------------" << endl << endl;
                funcaoTransicaoEstendidaAFN(d,palavra);
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

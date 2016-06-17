#include <iostream>
#include <string>
#include "Fila.cpp"
using namespace std;

class Transicao{
    public:
        

    public:
        Transicao(){
            
        };

        ~Transicao();

        

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

    void funcaoTransicaoEstendida(string palavra){
        Fila *fila = new Fila(); // Criando objeto fila

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
                        fila->enfileirar(fila);
                        //fila->enfileirar(fila/*, "q1"*/);
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


};

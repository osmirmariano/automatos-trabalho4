#include <iostream>
#include <string>
using namespace std;

class AutomatoAfn{
    public:
        string estado[4];
        string armazenaEstado[8];
        string palavra, armazenamento[10];
        int x, flag, k, b, conta;

    public:
        AutomatoAfn(){
            estado[0] = "q0";
            estado[1] = "q1";
            estado[2] = "q2";
            estado[3] = "q3";
            this->palavra = palavra;
            x=0;
            flag=1;
            k=0;
            b=0;
            conta=0;
        };

        ~AutomatoAfn();


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

    string roda(int x, string armazenamento){
        int y=0;
        while(y<x){
            estado[x] = estado[x+1];
            y++;
        }

        while(estado[x] != armazenamento){
            x++;
        }

        return estado[x];
    }

    void guarda(string palavra){
        int tamanho=0;
        tamanho = palavra.length();
        //estado[x] = armazenamento[b];
        //estado[x]
        while(k < tamanho){
            if(estado[x] == "q0"){
                if(palavra[x] == 'a'){
                    while(flag != 2){

                            if(conta > 1){
                                    armazenamento[b] = "q0";
                                    conta++;
                            }

                            if(estado[x] != armazenamento[b]){
                                //armazenamento[b] = "q0";
                                //estado[x] = armazenamento[b];
                                //while(estado[x] != armazenamento[b]){
                                    //x++;
                                //}
                                estado[x] = roda(x, armazenamento[b]);
                                //estado[x] = roda(estado[x], armazenamento[b]);
                                b++;
                            }
                            cout << " 1.1 - {" << estado[x];
                            //guarda(estado[x]);
                            guarda(palavra);
                            //b++;

                            armazenamento[b] = "q1";
                            if(estado[x] != armazenamento[b]){
                                //estado[x] = armazenamento[b];
                                estado[x] = roda(x, armazenamento[b]);

                            }
                            cout << "," << estado[x] << "}" << endl;;
                            //guarda(estado[x]);
                            flag++;
                    }
                    //guarda(estado[x]);
                    guarda(palavra);

                }else{
                    if(palavra[x] == 'b'){
                        armazenamento[b] = "q0";
                        //estado[x] = armazenamento[b];
                        if(estado[x] != armazenamento[b]){
                            //estado[x] = armazenamento[b];
                            estado[x] = roda(x, armazenamento[b]);

                        }
                        cout << " 1.2 - {" << estado[x] << "}" << endl;
                        //guarda(estado[x]);
                        guarda(palavra);
                    }
                }

            }

            if(estado[x] == "q1"){
                if(palavra[x] == 'a'){
                    armazenamento[b] = "q2";
                    //estado[x] = armazenamento[b];
                    if(estado[x] != armazenamento[b]){
                        estado[x] = roda(x, armazenamento[b]);
                    }
                    cout << " 2.1 - {" << estado[x] << "}" << endl;
                }else{
                    if(palavra[x] == 'b'){
                        armazenamento[b] = "q2";
                        if(estado[x] != armazenamento[b]){
                            estado[x] = roda(x, armazenamento[b]);
                        }
                        cout << " 2.2 - {" << estado[x] << "}" << endl;
                    }
                }
            }
            b++;
            x++;
            k++;
        }
    }


    // void funcaoTransicaoAFN(string palavra){
    //     int tamanho = 0, b = 0;
    //     armazenaEstado[0] = "q0";
    //     estado[0] = armazenaEstado[0];
    //     tamanho = palavra.length();

    //     cout << "TAMANHO: " << tamanho << endl;
    //     for(int x = 0; x < tamanho; x++){
    //         //estado[x] = armazenaEstado[b];
    //             if(estado[x] == "q0"){
    //                 if(palavra[x] == 'a'){//Para o caso de A
    //                     armazenaEstado[b] = "q0";
    //                     cout << " 1.1 - " << armazenaEstado[b];
    //                     b++;
    //                     armazenaEstado[b] = "q1";
    //                     //cout << " 1.1 - " << armazenaEstado[b+1] << endl;
    //                     cout << " " << armazenaEstado[b] << endl;
    //                 }
    //                 else{
    //                     if(palavra[x] == 'b'){//Para o caso de B
    //                         armazenaEstado[b] = "q0";
    //                         cout << " 1.2 - " << armazenaEstado[b] << endl;
    //                     }
    //                 }
    //                 b++;
    //             }
    //             else{
    //                 if(estado[x] == "q1"){
    //                     if(palavra[x] == 'a'){//Para o tratamento do A
    //                         armazenaEstado[b] = "q2";
    //                         cout << " 2.1 - " << armazenaEstado[b] << endl;
    //                     }
    //                     else{
    //                         if(palavra[x] == 'b'){//Tratamento do B
    //                             armazenaEstado[b] = "q2";
    //                             cout << " 2.2 - " << armazenaEstado[b] << endl;
    //                         }
    //                     }
    //                     b++;

    //                 }
    //                 else{
    //                     if(estado[x] == "q2"){
    //                         if(palavra[x] == 'a'){//Tratamento do A
    //                             armazenaEstado[b] = "q3";
    //                             cout << " 3.1 - " << armazenaEstado[b] << endl;
    //                         }
    //                         else{
    //                             if(palavra[x] == 'b'){//Tratamento do B
    //                                 armazenaEstado[b] = "q3";
    //                                 cout << " 3.2 - " << armazenaEstado[b] << endl;
    //                             }
    //                         }
    //                         b++;

    //                     }
    //                 }
    //             }
    //         //}
    //     }
    //     //int valor = armazenaEstado[].length();
    //     cout << " CONJUNTO DE ESTADOS: {";
    //     for(int x = 0; x < 3; x++){
    //         cout << " " << armazenaEstado[x];
    //     }
    //     cout << "}" << endl;
    // };


    /*void functionTest(string palavra){
        int tamanho = 0, b = 0, d = 0, c = 0, x = 0;
        armazenaEstado[0] = "q0";
        string armazena[7];
        estado[0] = armazenaEstado[0];
        tamanho = palavra.length();

        //for(int x = 0; x < tamanho; x++){
            if(estado[x] == "q0"){
                if(palavra[x] == 'a'){
                    armazenaEstado[b] = "q0";
                    b++;
                    armazenaEstado[b] = "q1";
                    while(c < 2){
                        x++;
                        if(armazenaEstado[c] == "q0"){

                            if(palavra[x] == 'a'){
                                armazena[d] = "q0";
                                d++;
                                armazena[d] = "q1";
                            }
                            else{
                                if(palavra[x] == 'b')
                                    armazena[d] = "q0";
                            }
                        }
                        c++;
                        if(armazena[c] == "q1"){
                            if(palavra[x] == 'a'){
                                armazena[d+1] = "q2";
                            }
                            else{
                                if(palavra[x] == 'b'){
                                    armazena[d+1] = "q2";
                                }
                            }
                        }
                        cout << " " << armazena[d] << endl;
                    }
                }
            }
        //}


    }*/

};

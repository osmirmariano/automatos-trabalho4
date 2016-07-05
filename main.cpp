#include <iostream>
#include <string>
#include "AutomatoAFN.cpp"
#include "Fila.cpp"

using namespace std;



        int main(){
            int opcao;
            string estado, palavraInformada;
            FILA *fila = NULL;
            
            criaFila(&fila);
            AutomatoAFN *afn =  new AutomatoAFN();

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
                        if(afn->verificaPalavraPertence(palavraInformada) == 0){
                            estado = afn->funcaoTransicaoEstendida(&estado, palavraInformada, fila);
                            if (estado == "q3"){
                                cout << "---------------------------------------------" << endl;
                                cout << " PALAVRA ACEITA PELA O AUTÔMATO!" << endl;
                                cout << " \tESTADOS " << afn->funcaoTransicaoEstendida(estado, palavra) << " É FINAL" << endl;
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
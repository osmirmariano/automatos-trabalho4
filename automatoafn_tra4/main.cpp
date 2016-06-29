#include <iostream>
#include <istream>
#include "AutomatoAfn.cpp"

using namespace std;

int main(){
    int opcao;
    string estado, palavra;

    AutomatoAfn *afn = new AutomatoAfn();

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
                cin >> palavra;
                //afn->funcaoTransicaoAFN(palavra);
                afn->functionTest(palavra);
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
#include <iostream>
#include <istream>
#include "Transicao.cpp"


using namespace std;

int main(){
    int opcao;

    Expressao *exp = new Expressao();
    Usuario *user = new Usuario();

    do{
        cout << endl << "---------------------------------------------" << endl;
        cout << "\t MENU PRINCIPAL" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 2 -- VISUALIZAR AUTÔMATO" << endl;
        cout << " 3 -- FUNCAO DE TRANSICAO ESTENDIDA" << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OPCAO: ";
        cin >> opcao;
        cout << "---------------------------------------------" << endl << endl;

        switch(opcao){
            case 1:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t DEFININDO AUTÔMATO " << endl;
                cout << "---------------------------------------------" << endl;
                user->definindoAutomato();
                
                break;
            case 2:
                cout << endl << "---------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DE AUTÔMATOS" << endl;
                cout << "---------------------------------------------" << endl;
                exp->mostrarAutomato();
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

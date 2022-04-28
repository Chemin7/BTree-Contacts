#include <iostream>
#include <random>
#include <chrono>
#include "btree.h"
#include "contact.h"

using namespace std;

void menu() {
    BTree<Contact>* myTree = new BTree<Contact>();

    int opc,id,opc2;
    Contact contacto;
    string name,address,email;

    ///----------------------------
    uniform_int_distribution<int> distribution(0,5);
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    ///--------------------------

    do {
        system("cls");
        //id = distribution(generator);

        cout<<"1) Insertar Datos \n"
            <<"2) Buscar Nodo \n"
            <<" a) Por ID \n"
            <<" b) Por Nombre\n"
            <<"3) Mostrar Mínimo ID (Nodo)\n"
            <<"4) Mostrar Máximo ID (Nodo)\n"
            <<"5) Mostrar Nodo Antecesor\n"
            <<"6) Mostrar Nodo Sucesor\n"
            <<"7) Editar Nodo (por ID)\n"
            <<"8) Eliminar Nodo(Por ID)\n"
            <<"9) Mostrar Datos en InOrder\n"
            <<"10) Mostrar Datos en PreOrder\n"
            <<"11) Mostrar Datos en PostOrder\n"
             <<"Selecciona una opcion: ";
        cin>>opc;

        switch(opc) {
            case 1:
                cout<<"Ingresa el id del contacto: "<<endl;
                cin>>id;
                contacto.setId(id);
                cout<<"Ingrese el nombre del contacto: "<<endl;
                cin.sync();
                getline(cin,name);
                contacto.setName(name);
                cout<<"Ingresa la direccion del contacto: "<<endl;
                getline(cin,address);
                contacto.setAddress(address);
                cout<<"Ingresa el email del contacto: "<<endl;
                getline(cin,email);
                contacto.setEmail(email);

                myTree->insertData(contacto);

                break;
            case 2:
                cout<<"1) Por Id\n"
                    <<"2) Por Nombre\n"
                    <<"Selecciona una opcion: ";
                cin>>opc2;
                if(opc2 == 1){
                    cout<<"Ingrese el id a buscar: ";
                    cin>>id;
                    myTree->searchById(id);
                }else if(opc2 == 2){
                    cout<<"Ingrese el id a buscar: ";
                   cin.sync();
                    getline(cin,name);
                    myTree->searchByName(name);
                }
                system("pause");

                break;
            case 3:
                cout<<endl;
                cout<<"Elemento menor: "<<myTree->retrieve(myTree->getLowest())<<endl;
                cout<<endl;
                system("pause");
                break;
            case 4:
                cout<<"Elemento mayor: "<<myTree->retrieve(myTree->getHighest())<<endl;
                cout<<endl;
                system("pause");
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                cout<<"Recorrido inOrder: "<<endl;
                myTree->parseInOrder();
                cout<<endl;
                system("pause");
                break;
            case 10:
                cout<<"Recorrido preOrder: "<<endl;
                myTree->parsePreOrder();
                system("pause");
                break;
            case 11:
                cout<<endl;
                cout<<"Recorrido postOrder: "<<endl;
                myTree->parsePostOrder();
                system("pause");
                cout<<endl;
                break;
            }
        }
    while(opc!=12);

    }

int main() {
    menu();
    /*BTree<int> myTree;
    int num;

    uniform_int_distribution<int> distribution(0,75);
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    cout<<"Valores ingresados: "<<endl;
    for(int i=0; i <= 10; i++) {
        num = distribution(generator);
        myTree.insertData(num);
        cout<<num << ", ";



        }
    cout<<endl;
    cout<<endl;

    cout<<endl;
    cout<<"Recorrido preOrder: "<<endl;
    myTree.parsePreOrder();
    cout<<endl;

    cout<<endl;
    cout<<"Recorrido inOrder: "<<endl;
    myTree.parseInOrder();
    cout<<endl;

    cout<<endl;
    cout<<"Recorrido postOrder: "<<endl;
    myTree.parsePostOrder();
    cout<<endl;

    cout<<endl;
    cout<<"Elemento menor: "<<myTree.retrieve(myTree.getLowest())<<endl;
    cout<<endl;


    cout<<"Elemento mayor: "<<myTree.retrieve(myTree.getHighest())<<endl;
    cout<<endl;

    cout<<"Altura sub-arbol izquierdo: "<<myTree.getHeightLeft()<<endl;
    cout<<endl;

    cout<<"Altura sub-arbol derecho: "<<myTree.getHeightRight()<<endl;
    cout<<endl;*/

    return 0;

    }

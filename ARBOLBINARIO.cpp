#include <iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;
struct Nodo{
int dato;
Nodo *der;
Nodo *izq;

};
Nodo *arbol =NULL;
///prototipos
///void funcion de menu
void menu();

Nodo *crearNodo(int);

void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
///Nodo *arbol = NULL;
int main(){

menu();


getch();
return 0;
}
///FUNCION PARA CREAR UN NUEVO NODO
Nodo *crearNodo(int n){

Nodo *nuevo_nodo = new Nodo();

nuevo_nodo->dato = n;
nuevo_nodo->der = NULL;
nuevo_nodo->izq = NULL;
return nuevo_nodo;

}

void insertarNodo(Nodo *&arbol, int n){
if(arbol==NULL){
    ///si el arbol esta vacio crear nuevo nodo
    Nodo *nuevo_nodo =crearNodo(n);
    arbol=nuevo_nodo;
} else{
///si el arbol tiene un nodo o mas
int valorRaiz= arbol->dato;///obtenemos el valor de la raiz
if (n==valorRaiz){
    return;
}
if(n< valorRaiz){///SI EL ELEMTO ES MENOS A LA RAIZ insertar a izq
    insertarNodo(arbol->izq,n);
}
else {
    ///si el elemento es mayor ala raiz inserata a la derecha
insertarNodo(arbol->der,n);
}


}


}
void menu(){
int dato, opcion, contador=0;
do{
    cout<<"\t. MENU: "<<endl;
    cout<<"\n1 insertar\n2 mostrar\n3 salir"<<endl;
    cout<<"opcion";
    cin>>opcion;
    switch(opcion){
    case 1: cout<<"\nDIGITE UN NUMERO: ";
    cin>>dato;
    insertarNodo(arbol,dato); ///insertqar un nuevo nodo
    cout<<"\n";
    system("pause");
    break;
    case 2:
        cout<<"\nMOSTRANDO EL ARBOL COMPLETO\n";
        mostrarArbol(arbol,contador);
        cout<<endl;
        system("pause");
        break;
    }
    system("cls");
} while (opcion !=3);

}

///funcion para mostrar arbol
void mostrarArbol(Nodo *arbol, int cont){
if (arbol==NULL){
    ///si el arbol esta vacio
    return;

}else{
mostrarArbol(arbol->der, cont+1);
for (int i=0; i<cont; i++){

    cout<<"   ";
}
cout<<arbol->dato<<endl;
mostrarArbol(arbol->izq, cont+1);

}


}








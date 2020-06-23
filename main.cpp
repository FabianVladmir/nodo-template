#include <iostream>
#include "nodo.h"
using namespace std;

int main(){
    /*
    linkedList <double> lista;
    for(double i = 1.2; i<10.9; i+=1.2){
      lista.insertar(i);
    }
    lista.print();

    lista.remove(2.4);
    lista.remove(6.0);

    lista.print(); 

    lista.find(7.2);
    lista.find(6.5);
    */
   
    linkedList<int> lista2;

    for (size_t i = 0; i < 20; i++)
    {
        lista2.insertar(i);
    }

    lista2.print();

    for (size_t i = 0; i < 13; i++)
    {
        if (i % 3 == 0)
        {
            lista2.remove(i);
        }
        
    }
    
    lista2.print();

    lista2.find(17);
    lista2.find(12);

    /*
    for (auto iterator = lista2.begin(); iterator != lista2.end(); iterator++)
    {
        cout << *iterator << " ";
    }
    
    cout << endl;
    */

    return 0;
}
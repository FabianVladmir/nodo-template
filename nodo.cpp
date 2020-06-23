#include "nodo.h"

// NODO
template <typename T>
Nodo<T>::Nodo(){
    this->element = 0;
    this->next = nullptr;
}

template <typename T>
Nodo<T>::Nodo(T element_)
{
    this->element = element_;
    this->next = nullptr;
}

template <typename T>
Nodo<T>::Nodo(T p, Nodo *n){
    this->element = p;
    this->next = n;
}

template <typename T>
Nodo<T>::~Nodo()
{
}

// LINKEDLIST
template <typename T>
linkedList<T>::linkedList( ){ 
       
    this->head = nullptr;
}

template <typename T>
void linkedList<T> :: insertar(T valor){   
    
    Nodo <T> * new1;
    Nodo <T> * aux = head;    
    
    new1 = new Nodo<T>(valor);      
    
    if (head == nullptr) // case 1
    {       
        head = new1;
    }   
    else 
    {
      if(head->element > valor){//case 2
        new1->next = head;
        head = new1;
      }else{ // case 3
        while((aux->next != nullptr) && (aux->next->element < valor)){
          aux = aux->next;
        }
        new1->next = aux->next;
        aux->next = new1;
      }
        
    }
}

template <typename T>
void linkedList<T>:: remove(T eliminar){
    if (head == nullptr) // case 1
    {
        return;
    }

    if (head->element == eliminar) // case2
    {
        Nodo<T>* aux = head;
        head = head->next;
        delete aux;
        return;        
    }
    Nodo<T>* aux = head;
    while (aux->next != nullptr && aux->next->element != eliminar) // case3
    
    aux = aux->next;
    
    Nodo<T> *aux2 = aux->next;
    aux->next = aux2->next;
    delete aux2;    
    
}

template <typename T>
void linkedList<T> ::print(){
    for (Nodo<T>* i = head; i != nullptr; i = i->next)
    {
        cout << i->element << " ";
    }
    cout << endl;
}

template <typename T>
void linkedList<T>::find(T valor){
    
    Nodo<T> *aux = head;
    while (aux != nullptr && aux->element != valor)
    {       
        aux = aux->next;
    }
    if(aux != nullptr){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
}

template <typename T>
linkedList<T>::~linkedList()
{
    while (head != nullptr)
    {
        Nodo<T> *p = head; 
        head = head->next;
        cout << "Eliminando: " << p->element << endl;
        delete p;
    }    
}
template <typename T>
Iterator linkedList<T>::begin(){
  return Iterator (head->nex);
}

// ITERATOR
template <typename T>
Iterator<T>::Iterator()
{
    iterator = nullptr;
    //posicion = nullptr;
}

template <typename T>
bool Iterator<T>::hasNext(){
    if (iterator->next == nullptr)
    {
        return false;
    }else
    {
        return true;
    }
}

template <typename T>
int Iterator<T>::operator*(int){
    return iterator->element;
}

template<typename T>
Iterator<T> Iterator<T>::end(){
    while (hasNext())
    {
        iterator = iterator->next;
    }
    return Iterator(iterator);
}

template<typename T>
Iterator<T> &Iterator<T>::operator=( Nodo<T> *p){
    iterator = p;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++(){
    if (iterator != nullptr)
    {
        iterator = iterator->next;
    }
    return *this;
}

template <typename T>
Iterator<T>::~Iterator()
{
}

template <typename T>
class Nodo
{
private:
    T element;
    Nodo<T> *next;
    template<typename U> friend class linkedList;
    template<typename U> friend class iterator;

public:
    Nodo();
    Nodo(T element_);
    Nodo(T p, Nodo* n);    
    ~Nodo();
};


template <typename T>
class linkedList
{
private:       
    Nodo<T>* head;
    template <typename U> friend class Iterator;
    
public:    
    linkedList();
    void insertar(T valor);
    void remove(T eliminar);
    void print();
    void find(T valor);    
    ~linkedList();

    // Iterator
    class Iterator
    {
    private:
        Nodo<T> *iterator;
        template<typename U>friend class linkedList;
        // Nodo<T> *posicion;
        
    public:
        Iterator(){
          iterator = nullptr;
        }
        
        bool hasNext(){
          if(iterator->next != nullptr){
            return true;
          }else{
            return false;
          }
        }

        bool operator!=(Iterator &inn) const{
          return iterator != inn.iterator;
        }

        Iterator& operator++(){
          if(iterator != nullptr){
            iterator = iterator->next;
          }
          return iterator;
        }

        Iterator& operator++(int){
          Iterator aux = *this;
          iterator = iterator->next;
          return aux;
        }

        T& operator*(){
          return iterator->element;
        }
        Iterator& operator=(Nodo<T> *p){
          iterator = p;
          return *this;
        } 
        ~Iterator();       
    }; // fin clase iterator

    Iterator begin(){
      return Iterator(head);
    }

    Iterator end(){
      Nodo<T>* aux = head;
      while(aux != nullptr){
        aux = aux->next;        
      }
      return Iterator(aux);
    }
};

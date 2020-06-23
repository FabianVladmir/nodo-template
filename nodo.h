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
    Nodo<T>* getHead();
    ~linkedList();
};


template <typename T>
class Iterator
{
private:
    Nodo<T> *iterator;
    // Nodo<T> *posicion;
    
public:
    Iterator();
    ~Iterator();
    bool hasNext();
    Iterator begin();
    Iterator end();
    Iterator& operator++();
    int operator*(int);
    Iterator& operator=(Nodo<T> *p);
};

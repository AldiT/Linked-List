

#ifndef Linked_list_hpp
#define Linked_list_hpp

#include <stdio.h>

#include <iostream>

using namespace std;

template< class T >
struct List_node{
    T _value;
    List_node<T> * _pPrev;
    List_node<T> * _pNext;
};

template<class T>
class Linked_list{
public:
    typedef T value_type;
    typedef List_node<T>* position;
    
    
    Linked_list();
    Linked_list(int);
    
    
    Linked_list(const Linked_list<T>& );
    
    
    ~Linked_list();
    
    // operators
    void create();
    bool empty() const;
    value_type read(position) const;
    void write(const value_type &, position);
    position begin() const;
    position last() const;
    bool end(position) const;
    position next(position) const;
    position previous(position) const;
    void insert(const value_type &, position);
    void erase(position);
    int size() const {
        return _length;
    };
    
    Linked_list<T>& operator=(const Linked_list<T>&);
    bool operator==(const Linked_list<T> &) const;
    
    friend std::ostream& operator<<(ostream& os, const Linked_list<T> &l){
        position p;
        p = l.begin();
        os << "[";
        while (!l.end(p)){
            if (p != l.begin())
                os << ", " << l.read(p);
            else
                os << l.read(p);
            p = l.next(p);
        }
        os << "]" << endl;
        return os;
    }
    
    void min_max_change();
    
    bool eshtPoliandrome();
    
private:
    List_node<T> * _pHead;
    int _length; 
};



#endif /* Linked_list_hpp */

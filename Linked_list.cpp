
#include "Linked_list.hpp"

using namespace std;

template< class T >
Linked_list< T >::Linked_list() {
    _pHead = new List_node<T>;
    _pHead->_pNext = _pHead;
    _pHead->_pPrev = _pHead;
    _length = 0;
}
template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L) {
    _length = 0;
    _pHead = new List_node<T>;
    _pHead->_pNext = _pHead;
    _pHead->_pPrev = _pHead;
    if (!L.empty()){
        position p = L.last();
        for (int i=0; i <= L._length; i++){
            insert(L.read(p), begin());
            p = L.previous(p);
        }
    }
}

template< class T >
Linked_list< T >::~Linked_list(){
    while(!empty())
        erase(begin());
    delete _pHead;
}
template< class T >
void Linked_list< T >::create(){
    if (empty())
        _length = 0;
}
template< class T >
bool Linked_list< T >::empty() const {
    return(_pHead == _pHead->_pNext);
}
template< class T >
typename Linked_list< T >::position Linked_list< T >::begin() const {
    return (_pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::last() const {
    return (_pHead->_pPrev);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::next(position p) const {
    return(p->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::previous(position p) const {
    if (p != _pHead)
        return(p->_pPrev);
    return p;
}

template< class T >
bool Linked_list< T >::end(position p) const {
    return(p == _pHead);
}

template< class T >
typename Linked_list< T >::value_type Linked_list< T >::read(position p) const {
    if (!end(p))
        return(p->_value);
    return 0;
}

template< class T >
void Linked_list< T >::write(const value_type &a, position p) {
    if (!end(p))
        p->_value = a;
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p){
    position t = new List_node<T>;
    t->_value = a;
    t->_pNext = p;
    t->_pPrev = p->_pPrev;
    p->_pPrev->_pNext = t;
    p->_pPrev = t;
    _length++;
}

template< class T >
void Linked_list< T >::erase(position p){
    if (!empty() && !end(p)){
        p->_pPrev->_pNext = p->_pNext;
        p->_pNext->_pPrev = p->_pPrev;
        delete p;
    }
}

template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
    if (this != &L){
        _length = 0;
        _pHead = new List_node<T>;
        _pHead->_pNext = _pHead;
        _pHead->_pPrev = _pHead;
        //cout << L.empty();
        //cout << L.size();
        if (!L.empty()){
            position p = L.last();
            for (int i=0; i < L.size(); i++){ //cout << i, L.read(p);
                insert(L.read(p), begin());
                p = L.previous(p);
            }
            return *this;
        }
    }
    return *this;
}

template <class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
    if (L.size() != _length)
        return false;
    
        position p, pL;
        p = begin();
        pL = L.begin();
        while (!end(p)){
            if (p->_value != pL->_value)
                return false;
            p = p->_pNext;
            pL = pL->_pNext;
        }
        return true;
}



template <class T>
void Linked_list<T>::min_max_change(){
    if(_length == 0){
        std::cout << "Lista esht boshe";
        return;
    }
    
    position min = _pHead->_pNext, max = _pHead->_pNext;
    position itr = _pHead->_pNext;
    
    for(int i = 0; i < size(); i++){
        if(itr->_value < min->_value){
            min = itr;
        }
        if(itr->_value > max->_value){
            max = itr;
        }
        itr = itr->_pNext;
    }
    
    if(min == max)
        return;
    
    min->_pPrev->_pNext = max;
    max->_pPrev->_pNext = min;
    itr = min->_pPrev;
    min->_pPrev = max->_pPrev;
    max->_pPrev = itr;
    min->_pNext->_pPrev = max;
    max->_pNext->_pPrev = min;
    itr = min->_pNext;
    min->_pNext = max->_pNext;
    max->_pNext = itr;
}

template <typename T>
bool Linked_list<T>::eshtPoliandrome(){
    if(_pHead == _pHead->_pNext)//lista eshte bosh
        return false;
    
    position itr1 = begin();
    position itr2 = last();
    
    while(itr1 != itr2 && itr1->_pNext != itr2){
        
        if(itr1->_value != itr2->_value)
            return false;
        
        
        itr1 = next(itr1);
        itr2 = previous(itr2);
    }
    
    return true;
    
}



template class Linked_list<int>;
template class Linked_list<float>;






































//
// Created by Alberto Dugo on 02/04/23.
//

#include <iostream>
#include <sstream>
#include "ArrayList.h"
#include "../Model/hierarchy/SpedizionePremium.h"
#include "../Model/SupportClasses/Assicurazione.h"

template<class T>
ArrayList<T>::ArrayList() {
    _dimensione = 0;
    _capacita = 1;
    _head = new T[_capacita];
}

template<class T>
ArrayList<T>::ArrayList(int _capacity) {
    _dimensione = 0;
    _capacita = _capacity;
    _head = new T[_dimensione];
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList &_al) {
    _head = new T[_al._capacita];
    this->_capacita = _al._capacita;
    this->_dimensione = _al._dimensione;
    for (int i = 0; i < _dimensione; ++i) {
        _head[i] = *(_al._head+i);
    }

}

template<class T>
ArrayList<T>::~ArrayList() {
    //delete [] _head;
}

template<class T>
T *ArrayList<T>::get(int _index) const {
    return _head+_index;
}

template<class T>
int ArrayList<T>::getDim() const {
    return _dimensione;
}

template<class T>
int ArrayList<T>::getCapacity() const {
    return _capacita;
}
/*
 * se non mette la dimensione la capacità raddoppia, se la mette usa quella dimensione come capacità
 * */
template<class T>
void ArrayList<T>::realloc(int dim) {
    _capacita = dim;
    T *t = new T[_capacita];
    for (int i = 0; i < _dimensione; i++){
        t[i] = _head[i];
    }
    //delete[] _head;
    _head = t;
}
template<class T>
void ArrayList<T>::add(const T &_obj) {
    if((_dimensione - 1) == _capacita && _dimensione != 0) realloc(_capacita*2);
    _head[_dimensione] = _obj;
    _dimensione++;
}

template<class T>
void ArrayList<T>::add(const T &_obj, int _index) {
    if (_index >= 0 && _index <= _dimensione)
    {
        if (_index >= _capacita || _dimensione == _capacita)
        {
            int dim = (_index >= _capacita) ? _index : _dimensione;
            realloc(dim * 2);
        }
        for (int i = _dimensione; i > _index; i--)
        {
            _head[i] = _head[i - 1];
        }
        _head[_index] = _obj;
        _dimensione++;
    }
}

template<class T>
const T *ArrayList<T>::remove(int _index) {
    T *_removed = nullptr;
    if (_index < _dimensione && _index >= 0){
        for (int i = _index; i < _dimensione; i++)
        {
            _head[i] = _head[i + 1];
        }
        _removed = _head + _index;
        _dimensione--;
    }
    return _removed;
}

template<class T>
void ArrayList<T>::removeAll() {
    delete [] _head;
    _head = new T[_capacita];
    _dimensione = 0;
}

template<class T>
bool ArrayList<T>::exchange(int _index1, int _index2) {
    if (_index1 >= 0 && _index2 >= 0 && _index1 < _dimensione && _index2 < _dimensione){
        T temp = _head[_index1];
        _head[_index1] = _head[_index2];
        _head[_index2] = temp;
        return true;
    }
    return false;
}

template<class T>
std::string ArrayList<T>::toString() const {
    std::ostringstream streamOut;
    streamOut << "(";
    for (int i = 0; i < _dimensione; i++){
        streamOut << _head[i];
        if (i != (_dimensione - 1)){
            streamOut << ", \n ";
        }
    }
    streamOut << ")\n";
    std::string returnString = streamOut.str();
    return returnString;
}

template<class T>
ArrayList<T>::Iterator::Iterator(T* ptr) : objPtr(ptr) {}

template<class T>
ArrayList<T>::Iterator ArrayList<T>::Iterator::operator++() {
    objPtr++;
    return objPtr;
}
template<class T>
ArrayList<T>::Iterator ArrayList<T>::Iterator::operator++(int i) {
    ArrayList<T>::Iterator temp = *this;
    objPtr++;
    return temp;
}

template<class T>
ArrayList<T>::Iterator  ArrayList<T>::Iterator::operator--() {
    objPtr--;
    return objPtr;
}
template<class T>
ArrayList<T>::Iterator  ArrayList<T>::Iterator::operator--(int) {
    ArrayList<T>::Iterator temp = *this;
    objPtr--;
    return temp;
}
template<class T>
T& ArrayList<T>::Iterator::operator*() {
    return *objPtr;
}
template<class T>
T* ArrayList<T>::Iterator::operator->() {
    return objPtr;
}
template<class T>
bool ArrayList<T>::Iterator::operator==(const ArrayList<T>::Iterator& other) {
    return objPtr == other.objPtr;
}
template<class T>
bool ArrayList<T>::Iterator::operator!=(const ArrayList<T>::Iterator& other) {
    return objPtr != other.objPtr;
}

template<class T>
ArrayList<T>::Iterator ArrayList<T>::begin() {
    return Iterator(_head);
}
template<class T>
ArrayList<T>::Iterator ArrayList<T>::end() {
    return Iterator(_head+_dimensione);
}


template class ArrayList<Spedizione*>;
template class ArrayList<Filiale*>;
template class ArrayList<Assicurazione*>;
template class ArrayList<int>;


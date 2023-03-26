//
// Created by Alberto Dugo on 26/03/23.
//

#include "ArrayList.h"

template<class T>
ArrayList<T>::ArrayList() {
    _dimensione = 0;
    _capacita = 1;
    _head = new T[1];
}

template<class T>
ArrayList<T>::ArrayList(int _capacity) {
    _dimensione = 0;
    _capacita = _dimensione;
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
    delete [] _head;
}

template<class T>
T *ArrayList<T>::get(int _index) const {
    return nullptr;
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
    _capacita = (dim != 0) ? dim : _capacita * 2;
    T * t = new T[_capacita];
    for (int i = 0; i < _dimensione; i++){
        t[i] = _head[i];
    }
    delete [] _head;
    _head = t;
}
template<class T>
void ArrayList<T>::add(const T &_obj) {
    if((_dimensione - 1) == _capacita) realloc();
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
            realloc((dim * 2);
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
    return nullptr;
}

template<class T>
bool ArrayList<T>::removeAll() {
    return false;
}

template<class T>
bool ArrayList<T>::exchange(int _index1, int _index2) {
    return false;
}

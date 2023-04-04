//
// Created by Alberto Dugo on 02/04/23.
//

#ifndef PROJECT_ARRAYLIST_H
#define PROJECT_ARRAYLIST_H
#include "string"
template <class T> class ArrayList {
private:
    int _dimensione;
    int _capacita;
    T *_head;
    void realloc(int dim = 0);
public:
    ArrayList();
    explicit ArrayList(int _capacity);
    ArrayList(const ArrayList& _al);
    ~ArrayList();

    T * get(int _index) const; //restituisce elemento a indice = _index
    int getDim() const;
    int getCapacity() const;
    void add(const T &_obj);
    void add(const T &_obj, int _index);
    const T* remove(int _index);
    void removeAll();
    bool exchange(int _index1, int _index2);
    std::string toString() const;
};


#endif //PROJECT_ARRAYLIST_H

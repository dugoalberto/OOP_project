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
    ArrayList(int _capacity);
    ArrayList(const ArrayList& _al);
    ~ArrayList();

    T * get(int _index) const; //restituisce elemento a indice = _index
    int getDim() const;
    int getCapacity() const;
    void add(const T &_obj);
    void add(const T &_obj, int _index);
    int search(int id) const;
    const T* remove(int _index);
    void removeAll();
    bool exchange(int _index1, int _index2);
    std::string toString() const;
    T& operator[](int _index) const;
    ArrayList<T>& operator=(ArrayList<T>);

    class Iterator {
    private:
        T* objPtr;
    public:
        Iterator operator++();
        Iterator operator++(int);
        Iterator operator--();
        Iterator operator--(int);
        T& operator*();
        T* operator->();
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);

        Iterator(T* ptr = nullptr);
    };

    Iterator begin();
    Iterator end();
};


#endif //PROJECT_ARRAYLIST_H

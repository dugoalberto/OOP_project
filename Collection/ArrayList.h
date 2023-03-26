//
// Created by Alberto Dugo on 26/03/23.
//

#ifndef PROJECT_ARRAYLIST_H
#define PROJECT_ARRAYLIST_H

template <class T>
class ArrayList {
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

    T * get(int _index) const;
    int getDim() const;
    int getCapacity() const;
    void add(const T &_obj);
    void add(const T &_obj, int _index);
    const T* remove(int _index);
    bool removeAll(); //restituisce true o false se è stato effettuata l'operazione
    bool exchange(int _index1, int _index2);

};



#endif //PROJECT_ARRAYLIST_H

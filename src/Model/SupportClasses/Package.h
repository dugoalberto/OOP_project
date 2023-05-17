//
// Created by Alberto Dugo on 10/03/23.
//

#ifndef PROJECT_PACKAGE_H
#define PROJECT_PACKAGE_H

#include <string>
#include <ostream>

using namespace std;

class Package {

private:
    string contenuto; //contenuto del pacco
    float valore; //valore del conenuto del pacco
    float volume;
    float peso;

public:
    Package() = default;
    Package(const string &contenuto, float valore, float vol, float peso);
    virtual ~Package();

    //getter
    const string &getContenuto() const;

    float getValore() const;

    float getVolume() const;


    float getPeso() const;

    //setter
    void setContenuto(const string &contenuto);

    void setValore(float valore);

    void setPeso(float peso);

    void setVolume(float volume);

    friend ostream &operator<<(ostream &os, const Package &aPackage);
};


#endif //PROJECT_PACKAGE_H

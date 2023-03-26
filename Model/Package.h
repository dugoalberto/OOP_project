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
    double valore; //valore del conenuto del pacco

public:
    Package(const string &contenuto, double valore);
    virtual ~Package();

    //getter
    const string &getContenuto() const;

    double getValore() const;

    //setter
    void setContenuto(const string &contenuto);

    void setValore(double valore);

    friend ostream &operator<<(ostream &os, const Package &aPackage);
};


#endif //PROJECT_PACKAGE_H

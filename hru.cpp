#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class HRUModel {
private:
    map<string, map<string, vector<string>>> accessMatrix;

public:
    // Crear un nuevo sujeto
    void createSubject(const string& subject) {
        if (accessMatrix.find(subject) == accessMatrix.end()) {
            accessMatrix[subject] = map<string, vector<string>>();
            cout << "Sujeto " << subject << " creado." << endl;
        } else {
            cout << "El sujeto " << subject << " ya existe." << endl;
        }
    }

    // Crear un nuevo objeto bajo un sujeto
    void createObject(const string& subject, const string& object) {
        if (accessMatrix.find(subject) != accessMatrix.end()) {
            if (accessMatrix[subject].find(object) == accessMatrix[subject].end()) {
                accessMatrix[subject][object] = vector<string>();
                cout << "Objeto " << object << " creado para el sujeto " << subject << "." << endl;
            } else {
                cout << "El objeto " << object << " ya existe para el sujeto " << subject << "." << endl;
            }
        } else {
            cout << "El sujeto " << subject << " no existe." << endl;
        }
    }

    // Agregar un permiso a un sujeto sobre un objeto
    void addPermission(const string& subject, const string& object, const string& permission) {
        if (accessMatrix.find(subject) != accessMatrix.end()) {
            if (accessMatrix[subject].find(object) != accessMatrix[subject].end()) {
                vector<string>& permissions = accessMatrix[subject][object];
                if (find(permissions.begin(), permissions.end(), permission) == permissions.end()) {
                    permissions.push_back(permission);
                    cout << "Permiso " << permission << " agregado a " << subject << " sobre " << object << "." << endl;
                } else {
                    cout << "El permiso " << permission << " ya existe para " << subject << " en " << object << "." << endl;
                }
            } else {
                cout << "El objeto " << object << " no existe para el sujeto " << subject << "." << endl;
            }
        } else {
            cout << "El sujeto " << subject << " no existe." << endl;
        }
    }

    // Eliminar un permiso para un sujeto sobre un objeto
    void removePermission(const string& subject, const string& object, const string& permission) {
        if (accessMatrix.find(subject) != accessMatrix.end()) {
            if (accessMatrix[subject].find(object) != accessMatrix[subject].end()) {
                vector<string>& permissions = accessMatrix[subject][object];
                auto it = find(permissions.begin(), permissions.end(), permission);
                if (it != permissions.end()) {
                    permissions.erase(it);
                    cout << "Permiso " << permission << " eliminado de " << subject << " sobre " << object << "." << endl;
                } else {
                    cout << "El permiso " << permission << " no existe." << endl;
                }
            } else {
                cout << "El objeto " << object << " no existe para el sujeto " << subject << "." << endl;
            }
        } else {
            cout << "El sujeto " << subject << " no existe." << endl;
        }
    }

    // Eliminar un sujeto de la matriz de acceso
    void deleteSubject(const string& subject) {
        if (accessMatrix.find(subject) != accessMatrix.end()) {
            accessMatrix.erase(subject);
            cout << "Sujeto " << subject << " eliminado." << endl;
        } else {
            cout << "El sujeto " << subject << " no existe." << endl;
        }
    }

    // Eliminar un objeto bajo un sujeto
    void deleteObject(const string& subject, const string& object) {
        if (accessMatrix.find(subject) != accessMatrix.end()) {
            if (accessMatrix[subject].find(object) != accessMatrix[subject].end()) {
                accessMatrix[subject].erase(object);
                cout << "Objeto " << object << " eliminado de " << subject << "." << endl;
            } else {
                cout << "El objeto " << object << " no existe para el sujeto " << subject << "." << endl;
            }
        } else {
            cout << "El sujeto " << subject << " no existe." << endl;
        }
    }

    // Mostrar la matriz de acceso completa
    void displayMatrix() const {
        for (const auto& subjectPair : accessMatrix) {
            cout << "Sujeto: " << subjectPair.first << endl;
            for (const auto& objectPair : subjectPair.second) {
                cout << "  Objeto: " << objectPair.first << " - Permisos: ";
                for (const string& perm : objectPair.second) {
                    cout << perm << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HRUModel hru;

    hru.createSubject("Usuario1");
    hru.createObject("Usuario1", "Archivo1");
    hru.addPermission("Usuario1", "Archivo1", "leer");
    hru.addPermission("Usuario1", "Archivo1", "escribir");

    cout<<"Mostrando Matriz"<<endl;
    hru.displayMatrix();

    hru.removePermission("Usuario1", "Archivo1", "escribir");
    cout<<"Mostrando Matriz"<<endl;
    hru.displayMatrix();

    hru.deleteObject("Usuario1", "Archivo1");
    cout<<"Mostrando Matriz"<<endl;
    hru.displayMatrix();

    hru.deleteSubject("Usuario1");
    cout<<"Mostrando Matriz"<<endl;
    hru.displayMatrix();

    return 0;
}

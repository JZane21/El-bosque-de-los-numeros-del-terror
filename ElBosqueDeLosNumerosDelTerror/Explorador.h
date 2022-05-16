#ifndef EXPLORADOR_H
#define EXPLORADOR_H
#include <bits/stdc++.h>    
using namespace std;
class Explorador{
    private:
        int vida;
        string nombre;
    public:
        void presentarse();
        void ouch(int valor);
        Explorador(string _nombre);
        int vidaActual();
};
Explorador::Explorador(string _nombre){
    vida=100;
    nombre=_nombre;
};
void Explorador :: presentarse(){
   cout<<"Me llamo "<<nombre<<" y tengo "<<vida<<" anios de vida."; 
};
void Explorador:: ouch (int valor){
    vida=vida-valor;
};
int Explorador::vidaActual(){
    return vida;
};
#endif
/*int main(){
    int vida;
    string nombre;
    cin>>nombre>>vida;
    Explorador e1=Explorador(vida,nombre);
    e1.presentarse();
    return 0;
}*/

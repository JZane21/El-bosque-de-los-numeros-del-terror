#ifndef MONSTRUO_H
#define MONSTRUO_H
#include<bits/stdc++.h>
#include "Explorador.h"
using namespace std;
class Monstruo {
    private:
        int valor;
        bool vivo;
    public:
        Monstruo(int _valor);
        int valorActual();
        void ouch(int divider);
        void hurtIt(Explorador* expl){
            expl->ouch(valor);
        };
        bool pista();
};
Monstruo::Monstruo (int valor){
    this->valor=valor;
    if(valor==0){
        vivo=true;
    }else{
        vivo=false;
    }
};
void Monstruo::ouch(int divider){
    if(valor % divider==0){
        valor=valor/divider;
    }
};
int Monstruo::valorActual(){
    return valor;
};
bool Monstruo::pista(){
    if(valor==1){
        valor=0;
        return true;
    }else{
        return false;
    }
}
#endif
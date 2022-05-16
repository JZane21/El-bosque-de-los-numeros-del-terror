#ifndef NARRADOR_H
#define NARRADOR_H
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
class Narrador{
    public:
        void presentation();
        void starting();
        void levels();
        void goodEnding();
        void badEnding();
        void invalid();
};
void Narrador:: presentation(){
    cout<<"\033[1m~~~~~~~~|||Bienvenido al bosque de Fermat|||~~~~~~~~\033[33m\n"<<endl;
    cout<<"\033[1mCae la noche... Y te encuentras atrapado en un bosque oscuro\033[33m\n";
    cout<<"\033[1mcon muchos monstruos en forma numerica, los cuales\033[33m\n";
    cout<<"\033[1mlo atacaran en cuanto tengan la oportunidad.\033[33m\n";
    getch();
    cout<<endl;
    cout<<"\033[1mDebes salir de este paraje cuanto antes... Tu\033[33m\n";
    cout<<"\033[1mvida sera consumida por la maldicion de los caminos\033[33m\n";
    cout<<"\033[1my el ataque de los monstruos.\033[33m\n";
    getch();
    cout<<endl;
};

void Narrador::starting(){
    cout<<"\033[1mRecuerda... Lo siguiente:\033[36m\n";
    cout<<endl;
    cout<<"\033[1mPara saber que elementos puedes usar para disparar\033[36m\n";
    cout<<"\033[1mse te proporcionara una lista de los mismos. Pero\033[36m\n";
    cout<<"\033[1mcuidado! cuando dispares un elemento, este desaparecera\033[36m\n";
    cout<<"\033[1mde tu inventario.\033[36m\n";
    cout<<"\033[1mTypea - > D #Elemento\033[36m\n";
    cout<<"\033[1mPodras obtener pistas sobre el\033[36m\n";
    cout<<"\033[1mcamino que debes seguir para escapar.\033[36m\n";
    cout<<"\033[1mCada vez que acabes con un mounstro \033[36m\n";
    cout<<endl;
    getch();
    cout<<"\033[1mPara moverte debes de hacer lo siguiente:\033[36m\n";
    cout<<"\033[1mTypea - > A #Vertice\033[36m\n";
    cout<<"\033[1mSelecciona uno de los caminos disponibles\033[36m\n";
    cout<<"\033[1mpor los cuales podras moverte.\033[36m\n";
    cout<<"\033[1mPero cuidado! Moverse de una posicion a otra\033[36m\n";
    cout<<"\033[1mconsumira tu salud.\033[36m\n";
    cout<<"\033[1mPara escapar deberas encontrar la posicion de\033[36m\n";
    cout<<"\033[1mescape que se encuentra en el mapa.\033[31m\n";
    cout<<endl;
    cout<<"\033[1mPuedes comenzar...\033[31m\n";
    cout<<endl;
};

void Narrador:: badEnding(){
    cout<<endl;
    cout<<"\033[1mLa maldicion del bosque te consumio... GAME OVER...\033[33m"<<endl;
    cout<<endl;
};

void Narrador:: goodEnding(){
    cout<<"\033[1m\033[33m"<<endl;
    cout<<"\033[1mEscapaste de la maldicion del bosque y los numeros del terror\033[33m"<<endl;
    cout<<endl;
};
void Narrador :: invalid(){
    cout<<"Entrada invalida... Intentalo OTRA VEZ!"<<endl;
};
void Narrador::levels(){
    cout<<"\n\033[1;32mSelecciona el mapa que utilizaras para escapar\033[33m\n";
    cout<<endl;
    cout<<"\033[1;32mMapa 1 --------------> 1\033[0m"<<endl;
    cout<<"\033[1;32mMapa 2 --------------> 2\033[0m"<<endl;
    cout<<"\033[1;32mMapa 3 --------------> 3\033[0m"<<endl;
    cout<<"\033[1;32mMapa 4 --------------> 4\033[0m"<<endl;
    cout<<"\033[1;32mMapa 5 --------------> 5\033[0m"<<endl;
    cout<<"\033[1;32mMapa 6 --------------> 6\033[0m"<<endl;
    cout<<"\033[1;32mSalir del Juego -----> 0\033[0m"<<endl;
    cout << "\033[1;32mBuena Suerte\033[0m\n"<<endl;
}
#endif
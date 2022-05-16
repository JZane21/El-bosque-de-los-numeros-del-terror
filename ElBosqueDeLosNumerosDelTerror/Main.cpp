#include<bits/stdc++.h>
#include "Narrador.h"
#include "Explorador.h"
#include "Monstruo.h"
#define INF 1000010
using namespace std;
//-------------------------------------------------PARA EL DIJKSTRA---------------------------------------------------------------
vector<pair<int, int> > grafo[26];
char nodosA[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
bool playing=false;
int visitados[100000]; 
int distancia[100000];
int previousN[26];
stack <int> pista;
vector<int> pistasVisibles;
char salida; //También para la etapa del juego
//------------------------MAPAS-------------------------------
// Mapa1
char vis1[]={'A','A','B','B','C','C'};
char vfs1[]={'B','C','D','E','F','G'};
int pesos1[]={3 , 3 , 4 , 2 , 3 , 1};
// Mapa2
char vis2[]={'A','A','B','C'};
char vfs2[]={'B','C','C','D'};
int pesos2[]={4 , 6 , 1 , 2 };
//Mapa3
char vis3[]={'A','A','B','C','D','E','F','G','G','I'};
char vfs3[]={'B','C','D','E','F','G','H','I','J','H'};
int pesos3[]={5 , 2 , 3 , 1 , 1 , 4 , 5 , 1 , 3 , 1 };
//Mapa4
char vis4[]={'A','B','C','D','E','E','F','G','J','L'};
char vfs4[]={'B','C','D','E','F','G','G','J','M','M'};
int pesos4[]={3 , 2 , 1 , 2 , 3 , 4 , 2 , 5 , 1 , 6 };
int nuevo(){
    return (int)(rand()%10);
}
// Mapa 5
char vis5[]={'H','B','B','B','I','A','A','V','F','M','M','R'};
char vfs5[]={'Z','T','A','I','K','V','F','F','N','N','R','P'};
int pesos5[]={nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo()};
// Mapa 6
char vis6[]={'Y','Y','M','X','X','G','J','J','I','P','A'};
char vfs6[]={'X','Z','Z','N','G','H','H','I','K','K','M'};
int pesos6[]={nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo(),nuevo()};
//-----------------------------------------------------------

void dijkstra(int verticeInicial){
    for(int i = 0; i < 100000; i++){
        distancia[i] = INF;
    }
    memset(visitados, 0, sizeof(visitados));
    multiset<pair<int, int> > colaPrioridad; // log(n)sk
    distancia[verticeInicial] = 0;
    colaPrioridad.insert(make_pair(0, verticeInicial));
    while (!colaPrioridad.empty()){
        pair<int, int> verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin()); // pop()
        int vertice = verticeActual.second; // el nodo de donde se esta viniendo
        int peso = verticeActual.first; // distancia 
        if (!visitados[vertice]){
            visitados[vertice] = true;
            for (int i = 0; i < grafo[vertice].size(); i++){
                int verticeVecino = grafo[vertice][i].second;
                int pesoVecino = grafo[vertice][i].first;
                //    inf  >                    0 + 60
                // Relajacion 
                if (distancia[verticeVecino]> distancia[vertice] + pesoVecino ){
                    distancia[verticeVecino] = distancia[vertice] + pesoVecino; 
                    previousN[verticeVecino]=vertice;
                    colaPrioridad.insert(make_pair(distancia[verticeVecino], verticeVecino));
                }
            }
        }
    }
}

// OBTENCIÓN DE PISTAS PARA EL CAMINO MÁS RÁPIDO "Algoritmo Obtención de Pistas"
void pistas(){     // numeroDeLetra 0 0 1 2
    int puntero=salida-'A';//previousN 0 1 2 3 ... 26
    while(puntero!=0){  //Analisis  A B C D
        pista.push(puntero);
        puntero=previousN[puntero];
    }
}
//-------------------------------------------------------------------------------

void mainDijkstra(int naristas, char vis[], char vfs[], int pesos[] ){
    int m;
    m=naristas;
    char verticeInicial,verticeFinal;int peso;
    //Se guarda todo el grafo
    for(int i=0;i<m;i++){
        verticeInicial=vis[i];
        verticeFinal=vfs[i];
        peso=pesos[i];
        grafo[verticeInicial-'A'].push_back(make_pair(peso,verticeFinal-'A'));
        grafo[verticeFinal-'A'].push_back(make_pair(peso,verticeInicial-'A'));
    }
    //Los caminos mas cortos desde A
    dijkstra(0);
    //El camino más corto del puntoInicial al puntoFinal
    pistas();
}
// Selección del mapa
void mapa1(){
    int nvertices=6;
    int naristas=sizeof(vis1)/sizeof(vis1[0]);
    salida='D';
    mainDijkstra(naristas,vis1,vfs1,pesos1);
}

void mapa2(){
    int nvertices=4;
    int naristas=sizeof(vis2)/sizeof(vis2[0]);
    salida='D';
    mainDijkstra(naristas,vis2,vfs2,pesos2);
}

void mapa3(){
    int nvertices=4;
    int naristas=sizeof(vis3)/sizeof(vis3[0]);
    salida='H';
    mainDijkstra(naristas,vis3,vfs3,pesos3);
}

void mapa4(){
    int nvertices=4;
    int naristas=sizeof(vis4)/sizeof(vis4[0]);
    salida='L';
    mainDijkstra(naristas,vis4,vfs4,pesos4);
}

void mapa5(){
    int nvertices=12;
    int naristas=sizeof(vis5)/sizeof(vis5[0]);
    salida='P';
    mainDijkstra(naristas,vis5,vfs5,pesos5);
    
}

void mapa6(){
    int nvertices=12;
    int naristas=sizeof(vis6)/sizeof(vis6[0]);
    salida='P';
    mainDijkstra(naristas,vis6,vfs6,pesos6);
    
}
//PARA LOS NUMEROS PRIMOS
vector<int> primos;
int municiones[10];
void sieve(int n){
    int cantidad = n+1;                      
    bool bs[cantidad];
    memset(bs,true,sizeof(bs));
    bs[0]=false;
    bs[1]=false;                            
    for (int i = 2;i < cantidad; ++i) if (bs[i]) {
        for (int j = i*i;j < cantidad; j += i){
            bs[j] = false;
        } 
        primos.push_back(i);
    }
}

void municion(){
    for(int i=0; i<10; i++){
        municiones[i]=primos[rand()%primos.size()];
    }
}


//------------------------------------PARA INICIAR EL JUEGO------------------------------------

void game(){
    while (playing){
        for(int i=0;i<26;i++){
            grafo[i].clear();
        }
    memset(visitados,false,sizeof(visitados));
    memset(distancia,0,sizeof(distancia));
    memset(previousN,0,sizeof(previousN));
    while(!pista.empty()){
           pista.pop(); 
    }
    pistasVisibles.clear();
    playing=false;
    Explorador expl= Explorador("Ander");
    Narrador narrador= Narrador();
    narrador.presentation();
    while(!playing){
        narrador.levels();
        int nmapa;
        cin>>nmapa;
            if(nmapa == 0){
                break;
            }else if(nmapa==1){
                mapa1();
                playing=true;
            }else if(nmapa==2){
                mapa2();
                playing=true;
            }else if(nmapa==3){
                mapa3();
                playing=true;
            }else if(nmapa==4){
                mapa4();
                playing=true;
            }else if(nmapa==5){
                mapa5();
                playing=true;
            }else if(nmapa==6){
                mapa6();
                playing=true;
            }else{
                cout<<"Tal nivel no existe!"<<endl;
            }
        }

        //PARA COMENZAR A JUGAR
    if(playing){
        vector <Monstruo> monstruos;
        for(int i=0;i<26;i++){
            if( (rand() % (2)) == 0){
                monstruos.push_back(Monstruo(rand()% 30));
            }else{
                monstruos.push_back(Monstruo(0));
            }
        }
        narrador.starting();
        char action;
        int vE,vM;
        char verticeActual='A';
        vE=expl.vidaActual();
        vM=monstruos[verticeActual-'A'].valorActual();
        cout<<"Nodo Actual: "<<nodosA[0]<<endl;
        cout<<"Nodos Vecinos: ";
        for(int i=0;i<grafo[verticeActual-'A'].size();i++){
            int vecino=grafo[verticeActual-'A'][i].second;
            cout<<1+i<<".->"<<nodosA[vecino]<<" ";
        }
        cout<<endl;
        cout<<"Nodo Salida: "<<salida<<endl;        
        cout<<"Pistas: "<<endl;
        sieve(20);
        municion();
        cout<<"Municiones: ";
        for(int i=0;i<sizeof(municiones)/sizeof(municiones[0]);i++){
            cout<<1+i<<".->"<<municiones[i]<<"  ";
        }
        cout<<endl;
        cout<<"Explorador: "<<vE<<endl;
        cout<<"Monstruo: "<<vM<<endl;
        cout<<endl;
        //APLICACIÓN DEL JUEGO EN EL MAPA

        bool end=false;//Se asume que siempre perderemos
            while(vE>0){
            cin>>action;
                if(action=='A'){
                    int nvertice;
                    cin>>nvertice;
                    if(nvertice>0 && nvertice<=grafo[verticeActual-'A'].size()){
                        monstruos[verticeActual-'A'].hurtIt(&expl);
                        expl.ouch(grafo[verticeActual-'A'][nvertice-1].first); 
                        verticeActual=nodosA[grafo[verticeActual-'A'][nvertice-1].second];
                    }else{
                        narrador.invalid();
                    }
                    if(nodosA[verticeActual-'A']==salida){
                        end=true;
                        break;
                    }
                }else if(action=='D'){
                    int proyectil;
                    cin>>proyectil;
                    if(municiones[proyectil-1]!=0){
                        monstruos[verticeActual-'A'].ouch(municiones[proyectil-1]);
                        municiones[proyectil-1]=0;
                        if(monstruos[verticeActual-'A'].pista()&&!pista.empty()){
                            pistasVisibles.push_back(pista.top());
                            pista.pop();
                        }
                    }
                }else{
                    narrador.invalid();
                }
                vE=expl.vidaActual();
                vM=monstruos[verticeActual-'A'].valorActual();
                if(vE>0){
                    cout<<"Nodo Actual: "<<nodosA[verticeActual-'A']<<endl;
                    cout<<"Pistas: ";
                    for(int i=0;i<pistasVisibles.size();i++){
                        cout<<nodosA[pistasVisibles[i]]<<" ";
                    }
                    cout<<endl;
                    cout<<"Nodos Vecinos: ";
                    for(int i=0;i<grafo[verticeActual-'A'].size();i++){
                        char vecino=nodosA[grafo[verticeActual-'A'][i].second];
                        cout<<vecino<<" ";
                    }
                    cout<<endl;
                    cout<<"Nodo Salida: "<<salida<<endl;
                    cout<<"Municiones: ";
                    for(int i=0;i<sizeof(municiones)/sizeof(municiones[0]);i++){
                        cout<<municiones[i]<<" ";
                    }
                    cout<<endl;
                    cout<<"Explorador: "<<vE<<endl;
                    cout<<"Monstruo: "<<vM<<endl;
                    cout<<endl;
                }
            }
            
            if(end){
            narrador.goodEnding();
            }else{
            narrador.badEnding();
            }
            }
            cout<<"Salir del juego?... Selecciona Y=Siiiii N=Nooooo"<<endl;
            char finalDecision;
            cin>>finalDecision;
            if(finalDecision=='Y'){
                playing=false;
                cout<<"Adios..."<<endl;
            }else if(finalDecision=='N'){
                playing=true;
                cout<<"Oscuridad y luz..."<<endl;
            }else{
                cout<<"Entrada invalida... Intentalo de nuevo"<<endl;
            }
        
    }
}

int main(){
    playing=true;
    game();
    return 0;
}


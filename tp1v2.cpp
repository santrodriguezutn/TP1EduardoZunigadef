#include <iostream>
#include <fstream>

using namespace std;

void mostrarnombres(string vecclie[], string vecprod[], int dimclie, int dimprod){
    for(int i=0; i < dimclie; i++){
        cout << "vec[" << i << "] = " << vecclie[i] << endl;
    }

    for(int i=0; i < dimprod; i++){
        cout << "vec[" << i << "] = " << vecprod[i] << endl;
    }

}

void mostrarmat(float vecpesoxprodclie[][5], int dimclie){
    const int dimprod {5};
    for(int i=0; i < dimclie; i++){
        for(int j=0; j < dimprod; j++){
            cout << vecpesoxprodclie[i][j] << '\t';
            cout << endl;
        }
    }
}

//PUNTO 1
void pesomay(float vecpeso[][5], string vecclie[], string vecprod[], int dimclie){
    const int dimprod {5};
    const int pesoclave{13000};

    for(int i=0; i < dimclie; i++){
        cout << "Cliente " << i << " :" << vecclie[i] << endl;
        for(int j=0; j < dimprod; j++){
            if(vecpeso[i][j] > pesoclave){
                cout << endl;
                //cout << "Cliente " << i << " :" << vecclie[i] << endl;
                cout << vecprod[j] << endl;
            }
        }
    }
}

//PUNTO 2
void contador(float vecpeso[][5], string vecclie[], string vecprod[], int cliente[]){
    const int dimprod {5};
    const int dimclie {8};
    const int pesoclave{13000};
    int cliemay;

    for(int i=0; i < dimclie; i++){
    for(int j=0; j < dimprod; j++){
        if(vecpeso[i][j] > pesoclave){
            cliente[i]++;
        }
        }
    }
}

int cliemay(float vecpeso[][5], string vecclie[], string vecprod[], int cliente[], float vecdist[][5]){
    const int dimclie {8};
    int clientemay = cliente[0];
    int aux{0};
    for(int i=1; i < dimclie; i++){
        if(cliente[i] > clientemay){
       clientemay = cliente[i];
        aux=i;
        }
    }return aux;
}

void mostrarlistado(float vecpeso[][5], string vecclie[], string vecprod[], int cliemay, float vecdist[][5]){
     const int pesoclave{13000};
     const int dimprod {5};

cout << "El cliente con mayor cantidad de productos que superan los 13.000kg es " << vecclie[cliemay] << endl;
cout << "Distancia total por producto: " << endl;
for(int i=0; i < dimprod; i++){
    cout << vecprod[i] << ":" << vecdist[cliemay][i] << endl;
}

}

void ordenar (float vecdist[][5], int dimprod,int clientemay, string vecaux[]){
    int pos, imin, i;
    float aux;
    for(pos=0; pos < dimprod-1; pos++){
        imin = pos;
        for(i=pos+1; i < dimprod; i++){
            if(vecdist[clientemay][i] < vecdist[clientemay][imin]){
                imin = i;
            }
        }
        swap(vecdist[clientemay][pos], vecdist[clientemay][imin]);
        swap(vecaux[pos], vecaux[imin]);
    }
}

//PUNTO 3
int buscarmayor (float distxprodclie[][5], int dimprod, int clientemay){
    float distmay = distxprodclie[clientemay][0];
    int imax = 0;
    for(int i=1; i < dimprod; i++){
        if(distxprodclie[clientemay][i] > distmay){
            imax = i;
            distmay = distxprodclie[clientemay][i];
        }
    }return imax;
}

int main(){

const int dimclie {8};
const int dimprod {5};

string nomclie[dimclie]{};
string nomprod[dimprod]{};
string vtemp[dimprod]{};
float pesoxprodclie[dimclie][dimprod]{};//vector para contabilizar el peso por producto y cliente
bool debug {true}; //para carteles de seguimiento
int cliecontador[dimclie]{}; //vector como contador de productos que superen los 13000kg
float distxprodclie[dimclie][dimprod]{};
int vecaux[dimclie][dimprod]{}; //Vector auxiliar para ordenar punto 2.
int entregasxprod[dimprod]{};

int iclie, iprod;
float ipeso, idist; 
float pesoxprod;

ifstream archilec;
archilec.open("Nombres.txt");

if(!archilec){
    cout << "Error al abrir el archivo." << endl;
    return 1;
}

for(int i=0; i < dimclie && archilec >> nomclie[i]; i++);
for(int i=0; i < dimprod && archilec >> nomprod[i]; i++);
if(debug){
    mostrarnombres(nomclie, nomprod, dimclie, dimprod);
}

archilec.close();

archilec.open("Datos.txt");
    
if(!archilec){
    cout << "Error al abrir el archivo." << endl;
    return 1;
}


while(archilec >> iclie >> iprod >> ipeso >> idist){
    pesoxprodclie[iclie][iprod] += ipeso;//PUNTO 1
    distxprodclie[iclie][iprod] += idist; //PUNTO 2
    entregasxprod[iprod]++; //PUNTO 3
}
archilec.close();

if(debug){
mostrarmat(pesoxprodclie, dimclie);
}

//PUNTO 1
pesomay(pesoxprodclie, nomclie, nomprod, dimclie);

//PUNTO 2
contador(pesoxprodclie, nomclie, nomprod, cliecontador);
int clientemay = cliemay(pesoxprodclie, nomclie, nomprod, cliecontador, distxprodclie);
cout << "----------------------------------------------" << endl;
cout << "CLIENTE CON MAYOR CANTIDAD DE PRODUCTOS QUE SUPERAN LOS 13000KG" << endl;
cout << "---------------- SIN ORDENAR ----------------" << endl;
mostrarlistado(pesoxprodclie, nomclie, nomprod, clientemay, distxprodclie);
ordenar (distxprodclie, dimprod, clientemay, nomprod);

cout << " ---------------- ORDENADO ----------------" << endl;
mostrarlistado(pesoxprodclie, nomclie, nomprod, clientemay, distxprodclie);

//PUNTO 3
int prodmay = buscarmayor (distxprodclie, dimprod, clientemay);
cout << "Los productos con mayor distancia recorrida son: " << nomprod[prodmay] << ", con " << entregasxprod[prodmay] << " entregas realizadas." << endl;

    cin.get();
    cin.ignore();
    return 0;
}

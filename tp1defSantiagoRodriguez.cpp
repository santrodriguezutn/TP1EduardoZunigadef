#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int dim_cliente {8};
const int dim_tprod {5};
string clientes[dim_cliente];
string tproductos[dim_tprod];
string nprodaux[dim_cliente];

int main(){
float pesos[dim_cliente][dim_tprod]{};
int clientmayprod [dim_cliente]{};
int contador [dim_cliente]{};
int prodmax[dim_tprod]{};
float distancia [dim_cliente][dim_tprod]{};
int cont[dim_cliente]{};


ifstream archilec;
archilec.open("NombresTP1.txt");
if(!archilec){
    cout << "Error al abrir el archivo de nombres." << endl;
    return 1;
}

for (int i = 0; i < dim_cliente; i++)
{
    archilec>>clientes[i];
}

for(int i=0; i<dim_tprod; i++)
{
    archilec>>tproductos[i];
    nprodaux[i]=tproductos[i];
}

archilec.close();

archilec.open("DatosTP1.txt");

if(!archilec)
{
    cout << "Error al abrir el archivo de datos" << endl;
    return 1;
}


int icliente, itprod;
float peso, dist;
while(archilec >> icliente >> itprod >> peso >> dist)
{
    pesos[icliente][itprod]+=peso;
    contador[itprod]++;
    distancia[icliente][itprod]+=dist;
    cont[icliente];
}

for (int j = 0; j < dim_tprod; j++)
{
    cout << contador[j] << endl;
}


for (int i = 0; i < dim_cliente; i++)
{
    for (int j = 0; j < dim_tprod; j++)
    {
        distancia[i][j];
    }  
}

archilec.close();

int campeon{0};
cout << "\nListado :" << endl;
for (int i = 0; i < dim_cliente ; ++i) {
        cout << clientes[i] << ": ";
        for (int j = 0; j < dim_tprod ; ++j) {
            if(pesos[i][j]>13000){
                 cout << tproductos[j] << "." << endl;
                 cont[i]++;
                 cont[i] > cont[i-1] ? cont[i] = campeon : cont[i-1] = campeon;//no se como lograr expresar al anterior correctamente para quedarme con el cliente con mas productos, creo que falla por el cont[i-1].
                 campeon = i;
                } 
                    else
                    {
                    cout << endl;
                    }
        }
}

//cout << "El cliente con mayor cantidad de productos que superan los 13000kg es: " << clientes[campeon] << endl;

// No puedo lograr obtener el nombre del cliente con mayor cantidad de productos que superen los 13000km.

//punto 3 , asi armaria la estructura para el punto 3

for(int i=0; i<dim_tprod; i++)
{
    cout << prodmax[i] << endl;
}


float temp;
int may;

for(int j=0; j<dim_tprod; j++)
{
    if(temp<prodmax[j])
    {
        temp==prodmax[j];
        j==may;
    }
}



cout << "El producto con mayor cantidad de kms recorridos es: " << tproductos[may] << "de las cuales se hicieron " << contador[may] << "entregas." << endl;

system ("PAUSE");
return 0;

}



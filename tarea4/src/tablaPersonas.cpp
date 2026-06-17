#include "../include/tablaPersonas.h"
/**/
struct rep_tablaPersonas {
    /*Lista*tabla;
    int max;*/
};
typedef rep_tablaPersonas* TTablaPersonas;

nat funcionDeDispersion(const char nombre[100]){
    /*nat res = 0;
    int i = 0;
    while(i< 100 && nombre[i] != '\0'){
        res += int(nombre[i]);
        i++;
    }
    return res;*/
    return 0;
}

TTablaPersonas crearTTablaPersonas(int max){
    /*TTablaPersonas h = new TTablaPersonas;
    h->n = max;
    h->tabla = new Lista[max];
    for (int i = 0; i < max; i++){
        h->tabla[i]=NULL;
    }
    return h;*/
    return NULL;
}

void insertarPersonaEnTTablaPersonas(TTablaPersonas &tabla, TPersona persona){
    /*int pos = funcionDeDispersion(persona->nombre);
    nodo*nuevo = new nodo;
    nuevo->persona = persona;
    nuevo->sig = t->tabla[pos];
    t->tabla[pos] = nuevo; // Insertamos a una persona
*/

}


void eliminarPersonaDeTTablaPersonas(TTablaPersonas &tabla, const char nombre[100]){
}

bool perteneceATTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
    return false;
}

TPersona obtenerPersonaDeTTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
    return NULL;
}


void liberarTTablaPersonas(TTablaPersonas &tabla){
}


void imprimirTTablaPersonas(TTablaPersonas tabla){
}
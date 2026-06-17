#include "../include/tablaPersonas.h"
struct rep_tablaPersonas {
    TPersonasLDE* tabla; // Tabla de dispersión abierta, cada posición de la tabla es una lista de personas
    int n; // Tamaño de la tabla de dispersión
};

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
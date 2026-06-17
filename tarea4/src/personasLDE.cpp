#include "../include/personasLDE.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////
//El nodo, contiene la variable que se trabaja, en este caso TPersona, además, contiene un puntero al siguiente nodo y al anterior nodo
struct Nodo {
    TPersona rpersona;
    Nodo *siguiente;
    Nodo *anterior;
};
//El cabezal, contiene la variable que se trabaja, en este caso TPersonas LDE, el cual es un puntero a rep_personasLDE, además, contiene inicio y fin
struct rep_personasLDE {
    Nodo *inicio;
    Nodo *fing;
};



TPersonasLDE crearTPersonasLDE(){
    TPersonasLDE personasLDE = new rep_personasLDE;
    personasLDE->inicio = NULL;
    personasLDE->fing = NULL;
    return personasLDE;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->rpersona = persona;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    //caso Lista vacía, por lo tanto, el nuevo nodo es el inicio y el fin de la lista
    if (personas->inicio == NULL) 
    {
        personas->inicio = nuevoNodo;
        personas->fing = nuevoNodo;
        return;
    }else if (pos == 1)
    {
        //caso insertar al inicio de la lista, pos es 1
        nuevoNodo->siguiente = personas->inicio;
        personas->inicio->anterior = nuevoNodo;
        personas->inicio = nuevoNodo;
        return;
    }
    //caso recorrer hasta pos
    Nodo* nodoActual = personas->inicio;
    nat contador = 1;
    while(nodoActual->siguiente != NULL && contador < pos-1)
    {
        nodoActual = nodoActual->siguiente;
        contador++;
    }

    //caso insertar al final de la lista, pos es mayor que la cantidad de personas en la lista
    
   /**/ if(nodoActual->siguiente == NULL && contador < pos){
        if(personas->fing != NULL){
            personas->fing->siguiente = nuevoNodo;
            nuevoNodo->anterior = personas->fing;
        }
        personas->fing = nuevoNodo;
    }
    else{
        //insertar en medio, después del nodo actual
        nuevoNodo->siguiente = nodoActual->siguiente;
        nuevoNodo->anterior = nodoActual;
        nodoActual->siguiente = nuevoNodo;
        if (nuevoNodo->siguiente != NULL) {
            nuevoNodo->siguiente->anterior = nuevoNodo;
        } else {
            personas->fing = nuevoNodo;
        }
    }
}

void liberarTPersonasLDE(TPersonasLDE &personasLDE){
    if (personasLDE == NULL) {
        return;
    }
    Nodo* nodoActual = personasLDE->inicio;
    while (nodoActual != NULL){
        Nodo* nodoSiguiente = nodoActual->siguiente;

        liberarTPersona(nodoActual->rpersona);

        delete nodoActual;
        nodoActual = nodoSiguiente;


    }
    delete personasLDE;
    personasLDE = NULL;

}

void imprimirTPersonasLDE(TPersonasLDE personas){
    if (personas->inicio == NULL){
        return;
    }
    Nodo* nodoActual = personas->inicio;

    while(nodoActual->siguiente != NULL){
        imprimirTPersona(nodoActual->rpersona);
        nodoActual = nodoActual->siguiente;
    }
    imprimirTPersona(nodoActual->rpersona);
}

nat cantidadTPersonasLDE(TPersonasLDE personas){
    nat contador;
    contador = 1;
    Nodo* nodoActual = personas->inicio;
    
    if (personas->inicio != NULL){

    while (nodoActual ->siguiente != NULL)
    {
        nodoActual = nodoActual->siguiente;
        contador ++;
    }
    return contador;
    }
    
    return 0;
}

void eliminarInicioTPersonasLDE(TPersonasLDE &personas){
    if(personas ->inicio == NULL){
        return;
    }
    Nodo * nodoBorrar = personas->inicio;
    personas ->inicio = nodoBorrar->siguiente;
    if(personas->inicio != NULL){
        personas->inicio->anterior = NULL;
    }else{
        personas ->fing = NULL;
    }
    liberarTPersona(nodoBorrar->rpersona);
    delete nodoBorrar;
    
}


void eliminarFinalTPersonasLDE(TPersonasLDE &personas){
    if(personas->fing == NULL){
        return;
    }
    Nodo* nodoBorrar = personas->fing;
    personas ->fing = nodoBorrar->anterior;
    if(personas->fing != NULL){
        personas->fing->siguiente = NULL;

    }
    else{
        personas -> inicio = NULL;
    }
    liberarTPersona(nodoBorrar->rpersona);
    delete nodoBorrar;
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id){
Nodo* nodoActual = personas->inicio;

while (nodoActual != NULL)
{
    if (idTPersona(nodoActual->rpersona)== id){
        return true;
    }
    nodoActual = nodoActual->siguiente;
}
    return false;
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id){
    Nodo* nodoActual = personas->inicio;
        while (nodoActual != NULL )
        {
            if (idTPersona(nodoActual->rpersona) == id){
                return nodoActual->rpersona;
            }
            nodoActual = nodoActual->siguiente;
        }
    return NULL;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2){

    TPersonasLDE nuevaLista = crearTPersonasLDE();
    if (personas1->inicio == NULL && personas2->inicio == NULL){
        nuevaLista->inicio = NULL;
        nuevaLista->fing = NULL;
    }
    if (personas2 ->inicio == NULL){
        nuevaLista->inicio = personas1->inicio;
        nuevaLista->fing = personas1->fing;
    }
    else if (personas1->inicio == NULL){
        nuevaLista->inicio = personas2->inicio;
        nuevaLista->fing = personas2->fing;
    }
    else {
        nuevaLista->inicio = personas1->inicio;
        nuevaLista->fing = personas2->fing;
        personas1->fing->siguiente = personas2->inicio;
        personas2->inicio->anterior = personas1->fing;
    }
    delete personas1;
    delete personas2;
    
    return nuevaLista;
}

void insertarInicioDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->rpersona = persona;
    nuevoNodo->anterior = NULL;


    if(personas->inicio == NULL){
        nuevoNodo->siguiente = NULL;
        personas->inicio = nuevoNodo;
        personas->fing = nuevoNodo;
        return;
    }

    nuevoNodo->siguiente = personas->inicio;
    personas->inicio->anterior = nuevoNodo;
    personas->inicio = nuevoNodo;
}

void insertarFinalDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){    
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->rpersona = persona;
    nuevoNodo->siguiente = NULL;

    if(personas->fing == NULL){
        personas->inicio = nuevoNodo;
        personas->fing = nuevoNodo;
        return;
    }
    personas->fing->siguiente = nuevoNodo;
    nuevoNodo->anterior = personas->fing;
    personas->fing = nuevoNodo;
}

TPersona obtenerInicioDeTPersonasLDE(TPersonasLDE personas){
    return personas->inicio->rpersona;
}

TPersona obtenerFinalDeTPersonasLDE(TPersonasLDE personas){
    return personas->fing->rpersona;
}
///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void eliminarPersonaConNombreTPersonasLDE(TPersonasLDE &personas, const char nombre[100]){
    if(personas->inicio != NULL){
        
        Nodo* nodoActual = personas->inicio;
        while(nodoActual != NULL){
            if(strcmp(nombreTPersona(nodoActual->rpersona), nombre) == 0){
                if(nodoActual->anterior != NULL){
                    nodoActual->anterior->siguiente = nodoActual->siguiente;
                }else{
                    personas->inicio = nodoActual->siguiente;
                }
                if(nodoActual->siguiente != NULL){
                    nodoActual->siguiente->anterior = nodoActual->anterior;
                }else{
                    personas->fing = nodoActual->anterior;
                }
                liberarTPersona(nodoActual->rpersona);
                delete nodoActual;
                return;
            }
            nodoActual = nodoActual->siguiente;
        }
    }
}

bool estaPersonaConNombreEnTPersonasLDE(TPersonasLDE personas, const char nombre[100])
{
    if(personas->inicio != NULL){
        Nodo* nodoActual = personas->inicio;
        while(nodoActual != NULL){
            if(strcmp(nombreTPersona(nodoActual->rpersona), nombre) == 0){
                return true;
            }
            nodoActual = nodoActual->siguiente;
        }
    }
    return false;
}

TPersona obtenerPersonaConNombreTPersonasLDE(TPersonasLDE personas, const char nombre[100]){
    if(personas->inicio != NULL){
        Nodo* nodoActual = personas->inicio;
        while(nodoActual != NULL){
            if(strcmp(nombreTPersona(nodoActual->rpersona), nombre) == 0){
                return nodoActual->rpersona;
            }
            nodoActual = nodoActual->siguiente;
        }
    }
    return NULL;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


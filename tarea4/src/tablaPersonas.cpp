#include "../include/tablaPersonas.h"
struct rep_tablaPersonas {
    TPersonasLDE* tabla; // Tabla de dispersión abierta, cada posición de la tabla es una lista de personas
    int n; // Tamaño de la tabla de dispersión
};

nat funcionDeDispersion(const char nombre[100]){
    nat res = 0;
    int i = 0;
    while(i< 100 && nombre[i] != '\0'){
        res += int(nombre[i]);
        i++;
    }
    return res;
}

TTablaPersonas crearTTablaPersonas(int max){
    TTablaPersonas t = new rep_tablaPersonas;
    t->n = max;
    t->tabla = new TPersonasLDE[max];
    for (int i = 0; i < max; i++) {
        t->tabla[i] = crearTPersonasLDE(); // Inicializamos cada posición de la tabla con una lista vacía de personas
    }
    return t;
}

void insertarPersonaEnTTablaPersonas(TTablaPersonas &tabla, TPersona persona){
    int pos = funcionDeDispersion(nombreTPersona(persona)) % tabla->n; // Calculamos la posición en la tabla de dispersión
    insertarTPersonasLDE(tabla->tabla[pos], persona, 1); // Insertamos la persona al inicio de la lista en esa posición

}


void eliminarPersonaDeTTablaPersonas(TTablaPersonas &tabla, const char nombre[100]){
    int pos = funcionDeDispersion(nombre) % tabla->n; // Calculamos la posición en la tabla de dispersión
    eliminarPersonaConNombreTPersonasLDE(tabla->tabla[pos], nombre); // Eliminamos la persona con el nombre dado de la lista en esa posición
}

bool perteneceATTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
    int pos = funcionDeDispersion(nombre) % tabla->n; // Calculamos la posición en la tabla de dispersión
    return estaPersonaConNombreEnTPersonasLDE(tabla->tabla[pos], nombre); // Verificamos si la persona con el nombre dado pertenece a la lista en esa posición
}

TPersona obtenerPersonaDeTTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
    int pos = funcionDeDispersion(nombre) % tabla->n; // Calculamos la posición en la tabla de dispersión
    return obtenerPersonaConNombreTPersonasLDE(tabla->tabla[pos], nombre); // Devolvemos la persona con el nombre dado de la lista en esa posición
}


void liberarTTablaPersonas(TTablaPersonas &tabla){
    if(tabla != NULL){
        for(int i = 0; i < tabla->n; i++){
            liberarTPersonasLDE(tabla->tabla[i]); // Liberamos cada lista de personas en la tabla
        }
        delete[] tabla->tabla; // Liberamos la memoria de la tabla de dispersión
        delete tabla; // Liberamos la memoria de la estructura de la tabla
        tabla = NULL; // Evitamos que el puntero quede colgando
    }
}


void imprimirTTablaPersonas(TTablaPersonas tabla){
    for(int i = 0; i < tabla->n; i++){
        imprimirTPersonasLDE(tabla->tabla[i]); // Imprimimos cada lista de personas en la tabla
    }
}
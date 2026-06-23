#include "../include/aplicaciones.h"
#include "../include/colaDePrioridadPersona.h"


// tenemos un arreglo de nombres y una tabla t
//hay que encontrar las coincidencias entre el arreglo y la tabla
//e imprimirlas en orden de prioridad según la fecha del primer evento
//de cada persona nombrada en el arreglo de nombres que tenga coincidencia dentro de la tabla

//funcoines a usar:

//primero comprobar que nombres de la lista estan en la tabla, conforme vayan dando positivo, irlos obteniendo y guardando en
//la cola de prioridad 

//para esto primero hay que crear la cola de prioridad y cada que pertenece a ttabla perosonas de true, se obtiene la persona
//y se inserta en la cola de prioridad

//por ultimo usamos un for de 0 a tope para imprimir cada persona de la cola de prioridad y la liberamos al final.


void listarEnOrden(TTablaPersonas t, char** nombres, nat n){
    TColaDePrioridadPersona cp = crearCP(MAX_ID);
    for (nat i = 0; i < n; i++){
        if(perteneceATTablaPersonas(t,nombres[i])){
            insertarEnCP(copiarTPersona(obtenerPersonaDeTTablaPersonas(t,nombres[i])),cp);
        }
    }

    while(!estaVaciaCP(cp)){
        imprimirTPersona(prioritaria(cp));
        eliminarPrioritaria(cp);
    }
    liberarCP(cp);
}
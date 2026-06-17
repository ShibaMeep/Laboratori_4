#include "../include/evento.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////
struct rep_evento {
    int id;
    char descripcion[MAX_DESCRIPCION];
    TFecha fecha;
};

TEvento crearTEvento(int id, const char descripcion[MAX_DESCRIPCION], TFecha fecha) {
    TEvento nuevoEvento = NULL;
    nuevoEvento = new rep_evento;
    nuevoEvento->id = id;
    strncpy(nuevoEvento->descripcion, descripcion, MAX_DESCRIPCION);
    nuevoEvento->fecha = fecha;
    return nuevoEvento;
}

void imprimirTEvento(TEvento evento) {
    printf("Evento %d: ", evento->id);
    printf("%s\n", evento->descripcion);
    printf("Fecha: ");
    imprimirTFecha(fechaTEvento(evento));
}

void liberarTEvento(TEvento &evento) {
    liberarTFecha(evento->fecha);
    delete evento;
    evento = NULL;
}

int idTEvento(TEvento evento) {
    int res = 0;
    res = evento->id;
    return res;
}

TFecha fechaTEvento(TEvento evento) {
    TFecha fecha = NULL;
     fecha = evento->fecha;
    return fecha;
}

void posponerTEvento(TEvento &evento, int dias) {
    aumentarTFecha(evento->fecha, dias);
}

TEvento copiarTEvento(TEvento evento) {
    TEvento copiaEvento = NULL;
    if (evento != NULL) {
        copiaEvento = crearTEvento(evento->id, evento->descripcion, copiarTFecha(evento->fecha));
    }
    return copiaEvento;
}

/////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
/////////////////////////////////

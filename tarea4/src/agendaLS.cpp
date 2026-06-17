#include "../include/agendaLS.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct rep_agendaLS {
     TEvento evento;
    rep_agendaLS *sig;
};

TAgendaLS crearAgendaLS() {
    TAgendaLS nuevaAgenda = NULL;
    return nuevaAgenda;
}

void agregarEnAgendaLS(TAgendaLS &agenda, TEvento evento) {
    TAgendaLS nuevo = new rep_agendaLS;
    nuevo->evento = evento;
    nuevo->sig = NULL;

    //Lista vacía o va al inicio
    if (agenda == NULL ||
        compararTFechas(fechaTEvento(evento),
                        fechaTEvento(agenda->evento)) <= 0)
    {
        nuevo->sig = agenda;
        agenda = nuevo;
        return;
    }

    TAgendaLS actual = agenda;

    //avanzar mientras la fecha sea menor
    while (actual->sig != NULL &&
           compararTFechas(fechaTEvento(evento),
                           fechaTEvento(actual->sig->evento)) > 0)
    {
        actual = actual->sig;
    }

    //si hay fechas iguales, NO avanzar
    //así el nuevo queda antes

    nuevo->sig = actual->sig;
    actual->sig = nuevo;
}


void imprimirAgendaLS(TAgendaLS agenda) {
     if (agenda->evento != NULL)
    {
        TAgendaLS actual = agenda;
        while (actual != NULL)
        {
            imprimirTEvento(actual->evento);
            actual = actual->sig;
        }
    }
}

void liberarAgendaLS(TAgendaLS &agenda) {
     while (agenda != NULL)
    {
        TAgendaLS nodoSiguiente = agenda->sig;
        liberarTEvento(agenda->evento);
        delete agenda;
        agenda = nodoSiguiente;
    }
    agenda = NULL;
}

bool esVaciaAgendaLS(TAgendaLS agenda){
   if (agenda == NULL)
        return true;
    return false;
}

TAgendaLS copiarAgendaLS(TAgendaLS agenda){
    TAgendaLS nuevaAgenda = crearAgendaLS();
    while (agenda != NULL)
    {
        TEvento eventoCopia = copiarTEvento(agenda->evento);
        agregarEnAgendaLS(nuevaAgenda, eventoCopia);
        agenda = agenda->sig;
    }
    return nuevaAgenda;
}


bool estaEnAgendaLS(TAgendaLS agenda, int id) {
   while (agenda != NULL)
    {
        if (idTEvento(agenda->evento) == id)
        {
            return true;
        }
        agenda = agenda->sig;
    }

    return false;
}

TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id) {
    while (agenda != NULL)
    {
        if (idTEvento(agenda->evento) == id) //el problema era que esta en agenda itera 2 veces, por lo que se compara directamente.
        {
            return agenda->evento;
        }
        agenda = agenda->sig;
    }
    return NULL;
}

void posponerEnAgendaLS(TAgendaLS &agenda, int id, nat n) {
      TAgendaLS nodoActual = agenda;
    TAgendaLS nodoAnterior = NULL;

    while (nodoActual != NULL)
    {
        if (idTEvento(nodoActual->evento) == id)
        {
            //sacar nodo de la lista
            if (nodoAnterior == NULL)
                agenda = nodoActual->sig;
            else
                nodoAnterior->sig = nodoActual->sig;

            TEvento eventoP = nodoActual->evento;

            //modificar directamente
            posponerTEvento(eventoP, n);

            delete nodoActual;

            //reinsertar
            agregarEnAgendaLS(agenda, eventoP);

            return;
        }

        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }
}

void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha) {
     while (agenda != NULL)
    {
        if (compararTFechas(fecha, fechaTEvento(agenda->evento)) == 0)
        {
            imprimirTEvento(agenda->evento);
        }
        agenda = agenda->sig;
    }
}

bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha) {
   while (agenda != NULL)
    {
        if (compararTFechas(fecha, fechaTEvento(agenda->evento)) == 0)
        {
            return true;
        }
        agenda = agenda->sig;
    }
    return false;
}

void removerDeAgendaLS(TAgendaLS &agenda, int id) {
     TAgendaLS nodoActual = agenda;
    TAgendaLS nodoAnterior = NULL;

    while (nodoActual != NULL)
    {
        if (idTEvento(nodoActual->evento) == id)
        {
            //sacar nodo de la lista
            if (nodoAnterior == NULL)
                agenda = nodoActual->sig;
            else
                nodoAnterior->sig = nodoActual->sig;

            liberarTEvento(nodoActual->evento);
            delete nodoActual;

            return;
        }

        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEvento primerEventoAgendaLS(TAgendaLS agenda){
    if (agenda!=NULL){ 
    return obtenerDeAgendaLS(agenda, 1);
 }
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
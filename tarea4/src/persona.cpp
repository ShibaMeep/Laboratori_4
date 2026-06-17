#include "../include/persona.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////
struct rep_persona {
int id;
nat edad;
char nombre[MAX_NOMBRE];
TAgendaLS agenda;
};


TPersona crearTPersona(nat id, nat edad, const char nombre[MAX_NOMBRE], TAgendaLS agenda) {
    TPersona nuevo = new rep_persona;

    nuevo->id = id;
    nuevo->edad = edad;
    strncpy(nuevo->nombre, nombre, MAX_NOMBRE);

    if (agenda != NULL) {
        nuevo->agenda = agenda;
    } else {
        nuevo->agenda = crearAgendaLS();
    }
    return nuevo;
}

void liberarTPersona(TPersona& persona) {
    if(!esVaciaAgendaLS(persona->agenda)){
        liberarAgendaLS(persona->agenda);
    }

    delete persona;
    persona = NULL;
}

//Imprime a la persona utilizando printf e imprimeAgendaLS
void imprimirTPersona(TPersona persona) {
    printf("Persona %d: %s, %d años\n",
        persona->id, persona->nombre, persona->edad );

    if(persona->agenda != NULL){
        imprimirAgendaLS(persona->agenda);
    }
}

nat idTPersona(TPersona persona) {
    if (persona != NULL){
        return persona->id;
    }
    return 0;
}

nat edadTPersona(TPersona persona) {
    if (persona != NULL){
        return persona->edad;
    }
    return 0;
}

char* nombreTPersona(TPersona persona) {
    if (persona != NULL){
        return persona ->nombre;
    }
    return NULL;
}

TAgendaLS agendaTPersona(TPersona persona) {
    if(persona != NULL){
        return persona->agenda;
    }
    return NULL;
}

void agregarEventoATPersona(TPersona &persona, TEvento evento) {
    agregarEnAgendaLS(persona ->agenda, evento);
}

void posponerEventoEnTPersona(TPersona &persona, int id, nat n) {
    posponerEnAgendaLS(persona->agenda, id, n);
}

void removerEventoDeTPersona(TPersona &persona, int id) {
    removerDeAgendaLS(persona->agenda,id);
}

bool estaEnAgendaDeTPersona(TPersona persona, int id) {
    if(estaEnAgendaLS(persona->agenda, id)){
        return true;
    }
    return false;
}

TEvento obtenerDeAgendaDeTPersona(TPersona persona, int id) {
    return obtenerDeAgendaLS(persona->agenda,id);
}

TPersona copiarTPersona(TPersona persona) {
    TPersona personaCopia = NULL;
    if(persona != NULL){
        personaCopia = crearTPersona(persona->id, persona->edad, persona->nombre, copiarAgendaLS(persona->agenda));
    }
    return personaCopia;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEvento primerEventoDeTPersona(TPersona persona){
    /*if (!esVaciaAgendaLS(persona->agenda)){
        return primerEventoAgendaLS(persona->agenda);
    }*/
    return NULL;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

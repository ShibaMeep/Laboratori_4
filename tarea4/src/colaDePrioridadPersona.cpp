#include "../include/colaDePrioridadPersona.h"
#include "../include/utils.h"
#include "../include/evento.h"
#include "../include/fecha.h"
struct rep_colaDePrioridadPersona {
TPersona* cola;
nat* posiciones;
nat tope;
nat cantidad;
};


TFecha fecha_prioritaria(TPersona persona){
  TEvento evento = primerEventoDeTPersona(persona);
  return fechaTEvento(evento);
}

void filtrado_ascendente(nat pos, TColaDePrioridadPersona &cp){
  bool para = false;
  while (pos > 1 && para == false) {
    nat posPadre = pos / 2;

    TFecha fechaHijo = fecha_prioritaria(cp->cola[pos]);
    TFecha fechaPadre = fecha_prioritaria(cp->cola[posPadre]);

    if (compararTFechas(fechaHijo, fechaPadre)< 0){
      TPersona aux = cp->cola[pos];
      cp->cola[pos] = cp->cola[posPadre];
      cp->cola[posPadre] = aux;

      cp->posiciones[idTPersona(cp->cola[pos])] = pos;
      cp->posiciones[idTPersona(cp->cola[posPadre])] = pos;

      pos = posPadre;

    }else {
      para = true;
    }
  }
}

TColaDePrioridadPersona crearCP(nat N) {
  //reservamos memoria para la estructura 
  TColaDePrioridadPersona cola = new rep_colaDePrioridadPersona; //Theta 1
  cola->cantidad = N; //Theta 1
  cola->tope = 0; //Theta 1

  //reservamos memoria para la cola 
  cola->cola = new TPersona[N +1 ]; //Theta N

  //reservamos memoria para las posiciones
  cola->posiciones = new nat[N + 1]; //Theta N


  //inicializamos las posiciones
  for (nat i = 1; i <= N; i++){
    cola->posiciones[i] = 0; //Theta N
  }
  return cola;
} 

void invertirPrioridad(TColaDePrioridadPersona &cp) {

}

void liberarCP(TColaDePrioridadPersona &cp) {
  if(cp != NULL){

    for (nat i = 1; i <= cp->tope; i++){
      liberarTPersona(cp->cola[i]);
    }
    delete[] cp->cola;
    delete[] cp->posiciones;
    delete cp;
    cp = NULL;
  }
}

void insertarEnCP(TPersona persona, TColaDePrioridadPersona &cp) {
  cp->tope++;

  nat posNueva = cp->tope;
  cp->cola[cp->tope] = persona;

  nat id = idTPersona(persona);
  cp->posiciones[id] = posNueva;


  filtrado_ascendente(posNueva, cp);
}

bool estaVaciaCP(TColaDePrioridadPersona cp) {
  return cp->tope == 0;
}

TPersona prioritaria(TColaDePrioridadPersona cp) {
  return cp->cola[1];
} 

void eliminarPrioritaria(TColaDePrioridadPersona &cp) {
  if (estaVaciaCP(cp))
   return;
}

bool estaEnCP(nat id, TColaDePrioridadPersona cp) {
  if (id > cp->cantidad || id < 1)
    return false;
  return cp->posiciones[id] != 0;
}

TFecha prioridad(nat id, TColaDePrioridadPersona cp){
  return NULL;
}
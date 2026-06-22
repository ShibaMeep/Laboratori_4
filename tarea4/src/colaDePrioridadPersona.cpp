#include "../include/colaDePrioridadPersona.h"
#include "../include/utils.h"
#include "../include/evento.h"

struct rep_colaDePrioridadPersona {
TPersona* cola;
nat* posiciones;
nat tope;
nat cantidad;
};


void filtrado_ascendente(nat pos, TColaDePrioridadPersona &cp){

}


TFecha fecha_prioritaria(TColaDePrioridadPersona cp){
  TFecha fecha = NULL;
    nat j = 2;
    nat k = 1;
    for(nat i = 1; i <= cp->cantidad; i++){
      if(!esVaciaAgendaLS()){

      }
    }

  return NULL;
}


TColaDePrioridadPersona crearCP(nat N) {
  //reservamos memoria para la estructura 
  TColaDePrioridadPersona cola = new rep_colaDePrioridadPersona; //Theta 1
  cola->tope = N; //Theta 1
  cola->cantidad = 0; //Theta 1

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
  
}

void insertarEnCP(TPersona persona, TColaDePrioridadPersona &cp) {
 
}

bool estaVaciaCP(TColaDePrioridadPersona cp) {
  return cp->cantidad == 0;
}

TPersona prioritaria(TColaDePrioridadPersona cp) {
  return cp->cola[1];
} 

void eliminarPrioritaria(TColaDePrioridadPersona &cp) {
  if (estaVaciaCP(cp))
   return;
}

bool estaEnCP(nat id, TColaDePrioridadPersona cp) {
  return cp->posiciones[id] != 0;
}

TFecha prioridad(nat id, TColaDePrioridadPersona cp){
  return NULL;
}
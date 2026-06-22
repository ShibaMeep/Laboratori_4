#include "../include/colaDePrioridadPersona.h"
#include "../include/utils.h"
#include "../include/evento.h"
#include "../include/fecha.h"
struct rep_colaDePrioridadPersona {
TPersona* cola;
nat* posiciones;
nat tope;
nat cantidad;
bool invertida;
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

    int cmp = compararTFechas(fechaHijo, fechaPadre);
    bool debe_subir = (cp->invertida) ? (cmp > 0) : (cmp < 0);

    if (debe_subir){
      TPersona aux = cp->cola[pos];
      cp->cola[pos] = cp->cola[posPadre];
      cp->cola[posPadre] = aux;

      cp->posiciones[idTPersona(cp->cola[pos])] = pos;
      cp->posiciones[idTPersona(cp->cola[posPadre])] = posPadre;

      pos = posPadre;

    }else {
      para = true;
    }
  }
}

void filtrado_descendente(nat pos, TColaDePrioridadPersona &cp) {
  bool para = false;

  while (2* pos <= cp->tope && !para){
    nat hIzq = 2 * pos;
    nat hDer = hIzq + 1;
    nat hSelect = hIzq;

    if (hDer <= cp->tope){
      TFecha fechaHDer = fecha_prioritaria(cp->cola[hDer]);
      TFecha fechaHIzq = fecha_prioritaria(cp->cola[hIzq]);
      int cmp = compararTFechas(fechaHDer, fechaHIzq);

      bool seleccionar_der = (cp->invertida) ? (cmp > 0) : (cmp < 0);
      if (seleccionar_der){
        hSelect = hDer;
      }
    }

    TFecha fechaHSelect = fecha_prioritaria(cp->cola[hSelect]);
    TFecha fechaPadre = fecha_prioritaria(cp->cola[pos]);
    int cmp = compararTFechas(fechaHSelect, fechaPadre);

    bool debe_bajar = (cp->invertida) ? (cmp > 0) : (cmp < 0);
    if (debe_bajar){
      TPersona aux = cp->cola[pos];
      cp->cola[pos] = cp->cola[hSelect];
      cp->cola[hSelect] = aux;

      cp->posiciones[idTPersona(cp->cola[pos])] = pos;
      cp->posiciones[idTPersona(cp->cola[hSelect])] = hSelect;

      pos = hSelect;
    } else {
      para = true;
    }
  }
}

TColaDePrioridadPersona crearCP(nat N) {
  //reservamos memoria para la estructura 
  TColaDePrioridadPersona cola = new rep_colaDePrioridadPersona; //Theta 1
  cola->cantidad = N; //Theta 1
  cola->tope = 0; //Theta 1
  cola->invertida = false; //Theta 1

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
  cp->invertida = !cp->invertida;
  
  if (cp->tope <= 1){
    return;
  }

  // Hacer heapify-down para reorganizar el heap con el nuevo criterio
  for (int i = cp->tope / 2; i >= 1; i--) {
    filtrado_descendente(i, cp);
  }
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
  if (estaVaciaCP(cp)){
    return;
  }

  TPersona personaEliminada = cp->cola[1];
  nat idEliminar = idTPersona(personaEliminada);
  cp->posiciones[idEliminar] = 0;

  if(cp->tope == 1){
    cp->tope--;
  } else {
    cp->cola[1] = cp->cola[cp->tope];
    cp->tope--;

    nat idNuevaPrioritaria = idTPersona(cp->cola[1]);
    cp->posiciones[idNuevaPrioritaria] = 1;

    filtrado_descendente(1, cp);

  }
  liberarTPersona(personaEliminada);
}

bool estaEnCP(nat id, TColaDePrioridadPersona cp) {
  if (id > cp->cantidad || id < 1)
    return false;
  return cp->posiciones[id] != 0;
}

TFecha prioridad(nat id, TColaDePrioridadPersona cp){
  nat pos = cp->posiciones[id];
  return fecha_prioritaria(cp->cola[pos]);
}
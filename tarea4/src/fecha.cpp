#include "../include/fecha.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct rep_fecha {
nat dia, mes, anio;
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
     TFecha nuevaFecha = NULL;
    nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
      delete fecha;  
    fecha = NULL;
}

void imprimirTFecha(TFecha fecha) {
     printf("%d/%d/%d", fecha->dia, fecha->mes, fecha->anio);
    printf("\n");
}
nat diasMes(nat mes, nat anio){
    nat dias = 0;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dias = 31;
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        case 2:
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
                dias = 29;
            } else {
                dias = 28;
            }
    } 
    return dias;  
}

void aumentarTFecha(TFecha &fecha, nat dias) {
    nat diasRestantes = dias;
    while (diasRestantes > 0) {
        nat diasEnMes = diasMes(fecha->mes, fecha->anio);
        nat diasHastaFinMes = diasEnMes - fecha->dia;
        if (diasRestantes <= diasHastaFinMes) {
            fecha->dia += diasRestantes;
            diasRestantes = 0;
        } else {
            fecha->dia = 1;
            fecha->mes++;
            if (fecha->mes > 12) {
                fecha->mes = 1;
                fecha->anio++;
            }
            diasRestantes -= (diasHastaFinMes + 1);
        }
    }

}

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    if (fecha1->anio < fecha2->anio) {
        res = -1;
    } else if (fecha1->anio > fecha2->anio){
        res = 1;
    } else {
        if(fecha1->mes < fecha2->mes){
            res = -1;
        } else if (fecha1->mes > fecha2->mes){
            res = 1;
        } else {
            if (fecha1->dia < fecha2->dia){
                res = -1;
            } else if (fecha1->dia > fecha2->dia){
                res = 1;   
            }
        }   
    }
    return res;
}

TFecha copiarTFecha(TFecha fecha) {
     TFecha copiaFecha = NULL;
    if (fecha != NULL) {
        copiaFecha = crearTFecha(fecha->dia, fecha->mes, fecha->anio);
    }
    return copiaFecha;
}

/////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
/////////////////////////////////

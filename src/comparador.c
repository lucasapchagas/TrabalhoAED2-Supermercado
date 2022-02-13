#include <stdio.h>
#include <stdlib.h>

#include "comparador.h"
#include "evento.h"

int compararEvento(void *evento1, void *evento2){
  evento *e1 = evento1;
  evento *e2 = evento2;
  //return (e1->tempo - e2->tempo);

  if (e1->tempo < e2->tempo){
    return -1;
  }else if(e1->tempo > e2->tempo){
          return 1;
  }else{
    if( (e1->tipo==0) && (e2->tipo == 1) ){
      return -1;
    }else if ( (e2->tipo == 0) && (e1->tipo == 1) ){
        return 1;
    }else{
      return 0;
    }
  }
}
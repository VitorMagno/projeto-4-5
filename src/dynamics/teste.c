#include <stdlib.h>
#include <structs.c>

void CriarLista(DATABASE *db){
  CITIES c;
  db = malloc(sizeof(DATABASE));
  db->city = c;
  db->head = NULL;
}


void Insere_Inicio(DATABASE *L, CITIES elem){
  Rec *p;
  p = malloc(sizeof(Rec));
  p->elem = elem;
  p->lig = L->head;
  L->head = p;
  L-> nelem++;
}

int Primeiro(DATABASE *L){
  return L->head->elem.name;
}

int Nelem(DATABASE *L){
  return L->nelem;
}

int main(){
  
  int elemento = 1;


  return 0;
}
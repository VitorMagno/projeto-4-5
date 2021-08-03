/*
    Implemente um banco de dados da cidade usando listas não ordenadas. 
    Cada registro do banco de dados contém o nome da cidade (uma string de comprimento arbitrário)
    e as coordenadas da cidade expressa como coordenadas x e y inteiras. Seu banco de dados deve
    permite que os registros sejam inseridos, excluídos por nome ou coordenada e pesquisados
    por nome ou coordenada. Outra operação que deve ser suportada é imprimir todos os registros 
    dentro de uma determinada distância de um ponto especificado. Implementar o banco de dados usando
    uma implementação de lista baseada em array e, em seguida, uma implementação de lista vinculada. 
    Colete estatísticas de tempo de execução para cada operação em ambas as implementações.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "structs.c"
#include "readFile.c"
#include "insertAndDelete.c"
#include "menu.c"

int main(){
    DATABASE db;
    int dbLength = readFile(&db);
    if(dbLength == -1){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    } else {
        menu(dbLength, &db);
    }

    return 0;
}
/*
    Implemente um banco de dados da cidade usando listas não ordenadas. 
    Cada registro do banco de dados contém o nome da cidade (uma string de comprimento arbitrário)
    e as coordenadas da cidade expressa como coordenadas xey inteiras. Seu banco de dados deve
    permite que os registros sejam inseridos, excluídos por nome ou coordenada e pesquisados
    por nome ou coordenada. Outra operação que deve ser suportada é imprimir todos os registros 
    dentro de uma determinada distância de um ponto especificado. Implementar o banco de dados usando
    uma implementação de lista baseada em array e, em seguida, uma implementação de lista vinculada. 
    Colete estatísticas de tempo de execução para cada operação em ambas as implementações.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"
#include "readFile.c"

int main(){
    DATABASE db;
    BOOL isRead = readFile(&db);
    if(isRead == 0){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    }

    // printf("%d = isRead", isRead);
    

    return 0;
}
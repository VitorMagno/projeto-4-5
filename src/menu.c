#include <math.h>

void menu();
void insert_city();
int answer = 0;

void print_cities(int dbLength, DATABASE* db){
    system("clear");
    char keyInput;
    for(int i = 0; i < dbLength; ++i){
        printf("%s [%d, %d]\n", db->city[i].name, db->city[i].coords[0], db->city[i].coords[1]);
    }
    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) menu(dbLength, db);
    }
}

void search_city(DATABASE* db, char newCityName[], int newCityCoords[], int dbLength){
    int option = 0;
    newCityCoords[0] = 0;
    newCityCoords[1] = 0;

    system("clear");
    printf("1 - Buscar por nome\n2 - Buscar por coordenada\n");
    scanf("%d", &option);
        switch (option)
        {
            case 1:
            scanf(" %[^\n]", newCityName);
            break;

            case 2:
            printf("Latitude:\n");
            scanf("%d", &newCityCoords[0]);    //lat
            printf("Longitude:\n");
            scanf("%d", &newCityCoords[1]);    //long
            break;

            default:
            printf("Opção inválida");
            search_city(db, newCityName, newCityCoords, dbLength);
        }
    
    for (int i = 0; i < dbLength; i++){
        //compara o nome dado ou newCityCoords[s a lista de cidades e printa nome ou newCityCoords[
        if (db->city[i].name == newCityName || (db->city[i].coords[0] == newCityCoords[0] && 
        db->city[i].coords[1] == newCityCoords[1])){
            printf("A cidade %s foi encontrada na coordenada [%d, %d]\n", db->city[i].name, db->city[i].coords[0], db->city[i].coords[0]);
        }
        else
        {
            printf("Cidade nao encontrada\n");
            break;
        }
    }
}


void list_distance_cities(int dbLength, DATABASE* db){
    system("clear");
    char keyInput;
    COORDS_TYPE CityCoords[2]; 
    float distance;
    printf("-LISTAR DISTÂNCIA CIDADES-\n\n");

    printf("Informe a Latitude da cidade:\n");
    scanf("%d", &CityCoords[0]);

    printf("Informe a Longitude da cidade:\n");
    scanf("%d", &CityCoords[1]);

    for(int i = 0; i < dbLength; ++i){
        int qua1 = pow(db->city[i].coords[0] - CityCoords[0], 2);
        int qua2 = pow(db->city[i].coords[1] - CityCoords[1], 2);
        distance = sqrt(qua1 + qua2);
        printf("%s -> %.2f\n", db->city[i].name, distance);
    }

    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) menu(dbLength, db);
    }
}



void escolha(int dbLength, DATABASE* db, int answer){
    switch(answer){
        case 1: 
        //printf("Cidades");
        print_cities(dbLength, db);
        break;

        case 2: printf("implementando:buscar");
        char newCityName[20];
        int newCityCoords[2];
        search_city(db, newCityName, newCityCoords, dbLength);
        menu();
        break;

        case 3: printf("inserir"); //insert_city();
        insert_city(dbLength, db);
        // menu();
        break;

        case 4: printf("excluir"); //delete_city();
        menu();
        break;

        case 5: printf("listar distância"); //list_distance
        list_distance_cities(dbLength, db);
        break;

        default: printf("opção incorreta");
        menu();
        break;
    }
}

void menu(int dbLength, DATABASE* db){
    system("clear");
    printf("BEM-VINDO AO BANCO DE DADOS DA AMBROLÂNDIA\nUTILIZE O MENU ABAIXO PARA UTILIZAR NOSSO SISTEMA.\n");
    printf("1 - Listar as cidades do nosso território\n2 - Buscar cidades próximas\n");
    printf("3 - Inserir uma cidade nova\n4 - Excluir uma cidade\n5 - Listar distância das cidades\n\n");
    scanf("%d", &answer);
    escolha(dbLength, db, answer);
}
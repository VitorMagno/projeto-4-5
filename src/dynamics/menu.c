void menu();
void insert_city();
int answer = 0;

void toLower(NAME_TYPE str[], int strLength, int index){
    if(index >= strLength) return;
    str[index] = tolower(str[index]);
    toLower(str, strLength, ++index);
}

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

int search_city(DATABASE* db, NAME_TYPE newCityName[], COORDS_TYPE newCityCoords[], int dbLength){
    newCityCoords[0] = 0;
    newCityCoords[1] = 0;
    char option = '0';
    int cityPosition = INVALID;

    system("clear");
    printf("\n1 - Buscar por nome\n2 - Buscar por coordenada\n");
    scanf(" %c", &option);

    switch (option){
        case '1':
        printf("Insira o nome da cidade:\n");
        scanf(" %[^\n]", newCityName);
        break;

        case '2':
        printf("Latitude:\n");
        scanf("%d", &newCityCoords[0]);    //lat
        printf("Longitude:\n");
        scanf("%d", &newCityCoords[1]);    //long
        break;

        default:
        printf("Opção inválida");
        search_city(db, newCityName, newCityCoords, dbLength);
    }

    for(int j = 0; j < dbLength; j++){
        NAME_TYPE auxName[20];
        strcpy(auxName, db->city[j].name);

        toLower(auxName, strlen(auxName), 0);
        toLower(newCityName, strlen(newCityName), 0);
        
        int strVerify = strcmp(auxName, newCityName);

        if(strVerify == 0 || (db->city[j].coords[0] == newCityCoords[0] && 
        db->city[j].coords[1] == newCityCoords[1])){
            cityPosition = j;
            printf("CIDADE ENCONTRADA -> %s [%d,%d]\n", db->city[j].name, db->city[j].coords[0], db->city[j].coords[1]);
            break;
        } else if(j == dbLength - 1){
            printf("CIDADE NÃO ECONTRADA.\n");
        }
    }
    if(cityPosition != INVALID) return cityPosition;

    char keyInput;
    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) menu(dbLength, db);
    }
}

void list_distance_cities(int dbLength, DATABASE* db){
    system("clear");
    char keyInput;
    COORDS_TYPE CityCoords[2]; 
    double distance;
    printf("- LISTAR DISTÂNCIA CIDADES -\n\n");

    printf("Informe a Latitude da cidade:\n");
    scanf("%d", &CityCoords[0]);

    printf("Informe a Longitude da cidade:\n");
    scanf("%d", &CityCoords[1]);

    for(int i = 0; i < dbLength; ++i){
        int qua1 = pow(db->city[i].coords[0] - CityCoords[0], 2);
        int qua2 = pow(db->city[i].coords[1] - CityCoords[1], 2);
        distance = sqrt(qua1 + qua2);
        if(distance > 0) printf("%s -> %.2lf km\n", db->city[i].name, distance/1000);
    }

    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) menu(dbLength, db);
    }
}

void escolha(int dbLength, DATABASE* db, int answer){
    char newCityName[20];
    COORDS_TYPE newCityCoords[2];

    switch(answer){
        case 1: 
        //printf("Cidades");
        print_cities(dbLength, db);
        break;

        case 2:
        search_city(db, newCityName, newCityCoords, dbLength);
        break;

        case 3: 
        insert_city(dbLength, db);//insert_city();
        break;

        case 4: 
        delete_city(dbLength, db); //delete_city();
        break;

        case 5: //list_distance
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
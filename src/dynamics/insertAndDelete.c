void menu();
int search_city();

void insert_city(int dbLength, DATABASE* db) {
    // Input data
    system("clear");
    NAME_TYPE newCityName[20]; 
    COORDS_TYPE newCityCoords[2]; 
    printf("-INSERIR CIDADES-\n\n");
    printf("Informe o nome da cidade:\n");

    scanf(" %[^\n]", newCityName);
    
    printf("Informe a Latitude da cidade:\n");
    scanf("%d", &newCityCoords[0]);

    printf("Informe a Longitude da cidade:\n");
    scanf("%d", &newCityCoords[1]);
    
    // Insert data
    strcpy(db->city[dbLength].name, newCityName);
    db->city[dbLength].coords[0] = newCityCoords[0];
    db->city[dbLength].coords[1] = newCityCoords[1];


    // void Insere_Inicio(DATABASE *L, CITIES elem){
    // Rec *p;
    // p = malloc(sizeof(Rec));
    // p->elem = elem;
    // p->lig = L->head;
    // L->head = p;
    // L-> nelem++;
    // }


    ++dbLength;

    printf("\nDeseja adicionar uma nova cidade - [s/n]\n");

    char keyInput;
    scanf(" %c", &keyInput);
    keyInput == 's' ? insert_city(dbLength, db) : menu(dbLength, db);

    // Return status
}

void delete_city(int dbLength, DATABASE* db){
    // Input data
    system("clear");
    char option;
    COORDS_TYPE newCityCoords[2];
    char newCityName[20]; 
    int cityPosition = search_city(db, newCityName, newCityCoords, dbLength);
    printf("%d\n", cityPosition);
    
    strcpy(db->city[cityPosition].name, "**");
    db->city[cityPosition].coords[0] = INVALID;
    db->city[cityPosition].coords[1] = INVALID;

    for(int i = cityPosition; i < dbLength - 1; i++){
        if(strcmp(db->city[i].name, "**") == 0){
            strcpy(db->city[i].name, db->city[i + 1].name);
            strcpy(db->city[i + 1].name, "**");

            db->city[i].coords[0] = db->city[i + 1].coords[0];
            db->city[i].coords[1] = db->city[i + 1].coords[1];
            db->city[i + 1].coords[0] = INVALID;
            db->city[i + 1].coords[1] = INVALID;
        }
    }

    menu(dbLength - 1, db);
}
void menu();

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

    ++dbLength;

    printf("\nDeseja adicionar uma nova cidade - [s/n]\n");

    char keyInput;
    scanf(" %c", &keyInput);
    keyInput == 's' ? insert_city(dbLength, db) : menu(dbLength, db);

    // Return status

}
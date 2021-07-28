BOOL readFile(DATABASE* db){
    int count = 0;
    char end[] = {"end"};
    char data[50];
    char cityName[50];
    int cityLat;
    int cityLong;

    FILE *arquivo = fopen("./db/cities.txt", "r");
    if(arquivo == NULL) return 0;
    
    while(!feof(arquivo)){
        fscanf(arquivo, "%s %d %d", cityName, &cityLat, &cityLong);
        int isEndOfFile = strcmp(end,cityName);

        if(isEndOfFile == 0){
            break;
        }

        strcpy(db->city[count].name, cityName);
        db->city[count].coords[0] = cityLat;
        db->city[count].coords[1] = cityLong;

        printf("%s %d %d\n", db->city[count].name, db->city[count].coords[0], db->city[count].coords[1]);

        // break;
        ++count;
    }
    fclose(arquivo);

    return 1;
}
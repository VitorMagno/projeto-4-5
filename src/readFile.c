int readFile(DATABASE* db){
    int count = 0;
    char end[] = {"end"};
    char data[50];
    char cityName[50];
    int cityLat, cityLong;

    FILE *arquivo = fopen("./db/cities.txt", "r");
    if(arquivo == NULL) return -1;
    
    while(!feof(arquivo)){
        fscanf(arquivo, "%s %d %d", cityName, &cityLat, &cityLong);
        int isEndOfFile = strcmp(end,cityName);

        if(isEndOfFile == 0){
            break;
        }

        for(int i = 0; i < strlen(cityName); i++){
            if(cityName[i] == '_'){
                cityName[i] = ' ';
            }
        }

        strcpy(db->city[count].name, cityName);
        db->city[count].coords[0] = cityLat;
        db->city[count].coords[1] = cityLong;

        ++count;
    }
    fclose(arquivo);

    return count;
}
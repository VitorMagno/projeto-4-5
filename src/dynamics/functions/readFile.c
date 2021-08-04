int readFile(CITIES **head){

    CITIES *current_node, *nvono;
    int count = 0;
    char end[] = {"end"};
    char data[50];
    char cityName[50];
    int cityLat, cityLong;

    FILE *arquivo = fopen("../db/cities.txt", "r");
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
        
        if(*head == NULL){
            *head = (CITIES *) malloc(sizeof(CITIES));
            strcpy((*head)->name_city, cityName);
            (*head)->coords_city[0] = cityLat;
            (*head)->coords_city[1] = cityLong;
            (*head)->next = NULL;
        }
        else{
            current_node = *head;
                while(current_node->next != NULL)
                    current_node = current_node->next;
                nvono = (CITIES *) malloc(sizeof(CITIES));
                strcpy(nvono->name_city, cityName);
                nvono->coords_city[0] = cityLat;
                nvono->coords_city[1] = cityLong;
                nvono->next = NULL;
                current_node->next = nvono; 
            }
    }
    fclose(arquivo);


}
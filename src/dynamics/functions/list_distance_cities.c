void list_distance_cities(CITIES *head){
    CITIES *current_node = head;
    system("clear");
    int CityCoords[2];
    long double distance;
    printf("- LISTAR DISTÂNCIA CIDADES -\n\n");

    printf("Informe a Latitude da cidade:\n");
    scanf("%d", &CityCoords[0]);

    printf("Informe a Longitude da cidade:\n");
    scanf("%d", &CityCoords[1]);
    while(current_node != NULL){
        long double qua1 = pow(current_node->coords_city[0] - CityCoords[0], 2);
        long double qua2 = pow(current_node->coords_city[0] - CityCoords[1], 2);
        distance = sqrt(qua1 + qua2);
        printf("%s -> %.2Lf km\n", current_node->name_city, distance/1000);
        current_node = current_node->next;
    }
    char keyInput;
    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) menu(head); return;
    }
}
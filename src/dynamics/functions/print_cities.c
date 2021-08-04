void menu();

void print_cities(CITIES *head){
    system("clear");
    CITIES *current_node = head;
    while( current_node != NULL) {
        printf("%s [%d, %d]\n", current_node->name_city, current_node->coords_city[0], current_node->coords_city[1]);
        current_node = current_node->next;   
    }

    char keyInput;
    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) menu(head); 
        menu(head);
    }
}
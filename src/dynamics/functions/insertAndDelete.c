void menu();
int search_city();

void insert_city(CITIES **head){
    CITIES *current_node, *new_node;
    char name_city[30];
    int latitude = 0, longitude = 0;

    printf("Nome da cidade: ");
    scanf(" %[^\n]", name_city);
    printf("Latitude: ");
    scanf("%d", &latitude);
    printf("Longitude: ");
    scanf("%d", &longitude);

    if (*head == NULL){
        *head = (CITIES *) malloc(sizeof(CITIES));
        strcpy((*head)->name_city, name_city);
        (*head)->coords_city[0] = latitude;
        (*head)->coords_city[1] = longitude;
        (*head)->next = NULL;
    } else {
        current_node = *head;
        while(current_node->next != NULL) current_node = current_node->next;
        
        new_node = (CITIES *) malloc(sizeof(CITIES));
        strcpy(new_node->name_city, name_city);
        new_node->coords_city[0] = latitude;
        new_node->coords_city[1] = longitude;
        new_node->next = NULL;
        current_node->next = new_node;     
    }
    
    printf("\nDeseja adicionar uma nova cidade - [s/n]\n");

    char keyInput;
    scanf(" %c", &keyInput);
    keyInput == 's' ? insert_city(*head) : menu(head);
}

void delete(CITIES **head)
{
    CITIES *current_node = *head;
    CITIES *aux = *head; 
    char name_city[30];
    int latitude = 0, longitude = 0;
    printf("Nome da cidade: ");
    scanf(" %[^\n]", name_city);
    if (current_node == NULL)
    {
        printf("lista esta vazia\n");
        return;
    }
    else
    {   
        while (current_node != NULL){
            if (strcmp(current_node->name_city, name_city) == 0){
                if(current_node == *head){
                    *head = (*head)->next;
                    free(current_node);
                    break;
                } else {
                    aux->next = current_node->next;
                    free(current_node);
                    break;
                }
                
            } 
            else {
                aux = current_node;
                current_node = current_node->next;
            }
        }

        char keyInput;
        printf("\n\nPressione 'ENTER' para voltar");
        setbuf(stdin, NULL);
        while(keyInput != 10){
            scanf("%c", &keyInput);
            if(keyInput == 10) return;
        }
    }
}
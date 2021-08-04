void menu();
void search_city();
void toLower();

void insert_city(CITIES *head){
    CITIES *current_node, *new_node;
    char name_city[30];
    int latitude = 0, longitude = 0;

    printf("Nome da cidade: ");
    scanf(" %[^\n]", name_city);
    printf("Latitude: ");
    scanf("%d", &latitude);
    printf("Longitude: ");
    scanf("%d", &longitude);

    if (head == NULL){
        head = (CITIES *) malloc(sizeof(CITIES));
        strcpy((head)->name_city, name_city);
        (head)->coords_city[0] = latitude;
        (head)->coords_city[1] = longitude;
        (head)->next = NULL;
    } else {
        current_node = head;
        while(current_node->next != NULL) current_node = current_node->next;
        
        new_node = (CITIES *) malloc(sizeof(CITIES));
        strcpy(new_node->name_city, name_city);
        new_node->coords_city[0] = latitude;
        new_node->coords_city[1] = longitude;
        new_node->next = NULL;
        current_node->next = new_node;     
    }

    // current_node = head;
    // while(current_node->next != NULL){
    //     printf("%s\n", new_node->name_city);
    //     current_node = current_node->next;
    // }
    
    printf("\nDeseja adicionar uma nova cidade - [s/n]\n");

    char keyInput;
    scanf(" %c", &keyInput);
    keyInput == 's' ? insert_city(head) : menu(head);
}

void delete_city(CITIES *head)
{
    CITIES *current_node = head;
    CITIES *aux = head;
    char name_city[30];
    printf("1 - busque pelo nome da cidade\n2 - busque pela coordenada\n");
    int answer = 0;
    int latitude, longitude;
    scanf("%d", &answer);
    
    if (answer == 1)
    {
        printf("Insira o nome da cidade:\n");
        scanf(" %[^\n]", name_city);
        
        if (current_node == NULL) printf("lista vazia\n");
        else
        {
            while(current_node != NULL)
            {
                int strLength = strlen(name_city);
                toLower(name_city, strLength, 0);

                char auxStr[30];
                strcpy(auxStr, current_node->name_city);
                strLength = strlen(auxStr);
                toLower(auxStr, strLength, 0);
                
                if (strcmp(auxStr, name_city) == 0)
                {
                    if (current_node == head)
                    {
                        printf("voce deletou a cidade %s na latitude:%d e long: %d\n", current_node->name_city, current_node->coords_city[0], current_node->coords_city[1]);
                        head = (head)->next;
                        free(current_node);
                        break;
                    }
                    else
                    {
                        printf("voce deletou a cidade %s na latitude:%d e long: %d\n", current_node->name_city, current_node->coords_city[0], current_node->coords_city[1]);
                        aux->next = current_node->next;
                        free(current_node);
                        break;
                    }
                }
                else
                {
                    aux = current_node;
                    current_node = current_node->next;
                }
            }
        }
        
    }
    else if(answer == 2)
    {
        printf("Latitude:\n");
        scanf("%d", &latitude);    //lat
        printf("Longitude:\n");
        scanf("%d", &longitude);    //long
        

        if (aux == NULL)
        {
            printf("lista vazia\n");
        }
        else
        {
            while(current_node != NULL)
            {
                if (latitude == current_node->coords_city[0] && longitude == current_node->coords_city[1])
                {
                    if (current_node == head)
                    {
                        printf("voce deletou a cidade %s na latitude:%d e long: %d\n", current_node->name_city, current_node->coords_city[0], current_node->coords_city[1]);
                        head = (head)->next;
                        free(current_node);
                        break;
                    }
                    else
                    {
                        printf("voce deletou a cidade %s na latitude:%d e long: %d\n", current_node->name_city, current_node->coords_city[0], current_node->coords_city[1]);
                        aux->next = current_node->next;
                        free(current_node);
                        break;
                    }
                }
                else
                {
                    aux = current_node;
                    current_node = current_node->next;
                }
            }
        }
    }
    else
    {
        printf("opção inválida\n");
    }
    char keyInput;
    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) menu(head); 
        return;
    }
}

void toLower(char str[], int strLength, int index){
    if(index >= strLength) return;
    str[index] = tolower(str[index]);
    toLower(str, strLength, ++index);
}  
    /*CITIES *aux = head; 
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
                if(current_node == head){
                    head = (head)->next;
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
            if(keyInput == 10) menu(head); return;
        }
    }
}*/
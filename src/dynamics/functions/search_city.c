void toLower();

void search_city(CITIES *head)
{
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
        
        if (aux == NULL) printf("lista vazia\n");
        else
        {
            while(aux != NULL)
            {
                int strLength = strlen(name_city);
                toLower(name_city, strLength, 0);

                char auxStr[30];
                strcpy(auxStr, aux->name_city);
                strLength = strlen(auxStr);
                toLower(auxStr, strLength, 0);
                
                if (strcmp(auxStr, name_city) == 0)
                {
                    printf("voce achou a cidade %s na latitude:%d e long: %d\n", aux->name_city, aux->coords_city[0], aux->coords_city[1]);
                    break;
                }
                else
                {
                    aux = aux->next;
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
            while(aux != NULL)
            {
                if (latitude == aux->coords_city[0] && longitude == aux->coords_city[1])
                {
                    printf("voce achou a cidade %s na latitude:%d e long: %d\n", aux->name_city, aux->coords_city[0], aux->coords_city[1]);
                    break;
                }
                else
                {
                    aux = aux->next;
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
        if(keyInput == 10) menu(head); return;
    }
}

/*void toLower(char str[], int strLength, int index){
    if(index >= strLength) return;
    str[index] = tolower(str[index]);
    toLower(str, strLength, ++index);
}*/
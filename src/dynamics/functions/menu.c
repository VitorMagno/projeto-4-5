void print_cities();
void search_city();
void insert_city();
void delete_city();
void list_distance_cities();

void menu();
int answer = 0;

void escolha(CITIES *head, int answer){


    switch(answer){
        case 1: 
        print_cities(head);
        break;

        case 2:
        search_city(head);
        break;

        case 3: 
        insert_city(head);//insert_city();
        break;

        case 4: 
        delete_city(head); //delete_city();
        break;

        case 5: //list_distance
        list_distance_cities(head);
        break;

        default: printf("opção incorreta");
        menu(head);
        break;
    }
}

void menu(CITIES *head){
    system("clear");
    printf("BEM-VINDO AO BANCO DE DADOS DA AMBROLÂNDIA\nUTILIZE O MENU ABAIXO PARA UTILIZAR NOSSO SISTEMA.\n");
    printf("1 - Listar as cidades do nosso território\n2 - Buscar cidades próximas\n");
    printf("3 - Inserir uma cidade nova\n4 - Excluir uma cidade\n5 - Listar distância das cidades\n\n");
    scanf("%d", &answer);
    escolha(head, answer);
}
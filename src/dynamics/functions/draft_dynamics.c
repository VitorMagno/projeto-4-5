#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* Estrutura que será usada para criar os nós da lista */

typedef struct cidades {
    char name_city[30];                  /* Codigo do produto */
    int coords_city[2];
    struct cidades *next;    /* next elemento da lista encadeada de Produtos */
}  CITIES;

/* Prototipos das funcoes para inserir e listar produtos */

void inserir();
void list_distance_cities();
void delete();
void listar();
void menu();
void buscar();

int main()
{
    system("clear");
    CITIES *head = NULL;          /* Ponteiro para a head da lista */
    CITIES *current_node;               /* Ponteiro a ser usado para percorrer a lista no momento de desalocar seus elementos*/
    int answer;                          /* Caractere para receber a opcao do usuario */
    do {
        system("clear");
        printf("BEM-VINDO AO BANCO DE DADOS DA AMBROLÂNDIA\nUTILIZE O MENU ABAIXO PARA UTILIZAR NOSSO SISTEMA.\n");
        printf("1 - Listar as cidades do nosso território\n2 - Buscar por cidades\n");
        printf("3 - Inserir uma cidade nova\n4 - Excluir uma cidade\n");
        printf("5 - Listar distância das cidades\n\n0 - Sair\n\n");
        scanf("%d", &answer);
        switch(answer) {
            case 1: listar(head); break;
            case 2: buscar(head); break;
            case 3: inserir(&head); break;
            case 4: delete(&head); break;
            case 5: list_distance_cities(head); break;
            case 0: return 0;
            default: printf("\n\n Opcao nao valida");
        }
        fflush(stdin);    /* Limpa o buffer de entrada */
    } while ( answer != 0 );

    /* Desaloca a memoria alocada para os elementos da lista */
    current_node = head;
    while (current_node != NULL)
    {
        head = current_node->next;
        free(current_node);
        current_node = head;
    }
}

/* Lista todos os elementos presentes na lista encadeada */
void listar (CITIES *current_node)
{
    CITIES *aux = current_node;
    while( aux != NULL)    /* Enquanto nao chega no fim da lista */
    {
        printf("\n\nCidade: %s\n", aux->name_city);
        printf("Latitude: %d\nLongitude: %d", aux->coords_city[0], aux->coords_city[1]);
        aux = aux->next;     /* Faz aux apontar para o next no */
    }

    char keyInput;
    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) return;
    }
}

/* Funcao para inserir um novo no, ao final da lista */
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
        if(keyInput == 10) return;
    }
}

void inserir (CITIES **head)
{
    CITIES *current_node, *new_node;
    char name_city[30];
    int latitude = 0, longitude = 0;
    printf("Nome da cidade: ");
    scanf(" %[^\n]", name_city);
    printf("Latitude: ");
    scanf("%d", &latitude);
    printf("Longitude: ");
    scanf("%d", &longitude);
    if (*head == NULL)    /* Se ainda nao existe nenhum produto na lista */
    {
/* cria o no head */
        *head = (CITIES *) malloc(sizeof(CITIES));
        strcpy((*head)->name_city, name_city);
        (*head)->coords_city[0] = latitude;
        (*head)->coords_city[1] = longitude;
        // (*head)->name_city = name_city;
        (*head)->next = NULL;
    }
    else
    {
/* Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o novo elemento */
        current_node = *head;
        while(current_node->next != NULL)
            current_node = current_node->next;    /* Ao final do while, current_node aponta para o ultimo no */
        new_node = (CITIES *) malloc(sizeof(CITIES));/* Aloca memoria para o novo no */
        strcpy(new_node->name_city, name_city);
        // new_node->name_city = name_city;
        new_node->coords_city[0] = latitude;
        new_node->coords_city[1] = longitude;
        new_node->next = NULL;
        current_node->next = new_node;     /* Faz o ultimo no apontar para o novo no */
    }
    char keyInput;
    printf("\n\nPressione 'ENTER' para voltar");
    setbuf(stdin, NULL);
    while(keyInput != 10){
        scanf("%c", &keyInput);
        if(keyInput == 10) return;
    }
}

/*void delete(CITIES **head)
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
}*/

void buscar(CITIES *head)
{
    CITIES *aux = head;
    char name_city[30];
    printf("1 - busque pelo nome da cidade\n2 - busque pela coordenada");
    int escolha = 0;
    scanf("%d", &escolha);
    if (escolha == 1)
    {
        scanf(" %[^\n]", name_city);
    }
    else if(escolha == 2)
    {
        scanf("%")
    }
    

    if (aux == NULL)
    {
        printf("lista vazia\n");
    }
    else
    {
        while(aux != NULL)
        {
            if (strcmp(aux->name_city, name_city) == 0)
            {
                printf("voce achou a cidade %s na lat:%d e long: %d\n", aux->name_city, aux->coords_city[0], aux->coords_city[1]);
                break;
            }
            else
            {
                aux = aux->next;
            }
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
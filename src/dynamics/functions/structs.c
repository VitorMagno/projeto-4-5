#define INVALID -1
#define MAX 100

typedef struct cidades {
    char name_city[30];                
    int coords_city[2];
    struct cidades *next;    
}  CITIES;

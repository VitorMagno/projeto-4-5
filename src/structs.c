#define INVALID -1
#define MAX 100

typedef int COORDS_TYPE;
typedef char NAME_TYPE;
typedef int BOOL; 

typedef struct {
    COORDS_TYPE coords[2];
    NAME_TYPE name[20];
} CITIES;

typedef struct {
    CITIES city[MAX];
} DATABASE;
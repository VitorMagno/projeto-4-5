#define INVALID -1
#define MAX 100

typedef int COORDS_TYPE;
typedef char NAME_TYPE;
typedef int BOOL; 

typedef struct {
    COORDS_TYPE coords[2];
    NAME_TYPE name[30];
} CITIES;


struct list_rec {
  CITIES elem;
  struct list_rec *lig;
};


typedef struct list_rec Rec;
typedef struct {
  CITIES city;
  Rec *head;
  int nelem;
} DATABASE;
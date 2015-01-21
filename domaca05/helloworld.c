#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "adresy"
#define MAX 200
#define SEPARATOR ";"

struct person {
    char fname[MAX];
    char sname[MAX];
    char street[MAX];
    int street_no;
    char city[MAX];
    int birth;
    struct person *_next;
};

void freeItems(struct person *list) {
    struct person *help = list;
    while (help != NULL) {
        list = list->_next;
        free(help);
        help = list;
    }
}

void printPersons(struct person *list) {
    struct person *next = list;
    while (next != NULL) {
        printf("%s %s; %s %d; %s; %d vek %d\n",
                next->fname,
                next->sname,
                next->street,
                next->street_no,
                next->city,
                next->birth,
                2014 - next->birth
        );
        next = next->_next;
    }
}

struct person *loadFromFile(FILE * file) {
    struct person *list = NULL;
    char r[MAX];
    char *string;
    struct person *help = NULL;

    while (fgets(r, MAX, file) != NULL) {
        help = malloc(sizeof(struct person));

        if (help == NULL) {
            perror("Not allocated memory!");
            return list;
        }

        string = strtok(r, SEPARATOR);
        strcpy(help->fname, string);
        string = strtok(NULL, SEPARATOR);
        if (string != NULL) {strcpy(help->sname, string);}
        string = strtok(NULL, SEPARATOR);
        if (string != NULL) {strcpy(help->street, string);}
        string = strtok(NULL, SEPARATOR);
        if (string != NULL) {help->street_no = atoi(string);}
        string = strtok(NULL, SEPARATOR);
        if (string != NULL) {strcpy(help->city, string);}
        string = strtok(NULL, SEPARATOR);
        if (string != NULL) {help->birth = atoi(string);}

        help->_next = list;
        list = help;
    }
    return list;
}


struct person *addPerson(struct person *list) {
    char string[25];
    int no;
    struct person *help = NULL;

    help = malloc(sizeof(struct person));

    printf("fname: ");
    scanf("%s", string);
    strcpy(help->fname, string);

    printf("sname: ");
    scanf("%s", string);
    strcpy(help->sname, string);

    printf("street: ");
    scanf("%s", string);
    strcpy(help->street, string);

    printf("street_no: ");
    scanf("%d", &no);
    help->street_no = no;

    printf("city: ");
    scanf("%s", string);
    strcpy(help->city, string);

    printf("birth: ");
    scanf("%d", &no);
    help->birth = no;

    help->_next = list;
    list = help;

    printf("+++++++\n");
    printPersons(list);
    return list;
}

struct person *delPerson(struct person *list) {

     struct person *a = list;
     struct person *b = NULL;
     int index;
     int i;

     printf("- DELETE ----------------------------\n");
     printf("index: ");
     scanf("%d", &index);
     if (index == 1) {
         list = a->_next;
         free(a);
     } else {
         for (i = 1; i < index - 1; i++)
             a = a->_next;
         b = a->_next;
         a->_next = b->_next;
         free(b);
     }
     printf("- DELETED !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
     printPersons(list);
    return list;
}

void age(struct person *list) {
    struct person *help = list;
    int index;
    int i = 1;
    printf("- Age ----------------------------\n");
    printf("index: ");
    scanf("%d", &index);

    while (i != index && help != NULL) {
        list = list->_next;
        help = list;
        i++;
    }
    printf("Birth %d age %d\n", help->birth, 2014 - help->birth);
}

void city(struct person *list, char city[]) {
    struct person *help = list;
    int c = 0;
    printf("- LOADED ---------------------\n");
    printf("city = '%s': \n", city);
    while (help != NULL) {
        if (strcmp(city, help->city) == 0) {
            printf("%s %s, %s %d, %s, %d\n",
                    help->fname,
                    help->sname,
                    help->street,
                    help->street_no,
                    help->city,
                    help->birth);
            c++;
        }
        help = help->_next;
    }
    if (c == 0) {
        printf("nothing found \n");
    }
}


int main(void) {
    FILE *file;
    int switchRun;
    int endRequested = 0;
    struct person *list = NULL;
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Cant read file");
        return 1;
    }

    list = loadFromFile(file);

    printf("- LOADED ---------------------\n");
    printPersons(list);

    while (endRequested == 0) {
        printf("- MENU ---------------------\n");
        printf("[1] - addPerson\n");
        printf("[2] - deletePerson\n");
        printf("[3] - age\n");
        printf("[4] - city == 'Presov'\n");
        printf("other - close\n");
        scanf("%d", &switchRun);
        switch (switchRun) {
            case 1 :
                list = addPerson(list);
                break;
            case 2 :
                list = delPerson(list);
                break;
            case 3 :
                age(list);
                break;
            case 4 :
                city(list, "Presov");
                break;
            default:
                endRequested = 1;
        }
    }
    freeItems(list);
    return 0;
}


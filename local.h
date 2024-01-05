#ifndef LOCAL_H
#define LOCAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <ctype.h>
#include <errno.h>
#include <stdint.h> 
#include <wait.h>
#include <signal.h>

#define MAX_PRODUCTS 100
#define MAX_LINE_LENGTH 255
#define MAX_TEAMS 100
#define SHKEY_PRODUCT 2222 // key for shared memory for all products


char* trim(char *str);
int randomInRange(int min_range, int max_range);
void readArgumentsFile(char *arguments_filename);
void readProductsFile(char *items_filename, int numProducts);
void readTeamsFile(char *teams_filename, int numShelvingTeams);
void createSharedMemory(int key, char *shmptr); 


struct String {
    char str[MAX_LINE_LENGTH];
};


struct Product {
    int ID;
    struct String Name;
    int onShelvesAmount;
    int StorageAmount;
};

typedef struct Product Product;

struct AllProducts {
    Product products[MAX_PRODUCTS];
    int numProducts;
};


struct Team {
    int team_id;
    int num_employees;
};

#endif

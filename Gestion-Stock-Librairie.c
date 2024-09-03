#include <stdio.h>
#include <string.h>



char titles[100][50];
char authors[100][50];
float prices[100];
int quantities[100];
int bookCount = 0; 

void addBook() {
    if (bookCount >= 100) {
        printf("Stock plein, impossible d'ajouter un livre.\n");
        return;
    }
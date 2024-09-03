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
    
    printf("Entrez le titre du livre : ");
    fgets(titles[bookCount], 50, stdin);
    titles[bookCount][strcspn(titles[bookCount], "\n")] = 0; // Supprimer le saut de ligne

    printf("Entrez l'auteur du livre : ");
    fgets(authors[bookCount], 50, stdin);
    authors[bookCount][strcspn(authors[bookCount], "\n")] = 0; // Supprimer le saut de ligne

    printf("Entrez le prix du livre : ");
    scanf("%f", &prices[bookCount]);
    
    printf("Entrez la quantité en stock : ");
    scanf("%d", &quantities[bookCount]);
    
    // Vider le tampon de l'entrée
    getchar();

    bookCount++;
}
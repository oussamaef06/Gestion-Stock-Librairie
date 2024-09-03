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
    titles[bookCount][strcspn(titles[bookCount], "\n")] = 0;

    printf("Entrez l'auteur du livre : ");
    fgets(authors[bookCount], 50, stdin);
    authors[bookCount][strcspn(authors[bookCount], "\n")] = 0;

    printf("Entrez le prix du livre : ");
    scanf("%f", &prices[bookCount]);
    
    printf("Entrez la quantité en stock : ");
    scanf("%d", &quantities[bookCount]);
    

    getchar();

    bookCount++;
}


void displayBooks() {
    if (bookCount == 0) {
        printf("Aucun livre en stock.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        printf("Titre : %s\n", titles[i]);
        printf("Auteur : %s\n", authors[i]);
        printf("Prix : %.2f\n", prices[i]);
        printf("Quantité : %d\n\n", quantities[i]);
    }
}


void searchBook() {
    char title[50];
    printf("Entrez le titre du livre à rechercher : ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("Livre trouvé !\n");
            printf("Titre : %s\n", titles[i]);
            printf("Auteur : %s\n", authors[i]);
            printf("Prix : %.2f\n", prices[i]);
            printf("Quantité : %d\n\n", quantities[i]);
            return;
        }
    }
    printf("Livre non trouvé.\n");
}


void updateQuantity() {
    char title[50];
    printf("Entrez le titre du livre dont vous souhaitez modifier la quantité : ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0; // Supprimer le saut de ligne

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("Entrez la nouvelle quantité : ");
            scanf("%d", &quantities[i]);
            // Vider le tampon de l'entrée
            getchar();
            printf("Quantité mise à jour.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}
#include "keepAlive.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJ_COUNT 1024 // Nombre maximal d'objets à stocker sur 16bits

// Fonction pour afficher les objets stockés dans la FIFO
void printFifo(struct obj* fifo, int count) {
    printf("Objets stockés dans la FIFO :\n");
    for (int i = 0; i < count; i++) {
        printf("Objet %d:\n", i + 1);
        printf("  Nom : %s\n", fifo[i].name);
        printf("  Chemin : %s\n", fifo[i].path);
        printf("  ID : %d\n", fifo[i].id);
        printf("  USB : %s\n", fifo[i].usb);
        printf("\n");
    }
}

int main() {
    struct obj fifo[MAX_OBJ_COUNT];
    int fifoCount = 0;

    FILE* fichier;
    char ligne[512];
    char tempName[64];
    char tempPath[256];

    // Ouvrir le fichier en mode lecture
    fichier = fopen("map.yaml", "r");

    // Vérifier si le fichier est ouvert avec succès
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    // Parcourir le fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Retirer le caractère de saut de ligne (\n)
        ligne[strcspn(ligne, "\n")] = '\0';

        // Vérifier si la ligne contient un nom d'objet
        if (strstr(ligne, "objname") != NULL) {
            // Extraire le nom de l'objet de la ligne
            char* nomObjet = strchr(ligne, ':');
            if (nomObjet != NULL) {
                strcpy(tempName, nomObjet + 1);
            }
        }
        // Vérifier si la ligne contient un chemin d'objet
        else if (strstr(ligne, "objpath") != NULL) {
            // Extraire le chemin de l'objet de la ligne
            char* cheminObjet = strchr(ligne, ':');
            if (cheminObjet != NULL) {
                strcpy(tempPath, cheminObjet + 1);
            }
        }
        // Vérifier si la ligne contient un ID d'objet
        else if (strstr(ligne, "id") != NULL) {
            // Extraire l'ID de l'objet de la ligne
            char* idObjet = strchr(ligne, ':');
            if (idObjet != NULL) {
                fifo[fifoCount].id = atoi(idObjet + 1);
            }
        }
        // Vérifier si la ligne contient un nom de port USB
        else if (strstr(ligne, "usb") != NULL) {
            // Extraire le nom du port USB de la ligne
            char* usbObjet = strchr(ligne, ':');
            if (usbObjet != NULL) {
                strcpy(fifo[fifoCount].name, tempName);
                strcpy(fifo[fifoCount].path, tempPath);
                strcpy(fifo[fifoCount].usb, usbObjet + 1);
                fifoCount++; // Passer à l'objet suivant dans la FIFO
            }
        }
    }

    // Fermer le fichier
    fclose(fichier);

    // Afficher les objets stockés dans la FIFO
    printFifo(fifo, fifoCount);

    return 0;
}


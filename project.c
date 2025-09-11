
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int idAvion = 1;   

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;
typedef struct {
    int id;
    char modele[30];
    int capacite;
    char statut[20];   // Disponible, En_vol, Maintenance
    Date dateEntree;
} Avion;

typedef struct {
    char nom[50];
    Avion flotte[50];  // tableau de 50 avions max
    int nbAvions;
} Aeroport;


Avion ajouterAvion() {
    Avion a;
    a.id = idAvion++;
    

    printf("Modele : ");
    scanf("%s", a.modele);

    printf("Capacite : ");
    scanf("%d", &a.capacite);

    printf("Statut (Disponible/En_vol/Maintenance) : ");
    scanf("%s", a.statut);

    printf("Date entree (jour mois annee) : ");
    scanf("%d %d %d", &a.dateEntree.jour, &a.dateEntree.mois, &a.dateEntree.annee);
   
    return a;
}

// Ajouter un avion a l aeroport
Aeroport ajouterAvionAeroport(Aeroport a) {
    if (a.nbAvions < 50) {
        a.flotte[a.nbAvions] = ajouterAvion();
        a.nbAvions++;
        printf("Avion ajoute avec succes !\n");
    } else {
        printf("Flotte pleine, impossible d'ajouter plus d'avions.\n");
    }
    return a;
}
void Satistiques(Aeroport a){ /*afiche  Nombre total d’avions-Nombre d’avions par statut (“Disponible”, “En maintenance”, “En vol”).-Capacité totale de la flotte.=L'avion ayant la plus grande capacité et celui ayant la plus petite capacité*/
    a.nbAvions++;
    printf("%d",a.nbAvions); /*afiche  Nombre total d’avion*/
    



}
// Afficher la liste des avions
void afficherAeroport(Aeroport a) {
    printf("\n=== Aeroport : %s ===\n", a.nom);
    if (a.nbAvions == 0) {
        printf("Aucun avion enregistre.\n");
        return ;
    }

    for (int i = 0; i < a.nbAvions; i++) {
        Avion av = a.flotte[i];
        printf("ID: %d | Modele: %s | Capacite: %d | Statut: %s | Date: %d/%d/%d\n",
               av.id, av.modele, av.capacite, av.statut,
               av.dateEntree.jour, av.dateEntree.mois, av.dateEntree.annee);
    }
}


int rechercherAvion(int id, Aeroport a) {
    for (int i = 0; i < a.nbAvions; i++) {
        if (a.flotte[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Modifier l avion
void modifierAvion(Aeroport a, int id) {
    int idx = rechercherAvion(id, a);
    if (idx == -1) {
        printf("Avion introuvable.\n");
        return;
    }

    int choix;
    printf("1- Modifier le modele\n");
    printf("2- Modifier la capacite\n");
    printf("3- Modifier le statut\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Nouveau modele : ");
            scanf("%s", a.flotte[idx].modele);
            break;
        case 2:
            printf("Nouvelle capacite : ");
            scanf("%d", &a.flotte[idx].capacite);
            break;
        case 3:
            printf("Nouveau statut : ");
            scanf("%s", a.flotte[idx].statut);
            break;
        default:
            printf("Choix invalide.\n");
    }
    printf("Modification reusssitte\n");
}

void supprimerAvion(Aeroport a, int id) {
    int idx = rechercherAvion(id, a);
    if (idx == -1) {
        printf("Avion introuvable.\n");
        return;
    }

    for (int i = idx; i < a.nbAvions - 1; i++) {
        a.flotte[i] = a.flotte[i + 1];
    }
    a.nbAvions--;
    printf("Avion supprime avec succes !\n");
}
void triParCapacite(Aeroport a) { // par bulles
    for (int i = 0; i < a.nbAvions - 1; i++)
        for (int j = 0; j < a.nbAvions - i - 1; j++)
            if (a.flotte[j].capacite > a.flotte[j+1].capacite) {
                Avion tmp = a.flotte[j];
                 a.flotte[j] = a.flotte[j+1]; 
                a.flotte[j+1] = tmp;
            }
    printf(" croissant).\n");
    afficherAeroport(a);
}

int main() {
    Aeroport aeroport;
    aeroport.nbAvions = 0;

    printf("Nom de l'aeroport : ");
    scanf("%s", aeroport.nom);

    int choix, id;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Ajouter un avion\n");
        printf("2. Afficher tous les avions\n");
        printf("3. Modifier un avion\n");
        printf("4. Supprimer un avion\n");
        printf("5. Rechercher un avion\n");
        printf("6. Trier les avions (par capacite)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterAvionAeroport(aeroport);
                aeroport.nbAvions++;
                break;
            case 2:
                afficherAeroport(aeroport);
                break;
            case 3:
                printf("Entrer ID avion a modifier : ");
                scanf("%d", &id);
                modifierAvion(aeroport, id);
                break;
            case 4:
                printf("Entrer ID avion a supprimer : ");
                scanf("%d", &id);
                supprimerAvion(aeroport, id);
                break;
            case 5:
                printf("Entrer ID avion a rechercher : ");
                scanf("%d", &id);
                int idrech = rechercherAvion(id, aeroport);
                if (idrech != -1)
                    printf("Avion trouve: %s\n", aeroport.flotte[idrech].modele);
                else
                    printf("Avion introuvable\n");
             
                      break;
            case 6:
                triParCapacite(aeroport);
                break;
            case 7 :
            printf("6. Statistiques");
            
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}

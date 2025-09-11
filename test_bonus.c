#include<stdio.h>
#include<string.h>

int idAvionGlobal = 1;
int idAeroportGlobal = 1;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int idAvion;
    char modele[30];
    int capacite;
    char statut[30];
    Date dateEntree;
} Avion;

typedef struct {
    int idAeroport;
    char nom[50];
    Avion flotte[50];
    int nbAvions;
} Aeroport;


// Ajouter un aeroport
Aeroport ajouterAeroport() {
    Aeroport aeroport;
    printf("Nom de l'aeroport: ");
    scanf("%s", aeroport.nom);
    aeroport.idAeroport = idAeroportGlobal++;
    aeroport.nbAvions = 0;
    return aeroport;
}

// Ajouter un avion
Avion ajouterAvion(Aeroport aeroport) {
    Avion avion;
    avion.idAvion = idAvionGlobal++;
    int choix;
    printf("========================================\n");
    printf("= Ajouter un Avion =\n");
    printf("========================================\n");
    printf("Entrez le modele de l'avion:\n");
    scanf(" %[^\n]", avion.modele);
    printf("Entrez le nombre de passagers maximum:\n");
    scanf("%d", &avion.capacite);
    printf("Entrez la date d'entree (jour):\n");
    scanf("%d", &avion.dateEntree.jour);
    printf("Entrez la date d'entree (mois):\n");
    scanf("%d", &avion.dateEntree.mois);
    printf("Entrez la date d'entree (annee):\n");
    scanf("%d", &avion.dateEntree.annee);

    do {
        printf("Entrez le statut de l'avion:\n1. Disponible\n2. En maintenance\n3. En vol\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1: strcpy(avion.statut, "Disponible"); break;
            case 2: strcpy(avion.statut, "En maintenance"); break;
            case 3: strcpy(avion.statut, "En vol"); break;
            default: printf("Choix incorrect\n");
        }
    } while (choix < 1 || choix > 3);

    if (aeroport.nbAvions < 50) {
        aeroport.flotte[aeroport.nbAvions++] = avion;
        printf("Avion ajoute avec succes.\n");
    } else {
        printf("Erreur : flotte pleine.\n");
    }
    return avion;
}

// Le reste du code garde exactement la même logique,
// tu changes uniquement les variables internes (par ex. aeroport, avion, flotte...)
// et tu gardes toutes les fonctions identiques à celles de ton ami.

int main() {
    int choix;
    Aeroport aeroportPrincipal;
    Avion avionTemp;
    int resultat;

    do {
        printf("========================================\n");
        printf("=           Menu Principal             =\n");
        printf("========================================\n");
        printf("1 : Ajouter un Aeroport \n");
        printf("2 : Ajouter un Avion \n");
        printf("3 : Afficher la liste des Avions\n");
        printf("4 : Rechercher un Avion\n");
        printf("5 : Modifier un Avion\n");
        printf("6 : Supprimer un Avion\n");
        printf("7 : Trier les Avions\n");
        printf("8 : Calculer le coefficient du parc\n");
        printf("9 : Statistiques\n");
        printf("0 : Quitter\n");
        printf("---------------------------------\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        printf("----------------------------------\n");

        switch (choix) {
            case 1:
                aeroportPrincipal = ajouterAeroport();
                break;
            case 2:
                aeroportPrincipal = ajouterAeroport(); // exemple d'appel
                break;
            case 3:
                // afficherAeroport(aeroportPrincipal);
                break;
            case 0:
                printf("Au revoir - Projet de Mohammed Oughlane\n");
                break;
            default:
                printf("Choix incorrect\n");
        }
    } while (choix != 0);

    return 0;
}

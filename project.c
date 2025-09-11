#include <stdio.h>
#include <string.h>


int idAeroport = 1;
int idAvion = 1;
int nbrAvion = 0;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int id;
    char modele[20];
    int capacite;
    char statut[20]; 
    Date dateEntree;
} Avion;

typedef struct {
    int id;
    char nom[50];
    Avion flotte[40];
} Aeroport;

void errMessage(char message[]) {
    printf("%s", message);
} 
void afficherAeroport(Aeroport a) {
    printf("Id Aeroport : %d | Nom : %s \n", a.id, a.nom);
    printf("------------- Flotte d'avions ---------------\n");
    for (int i = 0; i < nbrAvion; i++) {
        printf("Avion %d : ======================> \n", i+1);
        printf("Id : %d | Modele : %s | Capacite : %d | Statut : %s | Date entree : %d/%d/%d \n",
               a.flotte[i].id, a.flotte[i].modele, a.flotte[i].capacite, a.flotte[i].statut,
               a.flotte[i].dateEntree.jour, a.flotte[i].dateEntree.mois, a.flotte[i].dateEntree.annee);
    }
}

Avion ajouterAvion(Aeroport a) {
    Avion av;
    av.id = idAvion++;
    printf("Modele : ");
    scanf("%s", av.modele);
    printf("Capacite : ");
    scanf("%d", &av.capacite);
    printf("Statut (Disponible / En_vol / Maintenance) : ");
    scanf("%s", av.statut);
    printf("Date entree (jour mois annee) : ");
    scanf("%d %d %d", &av.dateEntree.jour, &av.dateEntree.mois, &av.dateEntree.annee);

    return av;
}

Aeroport ajouterAvionAeroport(Aeroport a) {
    afficherAeroport(a);
    a.flotte[nbrAvion] = ajouterAvion(a);
    nbrAvion++;
    return a;
}


Avion RechercheById(int id, Aeroport a) {
    int index = -1;
    for (int i = 0; i < nbrAvion; i++) {
        if (a.flotte[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Avion trouv \n");
        return a.flotte[index];
    } else {
        printf("Avion introuvable\n");
        Avion vide;
        vide.id = -1;
        return vide;
    }
}

// ------------------ SUPPRESSION ------------------
Aeroport supprimerAvion(int id, Aeroport a) {
    int index = -1;
    for (int i = 0; i < nbrAvion; i++) {
        if (a.flotte[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < nbrAvion - 1; i++) {
            a.flotte[i] = a.flotte[i + 1];
        }
        Avion avVide;
        a.flotte[nbrAvion - 1] = avVide;
        nbrAvion--;
        printf("Avion supprimé avec succès ✈️\n");
    } else {
        printf("Suppression impossible : avion introuvable ❌\n");
    }
    return a;
}

// ------------------ MAIN ------------------
int main() {
    int choix = 0;
    Aeroport aeroport;

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Ajouter Aeroport\n");
        printf("2 - Ajouter Avion\n");
        printf("3 - Afficher Aeroport\n");
        printf("4 - Rechercher un Avion par ID\n");
        printf("5 - Supprimer un Avion\n");
        printf("100 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                aeroport.id = idAeroport++;
                printf("Nom de l'aeroport : ");
                scanf("%s", aeroport.nom);
                break;
            case 2:
                aeroport = ajouterAvionAeroport(aeroport);
                break;
            case 3:
                afficherAeroport(aeroport);
                break;
            case 4: 
                afficherAeroport(aeroport);
                break;
        }

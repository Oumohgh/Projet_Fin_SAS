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

 Aeroport ajouterAvionAeroport(Aeroport a) {
    afficherAeroport(a);
    a.flotte[nbrAvion] = ajouterAvion(a);
    nbrAvion++;
    return a;
}

Avion modifyAvion (Avion x){ /*fonction pour modifier les elemetn d un avion avec le choix*/
    Aeroport m;
    Avion x;
    
    printf("Modifier \n");
    int  i, choix;
    for (i = 0; i < nbrAvion; i++) {
            printf("1 : modifier le modele\n");
            printf("2 : modifier le capacite\n");
            printf("3 : modifier le statut\n");
          
            printf("Entrer votre choix de modification: ");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    printf("entrer le nouveau modele : ");
                    scanf(" %[^\n]", x.modele[i] );
                     x.id = idAvion++;
                    break;
                case 2:
                    printf("entrer le nouveau capacite : ");
                    scanf(" %d", x.capacite );
                    break;
               
                    
                case 3:
                printf("Statut (Disponible / En_vol / Maintenance) : ");
                scanf("%s", x.statut);
                default:
                printf("choix de modification invalid");
                break;
            }
            return;
        }

 

  
}



void afficherAeroport(Aeroport a) {
    printf("Id Aeroport : %d | Nom : %s \n", a.id, a.nom);
    printf("------------- Flotte d'avions ---------------\n");
    for (int i = 0; i < nbrAvion; i++) {
        printf("Avion %d : ======================> \n", i+1);
        printf("Id : %d - Modele : %s - Capacite : %d - Statut : %s - Date entree : %d/%d/%d \n",
               a.flotte[i].id, a.flotte[i].modele, a.flotte[i].capacite, a.flotte[i].statut,
               a.flotte[i].dateEntree.jour, a.flotte[i].dateEntree.mois, a.flotte[i].dateEntree.annee);
    }
}

Avion ajouterAvion(Aeroport a) {
    Avion avv;
    avv.id = idAvion++;
    printf("Modele : ");
    scanf("%s", avv.modele);
    printf("Capacite : ");
    scanf("%d", &avv.capacite);
    printf("Statut (Disponible / En_vol / Maintenance) : ");
    scanf("%s", avv.statut);
    printf("Date entree (jour mois annee) : ");
    scanf("%d %d %d", &avv.dateEntree.jour, &avv.dateEntree.mois, &avv.dateEntree.annee);

    return avv;
}




Avion RechercheId(int id, Aeroport a) {
    int index = -1;
    for (int i = 0; i < nbrAvion; i++) {
        if (a.flotte[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Avion trouv :\n");
        return a.flotte[index];
    } else {
        printf("Avion introuvable\n");
        Avion vide;
        vide.id = -1;
        return vide;
    }
}


Aeroport supprimerAvion(int id, Aeroport s) {
    int index = -1;             /*desa index l -1  bach */
    for (int i = 0; i < nbrAvion; i++) {
        if (s.flotte[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < nbrAvion - 1; i++) {
            s.flotte[i] = s.flotte[i + 1];
        }
        Avion avVide;
        s.flotte[nbrAvion - 1] = avVide;
        nbrAvion--;
        printf("Avion supprime avec succes\n");
    } else {
        printf("Suppression impossible : avion introuvable \n");
    }
    return s;
}

/*testti */
int main() {
    int choix = 0;
    Aeroport aeroport;

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Ajouter Aeroport\n");
        printf("2 - Ajouter Avion\n");
        printf("3 - Afficher Aeroport\n");
        printf("4 - Modifier un avion (modele, capacite, statut).");
        printf("5 - Rechercher un Avion par ID\n");
        printf("6 - Supprimer un Avion\n");
        printf("10 - Quitter\n");
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
                 Avion av;
                av.id =-1;
                printf("id : " ) ;
                scanf("%d", &av.id);
                av = RechercheId(av.id, aeroport);
                if (av.id != -1) {
                    av = modifyAvion(av);
                } else {
                    printf("Aucun avion trouve");
                }
                break;
            case 5:
                afficherAeroport(aeroport);
                 Avion av;
                av.id =-1;
                printf("id : " ) ;
                scanf("%d", &av.id);
                av = RechercheId(av.id, aeroport);
                if (av.id != -1) {
                    aeroport = supprimerAvion(av.id, aeroport);
                } else {
                    printf("Aucun avion trouve");
                }
                break;
                default:    
                break;
        }
                return 0;
        }
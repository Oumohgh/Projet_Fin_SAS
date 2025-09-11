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


Aeroport ajouterAeroport() {
    Aeroport aeroport;
    printf("Nom de l'aeroport: ");
    scanf("%s", aeroport.nom);
    aeroport.idAeroport = idAeroportGlobal++;
    aeroport.nbAvions = 0;
    return aeroport;
}


Avion ajouterAvion(Aeroport aeroport){
    Avion avion;
    avion.idAvion = idAvionGlobal++;
    int choix;
    printf("= Ajouter un Avion =\n");
    printf("========================================\n");
    printf("Entrez le modele de Avion:\n");
    scanf(" %[^\n]", avion.modele);
    printf("Entrez le nombre de passagers maximum :\n");
    scanf("%d", &avion.capacite);
    printf("Entrez la date d'entree par jour:\n");
    scanf("%d", &avion.dateEntree.jour);
    printf("Entrez la date d'entree par mois:\n");
    scanf("%d", &avion.dateEntree.mois);
    printf("Entrez la date d'entree par annee:\n");
    scanf("%d", &avion.dateEntree.annee);

    do { 
        printf("Entrez le statut de l avion:\n1. Disponible\n2. En maintenance\n3. En vol\n");
        scanf("%d", &choix);
        switch(choix) {
            case 1: strcpy(avion.statut, "Disponible"); break;
            case 2: strcpy(avion.statut, "En maintenance"); break;
            case 3: strcpy(avion.statut, "En vol"); break;
            default: printf("Choix incorrect\n");
        }
    } while(choix < 1 || choix > 3);

    if (aeroport.nbAvions < 50) {
        aeroport.flotte[aeroport.nbAvions++] = avion;
        printf("Avion ajoute avec succès \n");
    } else {
        printf("Erreur : flotte pleine \n");
    }

    return avion;
}


Avion ajouterPlusieursAvions(Aeroport aeroport) {
    Avion avion;
    printf("===========================================\n");
    printf("= Ajouter plusieurs avions =\n");
    printf("===========================================\n");
    int nbr;
    printf("Entrer le nombre d avions : ");
    scanf("%d", &nbr);
    for (int i = 0; i < nbr; i++) {
        avion = ajouterAvion(aeroport);
    }
    return avion;
}


Avion menuAjouterAvion(Aeroport aeroport) {
    int choix;
    Avion avion;
    printf("========================================\n");
    printf("= Ajouter un Avion =\n");
    printf("========================================\n");
    do {
        printf("1. Ajouter un avion\n");
        printf("2. Ajouter plusieurs avions\n");
        printf("3. Quitter\n");
        printf("---------------------------------\n");
        printf("Entrer le choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: avion = ajouterAvion(aeroport); break;
            case 2: avion = ajouterPlusieursAvions(aeroport); break;
            case 3: break;
            default: printf("Choix incorrect\n");
        }
    } while (choix != 3);
    return avion;
}


void afficherAeroport(Aeroport aeroport) {
    printf("ID : %d | Nom : %s \n", aeroport.idAeroport, aeroport.nom );
    printf("------------- Flotte Avions ---------------\n");
    for (int i = 0; i < aeroport.nbAvions; i++) {
        printf("Avion %d : ======================\n", i+1);
        printf("%d modele : %s | capacite: %d | statut: %s | date dEntree : %d / %d / %d \n",
            aeroport.flotte[i].idAvion,
            aeroport.flotte[i].modele, 
            aeroport.flotte[i].capacite, 
            aeroport.flotte[i].statut, 
            aeroport.flotte[i].dateEntree.jour,
            aeroport.flotte[i].dateEntree.mois,
            aeroport.flotte[i].dateEntree.annee);
    }
}


Aeroport ajouterAvionAeroport(Aeroport aeroport) {
    afficherAeroport(aeroport);
    aeroport.flotte[aeroport.nbAvions] = menuAjouterAvion(aeroport);
    aeroport.nbAvions++;
    return aeroport;
}

void rechercherAvion(Aeroport aeroport) {
    printf("========================================\n");
    printf("= Recherche Avion =\n");
    printf("========================================\n");
    int choix, id, trouve = 0;
    char modele[30];

    printf("1 : Recherche par ID\n2 : Recherche par modele\nEntrer le choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Entrer ID : ");
        scanf("%d", &id);
        for (int i = 0; i < aeroport.nbAvions; i++) {
            if (aeroport.flotte[i].idAvion == id) {
                Avion avion = aeroport.flotte[i];
                printf("-------------------------------------\n");
                printf("ID : %d\nModele : %s\nCapacite: %d\nDate dEntree : %d/%d/%d\nStatut: %s\n",
                    avion.idAvion, avion.modele, avion.capacite,
                    avion.dateEntree.jour, avion.dateEntree.mois, avion.dateEntree.annee,
                    avion.statut);
                trouve = 1;
                break;
            }
        }
        if (!trouve) printf("Aucun avion trouv avec ID '%d'.\n", id);
    } else if (choix == 2) {
        printf("Entrer modele : ");
        scanf(" %[^\n]", modele);
        for (int i = 0; i < aeroport.nbAvions; i++) {
            if (strcmp(aeroport.flotte[i].modele, modele) == 0) {
                Avion avion = aeroport.flotte[i];
                printf("-------------------------------------\n");
                printf("ID : %d\nModele : %s\nCapacite: %d\nDate dEntree : %d/%d/%d\nStatut: %s\n",
                    avion.idAvion, avion.modele, avion.capacite,
                    avion.dateEntree.jour, avion.dateEntree.mois, avion.dateEntree.annee,
                    avion.statut);
                trouve = 1;
            }
        }
        if (!trouve) printf("Aucun avion trouv avec le modele '%s'.\n", modele);
    } else {
        printf("Choix incorrect\n");
    }
}


Aeroport modifierAvion(Aeroport aeroport) {
    printf("========================================\n");
    printf("= Modifier Avion =\n");
    printf("========================================\n");
    int id, choix;
    printf("Entrer lID de lavion a modifier : ");
    scanf("%d", &id);
    for (int i = 0; i < aeroport.nbAvions; i++) {
        if (aeroport.flotte[i].idAvion == id) {
            printf("1 : Modifier modele\n2 : Modifier capacite\n3 : Modifier statut\n4 : Quitter\nEntrer le choix : ");
            scanf("%d", &choix);
            switch (choix) {
                case 1: printf("Entrer nouveau modele : "); scanf(" %[^\n]", aeroport.flotte[i].modele); break;
                case 2: printf("Entrer nouvelle capacite : "); scanf("%d", &aeroport.flotte[i].capacite); break;
                case 3: 
                    do {
                        printf("1 : Disponible\n2 : En maintenance\n3 : En vol\nEntrer le choix : ");
                        scanf("%d", &choix);
                        switch (choix) {
                            case 1: strcpy(aeroport.flotte[i].statut, "Disponible"); break;
                            case 2: strcpy(aeroport.flotte[i].statut, "En maintenance"); break;
                            case 3: strcpy(aeroport.flotte[i].statut, "En vol"); break;
                            default: printf("Choix incorrect\n");
                        }
                    } while (choix < 1 || choix > 3);
                    break;
                case 4: break;
                default: printf("Choix incorrect\n");
            }
            return aeroport;
        }
    }
    printf("ID non trouv\n");
    return aeroport;
}


Aeroport supprimerAvion(Aeroport aeroport) {
    printf("========================================\n");
    printf("= Supprimer Avion =\n");
    printf("========================================\n");
    int id;
    printf("Entrer l'ID de l avion a supprimer : ");
    scanf("%d", &id);

    if (aeroport.nbAvions == 0) {
        printf("Le tableau davions est vide.\n");
        return aeroport;
    }

    for (int i = 0; i < aeroport.nbAvions; i++) {
        if (aeroport.flotte[i].idAvion == id) {
            for (int j = i; j < aeroport.nbAvions - 1; j++) {
                aeroport.flotte[j] = aeroport.flotte[j+1];
            }
            aeroport.nbAvions--;
            printf("Avion supprime.\n");
            return aeroport;
        }
    }
    printf("ID non trouve\n");
    return aeroport;
}


void afficherTrie(Aeroport aeroport) {
    int choix;
    Avion temp;
    printf("1 : Trier par ordre alphabetique (modele)\n2 : Trier par capacite\nEntrer le choix : ");
    scanf("%d", &choix);
    if (choix == 1) {
        for (int i = 0; i < aeroport.nbAvions - 1; i++) {
            for (int j = i+1; j < aeroport.nbAvions; j++) {
                if (strcmp(aeroport.flotte[i].modele, aeroport.flotte[j].modele) > 0) {
                    temp = aeroport.flotte[i];
                    aeroport.flotte[i] = aeroport.flotte[j];
                    aeroport.flotte[j] = temp;
                }
            }
        }
        afficherAeroport(aeroport);
    } else if (choix == 2) {
        for (int i = 0; i < aeroport.nbAvions - 1; i++) {
            for (int j = i+1; j < aeroport.nbAvions; j++) {
                if (aeroport.flotte[i].capacite < aeroport.flotte[j].capacite) {
                    temp = aeroport.flotte[i];
                    aeroport.flotte[i] = aeroport.flotte[j];
                    aeroport.flotte[j] = temp;
                }
            }
        }
        afficherAeroport(aeroport);
    } else {
        printf("Choix incorrect\n");
    }
}


int calculCoefficientParc(Aeroport aeroport) {
    int tmp = 0;
    for(int i=0; i<aeroport.nbAvions; i++){
        if(strcmp(aeroport.flotte[i].statut,"Disponible")==0){
            tmp++;
        }
    }
    return tmp * 100 / aeroport.nbAvions;
}


int nombreTotalAvions(Aeroport aeroport){
    return aeroport.nbAvions;
}


void nombreAvionsStatut(Aeroport aeroport){
    int dispo=0, maint=0, vol=0;
    for(int i=0;i<aeroport.nbAvions;i++){
        if(strcmp(aeroport.flotte[i].statut,"Disponible")==0) dispo++;
        else if(strcmp(aeroport.flotte[i].statut,"En maintenance")==0) maint++;
        else if(strcmp(aeroport.flotte[i].statut,"En vol")==0) vol++;
    }
    printf("Nombre d avions dans %s:\nDisponible: %d\nMaintenance: %d\nEn vol: %d\n", aeroport.nom, dispo, maint, vol);
}


int capaciteTotale(Aeroport aeroport){
    int somme=0;
    for(int i=0;i<aeroport.nbAvions;i++){
        somme += aeroport.flotte[i].capacite;
    }
    return somme;
}


Avion plusGrandeCapacite(Aeroport aeroport){
    Avion max = aeroport.flotte[0];
    for(int i=0;i<aeroport.nbAvions;i++){
        if(aeroport.flotte[i].capacite > max.capacite) max = aeroport.flotte[i];
    }
    return max;
}


Avion plusPetiteCapacite(Aeroport aeroport){
    Avion min = aeroport.flotte[0];
    for(int i=0;i<aeroport.nbAvions;i++){
        if(aeroport.flotte[i].capacite < min.capacite) min = aeroport.flotte[i];
    }
    return min;
}


void afficherStatistiques(Aeroport aeroport){
    int choix, a, b;
    Avion max, min;
    do{
        printf("========================================\n");
        printf("= Statistiques =\n");
        printf("========================================\n");
        printf("1: Nombre total d avions\n2: Nombre par statut\n3: Capacite totale\n4: Avion plus grande capacite\n5: Avion plus petite capacite\n6: Retour menu\n7: Quitter\n");
        printf("Entrer le choix : ");
         scanf("%d",&choix);
        switch(choix){
            case 1: a=nombreTotalAvions(aeroport); printf("Total avions: %d\n",a); 
            break;
            case 2: nombreAvionsStatut(aeroport); 
            break;
            case 3: b=capaciteTotale(aeroport); printf("Capacite totale: %d\n",b);
             break;
            case 4: max=plusGrandeCapacite(aeroport); printf("Plus grande capacite: %d\n", max.capacite); 
            break;
            case 5: min=plusPetiteCapacite(aeroport); printf("Plus petite capacite: %d\n", min.capacite); 
            break;
            default: printf("Choix incorrect\n");
            break;
        }
    } while(choix != 6);
}

Aeroport creerAeroportManuel() {
    Aeroport aeroport;

    strcpy(aeroport.nom, "Aeroport Marrakech");
    aeroport.idAeroport = idAeroportGlobal++;
    aeroport.nbAvions = 0;

    
    Avion avion1;
    avion1.idAvion = idAvionGlobal++;
    strcpy(avion1.modele, "Royal Air Maroc");
    avion1.capacite = 150;
    avion1.dateEntree.jour = 9;
    avion1.dateEntree.mois = 11;
    avion1.dateEntree.annee = 2001;
    strcpy(avion1.statut, "Disponible");
    aeroport.flotte[aeroport.nbAvions++] = avion1;

    Avion avion2;
    avion2.idAvion = idAvionGlobal++;
    strcpy(avion2.modele, "Ryanair flights");
    avion2.capacite = 180;
    avion2.dateEntree.jour = 10;
    avion2.dateEntree.mois = 5;
    avion2.dateEntree.annee = 2010;
    strcpy(avion2.statut, "En vol");
    aeroport.flotte[aeroport.nbAvions++] = avion2;

    Avion avion3;
    avion3.idAvion = idAvionGlobal++;
    strcpy(avion3.modele, "Boeing");
    avion3.capacite = 300;
    avion3.dateEntree.jour = 10;
    avion3.dateEntree.mois = 5;
    avion3.dateEntree.annee = 2025;
    strcpy(avion3.statut, "En maintenance");
    aeroport.flotte[aeroport.nbAvions++] = avion3;

    Avion avion4;
    avion4.idAvion = idAvionGlobal++;
    strcpy(avion4.modele, "Supratours");
    avion4.capacite = 500;
    avion4.dateEntree.jour = 25;
    avion4.dateEntree.mois = 6;
    avion4.dateEntree.annee = 2030;
    strcpy(avion4.statut, "Disponible");
    aeroport.flotte[aeroport.nbAvions++] = avion4;

    printf("Aeroport cree manuellement avec %d avions!\n", aeroport.nbAvions);
    return aeroport;
}

int main() {
    int choix;
    Aeroport aeroportPrincipal;
    Avion avionTemp;
    int resultat;

    do {
        printf("========================================\n");
        printf("= Menu Principal =\n");
        printf("========================================\n");
        printf("1 : Ajouter un Aeroport \n2 : Ajouter un avion \n3 : Afficher la liste des avions\n4 : Rechercher un avion\n5 : Modifier un avion\n6 : Supprimer un avion\n7 : Trier le avions\n8 : Calculer coefficient parc\n9 : Statistique\n10 ;;creerAeropomanuuaaaly\n0 : Quitte\n");
        printf("Entrer le choix : ");
        scanf("%d",&choix);

        switch(choix){
            case 1: 
            
            aeroportPrincipal = ajouterAeroport();
             break;
            case 2: 
            aeroportPrincipal = ajouterAvionAeroport(aeroportPrincipal); break;
            case 3: 
            afficherAeroport(aeroportPrincipal);
             break;
            case 4: 
            
            rechercherAvion(aeroportPrincipal); break;
            case 5: 
            aeroportPrincipal = modifierAvion(aeroportPrincipal);
             break;
            case 6:
             aeroportPrincipal = supprimerAvion(aeroportPrincipal); 
             afficherAeroport(aeroportPrincipal); 
             break;
            case 7:
             afficherTrie(aeroportPrincipal); 
            break;
            case 8: resultat = calculCoefficientParc(aeroportPrincipal); printf("Coefficient parc: %d%%\n", resultat); 
            break;
            case 9: afficherStatistiques(aeroportPrincipal); 
            break;
            case 10:
            aeroportPrincipal = creerAeroportManuel();
            afficherAeroport(aeroportPrincipal);
            break;

            case 0: printf("Au revoir -Oughlane\n");
             break;
            default: printf("Choix incorrect\n");
        }
    } while(choix != 0);

    return 0;
}

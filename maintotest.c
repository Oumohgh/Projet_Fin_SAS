int main() {
    Aeroport aeroport;
    int aeroportInitialise = 0; 
    int choix, id;

    do {
        printf("\n========== MENU TEST ==========\n");
        printf("1 - Creer un Aroport\n");
        printf("2 - Ajouter un Avion\n");
        printf("3 - Afficher l'Aeroport\n");
        printf("4 - Rechercher un Avion par ID\n");
        printf("5 - Supprimer un Avion\n");
        printf("100 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                aeroport = initialiserAeroport();
                aeroportInitialise = 1;
                break;

            case 2:
                if (!aeroportInitialise) {
                    printf(" Creez d'abord un aroport.\n");
                } else 
                    aeroport = ajouterAvionAeroport(aeroport);
                }
                break;

            case 3:
                if (aeroportInitialise) afficherAeroport(aeroport);
                else printf("⚠️ Aucun aéroport créé.\n");
                break;

            case 4:
                if (aeroportInitialise) {
                    printf("Id avion à rechercher : ");
                    scanf("%d", &id);
                    findById(id, aeroport);
                } else {
                    printf("Aucun aéroport cree.\n");
                }
                break;

            case 5:
                if (aeroportInitialise) {
                    printf("Id avion a supprimer : ");
                    scanf("%d", &id);
                    aeroport = supprimerAvion(id, aeroport);
                } else {
                    printf(" Aucun aéroport cree.\n");
                
                break;

            case 100:
                printf("Fermeture du programme...\n");
                break;

            default:
                errMessage("Choix invalide ");
        }
    } while (choix != 100);

    return 0;
}
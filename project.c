#include <stdio.h>
#include<string.h>
struct Joueur equipe[MAX];
int n = 0;         
int nextId = 1;     

void ajouterUnJoueur() {
    struct Joueur j;
    j.id = nextId++;  

    printf("Nom : ");
    scanf("%s", j.nom);
    printf("Prenom : ");
    scanf("%s", j.prenom);
    printf("Age : ");
    scanf("%d", &j.age);

    equipe[n++] = j;  

    printf("✅ Joueur %s %s ajouté avec ID = %d\n", j.nom, j.prenom, j.id);
}

int j_max;
struct joueur
{
    int id;
    char full_name[50];
    int num_maillot;
    int age;
    int buts;
    char poste[4];
    char statut[2];
};

void ajouterUnJoueur();
void ajouterPlusieurs();
void afficher_ordre();
void afficherParNom();
void afficherParAge();
void afficherParPoste();
void modifierJoueur();
void supprimerJoueur();
void chercherParId();
void chercherParNom();
void statistiques();

int main() {
    int choix;

    do {
        printf("\n===== MENU GESTION EQUIPE DE FOOT =====\n");
        printf("1. Ajouter un joueur\n");
        printf("2. Ajouter plusieurs joueurs\n");
        printf("3. Afficher tous les joueurs\n");
        printf("4. Afficher joueurs par nom (\n");
        printf("5. Afficher joueurs par age \n");
        printf("6. Afficher joueurs par poste\n");
        printf("7. Modifier un joueur\n");
        printf("8. Supprimer un joueur\n");
        printf("9. Rechercher un joueur par ID\n");
        printf("10. Rechercher un joueur par nom\n");
        printf("11. Statistiques\n");
        printf("12. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterUnJoueur(); break;
            case 2: ajouterPlusieurs(); break;
            case 3: afficherTous(); break;
            case 4: afficherParNom(); break;
            case 5: afficherParAge(); break;
            case 6: afficherParPoste(); break;
            case 7: modifierJoueur(); break;
            case 8: supprimerJoueur(); break;
            case 9: chercherParId(); break;
            case 10: chercherParNom(); break;
            case 11: statistiques(); break;
            case 12: printf("Au revoir !\n"); break;
            default: printf("Choix invalide, reessayez.\n");
        }

    } while (choix != 12);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "projet.h"
#include <string.h>
int main()
{
int choix, nv;
do
{
    system("cls");
    printf("\n                          ********************GESTION DU STOCK***********************\n");
    printf("\n 1: Ajouter un produit \n");
    printf("\n 2: Afficher la description d'un produit disponible\n");
    printf("\n 3: Supprimer un produit deja disponible\n");
    printf("\n 4: Modifier un produit deja disponible\n");
    printf("\n 5: Recherche d'un produit dans le stock\n");
    printf("\n 6: Afficher tous les produits disponibles dans le stock\n");
    printf("\n 7: Afficher l'historique de la gestion\n");
    printf("\n 8: Terminer \n");
    do
    {
      printf("\n Entre Votre Choix :");
      scanf("%d",&choix);
    }
    while(choix<1 || choix>8);
    {
        switch(choix)
       {
            case 1 :
               ajouter_produit();
               break;
            case 2 :
               description_produit();
               break;
            case 3:
               supprimer();
               break;
            case 4:
                modifier();
                break;
            case 5:
                recherche_produit();
               break;
            case 6:
               affiche_stockage();
               break;
            case 7:
               affiche_historique();
               break;
            case 8:
               break;
          }
          printf("\n Voulez-vous continuez 0/1:");
          scanf("%d",&nv);
          fflush(stdin);
          }
}while(nv==1);
}

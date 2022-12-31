#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
#include <string.h>
struct Produit
    {
        int num;
        char nom[10];
        float prix;
        int qte;
    };
struct Produit prod;

int rech(int numrech)
{
 FILE *F;
 F=fopen("stockage.txt","r");
 do
 {
     fscanf(F,"%d ;%s ;%f ;%d \n",&prod.num,&prod.nom,&prod.prix,&prod.qte);
     fflush(stdin);
     if(prod.num==numrech)
     {
      fclose(F);
      return 1;
     }
 }while(!feof(F));
 fclose(F);
 return 0;
}

int compte_chiffre(float chif)
  {
      int k=0;
      while ( chif > 10)
        {
            k=k+1;
            chif=chif /10;
         }
      return k+1;
  }

void ajouter_produit()
{
 FILE* F;
 FILE* H;
 int num;
 F=fopen("stockage.txt","r");
 H=fopen("historique.txt","a");
 do
 {
 printf("\n Entre l'ID du nouveau produit:");
 printf("\n !!!!!! IL NE FAUT PAS DEPASSER 6 CARACTERES !!!!!! \n");
 scanf("%d",&num);
 fflush(stdin);
 }while(compte_chiffre(num)>6);
 if(rech(num)==1)
  {printf("\n -------> Ce Produit existe deja\n");
   fclose(F);
  }
 else
 { fclose(F);
   F=fopen("stockage.txt","a");
   prod.num=num;
   do{
   printf("\n Entre le Nom du produit:");
   printf("\n !!!!!! IL NE FAUT PAS DEPASSER 6 CARACTERES !!!!!!\n");
   gets(prod.nom);
   fflush(stdin);
   }while(strlen(prod.nom)>6);
   do{
   printf("\n Entre le Prix du produit:");
   printf("\n !!!!!! IL NE FAUT PAS DEPASSER 6 CARACTERES !!!!!!\n");
   scanf("%f",&prod.prix);
   fflush(stdin);
   }while(compte_chiffre(prod.prix)>6);
   printf("\n Entre la Quantite du produit:");
   scanf("%d\n",&prod.qte);
   fflush(stdin);
   fprintf(F,"%d ;%s ;%f ;%d \n",prod.num,prod.nom,prod.prix,prod.qte);
   fprintf(H,"Vous avez effectue l'ajout du produit de l'ID %d ;%s ;%f ;%d %c\n",prod.num,prod.nom,prod.prix,prod.qte,'.');
   fclose(F);
   fclose(H);
 }
}
void description_produit()
{
 int nv ;
 FILE* F;
 FILE* H;
 F=fopen("stockage.txt","r");
 H=fopen("historique.txt","a");
 printf("\n Entre l'ID du  produit\n");
 scanf("%d",&nv);
 if (rech(nv)==0)
    printf("\n Ce Produit n'existe Pas:");
 else
 {
 do
 {
     fscanf(F,"%d ;%s ;%f ;%d \n",&prod.num,&prod.nom,&prod.prix,&prod.qte);
     if(nv==prod.num)
     {
         printf("____________ Description du Produit_____________\n\n");
         printf("ID\t\t: %d \n",prod.num);
         printf("Nom\t\t: %s \n",prod.nom);
         printf("Prix\t\t: %f \n",prod.prix);
         printf("Quantite\t: %d \n",prod.qte);
         fprintf(H,"Vous avez effectue l'Affichage de description du produit de l'ID %d ;%s ;%f ;%d %c\n",prod.num,prod.nom,prod.prix,prod.qte,'.');
     }
 }while(!feof(F));
 fclose(F);
 fclose(H);
 }
}

void affiche_historique()
{
 char info[100];
 FILE* H;
 H=fopen("historique.txt","r");
 printf("*******************Voici Votre Historique****************** :\n \n");
 do
 {
    fscanf(H,"%s",info);
    fflush(stdin);
    if(info[0]=='.')
       printf("%c\n",info[0]);
    else
    printf("%s ",info);

 }while(!feof(H));
 fclose(H);
 H=fopen("historique.txt","a");
 fprintf(H,"Vous avez effectue l'Affichage d'Historique .\n");
 fclose(H);
}

void affiche_stockage()
{
 FILE* F;
 FILE* H;
 int l1,l2,l3,l4,n=30,i;
 F=fopen("stockage.txt","r");
 H=fopen("historique.txt","a");
 printf("                  **************************** La liste des Produits *************************** :\n \n");
 printf("|ID\t\t\t\t|Nom\t\t\t\t|Prix\t\t\t\t|Quantite \n");
 printf("|_______________________________|_______________________________|_______________________________|____________________\n");
 do
 {
    fscanf(F,"%d ;%s ;%f ;%d \n",&prod.num,&prod.nom,&prod.prix,&prod.qte);
    printf("|%d\t\t\t\t",prod.num);
    printf("|%s\t\t\t\t",prod.nom);
    printf("|%f\t\t\t",prod.prix);
    printf("|%d\n",prod.qte);
    printf("|_______________________________|_______________________________|_______________________________|____________________\n");
 }while(!feof(F));
 fprintf(H,"Vous avez effectue l'Affichage du stockage .\n");
 fclose(F);
 fclose(H);
}

void recherche_produit()
{
  int nv ;
 FILE* F;
 FILE* H;
 F=fopen("stockage.txt","r");
 H=fopen("historique.txt","a");
 printf("\n Entre l'ID du  produit\n");
 scanf("%d",&nv);
 if (rech(nv)==0)
    printf("\n -----------> Ce Produit n'existe Pas\n");
 else
    printf("\n ------------> Ce Produit existe\n ");
 fclose(F);
 fprintf(H,"Vous avez effectue Le recherche du Produit de l'ID %d %c\n",nv,'.');
 fclose(H);
}
void supprimer()
{
    char r;
    int num;
    printf("Donner l'ID du produit a supprimer :");
    scanf("%d",&num);
    fflush(stdin);
    if(rech(num)==1)
    {
        printf("\n Etes-vous sure de supprimer ce produit, o/n ? ");
        scanf("%c",&r);
        fflush(stdin);
        if(r=='o'||r=='O')
        {
            FILE*F;
            FILE*Temp;
            FILE*H;
            F=fopen("stockage.txt","r");
            Temp=fopen("temp.txt","a");
            H=fopen("historique.txt","a");
            do
            {
                fscanf(F,"%d ;%s ;%f ;%d \n",&prod.num,&prod.nom,&prod.prix,&prod.qte);
                if(num!= prod.num)
                {
                    fprintf(Temp,"%d ;%s ;%f ;%d \n",prod.num,prod.nom,prod.prix,prod.qte);
                }
            }
            while(!feof(F));
            fclose(Temp);
            fclose(F);
            remove("stockage.txt");
            rename("temp.txt","stockage.txt");
            printf("Suppression effectuee avec succees");
            fprintf(H,"Vous avez effectuee la suppresion du produit d ID %d , son nom %s , le prix %f , la quantite %d %c\n",prod.num,prod.nom,prod.prix,prod.qte,'.');
            fclose(H);
        }

    }
    else
    {
        printf("\n L ID du produit n'estpas disponible --> produit n'est pas disponible dans le stock");
    }
}

void modifier()
{
    FILE*F;
    FILE*Temp;
    FILE*H;
    int i,num,op;
    char r;
    printf("\n Donner l'ID du produit a modifier :");
    scanf("%d",&num);
    fflush(stdin);
    if(rech(num)==1)
    {
        printf("\n Etes-vous sure de modifier ce produit, o/n ? ");
        scanf("%c",&r);
        fflush(stdin);
        if(r=='o'||r=='O')
        {
            F=fopen("stockage.txt","r");
            Temp=fopen("temp.txt","a");
            do
            {
                fscanf(F,"%d ;%s ;%f ;%d \n",&prod.num,&prod.nom,&prod.prix,&prod.qte);
                if(num==prod.num)
                {
                    printf("\n Qu'est ce que vous voulez modifier ?\n");
                    printf("\n 1: Modifier l ID du produit \n");
                    printf("\n 2: Modifier le nom du produit \n");
                    printf("\n 3: Modifier le prix du produit \n");
                    printf("\n 4: Modifier la quantite du produit \n");
                    printf("\n Entre Votre Choix :");
                    scanf("%d",&op);
                    switch(op)
                    {
                        case 1:
                           {
                               H=fopen("historique.txt","a");
                               printf("\n Donner le nouveau ID du produit : \n");
                               scanf("%d",&prod.num);
                               fprintf(Temp,"%d ;%s ;%f ;%d \n",prod.num,prod.nom,prod.prix,prod.qte);
                               fprintf(H,"\n Vous avez modifie l ID du produit %s par le nouveau ID %d %c\n",prod.nom,prod.num,'.');
                               fclose(H);
                               printf("la modification de l'ID est effectuee avec succees");
                        break;
                        }
                        case 2:
                        {
                            H=fopen("historique.txt","a");
                            printf("\n Donner le nouveau nom du produit :\n");
                            scanf("%s",prod.nom);
                            fprintf(Temp,"%d ;%s ;%f ;%d \n",prod.num,prod.nom,prod.prix,prod.qte);
                            fprintf(H,"\n Vous avez modifie le nom du produit ,de ID %d , par le nouveau nom %s %c\n",prod.num,prod.nom,'.');
                            fclose(H);
                            printf("la modification du nom est effectuee avec succees");

                            break;
                        }
                        case 3:
                            {
                                H=fopen("historique.txt","a");
                                printf("\nDonner le nouveau prix du produit :\n");
                                scanf("%f",&prod.prix);
                                fprintf(Temp,"%d ;%s ;%f ;%d \n",prod.num,prod.nom,prod.prix,prod.qte);
                                fprintf(H,"\n Vous avez modifie le prix du produit %s ,d ID%d , par le nouveau prix %f %c\n",prod.nom,prod.num,prod.prix,'.');
                                fclose(H);
                                printf("la modification du prix est effectuee avec succees");

                                break;
                            }
                        case 4:
                            {
                                H=fopen("historique.txt","a");
                                printf("\n Donner la nouvelle quantite de produit :\n");
                                scanf("%d",&prod.qte);
                                fprintf(Temp,"%d ;%s ;%f ;%d \n",prod.num,prod.nom,prod.prix,prod.qte);
                                fprintf(H,"\n Vous avez modifie la quantite de produit %s ,de ID %d , par la nouvelle quantite  %d %c\n",prod.nom,prod.num,prod.qte,'.');
                                fclose(H);
                                printf("la modification de la quantite du produit est effectuee avec succees");

                                break;
                            }
                        default :
                            printf("\n Vous avez choisi un choix invalide \n");
                            break;
                    }
                }
            }
            while (!feof(F));
            fclose(F);
            fclose(Temp);
            remove("stockage.txt");
            rename("temp.txt","stockage.txt");
        }
        else
        {
            printf("\n La modification est annulee \n");
        }

    }
    else
    {
        printf("\n l'ID de ce produit n'est pas disponible--> le prouduit n'est pas disponible ");
    }
}
#endif // PROJET_H_INCLUDED

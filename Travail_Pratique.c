#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct personne{
 	char nom[31];
 	char num_tel[11];
 }Personne;

int test_nbr_valide(int nbr)
 {
 	int i;
 	
 	int resultat,div,val;
 	div = 1000000000;
 	for(i=0;i<10;i++)
 	{
 		val = (nbr/div)%10;
 		div = div/10;
 		
		if((i==1 && val == 9) || (i==1 && val== 8))
		{resultat = 1;}
		
		else if((i==1 && val !=9) ||(i==1 && val !=8))
		{resultat = 0;
		break;}
		
		else if(val>=0)
		{resultat = 1;}
		
		else if(val<0)
		{resultat = 0;
		break;}
 	}
 	return resultat;	
 }
 
void upper(char *nom)
{
    int i,taille;
	taille = strlen(nom);
    for(i=0;i<taille;i++)
      {
        if(nom[i] >= 'a' && nom[i]<= 'z')
        {
            nom[i] = (nom[i] - 32);
        }
        else
        {
            nom[i] = (nom[i]);
        }
      }
} 
 
void Acquisition(Personne *p)
{
printf("\n******************Debut ajout******************\n");
	int num_tel;
	printf("\nEntrer le nom du contact : ");
	scanf("%s",p->nom);
	
	printf("Entrer le numero de telephone : ");
	scanf("%d",&num_tel);
	
	if(test_nbr_valide(num_tel) == 1 && strlen(p->nom)<=30)
	{
	    sprintf(p->num_tel,"%d",num_tel);
	    upper(p->nom);
	}
	else
	{
	
		printf("Erreur!! Veuillez entrer un numero ou un nom valide");
		exit(0);
	}
}

int rechercheNom(Personne Annuaire[],char nom[],int contenu,int *indice)
{
	int i,resultat = 0;
	for(i=0;i<contenu;i++)
	{
		if(strcmp(Annuaire[i].nom,nom) == 0)
		{
		   *indice = i;
		   return 1;
		}
		if(strcmp(Annuaire[i].nom, nom) != 0)
		  resultat = 0;
	}
	return resultat;
}

void rechercheNm(Personne Annuaire[],int contenu)
{
printf("\n***************Debut_Recherche numero***************\n");
	char num_char[11];int i,indice,num;
	printf("Entre le numero a rechercher : ");
	scanf("%d",&num);
	
	sprintf(num_char,"%d",num);	
	for(i=0;i<contenu;i++)
	{
		if(strcmp(Annuaire[i].num_tel,num_char
		)==0)
		  {
		   indice = i;
		   break;
		  }
		else
		  indice = -1;
	}
	if(indice >= 0)
	{
		printf("Le numero 0%s est enregistre au nom %s\n",num_char,Annuaire[indice].nom);
	}
	else
	   printf("Aucun nom enregistre a ce numero\n");
("\n******************Fin_Recherche******************\n");
}

void rechercheTel(Personne Annuaire[],int contenu)
{
printf("\n***************Debut_Recherche nom***************\n");
	char nom_ch[31];int i,indice;
	printf("Entre le nom a rechercher : ");
	scanf("%s",nom_ch);
	upper(nom_ch);
	for(i=0;i<contenu;i++)
	{
		if(strcmp(nom_ch, Annuaire[i].nom)==0)
		  {
		    indice = i;
		   break;
		  }
		else
		   indice = -1;
	}
	if(indice >= 0)
	{
		printf("Le nom %s est enregistre au numero 0%s\n",nom_ch,Annuaire[indice].num_tel);
	}
	else
	   printf("Aucune personne enregistre a ce nom\n");
printf("\n******************Fin_Recherche******************\n");
}
 

void ajoute(Personne **Annuaire,int *taille,Personne champ,int *point)
{
	Personne *taill_p; int indice;
	if(*point == *taille)
	{
		*taille = *taille + 3;
	    taill_p = realloc(*Annuaire,sizeof(Personne)*(*taille));
	   if(taill_p==NULL)
	    {
	    	free(*Annuaire);
	    	printf("Echec de reallocation");
	    	exit(0);
	    }
	    
	    *Annuaire = taill_p;
	    if(rechercheNom(*Annuaire,champ.nom,*point,&indice)==1)
	    {
	    	strcpy((*Annuaire)[indice].num_tel, champ.num_tel);
	    	printf("Le numero de 0%s a ete change en 0%s",champ.nom,champ.num_tel);
	    }
	    else
	    {
	    (*Annuaire)[*point] = champ;
		printf("Vous avez ajouter un element dans le repertoire");
		*point +=1;
	    }
	}

	else
	
	{
	   if(rechercheNom(*Annuaire,champ.nom,*point,&indice)==1)
	    {
	    	strcpy((*Annuaire)[indice].num_tel, champ.num_tel);
	    	printf("\nLe numero de %s a ete change en 0%s",champ.nom,champ.num_tel);
	    }
	    else
	    {
		(*Annuaire)[*point] = champ;
		puts("Vous avez ajouter un element dans le repertoire\n");
		*point +=1;
	    }
	}
printf("\n*****************Fin_ajout_dans_Annuaire*****************\n");
}

void trier(Personne *Annuaire, int taille)
{
    int i, j;
    Personne temp;
    for (i = 0; i < taille - 1; i++)
    {
        for ( j = i + 1; j < taille; j++)
        {
            if(strcmp(Annuaire[i].nom, Annuaire[j].nom) > 0)
            {
                temp = Annuaire[i];
                Annuaire[i] = Annuaire[j];
                Annuaire[j] = temp;
            }
        }
        
    }
}


void affiche(Personne Annuaire[],int taille)
{
printf("\n******************Affichage******************\n");
	int i;
	trier(Annuaire, taille);
if(taille >0)
	{
   {
	for(i=0;i<taille;i++)
	{
	   printf("\t Contact numero  %d\n",i+1);
       printf("\t Nom : %s\n\t Numero : 0%s\n",Annuaire[i].nom,Annuaire[i].num_tel);
       printf("\n");
	}
	}
	}
	else
	{
		printf("\nAucun element dans l'Annuaire veuillez y ajoute des element\n");
	}
printf("\n******************Fin_Affichage******************\n");
}

void supprimer(Personne *p, int *contenu)
{
	
	affiche(p, *contenu);
	printf("\n******************Suppression d'un element******************\n");
	int i,j,resultat; char nom_a_sup[31];
	printf("Taper le nom du contact a supprimer : ");
	scanf("%s",nom_a_sup);
	upper(nom_a_sup);
    Personne tmp;
    for (i = 0; i < *contenu; i++)
    {
        if (strcmp(p[i].nom, nom_a_sup)==0)
        {
            for ( j = i; j < *contenu - 1; j++)
            {
                p[j] = p[j+1];
            }
            p[*contenu-1] = tmp;
            *contenu = *contenu -1;
            resultat = 1;
            break;
        }
        else
        {
        	resultat = 0;
        }
       
    }
  if(resultat == 1) 
    printf("vous avez supprime la personne %s de l'annuaire\n",nom_a_sup);
  else
      printf("Aucune personne au nom de %s existe dans l'annuaire\n",nom_a_sup);
    
   printf("\n******************Fin_Suppression******************\n");
    
}
int main()
{
   Personne *Annuaire,personne;int contenu=0,taille=1;
   Annuaire = calloc(taille,sizeof(Personne));
   
   int menu;
    do
    {
    
        printf("\n\t************** BIENVENU DANS LE MENU*************\n\n"
        "\tQue voulez vous faire ? (taper un chiffre de 1 à 6 \n\tpour vailde une commande)\n"
        "\n\t1. Ajouter une personne dans l'annuaire\n"
        "\t2. Afficher les contenus de l'annuaire\n"
        "\t3. Supprimer une personne dans l'Annuiare\n"
        "\t4. Afficher le numero d'une personne \n"
         "\t5. Afficher le nom d'une personne\n"
        "\t6. Quitter le programe\n"
       
        "\n\tQue choisissez vous de faire : ");
        scanf("%d", &menu);
        
        switch(menu)
        {
        case(1):
            {
            Acquisition(&personne);
        	ajoute(&Annuaire,&taille,personne,&contenu);
            break;
            }
           case(2):
            {
            	affiche(Annuaire,contenu);
            	break;
            }
         	
         case(3):
         {
            supprimer(Annuaire, &contenu);
            break;
         }
         case(4):
         {
         	rechercheTel(Annuaire,contenu);
         	break;
         }
         case(5):
         {
         	rechercheNm(Annuaire, contenu);
         	break;
         }
         case(6):
         {
         	printf("\n\tAu revoir\n");
         	printf("\n\t****************Fin_du_Programme****************\n");
         	exit(1);
         }
        default:
          { 
            printf("Votre choix est invalide\n");
            break;
           }
        }
        
    } while (menu != 0);
   
    free(Annuaire);
      
	return 0; 
}

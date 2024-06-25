#include<stdio.h>
#include<string.h>
#include<conio.h>
#include"cadreenc.h"
#include"entetemenuderoulant.h"
#include"saisiefunc.h"





int main()
{
etudiant tab;char matnom[25];char logino[25];char password[25];pul akalpro;int cat;char akal[25];int mouna;char lon[25];int codeco;int in,out;int bo=0;int po;int c=0;int levelgate;int cut=0;int dora=0;int bg;
int a=0,i;int k,n;int b=0,p;int cpt=1;/*a pour savoir le  numero du menu*/utilisateur util;char verif[25];int ct;char compass[25]=" ";matiere mat;int levelup;int choice;int akalsearch;
char m[6][200]={"1. Saisie -->>>","2. Edition","3. Statistique","4. Gestion des utilisateurs","5. Releve de notes","6. Quitter"};
char t[5][200]={"1. Ajout etudiant","2. Ajout d'une matiere","3. Saisie note dans une matiere","4. Quitter"," "};
char menutili[4][200]={"1. Creer un nouveau compte","2. Acceder a votre compte","3. Quitter"," "};
char statpro[5][200]={"1.POURCENTAGE DE REUSSITE D'UNE MATIERE DANS UN NIVEAU DONNE","2.MEILLEUR ETUDIANT D'UN NIVEAU","3.L'EUDIANT LE PLUS FAIBLE","4.QUITTER","  "};
char ch[200];
inter();


/*intialisation de l'interface de l'application*/

gotoxy(20,14);
printf("CONNECTEZ VOUS EN TOUTES SECURITES");
cadre(18,60,13,15,9);
cadre(0,75,12,25,2);
cadre(20,55,16,18,14);
cadre(49,75,26,28,15);
gotoxy(51,27);
printf("INSTITUT SAINT JEAN");
gotoxy(1,17);
color(15,0);


printf("ENTRER VOTRE LOGIN:  ");
scanf("%s",&logino);

strcpy(password,mot_passe());
cat=rechercheutil(logino,password);/*recherche si le login entré et le mot de passe sont présents dans le fichier utilisateur*/
printf("\n\n\n");

if(cat==1)/*retourne 1 si les informations sont correctes et peremet a l'utilisateur de se connecter*/

{
	system("cls");
	cadre(9,38,8,17,9);
	do{
for(in=9;in<39;in++)
for(out=5;out<8;out++)
{
	gotoxy(in,out);
	printf("*");
}

	enmenu();	/*affichage menu personnalise*/
		for(i=0;i<6;i++)
		{
			if(i==a)
			
				color(2,0);
			else
				color(15, 0);
			gotoxy(10,9+i);	
			printf("%s",m[i]);
			
		}
	k=getch();
	if(k==80){
			if(a==5)
			a=0;
			else
				a++;
			}
	
	
	if(k==72)
	{
		if(a==0)
			a=5;
		else
			a--;
			
	}
	

	if((k==13)&&(a!=5))
	{
	switch(a){
		
	case 0:/*initialisation du menu 0*/
	cadre(39,71,8,14,4);
	do{
		for(i=0;i<5;i++)
		{
			if(i==b)
			
				color(9,0);
			else
				color(15, 0);
			gotoxy(40,9+i);	
			printf("%s",t[i]);
			
		}
	p=getch();
	/*if(b==5)
		b=4;*/
	
	if(p==80){
			if(b==4)
			b=0;
			else
				b++;
			}
	
	
	if(p==72)
	{
		if(b==0)
			b=4;
		else
			b--;
			
	}
	if((p==13)&&(b!=3))
	{
system("cls");
		switch(b)
	{
		
		case 0:/*initialsiation du sous menu 0*/
			tab=saisieetu(c);
			fichetudiant(tab);
			system("pause");
			system("cls");
			
			break;
		case 1:/*initialisation du sous menu 0*/
			mat=saisiemat();/*recuperation et stockage des données propres à une matiere dans la variable en question*/
			ecrire_mat(mat);
			system("pause");
			system("cls");
			break;
		case 2:
			cut=0;
			printf("Saisie note dans une matiere\n");
			printf("Entrer la matiere: ");
			scanf("%s",matnom);
			cut=saisienote(matnom,cut);/*enregistrer les notes des étudiants dans un niveau donnée*/
			if(cut==0)/*teste si la matiere en question a déja été enregistré dans le fihier matière retourne 1 si oui et 0 sinon*/
				printf("La matiere %s est introuvable ajouter la avant d'utiliser cette option ou verifier qu'il existe au moins un %ctudiant de ce niveau\n\n\n\n",matnom,130);
			else
			{
				
				printf("les informations ont %ct%c enregistr%cs avec succes\n\n\n",130,130,130);
			}
			system("pause");
			break;
	}
		
	}
	
	}while(((b!=3)||(p!=13))&&(cpt=1));/*fin initialisation du sous menu 0*/
	system("cls");	
	break;
			case 1:/*initialisation du menu 1*/
				system("cls");
				cadre(10,35,6,8,2);
				cadre(1,35,0,5,9);
				printf("\n\n\n\n");
				gotoxy(2,1);
				color(15,0);
				printf("\t1. LISTE D'UN NIVEAU\n");
				gotoxy(2,2);
				printf("\t2. LISTE DES MATIERES\n");
				gotoxy(11,7);
				printf("UNIVERSITE SAINT JEAN");
				gotoxy(2,3);
				printf("Votre choix: ");
				scanf("%d",&choice);
				
				if(choice==1)
				{
					system("cls");
				printf("Entrer le niveau: ");
				scanf("%d",&levelup);
				edition(levelup);/*liste les étudiants d'un niveau donné*/
				
				}
				else if(choice==2)
				{
					system("cls");
					printf("\t\t\tTABLEAU DES MATIERES");
					editmat();/*listes les différentes matières enrégistrées*/
					printf("\n\n");
					
				}
				gotoxy(1,30);
				system("pause");
				system("cls");
			
				
				break;
			case 2:/*statistique*/
				do{
		for(i=0;i<4;i++)
		{
			if(i==bo)
			
				color(6,0);
			else
				color(15, 0);
			gotoxy(40,11+i);	
			printf("%s",statpro[i]);
			
		}
	po=getch();
	
	if(po==80){
			if(bo==4)
			bo=0;
			else
				bo++;
			}
	
	
	if(po==72)
	{
		if(bo==0)
			bo=4;
		else
			bo--;
			
	}
	if((po==13)&&(bo!=3))
	{

	switch(bo){
		case 0:/*sous menu statistiques*/
		system("cls");
				printf("STATISTIQUES\n");
				printf("Entrer le niveau: \n");
				scanf("%d",&mouna);
				printf("Entrer le nom de la matiere: \n");
				scanf("%s",&lon);
				
				codeco=search_code_mat(lon);
				system("cls");
				color(14,0);
				gotoxy(20,1);
				printf("******************STATISTIQUES*******************");
				gotoxy(39,20);
				dora=0;
				dora=compt(mouna,lon,codeco,dora);/*teste si au moins un eleve dans un niveau donné possède une note en cette matiere retourne 1 si tel est le cas et 0 sinon*/
				
				if(dora==0)
					{
						system("cls");
						printf("Aucun %ctudiant du niveau %d n'est enregistr%c ou la matiere %s est incorrecte r%cessayer plustard!!!!!!\n",130,mouna,130,lon,130);
					}
				else{
			bg=(int)compat(mouna,lon,codeco);
			akalpro=compatio(mouna,lon,codeco);
			statis(bg,lon);
			gotoxy(39,21);
			printf("%d",akalpro.lev);
			gotoxy(53,21);
			printf("%s",akalpro.matiere);
			gotoxy(68,21);
			printf("%.2f",akalpro.pourc*100);
			color(15,0);
			gotoxy(1,26);		
			printf("\n\Nous vous remercions de votre fid%clit%c\n\n\n\n\n\n\n\n\n",130,130);
				}
				gotoxy(1,30);	
				system("pause");
				system("cls");
				dora=0;
				break;/*fin sous menu statistique numero 0*/
		case 1:
			system("cls");
			printf("BEST STUDENT\n");
			//printf("Entrer le niveau: \n");
			//scanf("%d",&levelgate);
			//pvmax();
			//max(levelgate,0);
			break;
		case 2:
			system("cls");
			printf("BAD STUDENT\n");
		
			//printf("Entrer le niveau: \n");
			//scanf("%d",&levelgate); 
			
		    max(levelgate,1);
			break; 
				}
					}
			}while(((bo!=3)||(po!=13)));
			color(15,0);
			system("cls");
			break;
			case 4:
				system("cls");
					
			puts("Entrer le matricule: \n");
			scanf("%s",&akal);
			system("cls");
			akalsearch=search(akal);/*cherche si un étudiant est enrégistré avec ce matricule donc s'il existe return lambda différent de 0 si oui et 0 sinon*/
			if(akalsearch!=0)
				releve(akal);/*fonction qui affiche le relevé avec toutes les informations necéssaires*/
			else
				printf("L ETUDIANT AYANT CE MATRICULE N'EXISTE PAS\nVEUILLEZ REESSAYER PLUSTARD MERCI POUR VOTRE BONNE COMPREHENSION\n");
				system("pause");
				system("cls");
				break;
			case 3:	
			do{
		for(i=0;i<4;i++)
		{
			if(i==b)
			
				color(6,0);
			else
				color(15, 0);
			gotoxy(40,12+i);	
			printf("%s",menutili[i]);
			
		}
	p=getch();

	
	if(p==80){
			if(b==4)
			b=0;
			else
				b++;
			}
	
	
	if(p==72)
	{
		if(b==0)
			b=4;
		else
			b--;
			
	}
	if((p==13)&&(b!=2))
	{
		switch(b)
		{
			case 0:
				system("cls");
				util=creation_utilisateur();/*creation et enregistrements d'un utilisateur lambda dans le fichier utilisateur*/
				ecrire_util(util);
				break;
			case 1:
				system("cls");
				cadre(10,50,1,3,5);
				gotoxy(12,2);
				printf("CONNECTEZ VOUS EN TOUTES SECURITE");
				color(9,0);
				gotoxy(0,4);
				printf("ENTRER VOTRE IDENTIFIANT:\n");
				scanf("%s",&verif);
				strcpy(compass,mot_passe());/*verification de la connection*/
				
				 ct=rechercheutil(verif,compass);
				 printf("\n\n\n");
				 if(ct==1)
				 	printf("OUVERTURE DU COMPTE REUSSI\n");
				else
					printf("ECHEC OUVERTURE DU COMPTE\n");
			
		}
	}
	
	}while((b!=2)||(p!=13));
	system("cls");
				
				break;
			case 5:
				system("cls");
				
				break;
				
			}
	}
	
	//system("pause");
	}while((a!=5)||(k!=13));
	}	
	else{
		gotoxy(0,30);
		color(2,0);
		printf("\tOUPS UNE ERREUR S'EST PRODUITE VOUS NE POUVEZ PAS AVOIR ACCESS \n\tA CETTE APPLICATION IDENTIFIANT OU MOT DE PASSE INCORRECT\n\tREESSAYER PLUSTARD.....");
	}



	return 0;
}
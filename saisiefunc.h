#include"structure.h"/*inclusion des fichiers strcutures */
#include<stdio.h>
#include<conio.h>


										/*FONCTIONS NECESSAIRES POUR LA CREATION DE NOTRE APPLICATION*/
void notecolor(float n);
int  search_code_mat(char matieres[25]);
void pv(char matricule[25]);
void appreciation(float n);
etudiant saisieetu(int i)/*saisie des informations d'un etudiant */
{
	int n;etudiant a;etudiant b;int compteur=0;int cpt=0;
FILE *f=fopen("etudiant.akal","r");
if(f==NULL)
	printf("ERREUR D'OUVERTURE DU FICHIER");
	
else{

printf("REMPLISSAGE INFORMATION PROPRE A UN ETUDIANT");
printf("\n");
printf("INFORMATION DU %d ETUDIANT\n",i+1);
do{
compteur=0;cpt=0;
printf("Entrer son matricule:(chaine de caractere) \n");
scanf("%s",&a.matricule);
n=fread(&b,sizeof(b),1,f);

while(n!=0)
{
	cpt++;
	
	if(strcmp(b.matricule,a.matricule)==0)
		compteur=1;
	n=fread(&b,sizeof(b),1,f);
	
}
rewind(f);
}while((compteur==1));/*pour controller qu'un étudiant ait un seul matricule*/
printf("Entrer le nom de l'%ctudiant: \n",130);
scanf("%s",&a.nom);
do{

printf("Entrer son niveau:(entier) \n");
scanf("%d",&a.niveau);}while(a.niveau<=0);
printf("LES INFORMATIONS DE L' ETUDIANTS ONT ETE ENREGISTRES AVEC SUCCESS\n");


fclose(f);

}
return a;}

void fichetudiant(etudiant p)/*recuperation des informations d'un etudiant et saisie dans le fichier*/
{
	FILE *f=fopen("etudiant.akal","a");
	
	
	if(f==NULL)
		printf("Erreur d'ouverture du fichier\n");
	else
	{
		fwrite(&p,sizeof(p),1,f);
		fclose(f);
	}
}
matiere saisiemat()
{
	matiere n;matiere t;int compteur,cpt,y;
	
	printf("REMPLISSAGE DES INFORMATIONS PROPRE A UNE MATIERE DONNEE\n");
	
	
	FILE *g=fopen("matiere.akal","r");
	if(g==NULL)
		printf("ERREUR D'OUVERTURE DU FICHIER");
	
else{

do{
		compteur=0;cpt=0;
		printf("Entrer le code:(entier) \n");
		scanf("%d",&n.code);
		y=fread(&t,sizeof(t),1,g);

		while(y!=0)
		{
			cpt++;
	
			if(t.code==n.code)
				compteur=1;
				
			y=fread(&t,sizeof(t),1,g);
	
		}
		rewind(g);/*deplacer le curseur au debut*/
		}while((compteur==1)&&(cpt!=0));/*pour controller qu'une matiere ait un code unique*/
fclose(g);
			printf("Entrer le nom: \n");
			scanf("%s",&n.nom);
			do{
			
			printf("Entrer le coefficient: \n");
			scanf("%d",&n.coef);}while(n.coef<=0);
			printf("LES INFORMATIONS DE LA MATIERE ONT ETE ENREGISTRES AVEC SUCCESS\n");
			
}
	return n;
}
compose saisiecomp()/*saisie des  informations propres à une composition*/
{
	
	compose b;
	printf("REMPLISSAGE INFORMATION PROPRE A UNE COMPOSITION\n");
	
	printf("Entrer le matricule: \n");
	scanf("%s",&b.matricule);
	printf("Entrer le code:(entier) \n");
	scanf("%d",&b.code);
	printf("Entrer la note: \n");
	scanf("%f",&b.note);
	printf("LES INFORMATIONS DE LA COMPOSITION ONT ETE ENREGISTRES AVEC SUCCESS\n");
	
	return b;
	
}
utilisateur creation_utilisateur()/*creation d'un nouveau utilisateur*/
{

	utilisateur a;
	printf("ENTRER VOTRE NOM: \n");

	scanf("%s",a.nom);
	printf("ENTRER VOTRE IDENTIFIANT: \n");
	scanf("%s",&a.login);
	printf("ENTRER VOTRE MOT DE PASSE: \n");
	scanf("%s",&a.mot_de_passe);
	printf("M/Mme %s votre enregistrement s'est effectu%c avec success",a.nom,130);
	return a;	
}
void ecrire_util(utilisateur n)/*Enregistrer les informations d'un nouveau utilisateur dans le fichier utilisateur*/
{
	FILE *g=fopen("utilisateur.akal","a");
	
	if(g==NULL)
		printf("ERROR");
	else
	{
		fwrite(&n,sizeof(n),1,g);
		fclose(g);
	}
}


char *mot_passe(){/*generation de mots de passes*/
	char *pass;
      char ch;
      short i = 0;
      short j = 0;
      gotoxy(1,19);
      puts("ENTRER VOTRE MOT DE PASSE: ");
     
      while(i < 20 && j == 0)
      {
             ch = getch();
             
              if(ch == '\r')
              {
                    j =20;
              }
             
              else if( ch != '\r')
              {
                   pass[i] = ch;
                   printf("*");
                   i++;
              }
      }
     
      pass[i]='\0';
     return pass;
}

int rechercheutil(char login[25],char mot[25])/*verfier si un utilisateur est bel et bien présent dans un fichier*/
{int no;utilisateur a;int cpt=0;
	FILE *f=fopen("utilisateur.akal","r");
	
	if( f==NULL)
		printf("LISTE DES UTILISATEURS EST VIDE");
	else{
		no=fread(&a,sizeof(a),1,f);
		while(no!=0)
		{
			if(((strcmp(a.login,login)==0)&&(strcmp(a.mot_de_passe,mot)==0)))
					{
							cpt=1;
					fseek(f,0,SEEK_END);
					
					}
			no=fread(&a,sizeof(a),1,f);
			
		
		}
			fclose(f);
	}
	return cpt;
	
	
	
	
	
	
	
}



void ecrire_mat(matiere n)/*enregistrer une matiere dans le fichier matiere*/
{
	FILE *g=fopen("matiere.akal","a");
	
	if(g==NULL)
		printf("ERROR");
	else
	{
		fwrite(&n,sizeof(n),1,g);
		fclose(g);
	}
}


void releve(char akal[25])/*creation relevé personnalisé*/
{
	int x1=0,y1=5;int j,i;int x2=16;int y2=7;int xx1=16,xx2=32,yy1=5,yy2=7;
cadre(97,100,5,28,11);
color(15,0);
gotoxy(98,6);
printf("I");
gotoxy(98,7);
printf("N");
gotoxy(98,8);
printf("S");
gotoxy(98,9);
printf("T");
gotoxy(98,10);
printf("I");
gotoxy(98,11);
printf("T");
gotoxy(98,12);
printf("U");
gotoxy(98,13);
printf("T");
gotoxy(98,14);
printf(" ");
gotoxy(98,16);
printf("S");
gotoxy(98,17);
printf("A");
gotoxy(98,18);
printf("I");
gotoxy(98,19);
printf("N");
gotoxy(98,20);
printf("T");
gotoxy(98,21);
printf(" ");
gotoxy(98,23);
printf("J");
gotoxy(98,24);
printf("E");
gotoxy(98,25);
printf("A");
gotoxy(98,26);
printf("N");

color(15,0);
	pv(akal);
	cadre(33,78,1,4,13);
	color(15,0);
	gotoxy(34,2);
	puts("  ************RELEVE DE NOTES************");
	gotoxy(0,3);
	color(14,0);
	puts("NOMS ET PRENOMS: ");
	gotoxy(50,3);
	color(14,0);
	puts("MATRICULE: ");
	gotoxy(5,6);
	color(2,0);
	puts("NIVEAU");
	color(2,0);
	gotoxy(17,6);
	color(2,0);
	puts("CODE MATIERE");
	gotoxy(37,6);
	color(2,0);
	puts("NOM UE");
	color(2,0);
	gotoxy(53,6);
	puts("NOTE/20");
	gotoxy(71,6);
	color(2,0);
	puts("COEF");
	gotoxy(81,6);
	color(2,0);
	puts("APPRECIATION");
	color(15,0);
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			cadre(x1,x2,y1,y2,9);
			x1+=16;
			x2+=16;
		}
		y1+=2;
		y2+=2;
		x1=0;
		x2=16;
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<5;j++)
		{
			gotoxy(xx1,yy2);
			printf("%c",197);
			xx1+=16;
			
		}
		xx1=16;
		yy2+=2;
		}
for(j=0;j<5;j++)
{
	gotoxy(xx2,19);
	printf("%c",193);
	xx2+=16;
}
	gotoxy(2,29);
	color(14,0);
	puts("MOYENNE: ");
	cadre(30,70,24,26,4);
	gotoxy(34,25);
	color(15,0);
	puts("********BILAN DU SEMESTRE********");
	cadre(28,72,23,27,14);
	cadre(0,96,28,30,10);
	
	
}


void pv(char matricule[25])/*creation d'un pv */
{
	compose a;int n,i,j,x=17,y=8,m;
	etudiant b;matiere d;int p;int cpt=0;float somme=0;moy guide;
	
	
	
	FILE *f=fopen("etudiant.akal","r");
	
	FILE *g=fopen("matiere.akal","r");
	
	FILE *h=fopen("compose.akal","r");
	
	FILE *mo=fopen("moyenne.akal","a");
	
	if(f==NULL)
		printf("UNE ERREUR S'EST PRODUITE\n");
	else{
		if(h==NULL)
			printf("ERREUR DE LECTURE DU FICHIER");
		else{
			if(g==NULL)
				printf("ERREUR DE LECTURE DU FICHIER");
			else{
				n=fread(&b,sizeof(b),1,f);
				while(n!=0)
				{
					
					if(strcmp(matricule,b.matricule)==0)
					{
							gotoxy(17,3);
							printf("%s",b.nom);
							gotoxy(5,y);
							printf("%d",b.niveau);
							m=fread(&a,sizeof(a),1,h);
							while(m!=0)
							{
								rewind(g);
								if(strcmp(a.matricule,matricule)==0)
								{
									p=fread(&d,sizeof(d),1,g);
									while(p!=0)
									{
									if(d.code==a.code)
									{
									cpt+=d.coef;
									gotoxy(x+5,y);
									printf("%d",a.code);
									gotoxy(35,y);
									printf("%s",d.nom);
									gotoxy(63,3);
									printf("%s",a.matricule);
								
									gotoxy(54,y);
									color(15,0);
									if(a.note<10)
									{
										color(4,0);
										printf("%.2f",a.note);
									}
									else
									
									{
										color(15,0);
										printf("%.2f",a.note);
										
									}
									color(15,0);
									gotoxy(84,y);
									appreciation(a.note);
									gotoxy(72,y);
									printf("%d",d.coef);
								
									somme+=(a.note*d.coef);
										y+=2;
										p=0;
										strcpy(guide.matricule,a.matricule);
									}
									else
										p=fread(&d,sizeof(d),1,g);
									}
									
									}
										m=fread(&a,sizeof(a),1,h);	
										n=0;
								}
								
							}
							else{
						
								n=fread(&b,sizeof(b),1,f);
									}
							
							guide.moyenne=(somme/cpt);
							fwrite(&guide,sizeof(guide),1,mo);
							
							gotoxy(13,29);
							if(somme/cpt<10)
							{
								color(4,0);
								printf("%.2f",somme/cpt);
							}
							else{
								color(15,0);
										printf("%.2f",somme/cpt);}
										color(15,0);
							gotoxy(30,29);
							printf("MENTION: ");
							gotoxy(40,29);
							appreciation(somme/cpt);
							printf("\n\n\n\n");
								
							
					}
					
				
				}
				fclose(mo);
				
			}
			
			fclose(g);
			fclose(f);
		fclose(h);
		
	}
}




int  saisienote(char mat[25],int cut){/*enregistrer les notes de tous les etudiants à une matière donné et ecriture dans le fichier compose*/
	etudiant a; matiere z;int level;int cpt=0;compose comp;int m;int p;
	FILE *f=fopen("etudiant.akal","r");
	FILE *g=fopen("matiere.akal","r");
	FILE *h=fopen("compose.akal","a");
	if(g==NULL)
		printf("ERREUR DE LECTURE DU FICHIER");
	else
	{
		if(f==NULL)
			printf("ERREUR DE LECTURE DU FICHIER");
		else{
			m=fread(&z,sizeof(z),1,g);
			while(m!=0)
			{
				if(strcmp(mat,z.nom)==0)
				{
					comp.code=z.code;
					printf("Entrer le niveau: \n");
					scanf("%d",&level);
					p=fread(&a,sizeof(a),1,f);
					while(p!=0)
					{
					
						if(level==a.niveau)
						{	cut++;
							do{
							
							printf("Entrer la note en %s de %s :",mat,a.nom);
							scanf("%f",&comp.note);}
							while(((comp.note<0)||(20<comp.note)));
							strcpy(comp.matricule,a.matricule);
							fwrite(&comp,sizeof(comp),1,h);
						}
						cpt=1;
						p=fread(&a,sizeof(a),1,f);
					}
					if(cpt!=1)
						printf("AUCUN ETUDIANT DU NIVEAU %d TROUVE",level);
				
				}
				m=fread(&z,sizeof(z),1,g);
			}
				
			fclose(f);
		fclose(h);
	}
	fclose(g);

	}
	return  cut;
	}
	
	
	
	void appreciation(float n)/*pour l'appreciation en fonctin d'une moyenne donnée*/
	{
		if(n<6)
			printf("TRES FAIBLE");
		else if((n>6)&&(n<9))
			printf("FAIBLE");
		else if((n>=9)&&(n<10))
			printf("MEDIOCRE");
		else if((n>=10)&&(n<12))
			printf("PASSABLE");
		else if((n>=12)&&(n<14))
				printf("ASSEZ-BIEN");
		else if((n>=14)&&(n<16))
			printf("BIEN");
		else if((n>=16)&&(n<18))
			printf("TRES-BIEN");
		else if(((n>=18)&&(n<=20)))
			printf("EXCELLENT");
		
	}
void inter(void)/*interface */
{
color(9,0);
   gotoxy(27,6);
	printf("APPLICATION DE GESTION");
	gotoxy(35,7);
	printf("FAIT PAR:");
	gotoxy(32,8);
	printf("AZEGHA ET NAFACK");
	gotoxy(30,9);
	printf("INSTITUT SAINT JEAN");
	gotoxy(13,5);
	color(11,0);
	puts("****************************************************");
	gotoxy(13,6);
	puts("**********");
	gotoxy(55,6);
	puts("**********");
	gotoxy(13,7);
	puts("**********");
	gotoxy(55,7);
	puts("**********");
	gotoxy(13,8);
	puts("**********");
	gotoxy(55,8);
	puts("**********");
	gotoxy(13,9);
	puts("**********");
	gotoxy(55,9);
	puts("**********");
	gotoxy(13,10);
	puts("****************************************************");


}


void edition(int level)/*Liste des étudiants d'un niveau donné*/
{
	
	etudiant a;int n;int i=7,cp=0;
	FILE *f=fopen("etudiant.akal","r");
	if(f==NULL)
		printf("UNE ERREUR S'EST PRODUITE");
	else{
		n=fread(&a,sizeof(a),1,f);
		
		system("cls");
		gotoxy(25,17);
		color(9,0);
		printf("INSTITUT SAINT JEAN");
		cadre(20,70,0,2,2);
		gotoxy(24,1);
		printf("**********LISTE DES ETUDIANTS***********");
		cadre(20,45,3,5,9);
		cadre(45,70,3,5,9);
		gotoxy(25,4);
		printf("MATRICULE");
		gotoxy(46,4);
		printf("NOM ETUDIANT");
		cadre(20,70,6,15,2);
		cadre(20,70,16,18,14);
		
		printf("\n\n\n");
		while(n!=0)
		{
			if(a.niveau==level)
			{
				cp++;
				color(15,0);
				gotoxy(10,i);
				printf("\t\t\t %s\t\t %s\n\n",a.matricule,a.nom);
				i++;
			}
			n=fread(&a,sizeof(a),1,f);
		}
		if(cp==0)
			printf("\n\n\n\tAUCUN ETUDIANT DU NIVEAU %d TROUVE\n\n",level);
		fclose(f);
	}
	
	
	
}
void editmat()/*liste des matières enregistrés au préalable*/
{
	int n;matiere e;
	int i=7;int t,o;
	int j=7;
	FILE *f=fopen("matiere.akal","r");
	
	if(f==NULL)
		printf("Erreur d'ouverture du fichier\n");
	else
	{
		for(t=92;t<94;t++)
			for(o=4;o<23;o++)
			{
				gotoxy(t,o);
				printf("*");
			}
		gotoxy(31,25);
		color(2,0);
		printf("**INSTITUT SAINT JEAN**");
		cadre(91,94,3,23,14);
		cadre(20,70,0,2,2);
		gotoxy(24,1);
		printf("**********LISTE DES MATIERES***********");
		cadre(5,40,3,5,9);
		cadre(40,75,3,5,9);
		cadre(75,90,3,5,9);
		gotoxy(77,4);
		printf("COEF");
		gotoxy(6,4);
		printf("CODE");
		gotoxy(46,4);
		printf("NOM MATIERE");
		cadre(5,90,6,23,2);
		cadre(20,70,24,26,14);
		n=fread(&e,sizeof(e),1,f);
		while(n!=0)
		{
			color(15,0);
			gotoxy(6,j);
			printf(" %d",e.code);
			gotoxy(46,j);
			printf("%s",e.nom);
			gotoxy(80,i);
			printf(" %d",e.coef);
			n=fread(&e,sizeof(e),1,f);
			i++;
			j++;
		}
		fclose(f);
	}
}

void notecolor(float n)/*pour la differenciation d'une moyenne et d'une sous moyenne en attribuant une couleur donné*/
{
	if(n<10)
		color(4,0);
	else
		color(15,0);
		
}
int search(char mat[25])/*recherche d'un etudiant ayant composé au moins une matière*/
	{
		
		compose a;int n;int compt=0;
		FILE *f=fopen("compose.akal","r");
		
		if(f==NULL)
			printf("ERREUR DE L'OUVERTURE DU FICHIER\n");
		else
		{
			n=fread(&a,sizeof(a),1,f);
			while(n!=0)
			{
			if(strcmp(mat,a.matricule)==0)	
				compt++;
				n=fread(&a,sizeof(a),1,f);
			}
			
			fclose(f);
		}		
		return compt;
		
			}		
			
			
int  search_code_mat(char matieres[25])/*recherche code d'une matiere*/
{
	matiere a;      int code,p;
FILE *f=fopen("matiere.akal","r");
if(f==NULL)
	printf("ERREUR DE LECTURE DU FICHIER\n");
else
{
	printf("bievenue\n");
	p=fread(&a,sizeof(a),1,f);
	while(p!=0)
	{
		if((strcmp(a.nom,matieres)==0))
			code=a.code;
	p=fread(&a,sizeof(a),1,f);	
	}
	fclose(f);
	}
	printf("%d",code);
	return code;	
}			
			
			
					
			
int compt(int level,char matiere[25],int val,int dora)/*pour gerer les statistiques*/
{
	FILE *f=fopen("etudiant.akal","r");
	FILE *g=fopen("compose.akal","r");
	etudiant a;compose c;int compt=0;int p;int copt=0,n;int t;double select;
	
	
if(g==NULL)
	printf("ERREUR DE LECTUE DU FICHIER\n");

else{
	
	if(f==NULL)
		printf("ERREUR DE LECTURE DU FICHIER\n");
	else
	{
		n=fread(&a,sizeof(a),1,f);
		while(n!=0)
		{
			
			if(a.niveau==level)
			{
				rewind(g);
				t=fread(&c,sizeof(c),1,g);
				while(t!=0)
				{
					if((strcmp(a.matricule,c.matricule)==0)&&(c.code==val))
					{
						if(c.note>=10)
						{
							compt++;
							
						}
							copt++;
						dora=1;	
					}
					
				t=fread(&c,sizeof(c),1,g);
				
				}

			}
			n=fread(&a,sizeof(a),1,f);	
		}
select=(double)compt/(double)copt;
printf("  %d\t%s\t   %.2f",level,matiere,select*100.0);
		
		printf("\n");
		fclose(f);	
	}
	
fclose(g);	
	
}

return dora;			
}

	
	
	

	
void max(int level,int oui)
{
	moy a;moy  max;moy min;
	char namemax[25]; char namemin[25];
	etudiant b;int p; int n;
		FILE *f=fopen("etudiant.akal","r");
		FILE *g=fopen("moyenne.akal","r");
		
		
		if(f==NULL)
			printf("ERREUR D'OUVERTURE DU FICHIER\n");
		else{
			if(g==NULL)
				printf("ERREUR D'OUVERTURE\n");
			else{
				p=fread(&b,sizeof(b),1,f);
		
				while(p!=0)
				{
					n=fread(&a,sizeof(a),1,g);
						max.moyenne=a.moyenne;
						min.moyenne=a.moyenne;
				
					while(n!=0)
					{
						//printf("bonjour %.2f %s\n",a.moyenne,a.matricule);
						if(((strcmp(b.matricule,a.matricule)==0)&&(b.niveau==level))&&(max.moyenne<=a.moyenne))
								{
								max.moyenne=a.moyenne;
								//printf("%f",max.moyenne);
								strcpy(namemax,b.nom);
								n=0;
								}
						
						else if(((strcmp(b.matricule,a.matricule)==0)&&(b.niveau==level))&&(min.moyenne>a.moyenne))	
						{
							min.moyenne=a.moyenne;
							strcpy(namemin,b.nom);
						}
						else	
						n=fread(&a,sizeof(a),1,g);
					}
					
					p=fread(&b,sizeof(b),1,f);
					}	fclose(g);	
					
					
					fclose(f);
						}
				if(oui==0)
						printf("Le max du niveau %d est %s et a comme moyenne %.2f",level,namemax,max.moyenne);
				else
						printf("Le min du niveau %d est %s et a comme moyenne %.2f",level,namemin,min.moyenne);
					
				
						}
}
	
	
		
	
	
	
	
	
void statis(float  p,char mot[25]){

int x=38; int y=18;int xx=52,yy=20;
int i,j;const float  b=100;
int c;
gotoxy(39,19);
printf("NIVEAU");
gotoxy(53,19);
printf("MATIERE");
gotoxy(68,19);
printf("POURCENTAGE");
	for(i=0;i<2;i++)
			{
				for(j=0;j<3;j++)
					{
						cadre(x,xx,y,yy,9);
						x+=14;
						xx+=14;
					}
					xx=52;
					x=38;
					y+=2;
					yy+=2;
			}
			
if(p==100)
	c=5;
else if(p>=50)
c=(b/p)*8-1;
else if(p==0)
c=0;
else 
c=(b/p)*8-6;

gotoxy(27,5);
printf("HISTOGRAMME DE LA MATIERE %s",mot);
cadre(25,60,4,6,4);
cadre(38,96,11,13,2);
gotoxy(40,12);
color(15,0);
printf("BANDE REPRESENTANT LE POURCENTAGE DE REUSSITE EN ");
color(2,0);
printf("%s",mot);
gotoxy(2,3);
color(15,0);
printf("POURCENTAGE 100/100");
color(15,0);
cadre(19,24,c,24,2);
for(i=19;i<25;i++)
	for(j=c;j<24;j++)
		{
			color(9,14);		
			gotoxy(i,j);
			printf("*");
		}
printf("\n\n\n")	;
for(i=0;i<20;i++)	
	{
		color(11,0);
		gotoxy(5,24-i);
		printf("*");
		printf("\n");
	}
for(i=0;i<60;i++)
		{
			color(11,0);
		gotoxy(i+5,24);
		printf("*");
		}
		
		
		
	
}
	
	
float compat(int level,char matiere[25],int val)
{
	FILE *f=fopen("etudiant.akal","r");
	FILE *g=fopen("compose.akal","r");
	etudiant a;compose c;int compt=0;int p;int copt=0,n;int t;double select;
	
	
if(g==NULL)
	printf("ERREUR DE LECTUE DU FICHIER\n");

else{
	
	if(f==NULL)
		printf("ERREUR DE LECTURE DU FICHIER\n");
	else
	{
		n=fread(&a,sizeof(a),1,f);
		while(n!=0)
		{
			
			if(a.niveau==level)
			{
				rewind(g);
				t=fread(&c,sizeof(c),1,g);
				while(t!=0)
				{
					if((strcmp(a.matricule,c.matricule)==0)&&(c.code==val))
					{
						if(c.note>=10)
						{
							compt++;
							
						}
							copt++;
					}
					
				t=fread(&c,sizeof(c),1,g);
				
				}

			}
			n=fread(&a,sizeof(a),1,f);	
		}
select=(double)compt/(double)copt;
		
		printf("\n");
		fclose(f);	
	}
	
fclose(g);	
	
}

return select*100;			
}

	
		
	
	
	
	
	
	
	
pul compatio(int level,char matiere[25],int val)
{
	pul akalo;
	FILE *f=fopen("etudiant.akal","r");
	FILE *g=fopen("compose.akal","r");
	etudiant a;compose c;int compt=0;int p;int copt=0,n;int t;double select;
	
	
if(g==NULL)
	printf("ERREUR DE LECTUE DU FICHIER\n");

else{
	
	if(f==NULL)
		printf("ERREUR DE LECTURE DU FICHIER\n");
	else
	{
		n=fread(&a,sizeof(a),1,f);
		while(n!=0)
		{
			
			if(a.niveau==level)
			{
				rewind(g);
				t=fread(&c,sizeof(c),1,g);
				while(t!=0)
				{
					if((strcmp(a.matricule,c.matricule)==0)&&(c.code==val))
					{
						if(c.note>=10)
						{
							compt++;
							
						}
							copt++;
						
					}
					
				t=fread(&c,sizeof(c),1,g);
				
				}

			}
			n=fread(&a,sizeof(a),1,f);	
		}
select=(double)compt/(double)copt;
akalo.lev=level;
akalo.pourc=select;
strcpy(akalo.matiere,matiere);
		

		fclose(f);	
	}
	
fclose(g);	
	
}

	return akalo;			
}
	
	
	
	
	
	

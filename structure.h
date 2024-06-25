
/*DEFINITION ET INITIALISATION DES STRUCTURES NECESSAIRES POUR LA CREATION DE CE PROGRAMME*/



typedef struct etudiant{
	char matricule[6];
	char nom[25];
	int niveau;
}etudiant;



typedef struct matiere{
	int code;
	char nom[25];
	int coef;
}matiere;


typedef struct compose{
	char matricule[6];
	int code;
	float note;
}compose;

typedef struct utilisateur{
	char nom[25];
	char  login[25];
	char mot_de_passe[20];
}utilisateur;
typedef struct moy
{
	char matricule[25];
	float moyenne;
}moy;

typedef struct pul
{
	int lev;
	char matiere[25];
	double pourc;
}pul;
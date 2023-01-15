#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
// #include <curses.h>
#include<string.h>


typedef struct {
    char chenf[25];
}chainedenf;

typedef struct{
	chainedenf nomenf[3];
	chainedenf prenomenf[3];
	int NbEnfant;
}enfant;

typedef struct{
	chainedenf nomenfS[15];
	chainedenf prenomenfS[15];
	int NbEnfantS;
}enfantS;


typedef struct{
	chainedenf nomac;
	chainedenf prenomac;
	char natac[15];
}accom;

typedef struct{
	char nom[25];
	char prenom[25];
	char sexe;
    int age;
    char nat[15];
	enfant enf;
	accom ac;
	enfantS enfS;
	int prixx;
	int nuit;
}clien;


int ValidN(char nom[25])
{int i=0;
	while(nom[i])
	{
		if(((nom[i]<'a')||(nom[i]>'z'))&&((nom[i]<'A')||(nom[i]>'Z')))
			return 0;
			i++;
        if (i>23) return 0;
	}
	return 1;}




clien SaisieClient()
{
	int i;
	clien pp;
	pp.ac.natac[0]=0;
	pp.enf.NbEnfant=0;
	pp.enfS.NbEnfantS=0;
	pp.nuit=1;
	printf("INSCRIPTION\n\n\n");
	printf("\t\t\tATTENTION:NE FAITE PAS DES ESPACES DANS LA SAISIE\n");

	do
	{
	printf("Nom:\t");
	scanf("%s",&pp.nom);
	if(ValidN(pp.nom)==0)
		printf("\tNOM INVALIDE\a\n");
	}while(ValidN(pp.nom)==0);
	do
	{
	printf("Prenom:\t");
	scanf("%s",&pp.prenom);
	if(ValidN(pp.prenom)==0)
		printf("\tPRENOM INVALIDE\a\n");
	}while(ValidN(pp.prenom)==0);

	do
	{
	printf("Sexe (M:male/F:femme):\t");
	scanf("%s",&pp.sexe);
	if ((pp.sexe!='m')&&(pp.sexe!='f')&&(pp.sexe!='M')&&(pp.sexe!='F'))
		printf("\tCHOIX INVALIDE\a\n");
	}while((pp.sexe!='m')&&(pp.sexe!='f')&&(pp.sexe!='M')&&(pp.sexe!='F'));

	do
	{
	printf("age:\t");
	scanf("%d",&pp.age);
	if((pp.age>99)||(pp.age<18))
		printf("\tAGE INVALIDE\a\n");
	}while((pp.age>99)||(pp.age<18));


	do
	{
	printf("Nombre de carte national:\t");
	scanf("%s",&pp.nat);
	if(strlen(pp.nat)>14)
		printf("\tNOM INVALIDE\a\n");
	}while(strlen(pp.nat)>14);


	puts("est ce que vous avez un accompagnon avec vous ?");
	puts("tapez 1 si oui ,sinon tapez 2");
	int ch;
	do{
	scanf("%d",&ch);
	if(ch!=1&&ch!=2){puts("\tNOMBRE INVALIDE\a\n");puts("tapez 1 si oui ,sinon tapez 2");}
	}while(ch!=1&&ch!=2);

	if(ch==1){
            printf("nom de ce accompagnon:\t");
		  do
			{
			  scanf("%s",&pp.ac.nomac);
	    if(ValidN(pp.ac.nomac.chenf)==0)
		printf("\t\aNOM NON VALIDE\n:\t");
			}while (ValidN(pp.ac.nomac.chenf)==0);

			printf("prenom :\t");
           do
			{
			  scanf("%s",&pp.ac.prenomac);
	    if(ValidN(pp.ac.prenomac.chenf)==0)
		printf("\t\aPRENOM NON VALIDE\n:\t");
			}while (ValidN(pp.ac.prenomac.chenf)==0);

           do
	       {
           printf("Nombre de carte national:\t");
	       scanf("%s",&pp.ac.natac);
	       if(strlen(pp.ac.natac)>14)
		   printf("\tNOM INVALIDE\a\n");
	       }while(strlen(pp.ac.natac)>14);

}

puts("\nvous pouvez acompagne par 3 enfant gratuit");

int confirm=1;
     do{

do{ printf("Nombre d'enfant vient avec vous ?:\t");
        scanf("%d",&pp.enf.NbEnfant);
     if((pp.enf.NbEnfant<0)){
		printf("\tNOMBE INVALIDE\a\n");}
    }while((pp.enf.NbEnfant<0));

    if((pp.enf.NbEnfant>3)){
		printf("vous etes sur que vous entre plus que 3 car tu vas paye une nouveau chambre pour chaque 5 nouveau enfants\n");
    puts("pour confirmer votre choix tapez 1");
    scanf("%d",&confirm);}

    }while((confirm!=1));

	if ((pp.enf.NbEnfant>0)){
     if((pp.enf.NbEnfant<4)){
		for(i=0;i<pp.enf.NbEnfant;i++)
		{
			printf("nom de %d enfant:\t",i+1);
		  do
			{
			  scanf("%s",&pp.enf.nomenf[i]);
	    if(ValidN(pp.enf.nomenf[i].chenf)==0)
		printf("\t\aNOM NON VALIDE\n:\t");
			}while (ValidN(pp.enf.nomenf[i].chenf)==0);

			printf("prenom de %d enfant:\t",i+1);
           do
			{
			  scanf("%s",&pp.enf.prenomenf[i]);
	    if(ValidN(pp.enf.prenomenf[i].chenf)==0){
		printf("\t\aPRENOM NON VALIDE\n:\t");}

			}while (ValidN(pp.enf.prenomenf[i].chenf)==0);
			}
			}
     if(pp.enf.NbEnfant>=4){
        pp.enfS.NbEnfantS=(pp.enf.NbEnfant-3);int j;
       for(i=0;i<3;i++)
		{
			printf("nom de %d enfant:\t",i+1);
		  do
			{
			  scanf("%s",&pp.enf.nomenf[i]);
	    if(ValidN(pp.enf.nomenf[i].chenf)==0)
		printf("\t\aNOM NON VALIDE:\n\t");
			}while (ValidN(pp.enf.nomenf[i].chenf)==0);

			printf("prenom de %d enfant:\t",i+1);
           do
			{
			  scanf("%s",&pp.enf.prenomenf[i]);
	    if(ValidN(pp.enf.prenomenf[i].chenf)==0){
		printf("\t\aPRENOM NON VALIDE\n:\t");}

			}while (ValidN(pp.enf.prenomenf[i].chenf)==0);
			}
        for(j=0;j<pp.enfS.NbEnfantS;j++)
		{
			printf("nom de %d enfant:\t",j+4);
		  do
			{
			  scanf("%s",&pp.enfS.nomenfS[j]);
	    if(ValidN(pp.enfS.nomenfS[j].chenf)==0)
		printf("\t\aNOM NON VALIDE\n:\t");
			}while (ValidN(pp.enfS.nomenfS[j].chenf)==0);

			printf("prenom de %d enfant:\t",j+4);
           do
			{
			  scanf("%s",&pp.enfS.prenomenfS[j]);
	    if(ValidN(pp.enfS.prenomenfS[j].chenf)==0){
		printf("\t\aPRENOM NON VALIDE\n:\t");}

			}while (ValidN(pp.enfS.prenomenfS[j].chenf)==0);
			}pp.enf.NbEnfant=3;
			}
}
system("cls");
printf("combien du nuit tu vas passer avec nous : ");scanf("%d",&pp.nuit);printf("\n%d",pp.nuit);
pp.prixx=argent(pp);
printf("\n\ntu doit paye :%d DH\n\n",pp.prixx);
ajout_argent(pp.prixx);



printf("votre chambre est de numero : %d ",reserv_chambre());
puts("");
if(pp.enfS.NbEnfantS!=0){
int c,q;
c=pp.prixx/(int)400;
c=c/pp.nuit;
for(q=1;q<c;q++){
printf("votre chambre est de numero : %d ",reserv_chambre());
puts("");}
}

 puts("votre inscription a etait valide avec succes");
 puts("tapez une touch pour retourner au menu");
getch();
return pp;}




int argent(clien pp){
    int k=1;
    int prix=400;
if(pp.ac.natac[0]==0){
    prix=400;
}else{prix=600;}
if(pp.enfS.NbEnfantS!=0){
    k=(pp.enfS.NbEnfantS/5)+1;
    prix=prix+(400*k);
}
    prix=prix*pp.nuit;
return prix;
}

void ajout_argent(int x){
FILE* argents;
int ag=0;
argents=fopen("argent.hotel","r");
if(argents==NULL){argents=fopen("argent.hotel","w");
fprintf(argents,"%d",ag);
}
fscanf(argents,"%d",&ag);
fclose(argents);
argents=fopen("argent.hotel","w");
fprintf(argents,"%d",(x+ag));
fclose(argents);
}
void perdu_argent(int x){
FILE* argents;
int total;
argents=fopen("argent.hotel","r");
if(argents==NULL){printf("la caisse est vide");
}else{fscanf(argents,"%d",&total);
fclose(argents);
if((total-x)<0){printf("impossible, il nya que :%d dans la caisse",total);}
else{remove("argent.hotel");
argents=fopen("argent.hotel","w");
fprintf(argents,"%d",(total-x));
puts("effectu�");fclose(argents);}
}}


void vide_argent(){
FILE* argents;
int k=0;
remove("argent.hotel");
argents=fopen("argent.hotel","w");
fprintf(argents,"%d",k);
fclose(argents);
}


int nbr_chambre_vide(){
FILE* chembre;
int N,i=0;
chembre=fopen("chambre_vide.hotel","r");
N=(feof(chembre));
while(N==0){
    fscanf(chembre,"%d",&N);
    i++;
    N=(feof(chembre));
}
fclose(chembre);
return i;
}

int reserv_chambre()
{
    FILE *chembre;
    chembre=fopen("chambre_vide.hotel","r");
    int N,i,r;
    int nb[20];
    N=nbr_chambre_vide();
    for(i=0;i<N;i++){fscanf(chembre,"%d",&nb[i]);}
    fclose(chembre);
    chembre=fopen("chambre_reserve.hotel","a");
    fprintf(chembre,"\n%d",nb[0]);
    fclose(chembre);
    remove("chambre_vide.hotel");
    chembre=fopen("chambre_vide.hotel","a");
    if(N>1){
    for(i=1;i<N;i++){fprintf(chembre,"\n%d",nb[i]);}
    }
    fclose(chembre);
    r=nb[0];
    return r;
}




void supprimer(int cbr,char CIN[]){
FILE* information;
int i;
int pose;
char* txt;
char* CIN_ADRS;
char* CIN_ADRS1;
char* pt;
char* PT;
char dz='#';
information=fopen("information_all.hotel","r");
fseek(information,0,SEEK_END);
pose=ftell(information);
txt=malloc(pose);
rewind(information);
for (i=0;i<pose;i++){
    txt[i]=fgetc(information);
}

CIN_ADRS=strstr(txt,CIN);
CIN_ADRS1=CIN_ADRS;
if(CIN_ADRS!=NULL){

do{
    CIN_ADRS++;
}while((*CIN_ADRS)!=dz);
CIN_ADRS++;
fclose(information);
remove("information_all.hotel");
information=fopen("information_all.hotel","a");
for(PT=txt;pt<(CIN_ADRS1-2);PT++){fprintf(information,"%c",*PT);}
    for(pt=CIN_ADRS;pt<=(txt+pose);pt++){fprintf(information,"%c",*pt);}
    fclose(information);
    information=fopen("chambre_reserve.hotel","r");
    int tab[20];
    int i=0,k=0;
    do{fscanf(information,"%d",&tab[i]);i++;}while(feof(information)==0);
    k=i;
    for(i=0;i<k;i++){
        if(tab[i]==cbr){tab[i]=0;break;}
        fclose(information);
        information=fopen("information_all.hotel","a");
        for(i=0;i<k;i++){if(tab[i]!=0){fprintf(information,"\nd%",tab[i]);}}
        fclose(information);
    }

}
else{puts("\nintrouvable");}
fclose(information);
}





void inserer_age(clien pp){
    FILE* information_age;
    do{
    information_age=fopen("information_age.hotel","a");

    if(information_age==NULL){
        puts("il exist un problem\nresoudre le probleme puis appuis sur une touch");getch();}
    }while(information_age==NULL);

    fprintf(information_age,"%s","\n__CIN__");
    fprintf(information_age,"%s%c",pp.nat,'.');
    fprintf(information_age,"%d",pp.age);
    fclose(information_age);
}




void inserer_all(clien pp){
    FILE* information_all;
    do{
    information_all=fopen("information_all.hotel","a");

    if(information_all==NULL){
        puts("il exist un problem\nresoudre le probleme puis appuis sur une touch");getch();}
    }while(information_all==NULL);

    fprintf(information_all,"\n__CIN__");
    fprintf(information_all,"%s.",&pp.nat);
    fprintf(information_all,"\nnom : %s-prenom : %s,\nsexe : %c\nage :%d",pp.nom,pp.prenom,pp.sexe,pp.age);
        int k=pp.enf.NbEnfant+(pp.enfS.NbEnfantS);
    fprintf(information_all,"\n%d enfant(s) : ",k);

    int i=0;
    if(pp.enf.NbEnfant!=0){
        for(i=0;i<pp.enf.NbEnfant;i++){
            fprintf(information_all,"\n%s_%s",pp.enf.nomenf[i].chenf,pp.enf.prenomenf[i].chenf);
        }
    }

    if(pp.enfS.NbEnfantS!=0){
        for(i=0;i<pp.enfS.NbEnfantS;i++){
            fprintf(information_all,"\n%s_%s",pp.enfS.nomenfS[i].chenf,pp.enfS.prenomenfS[i].chenf);
        }
    }
    fprintf(information_all,"\n");
    if(pp.ac.natac[0]!=0){
        fprintf(information_all,"%s%s%s%s%s%c%s","accompagne : \n","CIN : ",pp.ac.natac,"\n",pp.ac.nomac.chenf,'-',pp.ac.prenomac.chenf);
    }
    fprintf(information_all,"%s","\n#");
    fclose(information_all);
}




void inserer_nom(clien pp){
    FILE* information_nom;

    do{
    information_nom=fopen("information_nom.hotel","a");

    if(information_nom==NULL){
        puts("il exist un problem\nresoudre le probleme puis appuis sur une touch");getch();}
    }while(information_nom==NULL);

    fprintf(information_nom,"%s","\n__CIN__");
    fprintf(information_nom,"%s%c",pp.nat,'.');
    fprintf(information_nom,"%s",pp.nom);
    fclose(information_nom);
}

void creefichier(){
FILE* information_all;
information_all=fopen("information_all.hotel","a");
fclose(information_all);

FILE* information_age;
information_age=fopen("information_age.hotel","a");
fclose(information_age);

FILE* information_nom;
information_nom=fopen("information_nom.hotel","a");
fclose(information_nom);

FILE* fichier1=NULL;
int nb[3];
int i;
fichier1=fopen("nombr.hotel","r");
    if(fichier1==NULL){i=0;}
    else{i=1;}
fclose(fichier1);
if(i==0){
    fichier1=fopen("nombr.hotel","a");
    nb[2]=0;
    nb[1]=0;
    nb[0]=0;
    fprintf(fichier1,"le_nombre_des_responsables:  %d   \nle_nombre_des_accompagnons:  %d  \nle_nombre_des_enfants:  %d", nb[0], nb[1], nb[2]);
fclose(fichier1);
    }

    FILE* fichier2=NULL;
int j,o;
fichier2=fopen("chambre_vide.hotel","r");
    if(fichier2==NULL){j=0;}
    else{j=1;}
fclose(fichier2);
if(j==0){
    fichier2=fopen("chambre_vide.hotel","a");
    for(o=1;o<21;o++){
    fprintf(fichier2,"\n%d",o);}
fclose(fichier2);}

FILE* fichier3=NULL;
int l;
fichier3=fopen("chambre_reserve.hotel","r");
    if(fichier3==NULL){l=0;}
    else{l=1;}
fclose(fichier3);
if(l==0){
    fichier3=fopen("chambre_reserve.hotel","a");
fclose(fichier3);}
    }



void affichtt(char fichier[]){
FILE* information_all;
int pose;
char car;
int i;
information_all=fopen(fichier,"r");
fseek(information_all,0,SEEK_END);
pose=ftell(information_all);
rewind(information_all);
for(i=0;i<pose;i++){
    car=getc(information_all);
    printf("%c",car);
}
fclose(information_all);
}


void rech_info(char CIN[]){
FILE* information;
int i;
int pose;
char* txt;
char* CIN_ADRS;
char dz='#';
information=fopen("information_all.hotel","r");
fseek(information,0,SEEK_END);
pose=ftell(information);
txt=malloc(pose);
rewind(information);
for (i=0;i<pose;i++){
    txt[i]=fgetc(information);
}

CIN_ADRS=strstr(txt,CIN);
if(CIN_ADRS!=NULL){
printf("_CIN :");
do{
    printf("%c",*CIN_ADRS);
    CIN_ADRS++;
}while((*CIN_ADRS)!=dz);
}
else{puts("\nintrouvable");}
fclose(information);
}

void nombr(clien pp){

FILE* fichier1=NULL;
int nb[3];
char nbdenfent[50],nbdrespo[50],nbdaccom[50];
    fichier1=fopen("nombr.hotel","r+");
    if(fichier1==NULL){
        puts("il exist un problem\nresoudre le probleme puis appuis sur une touch");
    }else{
    fscanf(fichier1, "%s %d %s %d %s %d", nbdrespo, &nb[0], nbdaccom, &nb[1], nbdenfent, &nb[2]);
    nb[2]=nb[2]+pp.enf.NbEnfant+pp.enfS.NbEnfantS;
    nb[0]=nb[0]+1;
    if(pp.ac.natac[0]!=0){nb[1]=nb[1]+1;}
fclose(fichier1);remove("nombr.hotel");}

FILE* fichier2=NULL;
fichier2=fopen("nombr.hotel","a");
fprintf(fichier2,"le_nombre_des_responsables:  %d   \nle_nombre_des_accompagnons:  %d  \nle_nombre_des_enfants:  %d", nb[0], nb[1], nb[2]);
fclose(fichier2);
}



int main(){
    creefichier();
    char choix,choix2=0,choix3=0,choix4=0;
    clien pp;
	pp.ac.natac[0]=0;
	pp.enf.NbEnfant=0;
	pp.enfS.NbEnfantS=0;
    char CIN[15];
    char chaine[100];
    int i;
    system("color 0C");
    puts("BONJOUR DANS VOTRE HOTEL ! \nsoyer les bienvenus\n");
    printf("           /|||||||\\           ||        ||      ||  ||     |||||||||||||||      || |||| ||||        |||           \n");
    printf("          /|||||||||\\          ||        ||    ||      ||   |||||||||||||||      |||                 |||           \n");
    printf("         /|||||||||||\\         ||        ||   ||        ||       ||||            |||                 |||           \n");
    printf("        /|||||   |||||\\        ||        ||   ||        ||       ||||            |||                 |||           \n");
    printf("        |  |||   |||  |        ||||||||||||   ||        ||       ||||            || ||| |||          |||           \n");
    printf("        |||||||||||||||        ||        ||   ||        ||       ||||            |||                 |||           \n");
    printf("        ||||||/ \\||||||        ||        ||   ||        ||       ||||            |||                 |||           \n");
    printf("        ||||||   ||||||        ||        ||    ||      ||        ||||            |||                 ||||||        \n");
    printf("        ||||||   ||||||        ||        ||      ||  ||          ||||            || |||| ||||        || |||||||||  \n");
    getch();



while(choix!='4'){
    system("cls");system("color 5B");
		printf("\nla date du jour : %s",__DATE__);
		printf("\nl'heur d'ouverture : %s",__TIME__);
     	puts("\n\n\n");
 		puts("                                             -----------------------------------");
		puts("                                                | GESTION DE HOTEL D'AVENIR |");
		puts("                                             -----------------------------------");
		puts("                       ----------------------------------------------------------------------------- \n");
		puts("                      |  ->1) vous voulez inscrire maintenant ?                                     |\n");
		puts("                      |  ->2) Consulter a la base des informations.                                 |\n");
        puts("                      |  ->3) Supprimer tout.                                                       |\n");
        puts("                      |  ->4) Quitter.                                                              |\n");
        puts("                      |  ->5) vous avez un probleme() lors de l execution ou inscription.     |\n");
        puts("                      |  ->0) A propos.                                                             |\n");
        puts("                      ------------------------------------------------------------------------------ \n");
		printf("                                                                        |Choix : ");
        choix=getch();


switch(choix)
		{
		case '1':
		        if(nbr_chambre_vide()!=0){
		        system("cls");
		        pp=SaisieClient();
		        inserer_age(pp);
		        inserer_nom(pp);
		        inserer_all(pp);
		        nombr(pp);
		        }else{system("cls");puts("\ntout les chambre est reserver");}
				printf("frapper une touche pour retourner aux MENU");
				break;

		case '2':
        choix2=77;
while(choix2!='0'){
    system("cls");system("color 3f");
		printf("\nla date du jour : %s",__DATE__);
		printf("\nl'heur d'ouverture : %s",__TIME__);
     	puts("\n\n\n");
 		puts("                                            ------------------------------------");
		puts("                                                |  LA BASE DES INFORMATION  |");
		puts("                                            ------------------------------------");
		puts("                       ------------------------------------------------------------------------ \n");
		puts("                      |  ->1) nombre de personne aux hotel.                                    |\n");
		puts("                      |  ->2) gestion des chambre.                                             |\n");
		puts("                      |  ->3) gestion d'argent.                                                |\n");
		puts("                      |  ->4) rechercher un personne par CIN.                                  |\n");
        puts("                      |  -> ) affichage des personne trier par:                                |\n");
        puts("                      |  -------->5) nom.                                                      |\n");
        puts("                      |  -------->6) date d'inscription.                                       |\n");
        puts("                      |  ->7) suprimer un personne par CIN et par sa chambre.                  |\n");
        puts("                      |  ->0) retourn aux MENU.                                                |\n");
        puts("                      ------------------------------------------------------------------------- \n");
		printf("                                                                        |Choix : ");
choix2=getch();

switch(choix2)
		{
		case '1':
		        system("cls");
		        affichtt("nombr.hotel");
                puts("\n\nfrapper une touche pour retourner aux MENU");
                getch();
				break;
		case '2':choix4=77;
		            while(choix4!='0'){
                       system("cls");
                       puts("\n\n\n");
                       puts("                       --------------------------------------------- \n");
                       puts("                      | 1->les chambre vide.                        |\n");
                       puts("                      | 2->les chambre reserver.                    |\n");
                       puts("                      | 0->retourn au menu.                         |\n");
                       puts("                       --------------------------------------------- \n");
                       printf("                                               |Choix : ");choix4=getch();
                   switch(choix4)
                   {
                   case '1':
                       system("cls");
                       puts("les chambres qui sont vides : ");
                       affichtt("chambre_vide.hotel");
                       puts("\n\nfrapper une touche pour retourner aux MENU");
                       getch();
                       break;
                   case '2':
                       system("cls");
                       puts("les chambres qui sont reserver : ");
                       affichtt("chambre_reserve.hotel");
                       puts("\n\nfrapper une touche pour retourner aux MENU");
                       getch();
                       break;
		           }
		         }

				break;

		case '3':
		            choix3=77;int agpr;
		         while(choix3!='0'){
                    system("cls");
                    puts("\n\n\n");
                    puts("                       --------------------------------------------- \n");
                    puts("                      | 1->afficher l'argent dans la caisse.        |\n");
                    puts("                      | 2->tire de la caisse.                       |\n");
                    puts("                      | 3->vide la caisse.                          |\n");
                    puts("                      | 0->retourn au menu.                         |\n");
                    puts("                       --------------------------------------------- \n");
                    printf("                                               |Choix : ");choix3=getch();
                switch(choix3)
                {
                case '1':
                    system("cls");
                    puts("l'argent au caisse est:");
                    affichtt("argent.hotel");
                    puts("\n\nfrapper une touche pour retourner aux MENU");
                    getch();
                    break;
                case '2':
                    system("cls");puts("x7al bghit takhod");scanf("%d",&agpr);
                    perdu_argent(agpr);
                    puts("\n\nfrapper une touche pour retourner aux MENU");
                    getch();
                    break;
                case '3':
                    system("cls");
                    vide_argent();
                    puts("effectu�");
                    puts("\n\nfrapper une touche pour retourner aux MENU");
                    getch();
                    break;
                }
		         }

				break;
        case '4':
                 system("cls");
                 puts("entrer le CIN a rechercher");
                 scanf("%s",CIN);
                 rech_info(CIN);
                 puts("\n\nfrapper une touche pour retourner aux MENU");
                 getch();
				break;
		case '5':
                affichtt("information_nom.hotel");
                puts("\n\nfrapper une touche pour retourner aux MENU");
                getch();
				break;
        case '6':
                system("cls");
                affichtt("information_all.hotel");
                puts("\n\nfrapper une touche pour retourner aux MENU");
                getch();
                break;
        case '7':
                    system("cls");
                    int nbch=22;char CIN[15];
                    do{puts("entrer le num de chambre(entre 1 et 20) : ");
                    scanf("%d",&nbch);}while(nbch>20&&nbch<1);
                    puts("entre le cin a supprimer");
                    scanf("%d",CIN);
                    supprimer(nbch,CIN);
                    puts("\n\nfrapper une touche pour retourner aux MENU");
                getch();

                break;
        }}
                            break;

				break;
		case '3':system("cls");
		         int n;
		         puts("voulez vous vraiment supprimer tout, tout les donnes seras perdu  \n tapez 1 si vous etes sur sinon tapez une autre touch :");
		         scanf("%d",&n);
		         if(n==1){
		         remove("information_nom.hotel");remove("information_age.hotel");remove("information_all.hotel");remove("nombr.hotel");remove("chambre_reserve.hotel");remove("chambre_vide.hotel");remove("argent.hotel");
		         puts("vous devrais redemarer le programme avant le continue");}
				 puts("frapper une touche pour retourner aux MENU");
				 getch();

				break;

		case '5':
                    system("cls");
                    puts("ecrire votre probleme de moins de 100 lettre nous essayons de regler le probleme");
                    gets(chaine);
                break;

		case '0':	system("cls");
					puts("A Propos:");
                    printf("AUTEURS :MOHAMED SOULAIMANI 19 ANS ENSA KHOURIBGA CP2 G4 N134 JANVIER 2018\a\         TARIQ AIT ADDI 19 ANS G1 N4\n\n");
                    printf("EMAIL:MOHAMED-SOULAIMANI@HOTMAIL.COM\nGMAIL:MOHAMED.SOULAIMANI.1998.09.03@GMAIL.COM\nFACEBOOK:Moha Slimani(Assassin)\n\n ;) ;)\n\n\n");
					printf("frapper une touche pour retourner aux MENU");
					getch();
				break;
}

}
system("cls");
printf("\n\n\a vous avez fermer le programme avec succes\n\n");
system("exit");

    return 0;}

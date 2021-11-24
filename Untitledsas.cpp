#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int r=0,m=0,n=0,p=0;
char id[10],sol[10];

typedef struct cmpt{
	char cin[10];
	char nom[20];
	char prenom[20];
	float montant;
}cmpt;

cmpt c[50];
int main();
int recherch(cmpt c[50],char Cin[10],int m){																//find account by ID
	int i;
	for(i=0;i<m;i++){
		if(strcmp(Cin,c[i].cin)==0){
			return i;
			break;
			}		
		}
		return -1;
}

void introduire(cmpt c[50],int m){
	
	printf("\nEntrer votre CIN: ");
	scanf("%s",id);
	if(recherch(c,id,m)==-1){
		strcpy(c[m].cin,id);
	}else{
		printf("CIN deja utilise\n");
		system ("pause");
		system ("cls");
        main();
	}
	
	printf("\nEntrer votre nom: ");
	scanf("%s",c[m].nom);
	printf("\nEntrer votre prenom: ");
	scanf("%s",c[m].prenom);
	printf("\nEntrer votre montant: ");
	scanf("%f",&c[m].montant);
}

void afficher(cmpt c[50],int m){
	int i;
	for(i=0;i<m;i++){
		printf("			Compte %d:\n",i+1);
		printf("CIN: %s\n",c[i].cin);
		printf("NOM: %s\n",c[i].nom);
		printf("PRENOM: %s\n",c[i].prenom);
		printf("MONTANT: %.2f\n",c[i].montant);
		}
}

void tri_croi(cmpt c[50],int m){
	int i,j;
	cmpt t[10];
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			if(c[i].montant>c[j].montant){
				t[i]=c[i];
				c[i]=c[j];
				c[j]=t[i];
			}	
		}
	}	
}

void aff_croi_depuix(cmpt c[50],int montant_min,int m){
	int i;

	tri_croi(c,m);
	for(i=0;i<m;i++){
		if(c[i].montant>=montant_min){
			p=i;
			break;
		}		
	}
	
	for(i=p;i<m;i++){
		printf("			Compte %d:\n",i+1);
		printf("CIN: %s\n",c[i].cin);
		printf("NOM: %s\n",c[i].nom);
		printf("PRENOM: %s\n",c[i].prenom);
		printf("MONTANT: %.2f\n",c[i].montant);	
	}
}

void aff_decroi_depuix(cmpt c[50],int montant_min,int m){
	int i;

	tri_croi(c,m);						
									//find min pos 
	for(i=0;i<m;i++){
		if(c[i].montant>=montant_min){
			p=i;
			break;
		}	
	}
				//affichage
	for(i=m-1;i>=p;i--){
		printf("			Compte %d:\n",i+1);
		printf("CIN: %s\n",c[i].cin);
		printf("NOM: %s\n",c[i].nom);
		printf("PRENOM: %s\n",c[i].prenom);
		printf("MONTANT: %.2f\n",c[i].montant);	
	}
}

void tri_decroi(cmpt c[50],int m){
	int i,j;
	cmpt t[10];
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			if(c[i].montant<c[j].montant){
				t[i]=c[i];
				c[i]=c[j];
				c[j]=t[i];
			}	
		}
	}	
}

int Retrait(cmpt c[50],int z,int R){																		//withraw
	if(c[z].montant<R){
		printf("montant insuffisant!!\n");
		return 0;
	}
	else{
		c[z].montant=c[z].montant-R;
		printf("Votre nouveau montant est:%.2f\n",c[z].montant);
	}
}

void Depot(cmpt c[50],int z,int D){																			//deposition
	
	c[z].montant=c[z].montant+D;
		printf("Votre nouveau montant est:%.2f\n",c[z].montant);
}

void fidelisation(cmpt c[50],int m){																		//add 1.3% to top 3 accounts
	int i;
	tri_decroi(c,m);
	for(i=0;i<3;i++){
		c[i].montant=c[i].montant+c[i].montant*1.3/100;
	}
	printf("OPPERATION EFFECTUEE\n");
}

//							*********************************************************************************************************************
main(){
	int option,operation,affichage,i,pos,retrait,depot;
    char Cin[10];
    

	printf("\n\n\t----------------MENU----------------\n\n");
    printf("choose an option\n");
    
    printf("1-Introduire un compte bancaire \n");
	printf("2-Introduire plusieurs comptes bancaires \n");
	printf("3-Operations\n");
	printf("4-Affichage\n");
	printf("5-Fidelisation\n");
	printf("6-Quitter l'application\n");
	
	scanf("%d",&option);

    switch(option){

		case (1):																			//Introduire un compte bancaire
			for(i=m;i<m+1;i++){
				introduire(c,i);
			}
			m++;
			system ("pause");
			system ("cls");
            main();
            break;

        case (2):																			//Introduire plusieurs comptes
			printf("Entrer le nombre de comptes que vous voulez inserer\n");
			scanf("%d",&n);
			for(i=m;i<m+n;i++){
				introduire(c,i);
			}
			m=m+n;
			system ("pause");
			system ("cls");
			main();
    		break;

        case (3):																			//Operations
            printf("1-Retrait\n");																				
			printf("2-Depot\n");
			printf("3-Annuler\n");
			scanf("%d",&operation);																					
            switch(operation){
            	
				case (1):																							//Retrait
					printf("Entrer votre CIN\n");
            		scanf("%s",Cin);
					recherch(c,Cin,m);
					if(recherch(c,Cin,m)==-1){
						printf("CIN invalide \n");
						system ("pause");
						system ("cls");
						main();																					//check
						break;																						//check
					}																								//check
					else{																							//check
						printf("Entrer le montant que vous voulez retirer\n");
            			scanf("%d",&retrait);
						pos=recherch(c,Cin,m);
						printf("CIN: %s\n",c[pos].cin);
						printf("NOM: %s\n",c[pos].nom);
						printf("PRENOM: %s\n",c[pos].prenom);
						printf("MONTANT: %.2f\n",c[pos].montant);
						Retrait(c,pos,retrait);
					}
					system ("pause");
					system ("cls");
            		main();
            		break;
            		
            	case (2):																							//Dépôt
            		printf("Entrer votre CIN\n");
            		scanf("%s",Cin);
					recherch(c,Cin,m);
					if(recherch(c,Cin,m)==-1){
						printf("CIN invalide \n");
						system ("pause");
						system ("cls");
						main();
						break;
					}
					else{
						printf("Entrer le montant que vous voulez deposer\n");
            			scanf("%d",&depot);
						pos=recherch(c,Cin,m);
						printf("CIN: %s\n",c[pos].cin);
						printf("NOM: %s\n",c[pos].nom);
						printf("PRENOM: %s\n",c[pos].prenom);
						printf("MONTANT: %.2f\n",c[pos].montant);
						Depot(c,pos,depot);
					}
					system ("pause");
					system ("cls");
            		main();
            		break;
				
				case (3):
					system ("cls");
            		main();
					break;
				
				default:
					printf("Erreur! operateur incorrect\n");
					system ("pause");
					system ("cls");
					main();
			}

            break;

        case (4):																			//Affichage
        	printf("Choose an option\n");
        	
            printf("\n1-Affichage par Ordre Ascendant");
            printf("\n2-Affichage par Ordre Descendant");
            printf("\n3-Affichage par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit)");
            printf("\n4-Affichage par Ordre Descendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit)");
            printf("\n5-Recherche par CIN");
            printf("\n6-Annuler\n");
            
            scanf("%d",&affichage);
            
                switch(affichage){
                	
    				case (1):																						//Ordre Ascendant
						tri_croi(c,m);
						afficher(c,m);
    					system ("pause");
						system ("cls");
						main();
        				break;

    				case (2):																						//Ordre Descendant
						tri_decroi(c,m);
						afficher(c,m);
						system ("pause");
						system ("cls");
						main();
						break;

    				case (3):																						//Ordre Ascendant > n
        				int montant_min;
						printf("Entrer le montant minimal\n");
						scanf("%d",&montant_min);
						aff_croi_depuix(c,montant_min,m);
        				
						system ("pause");
						system ("cls");main();
						break;

        			case (4):																						//Ordre Descendant > n
						printf("Entrer le montant minimal\n");
						scanf("%d",&montant_min);
						aff_decroi_depuix(c,montant_min,m);
        			    system ("pause");
						system ("cls");
						main();
        				break;
         			     
					case (5):																						//Recherche par CIN
        			    printf("Entrer le CIN dont vous voulez chercher \n");
        			    scanf("%s",Cin);
						pos=recherch(c,Cin,m);
						if(pos==-1){
							printf("CIN invalide \n");
							system ("pause");
							system ("cls");
							main();
						}
						printf("CIN: %s\n",c[pos].cin);
						printf("NOM: %s\n",c[pos].nom);
						printf("PRENOM: %s\n",c[pos].prenom);
						printf("MONTANT: %.2f\n",c[pos].montant);
						printf("indice: %d",pos);
						system ("pause");
						system ("cls");
						main();
        				break;

    				case (6):
						system ("cls");
            			main();
						break;
       				 
					default:
    					printf("Erreur! operateur incorrect\n");
    					system ("pause");
						system ("cls");
						main();	
					}
        			break;

        case (5):																			//Fidelisation
            fidelisation(c,m);
    		system ("pause");
			system ("cls");
			main();
            break;
            
        case (6):																			//Quitter l'application
            break;
        
        default:
        	printf("Erreur! operateur incorrect\n");
        	scanf("%s",sol);
			system("cls");
			main();
				
    }
}


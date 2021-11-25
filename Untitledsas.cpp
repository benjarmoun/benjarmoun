#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int m=0;
char id[10];

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
	
	printf("\n Entrer votre CIN: ");
	scanf("%s",id);
	if(recherch(c,id,m)==-1){
		strcpy(c[m].cin,id);
	}else{
		printf("\n CIN deja utilise!!\n");
		system ("pause");
		system ("cls");
        main();
	}
	
	printf("\n Entrer votre nom: ");
	scanf("%s",c[m].nom);
	printf("\n Entrer votre prenom: ");
	scanf("%s",c[m].prenom);
	printf("\n Entrer votre montant: ");
	scanf("%f",&c[m].montant);
	printf("\n");
}

void afficher(cmpt c[50],int m){
	int i;
	for(i=0;i<m;i++){
		printf("\n			Compte %d:",i+1);
		printf("\n\tCIN: %s",c[i].cin);
		printf("\n\tNOM: %s",c[i].nom);
		printf("\n\tPRENOM: %s",c[i].prenom);
		printf("\n\tMONTANT: %.2f\n",c[i].montant);
		}
}

void tri_croi(cmpt c[50],int m){
	int i,j;
	cmpt t;
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			if(c[i].montant>c[j].montant){
				t=c[i];
				c[i]=c[j];
				c[j]=t;
			}	
		}
	}	
}

int aff_croi_depuix(cmpt c[50],int montant_min,int m,int p){
	int i;
	p=-1;
	
	tri_croi(c,m);
	for(i=0;i<m;i++){
		if(c[i].montant>=montant_min){
			p=i;
			break;
		}		
	}
	
	if(p==-1){
		printf("\n Aucun montant n'est supperieur a %d\n",montant_min);
		return 0;
	}
	
	for(i=p;i<m;i++){
		printf("			Compte %d:",i+1);
		printf("\n\tCIN: %s",c[i].cin);
		printf("\n\tNOM: %s",c[i].nom);
		printf("\n\tPRENOM: %s",c[i].prenom);
		printf("\n\tMONTANT: %.2f\n",c[i].montant);	
	}
}

int aff_decroi_depuix(cmpt c[50],int montant_min,int m,int p){
	int i;
	p=-1;
	
	tri_croi(c,m);						
									//find min pos 
	for(i=0;i<m;i++){
		if(c[i].montant>=montant_min){
			p=i;
			break;
		}
	}
	
	if(p==-1){
		printf("\n Aucun montant n'est supperieur a %d\n",montant_min);
		return 0;
	}
	
				//affichage
	for(i=m-1;i>=p;i--){
		printf("\n			Compte %d:",i+1);
		printf("\n\tCIN: %s",c[i].cin);
		printf("\n\tNOM: %s",c[i].nom);
		printf("\n\tPRENOM: %s",c[i].prenom);
		printf("\n\tMONTANT: %.2f\n",c[i].montant);	
	}
}

void tri_decroi(cmpt c[50],int m){
	int i,j;
	cmpt t;
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			if(c[i].montant<c[j].montant){
				t=c[i];
				c[i]=c[j];
				c[j]=t;
			}	
		}
	}	
}

int Retrait(cmpt c[50],int z,int R){																		//withraw
	if(c[z].montant<R){
		printf("\n montant insuffisant!!\n");
		return 0;
	}
	else{
		c[z].montant=c[z].montant-R;
		printf("\n Votre nouveau montant est: %.2f\n",c[z].montant);
	}
}

void Depot(cmpt c[50],int z,int D){																			//deposition
	
	c[z].montant=c[z].montant+D;
		printf("\n Votre nouveau montant est: %.2f\n",c[z].montant);
}

void fidelisation(cmpt c[50],int m){																		//add 1.3% to top 3 accounts
	int i;
	tri_decroi(c,m);
	for(i=0;i<3;i++){
		c[i].montant=c[i].montant+c[i].montant*1.3/100;
	}
	printf("\n OPPERATION EFFECTUEE.\n");
	afficher(c,3);
}

//							*********************************************************************************************************************
main(){
	int option,operation,affichage,i,pos,retrait,depot,n=0,p;
    char Cin[10],sol[10];
    

	printf("\n\n\t\t----------------MENU----------------\n\n");
    printf("\n  Choisis une option\n");
    
    printf("\n\t1-Introduire un compte bancaire");
	printf("\n\t2-Introduire plusieurs comptes bancaires");
	printf("\n\t3-Operations");
	printf("\n\t4-Affichage");
	printf("\n\t5-Fidelisation");
	printf("\n\t6-Quitter l'application\n");
	
	scanf("%d",&option);

    switch(option){

		case (1):																			//Introduire un compte bancaire
			
			introduire(c,m);
			m++;
			system ("pause");
			system ("cls");
            main();
            break;

        case (2):																			//Introduire plusieurs comptes
			printf("\n Entrer le nombre de comptes que vous voulez inserer: ");
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
            printf("\n  Choisis une option\n");
		    printf("\n\t1-Retrait");																				
			printf("\n\t2-Depot");
			printf("\n\t3-Annuler\n");
			scanf("%d",&operation);																					
            switch(operation){
            	
				case (1):																							//Retrait
					printf("\n Entrer votre CIN: ");
            		scanf("%s",Cin);
					recherch(c,Cin,m);
					if(recherch(c,Cin,m)==-1){
						printf("\n CIN invalide!!\n");
						system ("pause");
						system ("cls");
						main();																					//check
						break;																						//check
					}																								//check
					else{																					 		//check
						pos=recherch(c,Cin,m);
						printf("\n Montant actuel: %.2f",c[pos].montant);
						printf("\n Entrer le montant que vous voulez retirer: ");
            			scanf("%d",&retrait);
						
						printf("\n\tCIN: %s",c[pos].cin);
						printf("\n\tNOM: %s",c[pos].nom);
						printf("\n\tPRENOM: %s",c[pos].prenom);
						printf("\n\tMONTANT PRECEDENT: %.2f\n\t",c[pos].montant);
						Retrait(c,pos,retrait);
					}
					system ("pause");
					system ("cls");
            		main();
            		break;
            		
            	case (2):																							//Dépôt
            		printf("\n Entrer votre CIN: ");
            		scanf("%s",Cin);
					recherch(c,Cin,m);
					if(recherch(c,Cin,m)==-1){
						printf("\n CIN invalide!!\n");
						system ("pause");
						system ("cls");
						main();
						break;
					}
					else{
						printf("\n Entrer le montant que vous voulez deposer: ");
            			scanf("%d",&depot);
						pos=recherch(c,Cin,m);
						printf("\n\tCIN: %s",c[pos].cin);
						printf("\n\tNOM: %s",c[pos].nom);
						printf("\n\tPRENOM: %s",c[pos].prenom);
						printf("\n\tMONTANT PRECEDENT: %.2f\n",c[pos].montant);
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
					printf("\n Erreur! operateur incorrect.\n");
					system ("pause");
					system ("cls");
					main();
			}

            break;

        case (4):																			//Affichage
        	printf("\n  Choisis une option\n");
        	
            printf("\n\t1-Affichage par Ordre Ascendant");
            printf("\n\t2-Affichage par Ordre Descendant");
            printf("\n\t3-Affichage par Ordre Ascendant des comptes bancaire ayant un montant superieur a un chiffre introduit");
            printf("\n\t4-Affichage par Ordre Descendant des comptes bancaire ayant un montant superieur a un chiffre introduit");
            printf("\n\t5-Recherche par CIN");
            printf("\n\t6-Annuler\n");
            
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
						printf("\n Entrer le montant minimal: ");
						scanf("%d",&montant_min);
						aff_croi_depuix(c,montant_min,m,p);
        				
						system ("pause");
						system ("cls");
						main();
						break;

        			case (4):																						//Ordre Descendant > n
						printf("\n Entrer le montant minimal: ");
						scanf("%d",&montant_min);
						aff_decroi_depuix(c,montant_min,m,p);
        			    system ("pause");
						system ("cls");
						main();
        				break;
         			     
					case (5):																						//Recherche par CIN
        			    printf("\n Entrer le CIN dont vous voulez chercher: ");
        			    scanf("%s",Cin);
						pos=recherch(c,Cin,m);
						if(pos==-1){
							printf("\n CIN invalide!!\n");
							system ("pause");
							system ("cls");
							main();
						}
						printf("\n\tCIN: %s",c[pos].cin);
						printf("\n\tNOM: %s",c[pos].nom);
						printf("\n\tPRENOM: %s",c[pos].prenom);
						printf("\n\tMONTANT: %.2f\n",c[pos].montant);
//						printf("\n\tindice: %d",pos);
						system ("pause");
						system ("cls");
						main();
        				break;

    				case (6):
						system ("cls");
            			main();
						break;
       				 
					default:
    					printf("\n Erreur! operateur incorrect,\n");
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
        
//        case (7):
//        	afficher(c,m);
//        	break;
        	
        default:
        	printf("\n Erreur! operateur incorrect");
        	scanf("%s",sol);
			system("cls");
			main();				
    }
}


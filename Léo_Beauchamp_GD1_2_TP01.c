#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	
	//fonction random
	int a = 0;
	int b = 100;
	int rand_a_b(int a, int b){
		return rand()%(b-a) +a;
	}
	
	
	//variables
	int ptVieJoueur = 200;
	int ptVieAndre = 300;
	int action = 0;
	int tamponDefJoueur = 0;
	int tamponDefAndre = 0;
	int actionAndre = 0;
	
	//Paulo est un mage sans magie donc il n'a pas de mana.
	int nonMana = 5;
	int tamponPoisonAndre = 0;
	
	//me demandez pas pourquoi Andre fait de la magie. C'est un bouquetin magique. Voilà.
	int manaAndre = 5;
	int tamponPoisonJoueur = 0;
	
	
	
	//Début
	while(ptVieJoueur > 0 && ptVieAndre > 0){
		
		//TOUR JOUEUR
		printf("\nTour Paulo\n");
		
		//Réinitialisation de la defense et augmentation du mana.
		tamponDefJoueur=0;
		nonMana+=1;
		
		//affichage des PV et PM
		if(tamponPoisonJoueur==1){
			ptVieJoueur-=5;
		}
		printf("PV : %d\n", ptVieJoueur);
		printf("Schnaps : %d\n", nonMana);
		
		
		//Actions disponible
		printf("Tape 1 pour te defendre, 2 pour attaquer ou 3 pour empoisonner ce glandu. Tu peux aussi te soigner en appuyant sur 4, Chevreau !\n");
		scanf("%d",&action);
		
		//Vérification du choix du joueur
		while(action != 1 && action != 2 && action !=3 && action !=4){
			printf("Tape 1 pour te defendre, 2 pour attaquer ou 3 pour empoisonner ce glandu, Chevreau !\n");
			scanf("%d",&action);
		}
		
		//Def
		if(action==1){
			printf("parade cornue du Schnaps\n");
			tamponDefJoueur=1;
		}
		
		//Atq
		if(action==2){
			printf("High Kick du pif\n");
			if(tamponDefAndre==0){
				ptVieAndre-=20;
				printf("PV : %d\n", ptVieAndre);
			}else{
				ptVieAndre-=5;
				printf("PV : %d\n", ptVieAndre);
			}
		}
		
		//poison
		if(action==3){
			if(nonMana>5){
				printf ("Mange mon poisooooon \n");
					tamponPoisonAndre=1;
					nonMana-=5;
			}else{
				tamponPoisonAndre=0;
				printf ("Andre te regarde en ricannant. Tu viens de soigner son poison, boulet");
			}
		}
		
		//antidote
		if(action==4){
			if(nonMana>5){
				printf("un bon système imunitaire !\n");
				tamponPoisonJoueur=0;
				nonMana-=5;
			}else{
				tamponPoisonJoueur=1;
				printf ("Quel echec... t'es toujours empoisoné\n");
			}
		}
		
		printf("\n------------------------------------------\n");
				
		//TOUR ANDRE
		printf("\nTour Andre\n");
		
		//reinit def et Mana
		tamponDefAndre=0;
		manaAndre+=1;
		
		//Verification état poison
		if(tamponPoisonAndre==1){
			ptVieAndre-=10;
		}
		
		//affichage PV PM
		printf("PV Andre : %d\n", ptVieAndre);
		printf("mana Andre : %d\n", manaAndre);
		
		//action
		actionAndre = rand_a_b(a, b);
		
		//defense
		if (actionAndre < 29){
			printf("bêlement protecteur !\n");
			tamponDefAndre=1;
		}
		
		//Atq
		if (actionAndre > 30 && actionAndre < 89){
			printf("Coup de corne et demi !\n");
			if(tamponDefJoueur==0){
				ptVieJoueur-=20;
				printf("PV : %d\n", ptVieJoueur);
			}else{
				ptVieJoueur-=5;
				printf("PV : %d\n", ptVieJoueur);
			}
		}
		
		//Sort
		if (actionAndre> 90 && actionAndre<95){
			if(manaAndre>5){
				printf ("crachat répugnant du bouquetin sale !\n");
					tamponPoisonJoueur=1;
					manaAndre-=5;
			}else{
				tamponPoisonJoueur=0;
				printf ("Vous vous moquez d'Andre. C'est pas malin un bouquetin, il vient de vous soigner");
			}
		}
		//antidote
		if(actionAndre>95){
			if(manaAndre>5){
				printf ("guérison du caprin !\n");
				tamponPoisonAndre=0;
				manaAndre-=5;
			}else{
				tamponPoisonAndre=1;
				printf ("ouf...il a foiré son antidote\n");
			}
		}
		printf("\n------------------------------------------\n");
		
	}
}
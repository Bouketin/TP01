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
	
	
	
	//Paulo est un mage sans magie donc il n'a pas de mana. C'est le perso jouable.
	int nonMana = 5;
	int tamponPoisonAndre = 0;
	int ptVieJoueur = 200;
	int action = 0;
	int tamponDefJoueur = 0;
	
	//me demandez pas pourquoi Andre fait de la magie. C'est un bouquetin magique. Voilà. C'est l'ennemi N°1
	int manaAndre = 5;
	int tamponPoisonJoueur = 0;
	int ptVieAndre = 300;
	int tamponDefAndre = 0;
	int actionAndre = 0;
	int choixAttqAndre = 0;
	int tamponciblage = 0;
	
	//Sanguin le Paladin (ennemi)
	int manaSanguin = 5;
	int ptVieSanguin = 350;
	int tamponDefSanguin = 0;
	int actionSanguin = 0;
	int choixAttqSanguin = 0;
	
	//Jacomo le Gigolo (ennemi)
	int manaJacomo = 5;
	int ptVieJacomo = 200;
	int tamponDefJacomo = 0;
	int actionJacomo = 0;
	int choixAttqJacomo = 0;
	
	//Lélo le Chalaud (ennemi)
	int manaLelo = 5;
	int ptVieLelo = 100;
	int tamponDefLelo = 0;
	int actionLelo = 0;
	int choixAttqLelo = 0;
	
	//Frelon est le tank
	int ptVieFrelon = 250;
	int actionFrelon = 0;
	int tamponDefFrelon = 0;
	
	//Futile est la mage
	int manaFutile = 5;
	int ptVieFutile = 175;
	int actionFutile = 0;
	int tamponDefFutile = 0;
	
	//Armand est l'assassin
	int manaArmand = 5;
	int ptVieArmand = 150;
	int actionArmand = 0;
	int tamponDefArmand = 0;
	
	
	//Début
	while(ptVieJoueur > 0 && ptVieAndre > 0){
		
		//TOUR JOUEUR
		printf("\n------------------------------------------\n");
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
				printf("PV Andre : %d\n", ptVieAndre);
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
		
		//ciblage
		choixAttqAndre = rand_a_b(a, b);
			if(choixAttqAndre >80){
			tamponciblage=1;} //Paulo est visé
			
			if(choixAttqAndre > 40 && choixAttqAndre <=80){
			tamponciblage=2;} //Frelon est visé
			
			if(choixAttqAndre > 15 && choixAttqAndre <=40){
			tamponciblage=3;} //Futile est visée
			
			if(choixAttqAndre <=15){
			tamponciblage=4;} //Armand est visé
		
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
			
			if(tamponciblage==1){
				if(tamponDefJoueur==0){
					ptVieJoueur-=20;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}else{
					ptVieJoueur-=5;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}
			}
			
			if(tamponciblage==2){
				if(tamponDefFrelon==0){
					ptVieFrelon-=20;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}else{
					ptVieFrelon-=5;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}
			}
			
			if(tamponciblage==3){
				if(tamponDefFutile==0){
					ptVieFutile-=20;
					printf("PV Futile: %d\n", ptVieFutile);
				}else{
					ptVieFutile-=5;
					printf("PV Futile: %d\n", ptVieFutile);
				}
			}
			
			if(tamponciblage==4){
				if(tamponDefArmand==0){
					ptVieArmand-=25;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if(tamponDefArmand==1){
					ptVieArmand-=10;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if (tamponDefArmand==2){
					ptVieArmand-=0;
					printf("PV Armand: %d\n", ptVieArmand);
				}
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
				printf ("guerison du caprin !\n");
				tamponPoisonAndre=0;
				manaAndre-=5;
			}else{
				tamponPoisonAndre=1;
				printf ("ouf...il a foire son antidote\n");
			}
		}
		printf("\n------------------------------------------\n");
		
		//TOUR FRELON
		printf("\nTour Frelon\n");
		
		//reinit def et Mana
		tamponDefFrelon=0;
		
		//affichage PV PM
		printf("PV Frelon : %d\n", ptVieFrelon);
		if(ptVieFrelon < 100){
			printf("Frelon est en état de rage du demon !\n");
		}
		
		//action
		actionFrelon = rand_a_b(a, b);
		
		//defense
		if (actionFrelon < 49){
			printf("parade du demon ! !\n");
			tamponDefFrelon=1;
		}
		
		//capacité
		if(ptVieFrelon > 100){
			//Atq
			if (actionFrelon > 50){
				printf("dents de fer ! !\n");
				if(tamponDefAndre==0){
					ptVieAndre-=30;
					printf("PV : %d\n", ptVieAndre);
				}else{
					ptVieAndre-=10;
					printf("PV : %d\n", ptVieAndre);
				}
			}else if(ptVieFrelon < 100){
				//Atq
				if (actionFrelon > 50){
					printf("dents de fer enragées ! ! !\n");
					if(tamponDefAndre==0){
						ptVieAndre-=60;
						printf("PV Andre : %d\n", ptVieAndre);
					}else{
						ptVieAndre-=30;
						printf("PV Andre : %d\n", ptVieAndre);
					}
				}
			}
		}
			
		printf("\n------------------------------------------\n");
		
				
		//TOUR SANGUIN
		printf("\nTour Sanguin le Paladin\n");
		
		//reinit def et Mana
		tamponDefSanguin=0;
		manaSanguin+=1;
		
		//affichage PV PM
		printf("PV Sanguin : %d\n", ptVieSanguin);
		printf("mana Sanguin : %d\n", manaSanguin);
		
		//ciblage
		choixAttqSanguin = rand_a_b(a, b);
			if(choixAttqSanguin >80){
			tamponciblage=1;} //Paulo est visé
			
			if(choixAttqSanguin > 40 && choixAttqSanguin <=80){
			tamponciblage=2;} //Frelon est visé
			
			if(choixAttqSanguin > 15 && choixAttqSanguin <=40){
			tamponciblage=3;} //Futile est visée
			
			if(choixAttqSanguin <=15){
			tamponciblage=4;} //Armand est visé
		
		//action
		actionSanguin = rand_a_b(a, b);
		
		//defense
		if (actionSanguin < 29){
			printf("Bouclier du paladin !\n");
			tamponDefSanguin=1;
		}
		
		//Atq
		if (actionSanguin > 30 && actionSanguin < 89){
			printf("Petit Bonk !\n");
			
			if(tamponciblage==1){
				if(tamponDefJoueur==0){
					ptVieJoueur-=25;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}else{
					ptVieJoueur-=10;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}
			}
			
			if(tamponciblage==2){
				if(tamponDefFrelon==0){
					ptVieFrelon-=25;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}else{
					ptVieFrelon-=10;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}
			}
			
			if(tamponciblage==3){
				if(tamponDefFutile==0){
					ptVieFutile-=25;
					printf("PV Futile: %d\n", ptVieFutile);
				}else{
					ptVieFutile-=10;
					printf("PV Futile: %d\n", ptVieFutile);
				}
			}
			
			if(tamponciblage==4){
				if(tamponDefArmand==0){
					ptVieArmand-=25;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if(tamponDefArmand==1){
					ptVieArmand-=10;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if (tamponDefArmand==2){
					ptVieArmand-=0;
					printf("PV Armand: %d\n", ptVieArmand);
				}
			}
		}
		
		//Sort
		if (actionSanguin> 90 && actionSanguin){
			if(manaSanguin>5){
				printf ("BONK !\n");
					ptVieArmand-=10;
					printf("PV Armand: %d\n", ptVieArmand);
					ptVieFrelon-=10;
					printf("PV Frelon: %d\n", ptVieFrelon);
					ptVieFutile-=10;
					printf("PV Futile: %d\n", ptVieFutile);
					ptVieJoueur-=10;
					printf("PV Paulo: %d\n", ptVieJoueur);
			}
		}
		
		printf("\n------------------------------------------\n");
		//TOUR FUTILE
		printf("\nTour Futile\n");
		
		//reinit def et Mana
		tamponDefFutile=0;
		manaFutile+=2;
		
		//affichage PV PM
		printf("PV Futile : %d\n", ptVieFutile);
		printf("mana Futile : %d\n", manaFutile);
		
		//action
		actionFutile = rand_a_b(a, b);
		
		//defense
		if (actionFutile < 29){
			printf("mur de protection !\n");
			tamponDefFutile=1;
		}
		
		//Atq
		if (actionFutile >= 30 && actionFutile < 60){
			printf("telelynesie !\n");
			if(tamponDefAndre==0){
				ptVieAndre-=30;
				printf("PV : %d\n", ptVieAndre);
			}else{
				ptVieAndre-=10;
				printf("PV : %d\n", ptVieAndre);
			}
		}
		//Sort
		if (actionFutile >= 60 && actionFutile < 85){
			if(manaFutile>5){
				printf ("Malefice !\n");
					tamponPoisonAndre=1;
					manaFutile-=5;
			}else{
				tamponPoisonAndre=0;
				printf ("Futile vient de rater son malefice... elle l'a soigne");
			}
		}
		//antidote
		if(actionFutile>=85){
			if(manaFutile>5){
				printf ("Sort de guerison sur Paulo !\n");
				tamponPoisonJoueur=0;
				manaFutile-=5;
			}
		}
		
		printf("\n------------------------------------------\n");
				
		//TOUR JACOMO
		printf("\nTour Jacomo le Gigolo\n");
		
		//reinit def et Mana
		tamponDefJacomo=0;
		manaJacomo+=1;
		
		//affichage PV PM
		printf("PV Jacomo : %d\n", ptVieJacomo);
		printf("mana Jacomo : %d\n", manaJacomo);
		
		//ciblage
		choixAttqJacomo = rand_a_b(a, b);
			if(choixAttqJacomo >80){
			tamponciblage=1;} //Paulo est visé
			
			if(choixAttqJacomo > 40 && choixAttqAndre <=80){
			tamponciblage=2;} //Frelon est visé
			
			if(choixAttqJacomo > 15 && choixAttqAndre <=40){
			tamponciblage=3;} //Futile est visée
			
			if(choixAttqJacomo <=15){
			tamponciblage=4;} //Armand est visé
		
		//action
		actionAndre = rand_a_b(a, b);
		
		//defense
		if (actionJacomo < 29){
			printf("protection du styyyyle !\n");
			tamponDefAndre=1;
		}
		
		//Atq
		if (actionJacomo > 30 && actionJacomo < 89){
			printf("mépris évident !\n");
			
			if(tamponciblage==1){
				if(tamponDefJoueur==0){
					ptVieJoueur-=20;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}else{
					ptVieJoueur-=5;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}
			}
			
			if(tamponciblage==2){
				if(tamponDefFrelon==0){
					ptVieFrelon-=20;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}else{
					ptVieFrelon-=5;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}
			}
			
			if(tamponciblage==3){
				if(tamponDefFutile==0){
					ptVieFutile-=20;
					printf("PV Futile: %d\n", ptVieFutile);
				}else{
					ptVieFutile-=5;
					printf("PV Futile: %d\n", ptVieFutile);
				}
			}
			
			if(tamponciblage==4){
				if(tamponDefArmand==0){
					ptVieArmand-=25;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if(tamponDefArmand==1){
					ptVieArmand-=10;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if (tamponDefArmand==2){
					ptVieArmand-=0;
					printf("PV Armand: %d\n", ptVieArmand);
				}
			}
		}
		
		//Sort
		if (actionAndre> 90 && actionAndre<95){
			if(manaJacomo>5){
				printf ("Il est dans vos têêêêtes !\n");
					tamponPoisonJoueur=1;
					ptVieArmand-=5;
					printf("PV Armand: %d\n", ptVieArmand);
					ptVieFrelon-=5;
					printf("PV Frelon: %d\n", ptVieFrelon);
					ptVieFutile-=5;
					printf("PV Futile: %d\n", ptVieFutile);
					manaJacomo-=5;
			}
		}
		//sort2
		if(actionJacomo>95){
			if(manaJacomo>5){
				printf ("guerison générale !\n");
				tamponPoisonAndre=0;
				ptVieSanguin+=20;
				manaJacomo-=5;
			}else{
				tamponPoisonAndre=1;
				printf ("ouf...il a foire son antidote\n");
			}
		}
		
		printf("\n------------------------------------------\n");
		
		//TOUR ARMAND
		printf("\nTour Armand\n");
		
		//reinit def et Mana
		tamponDefArmand=0;
		manaArmand+=1;
		
		//affichage PV PM
		printf("PV Armand : %d\n", ptVieArmand);
		printf("mana Armand : %d\n", manaArmand);
		
		//action
		actionArmand = rand_a_b(a, b);
		
		//defense
		if (actionArmand < 29){
			printf("Lunettes de soleil protectrices !\n");
			tamponDefArmand=1;
		}
		
		//Atq
		if (actionArmand >= 30 && actionArmand < 60){
			printf("lancer de tasse !\n");
			if(tamponDefAndre==0){
				ptVieAndre-=30;
				printf("PV : %d\n", ptVieAndre);
			}else{
				ptVieAndre-=10;
				printf("PV : %d\n", ptVieAndre);
			}
		}
		//Sort
		if (actionArmand >= 60){
			if(manaArmand>5){
				printf ("Il ne fait rien de particulier\n");
					tamponDefArmand = 2;
					manaArmand-=5;
			}else{
				printf ("Il s'est fait remarquer");
			}
		}
		
		printf("\n------------------------------------------\n");
		
		//TOUR LELO
		printf("\nTour Lelo\n");
		
		//reinit def et Mana
		tamponDefLelo=0;
		manaLelo+=1;
		
		//affichage PV PM
		printf("PV Lelo : %d\n", ptVieLelo);
		printf("mana Lelo : %d\n", manaLelo);
		
		//ciblage
		choixAttqLelo = rand_a_b(a, b);
			if(choixAttqLelo >80){
			tamponciblage=1;} //Paulo est visé
			
			if(choixAttqLelo > 40 && choixAttqAndre <=80){
			tamponciblage=2;} //Frelon est visé
			
			if(choixAttqLelo > 15 && choixAttqAndre <=40){
			tamponciblage=3;} //Futile est visée
			
			if(choixAttqLelo <=15){
			tamponciblage=4;} //Armand est visé
		
		//action
		actionLelo = rand_a_b(a, b);
		
		//defense
		if (actionLelo < 29){
			printf("Feulement protecteur du felin !\n");
			tamponDefAndre=1;
		}
		
		//Atq
		if (actionLelo > 30 && actionLelo < 89){
			printf("Lelo !\n");
			
			if(tamponciblage==1){
				if(tamponDefJoueur==0){
					ptVieJoueur-=10;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}else{
					ptVieJoueur-=5;
					printf("PV Paulo: %d\n", ptVieJoueur);
				}
			}
			
			if(tamponciblage==2){
				if(tamponDefFrelon==0){
					ptVieFrelon-=10;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}else{
					ptVieFrelon-=5;
					printf("PV Frelon: %d\n", ptVieFrelon);
				}
			}
			
			if(tamponciblage==3){
				if(tamponDefFutile==0){
					ptVieFutile-=10;
					printf("PV Futile: %d\n", ptVieFutile);
				}else{
					ptVieFutile-=5;
					printf("PV Futile: %d\n", ptVieFutile);
				}
			}
			
			if(tamponciblage==4){
				if(tamponDefArmand==0){
					ptVieArmand-=10;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if(tamponDefArmand==1){
					ptVieArmand-=1;
					printf("PV Armand: %d\n", ptVieArmand);
				}else if (tamponDefArmand==2){
					ptVieArmand-=0;
					printf("PV Armand: %d\n", ptVieArmand);
				}
			}
		}
		
		//Sort
		if (actionLelo> 90 && actionLelo<99){
			if(manaLelo>5){
				printf ("insulte empoisonee !\n");
					tamponPoisonJoueur=1;
					manaLelo-=5;
			}else{
				tamponPoisonJoueur=0;
				printf ("Cette insulte ne vous atteint pas, nah !");
			}
		}
		//crash counter
		if(actionLelo>=99){
				printf (".............\n");
				ptVieArmand=0;
				printf("PV Armand: %d\n", ptVieArmand);
				ptVieFrelon=0;
				printf("PV Frelon: %d\n", ptVieFrelon);
				ptVieFutile=0;
				printf("PV Futile: %d\n", ptVieFutile);
				ptVieJoueur=1;
				printf("PV Paulo: %d\n", ptVieJoueur);
				printf("...LELO.\n");
		}
		
	}
}
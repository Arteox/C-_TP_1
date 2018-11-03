/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
void Ensemble::Afficher(void){
	cout << cardAct<<"\r\n";
	cout << cardMax<<"\r\n";
	cout <<"{";
	for (unsigned int i =0; i<cardAct; i++){
		if (i!= cardAct-1){
			cout << ens[i] <<",";
		}
		else {
			cout << ens[i];
		}
			
	}
	cout << "}" << "\r\n";
}

bool Ensemble::EstEgal(const Ensemble & unEnsemble)const{
	bool estEgal=false;
	if(cardAct==unEnsemble.cardAct){	
		for (int i=0;i<unEnsemble.cardAct;i++){
			if(ens[i]==unEnsemble.ens[i]){
			estEgal=true;	
			}else{
			estEgal=false;
			return estEgal;
			break;
			}
		}	
	}else{
		return estEgal;
	}
}

crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble)const{
	crduEstInclus inclu;
	unsigned int compteur=0;

	inclu=NON_INCLUSION;
	if (cardAct<=unEnsemble.cardAct){
	if(cardAct==unEnsemble.cardAct){
		if(this->EstEgal(unEnsemble)){
		inclu=INCLUSION_LARGE;
		}
	}else{
	for(int i=0;i<cardAct;i++){
		for(int j=0;j<unEnsemble.cardAct;j++){
			if(ens[i]==unEnsemble.ens[j]){
			compteur++;
			}
		}
	}
	}
	if(compteur==cardAct){
		inclu=NON_INCLUSION;
	}
	}

	return inclu;
}

crduAjouter Ensemble::Ajouter(int aAjouter){
	crduAjouter ajout;

	ajout=AJOUTE;

	for (int i=0;i<cardAct;i++){
		if(ens [i]==aAjouter){
		ajout=DEJA_PRESENT;
		break;
		}
	}
	if(cardAct==cardMax && ajout!=DEJA_PRESENT){
		ajout=PLEIN;
	}else if(ajout!=DEJA_PRESENT){
		ens[cardAct]=aAjouter;
		ajout=AJOUTE;
		cardAct++;
	}
	return ajout;
}

unsigned int Ensemble::Ajuster(int delta){
	int newCardMax=cardMax;

	if(delta>0){
		newCardMax=cardMax+delta;
	}
	if(delta<0){
		if(cardMax+delta>cardAct){
			newCardMax=cardMax+delta;	
		}else{
			newCardMax=cardAct;
		}
	}
	return newCardMax;
}

//----- Fin de Méthode1111

//------------------------------------------------- Surcharge d'opérateurs
Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble ( unsigned int cMax )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
    cardAct =0;
    ens = new int [cMax];
    cardMax = cMax;
} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble (int t [], unsigned int nbElements )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
    
    ens=new int[nbElements];
    cardMax=nbElements;
    cardAct = 0;
    int min;

    for (unsigned int j = 0; j <nbElements;j++){
	    for (unsigned k = 0; k<nbElements-1;k++){
		    if (t[k] > t[k+1]){
			min=t[k+1];
			t[k+1]=t[k];
			t[k]=min;
			}
		    if(t[k]==t[k+1]){
			for(int i=0;i<nbElements;i++){
			if(i>k){
				t[i]=t[i+1];
			}
		        }
			nbElements--;
	   	    }
   	    }
    }

    for (unsigned int i=0;i<nbElements;i++){
	ens[i] = t[i];
	cardAct++;
     }
} //----- Fin de Ensemble


Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
    delete [] ens;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

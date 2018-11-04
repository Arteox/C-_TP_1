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

unsigned int Ensemble::Intersection ( const Ensemble & unEnsemble )
{
	unsigned int suppr =0;
	
	for (int i =0; i<this->cardAct; i++){
		if (cardAct ==0){
			cardMax = cardAct;
			break;
		}
		if (!unEnsemble.Present(ens[i])){
			Retirer(ens[i]);
			i = -1;
			suppr++;
		}
	}
	return suppr;
}
			

int Ensemble::Reunir (const Ensemble & unEnsemble)
{
	int compteur =0;
	for (unsigned int i =0; i<unEnsemble.cardAct; i++){
		if (Present(unEnsemble.ens[i]) == false){
			if (cardAct < cardMax){
				ens[cardAct] = unEnsemble.ens[i];
				cardAct++;
				compteur++;
			} else {
				if (compteur >0){
					compteur =-compteur -1;
				}
				else {
					compteur--;
				}
				ens[cardAct] =unEnsemble.ens[i];
				cardAct++;
				cardMax = cardAct;
			}
		}
	}
	return compteur;
}

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
} //----- Fin de Méthode

unsigned int Ensemble::Retirer(const Ensemble & unEnsemble)
{
	unsigned int compteur =0;
	for (unsigned int i =0; i<unEnsemble.cardAct; i++){
		compteur = compteur +Retirer_v2(unEnsemble.ens[i]);
	}
	return compteur;
}

unsigned int Ensemble::Ajuster(int delta){
	if (delta >0){
		cardMax = cardMax+delta;
		return cardMax;
	}
	else if (delta == 0){
		return cardMax;
	}
	else{
		if (cardMax + delta >cardAct){
			cardMax = cardMax + delta;
		}
		else {
			cardMax = cardAct;
		}
		return cardMax;
	}
}

bool Ensemble::Retirer_v2 (int element){
	
	int index = -1;
	for (int i =0;i<cardAct;i++){
		if (ens[i] == element){
			index = i;
			break;
		}
	}
	if (index != -1){
		for (int j =index; j<cardAct-1;j++){
			ens[j]=ens[j+1];
		}
		cardAct--;
		//cardMax = cardAct;
		return true;
	}
	else {
		//cardMax = cardAct;
		return false;
	}
}

bool Ensemble::Retirer (int element){
	
	int index = -1;
	for (int i =0;i<cardAct;i++){
		if (ens[i] == element){
			index = i;
			break;
		}
	}
	if (index != -1){
		for (int j =index; j<cardAct-1;j++){
			ens[j]=ens[j+1];
		}
		cardAct--;
		cardMax = cardAct;
		return true;
	}
	else {
		cardMax = cardAct;
		return false;
	}
}

bool Ensemble::Present(int element) const{
	bool appartient=false;
	for (unsigned int i=0; i<this->cardAct;i++){
		if (element == this->ens[i]){
			appartient = true;
			break;
		}
	}
	return appartient;
}
	

crduAjouter Ensemble::Ajouter (int aAjouter){
	crduAjouter ajout;
	if (Present(aAjouter)==true){
		ajout = DEJA_PRESENT;
		return ajout;
	}
	else {
		if (cardAct == cardMax){
			ajout = PLEIN;
			return ajout;
		}
		else {
			ajout = AJOUTE;
			cardAct++;
			ens[cardAct-1] = aAjouter;
			return ajout;
		}
	}
}

crduEstInclus Ensemble::EstInclus (const Ensemble & unEnsemble) const
{
	bool appartient;
	crduEstInclus inclus = INCLUSION_LARGE;
	if (EstEgal(unEnsemble)==true){
		inclus = INCLUSION_LARGE;
		return inclus;
	}
	else {
		for (int i =0; i<this->cardAct;i++){
			appartient = false;
			for (int j =0; j< unEnsemble.cardAct; j++){
				if (this->ens[i] == unEnsemble.ens[j]){
					appartient = true;
				}
			}
			if (appartient == false){
				inclus = NON_INCLUSION;
				return inclus;
			}
		}
		inclus = INCLUSION_STRICTE;
		return inclus;
		
	}
}

bool Ensemble::EstEgal (const Ensemble & unEnsemble ) const
{
	bool appartient = false;
	bool egal = true;
	if (this->cardAct == unEnsemble.cardAct){
		for (int i =0; i<this->cardAct;i++){
			appartient = false;
			
			for (int j=0;j<this->cardAct;j++){
				if (this->ens[i] == unEnsemble.ens[j]){
					appartient = true;
				}
			}
			if (appartient == false){
				egal = false;
				//cout << " faux" <<egal<<"\r\n";
				return egal;
			}
		}
		
		//cout << "vrai" <<egal << "\r\n";
		return egal;
	}
	else {
		egal = false;
		//cout << " faux" <<egal<<"\r\n";
		return egal;
	}
}
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
	//cout << "Appel au constructeur de copie de <Ensemble>" << endl;
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
	//cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
	
	ens=new int[nbElements];
	cardMax=nbElements;
	cardAct = 0;
	bool doublon = false;

	for (unsigned int j = 0; j <nbElements;j++){
		for (unsigned int k =0;k<cardAct;k++){
			if (ens[k]==t[j]){
				doublon = true;
			}
		}
	
		if (doublon == false){
			ens[cardAct]=t[j];
			cardAct++;
		}
			doublon = false;
	}

	for (unsigned int i =0; i<cardAct;i++){
		for (unsigned int g =0; g<cardAct-1; g++){
			if (ens[g]>ens[g+1]){
				int temp = ens[g];
				ens[g]=ens[g+1];
				ens[g+1]=temp;
			}
		}
	}

} //----- Fin de Ensemble


Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
	//cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
	delete [] ens;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

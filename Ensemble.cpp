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
} //----- Fin de Méthode1111

//------------------------------------------------- Surcharge d'opérateurs
Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
{
} //----- Fin de operator =

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
	cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
	delete [] ens;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

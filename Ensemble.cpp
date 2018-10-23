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
    cardAct = 0;
    for (unsigned int i=0;i<nbElements;i++){
	ens[i] = t[i];
	cardAct++;
	
    }
    cardMax = nbElements;
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


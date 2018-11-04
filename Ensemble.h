/*************************************************************************
                           Ensemble  - Description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes
const unsigned  int CARD_MAX = 5;

enum crduEstInclus {NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE};
enum crduAjouter {DEJA_PRESENT, PLEIN, AJOUTE};
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	void Afficher(void);
	bool Present(int element) const;
	
	unsigned int Intersection ( const Ensemble & unEnsemble );
	int Reunir (const Ensemble & unEnsemble);
	bool Retirer_v2 (int element);
	unsigned int Retirer(const Ensemble & unEnsemble);
	bool Retirer (int element);
	unsigned int Ajuster (int delta);
	crduAjouter Ajouter(int aAjouter);
	crduEstInclus EstInclus (const Ensemble & unEnsemble) const;
	bool EstEgal (const Ensemble & unEnsemble ) const;

//------------------------------------------------- Surcharge d'opérateurs
    Ensemble & operator = ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	
//-------------------------------------------- Constructeurs - destructeur
    Ensemble ( unsigned int cMax=CARD_MAX );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ensemble (int t[], unsigned int nbElements);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	unsigned int cardMax;
	unsigned int cardAct;
	int *ens;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H


#include <iostream>
using namespace std;

#include "Ensemble.h"

int main()
{
	//second constructeur
	/*int a[]={8,8,8,4,4,7,7};
	Ensemble E(a,7);
	E.Afficher();*/
	
	//estegal
	/*int a[] = {8,5,4,6,2};
	Ensemble E(a,5);
	int b[] = {5,8,4,2};
	Ensemble E1(b,4);
	E.EstEgal(E1);*/
	
	//estinclus
	/*int a[] = {8,5,4,6};
	Ensemble E(a,4);
	int b[] = {5,8,4,2,6};
	Ensemble E1(b,5);
	cout << E.EstInclus(E1) <<"\r\n";*/
	
	//ajouter
	/*int a[] = {8,5,4,6,7,10,10};
	Ensemble E(a,7);
	E.Afficher();
	cout << E.Ajouter(11) << "\r\n";
	E.Afficher();*/
	
	//ajuster
	/*int a[] = {8,5,4,6,7,10,10};
	Ensemble E(a,7);
	E.Ajuster(-3);
	E.Afficher();*/
	
	//retirer
	/*int a[] = {8,5,4,6,7,10,10};
	Ensemble E(a,7);
	cout << "extraction : " << E.Retirer(15) <<"\r\n";
	E.Afficher();*/
	
	//retirer ens
	int a[] = {8,5,4,6,15,20};
	Ensemble E(a,6);
	int b[] = {6,4,5,20};
	Ensemble E1(b,4);
	cout << "nb d'elements retires : " <<E.Retirer(E1) <<"\r\n";
	E.Afficher();
	
	return 0;
}

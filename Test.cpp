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
	int a[] = {8,5,4,6};
	Ensemble E(a,4);
	int b[] = {5,8,4,2,6};
	Ensemble E1(b,5);
	cout << E.EstInclus(E1) <<"\r\n";
	
	return 0;
}

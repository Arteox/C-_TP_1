#include <iostream>
using namespace std;

#include "Ensemble.h"

int main()
{
	int a[]= {8,8,4,4,1,8};
	Ensemble E(a,6);
	int b[]={5,4,5,4,5,8,9,8};
	const Ensemble E1(b,8);
	E.Afficher();
	bool estegal;
	estegal=E.EstEgal(E1);
	
	if(estegal==true){
	cout<<"vrai"<<endl;
	}else{
	cout<<"faux"<<endl;
	}

	//cout<<E.EstInclus(E1)<<endl;
	//cout << E.Ajouter(3)<<endl;
	//cout<<E.Ajuster(0)<<endl;
	cout<<E.Retirer(4)<<endl;
	E.Afficher();


	return 0;
}

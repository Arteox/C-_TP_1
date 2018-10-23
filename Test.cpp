#include <iostream>
using namespace std;

#include "Ensemble.h"

int main()
{
	int a[]= {3,2,1,4};
	Ensemble E(a,4);
	E.Afficher();
	return 0;
}

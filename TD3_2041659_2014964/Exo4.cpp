#include<iostream>
#include<cmath>
#include <cstdlib>
#include <ctime>
#include<string>
#include<iomanip>

using namespace std;
int main() {
srand(time(nullptr));     
double iteration;
cout << "Entrez un nombre d'iteration: ";
cin >> iteration;
double x;
double y;
double nombrePoint = 0.0;    // compteur afin de compter le nombre de point qu'il y a dans le centre 


for (int i = 0;i < iteration;i++) {
	x = (rand() / double(RAND_MAX)) * 2 - 1;
	y = (rand() / double(RAND_MAX)) * 2 - 1;
	if (pow(x,2)+pow(y,2)<1)
	{
		 nombrePoint++;

	}

}

double z = (nombrePoint / iteration) * 4.0;
double approximation = abs((z - 3.141593));
cout.setf(ios::fixed);
cout << setprecision(6) << "L'approximation du nombre pi obtenu est de " << (nombrePoint / iteration) * 4.0 << " et l'ecart relatif avec la valeur pi donne est " << abs((z - 3.141593)) << "." << endl;


}
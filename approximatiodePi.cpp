

#include <iostream>
#include < cstdlib>
#include < ctime>
#include <math.h>
#include <iomanip>

using namespace std;

float generation_X_Hasard() {				// fonction qui genere des nombre au hasard comme // le x est eleve au carre on fait alors genere que des points positifs.
	int num;
	double numHasard;
	for (int i = 0; i < 1; i++)
	{
		num = (rand() %
			(0 - 100));
		numHasard = num / 100.0;
	}

	return numHasard;

}
float generation_Y_Hasard() {    // fonction qui genere des y // aussi, comme le y est eleve au carree alors on a decide de generer que des termes postifs.
	int num;
	double numHasard;
	for (int i = 0; i < 1; i++)
	{
		num = (rand() %
			(0 - 100));
		numHasard = num / 100.0;
	}

	return numHasard;

}




int main()
{

	int nb_Points, nb_Points_Rendu=0, nb_Points_Dans_Cercle=0;    // initialisation des compteurs qui seront utilises	// je sais que c'est un peu long comme nom, mais c'est pour etre claire.

	cout << "- Veuillez entrer le nombre d'iteration avec lesquelles Pi sera approximer : ";	// on lit le nombre d'iterations 
	cin >> nb_Points;
	cout << endl;

	float const pi_Theorique = 3.141593;

	float x_Hasard, y_Hasard, Pi_Experimental, erreur_Relative;
	

	srand(time(NULL));

	for (int i = 0; i < nb_Points ; i++)
	{
		        // initialisation a 0 a chaque fois; 
		x_Hasard = generation_X_Hasard();
		y_Hasard = generation_Y_Hasard(); 

		cout << "- x est :  " << x_Hasard << endl;
		cout << "- y est :  " << y_Hasard << endl;


		if ((pow(x_Hasard, 2.0)+ pow(y_Hasard, 2.0)<1))
		{
			nb_Points_Dans_Cercle++;						// ceci est afin de savoir combien de points qui sont a l'interieur du cercle 
		}

		nb_Points_Rendu++;					// meme si vers la fin de la boucle nb_points = nb_point_Rendu (nombre de point ou la boucle est rendu )


	}
	cout << endl << endl << endl;
	cout<<"- nombre de point dans le cercle est : "<<nb_Points_Dans_Cercle;			// ceci est le nombre de points qu'il y a dans le cercle 
	cout << endl<<endl<<endl<<endl;
	

	
	Pi_Experimental = 4.0 * (nb_Points_Dans_Cercle) / nb_Points_Rendu;					// calcul de PI

	cout << "- La valeur de PI proximee par la methode de Monte Carlo avec " << nb_Points << " iterations est de : " << fixed << setprecision(6) << Pi_Experimental << endl<<endl<<endl;   // AFFICHAGE de PI

	cout << "- La valeur de PI reelle avec une precision de 10^6 est de : 3,141593" << endl<<endl<<endl;    // valeur theorique


	erreur_Relative = Pi_Experimental - pi_Theorique;
	cout << "- L'erreur relative est de : " << fixed << setprecision(6) << abs(erreur_Relative);      //erreur relative en valeur absolue 

	 
	cout << endl << endl << endl;
}

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
static const int nombreMots = 4;
struct Dictionnaire
{
	string mot;
	string natureGenre;
	string definition;

};

int main() {
	Dictionnaire dictionnaire[nombreMots] = {};
	int a = 0;
	int b = 0;
	string motLong;
																// lecture fichier 
	ifstream fichier1("dictionnaire.txt");

															// boucle de lecture
	while (!(fichier1).eof()) {
		

			fichier1 >> dictionnaire[a].mot;
			fichier1.ignore(1);
			getline(fichier1, dictionnaire[a].natureGenre, '	');
			getline(fichier1, dictionnaire[a].definition);
			a++;
		
		
		
	}
	int taille = 0;
	int v = 0;
	while(b<4)													// boucle de traitement de donnees 
	{
		if (dictionnaire[b].mot.length() > taille) {
			taille = dictionnaire[b].mot.length();
			v = b;
			b++;
			
		}
		else
		{
			b++;
		}
		
		



	}

																					// afichage 
	cout << dictionnaire[v].mot << " " << dictionnaire[v].natureGenre << " : " << dictionnaire[v].definition;
}
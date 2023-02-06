

//---------- Réalisation de la classe <Ecriture> (fichier Ecriture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Noeud.h"
#include "Ecriture.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Ecriture::Ecrire_terminal( const vector < Noeud > & selection)
{
    for (size_t i = 0 ; i<selection.size() ; i++){
        cout<<selection[i].GetLabel()<<" ("<<selection[i].GetNombreLiens()<<" hits"<<")"<<endl ;  
    }
}



 void Ecriture::Ecrire_Graphe(Graphe graphe) 
{
	
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Ecriture::Ecriture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
} //----- Fin de Graphe


Ecriture::~Ecriture ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

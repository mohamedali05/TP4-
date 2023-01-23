/*************************************************************************
                           Graphe  -  Encapsule la structure d'un graphe orienté
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Noeud.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graphe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Graphe::AjouterLien( string Referer, string cible)
{

	if( tableLiens.count( cible) != 0 ) 
	{
		tableLiens[cible].AjouterLien(Referer);
	}
	else // Ajout du noeud avec un accès vers lui  
	{
		Noeud nouveauDoc = Noeud();
        nouveauDoc.AjouterLien(Referer) ; 
		tableLiens.emplace( cible, nouveauDoc );
		nombreNoeuds++;
	}
}


const vector < Noeud > Graphe:: TopNoeudConnectes(int n) const
// Algorithme:
// Extrait les documents de la structure pour les trier selon leur nombre d'accès puis par nom
// Utilisation d'une fonction lambda pour le tri personnalisé
// Puis extraction d'un sous vecteur de taille voulu
{
	unsigned int nbRetour = 0;
	if( n < 0 || (unsigned int)n > nombreNoeuds )
	{
		nbRetour = nombreNoeuds;
	}
	else
	{
		nbRetour = (unsigned int) n;
	}
	
	vector < Noeud > tousDocs = vector < Noeud > ( nombreNoeuds);
	unsigned int i = 0;
	for (map < string , Noeud > ::const_iterator it = tableLiens.begin(); it != tableLiens.end() ; ++ it )
	{
		tousDocs[i] = it->second;
		i++;
	}
	sort (tousDocs.begin() , tousDocs.end() ) ;  
	vector < Noeud > selection = vector < Noeud> (nbRetour);
	for (int i = 0 ; i<n ; i++){
		selection[i] = tousDocs[i] ; 
	}
	return selection;
	
}

const map < string, Noeud > & Graphe::GetStructure() 
{
	return tableLiens;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Graphe::Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
	tableLiens = map < string, Noeud >();
    nombreNoeuds = 0 ; 
} //----- Fin de Graphe


Graphe::~Graphe ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

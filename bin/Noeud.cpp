
//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Noeud::AjouterLien( string source )
{
    
    if( liens.count(source) != 0 )
    {
        liens[source]++;
    }
    else
    {
        liens.emplace( source , 1 );
    }
	nombreLiens++;
}

unsigned int Noeud::GetNombreLiens() const
{
	return nombreLiens;
}

const map < string, int > & Noeud::GetStructure() const
{
    return liens;
}

unsigned int Noeud::GetNumNoeud() const
{
    return numNoeud;
}

string Noeud::GetLabel() const
{
    return label ;
}

int Noeud::GetAccesDepuisSource( string source ) const
{
    if( liens.count( source ) != 0 )
    {
        return liens.at(source);
    }
    return -1;
}

//------------------------------------------------- Surcharge d'opérateurs



bool Noeud::operator > ( const Noeud & aComparer ) const 
{
    
    return nombreLiens > aComparer.GetNombreLiens();
    
}

bool Noeud::operator < ( const Noeud & aComparer ) const 
{
    
    return nombreLiens < aComparer.GetNombreLiens();
    
}

bool Noeud::operator == ( const Noeud & aComparer ) const 
{
    
    return nombreLiens == aComparer.GetNombreLiens();
    
}

//-------------------------------------------- Constructeurs - destructeur


Noeud::Noeud ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par defaut de <Noeud>" << endl;
#endif

    label = "Default" ; 
    nombreLiens = 0;
    numNoeud = nombreNoeuds;
    nombreNoeuds++;
    liens = map < string, int>() ;
} //----- Fin de Noeud

Noeud::Noeud (string label)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par defaut de <Noeud>" << endl;
#endif
    this->label = label ; 
    nombreLiens = 0;
    numNoeud = nombreNoeuds;
    nombreNoeuds++;
    liens = map < string, int>() ;
} //----- Fin de Noeud



Noeud::~Noeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
} //----- Fin de ~Noeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

unsigned int Noeud::nombreNoeuds = 0;
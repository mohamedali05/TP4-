
//---------- Interface de la classe <Graphe> (fichier Noeud.h) ----------------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Noeud.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//
//
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   
    void AjouterLien( string Referer, string cible ) ; 

    const vector <Noeud> TopNoeudConnectes(int n) const ; 

    const map < string, Noeud > & GetStructure() ;  


    Graphe ( );
    // Mode d'emploi : 
    // Construit un Graphe par défaut 
    

    virtual ~Graphe ( );
    // Mode d'emploi :
    // Detruit l'objet appelant
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

map < string, Noeud> tableLiens;
unsigned int nombreNoeuds;

};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // NOEUD_H


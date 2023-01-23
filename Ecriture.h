
//---------- Interface de la classe <Graphe> (fichier Noeud.h) ----------------
#if ! defined ( ECRITURE_H )
#define ECRITURE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include "Noeud.h"
#include "Graphe.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ecriture>
//
//
//------------------------------------------------------------------------

class Ecriture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   
    void Ecrire_terminal(const vector < Noeud > & selection)  ; 

    void Ecrire_Graphe(Graphe graphe) ; 

    

    Ecriture ( );
    // Mode d'emploi : 
    // Construit un Graphe par défaut 
    

    virtual ~Ecriture ( );
    // Mode d'emploi :
    // Detruit l'objet appelant
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés



};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // NOEUD_H


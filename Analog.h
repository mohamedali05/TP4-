
#if ! defined ( ANALOG_H )
#define ANALOG_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include "Lecture.h"
#include <string>
#include <map>
#include <vector>
#include "Noeud.h"
#include "Graphe.h"
#include "Ecriture.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analog>
//
//
//------------------------------------------------------------------------

//----------------------------------------------------------------- PUBLIC

//public:
//----------------------------------------------------- Méthodes publiques
    int main( int argc, char** argv );
    // Mode d'emploi : 
    // Appelé à l'éxécution du programme
    // Contrat : 
    //

//------------------------------------------------- Surcharge d'opérateurs


//------------------------------------------------------------------ PRIVE

//protected:
//----------------------------------------------------- Méthodes protégées

   
    

    bool stringEstChiffre( string );

    bool Filtre (log Doc , bool FiltreHeure , int heure , bool EnleveExtension) ; 

    bool contains (string s1 , string s2) ; 
//----------------------------------------------------- Attributs protégés

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // Analog_H


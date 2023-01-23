
//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if ! defined ( NOEUD_H )
#define NOEUD_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
//
//
//------------------------------------------------------------------------

class Noeud
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterLien( string source );
    // Mode d'emploi : 
    // Ajoute un lien du referer au doc dans la structure associée si details = true
    // Ne fait qu'incrémenter le nombre d'accès du doc sinon. 
    // Contrat :
    // Si le nom du referer a déjà été passé en paramètre de cette méthode alors il correspond au même Noeud 

    unsigned int GetNombreLiens() const;
    // Mode d'emploi : 
    // Renvoie le nombre de fois que le Noeud a été consulté
    // Contrat :

    unsigned int GetNumNoeud() const;

    
    string GetLabel() const;

    const map < string, int > & GetStructure() const;
    // Mode d'emploi :
    // Renvoie les liens encapsulés dans le Noeud
    // Contrat : 


    
    int GetAccesDepuisSource( string source ) const;
    // Mode d'emploi : 
    // Renvoie la valeur sur l'arc entre la source et le noeud si cet arc existe, -1 sinon
    // Contrat : 
    //

//------------------------------------------------- Surcharge d'opérateurs
    /*Noeud & operator = ( const Noeud & unNoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //*/
    bool operator > ( const Noeud & aComparer ) const ;
    // Mode d'emploi : 
    // Compare le Noeud courant et celui passé en paramètre par rappport à leur nombre d'accès puis par rapport à leur nom
    // Contrat : 
    // 

    bool operator < ( const Noeud & aComparer ) const ;

    bool operator == ( const Noeud & aComparer ) const ;
    
    Noeud ( );
    // Mode d'emploi : 
    // Construit un Noeud par défaut avec le nom DEFAULT
    
    Noeud (string label );

    virtual ~Noeud ( );
    // Mode d'emploi :
    // Detruit l'objet appelant
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

string label ; 
map < string, int> liens;
unsigned int nombreLiens;
unsigned int numNoeud;
static unsigned int nombreNoeuds;
};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // NOEUD_H


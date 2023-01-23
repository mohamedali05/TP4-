/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( LECTURE_H )
#define LECTURE_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct{
    unsigned int seconde ; 
    unsigned int minute ; 
    unsigned int heure ;
    unsigned int jour ; 
    unsigned int mois;
    unsigned int annee;
    bool decalagePositif;
    unsigned int heureCreneau;
    unsigned int minuteCreneau;
}Date ; 


typedef struct{
    string adresseIP;
    string nomUtilisateurAuth;
    string nomUtilisateur;
    string typeAction;
    string URL ;
    string typeDoc;
    string referer;
    string clientNav;
    Date date;
    int status, quantiteTr;
} Activite_t;




//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//
//
//------------------------------------------------------------------------

class Lecture 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    

//-------------------------------------------- Constructeurs - destructeur

    Lecture() ; 
    

    virtual ~Lecture ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};



//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LECTURE_H


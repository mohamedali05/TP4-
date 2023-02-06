

//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------
#if ! defined ( Lecture_H )
#define Lecture_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef struct{
    unsigned int sec;
    unsigned int min;
    int heure;
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;

    bool deca;
    unsigned int hCreneau;
    unsigned int mCreneau;
} Date;

typedef struct{
    string IP;
    string logname; //pas d'espace
    string username; //pas d'espace
    Date date;
    string action;
    string cible;
    string version;
    unsigned int status;
    unsigned int data;
    string referer;
    string IDnav;
}log;





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
    Lecture & operator = ( const Lecture & unLecture );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Lecture ( const Lecture & unLecture );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Lecture ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Lecture ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    log read (string cmd);
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
string partage(string & ligne);
//----------------------------------------------------- Attributs protégés
log Log;
const string nomMois[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
};


//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // Lecture_H


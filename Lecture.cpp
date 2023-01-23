/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Lecture::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Lecture & Lecture::operator = ( const Lecture & unLecture )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture ( const Lecture & unLecture )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Lecture>" << endl;
#endif
} //----- Fin de Lecture (constructeur de copie)


Lecture::Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Lecture>" << endl;
#endif
} //----- Fin de Lecture


Lecture::~Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
} //----- Fin de ~Lecture

log Lecture::read (string cmd)
// Algorithme :
//
{   
    int pos;
    string ladate,decalage,mois;
    Log. IP=partage(cmd);
    Log. logname=partage(cmd);
    Log. username=partage(cmd);

    //récupération de la date
    ladate=partage(cmd).substr(1);
    pos = ladate.find("/");
    Log. date .jour = stoi(ladate.substr(0,pos));
    ladate = ladate.substr(pos+1);

    pos = ladate.find("/");
    mois = ladate.substr(0,pos);
    int indiceMois;
    for(indiceMois = 0 ; indiceMois<12 && nomMois[indiceMois]!= mois ; indiceMois++){}// boucle vide : s'arretera quand la correspondance avec le mois aura été trouvée
    Log.date.mois = indiceMois+1;
    ladate = ladate.substr(pos+1);

    pos = ladate.find(":");
    Log. date .annee = stoi(ladate.substr(0,pos));
    ladate = ladate.substr(pos+1);

    pos = ladate.find(":");
    Log. date .heure = stoi(ladate.substr(0,pos));
    ladate = ladate.substr(pos+1);

    pos = ladate.find(":");
    Log. date .min = stoi(ladate.substr(0,pos));
    ladate = ladate.substr(pos+1);

    Log. date .sec = stoi(ladate);


    //décalage de la date
    decalage=partage(cmd);
    Log. date. deca = (decalage[0] == '+');
    decalage=decalage.substr(1);
    Log. date. hCreneau = stoi(decalage.substr(0,2));
    Log. date. mCreneau = stoi(decalage.substr(2,2));

    Log. action=partage(cmd);
    Log. action=Log. action.substr(1);
    Log. cible=partage(cmd);
    Log. version=partage(cmd);
    Log. version= Log.version.substr(0,Log.version.length()-1);
    Log. status=stoi(partage(cmd));
    Log. data=stoi(partage(cmd));
    Log. referer=partage(cmd);
    Log. referer= Log.referer.substr(0,Log.referer.length()-1);
    Log. referer= Log.referer.substr(1);
    Log. IDnav=cmd.substr(1);
    Log. IDnav=Log.IDnav.substr(0,Log.IDnav.length()-1);
    return Log;
} //----- Fin de read

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

string Lecture::partage(string & ligne)
{
    int pos = ligne.find(" ");
    string debut = ligne.substr(0,pos);
    ligne = ligne.substr(pos+1);
    return debut;
}
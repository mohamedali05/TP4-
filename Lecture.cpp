/*************************************************************************
                           LectureLog  -  Extrait les informations 
                           de lignes de logs apache
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<vector>
#include <iostream>
#include<fstream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes
const string REFERER_LOCAL = "http://intranet-if.insa-lyon.fr";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


   




Lecture::Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog


Lecture::~Lecture()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~Lecture


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


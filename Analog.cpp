/*************************************************************************
                           Analog  -  Lecture et statistiques sur des fichiers de logs apache
                             -------------------
    début                : 01/19
    copyright            : (C) 2019 par Gadacha A, Tondereau A
*************************************************************************/

//---------- Réalisation du module <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Lecture.h"

//------------------------------------------------------------- Constantes
const int NOMBRE_DOCS_DEFAUT = 10;
//----------------------------------------------------------------- PUBLIC

//---------------------------	-------------------------- Méthodes publiques
// type Analog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
int main( int argc, char ** argv)
{
    bool FaireGraphe = false ; 
    bool  EnleveExtension = false ;  
    bool FiltreHeure = false ; 
    bool ArgValides = true;

    string ArgCourant ;  
    string nom_fichier_graphe ; 
    string nom_log ; 

    int heure = 0 ; 


    for (int i = 1 ; i < argc ; i++){
        ArgCourant = argv[i]  ; 
        if (ArgCourant == "-g"){
                if (i >= argc - 2 ){
                    ArgValides = false ; 
                    
                    cerr<<"Nombre de paramètres invalides"<<endl ; 
                }else{
                    FaireGraphe = true ; 
                    nom_fichier_graphe = argv[i+1] ;
                    i++ ;  
                }
        }
        if(ArgCourant == "-e"){
            //exclure les extension 
            EnleveExtension = true ; 
        }
        if(ArgCourant == "-t"){
            //exclure ceux qui ne sont pas dans la bonne intervalle d'heure
            if (i == argc - 1){
                ArgValides = false ; 
                cerr<<"Nombre de paramètres invalides"<<endl ; 
            }else{
                    FiltreHeure = true ; 
                    heure  = stoi(argv[i+1]) ; 
                    if(heure <0 || heure >23 ){
                        cerr<<"écriture de l'heure invalide"<<endl ; 
                        ArgValides = false ; 
                    }
                    i++ ;  
                }
        }
        if (i==argc-1){
            nom_log = argv[i]  ; 
        }
    }

    cout<<"FaireGraphe : "<<FaireGraphe<<endl ; 
    cout<<"EnleveExtension : "<<EnleveExtension<<endl ; 
    cout<<"FiltreHeure : "<<FiltreHeure<<endl ; 
    cout<<"ArgValides : "<<ArgValides<<endl ; 
    cout<<"nom_fichier_graphe : "<<nom_fichier_graphe<<endl ; 
    cout<<"nom_log : "<<nom_log<<endl ; 
    cout<<"heure : "<<heure<<endl ; 

    
    return 0 ;
}
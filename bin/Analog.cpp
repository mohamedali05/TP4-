
//---------- Réalisation du module <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Analog.h"
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
    bool ajout = true ; 

    string ArgCourant ;  
    string nom_fichier_graphe ; 
    string nom_log ; 

    int heure = -1 ; 

    if (argc == 1){
        cerr<<"Le nom du fichier log n'a pas été spécifié"<<endl  ;
        return 1 ; 
    }


    for (int i = 1 ; i < argc ; i++){
        ArgCourant = argv[i]  ; 
        if (ArgCourant == "-g"){
                if (i >= argc - 2 ){
                    ArgValides = false ; 
                    cerr<<"Nombre de paramètres invalides"<<endl ; 
                }else{
                    FaireGraphe = true ; 
                    nom_fichier_graphe = argv[i+1] ;
                    if (!contains(nom_fichier_graphe, ".dot")){
                        ArgValides = false ; 
                        cerr<<"L'extension .dot n'est pas présente dans le nom du fichier graphe"<<endl ; 
                    }
                    i++ ;  
                }
        }
        else if(ArgCourant == "-e"){
            //exclure les extension 
            if (i == argc - 1){
                ArgValides = false ; 
                cerr<<"Nombre de paramètres invalides"<<endl ; 
            }else{
                EnleveExtension = true ;
            } 
        }
        else if(ArgCourant == "-t"){
            //exclure ceux qui ne sont pas dans la bonne intervalle d'heure
            if (i >= argc - 2){
                ArgValides = false ; 
                cerr<<"Nombre de paramètres invalides"<<endl ; 
            }else{
                    FiltreHeure = true ;
                    string heure_string  =  argv[i+1] ; 
                    if (stringEstChiffre( heure_string)){
                        heure  = stoi(argv[i+1]) ; 
                        if(heure <0 || heure >23 ){
                            cerr<<"écriture de l'heure invalide"<<endl ; 
                            ArgValides = false ; 
                        }
                        i++ ;  
                    }else{
                        ArgValides = false ;
                        cerr<<"L'argument 'heure' doit être un nombre"<<endl ; 
                    }
                }
        }

        else if (i==argc-1 && ArgValides){
            nom_log = argv[i]  ;

            if (!contains(nom_log , ".log")){
                ArgValides = false ; 
                cerr<<"L'extension .log n'est pas présente dans le fichier log"<<endl ; 
            } 
        }
    }


    if (!ArgValides){
        return 1 ; 
    }
    ifstream fichier ;
    fichier.open( nom_log , ios::in ); 
    string ligne = "a" ; 
    Graphe graphe ; 

    if (fichier){
        //cout<<"fichier valide"<<endl ; 

        getline(fichier, ligne)  ;
        while(fichier){
                //cout<<ligne<<endl ; 
                Lecture a  ; 
                log Doc  = a.read(ligne) ;
                //cout<<Doc.cible<<endl ;
                //cout<<contains(Doc.cible, ".jpg")<<endl ;
                ajout = Filtre(Doc , FiltreHeure ,heure ,EnleveExtension) ; 
                if (ajout){
                    graphe.AjouterLien(Doc.referer , Doc.cible) ; 
                }
                //graphe.AjouterLien(Doc.referer , Doc.cible) ; 
                getline(fichier, ligne) ;
        }
        const vector < Noeud > vecteur = graphe.TopNoeudConnectes(10) ; 
        Ecriture E ; 
        E.Ecrire_terminal(vecteur) ; 
    }else{
        cerr<<"Le fichier log indiqué n'est pas présent"<<endl ;
    }
    


    /*cout<<"FaireGraphe : "<<FaireGraphe<<endl ; 
    cout<<"EnleveExtension : "<<EnleveExtension<<endl ; 
    cout<<"FiltreHeure : "<<FiltreHeure<<endl ; 
    cout<<"ArgValides : "<<ArgValides<<endl ; 
    cout<<"nom_fichier_graphe : "<<nom_fichier_graphe<<endl ; 
    cout<<"nom_log : "<<nom_log<<endl ; 
    cout<<"heure : "<<heure<<endl ; */

    
    return 0 ;
}

bool stringEstChiffre( string chaine )
{
	for( unsigned int i = 0 ; i < chaine.size() ; i++)
  {
		if( !isdigit( chaine[i] ) )
		{
			return false;
		}
  }
	return true;
}

bool Filtre (log Doc , bool FiltreHeure , int heure , bool EnleveExtension){
    if (FiltreHeure && Doc.date.heure != heure){
        return false ; 
    }
    if (EnleveExtension && (contains(Doc.cible, ".jpg") || contains(Doc.cible, ".png") || contains(Doc.cible, ".jpeg")
    || contains(Doc.cible, ".gif") || contains(Doc.cible, ".css") || contains(Doc.cible, ".js"))){
        return false ;
    }
    return true ; 
}

bool contains (string s1 , string s2){
    if (s1.find(s2) != string::npos) {
        return true ;
    }
    return false ;
}


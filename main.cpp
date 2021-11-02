/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 28 octobre 2021, 15:47
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"
#include "Bibliographie.h"

using namespace std;
using namespace biblio;


/*
 *
 */
int
main (int argc, char** argv)
{

  string titre = "Shigley's";
  string auteur = "Richard Budynas";
  int annee = 2014;
  string ISBN = "ISBN 978-0073398204";
  string editeur = "McGraw-Hill";
  string ville = "New York";
  string ISBN2 = "ISBN 978-0831136314";

  string titre2 = "Nature";
  string auteur2 = "Aucun";
  string ISSN = "ISSN 1636-1241";
  int annee2 = 2010;
  int volume = 1;
  int numero = 10;
  int page = 292;

  Bibliographie bib;
  Ouvrage ref = Ouvrage (titre, auteur, annee, ISBN, editeur, ville);
  Journal ref2 = Journal (titre2, auteur2, annee2, ISSN, titre2,  volume, numero, page);
  Ouvrage ref3 = Ouvrage ("Machinery Handbook", "E. Oberg", annee, ISBN2, editeur, ville);
  bib.ajouterReference (ref);
  bib.ajouterReference (ref2);
  bib.ajouterReference (ref3);

  cout << bib.reqBibliographieFormate () << endl;
  int n = 1;
  bool check = n == n;

  return 0;

}


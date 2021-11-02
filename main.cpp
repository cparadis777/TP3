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
#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <iostream>
#include <string>
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

  biblio::Reference refR = biblio::Reference (titre, auteur, annee, ISBN);
  //Journal refJ = Journal (titre, auteur, annee, ISBN, "revue", 1, 1, 1);
  biblio::Journal refJ = biblio::Journal (titre, auteur, annee, ISBN, "test", 1, 1, 1);
  biblio::Ouvrage refO1 = biblio::Ouvrage (titre, auteur, annee, ISBN, editeur, ville);
  biblio::Ouvrage refO2 = biblio::Ouvrage (titre, auteur, annee, ISBN, editeur, ville);
  Reference* refJClone = refJ.clone ();
  cout << refJClone->reqAnnee () << endl;
  cout << refO1.reqReferenceFormate () << endl;
  cout << refO2.reqReferenceFormate () << endl;
  bool check = (refO1 == refR);
  cout << check << endl;

  return 0;

}


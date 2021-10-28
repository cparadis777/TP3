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
#include "validationFormat.h"
#include <iostream>
#include <string>
using namespace std;


/*
 *
 */
int
main (int argc, char** argv)
{
  string auteur = "Richard Budynas";
  bool test = util::validerFormatNom (auteur);
  bool result = test == true;
  std::cout <<  result << endl;
  biblio::Reference ("Shigley's", auteur, 2014, "ISBN 978-0073398204");
  return 0;
}


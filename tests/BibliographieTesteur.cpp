/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BibliographieTesteur.cpp
 * Author: etudiant
 *
 * Created on 2 novembre 2021, 12:10
 */

#include <stdlib.h>
#include <iostream>


/*
 * Simple C++ Test Suite
 */

void
test1 ()
{
  std::cout << "BibliographieTesteur test 1" << std::endl;
}


void
test2 ()
{
  std::cout << "BibliographieTesteur test 2" << std::endl;
  std::cout << "%TEST_FAILED% time=0 testname=test2 (BibliographieTesteur) message=error message sample" << std::endl;
}


int
main (int argc, char** argv)
{
  std::cout << "%SUITE_STARTING% BibliographieTesteur" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% test1 (BibliographieTesteur)" << std::endl;
  test1 ();
  std::cout << "%TEST_FINISHED% time=0 test1 (BibliographieTesteur)" << std::endl;

  std::cout << "%TEST_STARTED% test2 (BibliographieTesteur)\n" << std::endl;
  test2 ();
  std::cout << "%TEST_FINISHED% time=0 test2 (BibliographieTesteur)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}


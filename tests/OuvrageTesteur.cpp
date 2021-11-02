/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   OuvrageTesteur.cpp
 * Author: etudiant
 *
 * Created on 2 novembre 2021, 12:09
 */

#include <stdlib.h>
#include <iostream>


/*
 * Simple C++ Test Suite
 */

void
test1 ()
{
  std::cout << "OuvrageTesteur test 1" << std::endl;
}


void
test2 ()
{
  std::cout << "OuvrageTesteur test 2" << std::endl;
  std::cout << "%TEST_FAILED% time=0 testname=test2 (OuvrageTesteur) message=error message sample" << std::endl;
}


int
main (int argc, char** argv)
{
  std::cout << "%SUITE_STARTING% OuvrageTesteur" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% test1 (OuvrageTesteur)" << std::endl;
  test1 ();
  std::cout << "%TEST_FINISHED% time=0 test1 (OuvrageTesteur)" << std::endl;

  std::cout << "%TEST_STARTED% test2 (OuvrageTesteur)\n" << std::endl;
  test2 ();
  std::cout << "%TEST_FINISHED% time=0 test2 (OuvrageTesteur)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}


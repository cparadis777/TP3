/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ReferenceTesteur.cpp
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
  std::cout << "ReferenceTesteur test 1" << std::endl;
}


void
test2 ()
{
  std::cout << "ReferenceTesteur test 2" << std::endl;
  std::cout << "%TEST_FAILED% time=0 testname=test2 (ReferenceTesteur) message=error message sample" << std::endl;
}


int
main (int argc, char** argv)
{
  std::cout << "%SUITE_STARTING% ReferenceTesteur" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% test1 (ReferenceTesteur)" << std::endl;
  test1 ();
  std::cout << "%TEST_FINISHED% time=0 test1 (ReferenceTesteur)" << std::endl;

  std::cout << "%TEST_STARTED% test2 (ReferenceTesteur)\n" << std::endl;
  test2 ();
  std::cout << "%TEST_FINISHED% time=0 test2 (ReferenceTesteur)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}


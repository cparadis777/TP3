/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   JournalTesteur.cpp
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
  std::cout << "JournalTesteur test 1" << std::endl;
}


void
test2 ()
{
  std::cout << "JournalTesteur test 2" << std::endl;
  std::cout << "%TEST_FAILED% time=0 testname=test2 (JournalTesteur) message=error message sample" << std::endl;
}


int
main (int argc, char** argv)
{
  std::cout << "%SUITE_STARTING% JournalTesteur" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% test1 (JournalTesteur)" << std::endl;
  test1 ();
  std::cout << "%TEST_FINISHED% time=0 test1 (JournalTesteur)" << std::endl;

  std::cout << "%TEST_STARTED% test2 (JournalTesteur)\n" << std::endl;
  test2 ();
  std::cout << "%TEST_FINISHED% time=0 test2 (JournalTesteur)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}


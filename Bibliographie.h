/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bibliographie.h
 * Author: etudiant
 *
 * Created on 2 novembre 2021, 12:07
 */
#include <vector>
#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H
namespace biblio
{

  class Bibliographie
  {
  private:
    std::vector<Reference*> m_vReferences;
    bool referenceEstDejaPresente (const std::string& p_identifiant) const;

  public:
    Bibliographie ();
    ~Bibliographie ();
    void ajouterReference (const Reference& p_nouvelleReference);
    std::string reqBibliographieFormate ();
  };


}


#endif /* BIBLIOGRAPHIE_H */


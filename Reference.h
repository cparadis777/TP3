/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Reference.h
 * Author: etudiant
 *
 * Created on 30 septembre 2021, 16:00
 */



#include <string>
#ifndef REFERENCE_H
#define REFERENCE_H
namespace biblio
{

  class Reference
  {
  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
  public:
    Reference (std::string p_auteurs, std::string p_titre,
               int p_annee, std::string p_identifiant);
    std::string reqReferenceFormate ();
    void modifierAnnee (int p_nouvelleAnnee);
    std::string reqAuteurs () const;
    std::string reqTitre () const;
    int reqAnnee () const;
    std::string reqIdentifiant () const;
    friend bool operator== (const Reference& p_reference1, const Reference & p_reference2);
  };
}
#endif /* REFERENCE_H */


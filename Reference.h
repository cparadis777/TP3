/**
 * \file   Reference.h
 * \brief  Fichier contenant la déclaration de la classe Reference
 * \author Cédric Paradis
 * \version 2.0
 * \date 30 octobre 2021
 */

#include <string>
#ifndef REFERENCE_H
#define REFERENCE_H
namespace biblio
{

  class Reference
  {
  private:
    void verifieInvariant () const;
  protected:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;

  public:
    Reference (std::string p_auteurs, std::string p_titre,
               int p_annee, std::string p_identifiant);
    virtual ~Reference ();

    std::string reqAuteurs () const;
    std::string reqTitre () const;
    int reqAnnee () const;
    std::string reqIdentifiant () const;
    virtual std::string reqReferenceFormate () const;

    void asgAnnee (int p_nouvelleAnnee);
    virtual Reference* clone () const;
    friend bool operator== (const Reference& p_reference1, const Reference & p_reference2);
  };
}
#endif /* REFERENCE_H */


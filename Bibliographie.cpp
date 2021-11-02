/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <sstream>
#include <iostream>
#include "Reference.h"

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
    Bibliographie& operator = (const Bibliographie &p_bibliographie);
  } ;


  Bibliographie::Bibliographie () { };


  Bibliographie::~Bibliographie () { };


  bool
  Bibliographie::referenceEstDejaPresente (const std::string& p_identifiant) const
  {
    bool estPresente = false;
    int i = 0;
    if (m_vReferences.size () >= 1)
      {
        do
          {
            if (m_vReferences[i]->reqIdentifiant () == p_identifiant)
              {
                estPresente = true;
                break;
              }
            i = i + 1;
          }
        while ((i + 1) <= m_vReferences.size ());
      }
    return estPresente;
  };


  void
  Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {

    if (referenceEstDejaPresente (p_nouvelleReference.reqIdentifiant ()))
      {
        std::cout << "La référence ayant comme identifiant:" << std::endl;
        std::cout << p_nouvelleReference.reqIdentifiant () << std::endl;
        std::cout << "est déjà présente dans la bibliographie." << std::endl;
      }
    else
      {
        m_vReferences.push_back (p_nouvelleReference.clone ());
        std::cout << "La référence: " << std::endl;
        std::cout << p_nouvelleReference.reqReferenceFormate () << std::endl;
        std::cout << "a été ajoutée!" << std::endl;
      }

  };


  std::string
  Bibliographie::reqBibliographieFormate ()
  {
    std::ostringstream stream;
    stream << "Bibliographie" << std::endl;
    stream << "==========================" << std::endl;
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        stream << "[" << i + 1 << "] " << m_vReferences[i]->reqReferenceFormate () << std::endl;
      }

    return stream.str ();
  };


  Bibliographie& Bibliographie::operator = (const Bibliographie& p_bibliographie)
  {
    return *this;
  };
}
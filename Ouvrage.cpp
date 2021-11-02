/*!
 * \file Ouvrage.cpp
 * \brief Fichier source de la classe Ouvrage
 * \author Cédric Paradis
 * \version 1.0
 * \date 30 octobre 2021
 */


#include "Reference.h"
#include "ContratException.h"
#include <string>
#include <iostream>
#include <sstream>

namespace biblio
{

  /*!
   * \class Ouvrage
   * \brief Classe créant une référence bibliographique complète d'un ouvrage écrit.
   *
   */
  class Ouvrage : public Reference
  {

  private:
    void verifieInvariant () const;
  protected:
    std::string m_editeur;
    std::string m_ville;


  public:
    Ouvrage (std::string p_auteurs, std::string p_titre,
             int p_annee, std::string p_identifiant, std::string p_editeur, std::string p_ville); //!< \brief Constructeur de la classe Ouvrage
    ~Ouvrage ();

    std::string reqEditeur () const;
    std::string reqVille () const;

    std::string reqReferenceFormate () const override;
    Reference* clone () const override;
    friend bool operator == (const Ouvrage& p_ouvrage1, const Ouvrage & p_ouvrage2); //!< \brief Surcharge de l'opérateur == pour la classe Ouvrage


  } ;


  Ouvrage::Ouvrage (std::string p_auteurs, std::string p_titre, int p_annee, std::string p_identifiant,
                    std::string p_editeur, std::string p_ville) : Reference (p_auteurs, p_titre, p_annee, p_identifiant)
  , m_editeur (p_editeur), m_ville (p_ville)
  {

    PRECONDITION (!p_editeur.empty ());
    PRECONDITION (!p_ville.empty ());

    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);
    INVARIANTS ();
  }


  /*!
   * \fn Ouvrage::~Ouvrage ()
   * \brief Destructeur de la classe Ouvrage
   */
  Ouvrage::~Ouvrage () { }


  void
  Ouvrage::verifieInvariant () const
  {
    INVARIANT (!m_auteurs.empty ());
    INVARIANT (!m_titre.empty ());
    INVARIANT (!m_annee == 0);
    INVARIANT (!m_identifiant.empty ());
    INVARIANT (!m_editeur.empty ());
    INVARIANT (!m_ville.empty ());
  }


  /*!
   * \fn std::string Ouvrage::reqReferenceFormate()
   * \brief Méthode retournant un flux de string contenant la référence bibliographique formatée correctement.
   * \return Flux de string contenant la référence bibliographique formatée correctement.
   */

  std::string
  Ouvrage::reqReferenceFormate () const
  {
    std::ostringstream stream;
    stream << m_auteurs << ". " << m_titre << ". " << m_ville << ": " << m_editeur << ", " << m_annee <<
            ". " << m_identifiant << ".";
    POSTCONDITION (!stream.str ().empty ());
    INVARIANTS ();
    return stream.str ();
  }


  Reference*
  Ouvrage::clone () const
  {
    return new Ouvrage (*this);
  };


  /*!
   * \fn bool operator == (const Ouvrage& p_ouvrage1, const Ouvrage & p_ouvrage2)
   * \brief Surcharge de l'opérateur == pour la classe Ouvrage
   * \param p_ouvrage1 est la référence d'un objet Ouvrage
   * \param p_ouvrage2 est la référence d'un objet Ouvrage
   * \return Booléen pour l'égalité de p_ouvrage1 et p_ouvrage2
   */

  bool
  operator == (const Ouvrage& p_ouvrage1, const Ouvrage& p_ouvrage2)
  {
    return (
            (p_ouvrage1.m_titre == p_ouvrage2.m_titre) &&
            (p_ouvrage1.m_auteurs == p_ouvrage2.m_auteurs) &&
            (p_ouvrage1.m_annee == p_ouvrage2.m_annee) &&
            (p_ouvrage1.m_identifiant == p_ouvrage2.m_identifiant) &&
            (p_ouvrage1.m_editeur == p_ouvrage2.m_editeur) &&
            (p_ouvrage1.m_ville == p_ouvrage2.m_ville)
            );
  }


}
/*!
 * \file Reference.cpp
 * \brief Fichier source de la classe Reference
 * \author Cédric Paradis
 * \version 2.0
 * \date 30 octobre 2021
 */

#include <string>
#include <iostream>
#include <sstream>
#include "ContratException.h"
#include "validationFormat.h"

/*!
 * \namespace biblio
 * \brief Namespace contenant les méthodes de la class Reference.
 */
namespace biblio
{

  /*!
   * \class Reference
   * \brief Classe créant une référence bibliographique pour un ouvrage générique.
   *
   */
  class Reference
  {

  private:
    void verifieInvariant () const;

  protected:
    std::string m_auteurs;       //!< \brief Attribut contenant le nom ou les noms de l'auteur ou des auteurs de l'ouvrage
    std::string m_titre;         //!< \brief Attribut contenant le titre de l'ouvrage
    int m_annee;                 //!< \brief Attribut contenant l'année de publication de l'ouvrage
    std::string m_identifiant;   //!< \brief Attribut contenant l'identifiant ISSN ou ISBN de l'ouvrage

  public:
    Reference (std::string p_auteurs, std::string p_titre,
               int p_annee, std::string p_identifiant);                  //!< \brief Constructeur de la classe Reference
    virtual ~Reference ();                                               //!< \brief Destructeur de la classe Reference

    std::string reqAuteurs () const;                                     //!< \brief Accesseur permettant d'obtenir les auteurs de la référence
    std::string reqTitre () const;                                       //!< \brief Accesseur permettant d'obtenir le titre de la référence
    int reqAnnee () const;                                               //!< \brief Accesseur permettant d'obtenir l'année de publication de la référence
    std::string reqIdentifiant () const;                                 //!< \brief Attribut contenant l'identifiant ISSN ou ISBN de l'ouvrage

    std::string reqReferenceFormate () const;                                  //!< \brief Méthode retournant un string contenant la référence bibliographique formatée correctement.
    void asgAnnee (int p_nouvelleAnnee);                                 //!< Méthode mutatrice permettant de modifier l'année de publication de la référence bibliographique
    friend bool operator == (const Reference& p_reference1, const Reference & p_reference2); //!< \brief Surcharge de l'opérateur == pour la classe Reference
  } ;


  /*!
   * \fn Reference::Reference (std::string p_auteurs, std::string p_titre,int p_annee, std::string p_identifiant)
   * \brief Constructeur de la classe Reference
   * \param l'entrée p_auteurs est le nom ou les noms de l'auteur ou des auteurs de l'ouvrage
   * \param l'entrée p_titre est le titre de l'ouvrage.
   * \param l'entrée p_année est l'année de publication de l'ouvrage
   * \param l'entrée p_identifiant est le code ISBN ou ISSN de l'ouvrage
   * \return Objet Reference initialisé
   */

  Reference::Reference (std::string p_auteurs, std::string p_titre,
                        int p_annee, std::string p_identifiant)
  : m_auteurs (p_auteurs), m_titre (p_titre),
  m_annee (p_annee), m_identifiant (p_identifiant)
  {
    PRECONDITION (!p_auteurs.empty ());
    PRECONDITION (!p_titre.empty ());
    PRECONDITION (!p_annee == 0);
    PRECONDITION (!p_identifiant.empty ());

    POSTCONDITION (m_auteurs == p_auteurs);
    POSTCONDITION (m_titre == p_titre);
    POSTCONDITION (m_annee == p_annee);
    POSTCONDITION (m_identifiant == p_identifiant);

    INVARIANTS ();
  };


  /*!
   * \fn Reference::~Reference ()
   * \brief Destructeur de la classe Reference
   */
  Reference::~Reference () { };


  void
  Reference::verifieInvariant () const
  {
    INVARIANT (!m_auteurs.empty ());
    INVARIANT (!m_titre.empty ());
    INVARIANT (!m_annee == 0);
    INVARIANT (!m_identifiant.empty ());

  }


  /*!
   * \fn std::string Reference::reqReferenceFormate()
   * \brief Méthode retournant un flux de string contenant la référence bibliographique formatée correctement.
   * \return Flux de string contenant la référence bibliographique formatée correctement.
   */

  std::string
  Reference::reqReferenceFormate () const
  {
    std::ostringstream stream;
    stream << m_auteurs << ". " << m_titre << ". ";
    INVARIANTS ();
    return stream.str ();
  }


  /*!
   * \fn void Reference::modifierAnnee (int p_nouvelleAnnee)
   * \brief Méthode mutatrice permettant de modifier l'année de publication de la référence bibliographique
   * \param L'entrée p_nouvelleAnnee est l'année qui doit remplacer celle contenue dans la référence
   */

  void
  Reference::asgAnnee (int p_nouvelleAnnee)
  {
    PRECONDITION (!p_nouvelleAnnee == 0);
    int nouvelleAnnee = p_nouvelleAnnee;
    if (nouvelleAnnee > 0)
      {
        m_annee = p_nouvelleAnnee;
        std::cout << "L'année a été modifiée avec succès!" << std::endl;
      }
    else
      {
        std::cout << "L'année entrée est invalide. "
                "La référence n'a pas été modifiée" << std::endl;
      }
    INVARIANTS ();
  }


  /*!
   * \fn std::string Reference::reqAuteurs()
   * \brief Accesseur permettant d'obtenir les auteurs de la référence
   * \return Valeur de l'attribut m_auteurs
   */

  std::string
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /*!
   * \fn std::string Reference::reqTitre()
   * \brief Accesseur permettant d'obtenir le titre de la référence
   * \return Valeur de l'attribut m_titre
   */

  std::string
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /*!
   * \fn int Reference::reqAnnee()
   * \brief Accesseur permettant d'obtenir l'année de publication de la référence
   * \return Valeur de l'attribut m_année
   */

  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /*!
   * \fn std::string Reference::reqIdentifiant()
   * \brief Accesseur permettant d'obtenir l'identifiant de la référence
   * \return Valeur de l'attribut m_identifiant
   */
  std::string
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /*!
   * \fn bool operator == (const Reference& p_reference1, const Reference & p_reference2)
   * \brief Surcharge de l'opérateur == pour la classe Reference
   * \param p_reference1 est la référence d'un objet Reference
   * \param p_reference2 est la référence d'un objet Reference
   * \return Booléen pour l'égalité de p_reference1 et p_reference2
   */

  bool
  operator == (const Reference& p_reference1, const Reference & p_reference2)
  {
    return (
            (p_reference1.m_titre == p_reference2.m_titre) &&
            (p_reference1.m_auteurs == p_reference2.m_auteurs) &&
            (p_reference1.m_annee == p_reference2.m_annee) &&
            (p_reference1.m_identifiant == p_reference2.m_identifiant)
            );
  }


}
/*!
 * \file Reference.cpp
 * \brief Fichier source de la classe Reference
 * \author Cédric Paradis
 * \version 1.0
 * \date 30 octobre 2021
 */


#include "Reference.h"
#include "ContratException.h"
#include <string>
#include <sstream>

namespace biblio
{

  /*!
   * \class Journal
   * \brief Classe créant une référence bibliographique complète d'un article de journal.
   *
   */

  class Journal : public Reference
  {

  private:
    void verifieInvariant () const;
  protected:
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;

  public:
    Journal (std::string p_auteurs, std::string p_titre, int p_annee, std::string p_identifiant,
             std::string p_nom, int p_volume, int p_numero, int p_page);            //!< \brief Constructeur de la classe Journal
    ~Journal ();                                                                    //!< \brief Destructeur de la classe Journal

    std::string reqNom () const;                                                    //!< \brief Accesseur permettant d'obtenir le nom du journal
    int reqVolume () const;                                                         //!< \brief Accesseur permettant d'obtenir le volume du journal
    int reqNumero () const;                                                         //!< \brief Accesseur permettant d'obtenir la numero du journal
    int reqPage () const;                                                           //!< \brief Accesseur permettant d'obtenir la page de l'article

    std::string reqReferenceFormate () const override;                              //!< \brief Accesseur permettant d'obtenir la référence formatee de l'article
    Reference* clone () const override;                                             //!< \brief Methode permettant de cloner l'objet
    friend bool operator == (const Journal& p_journal1, const Journal & p_Journal2); //!< \brief Surcharge de l'opérateur == pour la classe Journal
  } ;


  Journal::Journal (std::string p_auteurs, std::string p_titre,
                    int p_annee, std::string p_identifiant, std::string p_nom, int p_volume, int p_numero, int p_page) : Reference (p_auteurs, p_titre, p_annee, p_identifiant)
  , m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {

    PRECONDITION (!p_nom.empty ());
    PRECONDITION (!p_volume == 0);
    PRECONDITION (!p_numero == 0);
    PRECONDITION (!p_page == 0);

    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_volume == p_volume);
    POSTCONDITION (m_numero == p_numero);
    INVARIANTS ();
  }


  /*!
   * \fn Journal::~Journal ()
   * \brief Destructeur de la classe Journal
   */
  Journal::~Journal () { }


  void
  Journal::verifieInvariant () const
  {
    INVARIANT (!m_auteurs.empty ());
    INVARIANT (!m_titre.empty ());
    INVARIANT (!m_annee == 0);
    INVARIANT (!m_identifiant.empty ());
    INVARIANT (!m_nom.empty ());
    INVARIANT (!m_volume == 0);
    INVARIANT (!m_numero == 0);
    INVARIANT (!m_page == 0);
  }


  /*!
   * \fn int Journal::reqNom()
   * \brief Accesseur permettant d'obtenir le nom du journal
   * \return Valeur de l'attribut m_nom
   */
  std::string
  Journal::reqNom () const
  {
    return m_nom;
  }


  /*!
   * \fn int Journal::reqVolume()
   * \brief Accesseur permettant d'obtenir le volume du journal
   * \return Valeur de l'attribut m_nom
   */
  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  /*!
   * \fn int Journal::reqVolume()
   * \brief Accesseur permettant d'obtenir le numero du journal
   * \return Valeur de l'attribut m_nom
   */
  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  /*!
   * \fn int Journal::reqPage()
   * \brief Accesseur permettant d'obtenir la page de l'article
   * \return Valeur de l'attribut m_nom
   */
  int
  Journal::reqPage () const
  {
    return m_page;
  }


  /*!
   * \fn std::string Journal::reqReferenceFormate()
   * \brief Méthode retournant un flux de string contenant la référence bibliographique formatée correctement.
   * \return Flux de string contenant la référence bibliographique formatée correctement.
   */

  std::string
  Journal::reqReferenceFormate () const
  {
    std::ostringstream stream;
    stream << m_auteurs << ", " << m_titre << ", " << m_annee <<
            ", " << m_identifiant << ".";
    POSTCONDITION (!stream.str ().empty ());
    INVARIANTS ();
    return stream.str ();
  }


  Reference *
  Journal::clone () const
  {
    return new Journal (*this);
  };


  /*!
   * \fn bool operator == (const Journal& p_journal1, const Journal & p_journal2)
   * \brief Surcharge de l'opérateur == pour la classe Journal
   * \param p_journal1 est la référence d'un objet Journal
   * \param p_journal2 est la référence d'un objet Journal
   * \return Booléen pour l'égalité de p_journal1 et p_journal2
   */

  bool
  operator == (const Journal& p_journal1, const Journal & p_journal2)
  {
    return (
            (p_journal1.m_titre == p_journal2.m_titre) &&
            (p_journal1.m_auteurs == p_journal2.m_auteurs) &&
            (p_journal1.m_annee == p_journal2.m_annee) &&
            (p_journal1.m_identifiant == p_journal2.m_identifiant) &&
            (p_journal1.m_nom == p_journal2.m_nom) &&
            (p_journal1.m_volume == p_journal2.m_volume) &&
            (p_journal1.m_numero == p_journal2.m_numero) &&
            (p_journal1.m_page == p_journal2.m_page)
            );
  }


}
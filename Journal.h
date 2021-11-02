/**
 * \file   Journal.h
 * \brief  Fichier contenant la déclaration de la classe Journal
 * \author Cédric Paradis
 * \version 1.0
 * \date 30 octobre 2021
 */
#ifndef JOURNAL_H
#define JOURNAL_H
namespace biblio
{

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
    Journal (std::string p_auteurs, std::string p_titre,
             int p_annee, std::string p_identifiant, std::string p_nom, int p_volume, int p_numero, int p_page);
    ~Journal ();

    std::string reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;
    std::string reqReferenceFormate ();

    void asgAnnee (int p_nouvelleAnnee);

    Reference* clone () const;
    friend bool operator== (const Journal& p_journal1, const Journal& p_journal2);

  };
}


#endif /* JOURNAL_H */


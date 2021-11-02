/**
 * \file   Ouvrage.h
 * \brief  Fichier contenant la déclaration de la classe Ouvrage
 * \author Cédric Paradis
 * \version 1.0
 * \date 30 octobre 2021
 */
#ifndef OUVRAGE_H
#define OUVRAGE_H
namespace biblio
{

  class Ouvrage : public Reference
  {
  private:
    void verifieInvariant () const;
  protected:
    std::string m_editeur;
    std::string m_ville;

  public:
    Ouvrage (std::string p_auteurs, std::string p_titre,
             int p_annee, std::string p_identifiant, std::string p_editeur, std::string p_ville);
    ~Ouvrage ();

    std::string reqEditeur () const;
    std::string reqVille () const;

    std::string reqReferenceFormate ();
    void asgAnnee (int p_nouvelleAnnee);

    virtual Reference* clone () const;
    friend bool operator== (const Ouvrage& p_ouvrage1, const Ouvrage& p_ouvrage2);

  };
}


#endif /* OUVRAGE_H */


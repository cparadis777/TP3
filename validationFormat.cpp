/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string>
#include <regex>
#include <iostream>

namespace util
{


  bool validerFormatNom (const std::string & p_nom)
  {
    bool validite = true;
    std::string invalide1 = "  ";
    std::string invalide2 = "--";
    std::string invalide3 = "- ";
    std::string invalide4 = " -";


    for (int i = 0; i < p_nom.size (); i++)
      {
        char lettre = p_nom[i];
        std::locale loc;

        if ((std::isalpha (lettre, loc) == false) && (lettre != '-') &&
            (isspace (lettre) == false))
          {
            validite = false;
          }
      }

    if ((p_nom.find (invalide1) != std::string::npos) ||
        (p_nom.find (invalide2) != std::string::npos) ||
        (p_nom.find (invalide3) != std::string::npos) ||
        (p_nom.find (invalide4) != std::string::npos))
      {


        validite = false;
      }
    return validite;
  }


  bool
  validerCodeIssn (const std::string & p_issn)
  {
    bool validite = false;

    std::string expreg = "ISSN \\d\\d\\d\\d-\\d\\d\\d\\d";
    const std::regex E (expreg);

    if (std::regex_match (p_issn, E))
      {
        std::string codeNumerique = p_issn.substr (5);

        codeNumerique.erase (remove (codeNumerique.begin (), codeNumerique.end (), '-'), codeNumerique.end ());
        int totalCumulatif = 0;
        int chiffreVerification = 0;

        if (codeNumerique[8] == 'X')
          {
            chiffreVerification = 10;
          }
        else
          {
            chiffreVerification = codeNumerique[7] - '0';
          }

        for (int i = 0; i < 7; i++)
          {

            int nombreCourant = codeNumerique[i] - '0';
            int multiplicateur = 8 - i;
            int resultatMultiplication = nombreCourant * multiplicateur;
            totalCumulatif = totalCumulatif + resultatMultiplication;
          }

        int modulo = totalCumulatif % 11;
        if (modulo == 0 && chiffreVerification == 0)
          {
            validite = true;
          }
        else if ((11 - modulo) == chiffreVerification)
          {
            validite = true;
          }
        else
          {


            validite = false;
          }
      }
    return validite;
  }


  bool
  validerCodeIsbn (const std::string & p_isbn)
  {
    std::string isbn = p_isbn;
    std::string isbnSansTirets = isbn;
    bool validiteGlobale = false;
    bool validiteCle = false;
    bool validiteDomaine = false;
    char tiret = '-';
    size_t position = 0;


    isbnSansTirets.erase (remove (isbnSansTirets.begin (),
                                  isbnSansTirets.end (), '-'), isbnSansTirets.end ());

    isbn = isbn.erase (0, 5);


    /*
     *  Vérification du format
     */



    std::string expreg = "ISBN 97[89]\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d";
    const std::regex E (expreg);

    if (std::regex_match (isbnSansTirets, E))
      {

        int nombreBlocs = (std::count (isbn.begin (), isbn.end (), tiret)) + 1;
        std::string blocs[nombreBlocs] {};
        std::string jeton = isbn;

        for (int i = 0; i < (nombreBlocs); i++)
          {
            position = jeton.find ("-");
            blocs[i] = jeton.substr (0, position);
            jeton = jeton.substr (position + 1, std::string::npos);
            blocs[nombreBlocs - 1] = jeton;
          }

        /*
         *  Verification du domaine
         */
        std::string domaine = blocs[1];
        int domaineInt = std::stoi (domaine);
        if (domaineInt <= 5 || domaineInt == 7)
          {
            validiteDomaine = true;
          }
        else if (domaineInt >= 80 && domaineInt <= 94)
          {
            validiteDomaine = true;
          }
        else if (domaineInt >= 600 && domaineInt <= 649)
          {
            validiteDomaine = true;
          }
        else if (domaineInt >= 950 && domaineInt <= 989)
          {
            validiteDomaine = true;
          }
        else if (domaineInt >= 9900 && domaineInt <= 9989)
          {
            validiteDomaine = true;
          }
        else if (domaineInt >= 99900 && domaineInt <= 99999)
          {
            validiteDomaine = true;
          }
        else
          {
            validiteDomaine = false;
          }

        /*
         *  Verification du chiffre de sécurité
         */
        std::string codeNumerique = isbnSansTirets;
        codeNumerique = codeNumerique.erase (0, 5);
        int totalCumulatif = 0;
        int chiffreVerification = codeNumerique[12] - '0';

        for (int i = 0; i < 12; i++)
          {
            int nombreCourant = codeNumerique[i] - '0';

            if (((i + 1) % 2) == 0)
              {
                totalCumulatif = totalCumulatif + (3 * nombreCourant);
              }
            else
              {
                totalCumulatif = totalCumulatif + (nombreCourant);
              }
          }


        int modulo = totalCumulatif % 10;
        if ((10 - modulo) == chiffreVerification)
          {
            validiteCle = true;
          }
        else
          {
            validiteCle = false;
          }

      }

    validiteGlobale = validiteDomaine && validiteCle;
    return validiteGlobale;
  }
}

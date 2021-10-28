

#include <iostream>
#include <string>
#include "validationFormat.h"
#include "Reference.h"


void
entreeUtilisateur ()
{
  std::string titre;
  std::string auteur;
  int annee;
  std::string identifiant;
  bool auteurValide = false;
  bool anneeValide = false;
  bool identifiantValide = false;

  std::cout << "Veuillez entrer le titre de l'ouvrage" << std::endl;
  std::getline (std::cin, titre);

  do
    {

      std::cout << "Veuillez entrer le nom de l'auteur ou les noms des auteurs de l'ouvrage:" << std::endl;
      std::getline (std::cin, auteur);
      auteurValide = util::validerFormatNom (auteur);
      if (auteurValide == 0)
        {
          std::cout << "Le nom de l'auteur ou les noms d'auteurs entrés sont invalides." << std::endl;
        }
    }
  while (auteurValide != 1);

  do
    {
      std::cout << "Veuillez entrer l'année de publication de l'ouvrage:" << std::endl;

      std::cin >> annee;

      if (!std::cin)
        {
          std::cout << "Veuillez entrer un nombre entier." << std::endl;
          std::cin.clear ();
        }
      else
        {
          if (annee > 0)
            {
              anneeValide = true;
            }
          else
            {
              std::cout << "L'annee de publication est invalide." << std::endl;
            }
        }
      std::cin.ignore (10000, '\n');
    }
  while (anneeValide != 1);

  do
    {
      std::cout << "Veuillez entrer le code ISSN ou ISBN de l'ouvrage:" << std::endl;

      std::getline (std::cin, identifiant);
      std::string typeIdentifiant = identifiant.substr (0, 4);

      if (typeIdentifiant == "ISBN")
        {
          if (util::validerCodeIsbn (identifiant))
            {
              identifiantValide = true;
            }
          else
            {
              std::cout << "Le code ISBN entré n'est pas valide." << std::endl;
            }
        }
      else if (typeIdentifiant == "ISSN")
        {
          if (util::validerCodeIssn (identifiant))
            {
              identifiantValide = true;
            }
          else
            {
              std::cout << "Le code ISSN entré n'est pas valide." << std::endl;
            }
        }
      else
        {
          std::cout << "L'identifiant entré n'est ni un code ISBN, ni un code ISSN." << std::endl;
        }
    }
  while (identifiantValide != 1);

  biblio::Reference reference (titre, auteur, annee, identifiant);
  std::cout << reference.reqReferenceFormate () << std::endl;
  std::string modificationAnnee;
  std::cout << "L'année de la référence est: " << reference.reqAnnee () << ". Désirez vous la modifier? O/N" << std::endl;
  std::cin >> modificationAnnee;
  if (modificationAnnee == "O")
    {
      anneeValide = false;
      do
        {
          std::cout << "Veuillez entrer l'année de publication de l'ouvrage:" << std::endl;

          std::cin >> annee;

          if (!std::cin)
            {
              std::cout << "Veuillez entrer un nombre entier." << std::endl;
              std::cin.clear ();
            }
          else
            {
              if (annee > 0)
                {
                  anneeValide = true;
                }
              else
                {
                  std::cout << "L'annee de publication est invalide." << std::endl;
                }
            }
          std::cin.ignore (10000, '\n');
        }
      while (anneeValide != 1);
      reference.modifierAnnee (annee);
      std::cout << reference.reqReferenceFormate () << std::endl;
    }
}

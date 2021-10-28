/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   validationFormat.h
 * Author: etudiant
 *
 * Created on 7 septembre 2021, 10:57
 */
#include <string>
#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
namespace util
{
  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string& p_issn);
  bool validerCodeIsbn (const std::string& p_isbn);
}
#endif /* VALIDATIONFORMAT_H */

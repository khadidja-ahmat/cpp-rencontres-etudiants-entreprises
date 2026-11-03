#include "Diplome.h"
#include <iostream>

// Constructeur paramétré
Diplome::Diplome(const std::string& c, const std::string& n, const std::string& d, const std::string& l)
    : code(c), nom(n), dateObtention(d), lieu(l) {}

// Méthode pour afficher les détails du diplôme
void Diplome::afficher() const {
    std::cout << "Diplôme : " << nom << "\n";
    std::cout << "Code : " << code << "\n";
    std::cout << "Date d'obtention : " << dateObtention << "\n";
    std::cout << "Lieu : " << lieu << "\n";
}

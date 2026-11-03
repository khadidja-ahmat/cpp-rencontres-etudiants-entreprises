#include "Experience.h"
#include <iostream>
#include <stdexcept>

// Constructeur paramétré avec validation
Experience::Experience(const std::string& debut, const std::string& fin, const std::string& ent, const std::string& fct)
    : dateDebut(debut), dateFin(fin), entreprise(ent), fonction(fct) {
    if (debut.empty() || fin.empty() || ent.empty() || fct.empty()) {
        throw std::invalid_argument("Erreur : Tous les champs doivent être renseignés.");
    }
    if (debut > fin) {
        throw std::invalid_argument("Erreur : La date de début doit être antérieure ou égale à la date de fin.");
    }
}

// Méthode pour afficher les informations de l'expérience
void Experience::afficher() const {
    std::cout << "Entreprise : " << entreprise 
              << ", Fonction : " << fonction 
              << ", De : " << dateDebut 
              << " à " << dateFin << "\n";
}

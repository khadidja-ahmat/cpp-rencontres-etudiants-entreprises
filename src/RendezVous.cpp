#include "RendezVous.h"
#include <iostream>
#include <stdexcept>

// Constructeur avec validation des horaires
RendezVous::RendezVous(const std::string& d, const std::string& hDebut, const std::string& hFin, 
                       Etudiant* e, Entreprise* ent)
    : date(d), heureDebut(hDebut), heureFin(hFin), etudiant(e), entreprise(ent) {

    if (heureDebut >= heureFin) {
        throw std::invalid_argument("Erreur : L'heure de début doit être antérieure à l'heure de fin.");
    }
    if (d.empty() || hDebut.empty() || hFin.empty()) {
        throw std::invalid_argument("Erreur : La date et les horaires doivent être renseignés.");
    }
}

// Méthode pour afficher les détails du rendez-vous
void RendezVous::afficher() const {
    std::cout << "Rendez-vous avec " << entreprise->getNom() << " le " << date 
              << " de " << heureDebut << " à " << heureFin << "\n";
    std::cout << "Étudiant : " << etudiant->getNom() << " " << etudiant->getPrenom() << "\n";
    entreprise->afficher();
}

// Vérifie si deux rendez-vous se chevauchent
bool RendezVous::conflit(const RendezVous& autre) const {
    return date == autre.date && 
           !(heureFin <= autre.heureDebut || heureDebut >= autre.heureFin);
}

#include "Etudiant.h"
#include "RendezVous.h"
#include <iomanip> // Pour std::setw et std::setfill
#include <iostream>
#include <string>

Etudiant::Etudiant(int numero, const std::string& nom, const std::string& prenom,
                   const std::string& adresse, const std::string& telephone)
    : numero(numero), nom(nom), prenom(prenom), adresse(adresse), telephone(telephone), 
      programmeActuel(""), datePremiereInscription(""), anneeInscription(0) {}

void Etudiant::afficherCV() const {
    std::cout << "\n";
    std::cout << "==========================================================\n";
    std::cout << "| " << std::setw(50) << std::left << ("CV de " + nom + " " + prenom) << "|\n";
    std::cout << "==========================================================\n";
    std::cout << "| " << std::setw(20) << std::left << "Numéro :" << numero << std::setw(28) << " " << "|\n";
    std::cout << "| " << std::setw(20) << std::left << "Adresse :" << adresse << std::setw(28) << " " << "|\n";
    std::cout << "| " << std::setw(20) << std::left << "Téléphone :" << telephone << std::setw(28) << " " << "|\n";

    if (!programmeActuel.empty()) {
        std::cout << "----------------------------------------------------------\n";
        std::cout << "| " << std::setw(50) << std::left << "Inscription actuelle" << "|\n";
        std::cout << "----------------------------------------------------------\n";
        std::cout << "| " << std::setw(20) << std::left << "Programme :" << programmeActuel << std::setw(28) << " " << "|\n";
        std::cout << "| " << std::setw(20) << std::left << "Première inscription :" << datePremiereInscription << std::setw(20) << " " << "|\n";
        std::cout << "| " << std::setw(20) << std::left << "Année :" << anneeInscription << std::setw(28) << " " << "|\n";
    }

    std::cout << "----------------------------------------------------------\n";
    std::cout << "| " << std::setw(50) << std::left << "Les diplômes obtenus" << "|\n";
    std::cout << "----------------------------------------------------------\n";
    if (diplomes.empty()) {
        std::cout << "| Aucun diplôme obtenu.                                   |\n";
    } else {
        for (const auto& diplome : diplomes) {
            diplome.afficher();
        }
    }

    std::cout << "----------------------------------------------------------\n";
    std::cout << "| " << std::setw(50) << std::left << "Les expériences acquises" << "|\n";
    std::cout << "----------------------------------------------------------\n";
    if (experiences.empty()) {
        std::cout << "| Aucune expérience professionnelle.                     |\n";
    } else {
        for (const auto& experience : experiences) {
            experience.afficher();
        }
    }

    std::cout << "==========================================================\n\n";
}

void Etudiant::ajouterDiplome(const Diplome& diplome) {
    diplomes.push_back(diplome);
}

void Etudiant::ajouterExperience(const Experience& experience) {
    experiences.push_back(experience);
}

void Etudiant::inscrireActuellement(const std::string& programme, const std::string& dateInscription, int annee) {
    programmeActuel = programme;
    datePremiereInscription = dateInscription;
    anneeInscription = annee;
}

// EtudiantPremierCycle
EtudiantPremierCycle::EtudiantPremierCycle(int numero, const std::string& nom, const std::string& prenom,
                                           const std::string& adresse, const std::string& telephone,
                                           const std::string& serieBac, int anneeObtentionBac,
                                           const std::string& lieuObtentionBac)
    : Etudiant(numero, nom, prenom, adresse, telephone),
      serieBac(serieBac), anneeObtentionBac(anneeObtentionBac), lieuObtentionBac(lieuObtentionBac) {}

void EtudiantPremierCycle::afficherCV() const {
    Etudiant::afficherCV();
    std::cout << "----------------------------------------------------------\n";
    std::cout << "| " << std::setw(50) << std::left << "Parcours secondaire" << "|\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << "| " << std::setw(20) << std::left << "Série du Bac :" << serieBac << std::setw(28) << " " << "|\n";
    std::cout << "| " << std::setw(20) << std::left << "Année d'obtention :" << anneeObtentionBac << std::setw(28) << " " << "|\n";
    std::cout << "| " << std::setw(20) << std::left << "Lieu d'obtention :" << lieuObtentionBac << std::setw(28) << " " << "|\n";
}

// EtudiantDeuxiemeCycle
EtudiantDeuxiemeCycle::EtudiantDeuxiemeCycle(int numero, const std::string& nom, const std::string& prenom,
                                             const std::string& adresse, const std::string& telephone,
                                             const std::string& disciplinePrincipale)
    : Etudiant(numero, nom, prenom, adresse, telephone), disciplinePrincipale(disciplinePrincipale) {}

void EtudiantDeuxiemeCycle::afficherCV() const {
    std::cout << "----------------------------------------------------------\n";
    std::cout << "| " << std::setw(50) << std::left << "Discipline principale" << "|\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << "| " << disciplinePrincipale << std::setw(50 - disciplinePrincipale.size()) << " " << "|\n";
    Etudiant::afficherCV();
}

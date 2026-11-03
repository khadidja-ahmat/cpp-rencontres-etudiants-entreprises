#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <string>

class Experience {
private:
    std::string dateDebut;  // Date de début de l'expérience
    std::string dateFin;    // Date de fin de l'expérience
    std::string entreprise; // Nom de l'entreprise
    std::string fonction;   // Fonction occupée

public:
    // Constructeur paramétré
    Experience(const std::string& debut, const std::string& fin, const std::string& ent, const std::string& fct);

    // Méthode pour afficher les informations de l'expérience
    void afficher() const;
};

#endif // EXPERIENCE_H

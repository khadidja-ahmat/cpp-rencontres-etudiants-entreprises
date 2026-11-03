#ifndef DIPLOME_H
#define DIPLOME_H

#include <string>

class Diplome {
private:
    std::string code;           // Code unique du diplôme
    std::string nom;            // Nom du diplôme
    std::string dateObtention;  // Date d'obtention (format attendu : YYYY-MM-DD)
    std::string lieu;           // Lieu où le diplôme a été obtenu

public:
    // Constructeur paramétré
    Diplome(const std::string& c, const std::string& n, const std::string& d, const std::string& l);

    // Méthode pour afficher les détails du diplôme
    void afficher() const;
};

#endif // DIPLOME_H

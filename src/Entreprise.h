#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include <string>
#include <stdexcept> // Pour les exceptions

class Entreprise {
private:
    std::string nom;
    std::string secteur;
    std::string adresse;
    std::string contactNom;
    std::string contactTel;

public:
    // Constructeurs
    Entreprise(); // Constructeur par défaut
    Entreprise(const std::string& n, const std::string& sec, const std::string& adr, const std::string& cNom, const std::string& cTel);

    // Getters
    std::string getNom() const;
    std::string getSecteur() const;
    std::string getAdresse() const;
    std::string getContactNom() const;
    std::string getContactTel() const;

    // Setters
    void setNom(const std::string& n);
    void setSecteur(const std::string& sec);
    void setAdresse(const std::string& adr);
    void setContactNom(const std::string& cNom);
    void setContactTel(const std::string& cTel);

    // Méthode pour afficher les informations de l'entreprise
    void afficher() const;
};

#endif // ENTREPRISE_H

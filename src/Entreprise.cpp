#include "Entreprise.h"
#include <iostream>
#include <stdexcept>

// Constructeur par défaut
Entreprise::Entreprise()
    : nom(""), secteur(""), adresse(""), contactNom(""), contactTel("") {}

// Constructeur paramétré
Entreprise::Entreprise(const std::string& n, const std::string& sec, const std::string& adr, const std::string& cNom, const std::string& cTel)
    : nom(n), secteur(sec), adresse(adr), contactNom(cNom), contactTel(cTel) {
    if (n.empty() || sec.empty() || adr.empty() || cNom.empty() || cTel.empty()) {
        throw std::invalid_argument("Erreur : Aucun des champs ne peut être vide.");
    }
}

// Getters
std::string Entreprise::getNom() const { return nom; }
std::string Entreprise::getSecteur() const { return secteur; }
std::string Entreprise::getAdresse() const { return adresse; }
std::string Entreprise::getContactNom() const { return contactNom; }
std::string Entreprise::getContactTel() const { return contactTel; }

// Setters
void Entreprise::setNom(const std::string& n) {
    if (n.empty()) {
        throw std::invalid_argument("Erreur : Le nom de l'entreprise ne peut pas être vide.");
    }
    nom = n;
}

void Entreprise::setSecteur(const std::string& sec) {
    if (sec.empty()) {
        throw std::invalid_argument("Erreur : Le secteur d'activité ne peut pas être vide.");
    }
    secteur = sec;
}

void Entreprise::setAdresse(const std::string& adr) {
    if (adr.empty()) {
        throw std::invalid_argument("Erreur : L'adresse ne peut pas être vide.");
    }
    adresse = adr;
}

void Entreprise::setContactNom(const std::string& cNom) {
    if (cNom.empty()) {
        throw std::invalid_argument("Erreur : Le nom du contact ne peut pas être vide.");
    }
    contactNom = cNom;
}

void Entreprise::setContactTel(const std::string& cTel) {
    if (cTel.empty()) {
        throw std::invalid_argument("Erreur : Le téléphone du contact ne peut pas être vide.");
    }
    contactTel = cTel;
}

// Méthode pour afficher les informations de l'entreprise
void Entreprise::afficher() const {
    std::cout << "Nom de l'entreprise : " << nom << "\n";
    std::cout << "Secteur d'activité : " << secteur << "\n";
    std::cout << "Adresse : " << adresse << "\n";
    std::cout << "Nom du contact : " << contactNom << "\n";
    std::cout << "Téléphone du contact : " << contactTel << "\n";
}

#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include "Etudiant.h"
#include "Entreprise.h"
#include <string>

class RendezVous {
private:
    std::string date;              // Date du rendez-vous (format attendu : YYYY-MM-DD)
    std::string heureDebut;        // Heure de début (format attendu : HH:MM)
    std::string heureFin;          // Heure de fin (format attendu : HH:MM)
    Etudiant* etudiant;            // Pointeur à l'étudiant participant
    Entreprise* entreprise;        // Pointeur à l'entreprise participante

public:
    // Constructeur avec validation
    RendezVous(const std::string& d, const std::string& hDebut, const std::string& hFin, 
               Etudiant* e, Entreprise* ent);

    // Méthode pour afficher les détails du rendez-vous
    void afficher() const;

    // Vérifie si deux rendez-vous sont en conflit
    bool conflit(const RendezVous& autre) const;

    // Getters pour accéder aux informations privées
    Etudiant* getEtudiant() const { return etudiant; }
    Entreprise* getEntreprise() const { return entreprise; }
    std::string getDate() const { return date; }
    std::string getHeureDebut() const { return heureDebut; }
    std::string getHeureFin() const { return heureFin; }
};

#endif // RENDEZVOUS_H

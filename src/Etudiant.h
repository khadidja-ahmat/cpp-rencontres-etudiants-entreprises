#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <string>
#include <vector>
#include <iostream>
#include "Diplome.h"
#include "Experience.h"

class Etudiant {
protected:
    int numero;
    std::string nom;
    std::string prenom;
    std::string adresse;
    std::string telephone;
    std::vector<Diplome> diplomes;
    std::vector<Experience> experiences;
    std::string programmeActuel; // Le programme actuel (ex : Licence 3)
    std::string datePremiereInscription; // Date de la première inscription
    int anneeInscription; // Année de l'inscription actuelle (ex : 3 pour la troisième année)

public:
    // Destructeur virtuel : indispensable pour supprimer correctement un
    // EtudiantPremierCycle / EtudiantDeuxiemeCycle via un pointeur Etudiant*
    virtual ~Etudiant() = default;

    // Constructeur
    Etudiant(int numero, const std::string& nom, const std::string& prenom,
             const std::string& adresse, const std::string& telephone);

    // Méthodes
    virtual void afficherCV() const;
    void inscrireActuellement(const std::string& programme, const std::string& dateInscription, int annee);
    void ajouterDiplome(const Diplome& diplome);
    void ajouterExperience(const Experience& experience);
    int getNumero() const { return numero; }

    // Accesseurs
    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }
    std::string getProgrammeActuel() const { return programmeActuel; }
    std::string getDatePremiereInscription() const { return datePremiereInscription; }
    int getAnneeInscription() const { return anneeInscription; }
};

class EtudiantPremierCycle : public Etudiant {
private:
    std::string serieBac;
    int anneeObtentionBac;
    std::string lieuObtentionBac;

public:
    // Constructeur
    EtudiantPremierCycle(int numero, const std::string& nom, const std::string& prenom,
                         const std::string& adresse, const std::string& telephone,
                         const std::string& serieBac, int anneeObtentionBac,
                         const std::string& lieuObtentionBac);

    // Méthodes
    void afficherCV() const override;
};

class EtudiantDeuxiemeCycle : public Etudiant {
private:
    std::string disciplinePrincipale;

public:
    // Constructeur
    EtudiantDeuxiemeCycle(int numero, const std::string& nom, const std::string& prenom,
                          const std::string& adresse, const std::string& telephone,
                          const std::string& disciplinePrincipale);

    // Méthodes
    void afficherCV() const override;
};

#endif // ETUDIANT_H

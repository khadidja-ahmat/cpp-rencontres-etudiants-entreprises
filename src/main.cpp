#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <memory>     // std::unique_ptr
#include <stdexcept>  // std::invalid_argument
#include "Etudiant.h"
#include "Diplome.h"
#include "Experience.h"
#include "Entreprise.h"
#include "RendezVous.h"

void afficherMenu();
void ajouterEtudiant(std::vector<std::unique_ptr<Etudiant>>& etudiants);
void ajouterEntreprise(std::vector<std::unique_ptr<Entreprise>>& entreprises);
void creerRendezVous(std::vector<RendezVous>& rendezVousList, const std::vector<std::unique_ptr<Etudiant>>& etudiants, const std::vector<std::unique_ptr<Entreprise>>& entreprises);
void afficherInformations(const std::vector<std::unique_ptr<Etudiant>>& etudiants, const std::vector<std::unique_ptr<Entreprise>>& entreprises, const std::vector<RendezVous>& rendezVousList);
void afficherRendezVousParEtudiant(const std::vector<RendezVous>& rendezVousList, const std::vector<std::unique_ptr<Etudiant>>& etudiants);
void afficherRendezVousParEntreprise(const std::vector<RendezVous>& rendezVousList);

int main() {
    // unique_ptr : les étudiants (de types différents) sont détruits automatiquement,
    // et les adresses restent stables même quand le vector grandit.
    std::vector<std::unique_ptr<Etudiant>> etudiants;
    std::vector<std::unique_ptr<Entreprise>> entreprises;
    std::vector<RendezVous> rendezVousList;

    int choix;

    do {
        afficherMenu();

        // Demander à l'utilisateur de faire un choix valide pour le menu
        while (!(std::cin >> choix) || choix < 0 || choix > 6) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Choix invalide, veuillez réessayer : ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Les constructeurs valident les données et lancent une exception si elles
        // sont invalides : on l'attrape ici pour revenir au menu sans planter.
        try {
            switch (choix) {
                case 1:
                    ajouterEtudiant(etudiants);
                    break;
                case 2:
                    ajouterEntreprise(entreprises);
                    break;
                case 3:
                    creerRendezVous(rendezVousList, etudiants, entreprises);
                    break;
                case 4:
                    afficherInformations(etudiants, entreprises, rendezVousList);
                    break;
                case 5:
                    afficherRendezVousParEtudiant(rendezVousList, etudiants);
                    break;
                case 6:
                    afficherRendezVousParEntreprise(rendezVousList);
                    break;
                case 0:
                    std::cout << "Au revoir !\n";
                    break;
                default:
                    std::cout << "Choix incorrect, réessayez.\n";
                    break;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << "\n";
        }
    } while (choix != 0);

    // Pas de nettoyage manuel : les unique_ptr libèrent la mémoire tout seuls.
    return 0;
}

void afficherMenu() {
    std::cout << "\n================ MENU =================\n";
    std::cout << "1. Ajouter un étudiant\n";
    std::cout << "2. Ajouter une entreprise\n";
    std::cout << "3. Créer un rendez-vous\n";
    std::cout << "4. Afficher les informations\n";
    std::cout << "5. Afficher les rendez-vous d'un étudiant triés\n";
    std::cout << "6. Afficher les rendez-vous de toutes les entreprises triés\n";
    std::cout << "0. Quitter\n";
    std::cout << "======================================\n";
    std::cout << "Votre choix : ";
}

void ajouterEtudiant(std::vector<std::unique_ptr<Etudiant>>& etudiants) {
    int choixType;
    std::cout << "Catégorie d'étudiant :\n";
    std::cout << "1. Étudiant de Premier Cycle\n";
    std::cout << "2. Étudiant de Deuxième Cycle\n";
    std::cout << "Votre choix : ";

    // Demander à l'utilisateur de faire un choix valide pour le type d'étudiant
    while (!(std::cin >> choixType) || (choixType != 1 && choixType != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Choix invalide, veuillez réessayer : ";
    }
    std::cin.ignore();

    // Saisie des informations générales
    int numero;
    std::string nom, prenom, adresse, telephone;

    std::cout << "Numéro étudiant : ";
    while (!(std::cin >> numero)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Veuillez entrer un numéro valide : ";
    }
    std::cin.ignore();

    std::cout << "Nom : ";
    std::getline(std::cin, nom);

    std::cout << "Prénom : ";
    std::getline(std::cin, prenom);

    std::cout << "Adresse : ";
    std::getline(std::cin, adresse);

    std::cout << "Numéro de téléphone : ";
    std::getline(std::cin, telephone);

    // Création de l'étudiant selon le type
    std::unique_ptr<Etudiant> etudiant;
    if (choixType == 1) {
        std::string serieBac, lieuBac;
        int anneeBac;

        std::cout << "Série du Bac : ";
        std::getline(std::cin, serieBac);

        std::cout << "Année d'obtention du Bac : ";
        while (!(std::cin >> anneeBac)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Veuillez entrer une année valide : ";
        }
        std::cin.ignore();

        std::cout << "Lieu d'obtention du Bac : ";
        std::getline(std::cin, lieuBac);

        etudiant = std::make_unique<EtudiantPremierCycle>(numero, nom, prenom, adresse, telephone, serieBac, anneeBac, lieuBac);
    } else if (choixType == 2) {
        std::string discipline;

        std::cout << "Discipline principale : ";
        std::getline(std::cin, discipline);

        etudiant = std::make_unique<EtudiantDeuxiemeCycle>(numero, nom, prenom, adresse, telephone, discipline);
    }

    // Demande d'inscription actuelle
    char inscrireActuellement;
    std::cout << "L'étudiant a-t-il une inscription actuelle ? (o/n) : ";
    std::cin >> inscrireActuellement;
    std::cin.ignore();

    if (inscrireActuellement == 'o' || inscrireActuellement == 'O') {
        std::string programme, dateInscription;
        int anneeInscription;

        std::cout << "Inscription actuelle dans un diplôme : ";
        std::getline(std::cin, programme);

        std::cout << "Date de première inscription (ex: 2024-09-01) : ";
        std::getline(std::cin, dateInscription);

        std::cout << "Numéro de l'année (ex : 3 pour 3ème année de licence) : ";
        while (!(std::cin >> anneeInscription)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Veuillez entrer une année valide : ";
        }

        etudiant->inscrireActuellement(programme, dateInscription, anneeInscription);
    }

    // Ajout des diplômes
    char ajouterDiplome;
    do {
        std::cout << "\nVoulez-vous ajouter un diplôme ? (o/n) : ";
        std::cin >> ajouterDiplome;
        std::cin.ignore();
        if (ajouterDiplome == 'o' || ajouterDiplome == 'O') {
            std::string code, nomDiplome, date, lieu;

            std::cout << "Code du diplôme : ";
            std::getline(std::cin, code);

            std::cout << "Nom national du diplôme : ";
            std::getline(std::cin, nomDiplome);

            std::cout << "Date d'obtention du diplôme: ";
            std::getline(std::cin, date);

            std::cout << "Lieu d'obtention du diplôme: ";
            std::getline(std::cin, lieu);

            etudiant->ajouterDiplome(Diplome(code, nomDiplome, date, lieu));
        }
    } while (ajouterDiplome == 'o' || ajouterDiplome == 'O');

    // Ajout des expériences professionnelles
    char ajouterExperience;
    do {
        std::cout << "\nVoulez-vous ajouter une expérience professionnelle ? (o/n) : ";
        std::cin >> ajouterExperience;
        std::cin.ignore();
        if (ajouterExperience == 'o' || ajouterExperience == 'O') {
            std::string dateDebut, dateFin, entreprise, fonction;

            std::cout << "Date de début (format AAAA-MM-JJ) : ";
            std::getline(std::cin, dateDebut);

            std::cout << "Date de fin (format AAAA-MM-JJ) : ";
            std::getline(std::cin, dateFin);

            // Validation des dates
            if (dateDebut > dateFin) {
                std::cerr << "Erreur : La date de début doit être antérieure ou égale à la date de fin.\n";
                continue;
            }

            std::cout << "Entreprise : ";
            std::getline(std::cin, entreprise);

            std::cout << "Fonction : ";
            std::getline(std::cin, fonction);

            etudiant->ajouterExperience(Experience(dateDebut, dateFin, entreprise, fonction));
        }
    } while (ajouterExperience == 'o' || ajouterExperience == 'O');

    etudiants.push_back(std::move(etudiant));

    std::cout << "Étudiant ajouté avec succès !\n";
}

void ajouterEntreprise(std::vector<std::unique_ptr<Entreprise>>& entreprises) {
    std::string nom, adresse, secteur, contactNom, contactTel;

    std::cout << "\nNom de l'entreprise : ";
    std::getline(std::cin, nom);

    std::cout << "Secteur d'activité : ";
    std::getline(std::cin, secteur);

    std::cout << "Adresse de l'entreprise : ";
    std::getline(std::cin, adresse);

    std::cout << "Nom du contact : ";
    std::getline(std::cin, contactNom);

    std::cout << "Téléphone du contact : ";
    std::getline(std::cin, contactTel);

    entreprises.push_back(std::make_unique<Entreprise>(nom, secteur, adresse, contactNom, contactTel));
}

void creerRendezVous(std::vector<RendezVous>& rendezVousList, const std::vector<std::unique_ptr<Etudiant>>& etudiants, const std::vector<std::unique_ptr<Entreprise>>& entreprises) {
    if (etudiants.empty() || entreprises.empty()) {
        std::cout << "Ajoutez au moins un étudiant et une entreprise avant de créer un rendez-vous.\n";
        return;
    }

    std::string date, heureDebut, heureFin;
    size_t choixEtudiant, choixEntreprise;

    std::cout << "Date (AAAA-MM-JJ) : ";
    std::getline(std::cin, date);

    std::cout << "Heure de début (HH:MM) : ";
    std::getline(std::cin, heureDebut);

    std::cout << "Heure de fin (HH:MM) : ";
    std::getline(std::cin, heureFin);

    std::cout << "Sélectionnez un étudiant :\n";
    for (size_t i = 0; i < etudiants.size(); ++i) {
        std::cout << i + 1 << ". " << etudiants[i]->getNom() << " " << etudiants[i]->getPrenom() << "\n";
    }
    while (!(std::cin >> choixEtudiant) || choixEtudiant < 1 || choixEtudiant > etudiants.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Choix invalide, veuillez réessayer : ";
    }

    std::cout << "Sélectionnez une entreprise :\n";
    for (size_t i = 0; i < entreprises.size(); ++i) {
        std::cout << i + 1 << ". " << entreprises[i]->getNom() << "\n";
    }
    while (!(std::cin >> choixEntreprise) || choixEntreprise < 1 || choixEntreprise > entreprises.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Choix invalide, veuillez réessayer : ";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Le constructeur de RendezVous valide les horaires (exception si invalides)
    RendezVous nouveau(date, heureDebut, heureFin,
                       etudiants[choixEtudiant - 1].get(), entreprises[choixEntreprise - 1].get());

    // Vérification des conflits d'horaires : l'étudiant et l'entreprise
    // ne peuvent pas avoir deux rendez-vous qui se chevauchent.
    for (const auto& rdv : rendezVousList) {
        bool memeParticipant = rdv.getEtudiant() == nouveau.getEtudiant()
                            || rdv.getEntreprise() == nouveau.getEntreprise();
        if (memeParticipant && rdv.conflit(nouveau)) {
            std::cout << "Conflit d'horaires avec un rendez-vous existant : rendez-vous refusé.\n";
            return;
        }
    }

    rendezVousList.push_back(nouveau);
    std::cout << "Rendez-vous créé avec succès !\n";
}

void afficherInformations(const std::vector<std::unique_ptr<Etudiant>>& etudiants, const std::vector<std::unique_ptr<Entreprise>>& entreprises, const std::vector<RendezVous>& rendezVousList) {
    std::cout << "\nListe des étudiants :\n";
    for (const auto& etudiant : etudiants) {
        etudiant->afficherCV();
    }

    std::cout << "\nListe des entreprises :\n";
    for (const auto& entreprise : entreprises) {
        entreprise->afficher();
    }

    std::cout << "\nListe des rendez-vous :\n";
    for (const auto& rdv : rendezVousList) {
        rdv.afficher();
    }
}

// Afficher les rendez-vous d'un étudiant triés par date et heure
void afficherRendezVousParEtudiant(const std::vector<RendezVous>& rendezVousList, const std::vector<std::unique_ptr<Etudiant>>& etudiants) {
    for (const auto& etudiant : etudiants) {
        std::cout << "Rendez-vous pour " << etudiant->getNom() << " " << etudiant->getPrenom() << " (N°" << etudiant->getNumero() << "):\n";

        // Filtrer les rendez-vous pour cet étudiant
        std::vector<RendezVous> filteredRendezVous;
        for (const auto& rdv : rendezVousList) {
            if (rdv.getEtudiant() == etudiant.get()) {
                filteredRendezVous.push_back(rdv);
            }
        }

        // Tri des rendez-vous par date et heure
        std::sort(filteredRendezVous.begin(), filteredRendezVous.end(), [](const RendezVous& rdv1, const RendezVous& rdv2) {
            if (rdv1.getDate() == rdv2.getDate()) {
                return rdv1.getHeureDebut() < rdv2.getHeureDebut();
            }
            return rdv1.getDate() < rdv2.getDate();
        });

        // Afficher les rendez-vous triés
        for (const auto& rdv : filteredRendezVous) {
            rdv.afficher();
        }
    }
}

void afficherRendezVousParEntreprise(const std::vector<RendezVous>& rendezVousList) {
    std::cout << "\nRendez-vous triés par entreprise :\n";

    // Trier les rendez-vous par entreprise, puis par date et heure
    std::vector<RendezVous> sortedRdv = rendezVousList;
    std::sort(sortedRdv.begin(), sortedRdv.end(), [](const RendezVous& rdv1, const RendezVous& rdv2) {
    if (rdv1.getEntreprise()->getNom() == rdv2.getEntreprise()->getNom()) {
            return rdv1.getDate() < rdv2.getDate() || (rdv1.getDate() == rdv2.getDate() && rdv1.getHeureDebut() < rdv2.getHeureDebut());
        }
        return rdv1.getEntreprise()->getNom() < rdv2.getEntreprise()->getNom();
    });

    for (const auto& rdv : sortedRdv) {
        rdv.afficher();
    }
}

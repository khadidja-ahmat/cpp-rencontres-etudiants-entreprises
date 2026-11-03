# Rencontres Étudiants-Entreprises (C++)

Application console en **C++** pour gérer des rencontres entre étudiants et entreprises : fiches étudiants (CV), entreprises et rendez-vous, avec vérification des conflits d'horaires.

Projet réalisé en binôme en Licence 3 Informatique (Université de Limoges, année 2024-2025), dans le cadre du cours d'Analyse et Programmation Orientées Objets.

## Fonctionnalités

- Ajout d'étudiants de **premier cycle** (parcours secondaire : bac) ou de **deuxième cycle** (discipline principale), avec diplômes, expériences professionnelles et inscription actuelle.
- Ajout d'entreprises (secteur, adresse, contact).
- Création de rendez-vous entre un étudiant et une entreprise, avec **détection des chevauchements d'horaires**.
- Affichage des CV, des entreprises et des rendez-vous, **triés** par étudiant ou par entreprise (date puis heure).
- Validation des saisies (exceptions `std::invalid_argument`).

## Notions de C++ utilisées

- Programmation orientée objet : classes, **héritage** (`EtudiantPremierCycle` et `EtudiantDeuxiemeCycle` héritent d'`Etudiant`), **polymorphisme** (`virtual` / `override`, destructeur virtuel).
- Gestion de la mémoire moderne : `std::unique_ptr` / `std::make_unique`.
- Bibliothèque standard : `std::vector`, `std::string`, `std::sort` avec fonctions lambda.
- Exceptions, séparation en fichiers `.h` / `.cpp`.

## Structure

```
src/
  main.cpp        menu et saisies
  Etudiant.*      Etudiant, EtudiantPremierCycle, EtudiantDeuxiemeCycle
  Diplome.*       diplômes d'un étudiant
  Experience.*    expériences professionnelles
  Entreprise.*    entreprises
  RendezVous.*    rendez-vous et détection de conflits
docs/
  rapport-projet-cpp.pdf   rapport du projet (analyse du besoin, diagramme de classes UML)
```

## Compiler et lancer

Il faut un compilateur C++17 (g++).

```bash
make
./rencontres
```

Sans `make` :

```bash
g++ -std=c++17 -o rencontres src/*.cpp
```

## Ma contribution

(à compléter : par exemple les classes que tu as écrites, le diagramme UML, la partie rapport…)

## Auteurs

- Khadidja Ahmat Hassan
- Djibrine Moustapha Mahamat

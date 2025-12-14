# Système de Régulateur de Vitesse Adaptatif (ACC) - AUTOSAR

Ce projet présente la conception et la simulation d'un **Adaptive Cruise Control (ACC)** utilisant l'architecture **AUTOSAR** sous MATLAB/Simulink. Le cœur du système repose sur une machine d'états **Stateflow** pour gérer la logique de décision.

## 📋 Description du Projet
Le système ajuste automatiquement la vitesse du véhicule pour maintenir une distance de sécurité avec le véhicule précédent. Il opère selon deux modes principaux :
1.  **Cruising Mode :** Maintien de la vitesse de consigne (route libre).
2.  **Following Mode :** Adaptation de la vitesse pour suivre le véhicule précédent (présence d'obstacle).

## 🛠️ Architecture Technique
*   **Environnement :** MATLAB / Simulink R2024b
*   **Logique de contrôle :** Stateflow (Machine d'états finis)
*   **Standard :** AUTOSAR (Code Generation: `autosar.tlc`)
*   **Interface :** Dashboard Simulink interactif

## 🧠 Logique de Contrôle (Stateflow)
Le système est piloté par un diagramme d'états (`ACC_Logic`) comprenant trois états principaux :

| État | Description | Actions Principales |
| :--- | :--- | :--- |
| **OFF** | Système désactivé | `Accel_Req = 0`, `Brake_Req = 0` |
| **CRUISING** | Route dégagée | Régulation P-Control : `Accel_Req = (Set - Current) * 2` |
| **FOLLOWING** | Obstacle détecté | Freinage actif : `Brake_Req = 1`, `Accel_Req = 0` |

### Conditions de transition (Logique d'hystérésis)
*   **Activation :** `Switch_ACC == 1`
*   **Détection Obstacle :** Passage en mode *Following* si `Radar_Dist < 50m`.
*   **Retour en Cruising :** Passage en mode *Cruising* si `Radar_Dist > 60m` (Marge de sécurité pour éviter les oscillations).

## 🎮 Simulation et Dashboard
Un tableau de bord interactif a été intégré au modèle pour tester le système en temps réel sans écrire de code.

### Entrées (Commandes)
*   **Switch ACC :** Interrupteur ON/OFF.
*   **Set Speed (Knob) :** Vitesse souhaitée par le conducteur (0-200 km/h).
*   **Current Speed (Knob) :** Vitesse actuelle du véhicule (simulation physique).
*   **Radar Distance (Slider) :** Simulation de la distance avec l'obstacle (0-255 m).

### Sorties (Visualisation)
*   **Jauge d'Accélération :** Visualise la demande de couple moteur (`Accel_Req`).
*   **Lampe de Freinage :** S'allume (Rouge) en cas de freinage d'urgence.
*   **État du Système (LED) :**
    *   ⚪ Gris : OFF
    *   🟢 Vert : Mode Cruising
    *   🟠 Orange : Mode Following

## 🚀 Guide d'installation et de test
1.  Clonez ce dépôt :
    ```bash
    git clone https://github.com/wafaguizani/Adaptive-Cruise-Control.git
    ```
2.  Ouvrez MATLAB et chargez le fichier **`ACC_System.slx`**.
3.  Lancez la simulation (bouton **Run**).
4.  Manipulez les boutons du Dashboard :
    *   Activez le Switch.
    *   Simulez un obstacle proche (< 50m) avec le slider "Radar" pour voir le système freiner.
    *   Eloignez l'obstacle (> 60m) pour voir le système ré-accélérer.

## 📄 Génération de Code (AUTOSAR)
Le modèle est configuré pour la génération de code automatique conforme au standard AUTOSAR :
*   **System Target File :** `autosar.tlc`
*   Les composants logiciels (Software Components) et les interfaces sont mappés via l'outil **AUTOSAR Component Designer**.

---
*Projet réalisé par Wafa Guizani.*

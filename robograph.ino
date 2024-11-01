#include <LiquidCrystal.h>

// Définition des broches
const int leftMotorForward = 5;   // Broche pour moteur gauche en avant
const int leftMotorBackward = 6;  // Broche pour moteur gauche en arrière
const int rightMotorForward = 9;  // Broche pour moteur droit en avant
const int rightMotorBackward = 10; // Broche pour moteur droit en arrière

const int leftSensor = 0;        // Broche pour le capteur gauche (A0)
const int rightSensor = 1;       // Broche pour le capteur droit (A1)

// Initialisation de l'écran LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // (RS, E, D4, D5, D6, D7)

// Variables pour le chemin
String path = "";

void setup() {
    // Initialiser les broches comme sorties
    pinMode(leftMotorForward, OUTPUT);
    pinMode(leftMotorBackward, OUTPUT);
    pinMode(rightMotorForward, OUTPUT);
    pinMode(rightMotorBackward, OUTPUT);
    
    // Initialiser les capteurs
    pinMode(leftSensor, INPUT);
    pinMode(rightSensor, INPUT);
    
    // Initialiser l'écran LCD
    lcd.begin(16, 2);
    lcd.print("Starting...");
    delay(2000);
    lcd.clear();
}

void loop() {
    // Lire les capteurs
    int leftValue = analogRead(leftSensor);
    int rightValue = analogRead(rightSensor);
    
    // Afficher les valeurs des capteurs sur l'écran LCD
    lcd.setCursor(0, 0);
    lcd.print("L: ");
    lcd.print(leftValue);
    lcd.print(" R: ");
    lcd.print(rightValue);
    
    // Vérifier les conditions de navigation
    if (leftValue < 300 && rightValue < 300) {
        // Avancer
        moveForward();
        path += "F"; // Enregistrer le mouvement dans le chemin
        lcd.setCursor(0, 1);
        lcd.print("Path: " + path);
    } else if (leftValue < 300) {
        // Tourner à droite
        turnRight();
        path += "R"; // Enregistrer le mouvement dans le chemin
        lcd.setCursor(0, 1);
        lcd.print("Path: " + path);
    } else if (rightValue < 300) {
        // Tourner à gauche
        turnLeft();
        path += "L"; // Enregistrer le mouvement dans le chemin
        lcd.setCursor(0, 1);
        lcd.print("Path: " + path);
    } else {
        // Retour en arrière (Dead End)
        moveBackward();
        path += "D"; // Enregistrer le cul de sac dans le chemin
        lcd.setCursor(0, 1);
        lcd.print("Path: " + path);
        delay(1000); // Attendre un moment avant de tourner
    }

    delay(100); // Petite pause avant la prochaine lecture
}

// Fonctions pour contrôler le mouvement
void moveForward() {
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorBackward, LOW);
}

void turnRight() {
    digitalWrite(leftMotorForward, HIGH);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorBackward, LOW);
}

void turnLeft() {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(rightMotorForward, HIGH);
    digitalWrite(leftMotorBackward, LOW);
    digitalWrite(rightMotorBackward, LOW);
}

void moveBackward() {
    digitalWrite(leftMotorForward, LOW);
    digitalWrite(rightMotorForward, LOW);
    digitalWrite(leftMotorBackward, HIGH);
    digitalWrite(rightMotorBackward, HIGH);
}

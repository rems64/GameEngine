#include <iostream>
#include <vector>
#include <time.h>

#include <SFML/Graphics.hpp>
#include "StaticSprite.h"
#include "DynamicSprite.h"
#include "InputManager.h"
#include "SceneComponent.h"
#include "Game.h"

using namespace std;
using namespace sf;

int main(){
  //Création du jeu
  Game myGame(60, Vector2i {1280, 720}, "Premiere fenetre"); //FPS, taille de la fenêtre, nom de la fenêtre
  myGame.setCanClose(true); //Définit la possibilité de fermer la fenêtre de manière classique
  myGame.setBackgroundColor(Color (0, 0, 0, 100));

  //Creation du gestionnaire des entrées
  InputManager inputManager;

  //Initialisation de la texture
  Texture tex1;
  if (!tex1.loadFromFile("Textures/dirt.png")){}
  Texture tex2;
  if (!tex2.loadFromFile("Textures/uvGrid.jpg")){}

  //Creation des static sprites
  //StaticSprite blocTerre1(Vector2f(0.0f, 0.0f), Vector2f(100.f, 100.f), &texture);
  //Actor bloc1(Vector2f(80.0f, -50.0f), Vector2f(200.f, 200.f), &tex1, 8, 6, 46, 60);
  Actor bloc1(Vector2f(0.0f, 0.0f));
  bloc1.setSimulatePhysics(false);
  StaticSprite bloc1Sprite(Vector2f(0.0f, 0.0f), Vector2f(200.f, 200.f), &tex1);
  bloc1.addChild(&bloc1Sprite);
  //Actor bloc2(Vector2f(0.0f, 200.0f), Vector2f(100.f, 100.f), &tex2);
  Actor bloc2(Vector2f(100.0f, 0.0f));
  bloc2.setSimulatePhysics(false);
  StaticSprite bloc2Sprite(Vector2f(0.0f, 0.0f), Vector2f(200.f, 200.f), &tex2);
  bloc2.addChild(&bloc2Sprite);

  //Ajout des statics dans le jeu --> /!\ fonction temporaire vouée à être remplacée
  myGame.newActor(&bloc1);
  myGame.newActor(&bloc2);

  //Creation de la camera principale
  Camera mainCamera;
  myGame.setMainCamera(&mainCamera);

  mainCamera.setZoom(.8f);

  //  ## Boucle principale ##
  while (myGame.isAlive())
  {
    myGame.newLoop();                                         //Nouvelle boucle (pour le calcul des FPS)

    if (inputManager.isKeyPressed(Keyboard::Escape)) {        //Si on presse la touche echap
      myGame.close();                                         //Quitter le jeu
    }
    if (inputManager.isKeyPressed(Keyboard::Up)) {
      bloc2.move(sf::Vector2f {0., -10.});                    //Déplacer vers le haut
    }
    if (inputManager.isKeyPressed(Keyboard::Down)) {
      bloc2.move(sf::Vector2f {0., 10.});                     //Déplacer vers le bas
    }
    if (inputManager.isKeyPressed(Keyboard::Left)) {
      bloc2.move(sf::Vector2f {-10., 0.});                    //Déplacer vers la gauche
    }
    if (inputManager.isKeyPressed(Keyboard::Right)) {
      bloc2.move(sf::Vector2f {10., 0.});                     //Déplacer vers la droite
    }
    //Mise à jour de la logique globale du jeu (ex. fermer la fenêtre si évènement détecté)
    myGame.updateLogic();
    //Mise à jour du moteur de physique
    myGame.updatePhysics();
    //Mise à jour de la fenêtre
    myGame.updateDraw();

    //Fin de la boucle et délai pour atteindre le nombre d'images par seconde désiré
    myGame.endLoop();
  }
  return 0;
}

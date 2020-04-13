#include <iostream>
#include <vector>
#include <time.h>

#include <SFML/Graphics.hpp>
#include "StaticSprite.h"
#include "DynamicSprite.h"
#include "InputManager.h"
#include "SceneComponent.h"
#include "Game.h"
#include "Character.h"

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
  Texture texExplosion;
  if (!texExplosion.loadFromFile("Textures/animatedSprite.png")){}
  Texture texSoil;
  if (!texSoil.loadFromFile("Textures/dirt.png")){}
  Texture texRunner;
  if (!texRunner.loadFromFile("Textures/runner2.png")){}
  Texture texRunner2;
  if (!texRunner2.loadFromFile("Textures/runner3.png")){}

  //Creation des static sprites
  //StaticSprite blocTerre1(Vector2f(0.0f, 0.0f), Vector2f(100.f, 100.f), &texture);
  DynamicSprite explosion(Vector2f(80.0f, -50.0f), Vector2f(200.f, 200.f), &texExplosion, 8, 6, 46, 60);
  StaticSprite blocTerre1(Vector2f(0.0f, 200.0f), Vector2f(100.f, 100.f), &texSoil);
  StaticSprite blocTerre2(Vector2f(100.0f, 200.0f), Vector2f(100.f, 100.f), &texSoil);

  Character runner(Vector2f(30.0f, 0.0f), Vector2f(100.f, 200.f), &texRunner, 6, 4, 24, 30);
  runner.setSimulatePhysics(false);
  runner.setPlayForward(false);

  //DynamicSprite runner2(Vector2f(180.0f, 0.0f), Vector2f(100.f, 100.f), &texRunner2, 12, 6, 64, 60);
  //runner2.setSimulatePhysics(false);
  //runner2.setPlayForward(true);

  //Ajout des statics dans le jeu --> /!\ fonction temporaire vouée à être remplacée
  myGame.newSceneComponent(&blocTerre1);
  myGame.newSceneComponent(&blocTerre2);
  myGame.newSceneComponent(&explosion);
  myGame.newActor(&runner);
  //myGame.newSceneComponent(&runner2);

  //Creation de la camera principale
  Camera mainCamera;
  myGame.setMainCamera(&mainCamera);

  mainCamera.setZoom(.8f);

  //Boucle principale
  bool hPressed(false);
  while (myGame.isAlive())
  {
    //Nouvelle boucle (pour le calcul des FPS)
    myGame.newLoop();

    //Si on presse la touche echap
    if (inputManager.isKeyPressed(Keyboard::Escape)) {
      myGame.close(); //Quitter le jeu
    }
    if (inputManager.isKeyPressed(Keyboard::Up)) {
      mainCamera.move(sf::Vector2f {0., -10.}); //Déplacer vers le haut
    }
    if (inputManager.isKeyPressed(Keyboard::Down)) {
      mainCamera.move(sf::Vector2f {0., 10.}); //Déplacer vers le bas
    }
    if (inputManager.isKeyPressed(Keyboard::Left)) {
      mainCamera.move(sf::Vector2f {-10., 0.}); //Déplacer vers la gauche
    }
    if (inputManager.isKeyPressed(Keyboard::Right)) {
      mainCamera.move(sf::Vector2f {10., 0.}); //Déplacer vers la droite
    }
    if (inputManager.isKeyPressed(Keyboard::Add)) {
      mainCamera.zoom(0.01f);
    }
    if (inputManager.isKeyPressed(Keyboard::Subtract)) {
      mainCamera.zoom(-0.01f);
    }
    if (inputManager.isKeyPressed(Keyboard::H)) {
      if(!hPressed)
      {
        runner.toggleVisibility();
      }
      hPressed=true;
    }
    else{
      hPressed=false;
    }
    if (inputManager.isKeyPressed(Keyboard::Space)) {
      runner.jump();
    }
    else{
      //blocTerre2.m_totalExtForces[2] = {0.f, 0.f};
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

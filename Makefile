all: test


gameobject:
	g++ -c GameObject.cpp -lsfml-graphics -lsfml-window -lsfml-system

scenecomponent: gameobject
	g++ -c SceneComponent.cpp GameObject.cpp -lsfml-graphics -lsfml-window -lsfml-system

staticsprite: scenecomponent
	g++ -c StaticSprite.cpp SceneComponent.cpp -lsfml-graphics -lsfml-window -lsfml-system

dynamicsprite: scenecomponent
	g++ -c DynamicSprite.cpp SceneComponent.cpp -lsfml-graphics -lsfml-window -lsfml-system


actor: gameobject
	g++ -c Actor.cpp GameObject.cpp -lsfml-graphics -lsfml-window -lsfml-system

character: actor dynamicsprite
	g++ -c Character.cpp Actor.cpp DynamicSprite.cpp -lsfml-graphics -lsfml-window -lsfml-system

camera: actor
	g++ -c Camera.cpp Actor.cpp -lsfml-graphics -lsfml-window -lsfml-system






game: gameobject camera actor scenecomponent
	g++ -c Game.cpp GameObject.cpp Actor.cpp Camera.cpp SceneComponent.cpp -lsfml-graphics -lsfml-window -lsfml-system

inputmanager:
	g++ -c InputManager.cpp -lsfml-graphics -lsfml-window -lsfml-system





jeu: gameobject actor inputmanager staticsprite game jeu.cpp
	g++ jeu.cpp GameObject.o Actor.o InputManager.o StaticSprite.o Game.o -o jeu -lsfml-graphics -lsfml-window -lsfml-system

jeu2: gameobject scenecomponent actor inputmanager staticsprite dynamicsprite camera game jeu.cpp
	g++ jeu2.cpp GameObject.o SceneComponent.o Actor.o InputManager.o StaticSprite.o DynamicSprite.o Camera.o Game.o -o jeu2 -lsfml-graphics -lsfml-window -lsfml-system

jeu3: gameobject scenecomponent actor character inputmanager staticsprite dynamicsprite camera game jeu.cpp
	g++ jeu3.cpp GameObject.o SceneComponent.o Actor.o Character.o InputManager.o StaticSprite.o DynamicSprite.o Camera.o Game.o -o jeu3 -lsfml-graphics -lsfml-window -lsfml-system

test: jeu2
	./jeu2

build: jeu2

run:
	./jeu2

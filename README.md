# Tempus 

Ce projet est notre projet de fin de 1erannée dans la matière algorithmique à l'ESTACA.  
Il a pour but de créer notre version du jeu Tempus en français et codé 100% en langage C.  
Pour faire la partie graphique nous avons utiliser SDL.  
Et voici le git [SDL](https://github.com/libsdl-org/SDL) et le [siteweb](https://wiki.libsdl.org/FrontPage)
pour en savoir plus.

Créé par Rémi Perrier-Gustin ([MrTNTX](https://github.com/Mrtntx)) et Dylan Perinetti (dylanPerinetti)

## Commande pour l'Installer et le Lancer (Linux et Mac OS):

1. Pour telecharger le dosser complet entrez :
```
git clone https://github.com/dylanPerinetti/Tempus
```
2. Puis entrez la commmande suivantes pour entrer dans le dossier :
```
cd Tempus
```
3. Pour compiler avec gcc (si vous le posséder déjà sur votre machine) utilisez la commande suivante :
```
 gcc src/*c -o Tempus -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2

```
4.a) Enfin pour lancer la version graphique du jeu (Avec SDL) entrez ceci :
```
./Tempus
```
4.b) Si vous ne parvenez pas à compiler ou lancer la version graphique pas de panique !!!  
Vous pourrez tout de même Jouer en entrant la commande :
```
./Tempus -g
```  
  
  
  
  
## Info Windows

1. Si vous souhaiter faire tourner le jeu sur une machine windows vous devez prealablement changer la ligne suivante (ligne 17) :
```
#define NETTOYER_TERMINAL "clear"
```
par :
```
#define NETTOYER_TERMINAL "cls"
```  
  
  
2. Puis entrez la commmande suivantes dans le PowerShell pour entrer dans le dossier :
```
cd Tempus
```
3. Pour compiler avec gcc (si vous le posséder déjà sur votre machine) utilisez la commande suivante :
```
gcc src/*c -o bin/Tempus -I include -L lib -lmingw32 -lSDL2main -lSDL2

```
4.a) Enfin pour lancer la version graphique du jeu (Avec SDL) entrez ceci :
```
Tempus
```
4.b) Si vous ne parvenez pas à compiler ou lancer la version graphique pas de panique !!!  
Vous pourrez tout de même Jouer en entrant la commande :
```
Tempus -g
``` 
  
  
  
  
  
### Image du 15/03/2022
![IMG_1](https://user-images.githubusercontent.com/101599798/158646783-4ce43688-70bc-44d6-9bf2-ec8391e891eb.png)
### Image du 17/03/2022
![IMG_2](https://user-images.githubusercontent.com/101599798/159054534-625011f0-507d-407e-b094-87c1c73bb3c4.png)
  
  
MERCI et GG :) 

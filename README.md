# Tempus 

Ce projet est notre projet de fin de 1erannée dans la matière algorithmique à l'ESTACA.  
Il a pour but de créer notre version du jeu Tempus en français et codé 100% en langage C.  
Pour faire la partie graphique nous avons utiliser SDL.

Créé par Rémi Perrier-Gustin (MrTNTX) et Dylan Perinetti (dylanPerinetti)

## Commande pour l'Installer et le Lancer (Linux et Mac OS):

1. Pour telecharger le dosser complet entrez :
```
git clone https://github.com/dylanPerinetti/tempus
```
2. Puis entrez la commmande suivantes pour entrer dans le dossier :
```
cd tempus
```
3. Pour compiler avec gcc (si vous le posséder déjà votre machine) utilisez la commande suivante :
```
gcc *.c -o tempus

```
4.a) Enfin pour lancer la version graphique du jeu (Avec SDL) entrez ceci :
```
./tempus
```
4.b) Si vous ne parvenez pas à compiler ou lancer la version graphique pas de panique !!!  
Vous pourrez tout de même Jouer en entrant la commande :
```
./tempus -g
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
cd tempus
```
3. Pour compiler avec gcc (si vous le posséder déjà votre machine) utilisez la commande suivante :
```
gcc *.c -o tempus

```
4.a) Enfin pour lancer la version graphique du jeu (Avec SDL) entrez ceci :
```
tempus
```
4.b) Si vous ne parvenez pas à compiler ou lancer la version graphique pas de panique !!!  
Vous pourrez tout de même Jouer en entrant la commande :
```
tempus -g
``` 
  
  
  
  
  
### Image du 15/03/2022
![IMG_1](https://user-images.githubusercontent.com/101599798/158646783-4ce43688-70bc-44d6-9bf2-ec8391e891eb.png)
### Image du 17/03/2022
![IMG_2](https://user-images.githubusercontent.com/101599798/159054534-625011f0-507d-407e-b094-87c1c73bb3c4.png)
  
  
MERCI et GG :) 

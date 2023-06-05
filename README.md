# Projet jeu C++

Ceci est le projet cree dans les meilleurs esprits des pioniers du jeu video sur PC des annees 90, qui non seulement ne servait pas au divertissement de leur publique, mais provoquaient une frustration intense, souvi, defois, des consequences irreversibles sur l'integrite mentale.

Dans notre jeu, *Tales of a monster hunter* vous allez prendre le role des deux chasseurs de monstres qui ont pour leur quete proncipale de tuer le grand dragon mechant, ainsi que tout ce qui bouge sur leur chemin, dans le seul but de demontrer notre capacite de programmer en langage objet C++.


## Installation

Ce projet est destine aux plateformes Linux et est dependant de la bibliotheque SFML. Pour l'installation de SFML, veuillez vous referer au [guide officel](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

Tout d'abord, choisissez le dossier dans lequel vous voulez installer le jeu. Dans ce dossier, cloner le repositoire du projet et lancer `make` :

  `git clone https://github.com/garciaflorentin/ProjectJeuxC-.git --branch master --single-branch`
  
  `cd ProjetJeuxC-`
  
  `make all`
  
Une fois le jeu installe, vous pouvez le lancer avec :
  `./the_game`
  
Pour acceder la documentation concernante le projet (`firefox` a remplacer par votre navigateur de preference):
  `firefox /html/annotated.html`


## Regles du jeu

Le nom du jeu peut paraitre trompeur, mais sa nature est cooperative ou vous et votre camarade, ou juste vos deux mains vont devoir prendre les roles non pas de un, mais de deux chasseurs de monstres. Le premier est un guerrier ![the knight](/PlayerTextures/player1_singlesprite.png) qui tire a l'arc avec une precision de demi-pixel et le deuxieme est un mage ![the wizard](/PlayerTextures/player2_singlesprite.png) qui tire des projectiles magiques. Pas de panique si ce ne sont pas vos classes preferes ! Il n'y a aucune difference entre les deux.

Pour deplacer le guerrier utilisez les fleches du clavier. Pour lances une fleche appuiyez sur **M**. Pour deplaces le mage utilisez **WASD** ou **ZQSD**. Pour utiliser la magie appuiyez sur **E**.

Le but du jeu est de tuer le boss fianl. Pour faire ceci, il faut traverser les quatres portes ![door](/WorldTextures/Door_singlesprite.png) qui delimitent les quatres zones de la carte. Les cles qui ouvrent ces portes se trouvent dans les grands coffres a leur opposes sur la carte d'une zone. Attention, vous ne pouvez par ouvrir ces coffres que si tous les monstres de la zone ont ete tues.

![the map](/OtherTextures/game_map.PNG)

Nous etions totalement conscients des concequences sur la perception du gameplay lorsque nous avons pris cette decision, suivie du choix de la tailles des zones que les joueurs vont devoir couvrir, ce que allait rendre l'experience totalement inedite. Mais, si cette experience n'est pas vraiment ce que vous cherchez, vous pouvez appuiyer sur **1** pour tuer instantanement tous les monstres de la zone.

Vous pouvez aussi appuiyer sur **2** pour obtenir une cle directrement.

Une fois tous les monstres tues, il n'en reste qu'un seul, qui se cache derriere la derniere porte. Il faut quatre cles pour l'ouvrir. Vous avez gagne le jeu lorsque le gradon final est tue.

Bonne chance !

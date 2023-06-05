# Projet jeu C++ - Florentin Garcia et Olga Shlykova

Ceci est le projet créé dans les meilleurs esprits des pionniers du jeu vidéo sur PC des années 90, qui non seulement ne servait pas au divertissement de leur publique, mais provoquaient une frustration intense, suivi, de fois, des conséquences irréversibles sur l'intégrité mentale.

Dans notre jeu, *Tales of a monster hunter*, vous allez prendre le rôle des deux chasseurs de monstres qui ont pour leur quête principale de tuer le grand dragon méchant, ainsi que tout ce qui bouge sur leur chemin, dans le seul but de démontrer notre capacité de programmer en langage objet C++.


## Installation

Ce projet est destiné aux plateformes Linux et est dépendant de la bibliothèque SFML. Pour l'installation de SFML, veuillez vous référer au [guide officel](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

Tout d'abord, choisissez le dossier dans lequel vous voulez installer le jeu. Dans ce dossier, cloner le repositoire du projet et lancer `make` :

  `git clone https://github.com/garciaflorentin/ProjectJeuxC-.git --branch master --single-branch`
  
  `cd ProjetJeuxC-`
  
  `make all`
  
Une fois le jeu installe, vous pouvez le lancer avec :

  `./the_game`
  
Pour accéder la documentation concernante le projet (`firefox` a remplacer par votre navigateur de préférence)

  `firefox /html/annotated.html`


## Regles du jeu

Le nom du jeu peut paraître trompeur, mais sa nature est coopérative, car vous et votre camarade, ou juste vos deux mains vont devoir prendre les rôles non pas d'un, mais de deux chasseurs de monstres. Le premier est un guerrier ![the knight](/PlayerTextures/player1_singlesprite.png) qui tire à l'arc avec une précision de demi-pixel et le deuxième est un mage ![the wizard](/PlayerTextures/player2_singlesprite.png) qui tire des projectiles magiques. Pas de paniques si ce ne sont pas vos classes préférés ! Il n'y a aucune différence entre les deux.

Pour déplacer le guerrier utilisez les flèches du clavier. Pour lancer une flèche appuyiez sur **M**. Pour déplacer le mage utilisez **WASD** si votre clavier a été conçu pour votre confort ou **ZQSD** si vous êtes français. Pour utiliser la magie appuyiez sur **E**.

Le but du jeu est de tuer le boss final. Pour faire ceci, il faut traverser les quatre portes ![door](/WorldTextures/Door_singlesprite.png) qui délimitent les quatre zones de la carte. Les clés qui ouvrent ses portes se trouvent dans les grands coffres à leur opposes sur la carte d'une zone. Attention, vous ne pouvez ouvrir ces coffres que si tous les monstres de la zone ont été tués.

![the map](/OtherTextures/game_map.PNG)

Nous etions totalement conscients des conséquences sur la perception du gameplay lorsque nous avons pris cette décision, suivie du choix de la taille des zones que les joueurs vont devoir couvrir, ce qu'allait rendre l'expérience totalement inédite. Mais, si cette expérience n'est pas vraiment ce que vous cherchez, vous pouvez appuyer sur **1** pour tuer instantanément tous les monstres de la zone.

Vous pouvez aussi appuyer sur **2** pour obtenir une clé directement.

Une fois tous les monstres tués, il n'en reste qu'un seul, qui se cache derrière la dernière porte. Il faut quatre clés pour l'ouvrir. Vous avez gagne le jeu lorsque le dragon final est tue.

Bonne chance !

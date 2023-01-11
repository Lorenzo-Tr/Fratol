# Fratol
Concevoir et programmer un explorateur de fractal

# Caractéristique
Votre programme devra prendre trois parametres en ligne de commande :
- La hauteur de la fenetre en pixels.
- La largeur de la fenetre en pixels.
- Le nom de la fractale a afficher a l'ecran (Mandelbrot ou Julia).

Les dimensions de la fenetre ne doivent pas depasser celles de l'ecran, au quel cas le programme
affiche un message sur la sortie d'erreur et quitte en renvoyant une valeur d'erreur. Si
l'utilisateur renseigne un nom de fractale invalide, le programme affiche l'usage sur la sortie
d'erreur, et quitte proprement.

Votre programme ne doit jamais quitter de maniere incontrolee, crash, ou encore faire fuiter de la memoire.

Si tous les parametres sont valides, alors le programme affiche la fractale correspondante dans une fenetre ouverte avec la librairie SDL.

Fonctionnalites obligatoires :

- Afficher de la fractale

- Pouvoir quitter le programme a tout moment avec la touche echap ou la croix rouge.

- Pouvoir passer d'une fractale a une autre avec la touche epace.

- Pouvoir deplacer la fractale de haut en bas et de gauche a droite avec les fleches du clavier.

- Pouvoir zoomer et dezoomer avec la molette de la souris, en centrant le zoom sur le curseur.

- Adapter votre Makefile pour qu'il installe les dependances necessaires (principalement la SDL),
et qu'il soit capable de compiler votre projet sur Windows, MacOs, et Linux.


Fonctionnalites Bonus :

- Proposer une liste de palettes de couleurs, et permettre a l'utilisateur de passer de l'une a l'autre avec la touche c.

- Permettre une variation de l'equation de la fractale Julia avec la souris. Activable / desactivable avec le clic droit.

- Proposer une interpolation lineaire entre les differentes couleurs des palettes. Permettre a l'utilisateur d'activer / desactiver cette option avec la touche i.

- Utiliser le multithreading avec la librairie pthread.h afin d'obtenir de meilleurs performances.

- Deporter les calculs sur GPU avec le framework OpenCL afin obtenir de (biens) meilleurs performances.

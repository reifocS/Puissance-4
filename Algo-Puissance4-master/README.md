Algo-Puissance4
IUT Paris Descartes - 2019 - Enseignant : ZIANE Mikal.

Algorithme et Programmation en C.
Dans le cadre du cours de Algorithme et Programmation en C, Mikal Ziane a proposé de développer un jeu : Le puissance 4.

Auteurs
BERTHIER Nicolas : nicolas-berthier@orange.fr
ESCOFFIER Vincent : alainvincentesc@gmail.com
JALLAIS Adrien : adrien.jallais@protonmail.com

Description
Une présentation du jeu est consultable au lien suivant : https://fr.wikipedia.org/wiki/Puissance_4 .

Portabilité
Programmé en C. Des dossiers joueurs et parties doivent être créés au préalable afin de permettre leur sauvegarde.

Interface graphique
Uniquement en console
Jeu contre l'ordinateur
L'IA est programmée d'après l'agorithme MinMax optimisé avec l'élagage alpha-bêta.

MinMax
A partir d’une grille de jeu donnee, on génère l’ensemble des positions que l’ordinateur peut atteindre. Pour chacunes de ces positions, on génère l’ensemble des posistions que l’adversaire pourrait à son tour atteindre. On recommence l’operation aussi lontemps que le permet la puissance de calcul de l’ordinateur. On construit ainsi un arbre representant l’ensemble des configurations de la grille du jeu pour un certain nombre de coups à l’avance. Il est clair que par cette technique, on ne peut pas construire l’arbre complet de la partie, c’est à dire un arbre dont toutes les feuilles seraient des coups terminaux (gagnant ou match nul). Puisqu’on est obligé de limiter la profondeur de l’arbre, il est nécessaire d’evaluer une position non terminale pour un joueur donné. La fonction d'évaluation choisie prend en compte l'ensemble des alignements présents et possibles dans la grille à l'état du jeu donné. Plus d'informations ici : https://fr.wikipedia.org/wiki/Algorithme_minimax.

Algorithme α−β
Tel que présenté ci-dessus, MinMax calcule sans distonctions toutes les positions jouables de chaque grille. Afin de limiter le nombre de noeuds de l’arbre, l’algorithme α−β empêche le calcul des positions jugées inintéressantes.

Joueurs
Jeu à deux joueurs physiques
Jeu contre l'ordinateur (IA)
Options possibles
Partie
Sauvegarde et Chargement (format binaire)
Profil de joueur
Sauvegarde et Chargement (format binaire)
Création et Actualisation des statistiques de jeu
Programmation
Grille
La grille est stockée sous la forme d'un tableau de caractères à une dimension. Elle est cependant artificiellement traitée comme un tableau 2D par l'intermédiaire de fonctions.

Test de Production
Tests unitaires tout au long de la programmation.

Tour de jeu
Afficher clairement le nom du joueur et son jeton associé qui devra jouer au prochain tour.
Evaluer la validité des coups proposés par l'utilisateur.
Evaluer une victoire ou un match-nul.
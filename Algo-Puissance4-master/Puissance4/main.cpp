/// @file main.cpp
#include <time.h>
#include <assert.h>
#include <string.h>
#include "unittest.h"
#include "T2d.h"
#include "partie.h"
#include "joueur.h"
#include "menu.h"

void testerT2d();
int tirage(int min, int max);
void initSeed();

int main() {
	accueilJeu();
	
	//testerT2d();
	return 0;
}

void  initSeed() {
	static bool initialized = false;
	if (!initialized) {
		srand((unsigned)time(NULL));
		initialized = true;
	}
}

int tirage(int min, int max) {
	initSeed();
	return (rand() % (max - min + 1)) + min;
}


void testerT2d() {
	assertEquals('.', getSymbole(0), "case vide");
	assertEquals('X', getSymbole(1), "symbole joueur 1");
	assertEquals('O', getSymbole(2), "symbole joueur 2");
	T2d t;
	init(&t, 7u, 6u);
	char s[200];
	viderGrille(&t);
	assertFalse(estRemplie(&t, 'd'), "Non estRemplie(&t,'d')");
	set(&t, 'd', 1, 'X');
	set(&t, 'd', 2, 'X');
	set(&t, 'd', 3, 'X');
	set(&t, 'd', 4, 'X');
	set(&t, 'd', 5, 'X');
	set(&t, 'd', 6, 'X');
	char* liste;
	liste = coupsLegaux(&t);
	assertEquals(0, strcmp("abcefg", liste), "coup legaux d pleine");
	assertTrue(estRemplie(&t, 'd'), "estRemplie(&t,'d')");
	// v�rifier que la largeur de t est 7
	assertEquals(7u, getLargeur(&t), "largeur de t");
	// v�rifier que la hauteur de t est 6
	assertEquals(6u, getHauteur(&t), "hauteur de t");    // mettre 'X' dans la case ('d', 3) de t
	set(&t, 'd', 3, 'X');
	// verifier que 'X' est bien dans la case ('d', 3)
	assertEquals('X', get(&t, 'd', 3u), "get('d',3)");
	set(&t, 'd', 4, 'X');
	set(&t, 'd', 2, 'X');
	set(&t, 'd', 1, 'X');
	assertTrue(estVictoire(&t, 'd', 4u), "estVictoire(&t, 'd', 4u)");
	set(&t, 'a', 1, 'O');
	assertFalse(estVictoire(&t, 'a', 1u), "Non estVictoire(&t, 'a', 1u)");
	toString(&t, s);
	printf("%s", s);
	viderGrille(&t);
	set(&t, 'd', 1, 'X');
	assertEquals('X', get(&t, 'd', 1), "d1 X");
	viderGrille(&t);
	set(&t, 'a', 1, 'X');
	set(&t, 'b', 1, 'X');
	set(&t, 'c', 1, 'X');
	set(&t, 'd', 1, 'X');
	assertTrue(estVictoire(&t, 'd', 1u), "estVictoire(&t, 'd', 1u)");
	assertTrue(estVictoire(&t, 'a', 1u), "estVictoire(&t, 'a', 1u)");
	set(&t, 'd', 2, 'O');
	assertFalse(estVictoire(&t, 'd', 2u), "Non estVictoire(&t, 'd', 2u)");
	toString(&t, s);
	printf("%s", s);
	viderGrille(&t);
	set(&t, 'a', 1, 'X');
	set(&t, 'b', 2, 'X');
	set(&t, 'c', 3, 'X');
	set(&t, 'd', 4, 'X');
	toString(&t, s);
	assertTrue(estVictoire(&t, 'a', 1), "estVictoire(&t, 'a', 1), victoire / montante ");
	assertTrue(estVictoire(&t, 'd', 4), "estVictoire(&t, 'd', 4), victoire / descendante ");
	set(&t, 'g', 4, 'O');
	assertFalse(estVictoire(&t, 'g', 4), "Non estVictoire(&t, 'g', 4) ");
	printf("%s", s);
	viderGrille(&t);
	set(&t, 'a', 4, 'X');
	set(&t, 'b', 3, 'X');
	set(&t, 'c', 2, 'X');
	set(&t, 'd', 1, 'X');
	toString(&t, s);
	assertTrue(estVictoire(&t, 'a', 4), "estVictoire(&t, 'a', 4)");
	assertTrue(estVictoire(&t, 'd', 1), "estVictoire(&t, 'd', 1)");
	set(&t, 'g', 4, 'O');
	assertFalse(estVictoire(&t, 'g', 4), "Non estVictoire(&t, 'g', 4)");
	printf("%s", s);    liberer(&t);
}

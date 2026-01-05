#include "organizm.h"
#include "swiat.h"

void Organizm::losuj_kierunek(unsigned int& new_x, unsigned int& new_y) const {

	const unsigned int random = swiat.losuj(0, 3);

	if (random == 0) { new_x++; } // PRAWO
	if (random == 1) { new_x--; } // LEWO
	if (random == 2) { new_y--; } // GORA
	if (random == 3) { new_y++; } // DOL
}

bool Organizm::czy_sie_miesci(unsigned int& new_x,unsigned int& new_y) {

	if (new_x < swiat.get_n() && new_y < swiat.get_m()) { return true; }
	else { return false; }
}
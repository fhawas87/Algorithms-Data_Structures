#pragma once

#include "organizm.h"
#include "zwierze.h"
#include "swiat.h"

class Czlowiek : public Zwierze {

public:

	void akcja();
	void wybierz_kierunek(unsigned int& new_x, unsigned int& new_y);

	char get_znak() const { return '&'; }

	// KONSTRUKTOR PUBLICZNY BO CZLOWIEK JEST TYM SAMYM CO POSZCZEGOLNE GATUNKI ZWIERZAT / ROSLIN

	Czlowiek(unsigned int x, unsigned int y, Swiat& swiat) : Zwierze(x, y, swiat) {

		this->sila = 5;
		this->inic = 4;
		this->wiek = 0;
	}
};

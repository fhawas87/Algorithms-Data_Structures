#pragma once

#include "organizm.h"
#include "swiat.h"

class Zwierze : public Organizm {

public:

	void akcja();
	void kolizja(Organizm* inny);

protected:

	Zwierze(unsigned int x, unsigned int y, Swiat& swiat) : Organizm(x, y, swiat) {}
};

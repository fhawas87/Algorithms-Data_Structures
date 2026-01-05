#pragma once

#include "organizm.h"
#include "swiat.h"

class Roslina : public Organizm {

public:

	void akcja();
	void kolizja(Organizm* inny);

protected:

	Roslina(unsigned int x, unsigned int y, Swiat& swiat) : Organizm(x, y, swiat) {}
};

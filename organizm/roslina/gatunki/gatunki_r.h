#pragma once

#include "roslina.h"
#include "organizm.h"

class Trawa : public Roslina {

public:

	Trawa(unsigned int x, unsigned int y, Swiat& swiat) : Roslina(x, y, swiat) {
		
		this->sila = 0;
		this->inic = 0;
		this->wiek = 0;
	}

	char get_znak() const { return 't'; }
	std::string get_nazwa() const { return "Trawa"; }
};

class Mlecz : public Roslina {

public:

	Mlecz(unsigned int x, unsigned int y, Swiat& swiat) : Roslina(x, y, swiat) {
	
		this->sila = 0;
		this->inic = 0;
		this->wiek = 0;
	}

	char get_znak() const { return 'm'; }
	std::string get_nazwa() const { return "Mlecz"; }
};

class Guarana : public Roslina {

public:

	Guarana(unsigned int x, unsigned int y, Swiat& swiat) : Roslina(x, y, swiat) {
	
		this->sila = 0;
		this->inic = 0;
		this->wiek = 0;
	}

	void kolizja(Organizm* inny);

	char get_znak() const { return 'g'; }
	std::string get_nazwa() const { return "Guarana"; }
};

class WilczeJagody : public Roslina {

public:

	WilczeJagody(unsigned int x, unsigned int y, Swiat& swiat) : Roslina(x, y, swiat) {
		
		this->sila = 99;
		this->inic = 0;
		this->wiek = 0;
	}

	void kolizja(Organizm* inny);

	char get_znak() const { return 'j'; }
	std::string get_nazwa() const { return "Wilcze Jagody"; }
};

class BarszczSosnowskiego : public Roslina {

public:

	BarszczSosnowskiego(unsigned int x, unsigned int y, Swiat& swiat) : Roslina(x, y, swiat) {
	
		this->sila = 10;
		this->inic = 0;
		this->wiek = 0;
	}

	void kolizja(Organizm* inny);
	void akcja();

	char get_znak() const { return 'b'; }
	std::string get_nazwa() const { return "Barszcz Sosnowskiego"; }
};



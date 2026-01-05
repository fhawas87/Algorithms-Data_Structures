#pragma once

#include "zwierze.h"
#include "organizm.h"

class Wilk : public Zwierze {
	
public:

	Wilk(unsigned int x, unsigned int y, Swiat& swiat) : Zwierze(x, y, swiat) {

		this->sila = 9;
		this->inic = 5;
		this->wiek = 0;
	}

	char get_znak() const { return 'W'; }
	std::string get_nazwa() const { return "Wilk"; }
};

class Lis : public Zwierze {

public:

	Lis(unsigned int x, unsigned int y, Swiat& swiat) : Zwierze(x, y, swiat) {

		this->sila = 3;
		this->inic = 7;
		this->wiek = 0;
	}

	void akcja();

	char get_znak() const { return 'L'; }
	std::string get_nazwa() const { return "Lis"; }
};

class Owca : public Zwierze {

public:

	Owca(unsigned int x, unsigned int y, Swiat& swiat) : Zwierze(x, y, swiat) {

		this->sila = 4;
		this->inic = 4;
		this->wiek = 0;
	}

	char get_znak() const { return 'O'; }
	std::string get_nazwa() const { return "Owca"; }
};

class Zolw : public Zwierze {

public:

	Zolw(unsigned int x, unsigned int y, Swiat& swiat) : Zwierze(x, y, swiat) {

		this->sila = 2;
		this->inic = 1;
		this->wiek = 0;
	}

	void akcja();
	void kolizja(Organizm* inny);

	char get_znak() const { return 'Z'; }
	std::string get_nazwa() const { return "Zolw"; }
};

class Antylopa : public Zwierze {

public:

	Antylopa(unsigned int x, unsigned int y, Swiat& swiat) : Zwierze(x, y, swiat) {

		this->sila = 9;
		this->inic = 5;
		this->wiek = 0;
	}

	//void akcja();
	void kolizja(Organizm* inny);
	void losuj_kierunek(unsigned int& new_x, unsigned int& new_y) const;

	char get_znak() const { return 'A'; }
	std::string get_nazwa() const { return "Antylopa"; }
};

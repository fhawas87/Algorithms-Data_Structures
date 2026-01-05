#pragma once

#include <string>

class Swiat;

class Organizm {

public:

	Organizm(unsigned int x, unsigned int y, Swiat& swiat) : x(x), y(y), swiat(swiat) {}
	//~Organizm() { delete this; }

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* inny) = 0;
	virtual void losuj_kierunek(unsigned int& new_x, unsigned int& new_y) const;

	virtual char get_znak() const = 0;

	//virtual std::string get_nazwa() const = 0;

	bool czy_sie_miesci(unsigned int& new_x,unsigned int& new_y);

	unsigned int get_sila() const { return this->sila; }
	unsigned int get_inic() const { return this->inic; }
	unsigned int get_wiek() const { return this->wiek; }
	unsigned int get_x() const { return this->x; }
	unsigned int get_y() const { return this->y; }

	void set_x(const unsigned int& new_x) { this->x = new_x; }
	void set_y(const unsigned int& new_y) { this->y = new_y; }
	void set_sila(const unsigned int& ile) { this->sila = ile; }
	void set_wiek(const unsigned int& ile) { this->wiek = ile; }

	void inc_sila(const unsigned int& ile) { this->sila += ile; }
	void inc_wiek() { this->wiek++; }

protected:

	unsigned int sila;
	unsigned int inic;
	unsigned int wiek;
	unsigned int x;
	unsigned int y;

	Swiat& swiat;
};
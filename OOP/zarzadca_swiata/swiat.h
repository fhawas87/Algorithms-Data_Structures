#pragma once

#include <vector>

#include "organizm.h"

class Swiat {
public:

	Swiat();
	~Swiat() {
		for (Organizm* o : organizmy) {

			delete o;
		}
	}
	void inicjuj_poczatkowe_organizmy();
	void rysuj_swiat() const;
	void wykonaj_ture();
	void dodaj_organizm(Organizm* organizm);
	void usun_organizm(Organizm* organizm);
	void przenies_organizm(Organizm* organizm, const unsigned int& new_x, const unsigned int& new_y);

	unsigned int losuj(const unsigned int& min, const unsigned int& max) const;

	unsigned int get_n() const { return this->n; }
	unsigned int get_m() const { return this->m; }

	Organizm* get_organizm(const unsigned int& x, const unsigned int& y) const { return plansza[x][y]; }

	bool czy_pole_wolne(const unsigned int& x, const unsigned int& y) const;
	bool stop() { return this->zakoncz; }

	bool wczytano = false;

	void zapisz_gre();
	void wczytaj_gre();
	void wybierz_sposob_inicjalizacji();
	void odtworz_organizmy(const char& c, const unsigned int& x, const unsigned int& y, 
						   const unsigned int& sila, const unsigned int& inic, const unsigned int& wiek);

private:

	static constexpr unsigned int n = 20;
	static constexpr unsigned int m = 20;
	
	bool zakoncz = false;

	unsigned int licznik_tur = 0;

	std::vector<std::vector<Organizm*>> plansza;
	std::vector<Organizm*> organizmy;

	std::pair<unsigned int, unsigned int> losuj_wolne_pole() const;

	std::vector<char> kto_zmarl;
};
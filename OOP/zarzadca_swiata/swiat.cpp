#include <random>
#include <utility>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

#include "organizm.h"
#include "swiat.h"
#include "gatunki_r.h"
#include "gatunki_z.h"
#include "czlowiek.h"

bool Swiat::czy_pole_wolne(const unsigned int& x, const unsigned int& y) const {

	if (this->plansza[x][y] == nullptr) { return true; }
	else { return false; }
}

unsigned int Swiat::losuj(const unsigned int& min, const unsigned int& max) const {

	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> dist(min, max);

	return dist(gen);
}

std::pair<unsigned int, unsigned int> Swiat::losuj_wolne_pole() const {

	while (true) {

		unsigned int x = this->losuj(0, this->n - 1);
		unsigned int y = this->losuj(0, this->m - 1);

		if (this->czy_pole_wolne(x, y)) { return { x, y }; }
	}
}

void Swiat::dodaj_organizm(Organizm* organizm) {

	this->plansza[organizm->get_x()][organizm->get_y()] = organizm;

	this->organizmy.emplace_back(organizm);
}

void Swiat::usun_organizm(Organizm* organizm) {

	if (plansza[organizm->get_x()][organizm->get_y()] == organizm) {
		plansza[organizm->get_x()][organizm->get_y()] = nullptr;
	}

	for (unsigned int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i] == organizm) { this->organizmy.erase(organizmy.begin() + i); break; }
	} // MOZE ERESA AUTOMATYCZNIE WYWOLUJE DESTRUKTOR ???
	  // TODO : SPRWAWDZIC
	//this->organizmy.emplace_back(nullptr);

	//delete organizm;

	this->kto_zmarl.emplace_back(organizm->get_znak());
}

void Swiat::przenies_organizm(Organizm* organizm, const unsigned int& new_x, const unsigned int& new_y) {

	if (this->plansza[organizm->get_x()][organizm->get_y()] == organizm) {
		this->plansza[organizm->get_x()][organizm->get_y()] = nullptr;
	}

	this->plansza[new_x][new_y] = organizm;

	organizm->set_x(new_x);
	organizm->set_y(new_y);
}

void Swiat::rysuj_swiat() const {

	system("cls");

	unsigned int gap = 2;

	for (unsigned int i = 0; i < this->n; i++) {
		for (unsigned int j = gap; j < this->m + gap; j++) {
			char znak;

			if (this->plansza[i][j - gap] != nullptr) {

				znak = this->plansza[i][j - gap]->get_znak();
			}
			else { znak = '..'; }

			std::cout << znak << ' ';
			//std::this_thread::sleep_for(std::chrono::microseconds(1));
		}

		std::cout << "\n";
		//std::this_thread::sleep_for(std::chrono::microseconds(2));
	}
}

void Swiat::wykonaj_ture() {

	for (unsigned int i = 0; i < this->organizmy.size(); i++) {
		for (unsigned int j = 0; j < this->organizmy.size() - i - 1; j++) {
			if (this->organizmy[j]->get_inic() > this->organizmy[j + 1]->get_inic()) {
				
				std::swap(this->organizmy[j], this->organizmy[j + 1]);
			}
			if (this->organizmy[j]->get_inic() == this->organizmy[j + 1]->get_inic()) {
				if (this->organizmy[j]->get_wiek() > this->organizmy[j + 1]->get_wiek()) {

					std::swap(this->organizmy[j], this->organizmy[j + 1]);
				}
				else { continue; }
			}
			else { continue; }
		}
	}

	auto kopia_przed_akcja = this->organizmy; // Z JAKIEGOS POWODU NIE DZIALA NA KOPII TYPU : Organizm* kopia

	for (Organizm* org : kopia_przed_akcja) {
		if (org != nullptr) {

			org->akcja();
			org->inc_wiek();

			if (org->get_znak() == '&') {

				//std::cout << "\n\n";
				//std::cout << org->get_x() << ", " << org->get_y() << "\n";

				// POZYCJA CZLOWIEKA NIE ZMIENIA SIE MIMO POPRAWNEGO WCZYTYWANIA KODOW KLAWISZY (w, a, s, d)
			}
		}
		//rysuj_swiat();
	}

	rysuj_swiat();

	std::cout << "\n" << this->organizmy.size();
	std::cout << "\n" << this->plansza.size();
	std::cout << "\n" << this->plansza[0].size();
	std::cout << "\n";

	for (const char& c : this->kto_zmarl) {

		std::cout << c << ", ";
	}

	this->licznik_tur++;

	if (this->licznik_tur > 50) { this->zakoncz = true; }
}

void Swiat::inicjuj_poczatkowe_organizmy() {

	unsigned int ile;
	unsigned int n = 5;

	std::pair<unsigned int, unsigned int> c;

	c = this->losuj_wolne_pole();

	//this->dodaj_organizm(new Czlowiek(c.first, c.second, *this));
	this->dodaj_organizm(new Czlowiek(18, 18, *this));

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Wilk(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Owca(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Lis(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Zolw(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Antylopa(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Trawa(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Mlecz(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new Guarana(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new WilczeJagody(c.first, c.second, *this));
	}

	ile = this->losuj(1, n);
	for (unsigned int i = 0; i < ile; i++) {

		c = this->losuj_wolne_pole();

		this->dodaj_organizm(new BarszczSosnowskiego(c.first, c.second, *this));
	}
}

void Swiat::odtworz_organizmy(const char& c, const unsigned int& x, const unsigned int& y,
							  const unsigned int& sila, const unsigned int& inic, const unsigned int& wiek) {
	std::cout << c << " " << x << " " << y << " " << sila << " " << inic << " " << wiek << "\n";
	if (c == 'W') {

		this->dodaj_organizm(new Wilk(x, y, *this));
		this->get_organizm(x, y)->inc_sila(sila);
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'O') {

		this->dodaj_organizm(new Owca(x, y, *this));
		this->get_organizm(x, y)->inc_sila(sila);
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'L') {

		this->dodaj_organizm(new Lis(x, y, *this));
		this->get_organizm(x, y)->inc_sila(sila);
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'Z') {

		this->dodaj_organizm(new Zolw(x, y, *this));
		this->get_organizm(x, y)->inc_sila(sila);
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'A') {

		this->dodaj_organizm(new Antylopa(x, y, *this));
		this->get_organizm(x, y)->inc_sila(sila);
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 't') {

		this->dodaj_organizm(new Trawa(x, y, *this));
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'm') {

		this->dodaj_organizm(new Mlecz(x, y, *this));
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'g') {

		this->dodaj_organizm(new Guarana(x, y, *this));
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'j') {

		this->dodaj_organizm(new WilczeJagody(x, y, *this));
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	if (c == 'b') {

		this->dodaj_organizm(new BarszczSosnowskiego(x, y, *this));
		this->get_organizm(x, y)->set_wiek(wiek);
	}
	//else { std::cout << "\nNIEZNANY ZNAK\n"; }
}

void Swiat::wybierz_sposob_inicjalizacji() {

	if (!this->wczytano) {

		this->inicjuj_poczatkowe_organizmy();
	}
	else {

		this->wczytaj_gre();
	}
}

Swiat::Swiat() {

	this->plansza.resize(this->n);
	for (unsigned int i = 0; i < this->n; i++) {
		this->plansza[i].resize(this->m, nullptr);
	}
}
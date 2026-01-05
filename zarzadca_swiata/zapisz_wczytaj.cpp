#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "swiat.h"

#define PATH "C:\\Desktop\\OOP_PROJ\\stan_gry.txt"

void Swiat::zapisz_gre() {

	std::ofstream os(PATH);
	if (!os) { std::cout << "NIE POPRAWNA SCIEZKA PLIKU\n"; }

	os << this->licznik_tur << " " << this->organizmy.size() << '\n';

	for (const auto& org : this->organizmy) {

		os << org->get_znak() << " "
		   << org->get_x()	  << " "
		   << org->get_y()	  << " "
		   << org->get_sila() << " "
		   << org->get_inic() << " "
		   << org->get_wiek() << " "
		   << "\n";
	}
}

void Swiat::wczytaj_gre() {
	 
	std::ifstream is(PATH);
	if (!is) { std::cout << "NIE POPRAWNA SCIEZKA PLIKU\n"; }

	unsigned int temp_licznik_tur;
	unsigned int ilosc_organizmow;

	is >> temp_licznik_tur >> ilosc_organizmow;

	this->licznik_tur = temp_licznik_tur;

	for (unsigned int i = 0; i < ilosc_organizmow; i++) {

		char znak;
		
		unsigned int x;
		unsigned int y;
		unsigned int sila;
		unsigned int inic;
		unsigned int wiek;

		is >> znak >> x >> y >> sila >> inic >> wiek;

		this->odtworz_organizmy(znak, x, y, sila, inic, wiek);
	}

	// NA KONIEC WCZYTYWANIE CZYSZCZE PLIK Z POPRZEDNIEGO STANU SWIATA
}
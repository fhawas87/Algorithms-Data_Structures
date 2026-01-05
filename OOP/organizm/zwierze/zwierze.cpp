#include "zwierze.h"
#include "organizm.h"
#include "swiat.h"
#include "gatunki_z.h"

void Zwierze::akcja() {

	unsigned int new_x = this->x;
	unsigned int new_y = this->y;

	while (true) {

		unsigned int new_changed_x = new_x;
		unsigned int new_changed_y = new_y;

		this->losuj_kierunek(new_changed_x, new_changed_y);

		if (this->czy_sie_miesci(new_changed_x, new_changed_y)) {

			new_x = new_changed_x;
			new_y = new_changed_y;

			break;
		}
		else { continue; }
	}

	if (swiat.czy_pole_wolne(new_x, new_y)) { swiat.przenies_organizm(this, new_x, new_y); }
	else { swiat.get_organizm(new_x, new_y)->kolizja(this); }
}

void Zwierze::kolizja(Organizm* inny) {
	if (inny->get_znak() == this->get_znak()) { // ROZMNAZANIE

		unsigned int licznik_pol = 0;

		while (true) { // INFO : MOZE DOJSC DO NIESKONCZONEJ PETLI JEZELI WSZYSTKIE POLA W OKOL BEDA ZAJETE ?

			if (licznik_pol > 4) { break; }

			int temp_x = (int)this->x;
			int temp_y = (int)this->y;

			if (temp_x < 0 || temp_y < 0) { continue; }
			else {

				unsigned int changed_x = (unsigned int)temp_x;
				unsigned int changed_y = (unsigned int)temp_y;

				losuj_kierunek(changed_x, changed_y);

				if (czy_sie_miesci(changed_x, changed_y)) {

					if (swiat.czy_pole_wolne(changed_x, changed_y)) {
						if (this->get_znak() == 'W') {

							swiat.dodaj_organizm(new Wilk(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'L') {

							swiat.dodaj_organizm(new Lis(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'O') {

							swiat.dodaj_organizm(new Owca(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'Z') {

							swiat.dodaj_organizm(new Zolw(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'A') {

							swiat.dodaj_organizm(new Antylopa(changed_x, changed_y, swiat));

							break;
						}
					}
					else { licznik_pol++; continue; }
				}
				else { continue; }
			}
		}
	}
	else {
		if (inny->get_sila() < this->sila) {

			swiat.usun_organizm(this);
		}
		else {
			swiat.przenies_organizm(this, inny->get_x(), inny->get_y());
			swiat.usun_organizm(inny);
		}
	}
}
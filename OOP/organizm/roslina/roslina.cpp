#include "roslina.h"
#include "organizm.h"
#include "swiat.h"
#include "gatunki_r.h"

void Roslina::akcja() {

	if (swiat.losuj(0, 5) == 0) {

		unsigned int licznik_pol = 0; // INFO : ZAPOBIEGA NIESKONCZONEJ PETLI

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
						if (this->get_znak() == 't') {

							swiat.dodaj_organizm(new Trawa(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'm') {

							swiat.dodaj_organizm(new Mlecz(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'g') {

							swiat.dodaj_organizm(new Guarana(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'j') {

							swiat.dodaj_organizm(new WilczeJagody(changed_x, changed_y, swiat));

							break;
						}
						if (this->get_znak() == 'b') {

							swiat.dodaj_organizm(new BarszczSosnowskiego(changed_x, changed_y, swiat));

							break;
						}
					}

					else { licznik_pol++; continue; }
				}
				else { continue; }
			}
		}
	}
}

void Roslina::kolizja(Organizm* inny) {
	
	if (inny->get_sila() < this->sila) { 

		swiat.usun_organizm(inny);
	}
	else {

		unsigned int new_x = this->x;
		unsigned int new_y = this->y;

		swiat.przenies_organizm(inny, new_x, new_y);
		swiat.usun_organizm(this);
    }
}
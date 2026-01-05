#include "gatunki_z.h"
#include "swiat.h"

/*
void Antylopa::akcja() {

	while (true) {

		unsigned int temp_x = this->x;
		unsigned int temp_y = this->y;

		losuj_kierunek(temp_x, temp_y);

		if (this->czy_sie_miesci(temp_x, temp_y)) {
			if (swiat.czy_pole_wolne(temp_x, temp_y)) {

				swiat.przenies_organizm(this, temp_x, temp_y);

				break;
			}
			else {
				
				Organizm* inny = swiat.get_organizm(temp_x, temp_y);

				this->kolizja(inny); break;
			}
		}
	}
}
*/

void Antylopa::losuj_kierunek(unsigned int& new_x, unsigned int& new_y) const {

	unsigned int random = swiat.losuj(0, 3);

	if (random == 0) { new_x += 2; } // PRAWO
	if (random == 1) { new_x -= 2; } // LEWO
	if (random == 2) { new_y += 2; } // DOL
	if (random == 3) { new_y -= 2; } // GORA
}

void Antylopa::kolizja(Organizm* inny) {

	if (inny->get_sila() > this->sila) {
		if (swiat.losuj(0, 1) != 0) {

			while (true) {

				unsigned int temp_x = this->x;
				unsigned int temp_y = this->y;

				losuj_kierunek(temp_x, temp_y);

				if (czy_sie_miesci(temp_x, temp_y)) {

					swiat.przenies_organizm(inny, this->x, this->y);
					swiat.przenies_organizm(this, temp_x, temp_y);

					break;
				}
				else { continue; }
			}
		}
		else {

			swiat.przenies_organizm(inny, this->x, this->y);
			swiat.usun_organizm(this);
		}
	}
	if (inny->get_sila() == this->sila) {

		swiat.przenies_organizm(this, inny->get_x(), inny->get_y());
	}
	else { swiat.usun_organizm(inny); }
}
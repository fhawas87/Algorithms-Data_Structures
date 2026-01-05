#include "gatunki_z.h"
#include "swiat.h"


void Zolw::kolizja(Organizm* inny) {

	if (inny->get_sila() < 5) {

		swiat.przenies_organizm(inny, this->x, this->y);
	}
	else {

		swiat.przenies_organizm(inny, this->x, this->y);
		swiat.usun_organizm(this);
	}
}

void Zolw::akcja() {

	if (swiat.losuj(0, 3) != 0) { return; }

	unsigned int new_x = this->x;
	unsigned int new_y = this->y;

	while (true) {

		unsigned int new_changed_x = new_x;
		unsigned int new_changed_y = new_y;

		this->losuj_kierunek(new_changed_x, new_changed_y);

		if (czy_sie_miesci(new_changed_x, new_changed_y)) {

			new_x = new_changed_x;
			new_y = new_changed_y;

			break;
		}
		else { continue; }
	}

	if (swiat.czy_pole_wolne(new_x, new_y)) { swiat.przenies_organizm(this, new_x, new_y); }
	else { swiat.get_organizm(new_x, new_y)->kolizja(this); }
}
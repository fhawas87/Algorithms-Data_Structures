#include "gatunki_z.h"
#include "swiat.h"

void Lis::akcja() {

	unsigned int new_x = this->x;
	unsigned int new_y = this->y;

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
				if (swiat.get_organizm(temp_x, temp_y)->get_sila() < this->sila) {
					swiat.get_organizm(temp_x, temp_y)->kolizja(this);

					break;
				}
			}
		}
		else { continue; }
	}
}
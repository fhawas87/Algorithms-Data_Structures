#include <conio.h>
#include <iostream>

#include "czlowiek.h"
#include "organizm.h"
#include "swiat.h"

void Czlowiek::akcja() {

	unsigned int new_x = this->x;
	unsigned int new_y = this->y;

	this->wybierz_kierunek(new_x, new_y);

	//std::cout << "\n\n";
	//std::cout << this->x << ", " << this->y << "\n";
	//std::cout << new_x << ", " << new_y << "\n";
 
	if (new_x == this->x && new_y == this->y) { std::cout << "NIE ZMIENILO SIE\n"; return; }
	if (swiat.czy_pole_wolne(new_x, new_y)) { swiat.przenies_organizm(this, new_x, new_y); }
	else { swiat.get_organizm(new_x, new_y)->kolizja(this); }
}

void Czlowiek::wybierz_kierunek(unsigned int& new_x, unsigned int& new_y) {

	while (true) {

		int temp_x = (int)this->x;
		int temp_y = (int)this->y;

		int c = _getch(); std::cout << c << "\n";

		if (c == 'q') { break; } // NIGDZIE SIE NIE RUSZAJ
		
		if (c == 0 || c == 224) {

			c = _getch(); std::cout << c << "\n";

			//if (c == 77) { temp_x++; }
			//if (c == 75) { temp_x--; }
			//if (c == 80) { temp_y++; }
			//if (c == 72) { temp_y--; }

			// Z IFAMI COS TU SIE NIE ZGADZALO I CZYTALO WSZYSTKI EKLAWISZE ALE JEDYNIE STRZALKA /
			// W GORE FAKTYCZNIE ZMIENIALA POZYCJE CZLOWIEKA LECZ NIE POPRAWNIE I CZLOWIEK SZEDL /
			// W PRAWO
			
			switch (c) {

			case 72: temp_x--; break;
			case 80: temp_x++; break;
			case 75: temp_y--; break;
			case 77: temp_y++; break;

			default: continue;
			}

			if (temp_x < 0 || temp_y < 0) { continue; }
			else {

				unsigned int changed_x = (unsigned int)temp_x;
				unsigned int changed_y = (unsigned int)temp_y;

				if (this->czy_sie_miesci(changed_x, changed_y)) {

					new_x = changed_x;
					new_y = changed_y;

					break;
				}
				else { continue; }
			}
		}
	}
}
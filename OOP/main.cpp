#include <thread>
#include <chrono>
#include <conio.h>
#include <iostream>

#include "swiat.h"

int main(void) {

	Swiat swiat;

	while (true) {

		std::cout << "Podaj 't' jezeli chcesz stworzyc nowy swiat lub 'y' jezeli chcesz wczytac swiat\n";

		char c = _getch();

		if (c == 't') { swiat.wczytano = false; break; }
		if (c == 'y') { swiat.wczytano = true; break; }

		else { continue; }
	}

	swiat.wybierz_sposob_inicjalizacji();

	while (true) {

		if (swiat.stop()) { break; }
		else {

			char c = _getch();

			if (c == 'o') {

				swiat.zapisz_gre();
				swiat.stop();

				break;
			}

			swiat.wykonaj_ture(); 
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}

	return 0;
}
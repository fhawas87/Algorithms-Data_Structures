#include "gatunki_r.h"
#include "swiat.h"

void BarszczSosnowskiego::kolizja(Organizm* inny) {

	swiat.usun_organizm(this);
	swiat.usun_organizm(inny);
}

bool w_planszy(const int& x, const int& y, Swiat& swiat) {
	
	if (x < 0 || x > swiat.get_n() || y < 0 || y > swiat.get_m()) { return false; }

	else { return true; }
}

void BarszczSosnowskiego::akcja() {

	// HARD CODE
	// CHYBA UNSIGNED INT SIE TU NIE NADA
	/*
	if (swiat.get_organizm(static_cast<int>(this->x - 1), static_cast<int>(this->y - 1)) != nullptr && w_planszy(static_cast<int>(this->x - 1), static_cast<int>(this->y - 1))) {
		swiat.usun_organizm(swiat.get_organizm(this->x - 1, this->y - 1));
	}
	if (swiat.get_organizm(static_cast<int>(this->x - 1), static_cast<int>(this->y + 1)) != nullptr && w_planszy(static_cast<int>(this->x - 1), static_cast<int>(this->y + 1))) {
		swiat.usun_organizm(swiat.get_organizm(this->x - 1, this->y + 1));
	}
	if (swiat.get_organizm(static_cast<int>(this->x + 1), static_cast<int>(this->y - 1)) != nullptr && w_planszy(static_cast<int>(this->x + 1), static_cast<int>(this->y - 1))) {
		swiat.usun_organizm(swiat.get_organizm(this->x + 1, this->y - 1));
	}
	if (swiat.get_organizm(static_cast<int>(this->x + 1), static_cast<int>(this->y + 1)) != nullptr && w_planszy(static_cast<int>(this->x + 1), static_cast<int>(this->y + 1))) {
		swiat.usun_organizm(swiat.get_organizm(this->x + 1, this->y + 1));
	}
	if (swiat.get_organizm(static_cast<int>(this->x), static_cast<int>(this->y - 1)) != nullptr && w_planszy(static_cast<int>(this->x), static_cast<int>(this->y - 1))) {
		swiat.usun_organizm(swiat.get_organizm(this->x, this->y - 1));
	}
	if (swiat.get_organizm(static_cast<int>(this->x), static_cast<int>(this->y + 1)) != nullptr && w_planszy(static_cast<int>(this->x), static_cast<int>(this->y + 1))) {
		swiat.usun_organizm(swiat.get_organizm(this->x, this->y + 1));
	}
	if (swiat.get_organizm(static_cast<int>(this->x - 1), static_cast<int>(this->y)) != nullptr && w_planszy(static_cast<int>(this->x - 1), static_cast<int>(this->y))) {
		swiat.usun_organizm(swiat.get_organizm(this->x - 1, this->y));
	}
	if (swiat.get_organizm(static_cast<int>(this->x + 1), static_cast<int>(this->y)) != nullptr && w_planszy(static_cast<int>(this->x + 1), static_cast<int>(this->y))) {
		swiat.usun_organizm(swiat.get_organizm(this->x + 1, this->y));
	}
	*/

	static const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static const int dy[8] = { -1, 1, 0, -1, 1, -1, 1, 0 };

	for (unsigned int i = 0; i < 8; i++) {

		int temp_x = this->x + dx[i];
		int temp_y = this->y + dy[i];

		if (w_planszy(temp_x, temp_y, swiat)) {
			if (swiat.get_organizm(temp_x, temp_y) != nullptr) {

				swiat.usun_organizm(swiat.get_organizm(temp_x, temp_y));
			}
			else { continue; }
		}
		else { continue; }
	}
}
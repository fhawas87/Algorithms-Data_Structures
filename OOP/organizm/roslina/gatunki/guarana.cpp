#include "gatunki_r.h"
#include "swiat.h"

void Guarana::kolizja(Organizm* inny) {

	swiat.przenies_organizm(inny, this->x, this->y);
	swiat.usun_organizm(this);
	inny->inc_sila(3);
}
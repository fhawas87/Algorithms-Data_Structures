#include "gatunki_r.h"
#include "swiat.h"

void WilczeJagody::kolizja(Organizm* inny) {

	swiat.usun_organizm(this);
	swiat.usun_organizm(inny);
}
#ifndef _SPRITEDEF_H_
#define _SPRITEDEF_H_

class SpriteDef{
	struct Modulo{
		int id;
		int x;
		int y;
		int w;
		int h;

	};

public:
	Modulo modulos [1];
	SpriteDef();

};
#endif

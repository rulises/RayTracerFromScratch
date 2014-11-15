#include "Color.h"


Color::~Color(void)
{
}

Color coltimes(Color *c1, Color *c2)
{
	Color ret = Color(c1->x*c2->x,c1->y*c2->y, c1->z *c2->z );
    return ret;
}
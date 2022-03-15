
#include "../includes/cube.h"

float	deg_rad(int	a)
{
	return (a * M_PI / 180.0);
}

float	fix_angle(float a)
{
	if (a < 0)
		a += 2 * PI;
	if (a > 2 * PI)
		a -= 2 * PI;
	return (a);
}

float	distance(float ax, float ay,float bx,float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}


#include "../includes/cube.h"

unsigned long createRGB(t_rgb *rgb)
{   
    return ((rgb->r & 0xff) << 16) + ((rgb->g & 0xff) << 8) + (rgb->b & 0xff);
}

t_rgb	*ft_change_bright_color(t_rgb *rgb, float correction)
{
	t_rgb	*rgb_bright;
	float	red;
	float	green;
	float	blue;

	rgb_bright = ft_memalloc(sizeof(t_rgb));
	red = (float)rgb->r;
	green = (float)rgb->g;
	blue =  (float)rgb->b;
	if (correction < 0)
	{
		correction += 1;
		red *= correction;
		green *= correction;
		blue *= correction;
	}

	else
	{
		red = (255 - red) * correction + red;
		green = (255 - green) * correction + green;
		blue = (255 - blue) * correction +  blue;
	}
	rgb_bright->r = (int)red;
	rgb_bright->g = (int)green;
	rgb_bright->b = (int)blue;
	return (rgb_bright);
}

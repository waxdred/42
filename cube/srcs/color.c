
#include "../includes/cube.h"

int	createRGB(t_rgb *rgb)
{   
    return ((rgb->r & 0xff) << 16) + ((rgb->g & 0xff) << 8) + (rgb->b & 0xff);
}

void	ft_set_rgb(t_rgb *rgb, int r, int g, int b)
{
		rgb->r = r;
		rgb->g = g;
		rgb->b = b;
}

int	ft_add_color_rgb(char **tab, t_rgb *rgb)
{
	int	i;
	i = 0;

	while (tab[i])
		i++;
	if (i < 2)
		return (0);
	rgb->r = ft_atoi(tab[0]);
	rgb->g = ft_atoi(tab[1]);
	rgb->b = ft_atoi(tab[2]);
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || rgb->g > 255 || rgb->b < 0 || rgb->b > 255 )
		return (0);
	printf("%d\n", rgb->r);
	return (1);
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

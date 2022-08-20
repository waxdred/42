/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:24:00 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/10 16:37:31 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H

# define DEFINE_H

// gnl

# define BUFFER_SIZE	63
# define MAX_FD			1024

// parsing

# define SPACES		" \n\r\t\v\f"
# define ALLOW_MAP	"0123NSEW"
# define DIR_MAP	"NSEW"
# define EXT_MAP	".cub"

// colors
# define R_COL 3
# define G_COL 2
# define B_COL 1
# define T_COL 0

# define X_WIN 1280
# define Y_WIN 1280

# define MAP_ALL_RAY 0

# define LINE 0
# define RECT 1

# define PI 3.14159265358979323846264338327950288
# define P2 1.57079632679489661923132169163975144
# define P3 4.71238898038468967399694520281627774
# define SQUARES 64
# define RAD 0.0043633231
# define DOF 240
# define HIT_BOX 25
# define SPEED 1
# define HEIGHT	0.75

# define ESC 53
# define ESP 49
# define Z 13
# define T 17
# define S 1
# define Q 0
# define D 2
# define M 41
# define AL 123
# define AR 124
# define AU 126
# define AD 125

# define L_CLICK 1

# define KEY				200
# define KEY_PRESS			2
# define KEY_RELEASE			3
# define MOUSE_PRESS			4
# define MOUSE_RELEASE			5
# define KEY_PRESSMASK 			1L
# define KEY_RELEASEMASK 		2L

#endif

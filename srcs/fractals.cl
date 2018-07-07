# define SQR(n) n * n
# define SQRD(n) SQR(n) * SQR(n)
# define W_W 1000
# define W_H 1000

/************************ FUNCTIONS TO FIND REAL AND IMAGINARY PARTS *******************/

double	find_real_part(int pow, double x, double y)
{
	double xx;

	if (pow == 2)
		xx = SQR(x) - SQR(y);
	if (pow == 3)
		xx = (SQR(x) - 3 * SQR(y)) * x;
	if (pow == 4)
		xx = SQRD(x) + SQRD(y) - 6 * SQR(x) * SQR(y);
	if (pow == 5)
		xx = x * (SQRD(x) - 10 * (SQR(x) * SQR(y)) + 5 * SQRD(y));
	return (xx);
}

double	find_imaginary_part(int pow, double x, double y)
{
	double yy;

	if (pow == 2)
		yy = 2 * x * y;
	if (pow == 3)
		yy = (3 * SQR(x) - SQR(y)) * y;
	if (pow == 4)
		yy = 4 * y * x * (SQR(x) - SQR(y));
	if (pow == 5)
		yy = y * (5 * SQRD(x) - 10 * (SQR(x) * SQR(y)) + SQRD(y));
	return (yy);
}

/********************* FUNCTIONS TO FIND COLOR ************************/

static int 		psycho_color(int iter, int magic)
{
	int color;

    color = iter * magic / (iter * iter * 0.2);
    return (color);
}

static double		percent(double first, double now, double second)
{
	if (now == first)
		return (0.0);
	if (now == second)
		return (1.0);
	return ((now - first) / (second - first));
}

static int	color(int c1, int c2, double percent)
{
	return (c1 + (c2 - c1) * percent);
}

int		colorate(int beforecolor, int aftercolor, int first, int now, int second)
{
	int r;
	int g;
	int b;
	double	respercent;
	
	respercent = percent(first, now, second);
	r = color(((beforecolor >> 16) & 0xFF), ((aftercolor >> 16) & 0xFF), respercent);
	g = color(((beforecolor >> 8) & 0xFF),
		((aftercolor >> 8) & 0xFF), respercent);
	b = color((beforecolor & 0xFF),
		(aftercolor & 0xFF), respercent);
	return (r << 16 | g << 8 | b);
}

/****************** FRACTALS *****************/

__kernel void fractals(
	__global int *output,
	__global double *buffer)
{
	int n;
	int res;
	double xx;
	double yy;
	int color;
	double re;
	double im;

	n = 0;
	res = 0;
	
	/* constant variables */

	double xmin = buffer[0];
	double ymin = buffer[1];
	double dx = buffer[2];
	double dy = buffer[3];
	double mouse_x = buffer[4];
	double mouse_y = buffer[5];
	int maxiterations = buffer[6];
	int pow = buffer[7];
	int beforecolor = buffer[8];
	int aftercolor = buffer[9];
	int set = buffer[10];
	int magic = buffer[11];

	int i = get_global_id(0);
	if (i < 0 || i > W_W * W_H)
		return;
		
	int x = i % W_W;
	int y = i / W_H;


	double x_s = x * dx + xmin;
	double y_s = y * dy + ymin;
	re = x * dx + xmin + mouse_x;
	im = y * dy + ymin + mouse_y;

	if (set == 1) /* MANDELBROT */
	{
		while (n < maxiterations)
		{
			xx = find_real_part(pow, re, im);
			yy = find_imaginary_part(pow, re, im);
			re = xx + x_s;
			im = yy + y_s;
			if ((re * re + im * im) > 16)
			{
				res = 1;
				break;
			}
			n++;
		}	
	}
	else if (set == 2) /* JULIA */
	{
		re = x * dx + xmin;
		im = y * dy + ymin;
		while (n < maxiterations)
		{
			
			xx = find_real_part(pow, re, im);
			yy = find_imaginary_part(pow, re, im);
			re = xx + mouse_x;
			im = yy + mouse_y;
			if ((re * re + im * im) > 16)
			{
				res = 1;
				break;
			}
			n++;
		}
	}
	else if (set == 3) /* TRICORN */
	{
		re = x * dx + xmin + mouse_x;
		im = y * dy + ymin + mouse_y;
		while (n < maxiterations)
		{
			xx = SQR(re) - SQR(im);
			yy = (re * im) * -2.0;
			re = xx + x_s;
			im = yy + y_s;
			if ((re * re + im * im) > 16)
			{
				res = 1;
				break;
			}
			n++;
		}
	}
	else if (set == 4) /* CELTIC */
	{
		re = x * dx + xmin + mouse_x;
		im = y * dy + ymin + mouse_y;
		while (n < maxiterations)
		{
			xx = fabs(SQR(re) - SQR(im));
			yy = (re * im) * 2.0;
			re = xx + x_s;
			im = yy + y_s;
			if ((re * re + im * im) > 16)
			{
				res = 1;
				break;
			}
			n++;
		}
	}
	else if (set == 5) /* BURNING SHIP */
	{
		re = x * dx + xmin + mouse_x;
		im = y * dy + ymin + mouse_y;
		while (n < maxiterations)
		{
			xx = SQR(re) - SQR(im);
			yy = fabs(re * im * 2.0);
			re = xx + x_s;
			im = yy + y_s;
			if ((re * re + im * im) > 16)
			{
				res = 1;
				break;
			}
			n++;
		}
	}
	else if (set == 6) /* HEART */
	{
		re = x * dx + xmin + mouse_x;
		im = y * dy + ymin + mouse_y;
		while (n < maxiterations)
		{
			xx = SQR(re) - SQR(im);
			yy = fabs(re) * im * 2.0;
			re = xx + x_s;
			im = yy + y_s;
			if ((re * re + im * im) > 16)
			{
				res = 1;
				break;
			}
			n++;
		}
	}
	else if (set == 7) /* BUFFALO */
	{
		re = x * dx + xmin;
		im = y * dy + ymin;
		while (n < maxiterations)
		{
			xx = fabs(SQR(re) - SQR(im));
			yy = fabs(re * im) * 2.0;
			re = xx + x_s;
			im = yy + y_s;
			if ((re * re + im * im) > 16)
			{
				res = 1;
				break;
			}
			n++;
		}
	}
	if (res == 1)
	{
		if (magic != 0)
			aftercolor = psycho_color(n, magic);
		color = colorate(beforecolor, aftercolor, 0, n, maxiterations);
		beforecolor = color;
	}
	else
		color = 0x0;
	output[i] = color;
}

//
//3) �� �׸���
//
//- ������ �߰��� ��� ���׸��� �ҽ��� �̿��϶�.
//
//- �߽���, ������, ������ ��ȭ���� ���� ���� ���� �׸���.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BYTE unsigned char
#define W 512
#define H 512

int Iarray[W][H][3];

void circlePlot(int Cx, int Cy, int x, int y) // 8��Ī
{
	setPixel(Cx + x, Cy + y);//marking function according to the output device
	setPixel(Cx - x, Cy + y);
	setPixel(Cx + x, Cy - y);
	setPixel(Cx - x, Cy - y);
	setPixel(Cx + y, Cy + x);
	setPixel(Cx - y, Cy + x);
	setPixel(Cx + y, Cy - x);
	setPixel(Cx - y, Cy - x);
}

void circleMidpoint(int xCenter, int yCenter, int radius)
{
	int x = 0, y = radius, p = 1 - radius;

	circlePlot(xCenter, yCenter, x, y);//start pixel marking..

	while (x <= y) {
		x++;
		if (p < 0) p += 2 * x + 1;
		else { y--; p += 2 * (x - y) + 1; }

		circlePlot(xCenter, yCenter, x, y);//marking..
	}
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BYTE unsigned char
#define W 512
#define H 512

BYTE Iarray[W][H][3];
int r, g, b;	// RGB

void setPixel(int x, int y) {	// set Pixel
	Iarray[x][y][0] = r;
	Iarray[x][y][1] = g;
	Iarray[x][y][2] = b;
}

void ellipsePlot(int Cx, int Cy, int x, int y) // 4 symmetry
{
	setPixel(Cx + x, Cy + y);//marking function according to the output device
	setPixel(Cx - x, Cy + y);
	setPixel(Cx + x, Cy - y);
	setPixel(Cx - x, Cy - y);
}

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry) // Ellipse Mid Point
{
	int Rx2 = Rx * Rx, Ry2 = Ry * Ry, twoRx2 = 2 * Rx2, twoRy2 = 2 * Ry2;
	int p, x = 0, y = Ry, px = 0, py = twoRx2 * y;

	ellipsePlot(xCenter, yCenter, x, y);//start pixel marking..

	//Region 1
	p = round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
	while (px < py) {
		x++;
		px += twoRy2;
		if (p < 0) p += Ry2 + px;
		else { y--; py -= twoRx2; p += Ry2 + px - py; }

		ellipsePlot(xCenter, yCenter, x, y);//marking..
	}

	//Region 2
	p = round(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
	while (y > 0) {
		y--;
		py -= twoRx2;
		if (p > 0) p += Rx2 - py;
		else { x++; px += twoRy2; p += Rx2 - py + px; }

		ellipsePlot(xCenter, yCenter, x, y);//marking..
	}
}

int main() {
	FILE* fp;

	// background color : white
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			Iarray[i][j][0] = 255;
			Iarray[i][j][1] = 255;
			Iarray[i][j][2] = 255;
		}
	}

	// EllipseMidpoint
	r = 0, b = 255, g = 0;
	ellipseMidpoint(250, 250, 100, 30);
	r = 0, b = 0, g = 255;
	ellipseMidpoint(100, 100, 50, 100);
	r = 255, b = 0, g = 0;
	ellipseMidpoint(300, 50, 200, 10);


	// File
	fp = fopen("MidPointEllipse.ppm", "wb");
	fprintf(fp, "P6\n");
	fprintf(fp, "%d %d\n", W, H);
	fprintf(fp, "255\n");
	fwrite(Iarray, sizeof(char), H * W * 3, fp);
	fclose(fp);

	return 0;
}

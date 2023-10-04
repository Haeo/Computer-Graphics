#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BYTE unsigned char
#define W 512
#define H 512

BYTE Iarray[W][H][3];
int r, g, b;	// RGB

void setPixel(int x, int y) { // set Pixel
	Iarray[x][y][0] = r;
	Iarray[x][y][1] = g;
	Iarray[x][y][2] = b;
}

void circlePlot(int Cx, int Cy, int x, int y) // 8 symmetry
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

	// MidPointCircle
	r = 0, b = 255, g = 0;
	circleMidpoint(250, 50, 30);
	r = 255, b = 0, g = 0;
	circleMidpoint(300, 300, 100);
	r = 0, b = 0, g = 255;
	circleMidpoint(250, 250, 200);

	// File
	fp = fopen("MidPointCircle.ppm", "wb");
	fprintf(fp, "P6\n");
	fprintf(fp, "%d %d\n", W, H);
	fprintf(fp, "255\n");
	fwrite(Iarray, sizeof(char), H * W * 3, fp);
	fclose(fp);

	return 0;
}

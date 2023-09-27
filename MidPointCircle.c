//
//3) 원 그리기
//
//- 제공된 중간점 기법 원그리기 소스를 이용하라.
//
//- 중심점, 반지름, 원색을 변화시켜 여러 개의 원을 그리기.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BYTE unsigned char
#define W 512
#define H 512

int Iarray[W][H][3];
int r, g, b;

void setPixel(int x, int y) {
	Iarray[x][y][0] = r;
	Iarray[x][y][1] = g;
	Iarray[x][y][2] = b;
}

void circlePlot(int Cx, int Cy, int x, int y) // 8대칭
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

int main()
{
	FILE* fp;
		
	// background color : white
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			Iarray[i][j][0] = 255;
			Iarray[i][j][1] = 255;
			Iarray[i][j][2] = 255;
		}
	}
	

	fp = fopen("MidPointCircle.ppm", "wb");
	fprintf(fp, "P6\n");
	fprintf(fp, "%d %d\n", W, H);
	fprintf(fp, "255\n");
	fwrite(Iarray, sizeof(char), H * W * 3, fp);
	fclose(fp);

	return 0;
}
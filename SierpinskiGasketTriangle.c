#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BYTE unsigned char
#define N 500

BYTE Iarray[N][N];

// DDA
void lineDDA(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1, dy = y2 - y1, step, k;
	float xinc, yinc, x = (float)x1, y = (float)y1;

	if (abs(dx) > abs(dy)) step = abs(dx);
	else step = abs(dy);
	xinc = dx / (float)step;
	yinc = dy / (float)step;

	Iarray[x1][y1] = 0;

	int i = 0;
	for (k = 0; k < step; k++) {
		x += xinc;
		y += yinc;

		Iarray[(int)(x + 0.5)][(int)(y + 0.5)] = 0;

		i++;
		i %= 8;
	}
}

// Sierpinski Triangle
void Sierpinski(int n, int x1, int y1, int x2, int y2, int x3, int y3) {
	if (n == 0) {
		return;
	}
	else {
		int mid1x = (x1 + x2) / 2;
		int mid1y = (y1 + y2) / 2;
		int mid2x = (x2 + x3) / 2;
		int mid2y = (y2 + y3) / 2;
		int mid3x = (x1 + x3) / 2;
		int mid3y = (y1 + y3) / 2;

		lineDDA(x1, y1, x2, y2);
		lineDDA(x2, y2, x3, y3);
		lineDDA(x3, y3, x1, y1);

		Sierpinski(n - 1, x1, y1, mid1x, mid1y, mid3x, mid3y);
		Sierpinski(n - 1, mid1x, mid1y, x2, y2, mid2x, mid2y);
		Sierpinski(n - 1, mid3x, mid3y, mid2x, mid2y, x3, y3);
	}
}

int main() {
	FILE* fp;

	// background color : white
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Iarray[i][j] = 255;
		}
	}

	Sierpinski(8, 10, 250, 490, 10, 490, 490);

	// File
	fp = fopen("Sierpinski.pgm", "wb");
	fprintf(fp, "P5\n");
	fprintf(fp, "%d %d\n", N, N);
	fprintf(fp, "255\n");
	fwrite(Iarray, sizeof(char), N * N, fp);
	fclose(fp);

	return 0;
}


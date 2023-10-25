#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BYTE unsigned char
#define N 500

BYTE Iarray[N][N];

// DDA line
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

// Koch Curve
void kochCurve(int x1, int y1, int x2, int y2, int count) {
	if (count == 0) {
		lineDDA(x1, y1, x2, y2);
	}
	else {
		int x1_temp = (2 * x1 + x2) / 3;
		int y1_temp = (2 * y1 + y2) / 3;
		int x2_temp = (x1 + 2 * x2) / 3;
		int y2_temp = (y1 + 2 * y2) / 3;
		int x3 = x1_temp + (x2_temp - x1_temp) / 2 - (y2_temp - y1_temp) * sqrt(3) / 2;
		int y3 = y1_temp + (x2_temp - x1_temp) * sqrt(3) / 2 + (y2_temp - y1_temp) / 2;
		
		kochCurve(x1, y1, x1_temp, y1_temp, count - 1);
		kochCurve(x1_temp, y1_temp, x3, y3, count - 1);
		kochCurve(x3, y3, x2_temp, y2_temp, count - 1);
		kochCurve(x2_temp, y2_temp, x2, y2, count - 1);
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

	// loop count
	int count = 5;

	// square shape
	//kochCurve(400, 250, 250, 100, count);
	//kochCurve(250, 100, 100, 250, count);
	//kochCurve(100, 250, 250, 400, count);
	//kochCurve(250, 400, 400, 250, count);

	// sparkle shape
	kochCurve(280, 280, 450, 250, count);
	kochCurve(250, 450, 280, 280, count);
	kochCurve(220, 280, 250, 450, count);
	kochCurve(50, 250, 220, 280, count);
	kochCurve(220, 220, 50, 250, count);
	kochCurve(250, 50, 220, 220, count);
	kochCurve(280, 220, 250, 50, count);
	kochCurve(450, 250, 280, 220, count);
	
	// File
	fp = fopen("KochCurve.pgm", "wb");
	fprintf(fp, "P5\n");
	fprintf(fp, "%d %d\n", N, N);
	fprintf(fp, "255\n");
	fwrite(Iarray, sizeof(char), N * N, fp);
	fclose(fp);

	return 0;
}


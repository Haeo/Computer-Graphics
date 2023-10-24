#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BYTE unsigned char
#define N 500

BYTE Iarray[N][N];

// radian
#define ANGLE(x) (x * M_PI / 180.0)

// DDA algorithm
void lineDDA(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1, dy = y2 - y1, step, k;
	float xinc, yinc, x = (float)x1, y = (float)y1;

	if (abs(dx) > abs(dy)) step = abs(dx);
	else step = abs(dy);
	xinc = dx / (float)step;
	yinc = dy / (float)step;

	if (x1 >= N || y1 >= N) {
		return;
	}
	else {
		Iarray[x1][y1] = 0;
	}
	
	int i = 0;
	for (k = 0; k < step; k++) {
		x += xinc;
		y += yinc;

		if (x + 0.5 > N || y + 0.5 > N) {
			continue;
		}
		else {
			Iarray[(int)(x + 0.5)][(int)(y + 0.5)] = 0;
		}
		

		i++;
		i %= 8;
	}
}

// BST draw Algorithm
void drawBST(int x, int y, double angle, double length, int n, int isrand) {
	int diff;
	if (isrand == 0) {
		diff = 20;
	}
	else {
		diff = (int)rand() % 50 + 5;
	}
	if (n > 0) {
		int rightX = x + (int)(length * cos(ANGLE(angle - diff)));
		int rightY = y + (int)(length * sin(ANGLE(angle - diff)));

		lineDDA(x, y, rightX, rightY);

		drawBST(rightX, rightY, ANGLE(angle - diff), length * 0.6, n - 1, isrand);

		int leftX = x + (int)(length * cos(ANGLE(angle + diff)));
		int leftY = y + (int)(length * sin(ANGLE(angle + diff)));

		lineDDA(x, y, leftX, leftY);

		drawBST(leftX, leftY, ANGLE(angle + diff), length * 0.6, n - 1, isrand);
	}
}

int main() {
	FILE* fp;
	srand(time(NULL));

	// background color : white
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Iarray[i][j] = 255;
		}
	}

	// drawing Symmetric BST
	lineDDA(450, 180, 350, 180);
	drawBST(350, 180, ANGLE(180), 100, 6, 0);
	
	// drawing Random BST
	lineDDA(450, 360, 350, 360);
	drawBST(350, 360, ANGLE(180), 60, 6, 1);

	// File
	fp = fopen("BST.pgm", "wb");
	fprintf(fp, "P5\n");
	fprintf(fp, "%d %d\n", N, N);
	fprintf(fp, "255\n");
	fwrite(Iarray, sizeof(char), N * N, fp);
	fclose(fp);

	return 0;
}


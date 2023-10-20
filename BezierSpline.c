#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BYTE unsigned char
#define N 500

BYTE Iarray[N][N];
BYTE linePattern[6] = { 1,1,0,1,1,0 }; // 파선 패턴

// 제어점
typedef struct {
	int x;
	int y;
}Point;

// Bezier 
Point Bezier(Point p0, Point p1, Point p2, Point p3, double t)
{
	Point result;
	double oneMinusT = 1 - t;
	double oneMinusT2 = oneMinusT * oneMinusT;
	double t2 = t * t;

	result.x = oneMinusT2 * oneMinusT * p0.x + 3 * oneMinusT2 * t * p1.x + 3 * oneMinusT * t2 * p2.x + t2 * t * p3.x;
	result.y = oneMinusT2 * oneMinusT * p0.y + 3 * oneMinusT2 * t * p1.y + 3 * oneMinusT * t2 * p2.y + t2 * t * p3.y;

	return result;
}

// 선 그리기
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

		if (linePattern[i] == 1) { // 파선
			Iarray[(int)(x + 0.5)][(int)(y + 0.5)] = 0;
		}
		else {
			Iarray[(int)(x + 0.5)][(int)(y + 0.5)] = 255;
		}

		i++;
		i %= 8;
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

	// 제어점 : 3개
	Point p0, p1, p2, p3;
	p0.x = 50;
	p0.y = 50;
	p1.x = 150;
	p1.y = 400;
	p2.x = 350;
	p2.y = 50;
	p3.x = 450;
	p3.y = 250;

	// 파선
	lineDDA(p0.x, p0.y, p1.x, p1.y);
	lineDDA(p1.x, p1.y, p2.x, p2.y);
	lineDDA(p2.x, p2.y, p3.x, p3.y);

	// Bezier
	for (int i = 0; i < N - 1; i++) {
		double t1 = (double)i / (double)(N - 1);
		double t2 = (double)(i + 1) / (double)(N - 1);
		Point startPoint = Bezier(p0, p1, p2, p3, t1);
		Point endPoint = Bezier(p0, p1, p2, p3, t2);
		lineDDA((int)startPoint.x, (int)startPoint.y, (int)endPoint.x, (int)endPoint.y);
	}

	// File
	fp = fopen("BezierSpline.pgm", "wb");
	fprintf(fp, "P5\n");
	fprintf(fp, "%d %d\n", N, N);
	fprintf(fp, "255\n");
	fwrite(Iarray, sizeof(char), N * N, fp);
	fclose(fp);

	return 0;
}


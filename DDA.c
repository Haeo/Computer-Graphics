//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define BYTE unsigned char
//#define H 512
//#define W 512
//
//BYTE Iarray[W][H][3];
//
//// solid, dashed, dotted
//int linepattern[3][8] = { 1,1,1,1,1,1,1,1,
//						1,1,1,1,0,0,0,0,
//						1,0,1,0,1,0,1,0 };
//
//void lineDDA(int x1, int y1, int x2, int y2, int r, int g, int b, int patt)
//{
//	int dx = x2 - x1, dy = y2 - y1, step, k;
//	float xinc, yinc, x = (float)x1, y = (float)y1;
//
//	if (abs(dx) > abs(dy)) step = abs(dx);
//	else step = abs(dy);
//	xinc = dx / (float)step;
//	yinc = dy / (float)step;
//
//	Iarray[x1][y1][0] = r;// start pixel marking(setpixel function)
//	Iarray[x1][y1][1] = g;
//	Iarray[x1][y1][2] = b;
//
//	int i = 0;
//	for (k = 0; k < step; k++) {
//		x += xinc;
//		y += yinc;
//		
//		if (linepattern[patt][i] == 1) {
//			Iarray[(int)(x + 0.5)][(int)(y + 0.5)][0] = r * linepattern[patt][i];// marking(setpixel function)
//			Iarray[(int)(x + 0.5)][(int)(y + 0.5)][1] = g * linepattern[patt][i];
//			Iarray[(int)(x + 0.5)][(int)(y + 0.5)][2] = b * linepattern[patt][i];
//		}
//		else{
//			Iarray[(int)(x + 0.5)][(int)(y + 0.5)][0] = 255;
//			Iarray[(int)(x + 0.5)][(int)(y + 0.5)][1] = 255;
//			Iarray[(int)(x + 0.5)][(int)(y + 0.5)][2] = 255;
//		}
//		
//		i++;
//		i %= 8;
//	}
//}
//
//int main() {
//	FILE* fp;
//
//	// background color : white
//	for (int i = 0; i < W; i++) {
//		for (int j = 0; j < H; j++) {
//			Iarray[i][j][0] = 255;
//			Iarray[i][j][1] = 255;
//			Iarray[i][j][2] = 255;
//		}
//	}
//
//	// x1, y1, x2, y2, r, g, b, line pattern
//	lineDDA(10, 10, 50, 500, 255, 255, 0, 0);
//	lineDDA(30, 40, 100, 350, 0, 255, 255, 1);
//	lineDDA(400, 100, 5, 300, 255, 0, 255, 2);
//
//	fp = fopen("DDA.ppm", "wb");
//	fprintf(fp, "P6\n");
//	fprintf(fp, "%d %d\n", W, H);
//	fprintf(fp, "255\n");
//	fwrite(Iarray, sizeof(char), H * W * 3, fp);
//	fclose(fp);
//
//	return 0;
//}
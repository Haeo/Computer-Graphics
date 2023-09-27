//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define BYTE unsigned char
//#define W 512
//#define H 512
//
//BYTE Iarray[W][H][3];
//
//void lineBres(int x1, int y1, int x2, int y2, int r, int g, int b)
//{
//	int dx = abs(x2 - x1), dy = abs(y2 - y1);
//	int p, twoDy, twoDyDx;
//	int x, y, xEnd, yEnd, IorD; // IorD => 기울기가 감소되는 경우(-1<m<0), 증가되는 경우(0<m<1) 계산
//
//	if (dx > dy) {
//		p = 2 * dy - dx; twoDy = 2 * dy; twoDyDx = 2 * (dy - dx);
//
//		if (x1 > x2) { x = x2; y = y2; xEnd = x1; if (y1 - y2 > 0)IorD = 1; else IorD = -1; }
//		else { x = x1; y = y1; xEnd = x2; if (y2 - y1 > 0)IorD = 1; else IorD = -1; }
//
//		Iarray[x][y][0] = r; Iarray[x][y][1] = g; Iarray[x][y][2] = b;// start point marking with a user-defined color(r,g,b) 
//
//		while (x < xEnd) {
//			x++;
//			if (p < 0) p += twoDy;
//			else { y += IorD; p += twoDyDx; }
//			Iarray[x][y][0] = r; Iarray[x][y][1] = g; Iarray[x][y][2] = b;//marking
//		}// end of while
//	}// end of if
//	else { // 기울기가 1보다 큰 경우, |m| > 1 
//		p = 2 * dx - dy; twoDy = 2 * dx; twoDyDx = 2 * (dx - dy);
//		
//		if (y1 > y2) { x = x2; y = y2; yEnd = y1; if (x1 - x2 > 0) IorD = 1; else IorD = -1; }
//		else { x = x1; y = y1; yEnd = y2; if (x2 - x1 > 0)IorD = 1; else IorD = -1; }
//
//		Iarray[x][y][0] = r; Iarray[x][y][1] = g; Iarray[x][y][2] = b;
//
//		while (y < yEnd) {
//			y++;
//			if (p < 0) p += twoDy;
//			else { x += IorD; p += twoDyDx; }
//			Iarray[x][y][0] = r; Iarray[x][y][1] = g; Iarray[x][y][2] = b;
//		}
//	}// end of else
//
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
//	lineBres(100, 400, 300, 30, 100, 100, 100);
//	lineBres(10, 350, 500, 200, 100, 255, 100);
//
//	fp = fopen("Bresenham.ppm", "wb");
//	fprintf(fp, "P6\n");
//	fprintf(fp, "%d %d\n", W, H);
//	fprintf(fp, "255\n");
//	fwrite(Iarray, sizeof(char), H * W * 3, fp);
//	fclose(fp);
//	
//	return 0;
//}
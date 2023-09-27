//4) 타원 그리기
//
//- 제공된 중간점 기법 타원그리기 소스를 이용하라.
//
//- 중심점, rx, ry, 타원색 및 회전 각도를 적용시켜 다양한 타원을 출력하라.
//

//
//void ellipsePlot(int Cx, int Cy, int x, int y) // 4대칭
//{
//	setPixel(Cx + x, Cy + y);//marking function according to the output device
//	setPixel(Cx - x, Cy + y);
//	setPixel(Cx + x, Cy - y);
//	setPixel(Cx - x, Cy - y);
//}
//
//void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry) // 타원
//{
//	int Rx2 = Rx * Rx, Ry2 = Ry * Ry, twoRx2 = 2 * Rx2, twoRy2 = 2 * Ry2;
//	int p, x = 0, y = Ry, px = 0, py = twoRx2 * y;
//
//	ellipsePlot(xCenter, yCenter, x, y);//start pixel marking..
//
//	//Region 1 => m이 -1이 될 때까지
//	p = ROUND(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
//	while (px < py) {
//		x++;
//		px += twoRy2;
//		if (p < 0) p += Ry2 + px;
//		else { y--; py -= twoRx2; p += Ry2 + px - py; }
//
//		ellipsePlot(xCenter, yCenter, x, y);//marking..
//	}
//
//	//Region 2 => 기울기가 -1보다 커짐
//	p = ROUND(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
//	while (y > 0) {
//		y--;
//		py -= twoRx2;
//		if (p > 0) p += Rx2 - py;
//		else { x++; px += twoRy2; p += Rx2 - py + px; }
//
//		ellipsePlot(xCenter, yCenter, x, y);//marking..
//	}
//}
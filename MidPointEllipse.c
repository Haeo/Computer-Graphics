//4) Ÿ�� �׸���
//
//- ������ �߰��� ��� Ÿ���׸��� �ҽ��� �̿��϶�.
//
//- �߽���, rx, ry, Ÿ���� �� ȸ�� ������ ������� �پ��� Ÿ���� ����϶�.
//

//
//void ellipsePlot(int Cx, int Cy, int x, int y) // 4��Ī
//{
//	setPixel(Cx + x, Cy + y);//marking function according to the output device
//	setPixel(Cx - x, Cy + y);
//	setPixel(Cx + x, Cy - y);
//	setPixel(Cx - x, Cy - y);
//}
//
//void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry) // Ÿ��
//{
//	int Rx2 = Rx * Rx, Ry2 = Ry * Ry, twoRx2 = 2 * Rx2, twoRy2 = 2 * Ry2;
//	int p, x = 0, y = Ry, px = 0, py = twoRx2 * y;
//
//	ellipsePlot(xCenter, yCenter, x, y);//start pixel marking..
//
//	//Region 1 => m�� -1�� �� ������
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
//	//Region 2 => ���Ⱑ -1���� Ŀ��
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
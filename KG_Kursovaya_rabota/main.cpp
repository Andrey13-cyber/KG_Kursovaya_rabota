<<<<<<< HEAD
#include <conio.h>
#include "Parallel.h"
#include "TrianglePyramid.h"

void cur();

int main() {

	system("color 58");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, nullptr);

	cur();
	return 0;
}

void cur() {

	int c;
	char flag = '+';
	Bitmap bmp1(
		(int)DIM_BMP_ONE::width, 
		(int)DIM_BMP_ONE::height, 
		(int)DIM_BMP_ONE::left_margin, 
		(int)DIM_BMP_ONE::top_margin,
		(COLORREF)COL_BMP::clear
	);
	Bitmap bmp2(
		(int)DIM_BMP_TWO::width,
		(int)DIM_BMP_TWO::height,
		(int)DIM_BMP_TWO::left_margin,
		(int)DIM_BMP_TWO::top_margin,
		(COLORREF)COL_BMP::clear
	);
	Parallel b1(
		&bmp1, 
		(size_t)NUM_VER::cube,
		(size_t)NUM_FACE::cube
		);
	TrianglePyramid b2(
		&bmp1,
		(size_t)NUM_VER::pyr,
		(size_t)NUM_FACE::pyr
	);
	Figure *ptr = &b1;
	bmp1.DrawBitmap();
	bmp2.DrawBitmap();
	while (1) {
		c = _getch();
		switch (c) {
		case 43:
			ptr->move('z', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 45:
			ptr->move('z', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 72:
			ptr->move('y', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 77:
			ptr->move('x', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 80:
			ptr->move('y', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 75:
			ptr->move('x', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 49:
			ptr = &b1;
			break;
		case 50:
			ptr = &b2;
			break;
		case 32:
			(flag == '+') ? flag = '-' : flag = '+';
			break;
		case 120:
			ptr->rotate('x', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 121:
			ptr->rotate('y', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 122:
			ptr->rotate('z', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 115:
			ptr->zoom('-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 116:
			ptr->zoom('+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		}
	}
=======
#include <conio.h>
#include "Parallel.h"
#include "TrianglePyramid.h"

void cur();

int main() {

	system("color 58");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, nullptr);

	cur();
	return 0;
}

void cur() {

	int c;
	char flag = '+';
	Bitmap bmp1(
		(int)DIM_BMP_ONE::width, 
		(int)DIM_BMP_ONE::height, 
		(int)DIM_BMP_ONE::left_margin, 
		(int)DIM_BMP_ONE::top_margin,
		(COLORREF)COL_BMP::clear
	);
	Bitmap bmp2(
		(int)DIM_BMP_TWO::width,
		(int)DIM_BMP_TWO::height,
		(int)DIM_BMP_TWO::left_margin,
		(int)DIM_BMP_TWO::top_margin,
		(COLORREF)COL_BMP::clear
	);
	Parallel b1(
		&bmp1, 
		(size_t)NUM_VER::cube,
		(size_t)NUM_FACE::cube
		);
	TrianglePyramid b2(
		&bmp1,
		(size_t)NUM_VER::pyr,
		(size_t)NUM_FACE::pyr
	);
	Figure *ptr = &b1;
	bmp1.DrawBitmap();
	bmp2.DrawBitmap();
	while (1) {
		c = _getch();
		switch (c) {
		case 43:
			ptr->move('z', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 45:
			ptr->move('z', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 72:
			ptr->move('y', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 77:
			ptr->move('x', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 80:
			ptr->move('y', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 75:
			ptr->move('x', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 49:
			ptr = &b1;
			break;
		case 50:
			ptr = &b2;
			break;
		case 32:
			(flag == '+') ? flag = '-' : flag = '+';
			break;
		case 120:
			ptr->rotate('x', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 121:
			ptr->rotate('y', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 122:
			ptr->rotate('z', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 115:
			ptr->zoom('-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 116:
			ptr->zoom('+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		}
	}
>>>>>>> edec401c9b420f6dd8ce8b5adcb2b47a12c17905
}
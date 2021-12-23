<<<<<<< HEAD
#pragma once
#include <windows.h>
#include "Matrica.h"
#include "BITMAP.h"
#include "Function.h"
#define PI 3.141592


enum class DIM_BMP_ONE {
	left_margin		=	10,
	top_margin		=	10,
	width			=	600,
	height			=	610
};
enum class DIM_BMP_TWO {
	left_margin		=	1000,
	top_margin		=	1000,
	width			=	1000,
	height			=	1000
};
enum class COL_BMP {
	clear	=	RGB_BMP(255, 255, 255),
	shadow	=	RGB_BMP(40, 40, 40)
};
enum class PYR {
	zero	=	RGB_BMP(11, 0, 242),
	one		=	RGB_BMP(12, 242, 0),
	two		=	RGB_BMP(255, 0, 0),
	three	=	RGB_BMP(255, 242, 0)
};
enum class CUBE {
	zero	=	RGB_BMP(0, 128, 255),
	one		=	RGB_BMP(247, 0, 0),
	two		=	RGB_BMP(0, 255, 128),
	three	=	RGB_BMP(255, 153, 0),
	four	=	RGB_BMP(255, 0, 229),
	five	=	RGB_BMP(0, 255, 253)
};
enum class NUM_VER {
	pyr		=	 4,
	cube	=	 8
};
enum class NUM_FACE {
	pyr = 4,
	cube = 6
};
enum class LIGHT {
	offset_Y = 450
};

const double	ANGLE		=	0.05;
const int		STEP		=	6;
const double	ZOOM_PLUS	=	1.25;
const double	ZOOM_MINUS	=	1 / ZOOM_PLUS;

class Figure {
public:
	enum {
		dim = 4
	};
	Figure(Bitmap *bmp, size_t numVer, size_t numFace);
	~Figure();

	void rotate(char, char);
	void move(char, char);
	void zoom(char);

	void print();
	void SetBitMap();
protected:
	virtual void SetFigure() = 0;
	virtual void ClrFigure() = 0;
	virtual void BasisOfFigure() = 0;

	void Test();
	Matrica V;
	size_t numFace;
	Vector e;

	Vector *VerPR;
	void SetPR();

	double sinAlpha;
	double cosAlpha;
	
	Vector center;
	void SetCenter();

	Vector *Ver;
	size_t numVer;

	Matrica ROTATE;
	Matrica ZOOM;

	Vector result;

	Matrica PR;
	
	Bitmap *bmp;

	Vector *VerSHDW;
	void SetShadow();
=======
#pragma once
#include <windows.h>
#include "Matrica.h"
#include "BITMAP.h"
#include "Function.h"
#define PI 3.141592


enum class DIM_BMP_ONE {
	left_margin		=	10,
	top_margin		=	10,
	width			=	600,
	height			=	610
};
enum class DIM_BMP_TWO {
	left_margin		=	1000,
	top_margin		=	1000,
	width			=	1000,
	height			=	1000
};
enum class COL_BMP {
	clear	=	RGB_BMP(255, 255, 255),
	shadow	=	RGB_BMP(40, 40, 40)
};
enum class PYR {
	zero	=	RGB_BMP(11, 0, 242),
	one		=	RGB_BMP(12, 242, 0),
	two		=	RGB_BMP(255, 0, 0),
	three	=	RGB_BMP(255, 242, 0)
};
enum class CUBE {
	zero	=	RGB_BMP(0, 128, 255),
	one		=	RGB_BMP(247, 0, 0),
	two		=	RGB_BMP(0, 255, 128),
	three	=	RGB_BMP(255, 153, 0),
	four	=	RGB_BMP(255, 0, 229),
	five	=	RGB_BMP(0, 255, 253)
};
enum class NUM_VER {
	pyr		=	 4,
	cube	=	 8
};
enum class NUM_FACE {
	pyr = 4,
	cube = 6
};
enum class LIGHT {
	offset_Y = 450
};

const double	ANGLE		=	0.05;
const int		STEP		=	6;
const double	ZOOM_PLUS	=	1.25;
const double	ZOOM_MINUS	=	1 / ZOOM_PLUS;

class Figure {
public:
	enum {
		dim = 4
	};
	Figure(Bitmap *bmp, size_t numVer, size_t numFace);
	~Figure();

	void rotate(char, char);
	void move(char, char);
	void zoom(char);

	void print();
	void SetBitMap();
protected:
	virtual void SetFigure() = 0;
	virtual void ClrFigure() = 0;
	virtual void BasisOfFigure() = 0;

	void Test();
	Matrica V;
	size_t numFace;
	Vector e;

	Vector *VerPR;
	void SetPR();

	double sinAlpha;
	double cosAlpha;
	
	Vector center;
	void SetCenter();

	Vector *Ver;
	size_t numVer;

	Matrica ROTATE;
	Matrica ZOOM;

	Vector result;

	Matrica PR;
	
	Bitmap *bmp;

	Vector *VerSHDW;
	void SetShadow();
>>>>>>> edec401c9b420f6dd8ce8b5adcb2b47a12c17905
};
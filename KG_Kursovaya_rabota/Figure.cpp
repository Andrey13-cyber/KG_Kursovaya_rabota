#include "Figure.h"
#include <cmath>
#include <iostream>

Figure::Figure(Bitmap*bmp, size_t numVer, size_t numFace) {
	Ver = new Vector[numVer];
	VerPR = new Vector[numVer];
	VerSHDW = new Vector[numVer];
	e.resize(Figure::dim);
	result.resize(Figure::dim);
	e.setVector(0.0, 0.0, 1.0, 0.0);
	for (size_t i = 0; i < numVer; ++i) {
		Ver[i].resize(Figure::dim);
		VerPR[i].resize(Figure::dim);
		VerSHDW[i].resize(Figure::dim);
	}
	ROTATE.newMatrica(Figure::dim, Figure::dim);
	ZOOM.newMatrica(Figure::dim, Figure::dim);
	PR.newMatrica(Figure::dim, Figure::dim);
	V.newMatrica(Figure::dim, numFace);
	double a1 = cos(PI / 6);
	double a2 = sin(PI / 6);
	double b1 = cos(PI / 6);
	double b2 = sin(PI / 6);
	PR.setMatrica(
		       a1,     -a2,  0.0, 0.0,
		  a2 * b1, a1 * b1,  -b2, 0.0,
		  a2 * b2, a1 * b2,   b1, 0.0,
		      0.0,     0.0,  0.0, 1.0
	);
	Matrica PR_(4,4);
	PR_.setMatrica(
	   	 a1, a2 * b1, a2 * b2, 0.0,
		-a2, a1 * b1, a1 * b2, 0.0,
		0.0,     -b2,      b1, 0.0,
		0.0,     0.0,     0.0, 1.0
	);
	e = PR_ * e;
	center.resize(Figure::dim);
	sinAlpha = sin(ANGLE);
	cosAlpha = cos(ANGLE);
	this->numVer = numVer;
	this->numFace = numFace;
	this->bmp = bmp;
}
Figure::~Figure() {
	delete[] Ver;
	delete[] VerPR;
	delete[] VerSHDW;
}
void Figure::rotate(char ch, char pn) {
	size_t i;
	ClrFigure();
	switch (ch) {
	case 'x':
		switch (pn) {
		case '+':
			ROTATE.setMatrica(		
				1.0,       0.0,       0.0,                                                      0.0,
				0.0,  cosAlpha,  sinAlpha, -cosAlpha * center[1] + center[1] - sinAlpha * center[2],
				0.0, -sinAlpha,  cosAlpha,  sinAlpha * center[1] + center[2] - cosAlpha * center[2],
				0.0,       0.0,       0.0,                                                      1.0
			);
			break;
		case '-':
			ROTATE.setMatrica(		
				1.0,       0.0,       0.0,                                                      0.0,
				0.0,  cosAlpha, -sinAlpha, -cosAlpha * center[1] + center[1] + sinAlpha * center[2],
				0.0,  sinAlpha,  cosAlpha, -sinAlpha * center[1] + center[2] - cosAlpha * center[2],
				0.0,       0.0,       0.0,                                                      1.0
			);
			break;
		}
		break;
	case 'y':
		switch (pn) {
		case '+':
			ROTATE.setMatrica(
				cosAlpha, 0.0, -sinAlpha, -cosAlpha * center[0] + center[0] + sinAlpha * center[2],
					 0.0, 1.0,       0.0,                                                      0.0,
				sinAlpha, 0.0,  cosAlpha, -sinAlpha * center[0] + center[2] - cosAlpha * center[2],
					 0.0, 0.0,       0.0,                                                      1.0
			);
			break;
		case '-':
			ROTATE.setMatrica(
				 cosAlpha, 0.0, sinAlpha, -cosAlpha * center[0] + center[0] - sinAlpha * center[2],
					  0.0, 1.0,      0.0,                                                      0.0,
				-sinAlpha, 0.0, cosAlpha,  sinAlpha * center[0] + center[2] - cosAlpha * center[2],
					  0.0, 0.0,      0.0,                                                      1.0
			);
			break;
		}
		break;
	case 'z':
		switch (pn) {
		case '+':
			ROTATE.setMatrica(		
				 cosAlpha,  sinAlpha,   0.0,  -cosAlpha * center[0] + center[0] - sinAlpha * center[1],
				-sinAlpha,  cosAlpha,   0.0,   sinAlpha * center[0] + center[1] - cosAlpha * center[1],
					  0.0,       0.0,   1.0,                                                       0.0,
					  0.0,       0.0,   0.0,                                                       1.0
			);
			break;
		case '-':
			ROTATE.setMatrica(		
				cosAlpha, -sinAlpha,  0.0, -cosAlpha * center[0] + center[0] + sinAlpha * center[1],
				sinAlpha,  cosAlpha,  0.0, -sinAlpha * center[0] + center[1] - cosAlpha * center[1],
					 0.0,       0.0,  1.0,                                                      0.0,
					 0.0,       0.0,  0.0,                                                      1.0
			);
			break;
		}
		break;
	default:
		return;
	}
	for (i = 0; i < numVer; ++i) {
		Ver[i] = ROTATE * Ver[i];
	}
	BasisOfFigure();
	Test();
	result = e * V;
}
void Figure::move(char ch, char pn) {
	size_t i, f = (ch == 'x') ? f = 0 : (ch == 'y') ? f = 1 : f = 2;
	int step;
	ClrFigure();
	if (pn == '+')
		step = STEP;
	else
		step = -STEP;
	for (i = 0; i < numVer; ++i) {
		Ver[i][f] += step;
	}
	center[f] += step;
}
void Figure::zoom(char ch) {
	size_t i;
	ClrFigure();
	if (ch == '+') {
		ZOOM.setMatrica(
			ZOOM_PLUS,       0.0,       0.0, -ZOOM_PLUS * center[0] + center[0],
			      0.0, ZOOM_PLUS,       0.0, -ZOOM_PLUS * center[1] + center[1],
			      0.0,       0.0, ZOOM_PLUS, -ZOOM_PLUS * center[2] + center[2],
			      0.0,       0.0,       0.0,								1.0
			);
	}
	else {
		ZOOM.setMatrica(
			ZOOM_MINUS,        0.0,        0.0, -ZOOM_MINUS * center[0] + center[0],
			       0.0, ZOOM_MINUS,        0.0, -ZOOM_MINUS * center[1] + center[1],
			       0.0,        0.0, ZOOM_MINUS, -ZOOM_MINUS * center[2] + center[2],
			       0.0,        0.0,        0.0,									1.0
			);
	}
	for (i = 0; i < numVer; ++i) {
		Ver[i] = ZOOM * Ver[i];
	}
}
void Figure::SetCenter() {
	center[0] = 0.0;
	center[1] = 0.0;
	center[2] = 0.0;
	center[3] = 1.0;
	for (size_t i = 0; i < numVer; ++i) {
		center[0] += Ver[i][0];
		center[1] += Ver[i][1];
		center[2] += Ver[i][2];
	}
	center[0] /= double(numVer);
	center[1] /= double(numVer);
	center[2] /= double(numVer);
}
void Figure::print() {
	bmp->DrawBitmap();
}
void Figure::SetShadow() {
	for (size_t i = 0; i < numVer; ++i) {
		VerSHDW[i] = Ver[i];
		VerSHDW[i][1] = double(LIGHT::offset_Y);
	}
}
void Figure::SetPR() {
	for (size_t i = 0; i < numVer; ++i) {
		VerPR[i] = PR * Ver[i];
		VerSHDW[i] = PR * VerSHDW[i];
	}
}
void Figure::SetBitMap() {
	SetShadow();
	SetPR();
	SetFigure();
}
void Figure::Test() {
	int i;
	Vector result(numFace);
	result = center * V;
	for (size_t j = 0; j < numFace; ++j)
		if (result[j] > 0) {
			for (i = 0; i < Figure::dim; ++i)
				V(i, j) *= -1.0;
		}
}
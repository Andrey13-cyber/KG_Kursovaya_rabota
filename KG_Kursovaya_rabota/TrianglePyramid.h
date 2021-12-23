#ifndef PYRAMID_H_
#define PYRAMID_H_
#include "Figure.h"

class TrianglePyramid : public Figure {
public:
	TrianglePyramid(Bitmap*bmp, size_t numVer, size_t numFace);
private:
	void SetFigure();
	void ClrFigure();
	void BasisOfFigure();
};

#endif // !PYRAMID_H_



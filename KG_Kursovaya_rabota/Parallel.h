#ifndef CUBE_H_
#define CUBE_H_
#include "Figure.h"

class Parallel : public Figure {
public:
	Parallel(Bitmap*bmp, size_t numVer, size_t numFace);
private:
	void SetFigure();
	void ClrFigure();
	void BasisOfFigure();
};

#endif // !CUBE_H_
<<<<<<< HEAD
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

=======
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

>>>>>>> edec401c9b420f6dd8ce8b5adcb2b47a12c17905
#endif // !CUBE_H_
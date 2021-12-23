#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "BITMAP.h"
#include "Vector.h"

void shwap(Vector **v1, Vector **v2, int d);

void paintTRIN(Bitmap *bmp, Vector &v1, Vector &v2, Vector &v3, COLORREF col);

#endif // !FUNCTION_H_

<<<<<<< HEAD
#ifndef MATRIX_H_
#define MATRIX_H_
#include "Vector.h"

class Matrica {
public:
	Matrica();
	Matrica(int M, int N);
	~Matrica();
	void newMatrica(int M, int N);
	void setMatrica(double Element ...);
	friend Vector operator*(const Matrica&, const Vector &a);
	friend Vector operator*(const Vector &a, const Matrica &A);
	double& operator()(int i, int j) { return data[j][i]; };
private:
	int rows;
	int cols;
	Vector *data;
};

=======
#ifndef MATRIX_H_
#define MATRIX_H_
#include "Vector.h"

class Matrica {
public:
	Matrica();
	Matrica(int M, int N);
	~Matrica();
	void newMatrica(int M, int N);
	void setMatrica(double Element ...);
	friend Vector operator*(const Matrica&, const Vector &a);
	friend Vector operator*(const Vector &a, const Matrica &A);
	double& operator()(int i, int j) { return data[j][i]; };
private:
	int rows;
	int cols;
	Vector *data;
};

>>>>>>> edec401c9b420f6dd8ce8b5adcb2b47a12c17905
#endif
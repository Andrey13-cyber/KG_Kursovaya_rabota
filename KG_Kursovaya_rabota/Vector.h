<<<<<<< HEAD
#ifndef VECTOR_H_
#define VECTOR_H_
#include <cstdarg>
#include <iostream>

class Vector {
public:
	//������������
	Vector();
	Vector(int);
	Vector(const Vector&);
	Vector(Vector&&);
	//����������
	~Vector();
	//������ � �������� �������
	int size() const { return length; }
	void resize(int);

	//��������� �������� �������
	void setVector(double, ...);
	//��������� ��� ������
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&);
	double& operator[](int i) { return data[i]; }
	double operator[](int i) const { return data[i]; }
	void print() {
		for (int j = 0; j < length; ++j) {
			std::cout << data[j] << ' ';
		}
		std::cout << std::endl;
	}
private:
	double *data;
	int length;
};

=======
#ifndef VECTOR_H_
#define VECTOR_H_
#include <cstdarg>
#include <iostream>

class Vector {
public:
	//������������
	Vector();
	Vector(int);
	Vector(const Vector&);
	Vector(Vector&&);
	//����������
	~Vector();
	//������ � �������� �������
	int size() const { return length; }
	void resize(int);

	//��������� �������� �������
	void setVector(double, ...);
	//��������� ��� ������
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&);
	double& operator[](int i) { return data[i]; }
	double operator[](int i) const { return data[i]; }
	void print() {
		for (int j = 0; j < length; ++j) {
			std::cout << data[j] << ' ';
		}
		std::cout << std::endl;
	}
private:
	double *data;
	int length;
};

>>>>>>> edec401c9b420f6dd8ce8b5adcb2b47a12c17905
#endif
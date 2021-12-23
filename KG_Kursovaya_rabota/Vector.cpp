<<<<<<< HEAD
#include "Vector.h"

//Конструкторы
Vector::Vector() : data(nullptr), length(0) {}
Vector::Vector(int size) {
	data = nullptr;
	length = 0;
	resize(size);
}
Vector::Vector(const Vector &b) {
	length = b.length;
	data = new double[length];
	for (int i = 0; i < length; ++i)
		data[i] = b.data[i];
}
Vector::Vector(Vector &&b) {
	data = b.data;
	length = b.length;
	b.data = nullptr;
	b.length = 0;
}
Vector::~Vector() {
	delete[] data;
}
//Работа с размером вектора
void Vector::resize(int size) {
	if (length == size)
		return;
	Vector tmp(*this);
	int interval = length > size ? size : length;
	delete[] data;
	data = nullptr;
	length = size;
	if (size) data = new double[size];
	for (int i = 0; i < interval; ++i)
		data[i] = tmp.data[i];
}
void Vector::setVector(double element, ...) {
	int i;
	va_list ap;
	va_start(ap, element);
	data[0] = element;
	for (i = 1; i < length; ++i) {
		data[i] = (double)va_arg(ap, double);
	}
	va_end(ap);
}

Vector& Vector::operator=(const Vector &b) {
	if (this != &b) {
		if (length != b.length) {
			delete[] data;
			this->resize(b.length);
		}
		for (int i = 0; i < length; ++i)
			data[i] = b.data[i];
	}
	return *this;
}
Vector& Vector::operator=(Vector &&b) {
	if (this != &b) {
		delete[] data;
		data = b.data;
		length = b.length;
		b.data = nullptr;
		b.length = 0;
	}
	return *this;
=======
#include "Vector.h"

//Конструкторы
Vector::Vector() : data(nullptr), length(0) {}
Vector::Vector(int size) {
	data = nullptr;
	length = 0;
	resize(size);
}
Vector::Vector(const Vector &b) {
	length = b.length;
	data = new double[length];
	for (int i = 0; i < length; ++i)
		data[i] = b.data[i];
}
Vector::Vector(Vector &&b) {
	data = b.data;
	length = b.length;
	b.data = nullptr;
	b.length = 0;
}
Vector::~Vector() {
	delete[] data;
}
//Работа с размером вектора
void Vector::resize(int size) {
	if (length == size)
		return;
	Vector tmp(*this);
	int interval = length > size ? size : length;
	delete[] data;
	data = nullptr;
	length = size;
	if (size) data = new double[size];
	for (int i = 0; i < interval; ++i)
		data[i] = tmp.data[i];
}
void Vector::setVector(double element, ...) {
	int i;
	va_list ap;
	va_start(ap, element);
	data[0] = element;
	for (i = 1; i < length; ++i) {
		data[i] = (double)va_arg(ap, double);
	}
	va_end(ap);
}

Vector& Vector::operator=(const Vector &b) {
	if (this != &b) {
		if (length != b.length) {
			delete[] data;
			this->resize(b.length);
		}
		for (int i = 0; i < length; ++i)
			data[i] = b.data[i];
	}
	return *this;
}
Vector& Vector::operator=(Vector &&b) {
	if (this != &b) {
		delete[] data;
		data = b.data;
		length = b.length;
		b.data = nullptr;
		b.length = 0;
	}
	return *this;
>>>>>>> edec401c9b420f6dd8ce8b5adcb2b47a12c17905
}
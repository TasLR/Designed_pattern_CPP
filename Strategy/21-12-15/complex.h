/*
	Name: 
	Copyright: 
	Author: 
	Date: 15/12/21 11:12
	Description: 
*/
#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>
class ostream;
class Complex;

Complex&
	__doapl (Complex* ths,const Complex& r);
template<typename T>
class Complex{
public:
	Complex(T t_real = 0, T t_imag = 0)
		:m_real(t_real),m_imag(t_imag){
		}
	Complex(const Complex & t_obj);
	Complex& operator = (const Complex & t_obj);
	Complex& operator + (const Complex& t_obj);
	Complex  operator + (T t_var)
	{
		return Complex(this->m_real + t_var, this->m_imag);
	}
	Complex& operator += (const Complex& t_obj);
	T real(void) const {
		return m_real;
	} 
	T imag(void) const {
		return m_imag;
	}
	friend ostream& operator << (ostream& t_cout,const Complex& t_obj);	
	virtual ~Complex();
private:
	T m_real;
	T m_imag;
	friend Complex& __doapl (Complex* ths,const Complex& t_obj);
};

inline Complex&
Complex::__doapl (Complex* ths,const Complex& t_obj)
{
	ths->m_imag += t_obj.m_imag;
	ths->m_real += t_obj.m_real;
	return *ths;
}

inline Complex&
Complex::operator += (const Complex& t_obj)
{
	return __doapl(this,t_obj);
}

inline ostream&
Complex::operator << (ostream& os, const Complex& t_obj)
{
	return os << '(' << t_obj.real() << ',' << t_obj.imag() << ')';
} 

#endif
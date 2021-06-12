#ifndef __MOCK_ADD_HPP__
#define __MOCK_ADD_HPP__

#include "../header/base.hpp"

class AddMock : public Base {
	public:
		AddMock(Base* obj) : Base(), val(obj) { };
		
		virtual double evaluate() { return val->evaluate(); };
		virtual string stringify() { return val->stringify(); }
	private:
		Base* val;
};

#endif // __MOCK_ADD_HPP__

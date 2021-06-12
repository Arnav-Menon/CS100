#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include "select.hpp"

#include <string>
#include <iostream>

using namespace std;

class Select_And: public Select_Column {
	private:
		mutable int andCount = 0;
		
		void increment_count() const;
		void reset_count() const;	
	public:
		Select_And(Select_Column*, Select_Column*);

		virtual bool select(const string&) const;
};

#endif // __SELECT_AND_HPP__

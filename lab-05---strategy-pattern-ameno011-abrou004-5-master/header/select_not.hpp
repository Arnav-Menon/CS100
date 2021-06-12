#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"

#include <string>

class Select_Not : public Select_Column {
	private:
			
	public:
		Select_Not(Select_Column*);

		virtual bool select(const string&) const;
};

#endif //__SELECT_NOT_HPP__

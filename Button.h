#pragma once
#include"Input.h"

class Button :public Input {
public:
	Button(const Button&);
	Button(const char*);

	Button& operator=(const Button&);

	virtual void convertToHtml(std::ostream&);
};
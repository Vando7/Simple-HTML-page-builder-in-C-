#pragma once
#include"Input.h"

class Password : public Input {
public:
	//	Text(const char*);
	Password(const Password&);
	Password(const char*, bool);

	Password& operator=(const Password&);

	virtual void convertToHtml(std::ostream&);

private:
	bool required;
};
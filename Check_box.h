#pragma once
#include"Input.h"

class Check_box : public Input {
public:
	//	Text(const char*);
	Check_box(const Check_box&);
	Check_box(const char*, bool);

	Check_box& operator=(const Check_box&);

	virtual void convertToHtml(std::ostream&);

	void setStatus(const bool);
private:
	bool checked;
};
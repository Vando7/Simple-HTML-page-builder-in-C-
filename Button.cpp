#include "pch.h"

Button::Button(const Button& btn)
	:
	Input(btn) {

}

Button::Button(const char* _description)
	:
	Input(_description) {

}

Button & Button::operator=(const Button &btn)
{
	if(this!=&btn)
	this->Input::operator=(btn);

	return *this;
}

void Button::convertToHtml(std::ostream &striim)
{
	if (!isHidden) {
		striim
			<< "<input type=\"button\" value=\""
			<< description
			<< "\"> </br>\n";
	}
}

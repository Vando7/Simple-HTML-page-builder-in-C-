#include "pch.h"

Check_box::Check_box(const Check_box & newcheck)
	:
	Input(newcheck)
{	
		checked = newcheck.checked;
}

Check_box::Check_box(const char *_description, bool _checked)
	:
	Input(_description)
{
	checked = _checked;
}

Check_box & Check_box::operator=(const Check_box &newcheck)
{
	if (this != &newcheck) {
		this->Input::operator=(newcheck);
		checked = newcheck.checked;
	}

	return *this;
}

void Check_box::convertToHtml(std::ostream &striim)
{
	if (!isHidden) {
		striim << "<input type=\"checkbox\"";

		if (checked)
			striim << " checked";

		striim << "> " << description << " </br>\n";
	}
}

void Check_box::setStatus(const bool status)
{
	checked = status;
}

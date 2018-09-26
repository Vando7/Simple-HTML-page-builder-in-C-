#include "pch.h"

Password::Password(const Password &pass)
	:
	Input(pass.description)
{
	required = pass.required;
}

Password::Password(const char *_description, bool _required)
	:
	Input(_description)
{
	required = _required;
}

Password & Password::operator=(const Password &newpass)
{
	if (this != &newpass) {
		this->Input::operator=(newpass);
		required = newpass.required;
	}

	return *this;
}

void Password::convertToHtml(std::ostream &striim)
{
	if (!isHidden) {
		striim << description << " <input type=\"password\"";

		if (required)
			striim << " required";

		striim << "> </br>\n";
	}
}

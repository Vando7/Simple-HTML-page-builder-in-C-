#include "pch.h"

Input::Input(const char *_description)
{
	description = new char[strlen(_description) + 1];
	strcpy(description, _description);
	isHidden = 0;
}

Input::Input(const Input &newput)
{
	description = new char[strlen(newput.description) + 1];
	strcpy(description, newput.description);
	isHidden = 0;
}

Input & Input::operator=(const Input &newput)
{
	if (this != &newput){
		delete[] description;
		description = new char[strlen(newput.description) + 1];
		strcpy(description, newput.description);
		isHidden = newput.isHidden;
	}

	return *this;
}

Input::~Input()
{
	delete[] description;
}

void Input::setVisibility(const bool status)
{
	isHidden = !status;
}

void Input::setDescription(const char *n)
{
	delete[] description;
	if (n == nullptr) {
		description = new char;
		description = '\0';
	}
	else {
		description = new char[strlen(n) + 1];
		strcpy(description, n);
	}

}

char * Input::getDescription() const
{
	return description;
}


#include "pch.h"

Form::Form()
	:
	elements(nullptr),
	size(0)
{

}

Form::~Form(){
	Clear();
}

void Form::Clear()
{
	for (size_t i = 0; i < size; ++i)
		delete[] elements[i];

	delete[] elements;
}

void Form::outputForm(std::ostream &striim)
{
	striim << "<!DOCTYPE html>\n<html>\n<body>\n<form>\n";
	for (size_t i = 0; i < size; ++i)
		this->operator[](i).convertToHtml(striim);
	striim << "</form>\n</body>\n</html>\n";

}

size_t Form::getSize() const
{
	return size;
}

unsigned Form::find(const char *target)
{
	for (unsigned int i = 0; i < size; ++i) {
		if (strcmp(target, this->operator[](i).getDescription()))
			return i+1;
	}

	return 0;
}

void Form::addElement(Input *addthis)
{
	Input** newElements = new Input*[size + 1];

	for (int i = 0; i < size; ++i)
		newElements[i] = elements[i];

	newElements[size] = addthis;
	++size;

	delete[] elements;

	elements = newElements;
}

Input & Form::operator[](const unsigned idx)
{
	if (idx > size)
		return *elements[size - 1];

	return *elements[idx];
}



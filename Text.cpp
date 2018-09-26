#include "pch.h"

// _description_ <input type="text" align="_alignment_"> </br>

/// 0 - for left
/// 1 - for middle
/// 2 - for right
/// 3 - invalid

Text::Text(const Text& newtxt)
	:
	Input(newtxt.getDescription()) 
{
	alignment = newtxt.getAlignment();
}

Text::Text(const char* _description, const char* _alignment) 
	:
	Input(_description)
{
	setAlignment(_alignment);
}

Text & Text::operator=(const Text &newText)
{
	if (this != &newText) {
		this->Input::operator=(newText);
		alignment = newText.getAlignment();
	}
	return *this;
}

void Text::convertToHtml(std::ostream &striim)
{
	if (!isHidden) {
		striim << description << " <input type=\"text\" align=";
		switch (alignment) {
		case 0:
			striim << "\"left\"";
			break;
		case 1:
			striim << "\"middle\"";
			break;
		case 2:
			striim << "\"right\"";
			break;
		default:
			striim << "\"invalid\"";
			break;
		}
		striim << "> </br>\n";
	}
}



void Text::setAlignment(const char *_alignment)
{
	switch (_alignment[0]) {
	case 'l':
	case 'L':
		alignment = 0;
		return;

	case 'm':
	case 'M':
		alignment = 1;
		return;

	case'r':
	case'R':
		alignment = 2;
		return;

	default:
		alignment = 3;
		return;
	}
}

unsigned short Text::getAlignment() const
{

	return alignment;
}

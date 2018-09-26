#pragma once
#include"Input.h"

class Text : public Input {
public:
//	Text(const char*);
	Text(const Text&);
	Text(const char*, const char*);

	Text& operator=(const Text&);

	virtual void convertToHtml(std::ostream&);

	void setAlignment(const char*);
	unsigned short getAlignment() const;

private:
	unsigned short alignment;
};
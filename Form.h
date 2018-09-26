#pragma once
#include"Input.h"

class Form {
private:
	Input** elements;
	size_t size;

public:
	Form();
	~Form();
	void Clear();
	Input& operator[](const unsigned idx);

	void outputForm(std::ostream&);
	
	size_t getSize() const;
	unsigned find(const char*);

	void addElement(Input*);

};

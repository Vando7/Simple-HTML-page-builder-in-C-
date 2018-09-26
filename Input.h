#pragma once
#include<iostream>

class Input {
public:
	Input(const char*);
	Input(const Input&);
	Input& operator=(const Input&);
	virtual ~Input();

	char* getDescription() const;
	
	void setVisibility(const bool);
	void setDescription(const char*);
	virtual void convertToHtml(std::ostream&) = 0;

protected:
	char* description;
	bool isHidden;
};
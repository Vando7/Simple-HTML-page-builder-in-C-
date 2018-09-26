#include "pch.h"

bool strcomp(const char* a, const char* b) {
	if (strlen(a) != strlen(b))
		return 0;
	for (int i = 0; i < strlen(a); ++i)
		if (a[i] != b[i])
			return 0;
	return 1;
}


int main() {
	/* TEST 1
	newForm.addElement(new Text("User:", "middle"));
	newForm.addElement(new Password("Password :", 1));
	newForm.addElement(new Check_box("I agree!", 1));
	newForm.addElement(new Button("I agree!"));

	newForm.outputForm(std::cout);
	newForm[1].setVisibility(0);
	*/
	
	/*
	TEST INPUT:
	Add Text User: left
	Add Password pass 1
	Add Checkbox I_agree! 1
	Add Button Submit
	Save
	Exit
	*/
	std::ofstream file;
	Form newForm;
	file.open("docmuent.html");
		
	std::cout
		<< "What do you want to do?\n"
		<< "*commands are case sensitive\n"
		<< "*indexes start from 1\n"
		<< ">Add [type] [description] [status or alignment]\n"
		<< " types: \nText [description] [alignment] (left,right,middle)\n"
		<< " Password [description] [required] (0 or 1)\n"
		<< " Checkbox [description] [checked] (0 or 1)\n"
	    << " Button\n\n"
		<< ">Hide [index] [0 or 1]\n"
		<< ">Find [description]\n"
		<< ">Output [index]\n"
		<< ">Save\n"
		<< ">Exit\n";
		
	
	char cmd[20], tempType[10], tempDescription[256], tempAlignment[6];
	bool tempStatus;
	int tempIdx;

	bool exit = 0;
	while (!exit) {
		std::cout << "\n >";
		std::cin >> cmd;


		/// Add element.
		if (strcomp(cmd, "Add")) {
			std::cin >> tempType >> tempDescription;
			
			if (strcomp(tempType, "Text")) {
				std::cin  >> tempAlignment;
				newForm.addElement(new Text(tempDescription, tempAlignment));
			}

			if (strcomp(tempType, "Password")) {
				std::cin >> tempStatus;
				newForm.addElement(new Password(tempDescription, tempStatus));
			}

			if (strcomp(tempType, "Checkbox")) {
				std::cin >> tempStatus;
				newForm.addElement(new Check_box(tempDescription, tempStatus));
			}

			if (strcomp(tempType, "Button")) {
				newForm.addElement(new Button(tempDescription));
			}
		}

		// Hide element.
		if (strcomp(cmd, "Hide")) {
			std::cin >> tempIdx >> tempStatus;
			newForm[tempIdx+1].setVisibility(tempStatus);
		}
		// Find element.
		if (strcomp(cmd, "Find")) {
			std::cin >> tempDescription;
			std::cout
				<< "\nElement found at: "
				<< newForm.find(tempDescription)
				<< ".\n";
		}

		if (strcomp(cmd, "Output")){
			std::cin >> tempIdx;
			newForm[tempIdx-1].convertToHtml(std::cout);
		}

		if (strcomp(cmd, "Save")) {
			std::cout<<"File saved to document.html (Changes apply after exiting)\n";
			newForm.outputForm(file);
		}

		if (strcomp(cmd, "Exit"))
			exit = 1;

	}
	
	return 0;
}
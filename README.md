# Simple HTML page builder in CPP
An HTML page builder written in C++. It uses key principles of OOP like polymorphism, encapsulation and inheritance.
# How it works and how it's structured
### Usage
  When you start the app you are greeted with a console.
In that console, you can input commands to add, remove, display (in console or in the HTML page) and hide any of the following HTML elements:

- Button
- Check box
- Text field
- Password field

After you're done working on the page, you can choose to save it as an HTML document.

### Structure
- The main class is called "Form". 
  
  A form manages an array of elements called "Input".
  Input is the base class that is inherited by all the classes listed in the "Usage" section above. 
  
  Each child has to have it's own implementation of the method:
  ```
  virtual void convertToHtml(std::ostream&) = 0;
  ```
  
  Which return the child's respective HTML code.

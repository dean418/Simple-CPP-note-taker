#include <iostream>
#include <fstream>

using namespace std;

int main () {
	
	string file;
	string text;
	
	cout << "Enter the name of the file you want to create.\n";
	getline(cin, file);
	cin.ignore();
	
	cout << "Type the contents of your file.\n";
	getline(cin, text);
	cin.ignore();

	cout << "The name of your file is: " << file << std::endl;
	cout << "The contents of your file are: " << text << std::endl;

	
	ofstream myfile;
	myfile.open (file);
	myfile << text << "\n";
	myfile.close();
	return 0;
}
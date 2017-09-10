#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cstddef>


using namespace std;

const int line = 50;

int main () {
	
	bool repeat = true;
	
	while (repeat) {
	string selection; //variable to store a, b or c depending on users input 
	string Read;
	
	cout << "C++ note taking.\n" << "Would you like to: (Type a, b, c or d to choose an option)\n\n" << "a) Make a new file.\nb) List all files.\nc) View a file.\nd) Delete a file." << endl; 
	cin >> selection; // storing the users input in the "selection" variable

	while (selection != "a" && selection != "b" && selection != "c" && selection != "d") { // loop until the user enters a valid letter
		cout << "Please enter a, b or c\n";
		cin >> selection;
	} //OK
	
//---------- Make a new file -----------
	
	if (selection == "a") {
		
		string file; //variable to store the file name
		char text[512]; // variable to store the contents of te file
		
		cout << "\nEnter the name of the file you want to create.\n";
		cin >> file; // setting the users input to the name of the file
		cin.get();
	
		cout << "\nType the contents of your file.\n";
		cin.getline(text, 512); // getting the enire line
		
		ofstream note; //object for the note
		note.open (file); //creating a file with the users input as a title
		note << text << "\n"; // adding the note to the file
		note.close(); // closing the file

		cout << "\nThe name of your file is: " << file << endl;
		cout << "The contents of your file are: " << text << endl;
		
		ofstream _titles_; // object for the list of the names of notes
		_titles_.open ("_titles_", fstream::app); //open and append the file named "_titles_";
		_titles_ << file << "\n"; // write the name of the note that the user created to the file
		_titles_.close(); // close the "_titles_" file
		
//----------- List all files ------------
	
	} else if (selection == "b") { //OK
	
		ifstream readFromFile("_titles_"); //open the file _titles_ 
		
		if (readFromFile.is_open()) { // if _titles_ is open do
			
			while(!readFromFile.eof()) { //while _titles_ is not at the end of tthe file do
				
				getline(readFromFile, Read); //get the text in _titles_ and store it under the Read variable
				cout << Read << endl; //print out the contents of _title_
			}
			readFromFile.close(); // close _titles_
				
		} else { //error
			cout << "you may no have permission to access these files or a different error has occured!" << endl;
		}
		
//------------ View a file ----------------

	} else if (selection == "c") { //OK
	
		string fileToView; // variable to store the name of the file
		
		cout << "Which note would you like to view? If you would like to see all of your notes choose option 'b' in the menu." << endl;
		cin >> fileToView; // set the variable to the name of te file
		
		ifstream view(fileToView); // open the file that the user wants to view
		
		if (view.is_open()) { // if the file is open do
			
			while(!view.eof()) { // while the the file is not at the end do
				
				getline(view, Read); //store the contents of the file under the Read variale
				cout << "\n" << Read << endl; // print out the contents of the file
			}
			view.close(); // close the file
			
		} else {
			cout << "The file you are trying to view does not exist!" << endl; //error
		}
		
//-------------- Delete a file ----------------

	} else if (selection == "d") { //O
		
		string fileToDelete; // variable to store the name of the file that the user wants to delete 
		
		cout << "Enter the name of the file that you would like to delete." << endl;
		cin >> fileToDelete; 
		
		ifstream Delete(fileToDelete);
		
		if (Delete.is_open()) { //bad way of checking if a file exists
			Delete.close();
			
			if(remove(fileToDelete.c_str()) != 0) { // why does this only work inside the if statement
			
				cout << "file could not be deleted" << endl;
			} else {
				
				cout << "Deleted the file: " << fileToDelete << endl;
			}
		}
		//----------- deleting the file name from _titles_ -----------
		
		size_t found = Read.find_first_of(fileToDelete);
		
		ifstream titles("_titles_");
			
		if(titles.is_open()) {
				
			getline(titles, Read);
			cout << Read << endl;
			
			while (found !=string::npos) {
				
				Read[found] = ' ';
				found = Read.find_first_of(fileToDelete, found + 1);
			}
			
			cout << Read << endl;
			titles.close();
		}
		
		remove("_titles_");
			
	
	
		ofstream deleted; // object for the list of the names of notes
		deleted.open ("_titles_", fstream::app); //open and append the file named "_titles_";
		deleted << Read << "\n"; // write the name of the note that the user created to the file
		deleted.close(); // close the "_titles_" file
	}
		

	
//------------ end of delete from file -------------

		string answer;
		cout << "Would you like to chose a different option from the menu? (y/n)" << endl;
		cin >> answer;
		
		if (answer == "y") { // giving the user the option to re-run the program
		                     // to chose a different option in the menu
			repeat = true;
		} else {
			repeat = false;
		}
	}
		return 0; //exit the program
} // END INT MAIN
	

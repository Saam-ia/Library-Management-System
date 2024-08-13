#pragma once//pragma once provides a simple and effective way to prevent multiple inclusions of a header file, 
#include<iostream>
#include<string>
#include<Windows.h>//
#include<vector>
#include<iterator>
#include<iomanip>
using namespace std;
namespace decor
{
	void fontColor()
	{
	HANDLE h;
	h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,5);	
	}
	void close(){
		cout<<setw(50)<<"\nThank you  for your visit.";
	}
	
}
using namespace decor;
class Book {
	string name, genre, author;
	int availableCopies, totalCopies;
public:
	Book() {

	}
	Book(string name, string genre, string author,
		int totalCopies) {
		this->name = name;
		this->genre = genre;
		this->author = author;
		this->totalCopies = totalCopies;
		availableCopies = this->totalCopies;
	}
	void setCopies(int availableCopies,int totalCopies) {
		this->availableCopies = availableCopies;
		this->totalCopies = totalCopies;
	}
	void displayInfo() {
		cout << "Book Name: " << name << endl;
		cout << "Book Genre: " << genre << endl;
		cout << "Book Author: " << author << endl;
		cout << "Available Copies: " << availableCopies << endl;
		cout << "Total Copies: " << totalCopies << endl;
	}
	string getName() {
		return name;
	}
	void setAvailableCopies(int availableCopies) {
		this->availableCopies = availableCopies;
	}
	int getAvailableCopies() {
		return availableCopies;
	}
};
vector<Book> bookList;
class Reader{
public:
	string name, phone, pass;
	string passArr[5] = { "eyeyamstewpeed", "readabookretard","qwerty", "shaykhUthman", "peekAboo" };
public:
	Reader(string name, string phone) {
		this->name = name;
		this->phone = phone;
	}
	Reader(string name, string phone, string pass) {
		this->name = name;
		this->phone = phone;
		this->pass = pass;
	}
	void ReaderRunner() {
		cout << "Enter your Password: ";
		cin>> pass;
		if (!check()) {
			cout << "Access Denied!" << endl;
		}
		else {
		START:
			int chosenOption = choiceDisplay();
			switch (chosenOption) {
			case 1:
			{
				cout << "Enter Name of Book to be searched: ";
				string bookName;
				cin>> bookName;
				vector<Book>::iterator itr;
				for (itr = bookList.begin(); itr != bookList.end(); itr++) {
					if (itr->getName() == bookName) {
						itr->displayInfo();
						break;
					}
				}
				cout << "\nContinue? (Y/N)\n";
				char choice;
				cin >> choice;
				if (choice == 'y' or choice == 'Y') {
					system("clear");
					goto START;
				}
				else {
					cout << "Doesn't Matter! We still moving On." << endl;
					goto START;
				}
			}
			case 2:
			{
				cout << "Enter Name of Book to be borrowed: ";
				string bookName;
				cin>> bookName;
				vector<Book>::iterator itr;
				for (itr = bookList.begin(); itr != bookList.end(); itr++) {
					if (itr->getName() == bookName) {
						itr->setAvailableCopies(itr->getAvailableCopies() - 1);
						break;
					}
				}
				itr->displayInfo();
				cout << "\nBook borrowed Successfully!" << endl;
				goto START;
			}
			case 3:
			{
				cout << "Enter Name of Book to be returned: ";
				string bookName;
				cin>> bookName;
				vector<Book>::iterator itr;
				for (itr = bookList.begin(); itr != bookList.end(); itr++) {
					if (itr->getName() == bookName) {
						itr->setAvailableCopies(itr->getAvailableCopies() + 1);
						break;
					}
				}
				itr->displayInfo();
				cout << "\nBook returned Successfully!" << endl;
				goto START;
			}
			default: {
				system("clear");
				cout <<setw(57)<< "INVALID CHOICE!" << endl;
				goto START;
			}
			}
		}
	}
	bool check() {
		for (int i = 0; i < 5; i++) {
			if (pass == passArr[i]) {
				return true;
			}
		}
		return false;
	}
	int choiceDisplay() {
		cout << "1) Search Book\n";
		cout << "2) Borrow Book\n";
		cout << "3) Return Book\n";
		cout << "Your Choice: ";
		int choice;
		cin.ignore(10,'\n');
		cin >> choice;
		return choice;
	}
	void displayInfo() {
		cout << "Reader Name: " << name << endl;
		cout << "Reader Phone: " << phone << endl;
		cout << "Reader Password: " << pass << endl;
	}
	string getName() {
		return name;
	}
};
vector<Reader> readerList;
class Librarian{
	string name;
	int veriCode;
	int veriCodeArr[5] = { 234, 333, 654, 984, 941 };
public:
	Librarian() {

	}
	Librarian(string name) {
		this->name = name;
	}
	void LibrarianRunner() {
		cout << "Enter your verification Code: ";
		cin >> veriCode;
		if (!check()) {
			cout << "Librarian Doesn't Exist." << endl;
		}
		else {
		START:
			int chosenOption = choiceDisplay();
			switch (chosenOption) {
			case 1:
			{
				cout << "Enter Name of the Book: ";
				string bookName;
				cin>> bookName;
				cout << "Enter Genre of the Book: ";
				string bookGenre;
				cin>> bookGenre;
				cout << "Enter Author's Name: ";
				string bookAuthor;
				cin>> bookAuthor;
				cout << "Enter Number of Copies: ";
				int bookCopies;
				cin >> bookCopies;
				Book newBook(bookName, bookGenre,
					bookAuthor, bookCopies);
				bookList.push_back(newBook);
				cout << "Book added Successfully!" << endl;
				goto START;
			}
			case 2:
			{
				cout << "Enter Name of Book to be removed: ";
				string bookName;
				cin>> bookName;
				vector<Book>::iterator itr;
				for (itr = bookList.begin(); itr != bookList.end(); itr++) {
					if (itr->getName() == bookName) {
						bookList.erase(itr);
						break;
					}
				}
				cout << "Book Removed Successfully!" << endl;
				goto START;
			}
			case 3:
			{
				cout << "Enter Name of Book to be searched: ";
				string bookName;
				cin>> bookName;
				vector<Book>::iterator itr;
				for (itr = bookList.begin(); itr != bookList.end(); itr++) {
					if (itr->getName() == bookName) {
						itr->displayInfo();
						break;
					}
				}
				cout << "\nContinue? (Y/N)\n";
				char choice;
				cin >> choice;
				if (choice == 'y' or choice == 'Y') {
					system("clear");
					goto START;
				}
				else {
					cout << "Doesn't Matter! We still moving On." << endl;
					goto START;
				}
			}
			case 4:
			{
				cout << "Enter Name of Reader to be searched: ";
				string readerName;
				cin>> readerName;
				vector<Reader>::iterator itr;
				for (itr = readerList.begin(); itr != readerList.end(); itr++) {
					if (itr->getName() == readerName) {
						itr->displayInfo();
						break;
					}
				}
				cout << "\nContinue? (Y/N)\n";
				char choice;
				cin >> choice;
				if (choice == 'y' or choice == 'Y') {
					system("clear");
					goto START;
				}
				else {
					cout << "Doesn't Matter! We still moving On." << endl;
					goto START;
				}
			}
			case 5:
			{
				cout << "Enter Name of the Reader: ";
				string readerName;
				cin>> readerName;
				cout << "Enter Phone of the Reader: ";
				string readerPhone;
				cin>> readerPhone;
				cout << "Enter Reader's Password: ";
				string readerPass;
				cin>> readerPass;
				Reader newReader(readerName, readerPhone, readerPass);
				readerList.push_back(newReader);
				cout << "Reader added Successfully!" << endl;
				goto START;
			}
			case 6:
			{
				cout << "Enter Name of Reader to be removed: ";
				string readerName;
				cin>> readerName;
				vector<Reader>::iterator itr;
				for (itr = readerList.begin(); itr != readerList.end(); itr++) {
					if (itr->getName() == readerName) {
						readerList.erase(itr);
						break;
					}
				}
				cout << "Reader Removed Successfully!" << endl;
				goto START;
			}
			case 0:
			{
				cout <<setw(57)<< "Allah de hawalay!" << endl;
				close();
				exit(1);
			}
			default:
			{
				system("clear");
				cout << "INVALID CHOICE!" << endl;
				goto START;
			}
			}
		}
	}
	bool check() {
		for (int i = 0; i < 5; i++) {
			if (veriCode == veriCodeArr[i]) {
				return true;
			}
		}
		return false;
	}
	int choiceDisplay() {
		cout << "1) Add Book\n";
		cout << "2) Remove Book\n";
		cout << "3) Search Book\n";
		cout << "4) Data of Readers\n";
		cout << "5) Add Reader\n";
		cout << "6) Remove Reader\n";
		cout << "0) Exit\n";
		cout << "Your Choice: ";
		int choice;
		cin >> choice;
		return choice;
	}
};
class Library{
public:
	string libraryName;
public:
	void LibraryRunner() {
		cout << "Enter your desired Library Name: ";
		getline(cin, libraryName);
		START:
		cout <<setw(50)<< "----Welcome to " << libraryName << 
			" Library----" << endl;
		int chosenOption = choiceDisplay();
		switch (chosenOption) {
			case 0:
			{
				close();
				exit(1);
			}
			case 1:
			{
				string name;
				cout << "Enter your Name: ";
				cin>>name;
				Librarian librarian(name);
				librarian.LibrarianRunner();
				break;
			}
			case 2:
			{
				string name,phone;
				cout << "Enter your Name: ";
				cin>> name;
				cout << "Enter your Phone Number: ";
				cin>> phone;
				Reader reader(name, phone);
				reader.ReaderRunner();
				break;
			}
			default:
			{
				system("clear");
				cout << "INVALID CHOICE!" << endl;
				goto START;
			}
		}
	}
	int choiceDisplay() {
		cout << "1) Enter as Librarian\n";
		cout << "2) Enter as Reader\n";
		cout << "0) Exit\n";
		cout << "Your Choice: ";
		int choice;
		cin >> choice;
		return choice;
	}
}; 

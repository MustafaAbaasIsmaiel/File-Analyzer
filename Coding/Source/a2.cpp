#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include "inord_list.h"
using namespace std;
long long int charCount;
long long int wordCount;
List Engine;
string Command;
string Argument;
bool Sort(const string Name)
{
	string Element;
	string Word;
	string Order;
	ifstream File(Name.c_str());
	if (!File) {
		cout << "File not found";
		return false;
	}
	int Line;
	charCount = 0;
	wordCount = 0;
	Line = 1;
	while (getline(File, Element)) {
		charCount += Element.length();
		for (int i = 0; i < Element.length(); i++) {
			if ((Element[i] < 65 || Element[i] > 90) && (Element[i] < 97 || Element[i] > 122) && (Element[i] < 48 || Element[i] > 57) && (Element[i] != 39)) {
					Element.replace(i, 1, " ");
			}

		}
		stringstream iss(Element);
		while (iss >> Word) {
			if(Word != "s")
				wordCount++;
			Order = Word;
			for (int i = 0; i < Order.length(); i++) {
				if (Order[i] >= 65 && Order[i] <= 90)
					Order[i] = Order[i] + 32;
			}
			if (Word != "s")
				Engine.Insert(Order, Line);
		}
		Line++;
	}
	charCount += Line - 1;
	return true;
	File.close();

}
bool Read(const string Name) {
	string Element;
	string Command;
	string Argument;
	string Word;
	string Order;
	bool empty = false;
	int Check;
	int Number;
	ifstream File(Name.c_str());
	if (!File) {
		cout << "File not found";
		return false;
	}
	while (getline(File, Element)) {
		empty = true;
		Number = 1;
		Check = 1;
		Command = "uninitialized";
		stringstream One(Element);
		while (One >> Word)
		{
			if (Check == 1)
				Order = Word;
			Check++;
		}
		if (Check- 1 > 2) {
			cout << "Incorrect number of arguments";
			return false;
		}
		if (Check - 1 > 1 && (Order == "wordCount" || Order == "disWords" || Order == "charCount" || Order == "frequentWord"))
		{
			cout << "Incorrect number of arguments";
			return false;
		}
		stringstream Two(Element);
		while (Two >> Word) {
			if (Number == 1)
			{
				if (Word == "countWord" || Word == "starting" || Word == "containing" || Word == "search")
					Command = Word;
				else if (Word == "wordCount")
					cout << wordCount << " " << "words" << endl;
				else if (Word == "distWords")
					Engine.distWords();
				else if (Word == "charCount")
					cout << charCount << " " << "characters" << endl;
				else if (Word == "frequentWord")
					Engine.frequentWord();
				else
					cout << "Undefined command" << endl;
			}
			else if (Number == 2)
			{
				if (Command == "countWord")
					Engine.countWord(Word);
				else if (Command == "starting")
					Engine.starting(Word);
				else if (Command == "containing")
					Engine.containing(Word);
				else if (Command == "search")
					Engine.search(Word);
			}
			Number++;
			}
		if ((Command == "countWord" || Command == "starting" || Command == "containing" || Command == "search") && Number - 1 == 1)
			cout << "Incorrect number of arguments";
	}
	if (!empty)
		cout << "Undefined command" << endl;
	File.close();
}
int main(int argc,char* argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect number of arguments" << endl;           
		exit(1);
	}
	string FileName = argv[1];
	string Commands = argv[2];
	if (Sort(FileName))
		Read(Commands);
	string test;
	return 0;
}


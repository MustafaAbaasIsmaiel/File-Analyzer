#include <iostream>
#include <string>
#include <vector>
#include "inord_list.h"
using namespace std;
List::List()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}
bool List::First(ListElemType &e, int &y)
{
	if (head == NULL)
		return false;
	else {
		current = head;
		e = current->elem;
		y = current->Count;
		return true;
	}
}
bool List::Next(ListElemType &e, int &y)
{
	if (current == NULL || current->next == NULL)
		return false;
	else {
		current = current->next;
		e = current->elem;
		y = current->Count;
		return true;
	}
}
bool List::Insert(const ListElemType &e, const int &x)
{
	Link addednode;
	Link pred;
	bool check;
	addednode = new Node;
	if (addednode == NULL)
		return false;
	addednode->elem = e;
	addednode->Line = x;
	addednode->Count = 1;
	if (head == NULL || e < head->elem) {
		addednode->next = head;
		head = addednode;
		head->Position.push_back(x);
	}
	else if (e == head->elem) {
		delete addednode;
		head->Count++;
		head->Position.push_back(x);
	}
	else {
		check = true;
		pred = head;
		while (pred->next != NULL && pred->next->elem < e) {
			pred = pred->next;
		}
		if (pred->next != NULL && pred->next->elem == e) {
			pred->next->Count++;
			pred->next->Position.push_back(x);                      
			check = false;
		}
		if (check) {
			addednode->next = pred->next;
			addednode->Position.push_back(x);
			pred->next = addednode;
		}
		else
			delete addednode;
	}
	return true;
} 
void Lower(ListElemType &word)
{
	for (int i = 0; i < word.length(); i++) {
		if (word[i] >= 65 && word[i] <= 90)
			word[i] = word[i] + 32;
	}

}
void List::distWords()
{
	Link temp;
	temp = head;
	long long int counter;
	counter = 1;
	while (temp->next != NULL) {
		counter = counter + 1;
		temp = temp->next;
	}
	cout << counter << " " << "distinct words" << endl;
}
void List::frequentWord()
{
	Link temp;
	bool Check;
	temp = head;
	long long int max;
	max = 0;
	if ((temp->Count) > max && (temp->elem != "a" && temp->elem != "an"  && temp->elem != "and" && temp->elem != "the" && temp->elem != "in" && temp->elem != "on" && temp->elem != "of" && temp->elem != "and" && temp->elem != "is" && temp->elem != "are" && temp->elem != "was" && temp->elem != "were" && temp->elem != "off"))
		max = temp->Count;
	while (temp->next != NULL){
		if ((temp->next->Count ) > max && (temp->next->elem != "a" && temp->elem != "and" && temp->next->elem != "an" && temp->next->elem != "the" && temp->next->elem != "in" && temp->next->elem != "on" && temp->next->elem != "of" && temp->next->elem != "and" && temp->next->elem != "is" && temp->next->elem != "are" && temp->next->elem != "was" && temp->next->elem != "were" && temp->next->elem != "off"))
			max= temp->next->Count;
		temp = temp->next;
	} 
	temp = head;
	Check = true;
	while (temp->next != NULL) {
		if (temp->Count == max && temp == head && (temp->elem != "a" && temp->elem != "an"  && temp->elem != "and" && temp->elem != "the" && temp->elem != "in" && temp->elem != "on" && temp->elem != "of" && temp->elem != "and" && temp->elem != "is" && temp->elem != "are" && temp->elem != "was" && temp->elem != "were" && temp->elem != "off") ){
			cout << "Most frequent word is:" << " " << temp->elem << " ";
			Check = false;
		}
		if (temp->next->Count == max && (temp->next->elem != "a" && temp->elem != "and" && temp->next->elem != "an" && temp->next->elem != "the" && temp->next->elem != "in" && temp->next->elem != "on" && temp->next->elem != "of" && temp->next->elem != "and" && temp->next->elem != "is" && temp->next->elem != "are" && temp->next->elem != "was" && temp->next->elem != "were" && temp->next->elem != "off")) {
			if (Check) {
				cout << "Most frequent word is:" << " ";
				Check = false;
			}
			cout << temp->next->elem << " ";
		}
		temp = temp->next;
	} 
	cout << endl;
}
void List::countWord(ListElemType e)
{
	Lower(e);
	if (head->elem == e)
		cout << e << " " << "is repeated " << head->Count << " " << "times" << endl;
	else {
		Link temp;
		temp = head;
			while (temp->next != NULL) {
				if (temp->next->elem == e)
					break;
					temp = temp->next;
			}
			if (temp->next == NULL)
				cout << "0" << endl;
			else
				cout << e << " " << "is repeated " << temp->next->Count << " " << "times" << endl;
	}

}
void List::starting(ListElemType e)
{
	bool Notfound;
	Link temp;
	temp = head;
	Lower(e);
	Notfound = true;
	while (temp->next != NULL) {
		if (head->elem.substr(0, e.length()) == e && temp == head) {
			Notfound = false;
			cout << head->elem << ": " << head->Count << "	";
		}
		if (temp->next->elem.substr(0, e.length()) == e) {
			Notfound = false;
			cout << temp->next->elem << ": " << temp->next->Count << "	";
		}
		temp = temp->next;
	}
	if (Notfound)
		cout << "Word not found";
	cout << endl;
}
void List::containing(ListElemType e)
{
	bool Notfound;
	size_t check;
	Link temp;
	temp = head;
	Lower(e);
	check = head->elem.find(e);
	Notfound = true;
	if (check != string::npos) {
		cout << head->elem << ": " << head->Count << "	";
		Notfound = false;
	}
	while (temp->next != NULL)
	{
		check = temp->next->elem.find(e);
		if (check != string::npos) {
			cout << temp->next->elem << ": " << temp->next->Count << "	";
			Notfound = false;
		}
		temp = temp->next;
	}
	if (Notfound)
		cout << "Word not found";
	cout << endl;
}

void List::search(ListElemType e)
{
	bool Notfound;
	size_t check;
	Link temp;
	temp = head;
	Lower(e);
	Notfound = true;
	check = head->elem.find(e);
	if (check != string::npos) {
		Notfound = false;
		cout << head->elem << ":	" << "lines ";
		for (int i = 0; i < head->Position.size(); i++) {
			if (i != 0 && head->Position[i] == head->Position[i - 1])
				continue;
			cout << head->Position[i] << " " ;
		}
		cout << endl;
	}
	while (temp->next != NULL) {
			check = temp->next->elem.find(e);
			if (check != string::npos) {
				Notfound = false;
				cout << temp->next->elem << ":	" << "lines ";
				for (int i = 0; i < temp->next->Position.size(); i++) {
					if (i != 0 && temp->next->Position[i] == temp->next->Position[i - 1])
						continue;
						cout << temp->next->Position[i] << " ";
				}
				cout << endl;
			}
			temp = temp->next;
		}
	if (Notfound)
		cout << "Word not found"<<endl;
}

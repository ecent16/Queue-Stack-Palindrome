// DataStructure_Assignment6_Centeno.cpp
// Ervin Centeno
// April 15, 2019

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <string>
#include <queue>
#include <stack>

using namespace std;

bool isPalindrome(string str);
// Postcondition: The function returns true or false depending on
// whether the statement or phrase is a palindrome.

int main()
{
	string letter;
	char replay = 'Y';

	while (replay == 'Y' || replay == 'y' ) {

		cout << "Enter a statement to see if its a palindrome:" << endl;
		
		getline(cin, letter);

		isPalindrome(letter);

		if (!isPalindrome(letter))
		{
			cout << "That is not a palindrome." << endl;
		}
		else
		{
			cout << "That is a palindrome." << endl;
		}
		
		cout << "Would you like to try another statement?: ";

		cin >> replay;

		// This clears the cin buffer and resets it for the next input if replay == y
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Thanks for playing!!!" << endl;

	return EXIT_SUCCESS;

}

bool isPalindrome(string str) 
{
	queue<char> q;
	stack<char> s;
	
	queue<char>::size_type misMatch = 0;
	
	int length = str.length();
	char arr[30];		// Array max character limit. 

	for (int i = 0; i < length; i++)
	{
		
		arr[i] = str[i];
		
		if (isalpha(arr[i]))	// Only passes alphanumeric characters
		{	
			// Converts all characters in arr to uppercase
			// and adds them into a queue and stack.
			q.push(toupper(arr[i]));
			s.push(toupper(arr[i]));
		}
	
	}
	while ((!q.empty()) && (!s.empty()))
	{
		if (q.front() != s.top())	// Compares the characters in the queue and stack.
		{
			++misMatch;
		}
		q.pop();
		s.pop();

	}
	// If mismatch has no mismatched characters.
	if (misMatch == 0)
		return true;
	else
		return false;


}
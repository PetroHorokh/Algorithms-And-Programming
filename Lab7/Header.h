#pragma once
#pragma warning (disable :4996)

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Ifile
{
public:
	virtual void Print_File() = 0;
	virtual void WhiteToFile() = 0;

};

class StackHandler
{
public:
	virtual void Numerise() = 0;
	virtual void StackOutput() = 0;
	virtual void StackRevers() = 0;
	virtual void DeleteStack() = 0;
	virtual void AddStringToStack() = 0;
	virtual void GetTop() = 0;
};

class STACK: public StackHandler
{
private:

	stack<string> Stack;
	;

public:
	string filename;

	virtual void Choise_File();
	virtual void Print_File();
	virtual int FileToStack();
	virtual void Numerise() ;
	virtual void DeleteStack() ;
	virtual void StackOutput() ;
	virtual void StackRevers() ;
	virtual void AddStringToStack() ;
	virtual void GetTop();
};

class Main
{
protected:
	int menu();

public:
	int Main_menu();
};


enum {choosefile, printfile, filetostack, numeresation, reversestack, addstring, gettop, printstack, deletestack, endprogram};
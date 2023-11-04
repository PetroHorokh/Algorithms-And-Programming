#pragma once
#pragma warning (disable :4996)

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const int SIZE_S = BUFSIZ, FILENAME_SIZE = 20;

struct STACK {
	char* txt;
	STACK* sptr;
};

char* FindAndEnterFile();
STACK* LoadFileToStack(const char*, int&);
int FilePrint(const char*);
void pop(STACK*);
void push(STACK*&, char*);
int purge(STACK*&);
int renumber(STACK*&, int);
int PrintStack(STACK*);
int menu();
int Main();

enum {choosefile, printfile, filetostack, numberesation, printstack, deletestack, endprogram};
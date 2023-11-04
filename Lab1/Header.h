#pragma once
#pragma warning (disable :4996)

#include<stdio.h>
#include <windows.h>

//using namespace std;

const int SIZE_S = BUFSIZ;

struct STACK
{
	char* txt;
	STACK* sptr;
};

STACK* LoadFileToStack(const char*, int&);
int FilePrint(const char*);
void pop(STACK*);
void push(STACK*&, char*);
void purge(STACK*&);
void renumber(STACK*&, int);
void PrintStack(STACK*);




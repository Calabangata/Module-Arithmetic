#ifndef USERIO_H
#define USERIO_H
#include<iostream>
#include<cstdarg>
#include<cstdlib>
#include<cstring>
#include"Modlib.h"

int PrintMenu ();

bool Menu (int, int**&, int&);

int PrintArray (int**, int);

int EnterNumber(int&, int = 0, int = 15);

#endif   // USERIO_H

#ifndef ADAPTARRAY_H
#define ADAPTARRAY_H

#include <stdio.h>
#include "AdptArray.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct AdptArray_* PAdptArray;
typedef enum  {FAIL = 0, SUCCESS=1} Result;
typedef void* PElement;

typedef void(*DEL_FUNC)(PElement);
typedef PElement(*COPY_FUNC)(PElement);
typedef void(*PRINT_FUNC)(PElement);

typedef struct AdptArray_
{
	size_t Size;
    DEL_FUNC delF;
	COPY_FUNC cpyF;
    PRINT_FUNC printF;
	PElement* pElemArr;
	
} *PAdptArray;

PAdptArray CreateAdptArray(COPY_FUNC, DEL_FUNC,PRINT_FUNC);
void DeleteAdptArray(PAdptArray);
Result SetAdptArrayAt(PAdptArray, int, PElement);
PElement GetAdptArrayAt(PAdptArray, int);
int GetAdptArraySize(PAdptArray);
void PrintDB(PAdptArray);


#endif
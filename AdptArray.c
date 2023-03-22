#include <stdio.h>
#include "AdptArray.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct AdptArray_
{
	size_t Size;
    DEL_FUNC delF;
	COPY_FUNC cpyF;
    PRINT_FUNC printF;
	PElement* pElemArr;
	
} *PAdptArray;


PAdptArray CreateAdptArray(COPY_FUNC copyfunc, DEL_FUNC delfunc,PRINT_FUNC printfunc){

    PAdptArray pArr = (PAdptArray)malloc(sizeof(struct AdptArray_));
    if(pArr == NULL){
        return NULL;
    }

    pArr -> Size = 1;
    pArr -> delF = delfunc;
    pArr -> cpyF = copyfunc;
    pArr -> printF = printfunc;
    pArr -> pElemArr = (PElement*)malloc(sizeof(PElement)*1);
    if(pArr -> pElemArr == NULL){
        free(pArr);
        return NULL;
    }
    for(int i=0; i < pArr -> Size; i++){
        pArr -> pElemArr[i] = NULL;
    }
    
    return pArr;
}


void DeleteAdptArray(PAdptArray pArr){

    if(pArr == NULL){
        return;
    }
    
    size_t i = 0;
    while(i < pArr -> Size){
        if(pArr -> pElemArr[i] != NULL){
            pArr ->delF(pArr->pElemArr[i]);
        }
        i++;
    }
    
    free((pArr -> pElemArr));
    free(pArr);
}

Result SetAdptArrayAt(PAdptArray pArr, int index, PElement pElem){

    if(pArr == NULL){
        return FAIL;
    }

    if(pElem == NULL){
        return FAIL;
    }

    if(index < 0){
        return FAIL;
    }

    if( pArr->Size < index){
        
        int newSize = index + 1;

        pArr->pElemArr = (PElement*)realloc(pArr->pElemArr, newSize * sizeof(PElement));
        if(pArr->pElemArr == NULL){
            return FAIL;
        }
        for(int i = pArr->Size; i < newSize; i++){
            pArr->pElemArr[i] = NULL;
        }
        pArr->Size = newSize;
    }

    if((pArr -> pElemArr)[index] != NULL){
        pArr -> delF(pArr -> pElemArr[index]);
    }
    
    pArr -> pElemArr[index] = pArr->cpyF(pElem);
    
    return SUCCESS;
}


PElement GetAdptArrayAt(PAdptArray pArr, int index){

    if(pArr == NULL){
        return NULL;
    }

    if(index < 0){
        return NULL;
    }

    if(index >= pArr -> Size){
        return NULL;
    }

    if(pArr -> pElemArr[index] == NULL){
        return NULL;
    }

    PElement newpElem = pArr->cpyF(pArr -> pElemArr[index]);
    return newpElem;
}


int GetAdptArraySize(PAdptArray pArr){ return (pArr == NULL) ? -1 : pArr -> Size; }
    

void PrintDB(PAdptArray pArr){

    if(pArr == NULL){
        return;
    }

    for(size_t i = 0 ; i < pArr->Size ; i++){
        if(pArr -> pElemArr[i] != NULL){
        pArr -> printF(pArr -> pElemArr[i]);
        }
    }
}
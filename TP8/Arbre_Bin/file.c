#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include "file.h"


FileNoeud* nouveau_fnoeud(void* ptr)
{
	FileNoeud* n = malloc(sizeof(FileNoeud));
	n->val = ptr;
	n->next = NULL;
	return n;
}

File* file_vide()
{
	File* fi = malloc(sizeof(File));
	fi->first = NULL;
	fi->last = NULL;
	return fi;
}

int est_file_vide(File* fi)
{
	return fi->first == NULL;
}

void* defile(File* fi)
{
	FileNoeud* fn = fi->first;
	void* a = fn->val;
		
	if (fn == fi->last) //(or nb==1)
	{
		fi->first = NULL;
		fi->last = NULL;
	}
	else
	{
		fi->first = fn->next;
	}

	free(fn);

	return a;
}


void  enfile(File* fi, void* ptr)
{
	FileNoeud* n = nouveau_fnoeud(ptr);
	
	if (fi->last == NULL)
	{
		fi->last = n;
		fi->first = n;
		return;
	}
	
	fi->last->next = n;
	fi->last = n;
}



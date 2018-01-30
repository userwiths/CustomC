#include "stdlib.h"
#include "string.h"
//#include <ctype>

#define IS ==
#define NOT !=
#define AND &&
#define OR ||
#define LS <
#define GR >
#define LEQ <=
#define GEQ >=

#define MAX_PAGE 4096
#define MAX_LINE 1024
#define LEN(A) sizeof(A)/sizeof(A[0])
#define STRING char*
#define VAR void*
#define CELL(A,B) *(A+B)
#define BG_CHAR setlocale(LC_ALL,"Bulgaria")
#define PAUSE getchar()

int PrintLike(void** arr,int sz,char* format){
	int i=0;
	for(i=0;i<sz;i++){
		printf(format,arr[i]);
	}
	return 0;
}

int DigitsNum(int num){
	int count=0;
	while(num/10){
		count++;
		num/=10;
	}
	return count+1;
}

int DigitsSum(int num){
	int sum=0;
	while(num/10){
		sum+=num%10;
		num/=10;
	}
	sum+=num;
	return sum;
}

void* Max(void** arr,int sz){
	void* max=NULL;
	int i;
	for(i=0;i<sz;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

void* Min(void** arr,int sz){
	void* min=arr[0];
	int i;
	for(i=0;i<sz;i++){
		if(arr[i]<min){
			min=arr[i];
		}
	}
	return min;
}

int IndexOf(void** arr,int sz,void* itm){
	int i;
	for(i=0;i<sz;i++){
		if(arr[i] IS itm){
			return i;
		}
	}
	return -1;
}

int HasItem(void** arr,int sz,void* itm){
	int i,count=0;
	for(i=0;i<sz;i++){
		if(arr[i] IS itm){
			count++;
		}
	}
	return count;
}

int Where(void** arr,int sz,int (*rule)(void*),void* (*action)(void*)){
	int i;
	for(i=0;i<sz;i++){
		if((*rule)(arr[i])){
			(*action)(arr[i]);
		}
	}
	return 0;
}

int ascending_rule(void* f,void* t){
	if(f>t){
		return 1;//Shall Swap them.
	}	
}

int descending_rule(void* f,void* t){
	if(f<t){
		return 1;
	}
}

 



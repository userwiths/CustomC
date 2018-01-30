#include "stdlib.h"
#include "stdio.h"

#include "misc.h"

struct Array{
	void** items;
	int lenght;
};

struct Array Array(){
	struct Array arr;
	arr.lenght=0;
	arr.items=(void*)malloc(sizeof(char*));
	return arr;
}

int Add(struct Array* arr,void* itm){
	arr->items[arr->lenght]=itm;
	arr->lenght++;
	realloc(arr->items,(arr->lenght+1)*sizeof(char*));
	return 0;
}

int InsertAt(struct Array* arr,void* itm,int  index){
	int i;
	arr->lenght++;
	realloc(arr->items,(arr->lenght+1)*sizeof(char*));
	i=arr->lenght;
	while(i>=index){
		arr->items[i]=arr->items[i-1];
		i--;
	}
	arr->items[i]=itm;
	return 0;
}

int Remove(struct Array* arr,void* itm){
	int i,replace=0;
	for(i=0;i<arr->lenght;i++){
		if(arr->items[i] IS itm OR replace AND i<arr->lenght-1){
			replace=1;
			arr->items[i]=arr->items[i+1];
		}
	}
	arr->lenght--;
	realloc(arr->items,(arr->lenght+1)*sizeof(char*));
	return 0;
}

int RemoveAll(struct Array* arr,void* itm){
	int count=Count(arr,itm);
	while(count){
		Remove(arr,itm);
		count--;
	}
	return 0;
}

int RemoveAt(struct Array* arr,int pos){
	int i;
	while(pos<arr->lenght-1){
		arr->items[pos]=arr->items[pos+1];
		pos++;
	}
	return 0;
}

int Has(struct Array arr,void* itm){
	int i;
	for(i=0;i<arr.lenght;i++){
		if(arr.items[i] IS itm){
			return i;
		}
	}
	return -1;
}

int ForEach(struct Array* arr, void (*func)(void*)){
	int i,res;
	for(i=0;i<arr->lenght;i++){
		(*func)(arr->items[i]);
	}
	return 0;
}

int Replace(struct Array* arr,void* itm,int count){
	int i;
	for(i=0;i<arr->lenght;i++){
		if(arr->items[i] IS itm){
			arr->items[i]=itm;
			if(count IS 0){
				return 0;
			}else{
				count--;
			}
		}
	}
	return 0;
}

int Count(struct Array* arr,void* itm){
	int count=0;
	for(int i=0;i<arr->lenght;i++){
		if(arr->items[i] IS itm){
			count++;
		}
	}
	return count;
}

int Delete(struct Array* arr){
	free(arr->items);
	return 0;
}



#include "misc.h"
#include "stdio.h"
#include "stdlib.h"

struct Pair{
	void* key;
	void* value;
};

struct Dictionary{
	struct Pair* items;
	int lenght;
};

struct Pair Pair(void* k,void* v){
	struct Pair pr;
	pr.key=k;
	pr.value=v;
	return pr;
}

struct Dictionary Dictionary(){
	struct Dictionary dct;
	dct.lenght=0;
	dct.items=malloc(sizeof(struct Pair));
	return dct;
}

int SetKey(struct Dictionary *dict,void* itm,int index){
	if(index>dict->lenght){
		return -1;
	}else{
		dict->items[index].key=itm;
	}
	return 0;
}

int SetValue(struct Dictionary *dict,void* itm,int index){
	if(index>dict->lenght){
		return -1;
	}else{
		dict->items[index].value=itm;
	}
	return 0;
}

int SetKeyValue(struct Dictionary *dict,void* key,void* value){
	int i=0;
	for(i=0;i LS dict->lenght;i++){
		if(dict->items[i].key IS key){
			dict->items[i].value = value;
			return 0;
		}
	}
	return -1;
}

int ContainsKey(struct Dictionary *dict,void* itm){
	int i=0;
	for(i=0;i<dict->lenght;i++){
		if(dict->items[i].key IS itm){
			return i;
		}
	}
	return -1;
}

int GetKeyValue(struct Dictionary *dict,void* key,struct Pair* out){
	int i=ContainsKey(dict,key);
	if(i){
		out=&dict->items[i];
		return 0;
	}
	return -1;
}

int AddPair(struct Dictionary *dict,struct Pair itm){
	if(ContainsKey(dict,itm.key)!=-1){
		SetKeyValue(dict,itm.key,itm.value);
		return 0;
	}
	dict->items[dict->lenght]=itm;
	dict->lenght+=1;
	realloc(dict->items,(dict->lenght+1)*sizeof(struct Pair));
	return 0;
}

int RemoveByKey(struct Dictionary *dict,void* key){
	int i,e=-1;
	struct Pair swap;
	for(i=0;i<dict->lenght;i++){
		if(dict->items[i].key IS key){
			e=i;
			break;
		}
	}
	
	if(e IS -1){
		return -1;
	}
	
	while(e<dict->lenght-1){
		swap=dict->items[e];
		dict->items[e]=dict->items[e+1];
		dict->items[e+1]=swap;
		e++;
	}

	dict->lenght-=1;
	realloc(dict->items,(dict->lenght+1)*sizeof(struct Pair));

	return 0;
}

int PrintDict(struct Dictionary dict,char* format){
	int i=0;
	for(i=0;i<dict.lenght;i++){
		printf(format,dict.items[i].key,dict.items[i].value);
	}
	return 0;
}

int DeleteDict(struct Dictionary *dict){
	free(dict->items);
	return 0;
}

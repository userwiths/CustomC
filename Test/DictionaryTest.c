
#include "dictionary.h"

int main(){
	struct Dictionary dict=Dictionary();
	
	AddPair(&dict,Pair("First Name","Stiliyan"));
	AddPair(&dict,Pair("Second name","Tonchev"));
	AddPair(&dict,Pair("Last Name","Tonev"));

	PrintDict(dict,"%s : %s\n");
	return 0;
}

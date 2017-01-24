#include "coda.h"

using namespace std;
using namespace files;

coda::coda(){
	count = 0;
}

bool coda::append(const T & e){
	if(full()) return false;
	file[count]=e;
	count++;
	return true;
}

bool coda::pop(T & e){
	if(empty()) return false;
	e=file[0];
	for(int i=0;i<dim-1;i++){
		file[i]=file[i+1];
	}
	count--;
	return true;
}

void coda::save_txt(const char* filename)const{
	ofstream of(filename);
	if(of.fail()) cout << "errore file!\n";
	for(int i=0;i<count;i++){
		file[i].memorizza_txt(of);
	}
	
	of.close();
}

void coda::save_bin(const char* filename)const{
	ofstream of;
	of.open(filename, ios::binary);
	if(of.fail()) cout << "errore file!\n";
	for(int i=0;i<count;i++){
		file[i].memorizza_dati(of);
	}
	of.close();
}






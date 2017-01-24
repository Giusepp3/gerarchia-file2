#ifndef CODA_H
#define CODA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "file.h"

using namespace std;
using namespace files;

typedef filemedia T;

//la coda è una coda di puntatori a classe base per utilizzare il polimorfismo

//implementazione con vettore

class coda{
	static const int dim = 50;
	T file[dim];
	int count;
	public:
		explicit coda();
		bool append(const T &);
		bool pop(T &);
		bool empty()const{return count==0;}
		bool full()const{return count==dim-1;}
		void save_bin(const char* filename)const;
		void save_txt(const char* filename)const;
};



#endif //CODA_H

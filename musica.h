#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "file.h"

using namespace std;

namespace files{
	
	class branomusic : public filemedia{
		private:
			char* brano;
			char* interprete;
			float time;
			virtual void serialize(ofstream & of)const;
			virtual void deserialize(ifstream & in);
			virtual void print(ostream & os)const;
			virtual void read(istream & in);
			virtual void savefile(ofstream & of)const;
			
		public:
			branomusic();
			branomusic(const char*, const int, const char*, const char*, const char*, const float);
			virtual ~branomusic();
			branomusic(const branomusic &);
			const branomusic& operator=(const branomusic &);
			void set_brano(const char*);
			void set_int(const char*);
			void set_time(const float);
			char* get_brano()const{return brano;}
			char* get_int()const{return interprete;}
			float get_time()const{return time;}
			virtual void save_bin(const char*)const;
			virtual void save_txt(const char*)const;
			friend ostream & operator<<(ostream & os, const branomusic &);
			friend istream & operator>>(istream & in, branomusic &);
			virtual void memorizza_dati(ofstream & of)const{serialize(of);}
			virtual void memorizza_txt(ofstream & of)const{savefile(of);}
			
	};
	
	
	
	
	
	
	
	
	
	
	
	
}

#endif //MUSIC_H

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "file.h"

using namespace std;

namespace files{
	
	class video : public filemedia{
		private:
			char* autore;
			char* soggetto;
			char* data;
			virtual void serialize(ofstream & of)const;
			virtual void deserialize(ifstream & in);
			virtual void print(ostream & of)const;
			virtual void read(istream & in);
			virtual void savefile(ofstream & of)const;
		public:
			video();
			video(const char*, const int, const char*, const char*, const char*, const char*);
			virtual ~video();
			video(const video &);
			const video & operator=(const video &);
			void set_aut(const char*);
			void set_sogg(const char*);
			void set_data(const char*);
			char* get_aut()const{return autore;}
			char* get_sogg()const{return soggetto;}
			char* get_data()const{return data;}
			virtual void save_bin(const char*)const;
			virtual void save_txt(const char*)const;
			friend ostream & operator<<(ostream & os, const video &);
			friend istream & operator>>(istream & in, video &);
			virtual void memorizza_dati(ofstream & of)const{serialize(of);}
			virtual void memorizza_txt(ofstream & of)const{savefile(of);}
			
		
	};
	
	
	
	
	
	
	
	
	
	
	
	
	
}

#endif //VIDEO_H

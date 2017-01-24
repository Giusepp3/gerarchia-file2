#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

namespace files{
	
	class filemedia{
		private:
			char* url;
			int kbyte;
			char* formato;
		protected:
			virtual void serialize(ofstream & of)const;
			virtual void deserialize(ifstream & in);
			virtual void print(ostream & of)const;
			virtual void read(istream & in);
			virtual void savefile(ofstream & of)const;
			
			
			
		public:
			filemedia();
			filemedia(const char*, const int, const char*);
			virtual ~filemedia();
			filemedia(const filemedia &);
			const filemedia& operator=(const filemedia&);
			virtual void save_bin(const char*)const;
			virtual void save_txt(const char*)const; //implementare la read
			friend ostream & operator<<(ostream & of, const filemedia &);
			friend istream & operator>>(istream & in, filemedia & );
			void set_url(const char*);
			void set_kbyte(const int);
			void set_form(const char*);
			char* get_url()const{return url;}
			int get_kbyte()const{return kbyte;}
			char* get_form()const{return formato;}
			virtual void memorizza_dati(ofstream & of)const{serialize(of);}	
			virtual void memorizza_txt(ofstream & of)const{savefile(of);}		
			
	};
	
	
	
	
	
	
	
	
	
	
	
}


#endif //FILE_H

#include "file.h"

using namespace std;

namespace files{
	
	filemedia::filemedia(){
		url = new char[1];
		strcpy(url,"");
		kbyte=0;
		formato=new char[1];
		strcpy(formato,"");
		
	}
	
	filemedia::filemedia(const char* web, const int dim, const char* ext){
		url = new char[strlen(web)+1];
		strcpy(url,web);
		kbyte=dim;
		formato=new char[strlen(ext)+1];
		strcpy(formato,ext);
		
	}
	
	filemedia::filemedia(const filemedia & f){
		url = new char[strlen(f.url)+1];
		strcpy(url,f.url);
		kbyte=f.kbyte;
		formato=new char[strlen(f.formato)+1];
		strcpy(formato,f.formato);
		
	}
	
	filemedia::~filemedia(){
		delete [] url;
		delete [] formato;
	}
	
	const filemedia& filemedia::operator=(const filemedia& f){
		if(this==&f) return *this;
		set_url(f.url);
		set_kbyte(f.kbyte);
		set_form(f.formato);
		return *this;
	}
	
	void filemedia::set_url(const char* url){
		if(this->url) delete [] this->url;
		this->url=new char[strlen(url)+1];
		strcpy(this->url,url);
		
	}
	
	void filemedia::set_kbyte(const int kbyte){
		this->kbyte=kbyte;
	}
	
	void filemedia::set_form(const char* form){
		if(this->formato) delete [] this->formato;
		this->formato=new char [strlen(form)+1];
		strcpy(this->formato,form);
	}
	
	
	void filemedia::serialize(ofstream & of)const{
		int len1,len2;
		len1=strlen(url);
		of.write((char*)&len1,sizeof(len1));
		of.write(url,len1);
		len2=strlen(formato);
		of.write((char*)&kbyte,sizeof(kbyte));
		of.write((char*)&len2,sizeof(len2));
		of.write(formato,len2);
	}
	
	void filemedia::deserialize(ifstream & in){
		int len1,len2;
		char* buffer;
		in.read((char*)&len1,sizeof(len1));
		buffer=new char[len1+1];
		in.read(buffer,len1);
		buffer[len1]='\0';
		set_url(buffer);
		in.read((char*)&kbyte,sizeof(kbyte));
		in.read((char*)&len2,sizeof(len2));
		delete [] buffer;
		buffer = new char[len2+1];
		in.read(buffer,len2);
		buffer[len2]= '\0';
		set_form(buffer);
	}
	
	void filemedia::save_bin(const char* filename)const{
		ofstream of;
		of.open(filename,ios::binary);
		if(of.fail()) cout << "errore file\n";
		this->serialize(of);
		of.close();
		
	}
	
	
	void filemedia::print(ostream & os)const{
		os << url << ' ' << kbyte << ' ' << formato <<' ';
	}
	
	ostream & operator<<(ostream & os, const filemedia & f){
		f.print(os);
		return os;
	}
	
	void filemedia::read(istream & in){
		char buffer[800];
		int buf;
		in.getline(buffer,799);
		set_url(buffer);
		in >> buf;
		set_kbyte(buf);
		in.ignore();
		in.getline(buffer,799);
		set_form(buffer);
	}
	
	istream & operator>>(istream & in, filemedia &f ){
		f.read(in);
		return in;
	}

	void filemedia::save_txt(const char* filename)const{
		ofstream of(filename);
		if(of.fail()) cout << "errore file\n";
		savefile(of);
		of.close();
		 
	}	
	
	void filemedia::savefile(ofstream & of)const{
		of << strlen(url) << ' '<< url << ' ' << kbyte << ' ' << strlen(formato) << ' ' << formato << ' ';
	}
	
	
	
	
	
	
	
	
}

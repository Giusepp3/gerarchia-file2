#include "video.h"

using namespace std;

namespace files{
	
	video::video() : filemedia(){
		autore = new char[1];
		strcpy(autore,"");
		soggetto = new char[1];
		strcpy(soggetto,"");
		data = new char[1];
		strcpy(data,"");
	}
	
	video::video(const char* ad, const int dim, const char* ext, const char* aut, const char* sog, const char* dt) : filemedia(ad,dim,ext){
		autore = new char[strlen(aut)+1];
		strcpy(autore,aut);
		soggetto = new char[strlen(sog)+1];
		strcpy(soggetto,sog);
		data = new char[strlen(dt)+1];
		strcpy(data,dt);
	}
	
	video::video(const video & v) : filemedia(v){
		autore = new char[strlen(v.autore)+1];
		strcpy(autore,v.autore);
		soggetto = new char[strlen(v.soggetto)+1];
		strcpy(soggetto,v.soggetto);
		data = new char[strlen(v.data)+1];
		strcpy(data,v.data);
	}
	
	video::~video(){
		delete [] autore;
		delete [] soggetto;
		delete [] data;
	}
	
	void video::set_aut(const char* aut){
		if(autore) delete [] autore;
		autore = new char[strlen(aut)+1];
		strcpy(autore,aut);
	}
	
	void video::set_sogg(const char* sog){
		if(soggetto) delete [] soggetto;
		soggetto = new char[strlen(sog)+1];
		strcpy(soggetto,sog);
	}
	
	void video::set_data(const char* d){
		if(data) delete [] data;
		data = new char[strlen(d)+1];
		strcpy(data,d);
	}
	
	const video& video::operator=(const video & v){
		if(this==&v) return *this;
		filemedia::operator=(v);
		set_aut(v.autore);
		set_sogg(v.soggetto);
		set_data(v.data);
		return *this;
	}
	
	
	void video::print(ostream & of)const{
		filemedia::print(of);
		of << autore << ' ' << soggetto << ' ' << data << ' ';
	}
	
	ostream & operator<<(ostream & of, const video & v){
		v.print(of);
		return of;
	}
	
	void video::read(istream & in){
		filemedia::read(in);
		char buffer[800];
		in.getline(buffer,799);
		set_aut(buffer);
		in.getline(buffer,799);
		set_sogg(buffer);
		in.getline(buffer,799);
		set_data(buffer);
	}
	
	istream & operator>>(istream & in, video & v){
		v.read(in);
		return in;
	}
	
	void video::savefile(ofstream & of)const{
		filemedia::savefile(of);
		of << autore << ' ' << soggetto << ' ' << data << ' ';
	}
	
	void video::save_txt(const char* filename)const{
		ofstream of(filename);
		if(of.fail()) cout << "errore file\n";
		savefile(of);
		of.close();
	}
	
	void video::serialize(ofstream & of)const{
		filemedia::serialize(of);
		int len1,len2,len3;
		len1=strlen(autore);
		len2=strlen(soggetto);
		len3=strlen(data);
		of.write((char*)&len1,sizeof(len1));
		of.write(autore,len1);
		of.write((char*)&len2,sizeof(len2));
		of.write(soggetto,len2);
		of.write((char*)&len3,sizeof(len3));
		of.write(data,len3);
	}
	
	void video::save_bin(const char*filename)const{
		ofstream of;
		of.open(filename, ios::binary);
		if(of.fail()) cout << "errore file\n";
		serialize(of);
		of.close();
	}
	
	void video::deserialize(ifstream & in){
		filemedia::deserialize(in);
		char* buffer;
		int len1,len2,len3;
		in.read((char*)&len1,sizeof(len1));
		buffer = new char[len1+1];
		in.read(buffer,len1);
		buffer[len1]='\0';
		set_aut(buffer);
		in.read((char*)&len2,sizeof(len2));
		delete [] buffer;
		buffer=new char[len2+1];
		in.read(buffer,len2);
		buffer[len2]='\0';
		set_sogg(buffer);
		delete [] buffer;
		in.read((char*)&len3,sizeof(len3));
		buffer=new char[len3+1];
		in.read(buffer,len3);
		buffer[len3]='\0';
		set_data(buffer);
		delete [] buffer;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

#include "musica.h"

using namespace std;

namespace files{
	
	branomusic::branomusic() : filemedia(){
		brano=new char[1];
		strcpy(brano,"");
		interprete=new char[1];
		strcpy(interprete,"");
		time=0;
	}
	
	branomusic::branomusic(const char* ad, const int dim, const char* ext, const char* br, const char* intrp, const float tm) : filemedia(ad,dim,ext){
		brano=new char[strlen(br)+1];
		strcpy(brano,br);
		interprete=new char[strlen(intrp)+1];
		strcpy(interprete,intrp);
		time=tm;
	}
	
	branomusic::branomusic(const branomusic & b) : filemedia(b){
		brano=new char[strlen(b.brano)+1];
		strcpy(brano,b.brano);
		interprete=new char[strlen(b.interprete)+1];
		strcpy(interprete,b.interprete);
		time=b.time;
	}
	
	const branomusic& branomusic::operator=(const branomusic& b){
		if(this==&b) return *this;
		filemedia::operator=(b);
		set_brano(b.brano);
		set_int(b.interprete);
		set_time(b.time);
		return *this;
		
	}
	
	
	void branomusic::set_brano(const char* br){
		if(brano) delete [] brano;
		brano = new char[strlen(br)+1];
		strcpy(brano,br);
	}
	
	void branomusic::set_int(const char* in){
		if(interprete) delete [] interprete;
		interprete = new char[strlen(in)+1];
		strcpy(interprete,in);
	}
	
	void branomusic::set_time(const float t){
		time = t;
	}
	
	
	branomusic::~branomusic(){
		delete [] brano;
		delete [] interprete;
	}
	
	
	void branomusic::serialize(ofstream & of)const{
		filemedia::serialize(of);
		int len1,len2;
		len1=strlen(brano);
		len2=strlen(interprete);
		of.write((char*)&len1,sizeof(len1));
		of.write(brano,len1);
		of.write((char*)&len2,sizeof(len2));
		of.write(interprete,len2);
		of.write((char*)&time,sizeof(time));
	}
	
	void branomusic::save_bin(const char* filename)const{
		ofstream of;
		if(of.fail()) cout << "errore file\n";
		of.open(filename,ios::binary);
		serialize(of);
		of.close();
	}
	
	void branomusic::save_txt(const char* filename)const{
		ofstream of(filename);
		if(of.fail()) cout << "errore file\n";
		savefile(of);
		of.close();
	}
	
	void branomusic::savefile(ofstream & of)const{
		filemedia::savefile(of);
		of << strlen(brano) << ' '<< brano << ' ' << strlen(interprete) << ' ' << interprete << ' ' << time << ' ';
	}
	
	void branomusic::deserialize(ifstream & in){
		filemedia::deserialize(in);
		int len1, len2;
		char* buffer;
		in.read((char*)&len1,sizeof(len1));
		buffer=new char[len1+1];
		in.read(buffer,len1);
		buffer[len1]='\0';
		set_brano(buffer);
		in.read((char*)&len2,sizeof(len2));
		delete [] buffer;
		buffer = new char[len2+1];
		in.read(buffer,len2);
		set_int(buffer);
		delete [] buffer;
		in.read((char*)&time,sizeof(time));
	}
	
	void branomusic::print(ostream & os)const{
		filemedia::print(os);
		os << brano << ' ' << interprete << ' ' << time << ' ';
	}
	
	ostream & operator<<(ostream & os, const branomusic & b){
		b.print(os);
		return os;
	}
	
	
	void branomusic::read(istream & in){
		filemedia::read(in);
		char buffer [800];
		in.getline(buffer,799);
		set_brano(buffer);
		in.getline(buffer,799);
		set_int(buffer);
		in >> time;
		in.ignore();
	}
	
	istream & operator>>(istream & in, branomusic & b){
		b.read(in);
		return in;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

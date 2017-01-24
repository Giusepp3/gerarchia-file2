#include <iostream>
#include "file.h"
#include <fstream>
#include <cstring>
#include "musica.h"

using namespace std;

using namespace files;


int main(int argc, char** argv) {
	
	branomusic b("www.spotify.com/songn1341",414,".mp3","ed-sheeran","ed-sheeran",3.4);
	
	b.save_bin("brano.bin");

	
	
	
	return 0;
}

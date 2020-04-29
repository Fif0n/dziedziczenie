#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct towar{
	int id;
	float cena;
	string nazwa;
};
struct buty: public towar{
	int rozmiar;
	string model, kolor;
};

struct pasty : public towar{
	string kolor;
};

class sklep {
	vector <struct buty> spis_butow;
	vector <struct pasty> spis_past;
	ifstream buty;
	ifstream pasty;
	ofstream towary;
		public:
			sklep();
			~sklep();
			
			void wczytaj_z_pliku();
			void zapisz_do_pliku();
};

	sklep::sklep(){
		buty.open("c:\\buty.txt");
    	pasty.open("c:\\pasty.txt");
    	towary.open("c:\\towary.txt");
	}

	void sklep::wczytaj_z_pliku(){
		struct buty but;
		struct pasty pasta;
		while(!buty.eof()){
			buty>>but.id>>but.cena>>but.nazwa>>but.rozmiar>>but.model>>but.kolor;
			spis_butow.push_back(but);
		}
		while(!pasty.eof()){
			pasty>>pasta.id>>pasta.cena>>pasta.nazwa>>pasta.kolor;
			spis_past.push_back(pasta);
		}
	}
	
	void sklep::zapisz_do_pliku(){
		towary<<"["<<endl;
		for(vector <struct buty>::iterator it = spis_butow.begin(); it != spis_butow.end(); ++it){
			towary<<"{\"typ_towaru"":\"\but\", \"id\":\""<<it->id<<"\", \"cena\":\""<<it->cena<<"\", \"nazwa\":\""<<it->nazwa<<"\", \"rozmiar\":\""<<it->rozmiar<<"\", \"model\":\""<<it->model<<"\", \"kolor\":\""<<it->kolor<<"\"},"<<endl;
		}
		for(vector <struct pasty>::iterator it = spis_past.begin(); it != spis_past.end(); ++it){
			towary<<"{\"typ_towaru"":\"\pasta\", \"id\":\""<<it->id<<"\", \"cena\":\""<<it->cena<<"\", \"nazwa\":\""<<it->nazwa<<"\", \"kolor\":\""<<it->kolor<<"\"},"<<endl;
		}
		towary<<"]";
	}
	
	sklep::~sklep(){
		buty.close();
    	pasty.close();
    	towary.close();
	}

int main(int argc, char** argv) {
	sklep s1;
	s1.wczytaj_z_pliku();
	s1.zapisz_do_pliku();
	
	return 0;
}

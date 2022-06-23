#include <iostream>
using namespace std;

struct mahasiswa{
	string nama;
	int nim;
};
class studi{
  	friend istream& operator >> (istream&, studi&);
	public :
		void proses();
		void output();
	private :
		int i;
		mahasiswa data[20];
		int *a[5];
		string *a1[5];		
};

istream& operator >> (istream& cin, studi& x){
	
	for(int i=0;i<5;i++){
		cout<<"Nama "<<i+1<<":";
		cin>>x.data[i].nama;
		cout<<"NIM "<<i+1<<":";
		cin>>x.data[i].nim;
	}
	return cin;
}
void studi::proses(){
	for(int i=0;i<5;i++){
	a1[i]=&data[i].nama;
	a[i]=&data[i].nim;
	}
}
void studi::output(){
		cout << "======= Data yang Disimpan =======\n";
	cout << "+================================+\n";
	cout << "||\tNIM\t||\tNAMA\t||" << endl;
	cout << "+================================+\n";
	for(int i=0;i<5;i++){
		cout << "||	" << *a[i] << "\t||	" << *a1[i] << "\t||"<<endl;
	}	
	cout << "+================================+\n";
}

int main(){
	studi x;
	cin >> x;
	x.proses();
	x.output();	
	return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

static int simpleSearch(char* txt, string search, int txt_length, int search_length) {
	int counterIterations = 0;
	int counterMove = 0;
	for (int i = 0; i <= txt_length - search_length; i++) {
		counterIterations++;
		counterMove++;
		for (int j = 0; txt[i + j] == search[j]; j++) {
			counterIterations++;
			counterMove += 2;
			if (search_length - j == 1) {
				cout << "Iterations and moves: " << counterIterations + counterMove << endl;
				return i;  
			}
		}
	}
	cout << "Iterations and moves: "  << counterIterations + counterMove << endl;
	return -1;
}

int main()
{
	ifstream file;
	file.open("D:\\test1.txt");
	if (file){
		file.seekg(0, file.end); // seekg - функци€, позвол€юща€ искать произвольную позицию в файле
		int txt_length = file.tellg(); // tellg - возвращает текущую позицию в файле
		file.seekg(0, file.beg); //beg - означает направление от начала файла
		char* txt = new char[txt_length];
		file.get(txt, txt_length +1); // get - ввод данных из файла file в массив line, при этом он вводит туда length+1 элементов
		cout << txt << endl;
		string search;
		cin >> search;
		int search_length = search.length();
		cout << "Index: " << simpleSearch(txt, search, txt_length, search_length) << " ";
	}
	else{
		cout << "file could not be opened";
	}
}
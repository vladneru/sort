// ConsoleApplication22.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>// ?
#include <iterator>
#include <algorithm>
using namespace std;

struct Vlad {

	int vladik;
};


class B {
public:
	B(string name_main_file);
	auto division()->void;
	auto file_size(string name_file)->size_t;
	auto make_file(string name_file)->void;
	auto file_sort()->void;
	auto open_streams()->void;
private:
	fstream file;
	bool out;
	size_t buffer, count_of_files;
	vector<string> lines;
};

B::B(string name_main_file) :file(name_main_file), buffer(100), count_of_files(0),out(true) {
	if (file.is_open()) {
		division();
	}
};

auto B::make_file(string name_file)->void {
	std::sort(lines.begin(),lines.end());
	ofstream temp(name_file);
	for (auto i : lines)
	{
		temp << i;
		if (i != *(--lines.end())) temp << endl;
	}
	temp.close();
	lines.clear();
}

auto B::file_size(string name_file)->size_t { // TESTED
	long fsize;
	ifstream temp(name_file);
	temp.seekg(0, ios::end);
	fsize = temp.tellg();
	temp.close();
	return fsize;

}


bool ya(string* p, int k)
{
	for (int i = 0; i < k; ++i) if (p[i] != "яяя") return false;
	return true;
}

auto B::open_streams()->void {
	

}



auto B::file_sort()->void {

	ifstream *files_streams = new ifstream[count_of_files];
	for (int i = 1; i <= count_of_files; i++) {
		files_streams[i].open(to_string(i) + ".txt");
	}

	string *top_line = new string[count_of_files];
	for (int i = 1; i <= count_of_files; i++)
	{
		getline(files_streams[i], top_line[i]);
	}

	while (!ya(top_line, count_of_files)) {
		string temp_min_line = top_line[0];
		int k_min = 0;
		for (int i = 0; i < count_of_files; ++i)
		{
			if (top_line[i] < temp_min_line)
			{
				temp_min_line = top_line[i];
				k_min = i;
			}
		}
		ofstream file("out.txt", ios::app);
		file << temp_min_line << endl;
		file.close();
		if (!files_streams[k_min].eof())
		{
			string s_new;
			getline(files_streams[k_min], s_new);
			top_line[k_min] = s_new;
		}
		else {
			top_line[k_min] = "яяя";
		}

	}
	for (int i = 0; i < count_of_files; ++i) files_streams[i].close();
}


auto B::division()->void {
	string line_of_file;
	size_t temp_size_files=0;
	while (!file.eof()) {
		getline(file, line_of_file);
		temp_size_files += line_of_file.size()+2;
		if (temp_size_files <= buffer) {
			lines.push_back(line_of_file);
		}
		else {
			count_of_files++;
			make_file(to_string(count_of_files)+".txt");
			lines.push_back(line_of_file);
			temp_size_files = line_of_file.size();
		}
	}
	file.close();
	file_sort();
};


int main()
{
	B obj("names.txt");


	system("pause");
    return 0;
}


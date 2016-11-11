// ConsoleApplication21.cpp: определяет точку входа для консольного приложения.
//

// SortBigFiles.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
#include <io.h>
#include <stdlib.h>
#include <sstream>
#include <map>
#include <locale.h>
using namespace std;

class File_Work {
public:
	File_Work(string name);

private:
ifstream mini_block;//файл
string mini_line;
};

File_Work::File_Work(string name):mini_block(name) {
	if (mini_block) {
		getline(mini_block,mini_line);
	}
}



template <typename T>
class SortFile {
public:
	auto Open_Division()->const void;//разделение на блоки исходного файла в соответствии с памятью в буфере
	auto CreateNewFile()->void;// create Block_File

	SortFile(string name);//открытие файла и вызов open_division
	SortFile();
	auto isOpened()->bool;//проверка открылся ли файл
	auto FileSize(string s)->int;//получаем размер файла
	auto Sort(const string file_name)->void;
	auto make_file(const string file_name)->void;
	auto link_sort(string line2)->void;

private:
	size_t size_avail_buff;//доступная операционная память 
	fstream file;//файл
	string main_file;//имя исходного файла
	size_t buff;//размер буфера
	list<string> lines;
	map<string, ifstream> temp_files;
	vector<string> file_names;

};

template<typename T>
auto SortFile<T>::link_sort(string line2)->void {

	temp_files.emplace(line, ifstream(file_name));
	getline(temp_files[line], line2);
	cout << line2 << "TUT" << endl;
	link_sort(line2);
}


template<typename T>
auto SortFile<T>::Sort(const string file_name)->void {
	
	string line, temp_line, main_line,line2;
	int i = 0;
	ifstream temp(file_name);
	while (!temp.eof()) {
		getline(temp, line);
		temp_line = line.substr(0, line.find(' ')) + "\n";
		main_line = line;
		lines.push_back(temp_line);
		if (i == 0) {
			
		}
		i++;
	}
	lines.sort();
	temp.close();

	ofstream my(file_name, ios::out);
	copy(lines.begin(), lines.end(), ostream_iterator<string>(my, ""));
	my.close();
	lines.clear();
	

}


template<typename T>
SortFile<T>::SortFile(string name) : file(name), main_file(name), buff(100) {
	if (isOpened() == true) Open_Division();
}

template <typename T>
auto SortFile<T>::isOpened()->bool {
	return file.is_open();
}


template <typename T>
auto  SortFile<T>::FileSize(string s)->int {
	long fsize;
	FILE *o = fopen(s, "rb");
	fsize = _filelength(_fileno(o));
	fclose(o);
	return fsize;
}

template<typename T>
auto SortFile<T>::make_file(const string file_name)->void
{
	ofstream ofile(file_name);
	copy(lines.begin(), lines.end(), ostream_iterator<string>(ofile,""));
	ofile.close();
	file_names.push_back(file_name);
	lines.clear();
	Sort(file_name);
}



template<typename T>
auto SortFile<T>::Open_Division()->const void {
	size_t i = 0;
	size_t SizeOfList=0;
	string line, temp_line;
	while (!file.eof()) {
		
		getline(file, line);
		temp_line = line.substr(0, line.find('\n'));
		SizeOfList += temp_line.size()+2;
		
		if (SizeOfList <= 100) {
			lines.push_back(temp_line);
			lines.push_back("\n");
		}
		else {
			lines.pop_back();
			i++;
			make_file(to_string(i)+".txt");
			lines.push_back(temp_line+"\n");
			SizeOfList = temp_line.size()+2;
			
		}
	}
	
	file.close();
};



int file_exist(const char *filename)
{
	struct stat   buffer;
	return (stat(filename, &buffer) == 0);
}

template<typename T>
auto SortFile<T>::CreateNewFile()->string{
	
	
	
	
	
}


int main()
{
	setlocale(LC_ALL, "rus");
	SortFile<int> newfile("names.txt");

	system("pause");
	return 0;

}



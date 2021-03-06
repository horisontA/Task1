#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace boost::filesystem;
using namespace std;

void main(int argc, char* argv[1])
{
	SetConsoleCP(1251);			
	SetConsoleOutputCP(1251);	
	string dir_path = "C:\\";
	cout << "Enter the directory path:\n" << endl;
	
	
	try
	{
		cin >> dir_path;
		path path = dir_path;
		if (!is_directory(path))
			throw "\nIncorrect path, try again!\n\n";
	}
	catch (const char* msg)
	{
		cout << msg;
		system("pause");
		exit(1);
	}


	ofstream fout("result.csv");//creating CSV 
	fout << "Path" << ";" << "Name" << ";" << "Size" << ";" << "Hash" << endl;
	
	
	path path = dir_path;
	recursive_directory_iterator itr(path);
	while (itr != recursive_directory_iterator()) 
	{
		if (!is_directory(itr->status()))
		{	
			fout << itr->path().string() << "; " << itr->path().filename() << "; " << file_size(itr->path()) << endl;
			++itr;
		}
		else
		{
			itr = ++itr;
		}
	}

	fout.close(); //closing CSV
	cout << "\n" << "result.csv in project current directory" << endl;
	system("pause");
}

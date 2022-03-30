#include <string>
#include <vector>
#include "Direction.hpp"
#include <unordered_map>


using namespace std;
using ariel::Direction;

#define SIZE_LINE 100
#define MAX_IN_LINE 99 

namespace ariel{
	// class Line{
	// 	public:
	// 	string lin;
	// 	int amount;
	// 	vector<char> row;
	// 	Line();
	// 	void addLines(int newSize);
	// };
	// class Page{
	// 	public:
	// 	int amount;
	// 	unordered_map<int, char[100]> lines;
	// 	Page();
	// 	void addLines(int newSize);
	// 	void resize(int newSize);
	// };
	class Notebook {
		private:
		int amount;
		unordered_map<int,unordered_map<int,char[100]>> notebook;
		public:
		Notebook();
		void write(int page, int line, int column, Direction, string str);
		string read(int page, int line, int column, Direction, int num);
		void erase(int page, int line, int column, Direction, int num);
		void show(int page); 
	};
};
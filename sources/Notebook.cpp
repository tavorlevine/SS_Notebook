#include <iostream>
#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <unordered_map>

using namespace std;
namespace ariel{
    Notebook::Notebook(){
		this->amount = 0;
	}
	void Notebook::write(int page, int line, int column, Direction direction, string str){
        const int minChar = 32;
		const int maxChar = 125;
		if (page < 0 || line < 0 || column < 0 || column >= SIZE_LINE){
			throw runtime_error("the parameters are ilegall");
		}
		if (direction == Direction::Horizontal && str.length() > SIZE_LINE){
			throw runtime_error("str is too mush big");
		}
		for (int i = 0; i < str.length(); i++){
			if (str[unsigned(i)] == '~' || str[unsigned(i)] < minChar || str[unsigned(i)] > maxChar){
				throw runtime_error("the str is iligall");
			}
		}
		if (direction == Direction::Horizontal){ // left to right
			int flag = column;
			for (int i = 0; i < str.length(); i++){
				if (unsigned(column) + str.length() > MAX_IN_LINE){
					throw runtime_error("str is big");
				}
				if (notebook[page][line][flag] == '~'){
					throw runtime_error("can't write on earese place");
				}
				if (notebook[page][line][flag] < maxChar && notebook[page][line][flag] > minChar ){
					if (notebook[page][line][flag] == '_'){
						notebook[page][line][flag] = str[unsigned(i)];
					}
					else{
						throw runtime_error("can't write on this place");	
					}

				}
				else{
					notebook[page][line][flag] = str[unsigned(i)];	
				}
				flag++;
			}
			// for (int i = 0; i < str.length(); i++)
			// {
			// 	notebook[page][line][column+i] = str[unsigned(i)];
			// 	//column++;
			// }
		}
		else if (direction == Direction::Vertical)
		{ // up to down
			//pages[unsigned(page)].addLines(unsigned(line) + str.length());
			int flag = line;
			for (int i = 0; i < str.length(); i++){
				if (notebook[page][flag][column] == '~'){
					throw runtime_error("can't write on earese place");
				}
				if (notebook[page][flag][column] < maxChar && notebook[page][flag][column] > minChar){
					if (notebook[page][flag][column] == '_'){
						notebook[page][flag][column] = str[unsigned(i)];
					}
					else{
						throw runtime_error("can't write on this place");
					}
				}
				else{
					notebook[page][flag][column] = str[unsigned(i)];
				}
				flag++;
			}
			// for (int i = 0; i < str.length(); i++)
			// {
			// 	if (notebook[page][line][column] == '_')
			// 	{
			// 		notebook[page][line][column] = str[unsigned(i)];
			// 	}
			// }
		}
    }
	string Notebook::read(int page, int line, int column, Direction direction, int num){
		const int min = 31;
		const int max = 127;
		if (page < 0 || line < 0 || column < 0 || num < 0 || column > MAX_IN_LINE){
			throw runtime_error("the parameters are ilegall");
		}
		if (direction == Direction::Horizontal && num + column > SIZE_LINE){
			throw runtime_error("str is too mush big");
		}
		// if (unsigned(column) > MAX_IN_LINE)	{
		// 	throw runtime_error("can't read- the line is end");
		// }
		string ans;
		if (direction == Direction::Horizontal){ // left right
			// int flag = line;
			for (int i = 0; i < num; i++){
				if (notebook[page][line][column +i] < max && notebook[page][line][column+i] > min){
					ans += notebook[page][line][column+i];
				}
				else {
					ans +='_';
				}	
				//column += 1;
			}
		}
		else if (direction == Direction::Vertical){ // up to down
			for (int i = 0; i < num; i++){
				if (notebook[page][line+i][column] < max && notebook[page][line+i][column] > min){
					ans += notebook[page][line+i][column];
				}	
				else{
					ans += '_';
				}
			}
		}
		return ans;        

    }
	void Notebook::erase(int page, int line, int column, Direction direction, int num){
        if (page < 0 || line < 0 || column < 0 || num < 0 || column >= SIZE_LINE)
		{
			throw runtime_error("the parameters are ilegall");
		}
		if (direction == Direction::Horizontal && num > SIZE_LINE){
			throw runtime_error("str is too mush big");
		}
		if (direction == Direction::Horizontal && num+column > SIZE_LINE){
			throw runtime_error("str is too mush big");
		}
		if (direction == Direction::Horizontal)
		{
			for (int i = 0; i < num; i++){
				notebook[page][line][column+i] = '~';
			}
		}
		else if (direction == Direction::Vertical)
		{
			for (int i = 0; i < num; i++){
				notebook[page][line+i][column] = '~';
			}
		}
    }
	void Notebook::show(int page){
		if (page < 0){
			throw runtime_error("no page");
		}
		this->amount = 0;
        cout << "bla" << endl;
    } 

    
}
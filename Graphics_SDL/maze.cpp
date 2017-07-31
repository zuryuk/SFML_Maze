#include "maze.h"
#include <iostream>


maze::maze()
{
	std::cout << "#";
	for (int i = 0; i < 8; i++) {
		std::cout << "-";
	}
	std::cout <<  "#" << std::endl;
	for (int j = 0; j < 8; j++) {
		std::cout << "|";
		for (int i = 0; i < 8; i++) {
			//TOP LEFT
			if (i < 4 && j < 4) {
				if (i == j) {
					std::cout << "#";
				}
				else if (i < j) {
					std::cout << "|";
				}
				else {
					std::cout << "=";
				}
			}
			//TOP RIGHT
			else if (i >= 4 && j < 4) {
				if (i == 7 - j) {
					std::cout << "#";
				}
				else if (i > 7 - j) {
					std::cout << "|";
				}
				else {
					std::cout << "=";
				}
			}
			//BOTTOM LEFT
			else if (i < 4 && j >= 4) {
				if (i == 7 - j) {

					std::cout << "#";
				}
				else if (i < 7 - j) {
					std::cout << "|";
				}
				else {
					std::cout << "=";
				}
			}
			//BOTTOM RIGHT
			else if (i >= 4 && j >= 4) {
				if (i == j) {
					std::cout << "#";
				}
				else if (i > j) {
					std::cout << "|";
				}
				else {
					std::cout << "=";
				}
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "#";
	for (int i = 0; i < 8; i++) {
		std::cout << "-";
	}
	std::cout << "#" << std::endl;
}


maze::~maze()
{
}

#include "stdafx.h"
#include<conio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include<chrono>
#include<vector>
#include<string>
#include<fstream>
class Wiki_graf {
private:
	std::vector<std::string>title;
	std::vector<int>sizes;
	std::vector<int>edges;
	std::vector<int>offset;
	std::vector<short int>redirect;
	int size_graf;
	int rebra;
		
public:
	Wiki_graf(std::string file_name) {
		std::ifstream file(file_name);
		file >> size_graf >> rebra;
		title = std::vector<std::string>(size_graf);
		sizes = std::vector<int>(size_graf);
		edges= std::vector<int>(rebra);
		offset = std::vector<int>(size_graf + 1);
		redirect = std::vector<short int>(size_graf);
		offset[0] = 0;
		for (int i = 0; i < size_graf; i++) {
			std::string tit;
			int s, v, r;
			file >> tit;
			file >> s >> v >> r;
			title[i] = tit;
			redirect[i] = r;
			offset[i + 1] = offset[i] + v;
			sizes[i] = s;
			for (int j = 0; j < v; j++) {
				int h;
				file >> h;
				edges[offset[i] + j] = h;
			}
		}
		std::cout<<"update";

	}
	int get_number_of_links_from(int id) {
		return offset[id];
	}
	int	get_links_from(int id) {
		return edges[id];
	}
		int get_id(std::string s) {
		int j = -1;
		for (int i = 0; i < size_graf; i++) {
			if (title[i] == s) { return i; }
		}
		return j;
	}
		bool is_redirect(int id) {
		return (redirect[id]==0);
	}
		std::string get_title(int id) {
		return title[id];
	}
		
		int get_page_size(int id) {
		return sizes[id];
	}
		int get_size_of_graf() {
		return size_graf;
	}
};
int main(std::string s) {
	Wiki_graf W(s);
	int kol_st_s_per = 0;
	int min_kol_s_from_st = 0;
	int kol_st_s_min_kol_s = 0;
	int max_kol_s_from_st = 0;
	int kol_st_s_max_kol_s = 0;
	std::string s_max = "";


}

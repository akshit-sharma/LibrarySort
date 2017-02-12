
#include <vector>
#include <string>
#include "Main.h"

#pragma once
class Source : public virtual main_class
{
private:

	std::vector <std::string> headers;

	int * scheme_prog_code;
	std::string * prog_name;
	int * scheme_id;
	std::string * prog_sem_year;
	std::string * prepared_date;
	std::string * declared_date;
	int * institution_code;
	std::string * institution_name;
	int * s_number;
	int * paper_id;
	std::string * paper_code;
	std::string * subject_name;
	int * credits;
	std::string * type;
	std::string * exam;
	std::string * mode;
	std::string * kind;
	std::string * minor;
	std::string * major;
	std::string * max_marks;
	std::string * pass_marks;

	static int init_num;

	std::string * sorted_col_string;
	int * sorted_col_int;

	enum type
	{
		inte, string
	};

	enum type sorted_col_type;

	size_t rows;

	bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
	void quicksort(int * toSort, size_t low, size_t high);
	void quicksort(std::string* toSort, size_t low, size_t high);
	size_t partition(int * toSort, size_t low, size_t high);
	size_t partition(std::string* toSort, size_t low, size_t high);
	void swap(const size_t index_1, const size_t index_2);
	bool compare_isLess(std::string str1, std::string str2);
	void shellsort(std::string* toSort, size_t low, size_t high);
	void shellsort(int* toSort, size_t low, size_t high);

public:
	void MemAllo();
	void readFile(const char * file_name);
	void sort(int column);
	void print_table(const char * file_name);
	void MemFree();

};

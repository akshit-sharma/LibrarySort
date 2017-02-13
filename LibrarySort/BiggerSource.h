

#pragma once
#include <vector>
#include <string>
#include "Main.h"

class BiggerSource : public virtual main_class
{
private:

    std::vector<std::string> headers;

    int * scheme_prog_code;
    std::string * prepared_date;
    std::string * declared_date;
    std::string * prog_name;
    std::string * prog_sem_year;
    int * batch;
    std::string * examination;
    int * institution_code;
    std::string * institution_name;
    long long * rollnumber;
    std::string * name;
    long long * sid;
    long long * result_scheme_id;
	int * paper_id;
    std::string * credits;
    std::string * minor;
    std::string * major;
    std::string * total;

	static int init_num;

	std::string * sorted_col_string;
	int * sorted_col_int;
	long long * sorted_col_long;

	enum type
	{
		inte, string, longe
	};

	enum type sorted_col_type;
    size_t rows;

	bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
	void quicksort(std::string * toSort, size_t low, size_t high);
	size_t partition(std::string * toSort, size_t low, size_t high);
	void quicksort(int * toSort, size_t low, size_t high);
	size_t partition(int * toSort, size_t low, size_t high);
	void quicksort(long long * toSort, size_t low, size_t high);
	size_t partition(long long * toSort, size_t low, size_t high);
	void swap(size_t index_1, size_t index_2);
	bool compare_isLess(std::string str1, std::string str2);
	void shellsort(std::string* toSort, size_t low, size_t high);
	void shellsort(long long* toSort, size_t low, size_t high);
	void shellsort(int* toSort, size_t low, size_t high);
	void bubblesort(std::string* toSort, size_t low, size_t high);
	void bubblesort(long long* toSort, size_t low, size_t high);
	void bubblesort(int* toSort, size_t low, size_t high);

public:
	void MemAllo();
	void readFile(const char * file_name);
	void sort(int column);
	void print_table(const char * file_name);
	void MemFree();


};

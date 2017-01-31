

#pragma once
#include <vector>
#include "Main.h"

class BiggerSource : public virtual main_class
{
private:

    std::vector<std::string> headers;

    int * scheme_prog_code;
    char ** prepared_date;
    char ** declared_date;
    char ** prog_name;
    char ** prog_sem_year;
    int * batch;
    char ** examination;
    int * institution_code;
    char ** institution_name;
    long long * rollnumber;
    char ** name;
    long long * sid;
    long long * result_scheme_id;
    char ** credits;
    char ** minor;
    char ** major;
    char ** total;

    enum type{
        inte, string
    };

    size_t rows;

	bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
	void quicksort(long long * toSort, size_t low, size_t high);
	size_t partition(long long * toSort, size_t low, size_t high);
	void swap(size_t index_1, size_t index_2);
	void swapper( char* str1, char* str2);

public:
	BiggerSource();
	void readFile(const char * file_name);
	void sort(int column);
	void print_table(const char * file_name);
	~BiggerSource();


};

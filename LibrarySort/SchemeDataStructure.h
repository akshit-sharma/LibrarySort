#pragma once
#include <string>

class SchemeDataStructure
{
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

public:
	void swap(size_t index_1, size_t index_2);

};

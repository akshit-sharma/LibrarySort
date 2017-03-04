#include "SchemeDataStructure.h"


void SchemeDataStructure::swap(size_t index_1, size_t index_2)
{
	int temp;
	std::string t_string;

	temp = paper_id[index_1];
	paper_id[index_1] = paper_id[index_2];
	paper_id[index_2] = temp;

	temp = scheme_prog_code[index_1];
	scheme_prog_code[index_1] = scheme_prog_code[index_2];
	scheme_prog_code[index_2] = temp;

	temp = institution_code[index_1];
	institution_code[index_1] = institution_code[index_2];
	institution_code[index_2] = temp;

	temp = s_number[index_1];
	s_number[index_1] = s_number[index_2];
	s_number[index_2] = temp;

	temp = credits[index_1];
	credits[index_1] = credits[index_2];
	credits[index_2] = temp;

	t_string = paper_code[index_1];
	paper_code[index_1] = paper_code[index_2];
	paper_code[index_2] = t_string;

	t_string = prog_name[index_1];
	prog_name[index_1] = prog_name[index_2];
	prog_name[index_2] = t_string;

	t_string = prog_sem_year[index_1];
	prog_sem_year[index_1] = prog_sem_year[index_2];
	prog_sem_year[index_2] = t_string;

	t_string = declared_date[index_1];
	declared_date[index_1] = declared_date[index_2];
	declared_date[index_2] = t_string;

	t_string = institution_name[index_1];
	institution_name[index_1] = institution_name[index_2];
	institution_name[index_2] = t_string;

	t_string = subject_name[index_1];
	subject_name[index_1] = subject_name[index_2];
	subject_name[index_2] = t_string;

	t_string = type[index_1];
	type[index_1] = type[index_2];
	type[index_2] = t_string;

	t_string = exam[index_1];
	exam[index_1] = exam[index_2];
	exam[index_2] = t_string;

	t_string = mode[index_1];
	mode[index_1] = mode[index_2];
	mode[index_2] = t_string;

	t_string = kind[index_1];
	kind[index_1] = kind[index_2];
	kind[index_2] = t_string;

	t_string = minor[index_1];
	minor[index_1] = minor[index_2];
	minor[index_2] = t_string;

	t_string = major[index_1];
	major[index_1] = major[index_2];
	major[index_2] = t_string;

	t_string = max_marks[index_1];
	max_marks[index_1] = max_marks[index_2];
	max_marks[index_2] = t_string;

	t_string = pass_marks[index_1];
	pass_marks[index_1] = pass_marks[index_2];
	pass_marks[index_2] = t_string;	
}


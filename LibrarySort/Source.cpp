#include "Source.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>

int Source::init_num = 0;

void Source::readFile(const char* file_name)
{
	std::vector<unsigned char> buffer;
	char temp_var[128];
	char line[513];
	int index;
	int line_number;
	int category;

    for(index=0;index<128;index++)
        temp_var[index] = '\0';

	std::ifstream file(file_name,
	                   std::ios::binary | std::ios::in);
	if (file.fail())
	{
		perror("Error in opening line");
		perror(file_name);
		exit(2);
	}

	line_number = 0;

	while (file.getline(line, 512, '\n'))
	{
		category = 0;
		index = 0;
		for (char* buffer_iter = line;
		     *buffer_iter != '\0'; ++buffer_iter)
		{
			if (*buffer_iter == '\n')
			{
				line_number++;
				index = 0;
				continue;
			}

			if (line_number == 0)
			{
				if (*buffer_iter == ',' || *(buffer_iter + 1) == '\0')
				{
					if (*buffer_iter == ',')
						temp_var[index] = '\0';
					else
					{
						temp_var[index++] = *buffer_iter;
						temp_var[index] = '\0';
					}
					headers.push_back(std::string(temp_var));
					index = 0;
					continue;
				}
			}

			if (*buffer_iter == ',' || (*(buffer_iter + 1) == '\0' && line_number != 0))
			{
				if (*buffer_iter == ',')
					temp_var[index] = '\0';
				else
				{
					temp_var[index++] = *buffer_iter;
					temp_var[index] = '\0';
				}
                if(line_number>=rows)
                    break;
				switch (category)
				{
				case 0:
					scheme_prog_code[line_number - 1] = (atoi(temp_var));
					break;
				case 1:
					prog_name[line_number - 1] = std::string(temp_var);
					break;
				case 2:
					scheme_id[line_number - 1] = (atoi(temp_var));
					break;
				case 3:
					prog_sem_year[line_number - 1] = std::string(temp_var);
					break;
				case 4:
					prepared_date[line_number - 1] = std::string(temp_var);
					break;
				case 5:
					declared_date[line_number - 1] = std::string(temp_var);
					break;
				case 6:
					institution_code[line_number - 1] = (atoi(temp_var));
					break;
				case 7:
					institution_name[line_number - 1] = std::string(temp_var);
					break;
				case 8:
					s_number[line_number - 1] = (atoi(temp_var));
					break;
				case 9:
					paper_id[line_number - 1] = (atoi((temp_var)));
					break;
				case 10:
					paper_code[line_number - 1] = std::string(temp_var);
					break;
				case 11:
					subject_name[line_number - 1] = std::string(temp_var);
					break;
				case 12:
					credits[line_number - 1] = (atoi(temp_var));
					break;
				case 13:
					type[line_number - 1] = std::string(temp_var);
					break;
				case 14:
					exam[line_number - 1] = std::string(temp_var);
					break;
				case 15:
					mode[line_number - 1] = std::string(temp_var);
					break;
				case 16:
					kind[line_number - 1] = std::string(temp_var);
					break;
				case 17:
					minor[line_number - 1] = std::string(temp_var);
					break;
				case 18:
					major[line_number - 1] = std::string(temp_var);
					break;
				case 19:
					max_marks[line_number - 1] = std::string(temp_var);
					break;
				case 20:
					pass_marks[line_number - 1] = std::string(temp_var);
					break;
				default:
					break;
				}
				index = 0;
				++category;
				category %= 21;
			}
			else
			{
				temp_var[index++] = *buffer_iter;
			}
		}

		line_number++;
	}

	file.close();
}

bool Source::readFileToBuffer(std::string filePath,
                              std::vector<unsigned char>& buffer)
{
	std::ifstream file(filePath,
	                   std::ios::binary | std::ios::in);
	if (file.fail())
	{
		perror("Error in opening line");
		perror(filePath.c_str());
		return false;
	}

	size_t fileSize = file.tellg();
	file.seekg(0, std::ios::end);

	buffer.resize(fileSize);
	file.seekg(0, std::ios::beg);
	file.read((char *)&(buffer[0]), fileSize);
	file.close();

	return true;
}

void Source::print_table(const char* file_name)
{
	FILE* p_file;
	FILE* single_col_file;
	std::string sorted_file_name(file_name);
	int i_value;
	std::string s_value;

	sorted_file_name.replace(sorted_file_name.end() - 4,
	                         sorted_file_name.end(), "_sma_");

	sorted_file_name += std::to_string(init_num);

	fopen_stream(&p_file, file_name, "w");
	fopen_stream(&single_col_file, sorted_file_name.c_str(), "w");
	sorted_file_name += ".csv";

	std::vector<std::string>::iterator iter;
	for (iter = headers.begin();
	     iter != headers.end(); ++iter)
	{
		if (iter != headers.begin())
		printf_stream(p_file, ",");
		printf_stream(p_file,"%s",(*iter).c_str());
	}

	printf_stream(p_file,"\n");

	for (size_t i = 0; i < rows; i++)
	{
		printf_stream(p_file, "%d,%s,%d,%s,%s,%s,%d,%s,%d,%d,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
			scheme_prog_code[i], prog_name[i].c_str(), scheme_id[i], prog_sem_year[i].c_str(),
			prepared_date[i].c_str(), declared_date[i].c_str(), institution_code[i], institution_name[i].c_str(), s_number[i],
			paper_id[i], paper_code[i].c_str(), subject_name[i].c_str(), credits[i], type[i].c_str(), exam[i].c_str(), mode[i].c_str(), kind[i].c_str(), minor[i].c_str(), major[i].c_str(), max_marks[i].c_str(), pass_marks[i].c_str())

		;

		switch (sorted_col_type)
		{
		case inte:
			i_value = sorted_col_int[i];
			printf_stream(single_col_file, "%d\n", i_value);
			break;
		case string:
			s_value = sorted_col_string[i];
			printf_stream(single_col_file, "%s\n", s_value.c_str());
			break;
		}
	}

	fclose(p_file);
	fclose(single_col_file);
}

void Source::MemAllo()
{
	size_t colmns = 21;
	rows = 247694;

	headers.reserve(colmns);

	scheme_prog_code = new int [rows];
	scheme_id = new int[rows];
	institution_code = new int[rows];
	s_number = new int[rows];
	paper_id = new int[rows];
	credits = new int[rows];

	prog_name = new std::string[rows];
	prog_sem_year = new std::string[rows];
	prepared_date = new std::string[rows];
	declared_date = new std::string[rows];
	institution_name = new std::string[rows];
	paper_code = new std::string[rows];
	subject_name = new std::string[rows];
	type = new std::string[rows];
	exam = new std::string[rows];
	mode = new std::string[rows];
	kind = new std::string[rows];
	minor = new std::string[rows];
	major = new std::string[rows];
	max_marks = new std::string[rows];
	pass_marks = new std::string[rows];

	init_num++;
}

void Source::MemFree()
{
	headers.clear();

	delete [] (scheme_prog_code);
	delete [] (prog_name);
	delete [] (scheme_id);
	delete [] (prog_sem_year);
	delete [] (prepared_date);
	delete [] (declared_date);
	delete [] (institution_code);
	delete [] (institution_name);
	delete [] (s_number);
	delete [] (paper_id);
	delete [] (paper_code);
	delete [] (subject_name);
	delete [] (credits);
	delete [] (type);
	delete [] (exam);
	delete [] (mode);
	delete [] (kind);
	delete [] (minor);
	delete [] (major);
	delete [] (max_marks);
	delete [] (pass_marks);
}

void Source::sort(int column)
{
	if (column == 1)
	{
		quicksort(paper_id, 0, rows - 1);
		sorted_col_int = paper_id;
		sorted_col_type = inte;
	}
	if (column == 2)
	{
		quicksort(subject_name, 0, rows - 1);
		sorted_col_string = subject_name;
		sorted_col_type = string;
	}
	if (column == 3)
	{
		quicksort(institution_name, 0, rows - 1);
		sorted_col_string = institution_name;
		sorted_col_type = string;
	}
	if (column == 4)
	{
		shellsort(paper_id, 0, rows - 1);
		sorted_col_int = paper_id;
		sorted_col_type = inte;
	}
	if (column == 5)
	{
		shellsort(subject_name, 0, rows - 1);
		sorted_col_string = subject_name;
		sorted_col_type = string;
	}
	if (column == 6)
	{
		shellsort(institution_name, 0, rows - 1);
		sorted_col_string = institution_name;
		sorted_col_type = string;
	}
}


void Source::shellsort(std::string* toSort, size_t low, size_t high)
{
	size_t i, j;
	long long k;


	for (i = (high + 1) / 2; i > 0; i = i / 2)
		for (j = i; j < high; j++)
			for (k = j - i; k >= 0; k = k - i)
			{
				if (compare_isLess(toSort[k], toSort[k + i]))
					break;
				else
					swap(k, k + i);
			}
}

void Source::shellsort(int* toSort, size_t low, size_t high)
{
	size_t i, j;
	long long k;

	for (i = (high + 1) / 2; i > 0; i = i / 2)
		for (j = i; j < high; j++)
			for (k = j - i; k >= 0; k = k - i)
			{
				if (toSort[k] < toSort[k + i])
					break;
				else
					swap(k, k + i);
			}
}

void Source::quicksort(int* toSort, size_t low, size_t high)
{
	std::stack<size_t> mini_stack;

	mini_stack.push(low);
	mini_stack.push(high);

	while (mini_stack.size() > 0)
	{
		size_t low;
		size_t high;

		high = mini_stack.top();
		mini_stack.pop();
		low = mini_stack.top();
		mini_stack.pop();

		if (low < high)
		{
			size_t part_index = partition(toSort, low, high);

			if (low < part_index - 1 && part_index != 0)
			{
				mini_stack.push(low);
				mini_stack.push(part_index - 1);
			}

			if (part_index + 1 < high)
			{
				mini_stack.push(part_index + 1);
				mini_stack.push(high);
			}

		}
	}
}


void Source::quicksort(std::string* toSort, size_t low, size_t high)
{
	std::stack<size_t> mini_stack;

	mini_stack.push(low);
	mini_stack.push(high);

	while (mini_stack.size() > 0)
	{
		size_t low;
		size_t high;

		high = mini_stack.top();
		mini_stack.pop();
		low = mini_stack.top();
		mini_stack.pop();

		if (low < high)
		{
			size_t part_index = partition(toSort, low, high);

			if (low < part_index - 1 && part_index != 0)
			{
				mini_stack.push(low);
				mini_stack.push(part_index - 1);
			}

			if (part_index + 1 < high)
			{
				mini_stack.push(part_index + 1);
				mini_stack.push(high);
			}
		}
	}
}

size_t Source::partition(int* toSort, size_t low, size_t high)
{
	int pivot = toSort[high];

	size_t i = (low - 1);

	for (size_t j = low; j <= high - 1; j++)
	{
		if (toSort[j] <= pivot)
		{
			i++;
			if (i != j)
				swap(i, j);
		}
	}

	if (i + 1 != high)
		swap(i + 1, high);

	return (i + 1);
}

size_t Source::partition(std::string* toSort, size_t low, size_t high)
{
	std::string pivot = toSort[high];

	size_t i = (low - 1);

	for (size_t j = low; j <= high - 1; j++)
	{
		if (compare_isLess(toSort[j],pivot))
		{
			i++;
			if (i != j)
				swap(i, j);
		}
	}

	if (i + 1 != high)
		swap(i + 1, high);

	return (i + 1);
}


void Source::swap(const size_t index_1, const size_t index_2)
{
	int temp;

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

	std::string t_string;

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

bool Source::compare_isLess(std::string str1, std::string str2)
{
	size_t i;
	size_t min_i;
	i = 0;

	min_i = std::min(str1.length(), str2.length());

	while (i < min_i)
	{
		if (str1[i] < str2[i])
		{
			return true;
		}
		else if (str1[i] > str2[i])
		{
			return false;
		}
		++i;
	}

	if (str1.length() > str2.length())
		return true;

	return false;
}

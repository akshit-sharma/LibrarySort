#include "BiggerSource.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>


void BiggerSource::readFile(const char* file_name)
{

    std::vector<unsigned char> buffer;
    char temp_var[128];
    char line[513];
    int index;
    size_t line_number;
    int category;

    std::ifstream file(file_name,
        std::ios::binary | std::ios::in);

    if(file.fail())
    {
        perror("Error in opening line");
        perror(file_name);
        exit(2);
    }

    line_number = 0;

    while(file.getline(line, 512, '\n')){
        category = 0;
        index = 0;
        for(char * buffer_iter = line;
            *buffer_iter != '\0'; ++buffer_iter){
                if(*buffer_iter == '\n')
                {
                    line_number++;
                    index = 0;
                    continue;
                }

                if(line_number == 0)
                {
                    if(*buffer_iter == ',' || *(buffer_iter+1)=='\0')
                    {
                        if(*buffer_iter == ',')
                            temp_var[index] = '\0';
                        else{
                            temp_var[index++] = *buffer_iter;
                            temp_var[index] = '\0';
                        }
                        headers.push_back(temp_var);
                        index = 0;
                        continue;
                    }
                }

                if(*buffer_iter == ',' || (*(buffer_iter+1) == '\0' && line_number!=0)){
                    if(*buffer_iter == ',')
                        temp_var[index] = '\0';
                    else{
                        temp_var[index++] = *buffer_iter;
                        temp_var[index] = '\0';
                    }

                switch(category)
                    {
                    case 0: //scheme_prog_code
                        scheme_prog_code[line_number-1] = (atoi(temp_var));
                        break;
                    case 1: //prepared_date
						prepared_date[line_number - 1] = temp_var;
                        break;
                    case 2: //declared_date
						declared_date[line_number - 1] = temp_var;
                        break;
                    case 3: //prog_name
						prog_name[line_number - 1] = temp_var;
                        break;
                    case 4: //prog_sem_year
						prog_sem_year[line_number - 1] = temp_var;
                        break;
                    case 5: //batch
                        batch[line_number-1] = (atoi(temp_var));
                        break;
                    case 6: //examination
						examination[line_number - 1] = temp_var;
                        break;
                    case 7: //institution_code
                        institution_code[line_number-1] = (atoi(temp_var));
                        break;
                    case 8: //institution_name
						institution_name[line_number - 1] = temp_var;
                        break;
                    case 9: //rollnumber
                        rollnumber[line_number-1] = (atoll(temp_var));
                        break;
                    case 10: //name
						name[line_number - 1] = temp_var;
                        break;
                    case 11: //sid
                        sid[line_number-1] = (atoll(temp_var));
                        break;
                    case 12: //result_scheme_id
                        result_scheme_id[line_number-1] = (atoll(temp_var));
                        break;
                    case 13: //credits
						credits[line_number - 1] = temp_var;
                        break;
                    case 14: //minor
						minor[line_number - 1] = temp_var;
                        break;
                    case 15: //major
						major[line_number - 1] = temp_var;
                        break;
                    case 16: //total
						total[line_number - 1] = temp_var;
                        break;
                    default:
                        break;
                    }
                    index = 0;
                    ++category;
                    category %= 17;
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

bool BiggerSource::readFileToBuffer(std::string filePath,
    std::vector<unsigned char>& buffer)
{

    std::ifstream file(filePath,
        std::ios::binary | std::ios::in);
    if(file.fail())
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

void BiggerSource::print_table(const char * file_name)
{

    FILE * p_file;

    fopen_s(&p_file, file_name, "w");

    std::vector<std::string>::iterator iter;
    for(iter = headers.begin();
        iter != headers.end(); ++iter){
            if(iter != headers.begin())
                fprintf_s(p_file, ",");
            fprintf_s(p_file,"%s",(*iter).c_str());
    }

    fprintf_s(p_file,"\n");

    for(size_t i=0; i < rows; i++){
		fprintf_s(p_file, "%d,%s,%s,%s,%s,%d,%s,%d,%s,%lld,%s,%lld,%lld,%s,%s,%s,%s\n",
			scheme_prog_code[i], prepared_date[i].c_str(), declared_date[i].c_str(), prog_name[i].c_str(),
			prog_sem_year[i].c_str(), batch[i], examination[i].c_str(), institution_code[i], institution_name[i].c_str(),
			rollnumber[i], name[i].c_str(), sid[i], result_scheme_id[i], credits[i].c_str(), minor[i].c_str(),
			major[i].c_str(), total[i].c_str());
		//fprintf_s(p_file, "%s\n", name[i]);
    }

    fclose(p_file);

}

BiggerSource::BiggerSource()
{
    size_t colmns = 17;
    rows = 3024380;

    headers.reserve(colmns);

    scheme_prog_code = new int[rows];
    batch = new int[rows];
    institution_code = new int[rows];
    rollnumber = new long long[rows];
    sid = new long long[rows];
    result_scheme_id = new long long[rows];

    prepared_date = new std::string[rows];
    declared_date = new std::string[rows];
    prog_name = new std::string[rows];
    prog_sem_year = new std::string[rows];
    examination = new std::string[rows];
    institution_name = new std::string[rows];
    name = new std::string[rows];
    credits = new std::string[rows];
    minor = new std::string[rows];
    major = new std::string[rows];
    total = new std::string[rows];

}

BiggerSource::~BiggerSource()
{

    headers.clear();

    delete [] scheme_prog_code;
    delete [] batch;
    delete [] institution_code;
    delete [] rollnumber;
    delete [] sid;
    delete [] result_scheme_id;

    delete [] prepared_date;
    delete [] declared_date;
    delete [] prog_name;
    delete [] prog_sem_year;
    delete [] examination;
    delete [] institution_name;
    delete [] name;
    delete [] credits;
    delete [] minor;
    delete [] major;
    delete [] total;

}

void BiggerSource::sort(int column)
{
	quicksort(name, 0, rows - 1);
}

void BiggerSource::quicksort(std::string * toSort, size_t low, size_t high)
{
	
	size_t part;
	std::stack<size_t> mini_stack;

	mini_stack.push(low);
	mini_stack.push(high);

	while (mini_stack.size() > 0) {
		size_t low;
		size_t high;

		high = mini_stack.top();
		mini_stack.pop();
		low = mini_stack.top();
		mini_stack.pop();

		if (low < high)
		{
			part = partition(toSort, low, high);

//			quicksort(toSort, low, part - 1);
//			quicksort(toSort, part + 1, high);

			mini_stack.push(part + 1);
			mini_stack.push(high);
			mini_stack.push(low);
			mini_stack.push(part - 1);

		}
	}
}

size_t BiggerSource::partition(std::string* toSort, size_t low, size_t high)
{
	std::string pivot = toSort[high];

	size_t i = low;

	for (size_t j = low + 1; j <= high - 1; j++)
	{
		if(compare_isLess(toSort[j],pivot))
		{
			i++;
			if(i!=j)
				swap(i, j);
		}
	}
	swap(i+1, high);
	return (i+1);
}

void BiggerSource::swap(size_t index_1, size_t index_2)
{
    int temp_int;
    long long temp_long;
	std::string t_string;

    temp_int = scheme_prog_code[index_1];
    scheme_prog_code[index_1] = scheme_prog_code[index_2];
    scheme_prog_code[index_2] = temp_int;

	t_string = prepared_date[index_1];
	prepared_date[index_1] = prepared_date[index_2];
	prepared_date[index_2] = t_string;


	t_string = declared_date[index_1];
	declared_date[index_1] = declared_date[index_2];
	declared_date[index_2] = t_string;
    

	t_string = prog_name[index_1];
	prog_name[index_1] = prog_name[index_2];
	prog_name[index_2] = t_string;
    

	t_string = prog_sem_year[index_1];
	prog_sem_year[index_1] = prog_sem_year[index_2];
	prog_sem_year[index_2] = t_string;

    temp_int = batch[index_1];
    batch[index_1] = batch[index_2];
    batch[index_2] = temp_int;

	t_string = examination[index_1];
	examination[index_1] = examination[index_2];
	examination[index_2] = t_string;

    temp_int = institution_code[index_1];
    institution_code[index_1] = institution_code[index_2];
    institution_code[index_2] = temp_int;

	t_string = institution_name[index_1];
	institution_name[index_1] = institution_name[index_2];
	institution_name[index_2] = t_string;

    temp_long = rollnumber[index_1];
    rollnumber[index_1] = rollnumber[index_2];
    rollnumber[index_2]  = temp_long;

	t_string = name[index_1];
	name[index_1] = name[index_2];
	name[index_2] = t_string;

    temp_long = sid[index_1];
    sid[index_1] = sid[index_2];
    sid[index_2] = temp_long;

    temp_long = result_scheme_id[index_1];
    result_scheme_id[index_1] = result_scheme_id[index_2];
    result_scheme_id[index_2] = temp_long;

	t_string = credits[index_1];
	credits[index_1] = credits[index_2];
	credits[index_2] = t_string;

	t_string = minor[index_1];
	minor[index_1] = minor[index_2];
	minor[index_2] = t_string;

	t_string = major[index_1];
	major[index_1] = major[index_2];
	major[index_2] = t_string;

	t_string = total[index_1];
	total[index_1] = total[index_2];
	total[index_2] = t_string;

}

bool BiggerSource::compare_isLess(std::string str1, std::string str2)
{
	size_t i;
	size_t min_i;
	i = 0;

	min_i = std::min(str1.length(), str2.length());

	while(i<min_i)
	{
		if(str1[i]<str2[i])
		{
			return true;
		}
		else if (str1[i]>str2[i])
		{
			return false;
		}
		++i;
	}

	if (str1.length() > str2.length())
		return true;

	return false;

}

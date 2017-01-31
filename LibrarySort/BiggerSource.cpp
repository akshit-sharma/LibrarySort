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
						prepared_date[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(prepared_date[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 2: //declared_date
						declared_date[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(declared_date[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 3: //prog_name
						prog_name[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(prog_name[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 4: //prog_sem_year
						prog_sem_year[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(prog_sem_year[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 5: //batch
                        batch[line_number-1] = (atoi(temp_var));
                        break;
                    case 6: //examination
						examination[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(examination[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 7: //institution_code
                        institution_code[line_number-1] = (atoi(temp_var));
                        break;
                    case 8: //institution_name
						institution_name[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(institution_name[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 9: //rollnumber
                        rollnumber[line_number-1] = (atoll(temp_var));
                        break;
                    case 10: //name
						name[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(name[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 11: //sid
                        sid[line_number-1] = (atoll(temp_var));
                        break;
                    case 12: //result_scheme_id
                        result_scheme_id[line_number-1] = (atoll(temp_var));
                        break;
                    case 13: //credits
						credits[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(credits[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 14: //minor
						minor[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(minor[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 15: //major
						major[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(major[line_number - 1], strlen(temp_var) + 1, temp_var);
                        break;
                    case 16: //total
						total[line_number - 1] = new char [strlen(temp_var)+1];
                        strcpy_s(total[line_number - 1], strlen(temp_var) + 1, temp_var);
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
            scheme_prog_code[i], prepared_date[i], declared_date[i], prog_name[i], 
            prog_sem_year[i], batch[i], examination[i], institution_code[i], institution_name[i],
            rollnumber[i], name[i], sid[i], result_scheme_id[i], credits[i], minor[i],
            major[i], total[i]);
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

    prepared_date = new char*[rows];
    declared_date = new char*[rows];
    prog_name = new char*[rows];
    prog_sem_year = new char*[rows];
    examination = new char*[rows];
    institution_name = new char*[rows];
    name = new char*[rows];
    credits = new char*[rows];
    minor = new char*[rows];
    major = new char*[rows];
    total = new char*[rows];

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

    for(size_t i = 0; i<rows; i++)
        delete [] prepared_date[i];
    delete [] prepared_date;
    for(size_t i = 0; i<rows; i++)
        delete [] declared_date[i];
    delete [] declared_date;
    for(size_t i = 0; i<rows; i++)
        delete [] prog_name[i];
    delete [] prog_name;
    for(size_t i = 0; i<rows; i++)
        delete [] prog_sem_year[i];
    delete [] prog_sem_year;
    for(size_t i = 0; i<rows; i++)
        delete [] examination[i];
    delete [] examination;
    for(size_t i = 0; i<rows; i++)
        delete [] institution_name[i];
    delete [] institution_name;
    for(size_t i = 0; i<rows; i++)
        delete [] name[i];
    delete [] name;
    for(size_t i = 0; i<rows; i++)
        delete [] credits[i];
    delete [] credits;
    for(size_t i = 0; i<rows; i++)
        delete [] minor[i];
    delete [] minor;
    for(size_t i = 0; i<rows; i++)
        delete [] major[i];
    delete [] major;
    for(size_t i = 0; i<rows; i++)
        delete [] total[i];
    delete [] total;

}

void BiggerSource::sort(int column)
{
	quicksort(rollnumber, 0, rows - 1);
}

void BiggerSource::quicksort(long long* toSort, size_t low, size_t high)
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

size_t BiggerSource::partition(long long* toSort, size_t low, size_t high)
{
	long long pivot = toSort[high];

	size_t i = low;

	for (size_t j = low + 1; j <= high - 1; j++)
	{
		if(toSort[j] <= pivot)
		{
			i++;
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

    temp_int = scheme_prog_code[index_1];
    scheme_prog_code[index_1] = scheme_prog_code[index_2];
    scheme_prog_code[index_2] = temp_int;

    swapper(prepared_date[index_1],prepared_date[index_2]);

    swapper(declared_date[index_1],declared_date[index_2]);
    
    swapper(prog_name[index_1],prog_name[index_2]);
    
    swapper(prog_sem_year[index_1],prog_sem_year[index_2]);

    temp_int = batch[index_1];
    batch[index_1] = batch[index_2];
    batch[index_2] = temp_int;

    swapper(examination[index_1],examination[index_2]);

    temp_int = institution_code[index_1];
    institution_code[index_1] = institution_code[index_2];
    institution_code[index_2] = temp_int;

    swapper(institution_name[index_1],institution_name[index_2]);

    temp_long = rollnumber[index_1];
    rollnumber[index_1] = rollnumber[index_2];
    rollnumber[index_2]  = temp_long;

    swapper(name[index_1],name[index_2]);

    temp_long = sid[index_1];
    sid[index_1] = sid[index_2];
    sid[index_2] = temp_long;

    temp_long = result_scheme_id[index_1];
    result_scheme_id[index_1] = result_scheme_id[index_2];
    result_scheme_id[index_2] = temp_long;

    swapper(credits[index_1],credits[index_2]);
    
    swapper(minor[index_1],minor[index_2]);
    
    swapper(major[index_1],major[index_2]);
    
    swapper(total[index_1],total[index_2]);

}

void BiggerSource::swapper( char* str1, char* str2)
{
	char *temp;
	temp = str1;
    str1 = str2;
    str2=temp;
}
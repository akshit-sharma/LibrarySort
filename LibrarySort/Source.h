
#include <vector>

#pragma once
class Source
{
private:

	std::vector <std::string> headers;

	std::vector <int> scheme_prog_code;
	std::vector <std::string> prog_name;
	std::vector <int> scheme_id;
	std::vector <std::string> prog_sem_year;
	std::vector <std::string> prepared_date;
	std::vector <std::string> declared_date;
	std::vector <int> institution_code;
	std::vector <std::string> institution_name;
	std::vector <int> s_number;
	std::vector <int> paper_id;
	std::vector <std::string> paper_code;
	std::vector <std::string> subject_name;
	std::vector <int> credits;
	std::vector <std::string> type;
	std::vector <std::string> exam;
	std::vector <std::string> mode;
	std::vector <std::string> kind;
	std::vector <std::string> minor;
	std::vector <std::string> major;
	std::vector <std::string> max_marks;
	std::vector <std::string> pass_marks;


	bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
	
public:
	Source();
	void readFile(const char * file_name);
	void print_table();
	~Source();
};


#include "SchemeDataStructure.h"
#include "GlobalHeader.h"

void SchemeDataStructure::MemAllo(){

    index = 0;

    this->scheme_prog_code = new int[MAX_SIZE];
    this->prog_name = new std::string[MAX_SIZE];
    this->scheme_id = new long long[MAX_SIZE];
    this->prog_sem_year = new std::string[MAX_SIZE];
    this->prepared_date = new std::string[MAX_SIZE];
    this->declared_date = new std::string[MAX_SIZE];
    this->institution_code = new int[MAX_SIZE];
    this->institution_name = new std::string[MAX_SIZE];
    this->s_number = new int[MAX_SIZE];
    this->paper_id = new int[MAX_SIZE];
    this->paper_code = new std::string[MAX_SIZE];
    this->subject_name = new std::string[MAX_SIZE];
    this->credits = new int[MAX_SIZE];
    this->type = new std::string[MAX_SIZE];
    this->exam = new std::string[MAX_SIZE];
    this->mode = new std::string[MAX_SIZE];
    this->kind = new std::string[MAX_SIZE];
    this->minor = new std::string[MAX_SIZE];
    this->major = new std::string[MAX_SIZE];
    this->max_marks = new std::string[MAX_SIZE];
    this->pass_marks = new std::string[MAX_SIZE];

}

void SchemeDataStructure::MemFree(){

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


void SchemeDataStructure::swap(size_t index_1, size_t index_2)
{
	int temp;
    long long t_long;
	std::string t_string;

	temp = paper_id[index_1];
	paper_id[index_1] = paper_id[index_2];
	paper_id[index_2] = temp;

    if(this->paper_id[index_1]<10){
        printf_stream(stderr, "Not good");
    }
    if(this->paper_id[index_2]<10){
        printf_stream(stderr, "Not good");
    }

	temp = scheme_prog_code[index_1];
	scheme_prog_code[index_1] = scheme_prog_code[index_2];
	scheme_prog_code[index_2] = temp;

    t_string = prog_name[index_1];
    prog_name[index_1] = prog_name[index_2];
    prog_name[index_2] = t_string;

    t_long = scheme_id[index_1];
    scheme_id[index_1] = scheme_id[index_2];
    scheme_id[index_2] = t_long;

	t_string = prog_sem_year[index_1];
	prog_sem_year[index_1] = prog_sem_year[index_2];
	prog_sem_year[index_2] = t_string;

	t_string = declared_date[index_1];
	declared_date[index_1] = declared_date[index_2];
	declared_date[index_2] = t_string;

    temp = institution_code[index_1];
    institution_code[index_1] = institution_code[index_2];
    institution_code[index_2] = temp;

	t_string = institution_name[index_1];
	institution_name[index_1] = institution_name[index_2];
	institution_name[index_2] = t_string;

    temp = s_number[index_1];
    s_number[index_1] = s_number[index_2];
    s_number[index_2] = temp;

    t_string = paper_code[index_1];
    paper_code[index_1] = paper_code[index_2];
    paper_code[index_2] = t_string;

	t_string = subject_name[index_1];
	subject_name[index_1] = subject_name[index_2];
	subject_name[index_2] = t_string;

    temp = credits[index_1];
    credits[index_1] = credits[index_2];
    credits[index_2] = temp;

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

void SchemeDataStructure::modifySDS(
        int scheme_prog_code, std::string prog_name, long long scheme_id, std::string prog_sem_year,
        std::string prepared_date, std::string declared_date, int institution_code,
        std::string institution_name,	int s_number,	int paper_id,	std::string paper_code,
        std::string subject_name,	int credits, std::string type, std::string exam, std::string mode,
        std::string kind,	std::string minor, std::string major, std::string max_marks, std::string pass_marks)
{

    this->scheme_prog_code[index] = scheme_prog_code;
    this->prog_name[index] = std::string(prog_name);
    this->scheme_id[index] = scheme_id;
    this->prog_sem_year[index] = std::string(prog_sem_year);
    this->prepared_date[index] = std::string(prepared_date);
    this->declared_date[index] = std::string(declared_date);
    this->institution_code[index] = institution_code;
    this->institution_name[index] = std::string(institution_name);
    this->s_number[index] = s_number;
    this->paper_id[index] = paper_id;
    this->paper_code[index] = std::string(paper_code);
    this->subject_name[index] = std::string(subject_name);
    this->credits[index] = credits;
    this->type[index] = std::string(type);
    this->exam[index] = std::string(exam);
    this->mode[index] = std::string(mode);
    this->kind[index] = std::string(kind);
    this->minor[index] = std::string(minor);
    this->major[index] = std::string(major);
    this->max_marks[index] = std::string(max_marks);
    this->pass_marks[index] = std::string(pass_marks);

    if(this->paper_id[index]<10){
        printf_stream(stderr, "Not good");
    }

    index++;

}


void SchemeDataStructure::modifySDS(size_t index,
        int scheme_prog_code, std::string prog_name, long long scheme_id, std::string prog_sem_year,
        std::string prepared_date, std::string declared_date, int institution_code,
        std::string institution_name,	int s_number,	int paper_id,	std::string paper_code,
        std::string subject_name,	int credits, std::string type, std::string exam, std::string mode,
        std::string kind,	std::string minor, std::string major, std::string max_marks, std::string pass_marks)
{

    this->scheme_prog_code[index] = scheme_prog_code;
    this->prog_name[index] = std::string(prog_name);
    this->scheme_id[index] = scheme_id;
    this->prog_sem_year[index] = std::string(prog_sem_year);
    this->prepared_date[index] = std::string(prepared_date);
    this->declared_date[index] = std::string(declared_date);
    this->institution_code[index] = institution_code;
    this->institution_name[index] = std::string(institution_name);
    this->s_number[index] = s_number;
    this->paper_id[index] = paper_id;
    this->paper_code[index] = std::string(paper_code);
    this->subject_name[index] = std::string(subject_name);
    this->credits[index] = credits;
    this->type[index] = std::string(type);
    this->exam[index] = std::string(exam);
    this->mode[index] = std::string(mode);
    this->kind[index] = std::string(kind);
    this->minor[index] = std::string(minor);
    this->major[index] = std::string(major);
    this->max_marks[index] = std::string(max_marks);
    this->pass_marks[index] = std::string(pass_marks);

}

void SchemeDataStructure::getValue(struct SchemeDSHolder * schemeDSHolder,
              size_t index)
{

    if(this->paper_id[index]<10){
        printf_stream(stderr, "Not good");
    }

    schemeDSHolder->scheme_prog_code = this->scheme_prog_code[index];
    schemeDSHolder->prog_name = this->prog_name[index];
    schemeDSHolder->scheme_id = this->scheme_id[index];
    schemeDSHolder->prog_sem_year = this->prog_sem_year[index];
    schemeDSHolder->prepared_date = this->prepared_date[index];
    schemeDSHolder->declared_date = this->declared_date[index];
    schemeDSHolder->institution_code = this->institution_code[index];
    schemeDSHolder->institution_name = this->institution_name[index];
    schemeDSHolder->s_number = this->s_number[index];
    schemeDSHolder->paper_id = this->paper_id[index];
    schemeDSHolder->paper_code = this->paper_code[index];
    schemeDSHolder->subject_name = this->subject_name[index];
    schemeDSHolder->credits = this->credits[index];
    schemeDSHolder->type = this->type[index];
    schemeDSHolder->exam = this->exam[index];
    schemeDSHolder->mode = this->mode[index];
    schemeDSHolder->kind = this->kind[index];
    schemeDSHolder->minor = this->minor[index];
    schemeDSHolder->major = this->major[index];
    schemeDSHolder->max_marks = this->max_marks[index];
    schemeDSHolder->pass_marks = this->pass_marks[index];

}
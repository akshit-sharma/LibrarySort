#include "SchemeDataStructure.h"
#include "GlobalHeader.h"

void SchemeDataStructure::swap(SchemeDataStructure * scheme_1, SchemeDataStructure * scheme_2){

    int t_int;
    long long t_long;
    std::string t_string;

    SWAP(t_int, scheme_1, scheme_2, scheme_prog_code);
    SWAP(t_string, scheme_1, scheme_2, prog_name);
    SWAP(t_long, scheme_1, scheme_2, scheme_id);
    SWAP(t_string, scheme_1, scheme_2, prog_sem_year);
    SWAP(t_string, scheme_1, scheme_2, prepared_date);
    SWAP(t_string, scheme_1, scheme_2, declared_date);
    SWAP(t_int, scheme_1, scheme_2, institution_code);
    SWAP(t_string, scheme_1, scheme_2, institution_name);
    SWAP(t_int, scheme_1, scheme_2, s_number);
    SWAP(t_int, scheme_1, scheme_2, paper_id);
    SWAP(t_string, scheme_1, scheme_2, paper_code);
    SWAP(t_string, scheme_1, scheme_2, subject_name);
    SWAP(t_int, scheme_1, scheme_2, credits);
    SWAP(t_string, scheme_1, scheme_2, type);
    SWAP(t_string, scheme_1, scheme_2, exam);
    SWAP(t_string, scheme_1, scheme_2, mode);
    SWAP(t_string, scheme_1, scheme_2, kind);
    SWAP(t_string, scheme_1, scheme_2, minor);
    SWAP(t_string, scheme_1, scheme_2, major);
    SWAP(t_string, scheme_1, scheme_2, max_marks);
    SWAP(t_string, scheme_1, scheme_2, pass_marks);

}

void SchemeDataStructure::modifySDS(
        int scheme_prog_code, std::string prog_name, long long scheme_id, std::string prog_sem_year,
        std::string prepared_date, std::string declared_date, int institution_code,
        std::string institution_name,	int s_number,	int paper_id,	std::string paper_code,
        std::string subject_name,	int credits, std::string type, std::string exam, std::string mode,
        std::string kind,	std::string minor, std::string major, std::string max_marks, std::string pass_marks)
{

    this->scheme_prog_code = scheme_prog_code;
    this->prog_name = std::string(prog_name);
    this->scheme_id = scheme_id;
    this->prog_sem_year = std::string(prog_sem_year);
    this->prepared_date = std::string(prepared_date);
    this->declared_date = std::string(declared_date);
    this->institution_code = institution_code;
    this->institution_name = std::string(institution_name);
    this->s_number = s_number;
    this->paper_id = paper_id;
    this->paper_code = std::string(paper_code);
    this->subject_name = std::string(subject_name);
    this->credits = credits;
    this->type = std::string(type);
    this->exam = std::string(exam);
    this->mode = std::string(mode);
    this->kind = std::string(kind);
    this->minor = std::string(minor);
    this->major = std::string(major);
    this->max_marks = std::string(max_marks);
    this->pass_marks = std::string(pass_marks);

}

void SchemeDataStructure::getValue(struct SchemeDSHolder * schemeDSHolder)
{

    schemeDSHolder->scheme_prog_code = this->scheme_prog_code;
    schemeDSHolder->prog_name = this->prog_name;
    schemeDSHolder->scheme_id = this->scheme_id;
    schemeDSHolder->prog_sem_year = this->prog_sem_year;
    schemeDSHolder->prepared_date = this->prepared_date;
    schemeDSHolder->declared_date = this->declared_date;
    schemeDSHolder->institution_code = this->institution_code;
    schemeDSHolder->institution_name = this->institution_name;
    schemeDSHolder->s_number = this->s_number;
    schemeDSHolder->paper_id = this->paper_id;
    schemeDSHolder->paper_code = this->paper_code;
    schemeDSHolder->subject_name = this->subject_name;
    schemeDSHolder->credits = this->credits;
    schemeDSHolder->type = this->type;
    schemeDSHolder->exam = this->exam;
    schemeDSHolder->mode = this->mode;
    schemeDSHolder->kind = this->kind;
    schemeDSHolder->minor = this->minor;
    schemeDSHolder->major = this->major;
    schemeDSHolder->max_marks = this->max_marks;
    schemeDSHolder->pass_marks = this->pass_marks;

}
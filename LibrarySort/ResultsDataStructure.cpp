//
// Created by akshit on 7/3/17.
//

#include "ResultsDataStructure.h"

void ResultsDataStructure::swap(ResultsDataStructure * result_1, ResultsDataStructure * result_2)
{
    int t_int;
    long long t_long;
    std::string t_string;

    SWAP(t_int, result_1, result_2, scheme_prog_code);
    SWAP(t_string, result_1, result_2, prepared_date);
    SWAP(t_string, result_1, result_2, declared_date);
    SWAP(t_string, result_1, result_2, prog_name);
    SWAP(t_string, result_1, result_2, prog_sem_year);
    SWAP(t_int, result_1, result_2, batch);
    SWAP(t_string, result_1, result_2, examination);
    SWAP(t_int, result_1, result_2, institution_code);
    SWAP(t_string, result_1, result_2, institution_name);
    SWAP(t_long, result_1, result_2, rollnumber);
    SWAP(t_string, result_1, result_2, name);
    SWAP(t_long, result_1, result_2, sid);
    SWAP(t_long, result_1, result_2, result_scheme_id);
    SWAP(t_long, result_1, result_2, paper_id);
    SWAP(t_string, result_1, result_2, credits);
    SWAP(t_string, result_1, result_2, minor);
    SWAP(t_string, result_1, result_2, major);
    SWAP(t_string, result_1, result_2, total);
}

void ResultsDataStructure::modifyRDS(
        int scheme_prog_code, std::string prepared_date, std::string declared_date,
        std::string prog_name, std::string prog_sem_year, int batch,
        std::string examination, int institution_code, std::string institution_name,
        long long rollnumber, std::string name, long long sid, long long result_scheme_id,
        int paper_id, std::string credits, std::string minor, std::string major,
        std::string total)
{

    this->scheme_prog_code = scheme_prog_code;
    this->prepared_date = prepared_date;
    this->declared_date = declared_date;
    this->prog_name = prog_name;
    this->prog_sem_year = prog_sem_year;
    this->batch = batch;
    this->examination = examination;
    this->institution_code = institution_code;
    this->institution_name = institution_name;
    this->rollnumber = rollnumber;
    this->name = name;
    this->sid = sid;
    this->result_scheme_id = result_scheme_id;
    this->paper_id = paper_id;
    this->credits = credits;
    this->minor = minor;
    this->major = major;
    this->total = total;

}

void ResultsDataStructure::getValue(struct ResultsDSHolder * resultsDSHolder)
{

      resultsDSHolder->scheme_prog_code = this->scheme_prog_code;
      resultsDSHolder->prepared_date = this->prepared_date;
      resultsDSHolder->declared_date = this->declared_date;
      resultsDSHolder->prog_name = this->prog_name;
      resultsDSHolder->prog_sem_year = this->prog_sem_year;
      resultsDSHolder->batch = this->batch;
      resultsDSHolder->examination = this->examination;
      resultsDSHolder->institution_code = this->institution_code;
      resultsDSHolder->institution_name = this->institution_name;
      resultsDSHolder->rollnumber = this->rollnumber;
      resultsDSHolder->name = this->name;
      resultsDSHolder->sid = this->sid;
      resultsDSHolder->result_scheme_id = this->result_scheme_id;
      resultsDSHolder->paper_id = this->paper_id;
      resultsDSHolder->credits = this->credits;
      resultsDSHolder->minor = this->minor;
      resultsDSHolder->major = this->major;
      resultsDSHolder->total = this->total;

}

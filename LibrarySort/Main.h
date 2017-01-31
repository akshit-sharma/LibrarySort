#pragma once
class main_class
{
public:
	virtual void readFile(const char * file_name) = 0;
	virtual void sort(int column) = 0;
	virtual void print_table(const char * file_name) = 0;
};
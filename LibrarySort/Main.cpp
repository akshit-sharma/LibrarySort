

#include <fstream>
#include <iomanip>
#include <string>

#include <stdio.h>

#include "Main.h"
#include "BiggerSource.h"
#include "Source.h"

Source source;
BiggerSource bigsource;

double small_times, big_times;
double avg_read_times_small, avg_read_times_big;
double quicksort_small, quicksort_big;
double avg_write_times_small, avg_write_times_big;

const char * file_name_small;
const char * file_name_big;
const char * output_file_name;

void runSort(main_class * source_obj, int value, double * timeTaken)
{

	std::clock_t start;
	double duration;

	start = std::clock();
	source_obj->MemAllo();
	if(value % 2 == 0)
		source_obj->readFile(file_name_small);
	else
		source_obj->readFile(file_name_big);
	duration = (std::clock() - start) / static_cast<double> CLOCKS_PER_SEC;
	if (value % 2 == 0)
		avg_read_times_small += duration;
	else
		avg_read_times_big += duration;

	start = std::clock();
	source_obj->sort(value/2);
	duration = (std::clock() - start) / static_cast<double> CLOCKS_PER_SEC;
	quicksort_small = duration;

	start = std::clock();
	source_obj->print_table(output_file_name);
	source_obj->MemFree();
	duration = (std::clock() - start) / static_cast<double> CLOCKS_PER_SEC;
	if (value % 2 == 0)
		avg_write_times_small += duration;
	else
		avg_write_times_big += duration;
	 
	if (value % 2 == 0)
		small_times++;
	else
		big_times++;

	*timeTaken = quicksort_small;

}

int main(int argc, char ** argv)
{
	clock_t start;
	double duration;

	if (argc != 4)
	{
		perror("Invalid parameter given");
		perror("Found parameter : "+argc);
		perror("argv[1], argv[2] & argv[3] not supplied");
		perror("argv[1] & argv[2] is the path of input file");
		perror("argv[3] is the path of output file");
		exit(1);
	}

	file_name_small = argv[1];
	file_name_big = argv[2];
	output_file_name = argv[3];

	avg_read_times_big = 0;
	avg_read_times_small = 0;
	avg_write_times_big = 0;
	avg_write_times_small = 0;

	small_times = 0;
	big_times = 0;


	fprintf_s(stdout, " %10s | %10s | %10s | %10s | %10s \n",
		"technique", "colSmData", "timeTaken", "colBiData", "timeTaken"
			);



	main_class * source_obj = &source;
	main_class * big_source_obj = &bigsource;

	double * sort_small;
	double * sort_big;

	double f1, f2;

	f1 = 0;
	f2 = 0;

	sort_small = &f1;
	sort_big = &f2;

	runSort(source_obj, 2, sort_small);
	runSort(big_source_obj, 3, sort_big);

	fprintf_s(stdout, " %10s | %10s | %5.5lf | %10s | %5.5lf \n",
		"quicksort", "paper_id", *sort_small, "paper_id", *sort_big
	);

	runSort(source_obj, 4, sort_small);
	runSort(big_source_obj, 5, sort_big);

	fprintf_s(stdout, " %10s | %10s | %5.5lf | %10s | %5.5lf \n",
		"quicksort", "subjName", *sort_small, "name", *sort_big
	);

	runSort(source_obj, 6, sort_small);
	runSort(big_source_obj, 7, sort_big);

	fprintf_s(stdout, " %10s | %10s | %5.5lf | %10s | %5.5lf \n",
		"quicksort", "InstiName", *sort_small, "rollnum.", *sort_big
	);

	runSort(source_obj, 8, sort_small);
	runSort(big_source_obj, 9, sort_big);

	fprintf_s(stdout, " %10s | %10s | %5.5lf | %10s | %5.5lf \n",
		"shellsort", "paper_id", *sort_small, "paper_id", *sort_big
	);

	runSort(source_obj, 10, sort_small);
	runSort(big_source_obj, 11, sort_big);

	fprintf_s(stdout, " %10s | %10s | %5.5lf | %10s | %5.5lf \n",
		"shellsort", "subjName", *sort_small, "name", *sort_big
	);

	runSort(source_obj, 12, sort_small);
	runSort(big_source_obj, 13, sort_big);

	fprintf_s(stdout, " %10s | %10s | %5.5lf | %10s | %5.5lf \n",
		"shellsort", "InstiName", *sort_small, "rollnum.", *sort_big
	);

	fprintf_s(stdout, "\n");

	fprintf_s(stdout, "Avg small file read time %lf\n", (avg_read_times_small / small_times));
	fprintf_s(stdout, "Avg big file read time %lf\n", (avg_read_times_big / big_times));
	fprintf_s(stdout, "Avg small file write time %lf\n", (avg_write_times_small / small_times));
	fprintf_s(stdout, "Avg big file write time %lf\n", (avg_write_times_big / big_times));

	fprintf_s(stdout, "\n");
	fprintf_s(stdout, "\n");

	return 0;

}




#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "Source.h"

int main(int argc, char ** argv)
{

	std::clock_t start;
	double duration;

	if (argc != 3)
	{
		perror("Invalid parameter given");
		perror("argv[1] & argv[2] not supplied");
		perror("argv[1] is the path of input file");
		perror("argv[2] is the path of output file");
		exit(1);
	}

	const char * file_name = argv[1];
	const char * output_file_name = argv[2];

	start = std::clock();

	Source source;
	source.readFile(file_name);

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fprintf_s(stdout, "Time to read : %lf sec \n", duration);


	start = std::clock();

	source.sort(10);

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fprintf_s(stdout, "Time to sort : %lf sec \n", duration);



	start = std::clock();

	source.print_table(output_file_name);

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	fprintf_s(stdout, "Time to print : %lf sec \n", duration);

	fprintf_s(stdout, "\n");

	return 0;

}


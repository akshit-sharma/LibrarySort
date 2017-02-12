#pragma once

#define printf_stream(stream,fixed_string,...)\
		fprintf_s(stream,fixed_string,##__VA_ARGS__)

#include "memallocator.h"


int main(void)
{
	FILE* f1 = fopen("my_allocator.txt", "w");
	size_t size = (max_size + memgetblocksize()) * unm_of_iterations;  //总空间
	LARGE_INTEGER t1, t2, freq;
	double time;
	double* results = (double*)malloc(unm_of_iterations * sizeof(double));
	char** pointers = (char**)malloc(unm_of_iterations * sizeof(char*));
	void* mem = malloc(size);

	meminit(mem, size);
	QueryPerformanceFrequency(&freq);

	for (int i = 0; i < unm_of_iterations; i++)
	{
		QueryPerformanceCounter(&t1);
		for (int k = 0; k < i; k++)
		{
			pointers[k] = (char*)memalloc((int)rand() % max_size);
		}

		for (int k = 0; k < i; k++)
		{
			memfree(pointers[k]);
		}

		QueryPerformanceCounter(&t2);
		time = (float)(t2.QuadPart - t1.QuadPart) / freq.QuadPart;
		results[i] = time;
	}

	for (int i = 0; i < unm_of_iterations; i++)
	{
		fprintf(f1, "%lf ", results[i]);
	}

	fclose(f1);
	
	f1 = fopen("sys_allocator.txt", "w");
	for (int i = 0; i < unm_of_iterations; i++)
	{
		QueryPerformanceCounter(&t1);
		for (int k = 0; k < i; k++)
		{
			pointers[k] = (char*)malloc((int)rand() % max_size);
		}

		for (int k = 0; k < i; k++)
		{
			free(pointers[k]);
		}

		QueryPerformanceCounter(&t2);
		time = (float)(t2.QuadPart - t1.QuadPart) / freq.QuadPart;
		results[i] = time;
	}

	for (int i = 0; i < unm_of_iterations; i++)
	{
		fprintf(f1, "%lf ", results[i]);
	}

	fclose(f1);

	free(results);
	free(pointers);
	free(mem);

	return 0;
}

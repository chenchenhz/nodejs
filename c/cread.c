#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(int argc,char** argv)
{
  if(argc<2)
    {
      printf("too few args");
      return 2;
    }

  int size = atoi(argv[1]);
  int max = size*size;
  FILE *ptr_file;
  char *data=malloc(sizeof(char)*max);
  assert(data>0);
  char *out=malloc(sizeof(char)*max);
  assert(out>0);
  int ops=0;

  ptr_file=fopen("test.bin","rb");
  if(!ptr_file)
    {
      printf("unable to read file");
      return 1;
    }
  fread(data,sizeof(char),max,ptr_file);
  fclose(ptr_file);


  clock_t t;
  t = clock();
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      {
	int index=i*size+j;
	int sum=data[index];
	int cnt=1;
	ops++;
	if(i-1>=0)
	  {
	    cnt++;
	    sum+=data[(i-1)*size+j];
	  }
	if(i+1<size)
	  {
	    cnt++;
	    sum+=data[(i+1)*size+j];
	  }
	if(j-1>=0)
	  {
	    cnt++;
	    sum+=data[i*size+j-1];
	  }
	if(j+1<size)
	  {
	    cnt++;
	    sum+=data[i*size+j+1];
	  }
	int val = sum/cnt;
	out[index]=val;
      }
  t=clock()-t;
  printf("arg %s, size: %d, max: %d, total ops: %d\n",argv[1],size,max,ops);
  printf("Took %f seconds(%d clicks)\n",((float)t)/CLOCKS_PER_SEC,(int)t);
  return 0;
}

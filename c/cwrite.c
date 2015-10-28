#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
  int counter;
  FILE *ptr_myfile;

  if(argc<2)
    {
      printf("too few args");
    }
  
  int size=atoi(argv[1]);
  int max=size*size;

  char *data = malloc(max*sizeof(char));

  ptr_myfile=fopen("test.bin","wb");
  if(!ptr_myfile)
    {
      printf("unable to open file!");
      return 1;
    }
  for(counter=0;counter<max; counter++)
    {
      data[counter]=counter%256;
    }
  fwrite(&data,sizeof(char),max,ptr_myfile);
  fclose(ptr_myfile);
  return 0;
}

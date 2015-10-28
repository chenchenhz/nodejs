#include<stdio.h>
#include<stdlib.h>
#define uint8 unsigned char
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

  uint8 *data = malloc(max*sizeof(uint8));

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
  printf("size: %d, total: %d, size: %d\n", size, max, (int)(max*sizeof(uint8)));
  fwrite(data,sizeof(uint8),max,ptr_myfile);
  fclose(ptr_myfile);
  return 0;
}

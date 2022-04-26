#include <stdio.h>
#include <unistd.h>

typedef struct {
    float   speed;
    int     rpm;
}taurus_cluster_data_t;

int main() {
  // call a function in another file
  printf("Hello Cluster!\n");
  unsigned char byte,dummy;
  FILE * cluster_drv;
  taurus_cluster_data_t cdata = {
	  .speed = 120.0,
	  .rpm = 2500,
  };
  cluster_drv=fopen("/dev/taurus-cluster","w");
  if(cluster_drv == NULL)
  {
     printf("fatal:Driver /dev/taurus-cluster does not exist.");
     return 0;
  }
  fwrite(&cdata, sizeof(cdata), 1, cluster_drv);
  fclose(cluster_drv);
  return(0);
}

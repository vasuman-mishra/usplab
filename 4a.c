#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
if(argc==3){
if((link(argv[1],argv[2]))==0){
printf("Hard link created\n");
}
else{
printf("Hard link error\n");
}
}
else if(argc==4){
if((symlink(argv[2],argv[3]))==0){
printf("Soft link created\n");
}
else{
printf("Soft link error\n");
}
}
return 0;
}
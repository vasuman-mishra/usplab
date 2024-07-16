#include<setjmp.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
static void f1(int,int,int,int);
static void f2(void);
static int gv;
static jmp_buf jb;
int main(void){
int av=2;register int rv=3; volatile int vv=4;static int sv=5;gv=1;
if(setjmp(jb)!=0){
printf("after longjmp\n");
printf("gv=%d,av=%d,rv=%d,vv=%d,sv=%d \n",gv,av,rv,vv,sv);
exit(0);
}
gv=95;av=96;rv=97;vv=98;sv=99;
f1(av,rv,vv,sv);
exit(0);
}
static void f1(int i,int j,int k,int l){
printf("in f1() \n");
printf("gv=%d,av=%d,rv=%d,vv=%d,sv=%d \n",gv,i,j,k,l);
f2();
}
static void f2(void){
longjmp(jb,1);
}
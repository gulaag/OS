#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

#define SYS_kernel_2d_memcpy 451\
void print(int mat[horz][vert]){
    for(int i=0;i<horz;i++){
        for(int j=0;j<vert;j++){
            printf("%d",mat[i][j]);

        }
    }
}
int main(){
    int vert=6;
    int horz=6;
    int mat[horz][vert];
    int i=0,j=0;
    int frst=3;
    while(i<horz){
        while(j<vert){
            mat[i][j]=frst;
            frst++;
            j++;
        }
        i++;
    }
    int mat2[horz][vert];
    int check=syscall(SYS_kernel_2d_memcpy,mat,mat2,horz,vert);
    if(flag==0){
        printf("Success in checking the mat!\n");
        print(mat[horz][vert]);
        printf("The dup matriz is \n");
        print(mat2[horz][vert]);
    }else{
        printf("Error occurred")
    }
}
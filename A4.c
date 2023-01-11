#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//structure to store key and content
typedef struct Node{
int sum_key;
int key[3];
int content[7];
}Node;
//simply obtains index of specific key
int getindex(Node B[20],int k)
{

    for (int i = 0; i < 20; i++)
{
     if ( k == B[i].sum_key)
     {
         return i;
     }

}
printf("\n----ERROR----\n");
return 0;
}

 //downheap algorithm
void Heapsort(Node B[20], int i, int run){

    

    Node temp;

while(i>=0 && i<=9 ) //does parent have a child and does it even exist (i>=0)
{
    //int Parent= floor((i-1)/2); (not needed but chould have been used) these files weill alwasy have 9 parents
    int isave=i;
    int childL=((2*i)+1);
    int childR=((2*i)+2);

    //one child mean ony left child aviable
    if(childR>19 && B[childL].sum_key<B[i].sum_key ){
        temp=B[i]; //for swaping 
        B[i]=B[childL];
        B[childL]=temp;
        i=getindex(B,temp.sum_key);
        Heapsort(B,i,1); //check for violation
        i=isave;
    }
    //2 children
    else if(B[childL].sum_key<B[childR].sum_key && B[childL].sum_key<B[i].sum_key){ //change left child with parent 
        temp=B[i];//for swaping 
        B[i]=B[childL];
        B[childL]=temp; 
        i= getindex(B,temp.sum_key);
        Heapsort(B,i,1); //check for violation
        i=isave;
    }
    //2 children
    else if(B[childR].sum_key<B[childL].sum_key && B[childR].sum_key<B[i].sum_key){ //change right child with parent
        temp=B[i];//for swaping 
        B[i]=B[childR];
        B[childR]=temp;
        i= getindex(B,temp.sum_key);
        Heapsort(B,i,1); //check for violation
        i=isave;
    }
    else{
              //do nothing

    }

    if(run==0){
        i--; 
        //go through parent 9-0 for main loop 
    }
    if(run!=0){
        break;
        //stop looping for recusrive loop (just check for violation)
    }

}
 
 
}   
    


int main(){

    char integers[11]="0123456789";
    int inc=0;
    int L=0;
    //rows,colums
    int array[20][10];
    FILE* ptr;
     char name[20];
     printf("\nplease enter file name(in this folder file name is 'f.dat':");
     scanf("%s",name);

    // Opening file in reading mode
    ptr = fopen(name, "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    char singleline[28];
    while(!feof(ptr)) { //do not stop until file completly read 

    fgets(singleline,150,ptr); //get on line
    for(int i=0;i<sizeof(singleline);i++){
        //if integer then add to array of int
        if(strchr(integers,singleline[i])!=NULL && strchr(integers,singleline[i+1])!=NULL){
            char chartoint[4];
            chartoint[0]=singleline[i];
            chartoint[1]=singleline[i+1];
            int x=atoi(chartoint);        
      array[inc][L]=x; //add content to int array
      L++;

        }
        
     }
    inc++;
    L=0;
}

//creat array of Node
Node BHF[20];
//add content from file to array
for(int i=0;i<20;i++){
     BHF[i].sum_key=(array[i][0]+array[i][1]+array[i][2]);
     BHF[i].key[0]=array[i][0];
     BHF[i].key[1]=array[i][1];
     BHF[i].key[2]=array[i][2];
     
    for (int k=3;k<10;k++){


     BHF[i].content[k-3]=array[i][k];

    }


}
printf("\nfile contents...");
//print out date before heapsort
for(int i=0;i<20;i++){
    printf("\nKey=%d, Content(inc key elements) %.2d %.2d %.2d ",BHF[i].sum_key,BHF[i].key[0],BHF[i].key[1],BHF[i].key[2]);
    for (int k=0;k<7;k++){
     printf("%.2d ",BHF[i].content[k]);

    }

}

//call heap funtion
Heapsort(BHF,9,0);

//print after downheaping
printf("\n\nafter downheaping....");
for(int i=0;i<20;i++){
    printf("\nKey=%d, Content(inc key elements) %.2d %.2d %.2d ",BHF[i].sum_key,BHF[i].key[0],BHF[i].key[1],BHF[i].key[2]);
    for (int k=0;k<7;k++){
     printf("%.2d ",BHF[i].content[k]);

    }

}
printf("\n");
return 0;
}
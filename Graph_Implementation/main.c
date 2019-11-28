#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
};
struct node *newnode(int data){
 
    struct node *Node=(struct node*)malloc(sizeof(struct node));
    Node->data=data;
   Node->next=NULL;
    return Node;
 
}
void read_graph(struct node *adj[],int n){
     struct node *c;
    int i,j,k;
     int val;
    for(i=0;i<n;i++){
        struct node *last=NULL;
     
        printf("enter the neighbours of %d \n",i+1);
        scanf("%d",&k);
        for(j=0;j<k;j++){
         
            printf("enter the value of %d neighbour of %d \n",j+1,i+1);
            scanf("%d",&val);
         
            c=newnode(val);
            if(adj[i]==NULL){
                adj[i]=c;
                last=c;
                       
            }
            else{
             
                last->next=c;
                last=c;
           
             
            }
        }
    }
}
void print_graph(struct node *adj[],int n){
    struct node *ptr;
    int i,j;
    for(i=0;i<n;i++){
        ptr=adj[i];
        printf("print the neighbour of %d \n",i+1);
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
 
}
void main(){
    int n,i;
    printf("enter the no. of nodes \n");
    scanf("%d",&n);
   
    struct node *adj_l[n];
    for(i=0;i<n;i++){
        adj_l[i]=NULL;
    }
    read_graph(adj_l,n);
    print_graph(adj_l,n);
}
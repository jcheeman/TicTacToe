#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create node struct
struct node{
//vairbales
    int n;
    char ID[30];
    int miles;
    char returndate[10];//yymmdd

}tmp;

//declar the node
typedef struct node node;

//link to the next node
struct linked_list{
    node data;
   struct linked_list *next;
};

//declar the node
typedef struct linked_list linked_list;
linked_list *ava,*rented,*in_repair,*p;

//compare the expect return date to order the list
int ccmp(char * a,char *b)
{
    int y1= a[0]*10+a[1],y2= b[0]*10+b[1];
    int m1= a[2]*10+a[3],m2= b[2]*10+b[3];
    int d1= a[4]*10+a[5],d2= b[4]*10+b[5];
    if(y1!=y2) return y1<y2;
    if(m1!=m2) return m1<m2;
    return d1<d2;
}
//Available_for_rent linked list
void Available_for_rent(node tmp)
{
    //calls linked list
    p=ava;
    //order and listing the list
    while(p->next!=0&&(tmp.miles) > (p->next->data.miles) )
    {
    p=p->next;
    }
    //allocate node memory space
    linked_list *t=(linked_list *)malloc(sizeof(linked_list));
    //listing the nodes
    t->data=tmp;
    t->next=p->next;
    p->next=t;
}

//Rented_cars linked list
void Rented_cars(node tmp)
{
    //calls linked list
    p=rented;
    //order and listing the list
    while(p->next!=0&& !ccmp(tmp.returndate,p->next->data.returndate))
    {
    p=p->next;
    }
    //allocate node memory space
    linked_list *t=(linked_list *)malloc(sizeof(linked_list));
    //listing the nodes
    t->data=tmp;
    t->next=p->next;
    p->next=t;
}

//In_Repair linked list
void In_repair(node tmp)
{
    //calls linked list
    p=in_repair;
    //order and listing the list
    while(p->next!=0&&(tmp.miles) > (p->next->data.miles) )
    {
    p=p->next;
    }
    //allocate node memory space
    linked_list *t=(linked_list *)malloc(sizeof(linked_list));
    //listing the nodes
    t->data=tmp;
    t->next=p->next;
    p->next=t;
}


//Read from the disk file
void read() {
  //open the file
  FILE * fid = fopen("data.txt", "r");
  //Error if it is not existing
  if (fid == NULL) {
    printf("Can't read the file.\n");
    //return;
  }

  //Reading the file
  while (!feof(fid)) {
    tmp.n=-1;
    fscanf(fid, "%d", &tmp.n);
    if (tmp.n == 1) {
      fscanf(fid, "%s%d", tmp.ID, &tmp.miles);
      printf("Readed: %d %s %d\n", tmp.n, tmp.ID, tmp.miles);
      Available_for_rent(tmp);

    } else if (tmp.n == 2) {
        fscanf(fid, "%s%d%s", tmp.ID, &tmp.miles, tmp.returndate);
        printf("Readed: %d %s %d %s\n", tmp.n, tmp.ID, tmp.miles, tmp.returndate);
      Rented_cars(tmp);
    } else if (tmp.n == 3) {
    fscanf(fid, "%s%d", tmp.ID, &tmp.miles);
    printf("Readed: %d %s %d\n", tmp.n, tmp.ID, tmp.miles);
      In_repair(tmp);
    }
  }
  //close the file
  fclose(fid);
}

//write into the disk file
void save() {
  //open the file
  FILE * fid = fopen("data.txt", "w");
  //Error if it it not existing
  if(fid == NULL) {
    printf("Can't write to the file\n");
    return;
  }
    //write in Available_for_rent
    p = ava->next;
    while (p != 0) {
      fprintf(fid, "%d %s %d\n", p->data.n, p->data.ID, p->data.miles), p = p->next;
    }
    //write in Rented_cars
    p = rented->next;
    while (p != 0) {
      fprintf(fid, "%d %s %d %s\n", p->data.n, p->data.ID, p->data.miles, p->data.returndate), p = p->next;
    }
    //write in In_Repair
    p = in_repair->next;
    while (p != 0) {
      fprintf(fid, "%d %s %d\n", p->data.n, p->data.ID, p->data.miles), p = p->next;
    }
    //close the file
    fclose(fid);
}

/*
//Read from the disk file
void read()
{
    //open the file
     FILE * fid = fopen("data.txt","r");
     //Error if it is not existing
    if(fid == NULL)
        printf("erro\n");
       // return;

       //Reading the file
    while(!feof(fid))
        {
            tmp.n=-1;
            fscanf(fid,"%d%s%d%s",&tmp.n,tmp.ID,&tmp.miles,tmp.returndate);
           // printf("%d %s %d %s\n",tmp.n,tmp.ID,tmp.miles,tmp.returndate);
            if(tmp.n==1)
                Available_for_rent(tmp);
            else if(tmp.n==2)
                Rented_cars(tmp);
            else if (tmp.n==3)
                In_repair(tmp);
        }
        //close the file
    fclose(fid);
}

//write into the disk file
void save()
{
    //open the file
    FILE * fid = fopen("data.txt","w");
    //Error if it it not existing
    if(fid == NULL)
    {
        printf("erro\n");
        return;
    }
    //write in Available_for_rent
     p=ava->next;
     while(p!=0)
        fprintf(fid,"%d %s %d %s\n",p->data.n,p->data.ID,p->data.miles,p->data.returndate),p=p->next;
    //write in Rented_cars
     p=rented->next;
     while(p!=0)
        fprintf(fid,"%d %s %d %s\n",p->data.n,p->data.ID,p->data.miles,p->data.returndate),p=p->next;
    //write in In_Repair
     p=in_repair->next;
     while(p!=0)
        fprintf(fid,"%d %s %d %s\n",p->data.n,p->data.ID,p->data.miles,tmp.returndate),p=p->next;
    //close the file
    fclose(fid);
}
*/

//Allocate each of the linked lists
void init()
{
    ava=(linked_list *)malloc(sizeof(linked_list));
    rented=(linked_list *)malloc(sizeof(linked_list));
    in_repair=(linked_list *)malloc(sizeof(linked_list));
    ava->next=rented->next=in_repair->next=0;
    read();
}

//print the lists
void print_all()
{
  //clear screen
  //printf("\n\n\n\n\n\n\n\n\n\n");
  //print the available for rent list
    printf("Available cars for Rent(plate number, miles):\n\n");
    p=ava->next;
     while(p!=0)
        printf("%s %d\n",p->data.ID,p->data.miles),p=p->next;
    //print the rented car list
    printf("Rented cars(plate number, expect return date):\n\n");
     p=rented->next;
     while(p!=0)
        printf("%s %s\n",p->data.ID,p->data.returndate),p=p->next;
    //print the in repair list
    printf("Cars in repair(plate number, miles):\n\n");
     p=in_repair->next;
     while(p!=0)
        printf("%s %d\n",p->data.ID,p->data.miles),p=p->next;
}

//menu
void menu() {
  //clear screen
  printf("\n\n\n\n\n\n\n\n\n\n");

  printf("\n\n\n");

  printf("Welcome to the best car rental company in the world!\n");
  printf("\n\n\n");

  printf("Please enter a transection code listed below to continue(1 to 7): \n");

  printf("\n");
  printf("\t1: Adding a new car to the available for rent list\n");
  printf("\t2: Adding a returned car to the avaiable for rent list\n");
  printf("\t3: Adding a returned car to the repair list \n");
  printf("\t4: Transfer a car from the repair list to the available for rent list\n");
  printf("\t5: Rent the first available car\n");
  printf("\t6: Print all the lists\n");
  printf("\t7: Quit\n");
  printf("\n");

  printf("Transection Code: ");

}

//continue steps
void press()
{
    printf("Press any key to return\n");
    getchar();
    getchar();
}

//income
int earning(int km)
{
    if(km<=100) {
      return 40;
    } else {
      return 40+(km-100)*15;
    }
}

int main()
{
    init();
    int tranCode;
    menu();

    while(~scanf("%d",&tranCode))
    {
        if(tranCode==1)
        {
            printf("\n\n\n\n\n");
            printf("You have chose to add a new car to the available for rent list\n");
            printf("\n");
            printf("Please input plate number and miles(separate with space):\n");
            scanf("%s %d",tmp.ID,&tmp.miles);
            tmp.n=1;
            Available_for_rent(tmp);
            printf("Plate number %s has been added to avaiable for rent list\n", tmp.ID);
            press();
            menu();
            save();
        }





        if (tranCode == 8) {
                  printf("\n\n\n\n\n");
                  printf("You have chose toable for rent list\n");
                  printf("\n");
                  printf("Please input plate number and miles(separate with space):\n");
                  scanf("%s %d %s", tmp.ID, &tmp.miles, tmp.returndate);
                  tmp.n = 2;
                  Rented_cars(tmp);
                  printf("Plate number %s has been addedt list\n", tmp.ID);
                  press();
                  menu();
                  save();
        }


        if (tranCode == 9) {
                  printf("\n\n\n\n\n");
                  printf("You have chose toable for rent list\n");
                  printf("\n");
                  printf("Please input with space):\n");
                  scanf("%s %d", tmp.ID, &tmp.miles);
                  tmp.n = 3;
                  In_repair(tmp);
                  printf("Plate number %s edt list\n", tmp.ID);
                  press();
                  menu();
                  save();
        }









        if(tranCode==2)
        {
            printf("\n\n\n\n\n");
            printf("You have chose to add a returned car to the avaiable for rent list\n");
            printf("\n");
            printf("Please input plate number and miles(separate with space):\n");
            scanf("%s %d",tmp.ID,&tmp.miles);
            p=rented;
            while(p->next!=0)
            {
                if(!strcmp(tmp.ID,p->next->data.ID))
                    break;
                p=p->next;
            }
            if(p->next!=0)
            {
            p->next=p->next->next;
            tmp.n=1;
            Available_for_rent(tmp);
            printf("Plate number %s has been transferd from returned cars to available for rent list\n", tmp.ID);
            printf("change :%d\n", earning(tmp.miles));
            }
            else
                printf("non-existent car\n");

            press();
            menu();
            save();
        }
        if(tranCode==3)
        {
            printf("\n\n\n\n\n");
            printf("You have chose to add a returned car to the repair list\n");
            printf("\n");
            printf("Please input plate number and miles(separate with space):\n");
            scanf("%s %d",tmp.ID,&tmp.miles);
            p=rented;
            while(p->next!=0)
            {
                if(!strcmp(tmp.ID,p->next->data.ID))
                    break;
                p=p->next;
            }
            if(p->next!=0)
            {
            p->next=p->next->next;
            tmp.n=3;
            In_repair(tmp);
            printf("Plate number %s has been transferd from returned cars to repair list\n", tmp.ID);
            printf("change :%d\n", earning(tmp.miles));
            }
           else
             printf("non-existent car\n");
            press();
            menu();
            save();
        }
        if(tranCode==4)
        {
            printf("\n\n\n\n\n");
            printf("You have chose to transfer a car from the repair list to the available for rent list\n");
            printf("\n");
            printf("Please input plate number:\n");
            scanf("%s",tmp.ID);
            p=in_repair;
            while(p->next!=0)
            {
                if(!strcmp(tmp.ID,p->next->data.ID))
                {
                    tmp=p->next->data;
                    break;
                }
                p=p->next;
            }
            if(p->next!=0)
            {
                p->next=p->next->next;
            tmp.n=1;
            Available_for_rent(tmp);
            printf("Plate number %s has been transferd from repair list to availabe for rent list\n", tmp.ID);
          }
            else
         printf("non-existent car\n");
            press();
            menu();
            save();
        }
        if(tranCode==5)
        {
            printf("\n\n\n\n\n");
            printf("You have chose to rent the first available car\n");
            printf("\n");

            p=ava;
            if(p->next==0) printf("avaliable for rent is NULL\n");
            else
            {
            printf("Please input expect return data(yymmdd):\n");
            tmp=p->next->data;
            p->next=p->next->next;
            tmp.n=2;
            scanf("%s",tmp.returndate);
            Rented_cars(tmp);
            printf("Rented %s\n",tmp.ID);
            }

            press();
            menu();
            save();
        }
        if(tranCode==6)
        {
            printf("You have chose to print all the lists\n");
            printf("\n\n\n");
            print_all();
            press();
            menu();
        }
        if(tranCode==7)
        {
            printf("You have chose to quit the program\n");
            printf("\n");
            int income=0;
            p=rented->next;
            while(p!=0)
            income+=earning(p->data.miles),p=p->next;
            printf("the total income from all the rented cars : %d \n" ,income);
             return 0;

        }
    }

    save();
    return 0;
}

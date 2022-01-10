#include<stdio.h>

typedef struct hostel{
    int roll_no;
    char name[30];
    char location[30];
    char gender[6];
    int room_no;
}hostel;

int lower = 601,upper = 610;

void create(){
    hostel h;
    FILE *fp = fopen("hostel.txt","a+");
     
    printf("Enter RollNo : ");
    scanf("%d",&h.roll_no);
    printf("Enter Name : ");
    scanf("%s",h.name);
    printf("Enter Location : ");
    scanf("%s",h.location);
    printf("Enter Gender : ");
    scanf("%s",h.gender);
    h.room_no = getRoomno(((rand()%(upper-lower+1))+lower));
    if(h.room_no!=0)
         fwrite(&h,sizeof(hostel),1,fp);


    fclose(fp);
}

int getRoomno(int room_no){
    int allocated = 0;
    FILE *fp = fopen("hostel.txt","r");
    hostel h1;
    while(fread(&h1,sizeof(hostel),1,fp)){
        if(h1.room_no == room_no){
            allocated = 1;
 
        }
    }
    if (allocated == 0)
       return room_no;
    else
       return getRoomno(((rand()%(upper-lower+1))+lower));
    fclose(fp);
}

void display(){
    hostel h1;
    FILE *fp = fopen("hostel.txt","r");
    printf("\n-----------------------------------------------------------------------\n");
    printf("%-10s%-20s%-15s%-10s%-5s","RollNo","Name","Location","Gender","RoomNo");
    printf("\n-----------------------------------------------------------------------\n");
    while(fread(&h1,sizeof(hostel),1,fp))
         printf("%-10d%-20s%-15s%-10s%-5d\n",h1.roll_no,h1.name,h1.location,h1.gender,h1.room_no);

}
int main()
{
    int ch;
    do{
        printf("\n1.ALLOCATE NEW ROOM TO THE STUDENT");
        printf("\n2.DISPLAY THE DETAILS");
        printf("\n0.EXIT");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 0:printf("\nThank You......\n");

        }
    }while(ch!=0);
}
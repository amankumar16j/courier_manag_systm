#include<stdio.h>
#include<stdlib.h>

struct customer{

    int cid;
    char name[50];
    char address[100];
    int mobile;
}cust,cust1[1000],temp;




int available(int cid){

    FILE *fptr;
    fptr=fopen("courier.txt","r");

    while(!feof(fptr)){
        fread(&cust,sizeof(cust),1,fptr);
        if(cid==cust.cid){
            fclose(fptr);
            return 1;
        }
    }
    return 0;
    fclose(fptr);

}


void insert(){

    FILE *fptr;
    int cid;

        fptr=fopen("courier.txt","a");

        printf("\nEnter the Courier ID :");
        scanf("%d",&cid);

        if(available(cid)==1){

            printf("\nCourier ID %d already present\n\n",cid);
            fclose(fptr);

        }

        else{

        cust.cid=cid;

        printf("\nEnter Customer name :");
        scanf("%s",&cust.name);

        printf("\nEnter Customer address :");
        scanf("%s",&cust.address);

        printf("\nEnter Customer mobile no. :");
        scanf("%d",&cust.mobile);

        printf("\n");

        fwrite(&cust,sizeof(cust),1,fptr);}

        fclose(fptr);

}

void display(){

    FILE *fptr;

    fptr=fopen("courier.txt","r");

    printf("\n\ncourier ID\t\tname\t\t\taddress\t\t\tmobile\n\n");

    while(fread(&cust,sizeof(cust),1,fptr)){

        printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\n\n",cust.cid,cust.name,cust.address,cust.mobile);

    }

    fclose(fptr);
}

void delet(){

    FILE *fptr;
    FILE *tfptr;
    int cid,s;


    printf("\nEnter the Courier ID to delete:");
    scanf("%d",&cid);

    if(available(cid)==0){
        printf("\nThe Courier ID %d does not exist\n",cid);

    }

    else{

    fptr=fopen("courier.txt","r");
    tfptr=fopen("tempo.txt","w");

        while(fread(&cust,sizeof(cust),1,fptr)){

            s=cust.cid;
            if(s!=cid){
                fwrite(&cust,sizeof(cust),1,tfptr);
            }
        }

            fclose(fptr);
            fclose(tfptr);

            fptr=fopen("courier.txt","w");
            tfptr=fopen("tempo.txt","r");

            while(fread(&cust,sizeof(cust),1,tfptr)){

                fwrite(&cust,sizeof(cust),1,fptr);
            }
            printf("\nRecord Deleted!!\n");
            fclose(fptr);
            fclose(tfptr);
    }

}

void update(){

    FILE *fptr;
    FILE *tfptr;
    int cid,se;
    int cho;

    printf("\nEnter Customer ID to update:");
    scanf("%d",&cid);
    printf("\n");

    if(available(cid)==0){
        printf("Customer ID %d not available!!\n\n",cid);
    }
    else{
        fptr=fopen("courier.txt","r");
        tfptr=fopen("tempo.txt","w");

        while(fread(&cust,sizeof(cust),1,fptr)){

            se=cust.cid;
            if(se!=cid){
                fwrite(&cust,sizeof(cust),1,tfptr);
            }
            else{
                printf("------------SELECT YOUR CHOICE TO UPDATE------------\n");
                printf("\t\t\t 1. Update name\n");
                printf("\t\t\t 2. Update address\n");
                printf("\t\t\t 3. Update mobile\n");
                printf("\t\t\t 4. Update all\n");

                printf("\nEnter your choice:");
                scanf("%d",&cho);


                switch(cho){

                    case 1:{
                        printf("Enter Customer name:");
                        scanf("%s",&cust.name);
                        break;
                    }

                    case 2:{
                        printf("Enter Customer address:");
                        scanf("%s",&cust.address);
                        break;
                    }

                    case 3:{
                        printf("Enter Customer mobile:");
                        scanf("%d",&cust.mobile);
                        break;
                    }

                    case 4:{
                        printf("Enter Customer name:");
                        scanf("%s",&cust.name);

                        printf("Enter Customer address:");
                        scanf("%s",&cust.address);

                        printf("Enter Customer mobile:");
                        scanf("%d",&cust.mobile);

                        break;
                    }

                    default:{
                        printf("Invalid Choice!!!!\n\n");

                        break;
                    }
                }

                fwrite(&cust,sizeof(cust),1,tfptr);
            }

    }

    fclose(fptr);
    fclose(tfptr);

    fptr=fopen("courier.txt","w");
    tfptr=fopen("tempo.txt","r");

    while(fread(&cust,sizeof(cust),1,tfptr)){
        fwrite(&cust,sizeof(cust),1,fptr);
    }

    fclose(fptr);
    fclose(tfptr);

    printf("\nRecord Updated!!\n\n");

  }

}

void search(){

    FILE *fptr;

    char name[20];
    char address[20];
    int ID;

    int cho;

    printf("\n\n-------------SELECT YOUR CHOICE TO SEARCH------------\n");

    printf("\t\t\t 1. Search by name\n");
    printf("\t\t\t 2. Search by address\n");
    printf("\t\t\t 3. Search by courier ID\n");

    printf("\n\nEnter your choice:");
    scanf("%d",&cho);

    switch(cho){

        case 1:{

            printf("\nEnter the name to search:");
            scanf("%s",&name);

            fptr=fopen("courier.txt","r");

            printf("\n\ncourier ID\t\tname\t\t\taddress\t\t\tmobile\n\n");

            while(fread(&cust,sizeof(cust),1,fptr)){

                if(strcmp(name,cust.name)==0){
                    printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\n\n",cust.cid,cust.name,cust.address,cust.mobile);
                }
            }

            fclose(fptr);
            break;

        }

        case 2:{

            printf("\nEnter the address to search:");
            scanf("%s",&address);

            fptr=fopen("courier.txt","r");

            printf("\n\ncourier ID\t\tname\t\t\taddress\t\t\tmobile\n\n");

            while(fread(&cust,sizeof(cust),1,fptr)){

                if(strcmp(address,cust.address)==0){
                    printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\n\n",cust.cid,cust.name,cust.address,cust.mobile);
                }
            }

            fclose(fptr);
            break;

        }

        case 3:{

            printf("\nEnter the Courier ID to search:");
            scanf("%d",&ID);

            fptr=fopen("courier.txt","r");

            printf("\n\ncourier ID\t\t\tname\t\t\t\taddress\t\t\t\tmobile\n\n");

            while(fread(&cust,sizeof(cust),1,fptr)){

                if(ID==cust.cid){
                    printf("%d\t\t\t\t%s\t\t\t\t%s\t\t\t\t%d\n\n",cust.cid,cust.name,cust.address,cust.mobile);
                }
            }

            fclose(fptr);
            break;
        }

        default:{
            printf("Invalid Choice!!\n");
            break;
        }

    }
}

void sort(){

    FILE *fptr;
    int i=0,length,s=0;
    fptr=fopen("courier.txt","r");

    while(fread(&cust,sizeof(cust),1,fptr)){

        cust1[i].cid=cust.cid;
        strcpy(cust1[i].name,cust.name);
        strcpy(cust1[i].address,cust.address);
        cust1[i].mobile=cust.mobile;
        i++;
    }
    fclose(fptr);
    length=i;

    //now sorting the array of structure

    for(int y=0;y<length-1;y++){
        for(int z=0;z<length-y-1;z++){

            if(cust1[z].cid>cust1[z+1].cid){

                temp=cust1[z];
                cust1[z]=cust1[z+1];
                cust1[z+1]=temp;
            }
        }
    }

    fptr=fopen("courier.txt","w");

    while(s<length){

        fwrite(&cust1[s],sizeof(cust),1,fptr);
        s++;

    }

    printf("Record Sorted!!\n\n");
    fclose(fptr);

}

int main(){

    int ch;

    printf("Opening Courier Management system\n\n");

    char default_psw[20]="amankumar16j";
    char default_uid[20]="amankumar16j";

    char psw[20],uid[20];

    printf("\n\nEnter User ID and Password : amankumar16j\n");

    printf("\n\nEnter User ID:");
    scanf("%s",&uid);

    printf("\n\nEnter Password:");
    scanf("%s",&psw);

    if(strcmp(psw,default_psw)==0 && strcmp(uid,default_uid)==0){

        printf("\n\nSuccessfully logged in!!!!\n\n");

    while(1){
    printf("-----------------------SELECT YOUR CHOICE-----------------------\n");
    printf("\n\t\t\t 1. Insert\n");
    printf("\t\t\t 2. Display\n");
    printf("\t\t\t 3. Search\n");
    printf("\t\t\t 4. Update\n");
    printf("\t\t\t 5. Delete\n");
    printf("\t\t\t 6. Sort\n");
    printf("\t\t\t 7. Exit\n");


    printf("\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch){

    case 1:{
            insert();
            break;}

    case 2:{
            display();
            break;}
//
    case 3:{
            search();
            break;}

//
    case 4:{
            update();
            break;}

    case 5:{
            delet();
            break;}

    case 6:{
            sort();
            break;}

    case 7:{

            printf("\nCourier Management System Closed\n\n");
            exit(0);
            break;}

    default:{
            printf("\nInvalid choice!!\n\n");}

}

    }


 }

 else{

    
    printf("\n\nInvlaid credintials!!!!!\n\n");
 }

}
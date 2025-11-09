#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct student{
    char Name[80];
    char Rollno[3];
    char Idno[100];
    char phone_no[20];
    struct address{
        char vname[100];
        char pincode[6];
    }addr;
    struct class{
        char branch_name[30];
        char section[10];
    }cls;    
};


int add_student()
{
struct student s;
FILE *fp;

fp=fopen("project_file.txt","a+");
    printf("Enter Idno of the student: ");
    scanf("%s",s.Idno);
    getchar();
    s.Idno[0]=toupper(s.Idno[0]);
    fprintf(fp,"%s,",s.Idno);
    printf("Name of the Student: ");
    fgets(s.Name,100,stdin);
    s.Name[strcspn(s.Name,"\n")]='\0';
    fprintf(fp,"%s,",s.Name);
    printf("Roll No of the Student: ");
    scanf("%s",s.Rollno);
    getchar();
    fprintf(fp,"%s,",s.Rollno);
    printf("Phone No Of The Student : ");
    scanf("%s",s.phone_no);
    getchar();
    fprintf(fp,"%s,",s.phone_no);
    printf("Enter Branch name:");
    fgets(s.cls.branch_name,100,stdin);
    s.cls.branch_name[strcspn(s.cls.branch_name,"\n")]='\0';
    fprintf(fp,"%s,",s.cls.branch_name);
    printf("Enter Section: ");
    scanf("%s",s.cls.section);
    getchar();
    fprintf(fp,"%s,",s.cls.section);
    printf("Enter village name: ");
    scanf("%s",s.addr.vname);
    getchar();
    fprintf(fp,"%s,",s.addr.vname);
    printf("Enter Pincode: ");
    scanf("%s",s.addr.pincode);
    getchar();
    fprintf(fp,"%s",s.addr.pincode);
    fprintf(fp,"%s","\n");
fclose(fp);
char add[10];
printf("Wants to Add one more more student Y/N:");
fgets(add,10,stdin);
add[strcspn(add,"\n")]='\0';
while(1){
    if(strcmp(add,"Y")==0 || strcmp(add,"Yes")==0 || strcmp(add,"YES")==0 ||strcmp(add,"y")==0){
        add_student();
    }
    break;
}


}

int print_all_student_details(){
    struct student s;
    char line[100];
    int count=0;
    FILE *fp;
    fp=fopen("project_file.txt","r");
        while(fgets(line,100,fp)){
            char *token=strtok(line,",");
            strcpy(s.Idno,token);
            printf(" IDNO : %s \n",s.Idno);
            token=strtok(NULL,",");
            strcpy(s.Name,token);
            printf(" Name : %s \n",s.Name);
            token=strtok(NULL,",");
            strcpy(s.Rollno,token);
            printf(" Rollno : %s\n",s.Rollno);
            token=strtok(NULL,",");
            strcpy(s.phone_no,token);
            printf(" Phone No : %s \n",s.phone_no);
            token=strtok(NULL,",");
            strcpy(s.cls.branch_name,token);
            printf(" Branch : %s\n",s.cls.branch_name);
            token=strtok(NULL,",");
            strcpy(s.cls.section,token);
            printf(" Section : %s \n",s.cls.section);
            token=strtok(NULL,",");
            strcpy(s.addr.vname,token);
            printf(" Village Name : %s\n",s.addr.vname);
            token=strtok(NULL,",");
            strcpy(s.addr.pincode,token);
            printf(" Pincode : %s\n",s.addr.pincode);
        }
    fclose(fp);
} 

int search_student(){
    struct student s;
    char id[100];
    printf("Enter Id to print that student Detaills : ");
    fgets(id,100,stdin);
    id[strcspn(id,"\n")]='\0';
    id[0]=toupper(id[0]);
    FILE *fp;
    fp=fopen("project_file.txt","r");
    char line[100];
    int found=0;
    while(fgets(line,100,fp)){
        char *token=strtok(line,",");
        if(strcmp(token,id)==0){
            strcpy(s.Idno,token);
            printf(" IDNO : %s \n",s.Idno);
            token=strtok(NULL,",");
            strcpy(s.Name,token);
            printf(" Name : %s \n",s.Name);
            token=strtok(NULL,",");
            strcpy(s.Rollno,token);
            printf(" Rollno : %s\n",s.Rollno);
            token=strtok(NULL,",");
            strcpy(s.phone_no,token);
            printf(" Phone No : %s \n",s.phone_no);
            token=strtok(NULL,",");
            strcpy(s.cls.branch_name,token);
            printf(" Branch : %s\n",s.cls.branch_name);
            token=strtok(NULL,",");
            strcpy(s.cls.section,token);
            printf(" Section : %s \n",s.cls.section);
            token=strtok(NULL,",");
            strcpy(s.addr.vname,token);
            printf(" Village Name : %s\n",s.addr.vname);
            token=strtok(NULL,",");
            strcpy(s.addr.pincode,token);
            printf(" Pincode : %s",s.addr.pincode);
            found=1;
            break;
        }
        else{
            found=0;
        }
    }
if(found==0){
    printf("Sorry Student Details Not found \n");
}
}

int update_studentDetails(){
    struct student s;
    FILE *fp,*p;
    char line[100];
    char id[10];
    printf("Enter Id Number to update the student : ");
    fgets(id,100,stdin);
    id[strcspn(id,"\n")]='\0';
    id[0]=toupper(id[0]);
    int found=0;

    fp=fopen("project_file.txt","r");
    while(fgets(line,100,fp)){
        char *token=strtok(line,",");
        if(strcmp(token,id )==0){
            printf("Student Found : \n");
            found=1;
        }
    }
    if(found==0){
        printf("Student Not found To update \n");
        return 0;
    }
    fclose(fp);
    
    fp=fopen("project_file.txt","r");
    p=fopen("temp.txt","a+");
    char *token;
    while(fgets(line,100,fp)){
        token=strtok(line,",");
        if(strcmp(token,id)==0){
            strcpy(s.Idno,token);
            fprintf(p,"%s,",s.Idno);
            token=strtok(NULL,",");
            strcpy(s.Name,token);
            fprintf(p,"%s,",s.Name);
            token=strtok(NULL,",");
            printf("Enter roll no to update: ");
            scanf("%s",s.Rollno);
            getchar();
            fprintf(p,"%s,",s.Rollno);
            token=strtok(NULL,",");
            printf("Enter Phone No to update : ");
            scanf("%s",s.phone_no);
            getchar();
            fprintf(p,"%s,",s.phone_no);
            token=strtok(NULL,",");
            strcpy(s.cls.branch_name,token);
            fprintf(p,"%s,",s.cls.branch_name);
            token=strtok(NULL,",");
            printf("Enter Section to update: ");
            scanf("%s",s.cls.section);
            getchar();
            fprintf(p,"%s,",s.cls.section);
            token=strtok(NULL,",");
            printf("Enter village name: ");
            scanf("%s",s.addr.vname);
            getchar();
            fprintf(p,"%s,",s.addr.vname);
            token=strtok(NULL,",");
            printf("Enter Pincode: ");
            scanf("%s",s.addr.pincode);
            getchar();
            fprintf(p,"%s",s.addr.pincode);
            fprintf(p,"%s","\n");
        }
        else{
            strcpy(s.Idno,token);
            fprintf(p,"%s,",s.Idno);
            token=strtok(NULL,",");
            strcpy(s.Name,token);
            fprintf(p,"%s,",s.Name);
            token=strtok(NULL,",");
            strcpy(s.Rollno,token);
            fprintf(p,"%s,",s.Rollno);
            token=strtok(NULL,",");
            strcpy(s.phone_no,token);
            fprintf(p,"%s,",s.phone_no);
            token=strtok(NULL,",");
            strcpy(s.cls.branch_name,token);
            fprintf(p,"%s,",s.cls.branch_name);
            token=strtok(NULL,",");
            strcpy(s.cls.section,token);
            fprintf(p,"%s,",s.cls.section);
            token=strtok(NULL,",");
            strcpy(s.addr.vname,token);
            fprintf(p,"%s,",s.addr.vname);
            token=strtok(NULL,",");
            strcpy(s.addr.pincode,token);
            fprintf(p,"%s",s.addr.pincode);
        }
    }
    fclose(p);
    fclose(fp);
    remove("project_file.txt");
    rename("temp.txt","project_file.txt");
    printf("Record Updated Suceessfully \n");
}


int delete_student(){
    struct student s;
    FILE *fp,*p;
    char line[100];
    char id[10];
    printf("Enter Id Number to Delete the student : ");
    fgets(id,100,stdin);
    id[strcspn(id,"\n")]='\0';
    id[0]=toupper(id[0]);
    int found=0;
    fp=fopen("project_file.txt","r");
    while(fgets(line,100,fp)){
        char *token=strtok(line,",");
        if(strcmp(token,id )==0){
            printf("Student Found \n");
            found=1;
        }
    }
    if(found==0){
        printf("Student Not found To Delete \n");
        return 0;
    }
    fclose(fp);
    fp=fopen("project_file.txt","r");
    p=fopen("temp.txt","a+");
    while(fgets(line,100,fp)){
        char *token=strtok(line,",");
        if(strcmp(token,id)==0){ 
            continue;
        }
        else{
            strcpy(s.Idno,token);
            fprintf(p,"%s,",s.Idno);
            token=strtok(NULL,",");
            strcpy(s.Name,token);
            fprintf(p,"%s,",s.Name);
            token=strtok(NULL,",");
            strcpy(s.Rollno,token);
            fprintf(p,"%s,",s.Rollno);
            token=strtok(NULL,",");
            strcpy(s.phone_no,token);
            fprintf(p,"%s,",s.phone_no);
            token=strtok(NULL,",");
            strcpy(s.cls.branch_name,token);
            fprintf(p,"%s,",s.cls.branch_name);
            token=strtok(NULL,",");
            strcpy(s.cls.section,token);
            fprintf(p,"%s,",s.cls.section);
            token=strtok(NULL,",");
            strcpy(s.addr.vname,token);
            fprintf(p,"%s,",s.addr.vname);
            token=strtok(NULL,",");
            strcpy(s.addr.pincode,token);
            fprintf(p,"%s",s.addr.pincode);
        }
    }
    fclose(p);
    fclose(fp);
    remove("project_file.txt");
    rename("temp.txt","project_file.txt");
    printf("Student Details are Suceessfully Deleted \n");
}


int main(){
printf(" ____________________________________________________________________________\n");
printf("|                                                                            |\n");
printf("|                                                                            |\n");
printf("|                         STUDENT MANAGMENT RECORD                           |\n");
printf("|                                                                            |\n");
printf("|____________________________________________________________________________|\n");
int a=0;

do{
    printf(" ____________________________________________________________________________\n");
    printf("|                            OPTIONS                                         |\n");
    printf("|                                                                            |\n");
    printf("| 1-To add a student                                                         |\n");
    printf("| 2-To print all students Details                                            |\n");
    printf("| 3-To print specific studnt                                                 |\n");
    printf("| 4-To Update Student Details                                                |\n");
    printf("| 5-To Delete a Student Details                                              |\n");
    printf("| 6-Exit                                                                     |\n");
    printf("|____________________________________________________________________________|\n \n");
    printf(" Enter Number : ");
    scanf("%d",&a);
    getchar();
    if(a==1) add_student();
    else if(a==2) print_all_student_details();
    else if(a==3) search_student();
    else if(a==4) update_studentDetails();
    else if(a==5) delete_student();
    else if(a==6) break;
    else printf("Enter Correct Number: \n");
}while(1);





}





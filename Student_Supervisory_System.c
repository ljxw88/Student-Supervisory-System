#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define max_len 100
#define max_ammount 1000
//#define max_temp 1000
float average_grade=0;
int all_grade=0;
int pt=0;
struct student
{
    char stu_id[max_len];
    char name[max_len];
    int sex;
    float math,eng,chinese,phy,chemic;
    float sum;
    float aver;
}stu[max_ammount];
void Show_Function()
{
    printf("Function Number :\n");
    puts(" |--------------------------");
    printf(" |- 1.Show all data\n |-- 2.Delete data\n |--- 3.Input data\n |---- 4.Search student\n |----- 5.Rankings\n |------ 6.Modify data\n |------- 7.Outstanding Students\n |-------- 8.Flunk Students\n |--------- 9.Exit\n");
    puts(" |--------------------------");
    printf("Choose Your Function (By order number) : ");
};
void calculate_sum_aver()
{
    stu[pt].sum = stu[pt].math+stu[pt].eng+stu[pt].chinese+stu[pt].phy+stu[pt].chemic;
    stu[pt].aver = (stu[pt].sum)/5.0;
    all_grade += stu[pt].sum;
};
void Print_Data(int i,int j)
{
    if(j==1)puts(">------------------------------------<");
    printf("| Data %d:\n",i+1);
    printf("| Student ID: %s\n",stu[i].stu_id);
    printf("| Student Name: %s\n",stu[i].name);
    if(stu[i].sex==-1)printf("| Student Sex: Female\n");
    else if(stu[i].sex==0)printf("| Student Sex: NULL\n");
    else if(stu[i].sex==1)printf("| Student Sex: Male\n");
    puts("| Score:");
    printf("| 1.Math: %.2f",stu[i].math);
    printf("    | 2.English: %.2f\n",stu[i].eng);
    printf("| 3.Chinese: %.2f",stu[i].chinese);
    printf(" | 4.Physics: %.2f\n",stu[i].phy);
    printf("| 5.Chemistry: %.2f\n",stu[i].chemic);
    printf("| Sum: %.2f",stu[i].sum);
    printf("      | Average: %.2f\n",stu[i].aver);
    if(j==1)puts(">------------------------------------<");
};
void Traverse_Data()
{
    int i;
    if(pt==0)
    {
        printf("No Student Data !\n");
    }
    else
    {
        for(i=0;i<pt;i++)
        {
            puts(">------------------------------------<");
            Print_Data(i,0);
            if(i==pt-1)
                puts(">------------------------------------<");
        }
    }
};
void Delete_Data()
{
    Traverse_Data();
    printf("Please input the data number you want to delete (1 ~ %d) : ",pt);
    int data_number;
    scanf("%d",&data_number);
    if(!(data_number>=1&&data_number<=pt))
    {
        printf("Invaild DataNumber\n");
        return;
    }
    else
    {
        data_number--;pt--;
        for(int i=data_number;i<pt;i++)
        {
            stu[i]=stu[i+1];
        }
        system("cls");
        printf("Data after manipulate : \n");
        Traverse_Data();
    }
};
void Input_Data()
{
    printf("Input the id : ");scanf("%s",stu[pt].stu_id);
    getchar();
    printf("Input the name : ");gets(stu[pt].name);
    printf("Input sex ( 1->Male : -1->Femail : 0->Unknown ) : ");scanf("%d",&stu[pt].sex);
    printf("Input the score :\n");
    printf("Math : ");scanf("%f",&stu[pt].math);
    printf("English : ");scanf("%f",&stu[pt].eng);
    printf("Chinese : ");scanf("%f",&stu[pt].chinese);
    printf("Physics : ");scanf("%f",&stu[pt].phy);
    printf("Chemistry : ");scanf("%f",&stu[pt].chemic);
    calculate_sum_aver();
    pt++;
};
void Outstanding_Students()
{
    struct student temp_stu[max_ammount];
    int i,j,pt_outstand=0;
    for(i=0;i<pt;i++)
    {
        if(stu[i].aver>=90.0)
        {
            temp_stu[pt_outstand++]=stu[i];
        }
    }
    if(pt_outstand==0)
    {
        printf("None\n");
        return;
    }
    struct student temp_aver;
    for(i=0;i<pt_outstand-1;i++)
    {
        for(j=i+1;j<pt_outstand;j++)
        {
            if(temp_stu[i].aver<temp_stu[j].aver)
            {
                temp_aver=temp_stu[i];
                temp_stu[i]=temp_stu[j];
                temp_stu[j]=temp_aver;
            }
        }
    }
    printf("Outstanding Students :\n");
    for(i=0;i<pt_outstand;i++)
    {
        puts(">----------------------------------<");
        printf("%dth : %s, Average score: %.2f\n",i+1,temp_stu[i].name,temp_stu[i].aver);
        if(i==pt_outstand-1)
            puts(">----------------------------------<");
    }
    return;
}
void sort_by_flunk_and_print(struct student *a,int pointer,int k)
{
    int i;
    if(k==1)printf("Student who fails in Mathematics : (%d)\n",pointer);
    if(k==2)printf("Student who fails in Chinese : (%d)\n",pointer);
    if(k==3)printf("Student who fails in English : (%d)\n",pointer);
    if(k==4)printf("Student who fails in Chemistry : (%d)\n",pointer);
    if(k==5)printf("Student who fails in Physics : (%d)\n",pointer);
    if(pointer==0)
        printf(" |----- No one fails !\n");
    else
    {
        if(k==1)
            for(i=0;i<pointer;i++)printf(" |%d|---- %s : %.2f\n",i+1,a[i].name,a[i].math);
        if(k==2)
            for(i=0;i<pointer;i++)printf(" |%d|---- %s : %.2f\n",i+1,a[i].name,a[i].chinese);
        if(k==3)
            for(i=0;i<pointer;i++)printf(" |%d|---- %s : %.2f\n",i+1,a[i].name,a[i].eng);
        if(k==4)
            for(i=0;i<pointer;i++)printf(" |%d|---- %s : %.2f\n",i+1,a[i].name,a[i].chemic);
        if(k==5)
            for(i=0;i<pointer;i++)printf(" |%d|---- %s : %.2f\n",i+1,a[i].name,a[i].phy);
    }
    printf("\n");
    return;
};
void Flunk_Students()
{
    int i;
    struct student fl_math[max_ammount];int pt1=0;
    struct student fl_chinese[max_ammount];int pt2=0;
    struct student fl_eng[max_ammount];int pt3=0;
    struct student fl_chemic[max_ammount];int pt4=0;
    struct student fl_phy[max_ammount];int pt5=0;
    for(i=0;i<pt;i++)
    {
        if(stu[i].math<60.0)
            fl_math[pt1++]=stu[i];
        if(stu[i].chinese<60.0)
            fl_chinese[pt2++]=stu[i];
        if(stu[i].eng<60.0)
            fl_eng[pt3++]=stu[i];
        if(stu[i].chemic<60.0)
            fl_chemic[pt4++]=stu[i];
        if(stu[i].phy<60.0)
            fl_phy[pt5++]=stu[i];
    }
    sort_by_flunk_and_print(fl_math,pt1,1);
    sort_by_flunk_and_print(fl_chinese,pt2,2);
    sort_by_flunk_and_print(fl_eng,pt3,3);
    sort_by_flunk_and_print(fl_chemic,pt4,4);
    sort_by_flunk_and_print(fl_phy,pt5,5);
    return;
};
void Show_Rankings()
{
    struct student temp_stu[max_ammount];
    int i,j,pt_outstand=pt;
    if(pt_outstand==0)
    {
        printf("None\n");
        return;
    }
    for(i=0;i<pt_outstand;i++)
        temp_stu[i]=stu[i];
    struct student struct_temp;
    for(i=0;i<pt_outstand-1;i++)
    {
        for(j=i+1;j<pt_outstand;j++)
        {
            if(temp_stu[i].aver<temp_stu[j].aver)
            {
                struct_temp=temp_stu[i];
                temp_stu[i]=temp_stu[j];
                temp_stu[j]=struct_temp;
            }
        }
    }
    printf("Rankings :\n");
    for(i=0;i<pt_outstand;i++)
    {
        puts(">----------------------------------<");
        printf("%dth -- %s :\nAverage : %.2f, Sum : %.2f\n",i+1,temp_stu[i].name,temp_stu[i].aver,temp_stu[i].sum);
        if(i==pt_outstand-1)
            puts(">----------------------------------<");
        printf("\n");
    }
    return;
};
void Modify_Data()
{
    Traverse_Data();
    printf("Please input which data you want to edit : ");
    int data_num;
    scanf("%d",&data_num);
    system("cls");
    Print_Data(data_num-1,1);
    printf("Which part do you want to edit ?\n");
    printf(" |-(1):ID |-(2):Name |-(3):Sex |-(4):Score \n |-Your selection : ");
    int part_num;
    scanf("%d",&part_num);
    if(part_num==1)
    {
        getchar();
        printf("Please input the new id : ");
        char newid[max_len];
        gets(newid);
        strcpy(stu[data_num-1].stu_id,newid);
        printf("Succeed !\n");
    }
    else if(part_num==2)
    {
        getchar();
        printf("Please input the new name : ");
        char newname[max_len];
        gets(newname);
        strcpy(stu[data_num-1].name,newname);
        printf("Succeed !\n");
    }
    else if(part_num==3)
    {
        printf("Input sex ( 1->Male : -1->Femail : 0->Unknown ) : ");
        scanf("%d",&stu[data_num-1].sex);
        printf("Succeed !\n");
    }
    else if(part_num==4)
    {
        int subject_num;
        float subject_score;
        printf("Please select the subject : \n");
        printf(" |-(1):Math |-(2):Chinese |-(3):English |-(4):Physics |-(5):Chemical \n |-Your selection : ");
        scanf("%d",&subject_num);
        printf("Input the score : ");
        scanf("%f",&subject_score);
        if(subject_num==1)
            stu[data_num-1].math=subject_score;
        else if(subject_num==2)
            stu[data_num-1].chinese=subject_score;
        else if(subject_num==3)
            stu[data_num-1].eng=subject_score;
        else if(subject_num==4)
            stu[data_num-1].phy=subject_score;
        else if(subject_num==5)
            stu[data_num-1].chemic=subject_score;
        printf("Succeed !\n");
    }
    int ptm=data_num-1;
    stu[ptm].sum = stu[ptm].math+stu[ptm].eng+stu[ptm].chinese+stu[ptm].phy+stu[ptm].chemic;
    stu[ptm].aver = (stu[ptm].sum)/5.0;
    printf("Data after modify : \n");
    Print_Data(data_num-1,1);
};
void Save_All()
{
    int i;
    FILE *fp_save;
    fp_save=fopen("Information.dtb", "wb");
    for(i=0;i<pt;i++)
    {
        fprintf(fp_save,"%s\n",stu[i].stu_id);fprintf(fp_save,"%s\n",stu[i].name);
        fprintf(fp_save,"%d\n",stu[i].sex);
        fprintf(fp_save,"%.2f %.2f %.2f %.2f %.2f",stu[i].math,stu[i].eng,stu[i].chinese,stu[i].phy,stu[i].chemic);
        if(i!=pt-1)
            fprintf(fp_save,"\n");
    }
    fclose(fp_save);
    return;
};
void profile_system();
void profile_system_Beta()
{
    while(1)
    {
        int i,j;
        char pass[max_len]="666";
        char input[max_len];
        printf(" |--- Login The System ---| \n");printf(" |--> Please Enter The Password : ");
        for(i=0;i<max_len;i++)
        {
            input[i]=_getch();
            if(input[i]=='\r')
            {
                input[i]='\0';
                break;
            }
            if(input[i]=='\b')
            {
                if(i==0)
                {
                    input[i]='\0';
                    i=-1;
                    continue;
                }
                else
                {
                    system("cls");
                    printf(" |--- Login The System ---| \n");printf(" |--> Please Enter The Password : ");
                    i-=2;
                    for(j=0;j<=i;j++)
                        putchar('*');
                    continue;
                }
            }
            else
                putchar('*');
        }
        system("cls");
        if(strcmp(pass,input)==0)
        {
            puts("Welcome Administrator !");
            break;
        }
    }
    return;
};
void Search_student()
{
    int i;
    printf("Choose the way of searching :\n");
    printf("|-- 1.By ID Number.\n");
    printf("|-- 2.By Name.\n");
    printf("|-- 0.Exit.\n");
    printf("Your selection : ");
    int selection;
    while(1)
    {
        scanf("%d",&selection);
        if(selection!=1&&selection!=2&&selection!=0)
        {
            printf("Invalid Number !\n");
            printf("Your selection : ");
        }
        else
            break;
    }
    if(selection==0)return;
    else if(selection==1)
    {
        printf("Input the ID number : ");
        char temp_id[max_len];
        getchar();
        gets(temp_id);
        int pt_id=-1;
        for(i=0;i<pt;i++)
            if(strcmp(temp_id,stu[i].stu_id)==0)
            {
                pt_id=i;
                break;
            }
        if(pt_id==-1)
            printf("No Such Student !\n");
        else
            Print_Data(pt_id,1);
    }
    else if(selection==2)
    {
        printf("Input the Name : ");
        char temp_name[max_len];
        getchar();
        gets(temp_name);
        int pt_id=-1;
        for(i=0;i<pt;i++)
            if(strcmp(temp_name,stu[i].name)==0)
            {
                pt_id=i;
                break;
            }
        if(pt_id==-1)
            printf("No Such Student !\n");
        else
            Print_Data(pt_id,1);
    }
    printf("Continue searching ? (1->Yes / 2->No) : ");
    while(1)
    {
        int continue_search;
        scanf("%d",&continue_search);
        if(continue_search==1)
        {
            system("cls");
            Search_student();
            return;
        }
        else if(continue_search==2)
        {
            return;
        }
    }
    return;
}
int main()
{
    //system("mode con cols=75 lines=45");
    system("title Supervisory System");system("color 0A");
    //printf("Immediate Time : ");system("TIME /T");
    FILE *fp;
    /*password code start*/
    
    profile_system_Beta();
    //profile_system();
    
    /*password code end*/
    fp=fopen("Information.dtb", "rb");
    while(fscanf(fp,"%s",stu[pt].stu_id)!=EOF)
    {
        fgetc(fp);
        fgets(stu[pt].name, max_len, (FILE*)fp);
        int pt_modi=strlen(stu[pt].name)-1;
        stu[pt].name[pt_modi]='\0';
        fscanf(fp,"%d",&stu[pt].sex);
        fscanf(fp,"%f %f %f %f %f",&stu[pt].math,&stu[pt].eng,&stu[pt].chinese,&stu[pt].phy,&stu[pt].chemic);
        calculate_sum_aver();
        pt++;
    }
    fclose(fp);
    Show_Function();
    while(1)
    {
        int function_number;int choose;
        scanf("%d",&function_number);
        system("cls");
        /*--------insert function code--------*/
        if(function_number==9)
        {
            break;
        }
        else if(function_number==1)
        {
            Traverse_Data();
        }
        else if(function_number==2)
        {
            Delete_Data();
        }
        else if(function_number==3)
        {
            Input_Data();
        }
        else if(function_number==4)
        {
            Search_student();
        }
        else if(function_number==5)
        {
            Show_Rankings();
        }
        else if(function_number==6)
        {
            Modify_Data();
        }
        else if(function_number==7)
        {
            Outstanding_Students();
        }
        else if(function_number==8)
        {
            Flunk_Students();
        }
        else
        {
            printf("Invalid function number !\n");
        }
        Save_All();
        /*--------end of function code--------*/
        while(1)
        {
            printf("Do you want to further manipulate the data? (1/Yes,2/No) : ");
            scanf("%d",&choose);
            system("cls");
            if(choose==1)
            {
                Show_Function();
                break;
            }
            else if(choose==2)
            {
                puts(" |--------------------------------------<\n |- Thankyou for using the software !\n |- Byebye~\n |--------------------------------------<\n");
                Save_All();
                system("pause");
                return 0;
            }
        }
    }
    puts(" |--------------------------------------<\n |- Thankyou for using the software !\n |- Byebye~\n |--------------------------------------<\n");
    Save_All();
    system("pause");
    return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
//global structure for employee
typedef struct{
    int id;
    char name[30];
    char designation[30];
    int salary;
    double accuracy;
    char user_pass[20];
}employee;

//global structure array

employee check_details[3];
int emNum = 3;

int employeeLimit(int en){
    check_details[en];
    emNum = en;
}

void addemployee(){
    FILE *addEm = fopen("Current_Employee.txt", "a");
    int temp;


    for( int j = 4 ; j > 0 ; j++){
        printf(">>>>> Please, enter the identification number : ");
        scanf("%d", &temp);
        printf("\n\n");
        emNum = temp;
        employeeLimit(j);
        check_details[j-1].id = temp; // auto id assign
        printf(">>>>> Employee Name : ");
        getchar();
        scanf("%[^\n]", check_details[j-1].name);
        getchar();
        printf(">>>>> Employee Designation : ");
        scanf("%[^\n]", check_details[j-1].designation);
        printf(">>>>> Employee Salary : ");
        scanf("%d", &check_details[j-1].salary);
        getchar();
        printf(">>>>> Employee Password : ");
        scanf("%[^\n]", check_details[j-1].user_pass);
        printf(">>>>> Initial Acuurecy: ");
        scanf("%lf", &check_details[j-1].accuracy);
        fprintf(addEm, "Identification Number : %d\nEmployee's Name : %s\nEmployee's Designation : %s\nEmployee's Salary : %d\nEmployee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[j-1].id, check_details[j-1].name, check_details[j-1].designation, check_details[j-1].salary, check_details[j-1].accuracy);
        fclose(addEm);
        printf(">>>>> Press 1 to add another employee\n>>>>> Press 2 to end\n");
        int d;
        scanf("%d", &d);

        if(d == 2){
            break;
        }


    }
}

int employee_details(int n, int who){
    printf("Please enter the Identification number: ");
    scanf("%d", &who);
    system("cls");
    printf("\t\t\t\t\t\t\t----------Employee's Personal Data----------\n");
    printf("\t\t\t\t\t\t\t____________________________________________\n\n\n");
    printf("\t\t\t\t\t\t\t  Identification Number : %d\n", check_details[who-1].id);
    printf("\t\t\t\t\t\t\t  Employee's Name : %s\n", check_details[who-1].name);
    printf("\t\t\t\t\t\t\t  Employee's Designation : %s\n", check_details[who-1].designation);
    printf("\t\t\t\t\t\t\t  Employee's Salary : %d\n", check_details[who-1].salary);
    printf("\t\t\t\t\t\t\t  Employee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[who-1].accuracy);
    printf("Press 1 to go back\n");
    scanf("%d", &n);
    return n;
}

int resign(int who){
    FILE *reg = fopen("resign.txt", "a");
    printf("Good bye %s :(\n\n", check_details[who-1].name);
    strcpy(check_details[who-1].designation, "N/A (resigned)");
    check_details[who-1].salary = 0;
    check_details[who-1].accuracy = 0.00;
    fprintf(reg, "Identification Number : %d\nEmployee's Name : %s\nEmployee's Designation : %s\nEmployee's Salary : %d\nEmployee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[who-1].id, check_details[who-1].name, check_details[who-1].designation, check_details[who-1].salary, check_details[who-1].accuracy);
    fclose(reg);
    printf("Your all information has been successfully removed from the system database\n\n");
    sleep(4);
}

void default_initialize(){
    FILE *fp = fopen("Current_Employee.txt", "w");
    //int del;
    int iD = 1, Salary = 40000;
    double per = 60.24;
    for(int i = 0; i < 3; i++){
        check_details[i].id = iD, check_details[i].salary = Salary, check_details[i].accuracy = per;
        if(i == 0){
            strcpy(check_details[i].name, "Munimah Mahereen");
            strcpy(check_details[i].designation, "Senior Software Engineer");
            strcpy(check_details[i].user_pass, "legendary##");
        }
        if(i == 1){
            strcpy(check_details[i].name, "Md. Zidny");
            strcpy(check_details[i].designation, "Senior Software Engineer");
            strcpy(check_details[i].user_pass, "lyfischill!!");
        }
        if(i == 2){
            strcpy(check_details[i].name, "Mohammad Azmee Tofail");
            strcpy(check_details[i].designation, "Junior Software Engineer");
            strcpy(check_details[i].user_pass, "intro$$");
        }
        iD++, Salary -= 2000, per -= 2.78;
        fprintf(fp, "Identification Number : %d\nEmployee's Name : %s\nEmployee's Designation : %s\nEmployee's Salary : %d\nEmployee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[i].id, check_details[i].name, check_details[i].designation, check_details[i].salary, check_details[i].accuracy);
    }
    fclose(fp);
}

void modify_by_admin(){
    FILE *mod = fopen("modify.txt", "a");
    printf("\t\t\t\t\t\t-------------Welcome to the modify Section-------------\n\n\n");
    int identification;
    back:
    printf(">>>>> Please, enter the identification number: ");
    scanf("%d", &identification);
    printf("\n\n");
    if(identification > emNum){
        printf("No Employee exist!\n");
        goto back;
    }
    while(1){
        printf(">>>>> Press 1 for updating designation\n\n");
        printf(">>>>> Press 2 for updating updating salary\n\n");
        printf(">>>>> Press 3 for update the accuracy level\n\n");
        printf(">>>>> Press anykey to stop!\n\n");
        int opr;
        scanf("%d", &opr);
        getchar();
        if(opr != 1 && opr != 2 && opr!= 3){
            fprintf(mod, "Identification Number : %d\nEmployee's Name : %s\nEmployee's Designation : %s\nEmployee's Salary : %d\nEmployee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[identification-1].id, check_details[identification-1].name, check_details[identification-1].designation, check_details[identification-1].salary, check_details[identification-1].accuracy);
            fclose(mod);
            break;
        }
        else if(opr == 1)
            scanf("%[^\n]", check_details[identification-1].designation);
        else if(opr == 2)
            scanf("%d", &check_details[identification-1].salary);
        else if(opr == 3)
            scanf("%lf", &check_details[identification-1].accuracy);
    }
}

void view_specific(){
    printf("\t\t\t\t\t\t-------------Welcome to the Specific Employee Section-------------\n\n\n");
    int identification;
    ret:
    printf(">>>>> Please, enter the identification number: ");
    scanf("%d", &identification);
    printf("\n\n");
    if(identification > emNum){
        printf("No Employee exist!\n");
        goto ret;
    }
    printf("\t\t\t\t\t\t\t----------Employee's Personal Data----------\n");
    printf("\t\t\t\t\t\t\t____________________________________________\n\n\n");
    printf("\t\t\t\t\t\t\t  Identification Number : %d\n", check_details[identification-1].id);
    printf("\t\t\t\t\t\t\t  Employee's Name : %s\n", check_details[identification-1].name);
    printf("\t\t\t\t\t\t\t  Employee's Designation : %s\n", check_details[identification-1].designation);
    printf("\t\t\t\t\t\t\t  Employee's Salary : %d\n", check_details[identification-1].salary);
    printf("\t\t\t\t\t\t\t  Employee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[identification-1].accuracy);
    printf(">>>>> For modify press 1 for return press 0\n");
    printf(">>>>> ");
    scanf("%d", &identification);
    if(identification == 1)
        modify_by_admin();
}

void delet(){
    FILE *rus = fopen("Rustricated_list", "a");
    printf("\t\t\t\t\t\t\t--------- Rusticated Section! ---------\n\n");
    int identifiation;
    printf(">>>>> Please, enter the identification number: ");
    scanf("%d", &identifiation);
    strcpy(check_details[identifiation-1].name, "Suspend!");
    strcpy(check_details[identifiation-1].designation, "N/A");
    check_details[identifiation-1].salary = 0;
    check_details[identifiation-1].accuracy = 0.00;
    strcpy(check_details[identifiation-1].user_pass, "byebye");
    fprintf(rus, "Identification Number : %d\nEmployee's Name : %s\nEmployee's Designation : %s\nEmployee's Salary : %d\nEmployee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[identifiation-1].id, check_details[identifiation-1].name, check_details[identifiation-1].designation, check_details[identifiation-1].salary, check_details[identifiation-1].accuracy);
    fclose(rus);
    printf(">>>> Operation done successfully!\n");
    sleep(3);

}

void file(){

    FILE *fp = fopen("Current_Employee.txt", "w");


for(int i = 0; i < emNum; i++){
    printf("\t\t\t\t\t\t\t  Identification Number : %d\n", i+1);
    printf("\t\t\t\t\t\t\t  Employee's Name : %s\n", check_details[i].name);
    printf("\t\t\t\t\t\t\t  Employee's Designation : %s\n", check_details[i].designation);
    printf("\t\t\t\t\t\t\t  Employee's Salary : %d\n", check_details[i].salary);
    printf("\t\t\t\t\t\t\t  Employee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[i].accuracy);

    fprintf(fp, "Identification Number : %d\nEmployee's Name : %s\nEmployee's Designation : %s\nEmployee's Salary : %d\nEmployee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[i].id, check_details[i].name, check_details[i].designation, check_details[i].salary, check_details[i].accuracy);
}
fclose(fp);


}


void main()
{
    int del, who;
    printf("\n\n\n");
    char em_pass[5] = "game";
    char ad_pass[11] = "superadmin";
    default_initialize();
    res:
    system("cls");
    printf("\t\t\t\t\t ---------------------------Welcome to TIGER IT---------------------------\n");
    printf("\t\t\t\t\t _________________________________________________________________________\n\n\n");
    printf("\t\t\t\t\t\t\t  For Details please login [limited access]\n");
    printf("\t\t\t\t\t\t\t\tPress 1 to login as an Employee\n");
    printf("\t\t\t\t\t\t\t\tPress 2 to login as an Admin\n");
    printf("\t\t\t\t\t   Caution! Press without any of this will gonna be stop this programm\n\n");
    printf(">>>>> Your Choice: ");
    int x;
    scanf("%d", &x);
    switch(x){
        case 1: ;
        //Employee
            char pas[13];
            printf(">>>>> Password : ");
            scanf("%s", pas);
            int yes = strcmp(pas, em_pass);
            if(yes == 0){
                level1:
                system("cls");
                printf("\t\t\t\t\t\t-------------Welcome to the Employee Section-------------\n");
                printf("\t\t\t\t\t\t_________________________________________________________\n\n\n");
                printf("\t\t\t\t\t\t\tHere 3 types of operation can be execute\n");
                printf("\t\t\t\t\t\t\t\t  1. Check Details\n");
                printf("\t\t\t\t\t\t\t\t  2. Resign\n");
                printf("\t\t\t\t\t\t\t\t  3. Return Main Menu\n");
                printf(">>>>> Your Choice: ");
                int n;
                scanf("%d", &n);
                if(n == 3)
                    goto res;
                switch(n){
                    case 1:
                    //check details
                        n = employee_details(n,who);
                        if(n == 1)
                            goto level1;
                        else{
                            printf("Wrong keyword! Programm Terminated\n");
                            exit(0);
                        }
                    case 2:
                    //Resign
                        printf("Please enter the Identification number: ");
                        scanf("%d", &who);
                        printf(">>>>> Password: ");
                        scanf("%s", pas);
                        yes = strcmp(pas, check_details[who-1].user_pass);
                        if(yes == 0){
                            printf("\t\t\t\t\t\t\t  Are you sure you want to resign? Y/N\n");
                            printf("\t\t\t\t\t\tCaution! It can't be undone (Becareful! Not case sensitive)\n");
                            getchar();
                            char var;
                            scanf("%c", &var);
                            if(var == 'Y' || var =='y'){
                                resign(who);
                                del = who-1;
                                //sleep(3);
                                file();
                                goto res;
                            }
                            else if(var == 'N' || var == 'n'){
                                system("cls");
                                goto res;
                            }
                            else{
                                system("cls");
                                printf("Wrong Keyword!\n");
                                printf("Programm Terminated!!\n");
                                exit(0);
                            }
                        }
                        else{
                            //system("cls");
                            printf("Access Denied, Wrong Password!\n");
                            printf("You maybe rusticated!\n");
                            printf("Contact with your system administrator.\n");
                            printf("Returning Main Menu...........");
                            sleep(6);
                            goto res;
                        }
                    default:
                        printf("Thanks for your Interest\n\n");
                        exit(0);
                }
            }
            else{
                printf("Access Denied, Wrong Password!\n");
                printf("Returning Main Menu..........");
                sleep(3);
                goto res;
            }
        case 2: ;
        //admin
            //system("clr");
            printf(">>>>> Password : ");
            char check_pas[11];
            scanf("%s", check_pas);
            int verify = strcmp(check_pas, ad_pass);
            if(verify == 0){
                printf("\t\t\t\t\t\t\t---------Welcome to the Admin Section---------\n");
                printf("\t\t\t\t\t\t\t______________________________________________\n\n\n");
                printf("\t\t\t\t\t\t\t  Here 5 types of operation can be execute\n");
                printf("\t\t\t\t\t\t\t\t\t1. Add New Employee\n");
                printf("\t\t\t\t\t\t\t\t\t2. Employee List\n");
                printf("\t\t\t\t\t\t\t\t\t3. View Specific Employee\n");
                printf("\t\t\t\t\t\t\t\t\t4. Update Status\n");
                printf("\t\t\t\t\t\t\t\t\t5. Delet\n");
                printf("\t\t\t\t\t\t\t\t\t6. Log out\n");
                printf(">>>>> Your Choice: ");
                scanf("%d", &verify);
                if(verify == 1){
                    //add new employee
                    printf("\t\t\t\t\t\t-------------Welcome to the employee adding Section-------------\n\n\n\n");
                    addemployee();
                    file();
                    goto res;
                }
                else if(verify == 2){
                    //employee list
                    system("cls");
                    printf("\t\t\t\t\t\t\t----------Employee's Personal Data----------\n\n");
                    for(int i = 0; i < emNum; i++){
                        printf("\t\t\t\t\t\t\t  Identification Number : %d\n", i+1);
                        printf("\t\t\t\t\t\t\t  Employee's Name : %s\n", check_details[i].name);
                        printf("\t\t\t\t\t\t\t  Employee's Designation : %s\n", check_details[i].designation);
                        printf("\t\t\t\t\t\t\t  Employee's Salary : %d\n", check_details[i].salary);
                        printf("\t\t\t\t\t\t\t  Employee's accuracy : %0.2lf%% Accuracy\n\n\n", check_details[i].accuracy);
                    }
                    printf(">>>>> press 1 to go back : ");
                    scanf("%d", &verify);
                    if(verify == 1)
                        goto res;
                    else{
                        printf("Wrong keyword\n");
                        exit(0);
                    }
                }
                else if(verify == 3){
                    //specific em.
                    view_specific();
                    goto res;
                }
                else if(verify == 4){
                    //modify
                    modify_by_admin();
                    file();
                    goto res;
                }
                else if(verify == 5){
                    //rusticate
                    delet();
                    file();
                    goto res;
                }
                else if(verify == 6)
                    goto res;
            }
            else{
                printf("Access Denied, Wrong Password\n");
                printf("Returning Main Menu...........");
                sleep(3);
                goto res;
            }

        //admin
            break;
        default:
            printf("Thanks for your Interest\n\n");
    }
    exit(0);
}

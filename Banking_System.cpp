#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct account
{
    int accno;
    char name[100];
    int password;
    int avb;
};
int i = 0;
int failure_admin = 0;
int failure_user = 0;
struct account ac[10];
void heading()
{
    printf("***********************************************************************************************************************************************************\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t");
    printf("BANKING SYSTEM\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("***********************************************************************************************************************************************************\n");
    printf("\n");
}

int random(int h, int l)
{
    int num = (rand()%(h-l+1)) + l;
    return num;
}

int admin()
{
    int p, f = 0;
    int y = 1;
    heading();
    printf("Enter admin password:\n");
    scanf("%d",&p);
    system("cls");
    heading();
    if(p==1234)
    {
        int ch;
        while(1)
        {
            printf("\t\t\t\t\t\t\t\tWELCOME ADMIN!\n\n");
            printf("\t\t\t\t\t\t\t\t1. Open Account\n");
            printf("\t\t\t\t\t\t\t\t2. Close Account\n");
            printf("\t\t\t\t\t\t\t\t3. Exit from Admin Mode\n");
            printf("\nEnter your choice:\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                if(i!=9)
                {
                    printf("Enter account number:\n");
                    scanf("%d",&ac[i].accno);
                    for(int b = 0;b<i;b++)
                    {
                        if(ac[i].accno == ac[b].accno)
                        {
                            printf("Account number already exits!\n");
                            continue;
                        }
                    }
                    printf("Enter name:\n");
                    scanf("%s",ac[i].name);
                    ac[i].password = random(1000, 9999);
                    ac[i].avb = 1000;
                    printf("Password: %d\n", ac[i].password);
                    printf("Account created successfully\n");
                    i++;
                    printf("Do you want to continue? Press 1 to continue and 0 to exit admin mode\n");
                    scanf("%d",&y);
                    if(y==1)
                    {
                        system("cls");
                        heading();
                        continue;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    printf("Account Limit Reached!\n");
                }
                break;
                case 2:
                int a;
                printf("Enter account number:\n");
                scanf("%d",&a);
                for(int b = 0;b<i;b++)
                {
                    if(a==ac[b].accno)
                    {
                        f = 1;
                        ac[b].accno = 0;
                        char x[100];
                        strcpy(x, ac[b].name);
                        int t = 0;
                        while(x[t]!='\0')
                        {
                            x[t] = '\0';
                            t++;
                        }
                        strcpy(ac[b].name, x);
                        ac[b].avb = 0;
                        ac[b].password = 0;
                    }
                }
                if(f==0)
                {
                    printf("Account not found!\n");
                    continue;
                }
                printf("Do you want to continue? Press 1 to continue and 0 to exit admin mode\n");
                scanf("%d",&y);
                if(y==1)
                {
                    system("cls");
                    heading();
                    continue;
                }
                else
                {
                    return 0;
                }
                break;
                case 3:
                return 0;
                default:
                printf("Invalid Choice\n");
            }
        }
    }
    else
    {
        failure_admin++;
        if(failure_admin <= 3)
        {
            printf("Incorrect Password! Press 1 to try again and 0 to exit admin mode\n");
            scanf("%d",&y);
            if(y==1)
            {
                system("cls");
                admin();
            }
            else
            {
                return 0;
            }
        }
        else
        {
            printf("3 incorrect attempts!!! Terminating Program....");
            exit(0);
        }
    }
}

void deposit(int a)
{
    int d, f = 0;
    printf("Enter amount to be deposited:\n");
    scanf("%d",&d);
    for(int b= 0;b<i;b++)
    {
        if(a==ac[b].accno)
        {
            f = 1;
            ac[b].avb = ac[b].avb + d;
            printf("Rs. %d has been deposited to your account successfully\n",d);
            break;
        }
    }
    if(f==0)
    {
        printf("Account not found!\n");
    }
}

void withdraw(int a)
{
    int w, f = 0;
    printf("Enter amount to be withdrawn:\n");
    scanf("%d",&w);
    for(int b = 0;b<i;b++)
    {
        f = 1;
        if(a==ac[b].accno)
        {
            if(w <= (ac[b].avb - 1000))
            {
                ac[b].avb = ac[b].avb - w;
                printf("Rs. %d has been withdrawn from your account successfully\n",w);
                break;
            }
            else
            {
                printf("Insufficient Balance! Minimum balance must be Rs. 1000\n");
            }
        }
    }
    if(f==0)
    {
        printf("Account not found!\n");
    }
}

void details(int a)
{
    int f = 0;
    printf("\n\t\t\t\t\t\t\t\tACCOUNT DETAILS\n");
    for(int b = 0;b<i;b++)
    {
        if(a==ac[b].accno)
        {
            f = 1;
            printf("\n");
            printf("\t\t\t\t\t\t\t\tAccount Number: %d\n",ac[b].accno);
            printf("\t\t\t\t\t\t\t\tName: %s\n",ac[b].name);
            printf("\t\t\t\t\t\t\t\tBalance: Rs. %d\n\n",ac[b].avb);
            break;
        }
    }
    if(f==0)
    {
        printf("Account not found!\n");
    }
}

int user()
{
    int a, f = 0;
    int ch, p;
    int y = 0;
    heading();
    printf("Enter account number:\n");
    scanf("%d",&a);
    printf("Enter password:\n");
    scanf("%d",&p);
    for(int b = 0;b<i;b++)
    {
        if(a==ac[b].accno)
        {
            if(p==ac[b].password)
            {
                printf("\n");
                strupr(ac[b].name);
                system("cls");
                heading();
                printf("\t\t\t\t\t\t\t\tWELCOME %s\n\n", ac[b].name);
                f = 1;
                while(1)
                {
                    printf("\t\t\t\t\t\t\t\t1. Deposit\n");
                    printf("\t\t\t\t\t\t\t\t2. Withdraw\n");
                    printf("\t\t\t\t\t\t\t\t3. Display Balance and Details\n");
                    printf("\t\t\t\t\t\t\t\t4. Exit from User Mode\n");
                    printf("\nEnter your choice:\n");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1:
                        deposit(ac[b].accno);
                        details(ac[b].accno);
                        printf("Do you want to continue? Press 1 to continue and 0 to exit user mode\n");
                        scanf("%d",&y);
                        if(y==1)
                        {
                            continue;
                        }
                        else
                        {
                            system("cls");
                            return 0;
                        }
                        break;
                        case 2:
                        withdraw(ac[b].accno);
                        details(ac[b].accno);
                        printf("Do you want to continue? Press 1 to continue and 0 to exit user mode\n");
                        scanf("%d",&y);
                        if(y==1)
                        {
                            continue;
                        }
                        else
                        {
                            system("cls");
                            return 0;
                        }
                        break;
                        case 3:
                        details(ac[b].accno);
                        printf("Do you want to continue? Press 1 to continue and 0 to exit user mode\n");
                        scanf("%d",&y);
                        if(y==1)
                        {
                            continue;
                        }
                        else
                        {
                            system("cls");
                            return 0;
                        }
                        break;
                        case 4:
                        system("cls");
                        return 0;
                        break;
                        default:
                        printf("Invalid Choice\n");
                    }
                }
            }
            else
            {
                failure_user++;
                if(failure_user <= 3)
                {
                    printf("Incorrect Password! Press 1 to try again and 0 to exit user mode.\n");
                    scanf("%d",&y);
                    if(y==1)
                    {
                        system("cls");
                        user();
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    printf("3 incorrect attempts!!! Terminating program....\n");
                    exit(0);
                }
            }
        }
    }
    if(f==0)
    {
        printf("Account not found!\n");
    }
}

int main()
{
    int x = 1;
    while(1)
    {
        printf("\n");
        heading();
        int ch;
        printf("\t\t\t\t\t\t\t\t1. Admin Mode\n");
        printf("\t\t\t\t\t\t\t\t2. User Mode\n");
        printf("\t\t\t\t\t\t\t\t3. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            system("cls");
            x = admin();
            system("cls");
            break;
            case 2:
            system("cls");
            user();
            break;
            case 3:
            printf("Program Ends\n");
            exit(0);
            default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}

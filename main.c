#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct account
{
    char first_name[20];
    char last_name[20];
    char mail[40];
    char account[15];
    char city[15];
    char pincode[10];
    char cr_dr[5];
    char reason[15];
    int balance;
    char pin[6];

    int acc_date,acc_month,acc_year,acc_hour,acc_minute;
};

int choice,i;

struct account user;

char account_no[15],name[20];

int main()
{
    system("title Varun Banking");
    system("color fc");
    choice_error:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tVarun Banking\n");
    printf("\n\t   YouTube.com/VarunTeja\n");
    printf("______________________________________________");
    printf("\n\n");
    printf("\t1.Guest");
    printf("\n\n\t2.User");
    printf("\n\n\t3.Admin");
    printf("\n\n\t4.Exit");
    printf("\n");
    printf("______________________________________________");
    printf("\n\n\nChoice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        guest();
        break;
    case 2:
        user_login();
        break;
    case 3:
        admin_login();
        break;
    case 4:
        break;
    default:
        goto choice_error;
    }
    return 0;
}

void user_login()
{
    int found=0,pin_check=0,main_menu=0,menu_user=0;
    char cpin[6],ch;
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Account No : ");
    scanf("%s",account_no);
    FILE *accounts;
    accounts=fopen("users.txt","r");
    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);

        if(strcmp(account_no,user.account)==0)
        {
            found=1;
            pin_mismatch:
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\t Pin : ");
            i=0;
            while(1)
    {
        ch=getch();
        if(ch==13)
        {
            cpin[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            cpin[i]=ch;
            i++;
            printf("*");
        }
    }
            if(strcmp(cpin,user.pin)!=0)
            {
                system("cls");
                printf("______________________________________________");
                printf("\n\n\t   Validating Credentials");
                for(i=0;i<3;i++)
                {
                    printf(".");
                    Sleep(1500);
                }

                choice_error:
                system("cls");
                printf("______________________________________________");
                printf("\n\n\tIncorrect Pin");
                printf("\n");
                printf("______________________________________________");
                printf("\n\n1.Retry With Correct pin");
                printf("\n\n2.Main menu");
                printf("\n\nChoice :");
                scanf("%d",&choice);

                switch(choice)
            {
            case 1:
                goto pin_mismatch;
                break;
            case 2:
                main_menu=1;
                break;
            default:
                goto choice_error;
            }
            }
            else
            {
                strcpy(name,user.first_name);
                menu_user=1;
            }
        }
    }

    fclose(accounts);

    if(found==0)
    {
        choice_error_1:
        system("cls");
        printf("______________________________________________");
        printf("\n");
        printf("\n\t   Account Does not exist");
        printf("\n");
        printf("______________________________________________");
        printf("\n\n1.Retry with correct Account no");
        printf("\n\n2.Create Account");
        printf("\n\n3.Main menu");
        printf("\n");
        printf("______________________________________________");
        printf("\n\nChoice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            user_login();
            break;
        case 2:
            create_account();
            break;
        case 3:
            main();
            break;
        default:
            goto choice_error_1;
        }
    }

    if(main_menu==1)
    {
        main();
    }

    if(menu_user==1)
    {
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t   Validating Credentials");
        for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }
        user_menu();
    }

}

void user_menu()
{
    system("color f0");
    choice_error:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tWelcome %s\n",name);
    printf("______________________________________________");
    printf("\n\n");
    printf("\n\t1.Check Balance");
    printf("\n\n\t2.Deposit Money");
    printf("\n\n\t3.Withdraw Money");
    printf("\n\n\t4.Fund Transfer");
    printf("\n\n\t5.Mini Statement");
    printf("\n\n\t6.Pin Change");
    printf("\n\n\t7.Close Account");
    printf("\n\n\t8.Main Menu");
    printf("\n\n\t9.View Details");
    printf("\n\n");
    printf("______________________________________________");
    printf("\n\nChoice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        check_balance();
        break;
    case 2:
        deposit();
        break;
    case 3:
        withdraw();
        break;
    case 4:
        transfer();
        break;
    case 5:
        mini_statement();
        break;
    case 6:
        pin_change();
        break;
    case 7:
        close_account();
        break;
    case 8:
        main();
        break;
    case 9:
        account_details();
        break;
    default:
        goto choice_error;
    }
}

void mini_statement()
{
    int balance;
    FILE *accounts,*statement;
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)==0)
        {
           balance=user.balance;
        }
    }
    fclose(accounts);
    system("cls");
    printf("_______________________________________________");
    printf("\n\n\tFetching Transaction Details");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(2000);
        }

    system("cls");
    printf("_______________________________________________________________________");
    printf("\n\n\t\t\t\tMini Statment\n");
    printf("\n   Account No : %s   Name : %s   Balance : %d\n",user.account,name,balance);
    printf("_______________________________________________________________________");
    printf("\n\n\tDate\t\tTime\t\tAmount\t\tReason\n");

    statement=fopen("transactions.txt","r");

    while(!feof(statement))
    {
       fscanf(statement,"%s %s %d %d %d %d %d %d %s\n",user.account,user.cr_dr,&user.balance,&user.acc_date,&user.acc_month,&user.acc_year,&user.acc_hour,&user.acc_minute,user.reason);
       if(strcmp(account_no,user.account)==0)
       {
           printf("\n\t%d/%d/%d \t%d:%d \t\t%s %d \t\t%s\n",user.acc_date,user.acc_month,user.acc_year,user.acc_hour,user.acc_minute,user.cr_dr,user.balance,user.reason);

       }
    }

    fclose(statement);
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)==0)
        {
           balance=user.balance;
        }
    }
    fclose(accounts);

    printf("_______________________________________________________________________");
    printf("\n\n\t\t\tFinal Balance : %d\n\n",balance);
    printf("_______________________________________________________________________");

    getch();
    user_menu();
}

void transfer()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    char receiver_account[20],receiver_name[20];
    int found_receiver_account=0,confirm=0,transfer_amount,insufficent=0,sufficent=0,valid=0,acc_matched=0;

    system("cls");
    printf("______________________________________________");
    printf("\n\n\tReceiver Account No : ");
    scanf("%s",receiver_account);
    FILE *accounts,*temp,*statement;
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);

        if(strcmp(receiver_account,user.account)==0)
        {
            found_receiver_account=1;
            strcpy(receiver_name,user.first_name);

        }
    }

    fclose(accounts);

    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);

        if(strcmp(receiver_account,user.account)==0)
        {
            if(strcmp(receiver_account,account_no)==0)
            {
                acc_matched=1;
            }

        }
    }

    fclose(accounts);

    if(found_receiver_account==0)
    {
        choice_error:
        system("cls");
        printf("______________________________________________");
        printf("\n");
        printf("\n\t   Account Does not exist");
        printf("\n");
        printf("______________________________________________");
        printf("\n\n1.Retry with correct Account no");
        printf("\n\n2.User menu");
        printf("\n\n3.Main menu");
        printf("\n");
        printf("______________________________________________");
        printf("\n\nChoice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            transfer();
            break;
        case 2:
            user_menu();
            break;
        case 3:
            main();
            break;
        default:
            goto choice_error;
        }
    }

    if(found_receiver_account==1 && acc_matched==1)
    {
        choice_error_1:
        system("cls");
        printf("______________________________________________");
        printf("\n\n  You can't transfer money to your account\n\n");
        printf("______________________________________________");
        printf("\n\n1.Retry with correct Account no");
        printf("\n\n2.User menu");
        printf("\n");
        printf("______________________________________________");
        printf("\n\nChoice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            transfer();
            break;
        case 2:
            user_menu();
            break;
        default:
            goto choice_error_1;
        }
    }

    if(found_receiver_account==1 && acc_matched==0)
    {
        choice_error_2:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t\tConfirm Account");
        printf("\n\n\tName       : %s",receiver_name);
        printf("\n\n\tAccount no : %s",receiver_account);
        printf("\n\n");
        printf("______________________________________________");
        printf("\n\n1.Confirm");
        printf("\n\n2.Change account no");
        printf("\n\n3.User menu");
        printf("\n\n\nChoice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            confirm=1;
            break;
        case 2:
            transfer();
            break;
        case 3:
            user_menu();
            break;
        default:
            goto choice_error_2;
        }
    }

    if(found_receiver_account==1 && acc_matched==0 && confirm==1)
    {
        amount_again:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tTransfer Amount : ");
        scanf("%d",&transfer_amount);

        if(transfer_amount>0)
        {
            valid=1;
        }
        else
        {
            valid=0;
        }

        if(valid==0)
    {
        choice_error_3:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t\tInvalid Amount\n");
        printf("______________________________________________");
        printf("\n\n1.Enter Amount Again");
        printf("\n\n2.Main Menu");
        printf("\n\nChoice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            goto amount_again;
            break;
        case 2:
            main();
            break;
        default:
            goto choice_error_3;
        }
    }
    }

    if(found_receiver_account==1 && acc_matched==0 && confirm==1 && valid==1)
    {
        accounts=fopen("users.txt","r");

        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)==0)
        {
            if(transfer_amount<user.balance)
            {
                sufficent=1;
            }
            else
            {
                insufficent=1;
            }
        }
    }

     fclose(accounts);

    }

    if(found_receiver_account==1 && acc_matched==0 && confirm==1 && valid==1 && insufficent==1)
    {
        choice_error_4:
        system("cls");
        printf("______________________________________________");
        printf("\n\n   Insufficient Balance In Your account");
        printf("\n\n");
        printf("______________________________________________");
        printf("\n\n\t1.Check Balance");
        printf("\n\n\t2.Enter amount again");
        printf("\n\n\t3.User menu");
        printf("\n\n\t4.Main menu");
        printf("\n\n");
        printf("______________________________________________");
        printf("\n\nChoice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            check_balance();
            break;
        case 2:
            insufficent=0;
            goto amount_again;
            break;
        case 3:
            user_menu();
            break;
        case 4:
            main();
            break;
        default:
            goto choice_error_4;
        }
    }

    if(found_receiver_account==1 && acc_matched==0 && confirm==1 && valid==1 && sufficent==1)
    {
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,(user.balance-transfer_amount),user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }

    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");

    accounts=fopen("users.txt","r");
    temp=fopen("temp.txt","w");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(receiver_account,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,(user.balance+transfer_amount),user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }

    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");

    statement=fopen("transactions.txt","a");
    fprintf(statement,"%s - %d %d %d %d %d %d ByTransfer\n",account_no,transfer_amount,time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
    fclose(statement);

    statement=fopen("transactions.txt","a");
    fprintf(statement,"%s + %d %d %d %d %d %d ByTransfer\n",receiver_account,transfer_amount,time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
    fclose(statement);

    system("cls");
    printf("______________________________________________");
    printf("\n\n    Your transaction is being processed");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }

    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Amount Transferred\n");
    printf("\n");
    printf("______________________________________________");
    printf("\n");
    Sleep(3000);
    user_menu();
    }

}

void pin_change()
{
    char pin[6],cpin[6],ch;
    pin_mismatch:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\tNew pin      : ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            pin[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            pin[i]=ch;
            i++;
            printf("*");
        }
    }

    i=0;

    printf("\n\n\tConfirm Pin  : ");
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            cpin[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            cpin[i]=ch;
            i++;
            printf("*");
        }
    }

    if(strcmp(cpin,pin)!=0)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\tPin Not Matched\n");
            printf("\n\t\tEnter it Again\n");
            printf("______________________________________________");
            printf("\n");
            Sleep(2500);
            goto pin_mismatch;
        }
    FILE *accounts,*temp;
    accounts=fopen("users.txt","r");
    temp=fopen("temp.txt","w");
    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");

    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tChanging Pin");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }

    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tPin changed\n");
    printf("\n");
    printf("______________________________________________");
    printf("\n");
    Sleep(3000);
    user_menu();
}

void withdraw()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    int withdraw_amount,insufficent=0,sufficent=0,valid=0;

    amount_again:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\tWithdraw Amount : ");
    scanf("%d",&withdraw_amount);

    if(withdraw_amount>0)
        {
            valid=1;
        }

    if(valid==0)
    {
        choice_error:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t\tInvalid Amount\n");
        printf("______________________________________________");
        printf("\n\n1.Enter Amount Again");
        printf("\n\n2.Main Menu");
        printf("\n\nChoice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            valid=1;
            goto amount_again;
            break;
        case 2:
            user_menu();
            break;
        default:
            goto choice_error;
        }
    }

    if(valid==1)
    {
    FILE *accounts,*temp,*statement;
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)==0)
        {
            if(withdraw_amount>user.balance)
            {
                insufficent=1;
            }
            else
            {
                sufficent=1;
            }
        }
    }

    fclose(accounts);

    if(sufficent==1)
    {
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,(user.balance-withdraw_amount),user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
        fclose(accounts);
        fclose(temp);
        remove("users.txt");
        rename("temp.txt","users.txt");

        statement=fopen("transactions.txt","a");
        fprintf(statement,"%s - %d %d %d %d %d %d Withdrawn\n",account_no,withdraw_amount,time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
        fclose(statement);

        system("cls");
        printf("______________________________________________");
        printf("\n\n    Your transaction is being processed");
        for(i=0;i<3;i++)
            {
                printf(".");
                Sleep(1500);
            }

        system("cls");
        printf("______________________________________________");
        printf("\n\n\t   Amount Withdrawn\n");
        printf("\n");
        printf("______________________________________________");
        printf("\n");
        Sleep(4000);
        user_menu();
    }

    if(insufficent==1)
    {
        choice_error_1:
        system("cls");
        printf("______________________________________________");
        printf("\n\n   Insufficient Balance In Your account");
        printf("\n\n");
        printf("______________________________________________");
        printf("\n\n\t1.Check Balance");
        printf("\n\n\t2.Enter amount again");
        printf("\n\n\t3.User menu");
        printf("\n\n\t4.Main menu");
        printf("\n\n");
        printf("______________________________________________");
        printf("\n\nChoice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            check_balance();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            user_menu();
            break;
        case 4:
            main();
            break;
        default:
            goto choice_error_1;
        }
    }
    }
}

void deposit()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    int deposit_amount,valid=0;

    amount_again:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\tDeposit Amount : ");
    scanf("%d",&deposit_amount);

    if(deposit_amount>0)
        {
            valid=1;
        }

        if(valid==0)
    {
        choice_error:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t\tInvalid Amount\n");
        printf("______________________________________________");
        printf("\n\n1.Enter Amount Again");
        printf("\n\n2.User Menu");
        printf("\n\nChoice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            valid=1;
            goto amount_again;
            break;
        case 2:
            user_menu();
            break;
        default:
            goto choice_error;
        }
    }

    if(valid==1)
    {
        FILE *accounts,*temp,*statement;
    accounts=fopen("users.txt","r");
    temp=fopen("temp.txt","w");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,(user.balance+deposit_amount),user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }

    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");

    statement=fopen("transactions.txt","a");
    fprintf(statement,"%s + %d %d %d %d %d %d SelfDeposit\n",account_no,deposit_amount,time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
    fclose(statement);

    system("cls");
    printf("______________________________________________");
    printf("\n\n    Your transaction is being processed");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Amount Deposited\n");
    printf("\n");
    printf("______________________________________________");
    printf("\n");
    Sleep(4000);
    user_menu();
    }

}

void close_account()
{
    system("cls");
    FILE *accounts,*temp,*statement;
    accounts=fopen("users.txt","r");
    temp=fopen("temp.txt","w");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }

    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");


    statement=fopen("transactions.txt","r");
    temp=fopen("temp.txt","w");
    while(!feof(statement))
    {
       fscanf(statement,"%s %s %d %d %d %d %d %d %s\n",user.account,user.cr_dr,&user.balance,&user.acc_date,&user.acc_month,&user.acc_year,&user.acc_hour,&user.acc_minute,user.reason);
       if(strcmp(account_no,user.account)!=0)
       {
          fprintf(temp,"%s %s %d %d %d %d %d %d %s\n",user.account,user.cr_dr,user.balance,user.acc_date,user.acc_month,user.acc_year,user.acc_hour,user.acc_minute,user.reason);

       }
    }
    fclose(statement);
    fclose(temp);
    remove("transactions.txt");
    rename("temp.txt","transactions.txt");

    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tClosing Account");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tAccount Closed\n");
    printf("\n");
    printf("______________________________________________");
    printf("\n");
    Sleep(4000);
    main();
}

void check_balance()
{
    system("cls");
    FILE *accounts;
    accounts=fopen("users.txt","r");
    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)==0)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t  Account Balance : %d\n",user.balance);
            printf("______________________________________________");
            printf("\n");
            Sleep(4000);
        }
    }
    fclose(accounts);
    user_menu();
}

void guest()
{
    system("color  f1");
    choice_error:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tWelcome Guest\n");
    printf("______________________________________________");
    printf("\n\n");
    printf("\n\t1.Create New Account");
    printf("\n\n\t2.Deposit Money");
    printf("\n\n\t3.Main Menu");
    printf("\n\n");
    printf("______________________________________________");
    printf("\n\nChoice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        create_account();
        break;
    case 2:
        guest_deposit();
        break;
    case 3:
        main();
        break;
    default:
        goto choice_error;
    }
}

void guest_deposit()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    char name[20];
    int found=0,deposit_amount,confirm=0,valid=0;

    system("cls");
    printf("______________________________________________");
    printf("\n\n\tAccount no : ");
    scanf("%s",account_no);

    FILE *accounts,*temp,*statement;
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)==0)
        {
            found=1;
            system("cls");
            strcpy(name,user.first_name);
        }
    }

    fclose(accounts);

    if(found==0)
    {
        choice_error:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t  Account does not exist\n\n");
        printf("______________________________________________");
        printf("\n\n1.Change account no");
        printf("\n\n2.Main menu");
        printf("\n\nChoice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            guest_deposit();
            break;
        case 2:
            main();
            break;
        default:
            goto choice_error;
        }
    }

    if(found==1)
    {
        choice_error_1:
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\tConfirm Account");
            printf("\n\n\tName       : %s",name);
            printf("\n\n\tAccount no : %s",account_no);
            printf("\n\n");
            printf("______________________________________________");
            printf("\n\n1.Confirm");
            printf("\n\n2.Change account no");
            printf("\n\n3.Main menu");
            printf("\n\n\nChoice :");
            scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            confirm=1;
            break;
        case 2:
            guest_deposit();
            break;
        case 3:
            main();
            break;
        default:
            goto choice_error_1;
        }
    }

    if(confirm==1)
    {
        amount_again:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tEnter Amount : ");
        scanf("%d",&deposit_amount);
        system("cls");
        if(deposit_amount>0)
        {
            valid=1;
        }

    }

    if(valid==0 && confirm==1)
    {
        choice_error_2:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t\tInvalid Amount\n");
        printf("______________________________________________");
        printf("\n\n1.Enter Amount Again");
        printf("\n\n2.Main Menu");
        printf("\n\nChoice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            goto amount_again;
            break;
        case 2:
            main();
            break;
        default:
            goto choice_error_2;
        }
    }

    if(valid==1 && confirm==1)
    {
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
        {
            fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);

            if(strcmp(account_no,user.account)!=0)
                {
                    fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

                }
                else
                {
                    fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,(user.balance+deposit_amount),user.pin,user.acc_date,user.acc_month,user.acc_year);

                }
        }

        fclose(accounts);
        fclose(temp);
        remove("users.txt");
        rename("temp.txt","users.txt");

        statement=fopen("transactions.txt","a");
        fprintf(statement,"%s + %d %d %d %d %d %d GuestDeposit\n",account_no,deposit_amount,time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
        fclose(statement);

        system("cls");
        printf("______________________________________________");
        printf("\n\n    Your transaction is being processed");

        for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }

        system("cls");
        printf("______________________________________________");
        printf("\n\n\t   Amount Deposited\n");
        printf("\n");
        printf("______________________________________________");
        printf("\n");
        Sleep(4000);
        main();
    }
}

void create_account()
{
    char cpin[6],ch;
    int matched=0;
    struct account temp;
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tCreate Account\n");
    printf("______________________________________________");
    printf("\n");
    printf("\nFirst Name   : ");
    scanf("%s",user.first_name);
    printf("\nLast Name    : ");
    scanf("%s",user.last_name);
    printf("\nEmail ID     : ");
    scanf("%s",user.mail);
    printf("\nMobile No    : ");
    scanf("%s",user.account);
    FILE *accounts;
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",temp.first_name,temp.last_name,temp.mail,temp.account,temp.city,temp.pincode,&temp.balance,&temp.pin,&temp.acc_date,&temp.acc_month,&temp.acc_year);
        if(strcmp(temp.account,user.account)==0)
        {
            matched=1;
        }
    }
    fclose(accounts);

    if(matched==1)
    {
        choice_error:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tAccount already exists");
        printf("\n\n");
        printf("______________________________________________");
        printf("\n\n1.Login to existing account");
        printf("\n\n2.Create new account");
        printf("\n\n3.Main menu");
        printf("\n\nChoice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            user_login();
            break;
        case 2:
            create_account();
            break;
        case 3:
            main();
            break;
        default:
            goto choice_error;
        }
    }

    if(matched==0)
    {


    printf("\nCity         : ");
    scanf("%s",user.city);
    printf("\nPinCode      : ");
    scanf("%s",user.pincode);
    printf("\nAmount       : ");
    scanf("%d",&user.balance);
    pin_mismatch:
    printf("\nPin          : ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            user.pin[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            user.pin[i]=ch;
            i++;
            printf("*");
        }
    }

    i=0;

    printf("\n\nConfirm Pin  : ");
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            cpin[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            cpin[i]=ch;
            i++;
            printf("*");
        }
    }

    if(strcmp(cpin,user.pin)!=0)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\tPin Not Matched\n");
            printf("\n\t\tEnter it Again\n");
            printf("______________________________________________");
            printf("\n");
            goto pin_mismatch;
        }
    choice_error_1:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tConfirm Details\n");
    printf("______________________________________________");
    printf("\n\n");
    printf("\n\tFirst Name   : %s",user.first_name);
    printf("\n\n\tLast Name    : %s",user.last_name);
    printf("\n\n\tEmail ID     : %s",user.mail);
    printf("\n\n\tMobile No    : %s",user.account);
    printf("\n\n\tCity         : %s",user.city);
    printf("\n\n\tPinCode      : %s",user.pincode);
    printf("\n\n\tAmount       : %d",user.balance);
    printf("\n");
    printf("______________________________________________");
    printf("\n");
    printf("\n1.Confirm\n2.Edit\n3.Main Menu");
    printf("\n\nChoice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        confirm_account();
        break;
    case 2:
        create_account();
        break;
    case 3:
        main();
        break;
    default:
        goto choice_error_1;
    }
}
}

void confirm_account()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    FILE *accounts,*statement;

    accounts=fopen("users.txt","a");
    fprintf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,time.wDay,time.wMonth,time.wYear);
    fclose(accounts);

    statement=fopen("transactions.txt","a");
    fprintf(statement,"%s + %d %d %d %d %d %d AccountOpen\n",user.account,user.balance,time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute);
    fclose(statement);

    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Creating Account");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }

    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tAccount Created\n");
    printf("\n\t  Account No : %s",user.account);
    printf("\n");
    printf("______________________________________________");
    printf("\n");
    Sleep(5000);
    main();
}

void account_details()
{
    system("cls");
    FILE *accounts;
    choice_error:
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);

        if(strcmp(account_no,user.account)==0)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\t%s Details\n",name);
            printf("______________________________________________");
            printf("\n\n");
            printf("\n\tFirst Name   : %s",user.first_name);
            printf("\n\n\tLast Name    : %s",user.last_name);
            printf("\n\n\tEmail ID     : %s",user.mail);
            printf("\n\n\tMobile No    : %s",user.account);
            printf("\n\n\tCity         : %s",user.city);
            printf("\n\n\tPinCode      : %s",user.pincode);
            printf("\n\n\tAmount       : %d",user.balance);
            printf("\n");
            printf("______________________________________________");
            printf("\n");
        }
    }
    fclose(accounts);
    printf("\n1.User Menu");
    printf("\n\n2.Edit Details");
    printf("\n\n\nChoice :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        user_menu();
        break;
    case 2:
        edit_details();
        break;
    default:
        goto choice_error;
    }
}

void edit_details()
{
    char first_name[20],last_name[20],mail[40],city[15],pincode[10],pin[6],cpin[6],account[15],ch;
    int match=0;
    system("cls");
    FILE *accounts,*temp,*statement;
    choice_error:
    accounts=fopen("users.txt","r");

    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);

        if(strcmp(account_no,user.account)==0)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\tEdit Details\n");
            printf("______________________________________________");
            printf("\n");
            printf("\n\n 1.First Name   : %s",user.first_name);
            printf("\n\n 2.Last Name    : %s",user.last_name);
            printf("\n\n 3.Email ID     : %s",user.mail);
            printf("\n\n 4.Mobile       : %s",user.account);
            printf("\n\n 5.City         : %s",user.city);
            printf("\n\n 6.PinCode      : %s",user.pincode);
            printf("\n\n 7.Pin Change");
            printf("\n\n 8.User Menu");
            printf("\n");
            printf("______________________________________________");
            printf("\n");
            printf("\nChoice :");
        }
    }

    fclose(accounts);
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tFirst Name : ");
        scanf("%s",first_name);
        strcpy(name,first_name);
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Updating Details");
    for(i=0;i<3;i++)
    {
        printf(".");
        Sleep(1500);
    }
    user_menu();
    break;

    case 2:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tLast Name : ");
        scanf("%s",last_name);
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Updating Details");
    for(i=0;i<3;i++)
    {
        printf(".");
        Sleep(1500);
    }
    user_menu();
    break;

    case 3:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tMail ID : ");
        scanf("%s",mail);
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Updating Details");
    for(i=0;i<3;i++)
    {
        printf(".");
        Sleep(1500);
    }
    user_menu();
    break;

    case 4:
        {
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tMobile      : ");
        scanf("%s",account);
        accounts=fopen("users.txt","r");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(user.account,account)==0)
        {
            match=1;
        }
    }

        fclose(accounts);

        if(match==1)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\tMobile no already registered");
            printf("\n\n");
            printf("______________________________________________");
            printf("\n");
            Sleep(3000);
            user_menu();
        }

        if(match==0)
        {
            accounts=fopen("users.txt","r");
            temp=fopen("temp.txt","w");
            while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
        fclose(accounts);
        fclose(temp);
        remove("users.txt");
        rename("temp.txt","users.txt");

        statement=fopen("transactions.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(statement))
        {
            fscanf(statement,"%s %s %d %d %d %d %d %d %s\n",user.account,user.cr_dr,&user.balance,&user.acc_date,&user.acc_month,&user.acc_year,&user.acc_hour,&user.acc_minute,user.reason);
            if(strcmp(account_no,user.account)!=0)
            {
                fprintf(temp,"%s %s %d %d %d %d %d %d %s\n",user.account,user.cr_dr,user.balance,user.acc_date,user.acc_month,user.acc_year,user.acc_hour,user.acc_minute,user.reason);
            }
            else
            {
            fprintf(temp,"%s %s %d %d %d %d %d %d %s\n",account,user.cr_dr,user.balance,user.acc_date,user.acc_month,user.acc_year,user.acc_hour,user.acc_minute,user.reason);
            }
        }
    fclose(statement);
    fclose(temp);
    remove("transactions.txt");
    rename("temp.txt","transactions.txt");

        strcpy(account_no,account);
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t   Updating Details");
        for(i=0;i<3;i++)
            {
                printf(".");
                Sleep(1500);
            }
            user_menu();
        }
        }
        break;

    case 5:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tCity : ");
        scanf("%s",city);
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Updating Details");
    for(i=0;i<3;i++)
    {
        printf(".");
        Sleep(1500);
    }
    user_menu();
    break;

    case 6:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tPincode : ");
        scanf("%s",pincode);
        accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Updating Details");
    for(i=0;i<3;i++)
    {
        printf(".");
        Sleep(1500);
    }
    user_menu();
    break;

    case 7:
    pin_mismatch:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\tNew pin      : ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            pin[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            pin[i]=ch;
            i++;
            printf("*");
        }
    }

    i=0;

    printf("\n\n\tConfirm Pin  : ");
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            cpin[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            cpin[i]=ch;
            i++;
            printf("*");
        }
    }

    if(strcmp(cpin,pin)!=0)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\tPin Not Matched\n");
            printf("\n\t\tEnter it Again\n");
            printf("______________________________________________");
            printf("\n");
            Sleep(2500);
            goto pin_mismatch;
        }
        else
        {
            accounts=fopen("users.txt","r");
        temp=fopen("temp.txt","w");
        while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);

        }
        else
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,pin,user.acc_date,user.acc_month,user.acc_year);

        }
    }
    fclose(accounts);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t   Updating Details");
    for(i=0;i<3;i++)
    {
        printf(".");
        Sleep(1500);
    }
    user_menu();

    case 8:
        user_menu();
        break;

    default:
        goto choice_error;
        }
    }
}

void admin_login()
{
    char admin_name[]={"varun"};
    char admin_password[]={"admin"};
    char name[15],password[15],ch;

    system("cls");
    printf("______________________________________________");
    printf("\n");
    printf("\n\tAdmin Name : ");
    scanf("%s",name);
    printf("\n\tPassword   : ");
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            password[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");

            }
        }
        else if(ch==9 || ch==32)
        {
            continue;
        }
        else
        {
            password[i]=ch;
            i++;
            printf("*");
        }
    }
    system("cls");

    if(strcmp(admin_name,name)==0 && strcmp(admin_password,password)==0)
    {
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t   Validating Credentials");
        for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }
        admin_menu();
    }
    else
    {
        system("cls");
        printf("______________________________________________");
        printf("\n\n\t   Validating Credentials");
        for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(1500);
        }
        choice_error:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tInvalid Credentials\n");
        printf("______________________________________________");
        printf("\n");
        printf("\n\t1.Retry Login");
        printf("\n\n\t2.Main Menu");
        printf("\n");
        printf("______________________________________________");
        printf("\n\nChoice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            admin_login();
            break;
        case 2:
            main();
            break;
        default:
            goto choice_error;
        }
    }
}

void admin_menu()
{
    system("color 02");
    choice_error:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tWelcome Admin\n");
    printf("______________________________________________");
    printf("\n\n");
    printf("\n\t1.View Users");
    printf("\n\n\t2.Create Database");
    printf("\n\n\t3.Delete User");
    printf("\n\n\t4.Delete Database");
    printf("\n\n\t5.Main Menu");
    printf("\n\n");
    printf("______________________________________________");
    printf("\n\nChoice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        view_users_option();
        break;
    case 2:
        create_database();
        break;
    case 3:
        delete_user();
        break;
    case 4:
        delete_database();
        break;
    case 5:
        main();
        break;
    default:
        goto choice_error;
    }
}

void create_database()
{
    FILE *accounts,*statement;
    accounts=fopen("users.txt","a");
    fclose(accounts);
    statement=fopen("transactions.txt","a");
    fclose(statement);

    system("cls");
    printf("___________________________________________________");
    printf("\n\n\t\tCreating Database");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(2000);
        }

    system("cls");
    printf("___________________________________________________");
    printf("\n\n\t\tDatabase Created");
    printf("\n");
    printf("___________________________________________________");
    printf("\n");
    Sleep(3000);
    admin_menu();

}

void view_users_option()
{
    choice_error:
    system("cls");
    printf("______________________________________________");
    printf("\n\n\t\tWelcome Admin\n");
    printf("______________________________________________");
    printf("\n\n");
    printf("\n\t1.Search with Account No");
    printf("\n\n\t2.All account holders");
    printf("\n\n");
    printf("______________________________________________");
    printf("\n\nChoice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        view_user();
        break;
    case 2:
        view_all_users();
        break;
    default:
        goto choice_error;
    }
}

void view_user()
{

    int found=0;
    system("cls");
    printf("______________________________________________");
    printf("\n\n\tUser Account No : ");
    scanf("%s",account_no);
    system("cls");
    printf("_______________________________________________");
    printf("\n\n\tFetching User Details");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(2000);
        }

    FILE *accounts;
    choice_error:
    accounts=fopen("users.txt","r");
    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)==0)
        {
            system("cls");
            printf("______________________________________________");
            printf("\n\n\t\tUser Details\n");
            printf("______________________________________________");
            printf("\n");
            printf("\n\tFirst Name   : %s",user.first_name);
            printf("\n\n\tLast Name    : %s",user.last_name);
            printf("\n\n\tEmail ID     : %s",user.mail);
            printf("\n\n\tMobile No    : %s",user.account);
            printf("\n\n\tCity         : %s",user.city);
            printf("\n\n\tPinCode      : %s",user.pincode);
            printf("\n\n\tAmount       : %d",user.balance);
            printf("\n\n\tPin          : %s",user.pin);
            printf("\n");
            printf("______________________________________________");
            found=1;
        }
    }
    fclose(accounts);
    if(found==0)
    {
        system("cls");
        printf("______________________________________________");
        printf("\n");
        printf("\n\tAccount Does not exist");
        printf("\n");
        printf("______________________________________________");
    }
    printf("\n\nPress\n");
    printf("\n1.Admin menu");
    printf("\n2.Main Menu");
    printf("\n");
    printf("______________________________________________");
    printf("\n\nChoice :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        admin_menu();
        break;
    case 2:
        main();
        break;
    default:
        goto choice_error;
    }
}

void view_all_users()
{
    system("cls");
    FILE *accounts;
    accounts=fopen("users.txt","r");
    system("cls");
    printf("_______________________________________________");
    printf("\n\n\tFetching Account Holder Details");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(2000);
        }
    system("cls");
    printf("_________________________________________________________________________");
    printf("\n\n\t\t\tAccount Holders List\n");
    printf("_________________________________________________________________________");
    printf("\n\n\tAccount No\tBalance\t\tOpened On\tPin\tName\n\n");
    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        printf("\t%s \t%d \t\t%d/%d/%d \t%s \t%s\n\n",user.account,user.balance,user.acc_date,user.acc_month,user.acc_year,user.pin,user.first_name);

    }
    fclose(accounts);
    getch();
    admin_menu();
}

void delete_user()
{
    int found=0;
    system("cls");
    printf("______________________________________________");
    printf("\n\n");
    printf("\tUser Account No : ");
    scanf("%s",account_no);
    FILE *accounts,*temp,*statement;
    accounts=fopen("users.txt","r");
    temp=fopen("temp.txt","w");
    while(!feof(accounts))
    {
        fscanf(accounts,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,&user.balance,user.pin,&user.acc_date,&user.acc_month,&user.acc_year);
        if(strcmp(account_no,user.account)!=0)
        {
            fprintf(temp,"%s %s %s %s %s %s %d %s %d %d %d\n",user.first_name,user.last_name,user.mail,user.account,user.city,user.pincode,user.balance,user.pin,user.acc_date,user.acc_month,user.acc_year);
        }
        else
        {
            found=1;
        }
    }

    fclose(accounts);
    fclose(temp);

    if(found==0)
    {
        remove("temp.txt");
        choice_error:
        system("cls");
        printf("______________________________________________");
        printf("\n\n\tAccount Does Not Exist\n");
        printf("______________________________________________");
        printf("\n\n1.Retry with correct account no");
        printf("\n\n2.Admin Menu");
        printf("\n\n\nChoice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            delete_user();
            break;
        case 2:
            admin_menu();
            break;
        default:
            goto choice_error;
        }
    }

    if(found==1)
    {
    remove("users.txt");
    rename("temp.txt","users.txt");

    statement=fopen("transactions.txt","r");
    temp=fopen("temp.txt","w");
    while(!feof(statement))
    {
       fscanf(statement,"%s %s %d %d %d %d %d %d %s\n",user.account,user.cr_dr,&user.balance,&user.acc_date,&user.acc_month,&user.acc_year,&user.acc_hour,&user.acc_minute,user.reason);
       if(strcmp(account_no,user.account)!=0)
       {
          fprintf(temp,"%s %s %d %d %d %d %d %d %s\n",user.account,user.cr_dr,user.balance,user.acc_date,user.acc_month,user.acc_year,user.acc_hour,user.acc_minute,user.reason);

       }
    }
    fclose(statement);
    fclose(temp);
    remove("transactions.txt");
    rename("temp.txt","transactions.txt");

    system("cls");
    printf("___________________________________________________");
    printf("\n\n\t\tDeleting User");
    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(2000);
        }

    system("cls");
    printf("___________________________________________________");
    printf("\n\n\t\tUser Deleted");
    printf("\n");
    printf("___________________________________________________");
    printf("\n");
    Sleep(3000);
    admin_menu();
    }
}

void delete_database()
{
    remove("users.txt");
    remove("transactions.txt");
    system("cls");
    printf("___________________________________________________");
    printf("\n\n\t\tDeleting Database");

    for(i=0;i<3;i++)
        {
            printf(".");
            Sleep(2000);
        }

    system("cls");
    printf("___________________________________________________");
    printf("\n\n\t\tDatabase Deleted");
    printf("\n");
    printf("___________________________________________________");
    printf("\n");
    Sleep(3000);
    admin_menu();
}

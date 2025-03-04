#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char phone[20];
    char ac[40];
    char password[45];
    float balance;
};

int main()
{
    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50], phone2[50];

    int opt, choice;
    char cont = 'y';
    float amount;

    printf("\nwhat do you want to do?");
    printf("\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n your choice:\n");
    scanf("%d", &opt);

    if (opt == 1)
    {
        system("cls");
        printf("Enter your account number:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n Account successfully registered");
        }
        else
        {
            printf("\nSomething went wrong please try again");
        }
        fclose(fp);
    }
    if (opt == 2)
    {
        system("cls");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("\nAccount number not registered");
        }
        else
        {

            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password))
            {
                printf("\n\n\tWelcome %s", usr.phone);
                while (cont == 'y')
                {
                    system("cls");
                    printf("\n\nPress 1 for balance inquiry");
                    printf("\nPress 2 for depositing cash");
                    printf("\nPress 3 for cash withdrawl");
                    printf("\nPress 4 for online transfer");
                    printf("\nPress 5 for password change");
                    printf("\nYour choice:\t");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\nYour current balance is Rs.%.2f", usr.balance);
                        break;
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\nSuccessfullu Deposited.");
                        }
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\nYou have withdrawn Rs.%.2f", amount);
                        }
                        fclose(fp);
                        break;
                    case 4:
                        printf("\nEnter the phone number to transfer the balance:\t");
                        scanf("%s", phone);
                        printf("\nEnter the amount to transfer:\t");
                        scanf("%f", &amount);
                        strcpy(filename, phone);
                        fp = fopen(strcat(filename, ".dat"), "r");

                        if (fp == NULL)
                        {
                            printf("\nAccount number not registered");
                        }
                        else
                        {

                            fread(&usr1, sizeof(struct user), 1, fp);
                            fclose(fp);
                            if (amount > usr.balance)
                            {
                                printf("\nInsufficient Balance");
                            }
                            else
                            {
                                fp = fopen(filename, "w");
                                usr1.balance += amount;
                                fwrite(&usr1, sizeof(struct user), 1, fp);
                                fclose(fp);
                                if (fwrite != NULL)
                                {
                                    printf("\nYou have successfully transferred Rs.%.2f to %s", amount, phone);
                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "w");
                                    usr.balance -= amount;
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                }
                            }
                            break;

                        case 5:
                            printf("\nPlease enter your new password:\t");
                            scanf("%s", pword);
                            fp = fopen(filename, "w");
                            strcpy(usr.password, pword);
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            if (fwrite != NULL)

                                printf("\nPassword successfully changed");
                        }
                        break;
                    default:
                        printf("\nInvalid option");
                    }

                    printf("\nDo you want to continue the transaction [yes/no]\t");
                    scanf("%s", &cont);
                }
            }
            else
            {
                printf("\nInvalid password");
            }
        }
        printf("\n\n***Thank you for banking with SBI bank***\n\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tab printf("\n\t\t\t\t")

void ChooseRole(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void MenuOwner(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void GetChoiceOfOwner(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void MenuCustomer(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void GetChoiceOfCustomer(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void MenuSort(); 
void MenuSubSort();
void MenuFind();
void GetChoiceOfSubSort(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);

int isEmpty(int n);
void DisplayEquipment(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void AddNewEquipment(int*nums,int*Rno,int rno,char*Names[],char getname[],int*Price,int price,int*Quantity,int quantity,char*mfg[],char getmfg[],char*exp[],char getexp[]);
void SwapInt(int*p1,int*p2);
void SwapChar(char* str1,char* str2);
void Sort(int choice1,int choice2,int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void FindByName(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]);
void FindByPrice(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],int price);
void DeleteEquipment(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]);
void DeleteAllEquipment(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void ChangePrice(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int NPrice);
void BuyEquipment(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int BQuantity,float *Money,int * NumInCart);
void ReadFile(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);
void WriteFile(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]);


void ChooseRole(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int userChoice;
	tab;printf(" ===============================================");
	tab;printf(" |                ENTER ROLE                   |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. SHOP OWNER\n");
	tab;printf("   2. CUSTOMER\n ");
	tab;printf("   3. EXIT \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your role: ");
	scanf("%d",&userChoice);
	while (userChoice>3 || userChoice <0) {
		tab;printf("Enter again (1 - 3): ");
		scanf("%d",&userChoice);
	}
	switch(userChoice) {
		case 1:
			system("cls");
			MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 2:
			system("cls");
			MenuCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 3:
			tab;printf("Exit!");
			exit(1);
			break;
	}
}

void MenuOwner(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {

	tab;printf(" ===============================================");
	tab;printf(" |                MENU SHOP OWNER              |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Display all Equipment                 \n");
	tab;printf("   2. Add new Equipment                     \n");
	tab;printf("   3. Sort all Equipment 				   \n");
	tab;printf("   4. Looking for Equipment         \n");
	tab;printf("   5. Delete Equipment       \n");
	tab;printf("   6. Delete All Equipment       \n");
	tab;printf("   7. Edit Price Of Equipment       \n");
	tab;printf("   8. Write to text file      \n");
	tab;printf("   9. Back to Role Menu      \n");
	tab;printf("   10. EXIT      \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");
	GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
}

void GetChoiceOfOwner(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int userChoice,NPrice;
	int daymfg,dayexp,monthmfg,monthexp,yearmfg,yearexp;  
	char getname[20],getmfg[20],getexp[20];
	int rno,price,quantity,i;
		scanf("%d", &userChoice);
		switch(userChoice) {
		case 1:
			do {
				system("cls");
				printf("\n<===============|SHOW EQUIPMENT MENU|===============>\n\n");
				if(isEmpty(*NumOfEquipment)) {
					printf("FPT Shop doestn't have anything to show!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nExit!"); exit(1); break;
				} 
				else {
					DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
					fflush(stdin);
					MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
					GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);

				}
			} while(userChoice==121);
			break;
		case 2:
			do {
				system("cls");
				printf("\n<===============|ADD EQUIPMENT|===============>\n");
				printf("\nEnter Roll No: ");
				scanf("%d",&rno);
				printf("\nEnter name: ");
				fflush(stdin);
				scanf("%[^\n]s",getname);
				printf("\nEnter Price: ");
				scanf("%d",&price);
				printf("\nEnter Quantity: ");
				scanf("%d",&quantity);
				printf("\nEnter Manufacturing Date (dd/mm/yyyy): ");
				fflush(stdin);
				scanf("%[^\n]s",getmfg);
				while(!CheckDay(getmfg,&daymfg,&monthmfg,&yearmfg)) {
									printf("\nInvalid Manufacturing Date!\n");
									printf("\nEnter Manufacturing Date Of Equipment Again (dd/mm/yyyy): ");
									fflush(stdin);
									scanf("%[^\n]s",getmfg);
								}
				printf("\nEnter Expiry Date (dd/mm/yyyy): ");
				fflush(stdin);
				scanf("%[^\n]s",getexp);
				while(!CheckDay(getexp,&dayexp,&monthexp,&yearexp)) {
									printf("\nInvalid Expiry Date!\n");
									printf("\nEnter Expiry Date Of Equipment Again (dd/mm/yyyy): ");
									fflush(stdin);
									scanf("%[^\n]s",getexp);
								}
									if(yearexp<yearmfg) {
										printf("\nThe year of the expiry date must be greater than the year of the manufacture date\n");
										printf("\nEnter Expiry Date Of Equipment Again (dd/mm/yyyy): ");
										fflush(stdin);
										scanf("%[^\n]s",getexp);
									} else {
										if(monthexp<monthexp) {
											printf("\nThe year of the expiry date must be greater than the year of the manufacture date");
											printf("\nEnter Expiry Date Of Equipment Again (dd/mm/yyyy): ");
											fflush(stdin);
											scanf("%[^\n]s",getexp);
										} else {
											if(dayexp<dayexp) {
												printf("\nThe year of the expiry date must be greater than the year of the manufacture date");
												printf("\n\nEnter Expiry Date Of Equipment Again (dd/mm/yyyy): ");
												fflush(stdin);
												scanf("%[^\n]s",getexp);
											}
										}
									}
			AddNewEquipment(NumOfEquipment,Rno,rno,Names,getname,Price,price,Quantity,quantity,mfg,getmfg,exp,getexp);
			printf("\nADDED!!!");
			printf("\n\nDo you want to add more? (y/n): ");
			fflush(stdin);
			userChoice = getch();	
			} while(userChoice==121);
			system("cls");
			MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;

		case 3:
				if(isEmpty(*NumOfEquipment)) {
					system("cls");
					printf("\n<===============|SORT EQUIPMENT|===============>\n");
					printf("\nFPT Shop doestn't have anything to sort!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nExit!"); exit(1); break;
				}
				GetChoiceOfSubSort(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
				fflush(stdin);
				MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 4:
			if(isEmpty(*NumOfEquipment)) {
					system("cls");
					printf("\n<===============|FIND-EQUIPMENT|===============>\n");
					printf("\nFPT shop doestn't have anything to find!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nExit!"); exit(1); break;
				}
			system("cls");
			MenuFind();
			scanf("%d", &userChoice);
			if(userChoice==1) {
				system("cls");
				printf("<=======================|FIND-EQUIPMENT|=======================>\n");
				printf("\nEnter name of equipment: ");
				fflush(stdin);
				scanf("%20[^\n]s",getname);
				while(getname[0]==' ') {

						for(i=0;i<strlen(getname);i++) {
							getname[i] = getname[i+1];
						}

				}
				while(strlen(getname)<20) {
					strncat(getname, " ",20-strlen(getname));
				}
				FindByName(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp,getname);
				MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);

			} else if(userChoice==2) {
				printf("Enter Price: ");
				scanf("%d",&price);
				FindByPrice(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp,price);
				MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			} else {
				fflush(stdin);
				MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
				GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			}
			break;
		case 5:
			if(isEmpty(*NumOfEquipment)) {
					system("cls");
					printf("\n<===============|DELETE-EQUIPMENT|===============>\n");
					printf("\nFPT doestn't have any equipment to delete!\n");
					printf("\nBack to Menu Shop Owner (y/n): ");
					userChoice = getch();
						if(userChoice==121) {
							system("cls");
							MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
							GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						} else printf("\n\nExit!"); exit(1); break;
				}
			printf("\nEnter name of equipment: ");
			fflush(stdin);
			scanf("%[^\n]s",getname);
			while(getname[0]==' ') {

						for(i=0;i<strlen(getname);i++) {
							getname[i] = getname[i+1];
						}
				}
			while(strlen(getname)<20) {
				strncat(getname, " ",20-strlen(getname));
			}
			DeleteEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp,getname);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 6:
			DeleteAllEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 7:
			system("cls");
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			printf("\nEnter name of equipment: ");
				fflush(stdin);
				scanf("%20[^\n]s",getname);
			printf("\nEnter new price: ");
			scanf("%d", &NPrice);
				while(strlen(getname)<20) {
					strncat(getname, " ",20-strlen(getname));
				}
			ChangePrice(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp,getname,NPrice);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 8:
			WriteFile(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 9:
			system("cls");
			ChooseRole(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		default:
			tab;printf("Exit!");
			exit(1);
	}	
}

void MenuCustomer(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {

	tab;printf(" ===============================================");
	tab;printf(" |                MENU CUSTOMER                |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Display all Equipment                 \n");
	tab;printf("   2. Buy Equipment \n");
	tab;printf("   3. Back To Role Menu  \n");
	tab;printf("   4. EXIT      \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");
	GetChoiceOfCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);

}

void GetChoiceOfCustomer(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int userChoice,i,Bquantity,NumInCart;
	float Money,userMoney,userBanking;
	char getname[20];
	scanf("%d", &userChoice);
	switch(userChoice) {
		case 1:
				do {
					system("cls");
					printf("\nWELCOME TO FPT LABORATORY EQUIPMENT SHOP <3\n");
					if(isEmpty(*NumOfEquipment)) {
						printf("FPT Shop doestn't have anything to show!\n");
						printf("\nBack to Menu Shop Owner (y/n): ");
						userChoice = getch();
							if(userChoice==121) {
								system("cls");
								MenuCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
								GetChoiceOfCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
							} else printf("\n\nExit!"); exit(1); break;
					} 
					else {
						DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						fflush(stdin);
						MenuCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						GetChoiceOfCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
					}
				} while(userChoice==121);

			break;

		case 2:

			do {
					system("cls");
					printf("\nWELCOME TO FPT LABORATORY EQUIPMENT SHOP <3\t\t\t\t\t\t\t\t\tYour cart: %d\n", NumInCart);
					DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
					printf("\nEnter name of equipment: ");
					fflush(stdin);
					scanf("%20[^\n]s",getname);
					while(strlen(getname)<20) {
						strncat(getname, " ",20-strlen(getname));
					}
					printf("\nEnter quantity of equipment: ");
					scanf("%d", &Bquantity);
					BuyEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp,getname,Bquantity,&Money,&NumInCart);
					printf("\nPress 1 to continue shopping or Press any button to get bill\n");
					userChoice = getch();
			} while(userChoice==49);
			if (NumInCart==0) {
					MenuCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
					GetChoiceOfCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			}
			else{ 
					printf("\nEnter your cash: ");
					scanf("%f", &userMoney);
					while(userMoney<Money) {
					printf("\nYou don't have enough cash to pay!\n\nYou must cash from your banking\n");
					printf("\nEnter your cash: ");
					scanf("%f", &userBanking);
					userMoney+=userBanking;

					}
					printf("\nPay Successfully! \n");
					printf("\nYour money remaining: %f VND", userMoney - Money);
					MenuCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
					GetChoiceOfCustomer(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
				}
			break;
		case 3: 
		system("cls");
		ChooseRole(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
		GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
		break;	

		default:
			tab;printf("FPT Shop xin cam on");
			exit(1);
	}
}

void MenuSort() {

	tab;printf(" ===============================================");
	tab;printf(" |                  MENU SORT                  |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Sort depend on Roll NO                 \n");
	tab;printf("   2. Sort depend on Name                 \n");
	tab;printf("   3. Sort depend on Price \n"); 
	tab;printf("   4. Sort depend on Manufacturing_Date       \n");
	tab;printf("   5. Sort depend on Expiry_Date     \n");
	tab;printf("   6. Sort depend on Quantity     \n");
	tab;printf("   7. Back to Shop Owner Menu     \n");
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");

}

void MenuSubSort() {

	tab;printf(" ===============================================");
	tab;printf(" |                 MENU SUB SORT               |");
	tab;printf(" ===============================================\n");
	tab;printf("   1. Sort Ascending                 \n");
	tab;printf("   2. Sort Descending                 \n");
	tab;printf("   3. Back to other Sort \n"); 
	tab;printf("   4. Back to Shop Owner Menu \n"); 
	tab;printf(" ===============================================\n\n");
	tab;printf("Enter your choice: ");

}
void GetChoiceOfSubSort(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int CSort,CSSort;
	system("cls");
	do {
		MenuSort();
		scanf("%d", &CSort);
		system("cls");
		switch(CSort) {
		case 1:
			MenuSubSort();
			scanf("%d", &CSSort);
				switch(CSSort) {
					case 1:
						system("cls");
						Sort(CSort,CSSort,NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						break;
					case 2:
						system("cls");
						Sort(CSort,CSSort,NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						break;
					case 3:
						system("cls");
						break;
					default:
						system("cls");
						MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
						break;
					}
			break;
		case 2:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 3:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		case 4:
			MenuSubSort(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;

		case 5:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;

		case 6:
			MenuSubSort();
			scanf("%d", &CSSort);
			system("cls");
			Sort(CSort,CSSort,NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			DisplayEquipment(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		default:
			MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
		}
	} while (CSort > 0 && CSort < 8);

}

int isEmpty(int n) {
	return n == 0;
}

void DisplayEquipment(int*NumOfEquipment,int*Rno,char *Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int i =0;
	printf("\t\t\t\t\t\t|MENU OF EQUIPMENT|");
	printf("\n===================================================================================="
	"====================================\n");
	printf("\nNO\t    NAME\t\tPRICE\t\t  QUANTITY\t     Manufacturing_Date    Expiry_Date\n\n");
	for(i=0;i<*NumOfEquipment;i++) {

		printf("%-10d  ",Rno[i]);
		printf("%-20s",Names[i]);
		printf("%-20d",Price[i]);
		printf("%-20d",Quantity[i]);
		printf("%-20s",mfg[i]);
		printf("%-10s\n",exp[i]);

	}
	printf("\n===================================================================================="
	"====================================\n");
}

int CheckDay(char a[],int*pd,int*pm,int*py) {

	char d[2],m[2],y[4];

	strncpy(d, a, 2); 
	strncpy(m, a+3, 2);
	strncpy(y, a+6, 4);

	*(pd) = atoi(d);
	*(pm) = atoi(m);
	*(py) = atoi(y);

	int maxd = 31;
    if (((*pd) < 1) || ((*pd) > 31) || ((*pm) < 1) || ((*pm) > 12))
    	return 0;
    if (((*pm) == 4) || ((*pm) == 6) || ((*pm) == 9) || ((*pm) == 11))
        maxd = 30;
    if ((*pm) == 2)
	{
        if (((*py) % 400 == 0) || (((*py) % 4 == 0) && ((*py) % 100 != 0)))
 	    	maxd = 29;
        else
        	maxd = 28; 
	}
	return (*pd) <= maxd;
}

void AddNewEquipment(int*nums,int*Rno,int rno,
				char*Names[],char getname[],
				int*Price,int price,int*Quantity,int quantity,
				char*mfg[],char getmfg[],char*exp[],char getexp[]) {

	 Names[*nums] = malloc(strlen(getname) + 1);
	   mfg[*nums] = malloc(strlen(getmfg) + 1);
	   exp[*nums] = malloc(strlen(getexp) + 1);

	   Rno[*nums] = rno;
 	 Price[*nums] = price;
  Quantity[*nums] = quantity;

	strcpy(Names[*nums], getname);
	strcpy( mfg[*nums], getmfg);
	strcpy( exp[*nums], getexp);
	(*nums)++;
}

void SwapInt(int*p1,int*p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void SwapChar(char* str1,char* str2) 
{
	char temp[20];
   strcpy(temp,str1);
   strcpy(str1,str2);
   strcpy(str2,temp);
}

void Sort(int choice1,int choice2,int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	int i,j;
	char d[2],m[2],y[4];
	int day1,month1,year1,day2,month2,year2;
	switch(choice1) {
		case 1: 
			if(choice2==1) {
				for(i=0;i<(*NumOfEquipment)-1;i++) {
					for(j=i+1;j<*NumOfEquipment;j++) {
						if (Rno[i] > Rno[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
					}
				}
			}
		} else {
				for(i=0;i<(*NumOfEquipment)-1;i++) {
					for(j=i+1;j<*NumOfEquipment;j++) {
					if (Rno[i] < Rno[j]) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		}	
			break;
		case 2:
			if(choice2==1) {
				for(i=0;i<(*NumOfEquipment)-1;i++) {
					for(j=i+1;j<*NumOfEquipment;j++) {
					if (strcmp(Names[i],Names[j])>0) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		} else {
			for(i=0;i<(*NumOfEquipment)-1;i++) {
				for(j=i+1;j<*NumOfEquipment;j++) {
					if (strcmp(Names[i],Names[j])<0) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		}
			break;
		case 3:
			if(choice2==1) {
				for(i=0;i<(*NumOfEquipment)-1;i++) {
					for(j=i+1;j<*NumOfEquipment;j++) {
					if (Price[i] > Price[j]) {
						SwapInt(&Rno[i],&Rno[j]);
						SwapInt(&Price[i],&Price[j]);
						SwapInt(&Quantity[i],&Quantity[j]);
						SwapChar(Names[i],Names[j]);
						SwapChar(mfg[i],mfg[j]);
						SwapChar(exp[i],exp[j]);
					}
				}
			}
		} else {
			for(i=0;i<(*NumOfEquipment)-1;i++) {
				for(j=i+1;j<*NumOfEquipment;j++) {
						if (Price[i] < Price[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			}
			break;
		case 4:
			if(choice2==1) {
				for(i=0;i<(*NumOfEquipment)-1;i++) { 
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);

						for(j=i+1;j<*NumOfEquipment;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);

							if(year1>year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1>month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 > day2) {
										SwapInt(&Rno[i],&Rno[j]);
										SwapInt(&Price[i],&Price[j]);
										SwapInt(&Quantity[i],&Quantity[j]);
										SwapChar(Names[i],Names[j]);
										SwapChar(mfg[i],mfg[j]);
										SwapChar(exp[i],exp[j]);	
									}
								}
							}
						}
				} } else {
					for(i=0;i<(*NumOfEquipment)-1;i++) { 	
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);

						for(j=i+1;j<*NumOfEquipment;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);

							if(year1<year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1<month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 < day2) {
										SwapInt(&Rno[i],&Rno[j]);
										SwapInt(&Price[i],&Price[j]);
										SwapInt(&Quantity[i],&Quantity[j]);
										SwapChar(Names[i],Names[j]);
										SwapChar(mfg[i],mfg[j]);
										SwapChar(exp[i],exp[j]);	
									}
								}
							}
						}
					}
				}	
				break;
		case 5:
			if(choice2==1) {
				for(i=0;i<(*NumOfEquipment)-1;i++) { 
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);

						for(j=i+1;j<*NumOfEquipment;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);

							if(year1<year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1<month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 < day2) {
										SwapInt(&Rno[i],&Rno[j]);
										SwapInt(&Price[i],&Price[j]);
										SwapInt(&Quantity[i],&Quantity[j]);
										SwapChar(Names[i],Names[j]);
										SwapChar(mfg[i],mfg[j]);
										SwapChar(exp[i],exp[j]);	
									}
								}
							}
						}
				} } else {
					for(i=0;i<(*NumOfEquipment)-1;i++) { 	
					strncpy(d, mfg[i], 2); day1 = atoi(d);
					strncpy(m, mfg[i]+3,2); month1 = atoi(m);
					strncpy(y, mfg[i]+6, 4); year1 = atoi(y);

						for(j=i+1;j<*NumOfEquipment;j++) {
						strncpy(d, mfg[j], 2); day2 = atoi(d);
						strncpy(m, mfg[j]+3,2); month2 = atoi(m);
						strncpy(y, mfg[j]+6, 4); year2 = atoi(y);

							if(year1>year2) {
								SwapInt(&Rno[i],&Rno[j]);
								SwapInt(&Price[i],&Price[j]);
								SwapInt(&Quantity[i],&Quantity[j]);
								SwapChar(Names[i],Names[j]);
								SwapChar(mfg[i],mfg[j]);
								SwapChar(exp[i],exp[j]);
							} else if (year1 == year2) {
								if (month1>month2) {
									SwapInt(&Rno[i],&Rno[j]);
									SwapInt(&Price[i],&Price[j]);
									SwapInt(&Quantity[i],&Quantity[j]);
									SwapChar(Names[i],Names[j]);
									SwapChar(mfg[i],mfg[j]);
									SwapChar(exp[i],exp[j]);
								} else if (month1 == month2) {
									if (day1 > day2) {
										SwapInt(&Rno[i],&Rno[j]);
										SwapInt(&Price[i],&Price[j]);
										SwapInt(&Quantity[i],&Quantity[j]);
										SwapChar(Names[i],Names[j]);
										SwapChar(mfg[i],mfg[j]);
										SwapChar(exp[i],exp[j]);	
									}
								}
							}
						}
					}
				}
			break;
		case 6:
			if(choice2==1) {
				for(i=0;i<(*NumOfEquipment)-1;i++) {
					for(j=i+1;j<*NumOfEquipment;j++) {
						if (Quantity[i] > Quantity[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
					}
				} else {
					for(i=0;i<(*NumOfEquipment)-1;i++) {
					for(j=i+1;j<*NumOfEquipment;j++) {
						if (Quantity[i] < Quantity[j]) {
							SwapInt(&Rno[i],&Rno[j]);
							SwapInt(&Price[i],&Price[j]);
							SwapInt(&Quantity[i],&Quantity[j]);
							SwapChar(Names[i],Names[j]);
							SwapChar(mfg[i],mfg[j]);
							SwapChar(exp[i],exp[j]);
						}
					}
				}
			}
			break;
		default:
			MenuOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			GetChoiceOfOwner(NumOfEquipment,Rno,Names,Price,Quantity,mfg,exp);
			break;
	}
}

void ReadFile(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
		char getexp[20],getmfg[20], getname[20];
		int rno,price,quantity;
			Names[*NumOfEquipment] = malloc(strlen(getname) + 1);
	   		mfg[*NumOfEquipment] = malloc(strlen(getmfg) + 1);
	  		exp[*NumOfEquipment] = malloc(strlen(getexp) + 1);
		int i = 0;
		FILE* fp;
		fp = fopen("Equipment.txt", "r");
		if(fp) {
			while(fscanf(fp, "%10d %20[^\n] %20d %20d %20[^\n] %10[^\n]\n",&rno,getname,&price,&quantity,getmfg,getexp)==6) {

				Names[*NumOfEquipment] = malloc(strlen(getname) + 1);
	   			mfg[*NumOfEquipment] = malloc(strlen(getmfg) + 1);
	  			exp[*NumOfEquipment] = malloc(strlen(getexp) + 1);
				Rno[*NumOfEquipment] = rno;
				Price[*NumOfEquipment] = price;
				Quantity[*NumOfEquipment] = quantity;
				strcpy(Names[*NumOfEquipment],getname);
				strcpy(mfg[*NumOfEquipment],getmfg);
				strcpy(exp[*NumOfEquipment],getexp);

				(*NumOfEquipment)++;
				if(feof(fp)) {
					break;
				}	
			}
		}
		fclose(fp);
	}


void WriteFile (int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	getchar();
	char fName[26];
	printf("Enter File Name: ");
	gets(fName);
	FILE* fp = fopen(fName, "a");
	int i;
	for(i = 0; i < *NumOfEquipment; i++) {
		fprintf(fp, "%-10d %-20s %-10d %-10d %-20s %-20s \n",Rno[i], Names[i], Price[i], Quantity[i], mfg[i], exp[i]);
	}
	fclose(fp);
}

void MenuFind() {
		tab;printf(" ===============================================");
		tab;printf(" |                  FIND-EQUIPMENT                  |");
		tab;printf(" ===============================================\n");
		tab;printf("   1. Find equipment depend on Name                 \n");
		tab;printf("   2. Find equipment depend on Price \n"); 
		tab;printf("   3. Back to Shop Owner Menu     \n");
		tab;printf(" ===============================================\n\n");
		tab;printf("Enter your choice: ");

	}

void FindByName(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]) {
	int a;
	int i,check=0;

	for(i=0;i<*NumOfEquipment;i++) {
		a = strcmp(strlwr(Names[i]),strlwr(getname));
		if (a==0) {
			check=1;
			printf("\n===================================================================================="
			"====================================\n");
	
				printf("%-10d  ",Rno[i]);
				printf("%-20s",Names[i]);
				printf("%-20d",Price[i]);
				printf("%-20d",Quantity[i]);
				printf("%-20s",mfg[i]);
				printf("%-10s\n",exp[i]);


			printf("\n===================================================================================="
			"====================================\n");
		}
	} 
	if(check==0) {
		printf("\nNOT FOUND!\n");
	} 
}


void FindByPrice(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],int price) {
	int i,check=0;

	for(i=0;i<*NumOfEquipment;i++) {
		if (Price[i]==price) {
			check=1;
			printf("\n===================================================================================="
			"====================================\n");
			printf("NO\t    NAME\t\tPRICE\t\t  QUANTITY\t     Manufacturing_Date    Expiry_Date\n\n");

				printf("%-10d  ",Rno[i]);
				printf("%-20s",Names[i]);
				printf("%-20d",Price[i]);
				printf("%-20d",Quantity[i]);
				printf("%-20s",mfg[i]);
				printf("%-10s\n",exp[i]);

			printf("\n===================================================================================="
			"====================================\n");

		}
	}
	if(check==0) {
		printf("\nNOT FOUND!\n");
	}
}

void DeleteEquipment(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[]) {
	int i,check=0,j,a;
	for(i=0;i<*NumOfEquipment;i++) {
		a = strcmp(strlwr(Names[i]),strlwr(getname));
		if (a==0) { check=1;
			for(j=i+1;j<*NumOfEquipment;j++) {
				Rno[j-1] = Rno[j];
				Price[j-1] = Price[j];
				Quantity[j-1] = Quantity[j];
				strcpy(Names[j-1],Names[j]);
				strcpy(mfg[j-1],mfg[j]);
				strcpy(exp[j-1],exp[j]);
			}
			(*NumOfEquipment)--;
		}
	} 
	if(check==0) {
			printf("\nNOT FOUND!\n");
		} else {
			printf("\nDELETED SUCCESSFULLY!!!\n");
		}

}

void DeleteAllEquipment(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[]) {
	(*NumOfEquipment)=0;
	int*Rno_=realloc(Rno,0*sizeof(int));
	int*Price_=realloc(Price,0*sizeof(int));
	int*Quantity_=realloc(Quantity,0*sizeof(int));
	char**Names_=realloc(Names,0*sizeof(char*));
	char**mfg_=realloc(mfg,0*sizeof(char*));
	char**exp_=realloc(exp,0*sizeof(char*));
	free(Rno_);
	free(Price_);
	free(Quantity_);
	free(Names_);
	free(mfg_);
	free(exp_);
}

void ChangePrice(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int NPrice) {
	int a;
		int i,check=0;

		for(i=0;i<*NumOfEquipment;i++) {
			a = strcmp(strlwr(Names[i]),strlwr(getname));
			if (a==0) {
				check=1;
				Price[i] = NPrice;
			}
		} 
		if(check==0) {
			printf("\nNOT FOUND!\n\n");
		} else {
			printf("\nChange Price Successfully!\n\n");
		}
}

void BuyEquipment(int*NumOfEquipment,int*Rno,char*Names[],int*Price,int*Quantity,char*mfg[],char*exp[],char getname[],int BQuantity,float *Money,int * NumInCart) {
	int a;
		int i,check=0;
		if (BQuantity==0) {
			printf("\nHuh???\n");
		}
		for(i=0;i<*NumOfEquipment;i++) {
			a = strcmp(strlwr(Names[i]),strlwr(getname));
			if (a==0) {
				check=1;
				Quantity[i]=Quantity[i]-BQuantity;
				(*Money)+=(Price[i]*BQuantity);
					(*NumInCart)++;
			}
		} 
		if(check==0 && BQuantity!=0) {
			printf("\nNOT FOUND!\n");
		} else if (check!=0 && BQuantity!=0) {
			printf("\nBuy Successfully\n");
		}	

}

int main() {
	int NumberOfEquipment=0,i;

	int*Rno = (int*)calloc(10,sizeof(int));
	int*Price = (int*)calloc(10,sizeof(int));
	int*Quantity = (int*)calloc(10,sizeof(int));

	char **Names = (char**)calloc(10,sizeof(char*));
	char **MFG = (char**)calloc(10,sizeof(char*));
	char **EXP = (char**)calloc(10,sizeof(char*));


	ReadFile(&NumberOfEquipment,Rno,Names,Price,Quantity,MFG,EXP);

	ChooseRole(&NumberOfEquipment,Rno,Names,Price,Quantity,MFG,EXP);
	free(Rno);
	free(Price);
	free(Quantity);

	for(i=0;i<NumberOfEquipment;i++) {
		free(Names[i]);
		free(MFG[i]);
		free(EXP[i]);
	}
	free(Names);
	free(MFG);
	free(EXP);
    return 0;
}

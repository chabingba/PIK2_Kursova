#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "func.h"

//------------- ������ -----------------------
char *txt_menu_g[]=
{
	  "---===MENU===---",
		"��������� �� ������������",
		"��������� �� ������� �� ��� ��������",
		"��������� �� ������� �� ��������",
		"��������� �� ������������ �� ��������",
		"��������� �� �������",
		"��������� �� ������� �� ������ ���������",
		"��������� �� ����������� ������ �������� ����",
		"���������� �� ���� �� �����������, ��������� �� ������ ����� �� �������� ���������� �������",
		"Exit",
		NULL
};

char *menu_2[]=
{
	  "---===����� �� ������ ����===---",
		"������� ����",
		"������� ����",
		"�� ������������",
		"�����",
		NULL
};

char *menu_3[]=
{
	  "---===��������� �� ������������ �� ��������===---",
		"�� ���",
		"�� ���",
		"�����",
		NULL
};


int main()
{
	node *head=NULL;
	long long int del_egn, print_egn;
	int mode, m=0, mode_2, mode_3, br_1=0, state=0, state1=0, br_r=0, age;
	FILE *fp_in=NULL, *fp_out=NULL, *fp_keyb=NULL;
	char name_file[256],name_out[256], print_imena[20];


  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
	do
	{
		et_1: mode=menu(txt_menu_g);
		switch (mode)
		{
			case 1:
			do{
				mode_2=menu(menu_2);
				switch(mode_2)
					{
						case 1:	printf("\n�������� ��� �� ��������� ����: ");
								scanf("%s",name_file);
								if ( (fp_in=fopen(name_file,"rt")) == NULL )
								   printf ("\n������: ���� ������� ���� !!!\n");
								else
								   {
									   printf ("\nOK - ������ %s � �������!\n", name_file);
									   head=MakeListFromTxt(head, fp_in);
									    if(head==NULL)
										   {
												printf("\n������ ��� ����������� �� ������� �� ������� ����!\n");
												goto et_1;
										   }
									   else
										printf("\n�������� � �������� �������!\n");
									   //prt(head);
									}
								break;

						case 2:	printf("\n�������� ��� �� �������� ����: ");
								scanf("%s",name_file);
								if ( (fp_in=fopen(name_file,"rb")) == NULL )
								   printf ("\n������: ���� ������� ���� !!!\n");
								else
								   {
									   printf ("\nOK - ������ %s � �������!\n", name_file);
									   head=MakeListFromDat(head, fp_in);
									   if(head==NULL)
									   {
											printf("\n������ ��� ����������� �� ������� �� ������� ����!\n");
											goto et_1;
									   }
									   else
										printf("\n�������� � �������� �������!\n");
									   //prt(head);
									}
								break;
						case 3:	
								do{
									printf("\n---===����� �� ������������===---\n\n");
									printf("<1> - � ������� ����.\n");
									printf("<2> - � ������� ���� ����.\n");
									printf("\n�������� �� �����: ");
									scanf("%d", &state);
								}while(state<1 || state>2);
							
								printf("\n�������� ��� �� ����� �� �����:");
								scanf("%s", name_out);

								printf("\n�������� ���� �� ��������:");
								scanf("%d", &br_1);

								if(state==1)
									{
										if((fp_keyb=fopen(name_out,"w+b"))!=NULL)
											{
												keyb_enter(fp_keyb, br_1, state);
												printf("The file is created");
											}
										if((fp_keyb=fopen(name_out,"rb"))!=NULL)
											{
												head=MakeListFromDat(head, fp_keyb);
												 if(head==NULL)
												   {
														printf("\n������ ��� ����������� �� ������� �� ������������!\n");
														goto et_1;
												   }
											   else
												printf("\n�������� � �������� �������!\n");
												//printf("\n--------------------------------------------\n");
												//prt(head);
											}
									}

								if(state==2)
									{
										if((fp_keyb=fopen(name_out,"w"))!=NULL)
											{
												keyb_enter(fp_keyb, br_1, state);
												printf("The file is created");
											}
										if((fp_keyb=fopen(name_out,"r"))!=NULL)
											{
												head=MakeListFromTxt(head, fp_keyb);
												 if(head==NULL)
												   {
														printf("\n������ ��� ����������� �� ������� �� ������������!\n");
														goto et_1;
												   }
											   else
												printf("\n�������� � �������� �������!\n");
											}
									}
								break;
				}
			}while(mode_2!=4);
			break;
     
			case 2:
				
				head=add(head);

				if(head!=NULL) printf("\n������� �� ��������� �� ������� ��������!\n");
				
				else
										{
											printf("������ ��� ����� �� ������� �� ���������!");
											goto et_1;
										}
			break;
			case 3:
				printf("\n�������� ��� �� ���������: ");
				scanf("%lld", &del_egn);

				head=rabotnik_del(head, del_egn);

				if(head!=NULL) printf("\n������� �� ��������� �� ������� �������!\n");
				
				else
										{
											printf("������ ��� ��������� �� ������� �� ���������!");
											goto et_1;
										}
				break;

			case 4:
				do{
				mode_3=menu(menu_3);
				switch(mode_3)
					{
						case 1:	printf("\n�������� ��� �� ���������: ");
							scanf("%20s", print_imena);
							print_info_imena(head, print_imena);
								break;

						case 2:	printf("\n�������� ��� �� ���������: ");
							scanf("%lld", &print_egn);
							print_info_egn(head, print_egn);
								break;
					}
			}while(mode_3!=3);
				break;
		    case 5:
								do{
									printf("\n---===����� �� ������������===---\n\n");
									printf("<1> - � ������� ����.\n");
									printf("<2> - � ������� ���� ����.\n");
									printf("\n�������� �� �����: ");
									scanf("%d", &state1);
								}while(state1<1 || state1>2);
							
								printf("\n�������� ��� �� ����� �� �����:");
								scanf("%s", name_out);
								if(state1==1)
									{
										if((fp_out=fopen(name_out,"w+b"))!=NULL)
										{
											write_to_dat(fp_out, head);
											printf("\nThe file is created\n");
										}

										else
										{
											printf("������ ��� ����� ��� ����.");
											goto et_1;
										}
									}
								if(state1==2)
									{
										if((fp_out=fopen(name_out,"w"))!=NULL)
										{
											write_to_txt(fp_out, head);
											printf("\nThe file is created\n");
										}

										else
										{
											printf("������ ��� ����� ��� ����.");
											goto et_1;
										}
									}

					
				break;

			case 6:
									if(head==NULL)
										   {
												printf("\n���� ������� ������!\n");
												goto et_1;
										   }
									   else
									prt(head);
			break;

			case 7:
									if(head==NULL)
										   {
												printf("\n���� ������� ������!\n");
												goto et_1;
										   }
									   else

									head=sort(head);

									if(head==NULL)
										   {
												printf("\n������ ��� ����������� �� �������!\n");
												goto et_1;
										   }
									else
										printf("\n����������� �� ������� � �������!\n");
			break;

			case 8:
									if(head==NULL)
										   {
												printf("\n���� ������� ������!\n");
												goto et_1;
										   }
									   else{
											do{
												printf("\n�������� �������: ");
												scanf("%d", &age);
											}while(age<=0);

											br_r=broi(head, age);

											if(br_r==0)
												   {
														printf("\n���� ���������, ��������� ����� �� �������� <%d> ������!\n", age);
														goto et_1;
												   }
											else
												printf("\n�����������, ��������� ����� �� �������� <%d> ������ ��: %d\n", age, br_r);
										}
			break;
		}
	}while (mode != 9);
}


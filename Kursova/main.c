#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "func.h"

//------------- менюта -----------------------
char *txt_menu_g[]=
{
	  "---===MENU===---",
		"Въвеждане на информацията",
		"Въвеждане на данните за нов работник",
		"Изтриване на данните за работник",
		"Извеждане на информацията за работник",
		"Записване на данните",
		"Изписване на данните за всички работници",
		"Сортиране на работниците според трудовия стаж",
		"Определяне на броя на работниците, постъпили на работа преди да навършат определена възраст",
		"Exit",
		NULL
};

char *menu_2[]=
{
	  "---===Избор на входен файл===---",
		"Текстов файл",
		"Двоичен файл",
		"От клавиатурата",
		"Назад",
		NULL
};

char *menu_3[]=
{
	  "---===Изписване на информацията за работник===---",
		"По име",
		"По ЕГН",
		"Назад",
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
						case 1:	printf("\nВъведете име на текстовия файл: ");
								scanf("%s",name_file);
								if ( (fp_in=fopen(name_file,"rt")) == NULL )
								   printf ("\nГрешка: няма отворен файл !!!\n");
								else
								   {
									   printf ("\nOK - Файлът %s е отворен!\n", name_file);
									   head=MakeListFromTxt(head, fp_in);
									    if(head==NULL)
										   {
												printf("\nГРЕШКА ПРИ СЪЗДАВАНЕТО НА СПИСЪКА ОТ ТЕКСТОВ ФАЙЛ!\n");
												goto et_1;
										   }
									   else
										printf("\nСписъкът е създаден успешно!\n");
									   //prt(head);
									}
								break;

						case 2:	printf("\nВъведете име на двоичния файл: ");
								scanf("%s",name_file);
								if ( (fp_in=fopen(name_file,"rb")) == NULL )
								   printf ("\nГрешка: няма отворен файл !!!\n");
								else
								   {
									   printf ("\nOK - Файлът %s е отворен!\n", name_file);
									   head=MakeListFromDat(head, fp_in);
									   if(head==NULL)
									   {
											printf("\nГРЕШКА ПРИ СЪЗДАВАНЕТО НА СПИСЪКА ОТ ДВОИЧЕН ФАЙЛ!\n");
											goto et_1;
									   }
									   else
										printf("\nСписъкът е създаден успешно!\n");
									   //prt(head);
									}
								break;
						case 3:	
								do{
									printf("\n---===Запис на информацията===---\n\n");
									printf("<1> - В двоичен файл.\n");
									printf("<2> - В текстов файл файл.\n");
									printf("\nИзберете на режим: ");
									scanf("%d", &state);
								}while(state<1 || state>2);
							
								printf("\nВъведете име на файла за запис:");
								scanf("%s", name_out);

								printf("\nВъведете броя на записите:");
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
														printf("\nГРЕШКА ПРИ СЪЗДАВАНЕТО НА СПИСЪКА ОТ КЛАВИАТУРАТА!\n");
														goto et_1;
												   }
											   else
												printf("\nСписъкът е създаден успешно!\n");
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
														printf("\nГРЕШКА ПРИ СЪЗДАВАНЕТО НА СПИСЪКА ОТ КЛАВИАТУРАТА!\n");
														goto et_1;
												   }
											   else
												printf("\nСписъкът е създаден успешно!\n");
											}
									}
								break;
				}
			}while(mode_2!=4);
			break;
     
			case 2:
				
				head=add(head);

				if(head!=NULL) printf("\nДанните за работника са успешно добавени!\n");
				
				else
										{
											printf("Грешка при запис на данните на работника!");
											goto et_1;
										}
			break;
			case 3:
				printf("\nВъведете ЕГН на работника: ");
				scanf("%lld", &del_egn);

				head=rabotnik_del(head, del_egn);

				if(head!=NULL) printf("\nДанните за работника са успешно изтрити!\n");
				
				else
										{
											printf("Грешка при изтриване на данните на работника!");
											goto et_1;
										}
				break;

			case 4:
				do{
				mode_3=menu(menu_3);
				switch(mode_3)
					{
						case 1:	printf("\nВъведете име на работника: ");
							scanf("%20s", print_imena);
							print_info_imena(head, print_imena);
								break;

						case 2:	printf("\nВъведете ЕГН на работника: ");
							scanf("%lld", &print_egn);
							print_info_egn(head, print_egn);
								break;
					}
			}while(mode_3!=3);
				break;
		    case 5:
								do{
									printf("\n---===Запис на информацията===---\n\n");
									printf("<1> - В двоичен файл.\n");
									printf("<2> - В текстов файл файл.\n");
									printf("\nИзберете на режим: ");
									scanf("%d", &state1);
								}while(state1<1 || state1>2);
							
								printf("\nВъведете име на файла за запис:");
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
											printf("Грешка при запис във файл.");
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
											printf("Грешка при запис във файл.");
											goto et_1;
										}
									}

					
				break;

			case 6:
									if(head==NULL)
										   {
												printf("\nНяма въведен списък!\n");
												goto et_1;
										   }
									   else
									prt(head);
			break;

			case 7:
									if(head==NULL)
										   {
												printf("\nНяма въведен списък!\n");
												goto et_1;
										   }
									   else

									head=sort(head);

									if(head==NULL)
										   {
												printf("\nГрешка при сортирането на списъка!\n");
												goto et_1;
										   }
									else
										printf("\nСортирането на списъке е успешно!\n");
			break;

			case 8:
									if(head==NULL)
										   {
												printf("\nНяма въведен списък!\n");
												goto et_1;
										   }
									   else{
											do{
												printf("\nВъведете възраст: ");
												scanf("%d", &age);
											}while(age<=0);

											br_r=broi(head, age);

											if(br_r==0)
												   {
														printf("\nНяма работници, постъпили преди да навършат <%d> години!\n", age);
														goto et_1;
												   }
											else
												printf("\nРаботниците, постъпили преди да навършат <%d> години са: %d\n", age, br_r);
										}
			break;
		}
	}while (mode != 9);
}


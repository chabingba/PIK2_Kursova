#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
node *MakeListFromDat(node *head, FILE *fp_in)
{
	node *p;

		do{
			p=(node *)malloc(sizeof(node));
			if(p==0)
			{
				printf("\nГРЕШКА!\n");
				exit(0);
			}
			else
				p->next=NULL;

			if(!(fread(&(p->prs),sizeof(rabotnik),1,fp_in)))
				{
					free(p); break;
				}

				p->next=head;
				head = p;
		}while(1);

		return head;
}

node *MakeListFromTxt(node *head, FILE *fp_in)
{
	node *p;

		do{
			p=(node *)malloc(sizeof(node));
			if(p==0)
			{
				printf("\nГРЕШКА!\n");
				exit(0);
			}
			else
				p->next=NULL;

			fscanf(fp_in, "%s\n%lld\n%s\n%d\n%d\n%d\n%f\n", p->prs.imena, &(p->prs.egn), p->prs.rojdeno_mqsto, &(p->prs.yy), &(p->prs.mm), &(p->prs.dd), &(p->prs.zaplata));
			

				p->next=head;
				head = p;
		}while(!feof(fp_in));

		return head;
}

node *add(node *head)
{
	node *hlp;
	rabotnik p;
	int flag_visokosna=0;

									fflush(stdin);
									printf ("\nВъведете имена: ");
									scanf("%20[^\r\n]", p.imena);
									fflush(stdin);
									printf("\nВъведете ЕГН: ");
									scanf("%lld",&(p.egn));
									fflush(stdin);
									printf ("\nВъведете рождено място: ");
									scanf("%70[^\r\n]", p.rojdeno_mqsto);
									fflush(stdin);
									do{
										printf("\nВъведете година на постъпване: ");
										scanf("%d",&(p.yy));
										fflush(stdin);
									}while(p.yy>2013);
									if((p.yy)%4==0 || ((p.yy)%4==0 && (p.yy)%400==0)) flag_visokosna=1;
									
									if(flag_visokosna==1)
									{
											do{
												printf("\nВъведете месец на постъпване: ");
												scanf("%d",&(p.mm));
												fflush(stdin);
											}while(p.mm>12);

											switch(p.mm)
											{
											case 1:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 2:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>29);
												break;
											case 3:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 4:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 5:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 6:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 7:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 8:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 9:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 10:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 11:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 12:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											}
									}

									if(flag_visokosna==0)
									{
											do{
												printf("\nВъведете месец на постъпване: ");
												scanf("%d",&(p.mm));
											}while(p.mm>12);

											switch(p.mm)
											{
											case 1:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 2:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>28);
												break;
											case 3:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 4:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 5:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 6:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 7:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 8:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 9:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 10:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 11:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 12:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											}
									}

												do{
													printf("\nВъведете заплата: ");
													scanf("%f",&(p.zaplata));
												}while(p.zaplata<0);

												if(!(hlp= (node *)malloc(sizeof(node)))) {printf("\nГрешка при добавяне на данните за работника!\n");}
													hlp->prs=p;
													hlp->next=head;
													head=hlp;
												return head;


}

node *rabotnik_del(node *head, long long int egn_remove)
{
	int flag=0;
	node *currP, *prevP;

			currP=(node *)malloc(sizeof(node));
			if(currP==0)
			{
				printf("\nГРЕШКА!\n");
				exit(0);
			}
			prevP=(node *)malloc(sizeof(node));
			if(prevP==0)
			{
				printf("\nГРЕШКА!\n");
				exit(0);
			}
	prevP = NULL;

 
  for (currP = head; currP != NULL; prevP = currP, currP = currP->next)
  {

	  if (currP->prs.egn==egn_remove)
	  {
		  if (prevP == NULL)
			  {
					head = currP->next;
			  }
	  
		  else
			  {
				prevP->next = currP->next;
			  }
	  }
  }
	
	  free(currP);
      return head;
}

node *sort(node *head)
{
	int br=1, i;
	node *br_1, *crnt, *temp;
	br_1=(node *)malloc(sizeof(node));
	crnt=(node *)malloc(sizeof(node));
	temp=(node *)malloc(sizeof(node));
	br_1=head;
	while((br_1->next)!=NULL)
	{
		br++;
		br_1=br_1->next;
	}
	for(i=0; i<br; i++)
	{
		for(crnt=head; (crnt->next)!=NULL; crnt=crnt->next)
		{
			if (crnt->prs.yy < (crnt->next->prs.yy))
            {
				temp->prs = crnt->prs;
				crnt->prs = crnt->next->prs;
				crnt->next->prs = temp->prs;
            }
			else if ((crnt->prs.yy == (crnt->next->prs.yy))&&(crnt->prs.mm < (crnt->next->prs.mm)))
            {
				temp->prs = crnt->prs;
				crnt->prs = crnt->next->prs;
				crnt->next->prs = temp->prs;
            }
			else if ((crnt->prs.yy == (crnt->next->prs.yy))&&(crnt->prs.mm == (crnt->next->prs.mm))&&(crnt->prs.dd < (crnt->next->prs.dd)))
            {
				temp->prs = crnt->prs;
				crnt->prs = crnt->next->prs;
				crnt->next->prs = temp->prs;
            }
		}
	}
	return head;
}

int broi(node *head, int age)
{
	int broi=0, i, yy_i;
	char temp[11], yy[2];
	node *crnt;

		crnt=(node *)malloc(sizeof(node));

			if(crnt==0)
				{
					printf("\nГРЕШКА!\n");
					exit(0);
				}

	for(crnt=head; crnt!=NULL; crnt=crnt->next)
	{
		sprintf(temp, "%lld", crnt->prs.egn);
		yy[0]=temp[0];
		yy[1]=temp[1];
		yy_i=atoi(yy);
		if(yy_i>13) yy_i=1900+yy_i;
		printf("\n%d\n", yy_i);
		if((crnt->prs.yy-yy_i)<age) broi++;
	}

	return broi;
}

void print_info_egn(node *head, long long int egn_prt)
{
	node *crnt;

	crnt=(node *)malloc(sizeof(node));
			if(crnt==0)
			{
				printf("\nГРЕШКА!\n");
				exit(0);
			}
			else
				crnt=head;
			for(;;)
			{
				if(crnt->prs.egn==egn_prt)
				{
					printf("\nДанни за работник с ЕГН <%lld>:\n\nИмена: %s\nРождено място: %s\nДата на постъпване: %d/%d/%d\nЗаплата: %6.2f euro\n\n", crnt->prs.egn, crnt->prs.imena, crnt->prs.rojdeno_mqsto, crnt->prs.yy, crnt->prs.mm, crnt->prs.dd, crnt->prs.zaplata);
					break;
				}
				crnt=crnt->next;
			}
}

void print_info_imena(node *head, char print_name[])
{
	node *crnt;

	crnt=(node *)malloc(sizeof(node));
			if(crnt==0)
			{
				printf("\nГРЕШКА!\n");
				exit(0);
			}
			else
				crnt=head;
			do{
				if(strcmp(crnt->prs.imena, print_name)==0)
				{
					printf("\nДанни за работник <%s>:\n\nЕГН: %lld\nРождено място: %s\nДата на постъпване: %d/%d/%d\nЗаплата: %6.2f euro\n\n", crnt->prs.imena, crnt->prs.egn, crnt->prs.rojdeno_mqsto, crnt->prs.yy, crnt->prs.mm, crnt->prs.dd, crnt->prs.zaplata);
				}
				crnt=crnt->next;
			}while(crnt);
}

void keyb_enter(FILE *fp_keyb, int br_1, int mode)
{
	rabotnik p;
	int flag_visokosna=0;
							do{
									fflush(stdin);
									printf ("\nВъведете имена: ");
									scanf("%20[^\r\n]", p.imena);
									fflush(stdin);
									printf("\nВъведете ЕГН: ");
									scanf("%lld",&(p.egn));
									fflush(stdin);
									printf ("\nВъведете рождено място: ");
									scanf("%70[^\r\n]", p.rojdeno_mqsto);
									fflush(stdin);
									do{
										printf("\nВъведете година на постъпване: ");
										scanf("%d",&(p.yy));
										fflush(stdin);
									}while(p.yy>2013);
									if((p.yy)%4==0 || ((p.yy)%4==0 && (p.yy)%400==0)) flag_visokosna=1;
									
									if(flag_visokosna==1)
									{
											do{
												printf("\nВъведете месец на постъпване: ");
												scanf("%d",&(p.mm));
												fflush(stdin);
											}while(p.mm>12);

											switch(p.mm)
											{
											case 1:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 2:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>29);
												break;
											case 3:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 4:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 5:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 6:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 7:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 8:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 9:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 10:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 11:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 12:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											}
									}

									if(flag_visokosna==0)
									{
											do{
												printf("\nВъведете месец на постъпване: ");
												scanf("%d",&(p.mm));
											}while(p.mm>12);

											switch(p.mm)
											{
											case 1:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 2:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>28);
												break;
											case 3:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 4:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 5:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 6:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 7:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 8:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 9:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 10:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											case 11:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>30);
												break;
											case 12:
												do{
													printf("\nВъведете ден на постъпване: ");
													scanf("%d",&(p.dd));
												}while(p.dd>31);
												break;
											}
									}

												do{
													printf("\nВъведете заплата: ");
													scanf("%f",&(p.zaplata));
												}while(p.zaplata<0);


									if(mode==1)	fwrite(&p, sizeof(rabotnik), 1, fp_keyb);
									if(mode==2)	fprintf(fp_keyb, "%s\n%lld\n%s\n%d\n%d\n%d\n%f\n", p.imena, p.egn, p.rojdeno_mqsto, p.yy, p.mm, p.dd, p.zaplata);

									--br_1;
								}while (br_1!=0);

								fclose(fp_keyb);

}

void prt(node *crnt)
{
	printf("\nИнформация за работници:\n\n");
	printf("\n--------------------------------------------\n\n\n");
	while(crnt)
	{
		printf("Имена: %s\nЕГН: %lld\nРождено място: %s\nДата на постъпване: %d/%d/%d\nЗаплата: %6.2f euro\n\n",crnt->prs.imena,crnt->prs.egn,crnt->prs.rojdeno_mqsto,crnt->prs.yy,crnt->prs.mm,crnt->prs.dd,crnt->prs.zaplata);
		crnt=crnt->next;
	}
	printf("\n--------------------------------------------\n");
}

void write_to_dat(FILE *fp_out, node *crnt)
{
	while(crnt)
	{
		fwrite(&crnt->prs, sizeof(rabotnik),1,fp_out);
		crnt=crnt->next;
	}
}

void write_to_txt(FILE *fp_out, node *crnt)
{
	while(crnt)
	{
		fprintf(fp_out, "%s\n%lld\n%s\n%d\n%d\n%d\n%f\n", crnt->prs.imena, crnt->prs.egn, crnt->prs.rojdeno_mqsto, crnt->prs.yy, crnt->prs.mm, crnt->prs.dd, crnt->prs.zaplata);
		crnt=crnt->next;
	}
}
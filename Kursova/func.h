typedef struct{
	char imena[20];
	long long int egn;
	char rojdeno_mqsto[70];
	unsigned int dd;
	unsigned int mm;
	unsigned int yy;
	float zaplata;
}rabotnik;

typedef struct node{ 
	rabotnik prs;
	struct node *next;
}node;

node *MakeListFromDat(node *head, FILE *fp_in);

node *MakeListFromTxt(node *head, FILE *fp_in);

node *add(node * head);

node *rabotnik_del(node * head, long long int egn_remove);

node *sort(node *head);

int broi(node *head, int age);

void keyb_enter(FILE *fp_keyb, int br_1, int mode);

void prt(node *crt);

void print_info_egn(node *head, long long int egn_prt);

void print_info_imena(node *head, char print_name[]);

void write_to_dat(FILE *fp_out, node *crt);

void write_to_txt(FILE *fp_out, node *crt);

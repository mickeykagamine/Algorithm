#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//------------------------------�ʷ�����--------------------------------------- 
int type_is_char=2;
char token[100]={};
char token2[100]={};
char Char;
int num;
char Char2;
int line=1; 
FILE *fp;
char StringTable[100][100];
int String_count=0;
void add_String_Table(){
	strcpy(StringTable[String_count++],token);
}
int check_String_Table(char array[100]){
	int i=0;
	for(i=0;i<String_count;i++){
		if(strcmp(array,StringTable[i])==0){
			return i;
		}
	}
}
void lowercase(){
    int i=0;
    for(i=0;i<100;i++){
        if(token[i]>='A'&&token[i]<='Z'){
            token2[i]=token[i]+'a'-'A';
        }
        else token2[i]=token[i];
    }
}

void clearToken(){
	int i;
	for(i=0;i<100;i++){
		token[i]=NULL;
		token2[i]=NULL;
	}
	return;
}

int isString(char a){
	if(a==32|a==33|(a>=35&&a<=126)){
		return 1;
	}
	else
		return 0;
}

int isLetter(char a){
	if((a>='A'&&a<='Z')|(a>='a'&&a<='z')|a=='_'){
		return 1;
	}
	else
		return 0;
}

int isSpace(char a){
	if(a==' '){
		return 1;
	}
	else
		return 0;
}

int isTab(char a){
	if(a=='\t'){
		return 1;
	}
	else
		return 0;
}

int isEndofline(char a){
	if(a=='\0'){
		return 1;
	}
	else
		return 0;
}

int isNewline(char a){
	if(a=='\n'){
		return 1;
	}
	else
		return 0;
}

int isDigit(char a){
	if(a>='1'&&a<='9'){
		return 1;
	}
	else
		return 0;
}

int isZero(char a){
	if(a=='0'){
		return 1;
	}
	else
		return 0;
}

int isPlus(char a){
	if(a=='+'){
		return 1;
	}
	else
		return 0;
}

int isSubb(char a){
	if(a=='-'){
		return 1;
	}
	else
		return 0;
}

int isDiv(char a){
	if(a=='/'){
		return 1;
	}
	else
		return 0;
}

int isStar(char a){
	if(a=='*'){
		return 1;
	}
	else
		return 0;
}

int isCom(char a){
	if(a==','){
		return 1;
	}
	else
		return 0;
}

int isLpar(char a){
	if(a=='('){
		return 1;
	}
	else
		return 0;
}

int isRpar(char a){
	if(a==')'){
		return 1;
	}
	else
		return 0;
}

int isLbrace(char a){
	if(a=='{'){
		return 1;
	}
	else
		return 0;
}

int isRbrace(char a){
	if(a=='}'){
		return 1;
	}
	else
		return 0;
}

int isLess(char a){
	if(a=='<'){
		return 1;
	}
	else
		return 0;
}

int isMore(char a){
	if(a=='>'){
		return 1;
	}
	else
		return 0;
}

int isExclamation(char a){
	if(a=='!'){
		return 1;
	}
	else
		return 0;
}

int isSeparator(char a){
	if(a==';'){
		return 1;
	}
	else
		return 0;
}

int isEqual(char a){
	if(a=='='){
		return 1;
	}
	else
		return 0;
}

int isQuote(char a){
	if(a=='\''){
		return 1;
	}
	else
		return 0;
}

int isDoublequote(char a){
	if(a=='\"'){
		return 1;
	}
	else
		return 0;
}

int isLbracket(char a){
	if(a=='['){
		return 1;
	}
	else
		return 0;
}

int isRbracket(char a){
	if(a==']'){
		return 1;
	}
	else
		return 0;
}

int isColon(char a){
	if(a==':'){
		return 1;
	}
	else
		return 0;
}

void catToken(char b){
	char test[10]={};
	test[0]=b;
	strcat(token,test);
	return;
}

void retract(char a,FILE* p){
	ungetc(a,p);
	return;
}

int transNum(){
	int i=0;
	int result=0;
	for(i=0;i<100;i++){
		if (token[i]>='0'&&token[i]<='9'){
			result=result*10+token[i]-48;
    	}
    	else{
    		break;
		}
	}
	return result;
}

int reserver(){
	char s1[10]="while";
	char s2[10]="switch";
	char s3[10]="case";
	char s4[10]="do";
	char s5[10]="if";
	char s6[10]="int";
	char s7[10]="char";
	char s18[10]="const";
	char s19[10]="scanf";
	char s20[10]="printf";
	char s21[10]="return";
	char s22[10]="void";
	char s23[10]="main";
	lowercase();
	if(strcmp(token2,s1)==0){
		return 1;
	}

	else if(strcmp(token2,s2)==0){
		return 2;
	}

	else if(strcmp(token2,s3)==0){
		return 3;
	}

	else if(strcmp(token2,s4)==0){
		return 4;
	}

	else if(strcmp(token2,s5)==0){
		return 5;
	}

	else if(strcmp(token2,s6)==0){
		return 6;
	}

	else if(strcmp(token2,s7)==0){
		return 7;
	}

	else if(strcmp(token2,s18)==0){
		return 18;
	}

	else if(strcmp(token2,s19)==0){
		return 19;
	}

	else if(strcmp(token2,s20)==0){
		return 20;
	}

	else if(strcmp(token2,s21)==0){
		return 21;
	}

	else if(strcmp(token2,s22)==0){
		return 22;
	}

	else if(strcmp(token2,s23)==0){
		return 23;
	}

	else return 0;
}

int getsym() /*����������*/
{	
		
		Char=fgetc(fp);
		if(Char!=EOF){
		int symbol=0;
		clearToken();
		num=0;
		while(isSpace(Char)||isNewline(Char)||isTab(Char)||isEndofline(Char)){
			if(isNewline(Char)){
//!				printf("\n");
				line++;
			}
			Char=fgetc(fp); /*��ȡ�ַ��������ո񡢻��к�Tab*/
		}
	 	if(isLetter(Char)) /*�жϵ�ǰ�ַ��Ƿ���һ����ĸ*/
		{
			while(isLetter(Char)||isDigit(Char)||isZero(Char)) /*���ַ�ƴ�ӳ��ַ���*/
	 		{
				catToken(Char);
				Char=fgetc(fp);
			}
			retract(Char,fp); /*ָ�����һ���ַ�*/
			int resultValue = reserver(); /*resultValue�ǲ��ұ����ֵķ���ֵ*/
			if(resultValue==0){
				lowercase();
				symbol= 8; /*resultValue=0��token�е��ַ���Ϊ��ʶ��*/				
//!  			printf("%d IdSym ",symbol);
//!				int j=0;
//!				for(j=0;token[j]!=NULL;j++){
//!					printf("%c",token[j]);
//!				}				
//!				printf(" ");
				return symbol;
				}
	 		else {
		 		symbol= resultValue; /*����token�е��ַ���Ϊ������*/
		 		//printf("%d ",symbol)
				if(symbol==1){
//!		 			printf("%d WhileSym while ",symbol );	
				}
				else if(symbol==2){
//!		 			printf("%d SwitchSym switch ",symbol );	
				}
				else if(symbol==3){
//!		 			printf("%d CaseSym case ",symbol );	
				}
				else if(symbol==4){
//!		 			printf("%d DoSym do ",symbol );	
				}
				else if(symbol==5){
//!		 			printf("%d IfSym if ",symbol );	
				}
				else if(symbol==6){
//!		 			printf("%d INTSym int ",symbol );	
				}
				else if(symbol==7){
//!		 			printf("%d CHARSym char ",symbol );	
				}
				else if(symbol==18){
//!		 			printf("%d ConstSym const ",symbol );	
				}
				else if(symbol==19){
//!		 			printf("%d ScanSym scanf ",symbol );	
				}
				else if(symbol==20){
//!		 			printf("%d PrintSym printf ",symbol );	
				}
				else if(symbol==21){
//!		 			printf("%d ReturnSym return ",symbol );	
				} 
				else if(symbol==22){
//!		 			printf("%d VoidSym void ",symbol );	
				}
				else if(symbol==23){
//!		 			printf("%d MainSym main ",symbol );	
				}
				return symbol;
			}
	 	}
	 	else if(isDigit(Char)) /*�жϵ�ǰ�ַ��Ƿ���һ����������*/
	 	{
			while(isDigit(Char)||isZero(Char)) /*���ַ�ƴ�ӳ�����*/
		 	{
			 	catToken(Char);
				Char=fgetc(fp);
			}
			retract(Char,fp);
			num= transNum(); /*��token�е��ַ���ת��������*/
			symbol= 9; /*��ʱʶ��ĵ������޷�������*/
//!			printf("%d IntSym %d ",symbol,num );
			return symbol;
	 	}
	 	else if(isZero(Char)) /*�жϵ�ǰ�ַ��Ƿ���0*/
	 	{
			
			Char=fgetc(fp);
			if(isDigit(Char)||isZero(Char)){
				printf("��%d�� �ʷ��������ֲ��ܺ���ǰ�� \n",line);
				retract(Char,fp);
			}
			else{			
				retract(Char,fp);
				num= transNum(); /*��token�е��ַ���ת��������*/
				symbol= 38; /*��ʱʶ�������*/
//!				printf("%d ZeroSym %d ",symbol,num );
				return symbol;
			}
	 	}
		else if(isPlus(Char)){
			symbol=11;
//!			printf("%d PlusSym + ",symbol );
			return symbol;
		}
		else if(isSubb(Char)){
			symbol=10;
//!			printf("%d SubbSym - ",symbol );
			return symbol;
		}
		else if(isDiv(Char)){
			symbol=24;
//!			printf("%d DivSym / ",symbol );
			return symbol;
		}
		else if(isStar(Char)){
			symbol=12;
//!			printf("%d StarSym * ",symbol );
			return symbol;
		}
		else if(isCom(Char)){
			symbol=13;
//!			printf("%d ComSym , ",symbol );
			return symbol;
		}
		else if(isLpar(Char)){
			symbol=14;
//!			printf("%d LparSym ( ",symbol );
			return symbol;
		}
		else if(isRpar(Char)){
			symbol=15;
//!			printf("%d RparSym ) ",symbol );
			return symbol;
		}
		else if(isLbrace(Char)){
			symbol=16;
//!			printf("%d LbraceSym { ",symbol );
			return symbol;
		}
		else if(isRbrace(Char)){
			symbol=17;
//!			printf("%d RbraceSym } ",symbol );
			return symbol;
		}
		else if(isSeparator(Char)){
			symbol=32;
//!			printf("%d SeparatorSym ; ",symbol );
			return symbol;
		}
		else if(isQuote(Char)){
			Char=fgetc(fp);
			if(isPlus(Char)|isSubb(Char)|isStar(Char)|isDiv(Char)|isLetter(Char)|isZero(Char)|isDigit(Char)) /*���ַ�*/
	 		{
				Char2=Char;
				Char=fgetc(fp);				
				if(isQuote(Char)){
				symbol=37;
//!				printf("%d CharSym /'%c/'",symbol,Char2 );
				return symbol;
				}
				else{
					retract(Char,fp); /*ָ�����һ���ַ�*/
					printf("��%d�� �ʷ������ַ�����ֻ����һ���ַ� \n",line);
				}
			}
			else{
				retract(Char,fp); /*ָ�����һ���ַ�*/
				printf("��%d�� �ʷ����󣡷Ƿ����ַ����� \n ",line);
			}
			
		}
		else if(isDoublequote(Char)){
			Char=fgetc(fp);
			int count=0;
			while(isString(Char)&&count<=100) /*���ַ�ƴ�ӳ��ַ���*/
	 		{	
	 			if(Char==92){
	 				catToken(Char);
				 }
	 			count++;
			 	catToken(Char);
				Char=fgetc(fp);
			}
			if(count>100){
				printf("��%d�� �ʷ������ַ��������������ޣ�100�� \n ",line);
			}
			else if(isDoublequote(Char)){
				symbol=35;
//!	     		printf("%d StringSym \"",symbol ); 
	     		int k;
//!	     		for(k=0;token[k]!=NULL;k++){
//!					printf("%c",token[k]);
//!				}
//!				printf("\" " ); 
				add_String_Table();
				return symbol;
			}
			else{
				retract(Char,fp); /*ָ�����һ���ַ�*/
				printf("��%d�� �ʷ������ַ����г����˷Ƿ��ַ� \n ",line);
			}			
		}
		else if(isLbracket(Char)){
			symbol=33;
//!			printf("%d LbracketSym [ ",symbol );
			return symbol;
		}
		else if(isRbracket(Char)){
			symbol=34;
//!			printf("%d RbracketSym ] ",symbol );
			return symbol;
		}
		else if(isColon(Char)){
			symbol=36;
//!			printf("%d ColonSym : ",symbol );
			return symbol;
		}
		else if(isLess(Char)){
			Char=fgetc(fp);
			if(Char=='='){
				symbol=26;
//!			    printf("%d LessOESym <= ",symbol );
			    return symbol;
			}
			else {
				retract(Char,fp);
				symbol=25;
//!			    printf("%d LessSym < ",symbol );
			    return symbol;
			}
		}
		else if(isMore(Char)){
			Char=fgetc(fp);
			if(Char=='='){
				symbol=28;
//!			    printf("%d MoreOESym >= ",symbol );
			    return symbol;
			}
			else {
				retract(Char,fp);
				symbol=27;
//!			    printf("%d MoreSym > ",symbol );
			    return symbol;
			}
		}
		else if(isExclamation(Char)){
			Char=fgetc(fp);
			if(Char=='='){
				symbol=29;
//!			    printf("%d NotESym != ",symbol );
			    return symbol;
			}
			else {
				retract(Char,fp);
				printf("��%d�� �ʷ����󣡾�̾��֮��ֻ�ܽ��ӵȺ� \n",line);
			}
		} 
		else if(isEqual(Char)){
			Char=fgetc(fp);
			if(Char=='='){
				symbol=30;
//!			    printf("%d EQUALSym == ",symbol );
			    return symbol;
			}
			else {
				retract(Char,fp);
				symbol=31;
//!			    printf("%d EqualSym = ",symbol );
			    return symbol;
			}
		}
		else{
			printf("��%d�� �ʷ����󣡷Ƿ����ַ� \n  ",line);
		}
		return -1;
	}
	
 }
 
//------------------------------�﷨����--------------------------------------- 
int Sym=0;//Ŀǰ�����ķ��ŵı�ʶ��
int KIND=0;
int TYPE=0;
int LEVEL=0; 
int fun_space=0; //����ں���ͷ�ĵ�ַλ�� 

struct SYMBOL{
	char Name[100];
	int lev;
	int kind;
	int type;
	int addr;
	int temp;
	int para_num;
};
struct SYMBOL SymbolTable[1000];//�����м�����ʱ��


int Statement_SymbolTable_Addr(char token[100],int level,int kind);
int Statement_SymbolTable3_v(char token[100],int level,int kind,int i);
int Statement_SymbolTable3_fun(char token[100],int level,int kind);
struct Operand{
	int addr;
	int type;
	int kind;
}; 

struct Quadruple{
	int action;
	int first;
	int second;
	int result; 
//	struct Operand first;
//	struct Operand second;
//	struct Operand result;
	struct Quadruple* next;
	struct Quadruple* last;
}; 

struct function{
	char name[100];
	int n;
};

struct function FUN[100]={};
int function_count=0;

struct Quadruple *head=NULL,*p,*q;
struct Quadruple *head2=NULL;
//void add_quadruple(int act,struct Operand one,struct Operand two,struct Operand three){
void add_quadruple(int act,int one,int two,int three){	
	if (head==NULL){
		head=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		head->action=act;
		head->first=one;
		head->second=two;
		head->result=three;
//		head->first=one;
//		head->second=two;
//		head->result=three;
		head->next=head;
		head->last=head;
	}
	else{
		for(p=head;p->next!=head;p=p->next){
			;
		}
		q=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		q->action=act;
		q->first=one;
		q->second=two;
		q->result=three;
		
		q->next=head;
		q->last=p;
		p->next=q;
		head->last=q;		
	}
}

void add_quadruple_2(int act,int one,int two,int three){	
	if (head2==NULL){
		head2=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		head2->action=act;
		head2->first=one;
		head2->second=two;
		head2->result=three;
//		head->first=one;
//		head->second=two;
//		head->result=three;
		head2->next=head2;
		head2->last=head2;
	}
	else{
		for(p=head2;p->next!=head2;p=p->next){
			;
		}
		q=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		q->action=act;
		q->first=one;
		q->second=two;
		q->result=three;
		
		q->next=head2;
		q->last=p;
		p->next=q;
		head2->last=q;		
	}
}
void add_head_quadruple(int act,int one,int two,int three){	
	if (head==NULL){
		head=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		head->action=act;
		head->first=one;
		head->second=two;
		head->result=three;
		head->next=head;
		head->last=head;
	}
	else{
		q=(struct Quadruple*)malloc(sizeof(struct Quadruple));
		q->action=act;
		q->first=one;
		q->second=two;
		q->result=three;
		q->next=head;
		q->last=head->last;
		head->last->next=q;
		head->last=q;
		head=q;
	}
		
}
void delete_quadruple(){
	if(head!=NULL){
		for(p=head;p->next!=head;p=p->next){
			;
		}
		
	}
}

void error_effect(){
	
	//declaration_head&statement_head
	while(!(Sym==18|Sym==6|Sym==7|Sym==22|Sym==5|Sym==4|Sym==2|Sym==16|Sym==8|Sym==19|Sym==20|Sym==21)){
		Sym=getsym();
	}
	
}  

void error(int i){
	if(i==1){
		printf("��%d�� �﷨���󣡲���һ�����ͱ�ʶ��\n",line);
	}
	else if(i==2){
		printf("��%d�� �﷨����ȱ����������\n",line);
	}
	else if(i==3){
		printf("��%d�� �﷨���󣡶��������С����\n",line);
	}
	else if(i==4){
		printf("��%d�� �﷨���󣡲���һ����ȷ�ı�ʶ�� \n",line);
	}
	else if(i==5){
		printf("��%d�� �﷨���󣡲���һ����ϵ����� \n",line);
	}
	else if(i==6){
		printf("��%d�� �﷨�����㲻�����з��� \n",line);
	}
	else if(i==7){
		printf("��%d�� �﷨���󣡲���һ������ \n",line);
	}
	else if(i==8){
		printf("��%d�� �﷨���󣡲���һ������ \n",line);
	}
	else if(i==9){
		printf("��%d�� �﷨����ȱ�ٷֺ� \n",line);
	}
	else if(i==10){
		printf("��%d�� �﷨���󣡲���һ����� (�Ŀ�ͷ���ż�)\n",line);
	}
	else if(i==11){
		printf("��%d�� �﷨����ȱ����С���� \n",line);
	}
	else if(i==12){
		printf("��%d�� �﷨����ȱ����С���� \n",line);
	}
	else if(i==13){
		printf("��%d�� �﷨���󣡲���������� \n",line);
	}
	else if(i==14){
		printf("��%d�� �﷨����ȱ�ٱ�����while \n",line);
	}
	else if(i==15){
		printf("��%d�� �﷨���󣡲���ѭ�����  \n",line);
	}
	else if(i==16){
		printf("��%d�� �﷨����ȱ��ð�� \n",line);
	}
	else if(i==17){
		printf("��%d�� �﷨���󣡲����������� \n",line);
	}
	else if(i==18){
		printf("��%d�� �﷨����ȱ���Ҵ����� \n",line);
	}
	else if(i==19){
		printf("��%d�� �﷨����ȱ��������� \n",line);
	}
	else if(i==20){
		printf("��%d�� �﷨���󣡲��������� \n",line);
	} 
	else if(i==21){
		printf("��%d�� �﷨����ȱ�ٵȺ� \n",line);
	} 
	else if(i==22){
		printf("��%d�� �﷨���󣡲��Ǹ�ֵ��� \n",line);
	} 
	else if(i==23){
		printf("��%d�� �﷨���󣡲��Ƕ���� \n",line);
	} 
	else if(i==24){
		printf("��%d�� �﷨���󣡲���д��� \n",line);
	}
	else if(i==25){
		printf("��%d�� �﷨���󣡲��Ƿ������ \n",line);
	}
	else if(i==26){
		printf("��%d�� �﷨���󣡴���Ķ��壨���Ǳ���Ҳ�����з���ֵ������ \n",line);
	}
	else if(i==27){
		printf("��%d�� �﷨�����Ҳ���main����\n",line);
	}
	else if(i==28){
		printf("��%d�� �﷨���󣡲���һ����ȷ�ĳ��򣨵Ŀ�ͷ�����ţ�\n",line);
	}
	else if(i==29){
		printf("��%d�� �﷨���󣡴�����޷���ֵ��������\n",line);
		
	}
	else if(i==30){
		printf("��%d�� �﷨���󣡲���һ���ַ�����\n",line);
	}
	else if(i==31){
		printf("��%d�� �﷨����ȱ�ٳ���������const\n",line);
	}
	else if(i==32){
		printf("��%d�� �﷨���󣡴���ı�������\n",line); 
	}
	else if(i==33){
		printf("��%d�� �﷨���󣡲��Ǹ�����䣨�Ŀ�ͷ�����ţ�\n",line);
	}
	else{
		printf("��%d�� �﷨����!\n",line);
	} 
	error_effect(); 
}

 
void TypeIdentifier(){//���ͱ�ʶ�� 
	if(Sym==6|Sym==7){
		if(Sym==6){
			TYPE=1;
		} 
		else{
			TYPE=2;
		}
		Sym=getsym(); 
//!		printf("This is TypeIdentifier���ͱ�ʶ��\n");	
		return;
	}
	else{
		error(1);
		TYPE=0;
	}
 }
 
void Declaration_SymbolTable_fun(char token[100],int level,int kind,int type,int space,int space2);
 void Declaration_SymbolTable_v(char token[100],int level,int kind,int type,int space,int i);
int RelationOperator(){//��ϵ����� (�ǹ�ϵ������ͷ���0 ����-1)
	if(Sym>=25&&Sym<=30){
		int re_Sym=Sym;
		Sym=getsym();
//!		printf("This is RelationOperator��ϵ�����\n");
		return re_Sym;
	}
	else{
		error(5);
	}
} 

int Expression();
int Expression_typecheck();
int exp_type=0;
int ValueParameterTable(int i){//ֵ������ 
	int result_exp=0;
	exp_type=0;
	
	int count=0;
	if(Sym==15){		
//!		printf("This is ValueParameterTableֵ��������\n");
		if(SymbolTable[i+1].kind==4){
			printf("Error! δ���뺯������ ������� ��%d��\n",line); 
		}
		return 0;
	}
	else{					
		while(1){
			count++;
			result_exp=Expression();
//			exp_type=Expression_typecheck(); 
			if(exp_type==3){
				exp_type=1;
			}
			if(SymbolTable[i+count].type!=exp_type){
//				printf("Error!�����������Ͳ��� ������� ��%d��\n",line);
			}
			if(SymbolTable[i+count].kind!=4){
				printf("Error!���������������� ������� ��%d��\n",line); 
			} 
//			printf("push t%d\n",result_exp);
			add_quadruple(20,result_exp,SymbolTable[i+count].addr,0);
			if(Sym==13){
				Sym=getsym();			
			}
			else{
//!				printf("This is ValueParameterTableֵ���������ʽ{,���ʽ}\n");
				return 1;
			}			
		}
	} 
}

int expression_sign=1; 
int operand1_integer=0;
int Integer(){//���� 
	int sign_integer=1;
	if(Sym==38){
		operand1_integer=sign_integer*num;
		Sym=getsym();
//!		printf("This is Integer��������\n");
		return operand1_integer;
	}
	else if(Sym==11|Sym==10){
		if(Sym==11){
			sign_integer=1;
		}
		else{
			sign_integer=-1;
		}
		Sym=getsym();
		if(Sym==9){
			operand1_integer=sign_integer*num;
			Sym=getsym();			
//!			printf("This is Integer�������з�������\n");
			return operand1_integer;
		}
		else if(Sym==38){
			error(6);
		}
		else{
			error(7);
		}
	}
	else if(Sym==9){
		operand1_integer=expression_sign*num;
		Sym=getsym();		
//!		printf("This is Integer�������޷�������\n");
		return operand1_integer;
	}
	else{
		error(7);
	} 	
}
int register_count=0;
int REGISTERMAX=3; 
struct register_table{
	int register_num;
	int temp_num;
};
struct temp_table{
	int temp_num;
	int addr;//��ʱ���� �����ڵ�ַƫ�� 
	int addr_array;//�������ͷ����ƫ�� 
	int temp_num_little;//ûʲô���õĶ��� 
};
struct register_table Register_table[30];
int Temp_table_max=1000;
struct temp_table Temp_table[1000];//�������Ǿ�һ���

int register_table_count=0;
void add_register_table(int a,int b){
	Register_table[register_table_count].register_num=a;
	Register_table[register_table_count].temp_num=b;
	if(register_table_count==REGISTERMAX-1){
		register_table_count=0;
	}
	else{
		register_table_count++;
	}
	
}
void apply_register(int t){
	add_register_table(register_count%REGISTERMAX,t);
	register_count++;
}
int check_register(int t){
	int i=0;
	for(i=0;i<10;i++){
		if(Register_table[i].temp_num==t){
			return Register_table[i].register_num;
		}
	}
	return -1;
}

int apply_count=0;
void add_temp_table(int t,int funspace,int array,int temp_num_little){

	Temp_table[apply_count-1].temp_num=t;
	Temp_table[apply_count-1].addr=funspace;//$�������������ʹ�õ�λ�� 
	Temp_table[apply_count-1].addr_array=array;//Ŀǰ��ʱ���������$sp��ƫ�� 
//	Temp_table[apply_count-1].temp_num_little=temp_num_little; ûʲô���� 
	return ;


}
int check_temp_table(int tempname){//��ʱ������ѯ 
	int i=0;
	for(int i=0;i<Temp_table_max;i++){
		if(tempname==Temp_table[i].temp_num){
			return Temp_table[i].addr;
		}
	}
	return -1;
}

char temporary[10]="t";
int apply_count_2=0;//ÿ���������������ʱ����������  һ�������������� 
void apply(int array){
	if(apply_count!=999){
		apply_count++;
	}
	else{
		apply_count=1;
	}
	
	if(fun_space>1000){
		add_temp_table(apply_count,fun_space+apply_count_2-1000,array,0);
	}
	else{
		add_temp_table(apply_count,fun_space+apply_count_2,array,0);//��һ�����ܵ���ʱ�����ţ��ڶ������ں����ڵ���ʱ�����ţ��������� 
	}
	apply_count_2++;
}

void apply_have_type(int array,int type){
	if(apply_count!=999){
		apply_count++;
	}
	else{
		apply_count=1;
	}
	apply_count_2++;
	if(fun_space>1000){
		add_temp_table(apply_count,fun_space+apply_count_2-1000,array,type);
	}
	else{
		add_temp_table(apply_count,fun_space+apply_count_2,array,type);
	}
}

void clear_apply(){
	apply_count_2=0;
}
char fun_name[100]={"!"};


void ReturnValueFunctionCallStatement();
int result_factor=0;

char operand1_char;
int operand1_fun=1000;
char TokenCopy[100]={};
int result_array=0;
int result_return=-1;

int factor_type=0;

int term_type=0; 
int Factor(){//���� 
	factor_type=0;
	exp_type=0;
	int i;
	int return_type=0;
	//����ֵ 1-��ʶ�� 2-��ʶ��[���ʽ] 3-���� 4-�ַ� 5-��ʶ��(ֵ������) 6-(���ʽ) 
	int result_exp=0;//���ñ��ʽ�� �������ڵĵط� 
	if(Sym==8){
		strcpy(TokenCopy,token2);
		Sym=getsym();
		if(Sym==33){
			i=Statement_SymbolTable3_v(TokenCopy,LEVEL,3,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
			if(i>0){
				if(SymbolTable[i].type==1){
					factor_type=3;
					type_is_char=3;
				}
				else{
					factor_type=SymbolTable[i].type;
				}
			}
			else {
				if(SymbolTable[-i].type==1){
					factor_type=3;
					type_is_char=3;
				}
				else{
					factor_type=SymbolTable[-i].type;
				}
			}
			result_array=0;
			Sym=getsym();
			int type_is_char2=type_is_char; 
			int type_temp=factor_type;
			result_exp=Expression();
			factor_type=type_temp;
			type_is_char=type_is_char2;
			if(Sym==34){
				apply(result_exp);
//!!!!			printf("LOAD t%d ",apply_count);
				int k=0;
				for(k=0;k<strlen(TokenCopy);k++){
//!!!!				printf("%c",TokenCopy[k]);
				}
//!!!!			printf(" t%d\n",result_exp);
				if(i>0){
					add_quadruple(15,SymbolTable[i].addr,apply_count,result_exp); 
				}
			    else{
					add_quadruple(26,SymbolTable[-i].addr,apply_count,result_exp); 
				}
				result_array=apply_count;
				Sym=getsym();
//!				printf("This is Factor���ӣ���ʶ��[���ʽ]\n");
				return 2;
			}
			else{
				error(2);
			}
		}
		else if(Sym==14){
			i=Statement_SymbolTable3_fun(TokenCopy,LEVEL,2);
			if(SymbolTable[i].type==0){
				printf("Error�����ʽ�в��ܵ����޷���ֵ���� �﷨���� ��%d��\n",line); 
			}
			else if(SymbolTable[i].type==1){
				return_type=3;
				ReturnValueFunctionCallStatement();
				factor_type=3; 
				type_is_char=3;
			}
			else{
				ReturnValueFunctionCallStatement();
				factor_type=SymbolTable[i].type;
			}							
			return 5;
		}
		else{
//!			printf("This is Factor���ӣ���ʶ��\n");
			i=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
			if(i<0){
				i=0-i;
			}
			if(SymbolTable[i].type==1){
				factor_type=3;
				type_is_char=3;
			}
			else{
				factor_type=SymbolTable[i].type;
			}
			return 1;
		}
	}
	else if(Sym==37){
		factor_type=2; 
		operand1_char=Char2;
		Sym=getsym();
//!		printf("This is Factor���ӣ��ַ�\n");
		return 4;
	} 
	else if(Sym==14){
		Sym=getsym();		
		result_exp=Expression();
//		exp_type=Expression_typecheck();
		factor_type=exp_type;
		if(Sym==15){
			Sym=getsym();
//!			printf("This is Factor���ӣ�(���ʽ)\n");
			return -result_exp;//����Ϊ���ʽ������Ľ�����ڵļĴ��� 
		}
	}
	else if(Sym==11|Sym==10|Sym==38|Sym==9){
		factor_type=3;
		type_is_char=3;
		Integer();
//!		printf("This is Factor���ӣ�����\n");		
		return 3;
	} 	
	else{
		error(8);
	}
	
}





int Term(){//�� 
	char operand1_symbol[100]={};
	int operand11_integer=0; //����ǰ����һ�������� 
	//��Ӧ��ϵ TokenCopy       --operand1_integer --operand1_char
	//         operand1_symbol-- operand11_integer--operand11_char
	
	int operand11_char=0;
	int operand11_fun=1000;
	int operand11_array=0;
	
	int Connector2=0;//���Ӽ�Ĳ����� ֻ�� * ���� /
	int result_term;
	int result_factor;
	int re_result_factor=0; 
	int sign_term=0;//�Ƿ�ֻ��һ�����Ӿͷ��� 
	int act=0;
	int quadruple_first=0;
	int quadruple_second=0;
	int quadruple_result=0;
	int I=0;
	term_type=0;
	factor_type=0;
	while(1){
		int symcheck=Sym;
		result_factor=Factor();		
//		factor_type=Factor_typecheck(symcheck);
		if(Connector2!=0){
			
			if(Connector2==12){
//!!!!			printf("MULT ");
				act=3;
				int k=0;
				//������1
				if(sign_term==0){
					if(re_result_factor==1){
						I=Statement_SymbolTable3_v(operand1_symbol,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
						apply(0);
					//?	printf("load %d t%d",addr,apply_count);
						if(I>0){
							add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
						}
						else{
							add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
						}
						quadruple_first=apply_count;
						for(k=0;k<strlen(operand1_symbol);k++){
//!!!!						printf("%c",operand1_symbol[k]);
						} 
						
					}
					else if(re_result_factor==3){
//!!!!					printf("%d",operand11_integer);
						apply(0);	
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(16,operand11_integer,apply_count,0);//li
						quadruple_first=apply_count;
					}
					else if(re_result_factor==4){
//!!!!					printf("%d",operand11_char);
						apply(0);					
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(16,operand11_char,apply_count,0);//li
						quadruple_first=apply_count;
					}
					else if(re_result_factor==5){
						apply(0);					
					//?	printf("move $v0 t%d",v0,apply_count);
						add_quadruple(22,operand11_fun,apply_count,0);//li
						quadruple_first=apply_count;
					}
					else if(re_result_factor<0){//���ص��Ǳ��ʽ ������Ľ�����ڵļĴ��� 
//!!!!					printf("t%d",-re_result_factor); 
						quadruple_first=-re_result_factor;
					}
					else if(re_result_factor==2){
//!!!!					printf("t%d",operand11_array);
						quadruple_first=operand11_array;
					}
				}
				else{
//!!!!				printf("t%d",result_term);
					quadruple_first=result_term;
				}
//!!!!			printf(" ");
				//������2
				if(result_factor==1){
					
					for(k=0;k<strlen(TokenCopy);k++){
//!!!!					printf("%c",TokenCopy[k]);
					}
					I=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
					apply(0);
				//?	printf("load %d t%d",addr,apply_count);
					if(I>0){
						add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
					}
					else{
						add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
					}
					quadruple_second=apply_count;
				} 
				else if(result_factor==3){
					apply(0);
					//?	printf("li %d t%d",operand1_integer,apply_count);
					add_quadruple(16,operand1_integer,apply_count,0);//li
					quadruple_second=apply_count;
//!!!!				printf("%d",operand1_integer);
				}
				else if(result_factor==4){
//!!!!				printf("%d",operand1_char);
					apply(0);					
					//?	printf("li %d t%d",operand1_integer,apply_count);
					add_quadruple(16,operand1_char,apply_count,0);//li
					quadruple_second=apply_count;
				}
				else if(result_factor==5){
//!!!!				printf("%d",operand1_char);
					apply(0);					
					//?	printf("li %d t%d",operand1_integer,apply_count);
					add_quadruple(22,operand1_fun,apply_count,0);//li
					quadruple_second=apply_count;
				}
				else if(result_factor<0){//���ص��Ǳ��ʽ ������Ľ�����ڵļĴ��� 
//!!!!				printf("t%d",-result_factor); 
					quadruple_second=-result_factor;
				}
				else if(result_factor==2){
//!!!!				printf("t%d",result_array);
					quadruple_second=result_array;
				}
//!!!!			printf(" "); 
				//���
				if(sign_term==0){
					apply(0);
//!!!!				printf("t%d\n",apply_count);
					quadruple_result=apply_count;
					result_term=apply_count;
					sign_term=1;
				} 
				else{
//!!!				printf("t%d\n",result_term);
					quadruple_result=result_term;
				}
				add_quadruple(act,quadruple_first,quadruple_second,quadruple_result);
				add_quadruple(27,quadruple_first,quadruple_second,quadruple_result);
				Connector2=0;
			}
			else if(Connector2==24){
//!!!!			printf("DIV ");
				act=4;
				int k=0;
				//������1
				if(sign_term==0){
					if(re_result_factor==1){
						I=Statement_SymbolTable3_v(operand1_symbol,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
						apply(0);
					//?	printf("load %d t%d",addr,apply_count);
						if(I>0){
							add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
						}
						else{
							add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
						}
						quadruple_first=apply_count;
						for(k=0;k<strlen(operand1_symbol);k++){
//!!!!						printf("%c",operand1_symbol[k]);
						} 
					}
					else if(re_result_factor==3){
						apply(0);					
					//?	printf("li %d t%d",operand11_integer,apply_count);
						add_quadruple(16,operand11_integer,apply_count,0);//li
						quadruple_first=apply_count;
//!!!!					printf("%d",operand11_integer);
					}
					else if(re_result_factor==4){
						apply(0);					
					//?	printf("li %d t%d",operand11_integer,apply_count);
						add_quadruple(16,operand11_char,apply_count,0);//li
						quadruple_first=apply_count;
//!!!!					printf("%d",operand11_char);
					}
					else if(re_result_factor==5){
						apply(0);					
					//?	printf("li %d t%d",operand11_integer,apply_count);
						add_quadruple(22,operand11_fun,apply_count,0);//li
						quadruple_first=apply_count;
//!!!!					printf("%d",operand11_char);
					}
					else if(re_result_factor<0){//���ص��Ǳ��ʽ ������Ľ�����ڵļĴ��� 
//!!!!					printf("t%d",-re_result_factor); 
						quadruple_first=-re_result_factor;
					}
					else if(re_result_factor==2){
//!!!!					printf("t%d",operand11_array);
						quadruple_first=operand11_array;
					}
				}
				else{
//!!!!				printf("t%d",result_term);
					quadruple_first=result_term;
				}
//!!!!			printf(" ");
				//������2 
				if(result_factor==1){
					I=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
					apply(0);
				//?	printf("load %d t%d",addr,apply_count);
				    if(I>0){
				    	add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
					}
					else{
						add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
					}
					if(apply_count<0){
						printf("apply error!\n");
					}
					quadruple_second=apply_count;
					for(k=0;k<strlen(TokenCopy);k++){
//!!!!					printf("%c",TokenCopy[k]);
					}
				}
				else if(result_factor==3){
					apply(0);					
				//?	printf("li %d t%d",operand11_integer,apply_count);
					add_quadruple(16,operand1_integer,apply_count,0);//li
					quadruple_second=apply_count;
					if(apply_count<0){
						printf("alppy2 error!\n");
					}
//!!!!				printf("%d",operand1_integer);
				}
				else if(result_factor==4){
					apply(0);					
				//?	printf("li %d t%d",operand11_integer,apply_count);
					add_quadruple(16,operand1_char,apply_count,0);//li
					quadruple_second=apply_count;
					if(apply_count<0){
						printf("alppy3 error!\n");
					}
//!!!!				printf("%d",operand1_char);
				}
				else if(result_factor==5){
					apply(0);					
				//?	printf("li %d t%d",operand11_integer,apply_count);
					add_quadruple(22,operand1_fun,apply_count,0);//li
					quadruple_second=apply_count;
					if(apply_count<0){
						printf("alppy4 error!\n");
					}
//!!!!				printf("%d",operand1_char);
				}
				else if(result_factor<0){//���ص��Ǳ��ʽ ������Ľ�����ڵļĴ��� 
//!!!!				printf("t%d",result_factor); 
					quadruple_second=-result_factor;
					if(quadruple_second<0){
						printf("factor error!\n");
					}
				}	
				else if(result_factor==2){
//!!!!				printf("t%d",result_array);
					quadruple_second=result_array;
					if(result_array<0){
						printf("array error!\n");
					}
				}		
//!!!!			printf(" ");
				//���
				if(sign_term==0){
					apply(0);
//!!!!				printf("t%d\n",apply_count);
					quadruple_result=apply_count;
					result_term=apply_count;	
					sign_term=1;
				} 
				else{
//!!!!				printf("t%d\n",result_term);
					quadruple_result=result_term;
				}	
				if(quadruple_second<0){
					printf("stop\n");
				}
				add_quadruple(act,quadruple_first,quadruple_second,quadruple_result);
				add_quadruple(27,quadruple_first,quadruple_second,quadruple_result);		
				Connector2=0;
			}
		}
		else if(Connector2==0){
			if(result_factor==1){
				strcpy(operand1_symbol,TokenCopy);
			}
			else if(result_factor==3){
				operand11_integer=operand1_integer;
			}
			else if(result_factor==4){
				operand11_char=operand1_char;
			}
			else if(result_factor==5){
				operand11_fun=operand1_fun;
			}
			else if(result_factor==2){
				operand11_array=result_array;
			}
			
		}
		if(Sym==12|Sym==24){
			type_is_char=3;
			Connector2=Sym;
			Sym=getsym();
		}
		else{
//!			printf("This is Term��\n");
			if(sign_term==0){//ֻ��һ�����Ӿͷ��ظ��� 
				term_type=factor_type;
				return -result_factor;
			} 
			else{
				term_type=3;
				return result_term;//���򷵻�Ŀǰ�����ŵļĴ��� 
			}			
		}
		re_result_factor=result_factor;
	}
} 

int Expression(){//���ʽ 
	expression_sign=1;	
	int Connector=0; 
	int sign=0;//�Ƿ�Ϊ��һ���� 
	int result_exp=0;
	int result_term=0;
	int act=0;
	int quadruple_first=0;
	int quadruple_second=0;
	int quadruple_result=0;
	int I=0;
	exp_type=0;
	term_type=0;
	if(Sym==11|Sym==10){
		type_is_char=3;
		Connector=Sym;
		Sym=getsym();
		
		while(1){
			result_term=Term();
			if(Connector!=0){
				if(Connector==11){
					
//!!!!				printf("ADD ");
					act=1;
					//������1 
					int k=0;
					
					if(sign==0){//��һ���� ���⴦�� 
//!!!!					printf("0 ");
						quadruple_first=0;
					}
					else{
//!!!!					printf("t%d ",result_exp);
						quadruple_first=result_exp;
					}
					//������2�������������һ�����ӣ�����Ľ��������˵����ֻ��һ������ 
					
					if(result_term==-1){
						exp_type=term_type;
						I=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
						apply(0);
					//?	printf("load %d t%d",addr,apply_count);
					    if(I>0){
					    	add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
						}
						else{
							add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
						}
						for(k=0;k<strlen(TokenCopy);k++){
//!!!!						printf("%c",TokenCopy[k]);
						}
						quadruple_second=apply_count;						
					} 
					else if(result_term==-3){
						exp_type=3;
//!!!!					printf("%d",operand1_integer);
						apply(0);
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(16,operand1_integer,apply_count,0);//li
						quadruple_second=apply_count;
						
					}
					else if(result_term==-4){//ֻ��һ�����ӣ���Ϊ�ַ� 
//!!!!					printf("%d",operand1_char);
						if(exp_type<2){
							exp_type=2;//ֻ�е�һ�λᱻд��2��֮�󲻻�ı� ����'b'+'a'������ 
						} 
						apply(0);
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(16,operand1_char,apply_count,0);//li
						quadruple_second=apply_count;
					}
					
					else if(result_term==-5){//ֻ��һ�����ӣ���Ϊ�ַ� 
//!!!!					printf("%d",operand1_char);
						if(exp_type<2){
							exp_type=term_type;
						} 
						apply(0);
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(22,operand1_fun,apply_count,0);//li
						quadruple_second=apply_count;
					}
					else if(result_term>0){
//!!!!					printf("t%d",result_term);
						if(exp_type<2){
							exp_type=term_type;
						} 
						quadruple_second=result_term;
					}
					else if(result_term==-2){
						exp_type=term_type;
//!!!!					printf("t%d",result_array);
						quadruple_second=result_array;
					}
					
					//�������ĵط�����һ��ʱapplyΪ����һ���µĿɴ洢�ļĴ��� 
					if(sign==0){
						apply(0);
//!!!!					printf("t%d\n",apply_count);
						result_exp=apply_count;						
						quadruple_result=apply_count;
					} 
					else{
//!!!!					printf("t%d\n",result_exp);
						quadruple_result=result_exp;
					}	
					
					add_quadruple(act,quadruple_first,quadruple_second,quadruple_result);	
					add_quadruple(27,quadruple_first,quadruple_second,quadruple_result);		
					Connector=0;
					sign=1;
				}
				else if(Connector==10){
//!!				printf("SUB ");
					act=2;
					//������1 
					int k=0;
					if(sign==0){
//!!!!					printf("0 ");
						quadruple_first=0;
					}
					else{
//!!!!					printf("t%d ",result_exp);
						quadruple_first=result_exp;
					}
					
					//������2 
					if(result_term==-1){
						exp_type=term_type;
						I=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
						apply(0);
					//?	printf("load %d t%d",addr,apply_count);
						if(I>0){
							add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
						}
						else{
							add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
						}
						for(k=0;k<strlen(TokenCopy);k++){
//!!!!						printf("%c",TokenCopy[k]);
						}
						quadruple_second=apply_count;
					}
					else if(result_term==-3){
//!!!!					printf("%d",operand1_integer);
						exp_type=3;
						apply(0);
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(16,operand1_integer,apply_count,0);//li
						quadruple_second=apply_count;
					}
					else if(result_term==-4){
//!!!!					printf("%d",operand1_char);
						if(exp_type<2){
							exp_type=2;
						}
						apply(0);
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(16,operand1_char,apply_count,0);//li
						quadruple_second=apply_count;
					}
					else if(result_term==-5){
//!!!!					printf("%d",operand1_char);
						if(exp_type<2){
							exp_type=term_type;
						}
						apply(0);
					//?	printf("li %d t%d",operand1_integer,apply_count);
						add_quadruple(22,operand1_fun,apply_count,0);//li
						quadruple_second=apply_count;
					}
					else if(result_term>0){
						if(exp_type<2){
							exp_type=term_type;
						}
//!!!! 					printf("t%d",result_term);
						quadruple_second=result_term;
					}
					else if(result_term==-2){
						exp_type=term_type;
//!!!!					printf("t%d",result_array);
						quadruple_second=result_array;
					}
//!!!!				printf(" ");
					//��� 
					if(sign==0){
						apply(0);
//!!!!					printf("t%d\n",apply_count);
						result_exp=apply_count;
						quadruple_result=apply_count;
					}
					else{
//!!!!					printf("t%d\n",result_exp);
						quadruple_result=result_exp;		
					}	
					
					add_quadruple(act,quadruple_first,quadruple_second,quadruple_result);
					add_quadruple(27,quadruple_first,quadruple_second,quadruple_result);
					Connector=0;
					sign=1;
				}
			}
			if(Sym==11|Sym==10){
				Connector=Sym;
				Sym=getsym();
			} 
			else{
//!				printf("This is Expression���ʽ\n");
				return result_exp;
			}
		}
		
	}
	else {
		while(1){
			result_term=Term();
			if(sign==0){
//!!!!			printf("ADD ");
				act=1;
				//������1 
				int k=0;
				if(sign==0){
//!!!!				printf("0 ");
					quadruple_first=0;
				}
				//������2 
				if(result_term==-1){
					exp_type=term_type;
					apply(0);
					I=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
				//?	printf("load %d t%d",addr,apply_count);
				    if(I>0){
					    add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
			    	}
					else {
					    add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
			    	}
					for(k=0;k<strlen(TokenCopy);k++){
//!!!!					printf("%c",TokenCopy[k]);
					}
					quadruple_second=apply_count;
				}
				else if(result_term==-3){
					exp_type=3;
					apply(0);
					//?	printf("load %d t%d",addr,apply_count);
					add_quadruple(16,operand1_integer,apply_count,0);//li
//!!!!				printf("%d",operand1_integer);
					quadruple_second=apply_count;
				}
				else if(result_term==-4){
					if(exp_type<2){
						exp_type=2;
					}
					apply(0);
					//?	printf("load %d t%d",addr,apply_count);
					add_quadruple(16,operand1_char,apply_count,0);//li
//!!!!				printf("%d",operand1_char);
					quadruple_second=apply_count;
				}
				else if(result_term==-5){
					if(exp_type<2){
						exp_type=term_type;
					}
					apply(0);
					//?	printf("load %d t%d",addr,apply_count);
					add_quadruple(22,operand1_fun,apply_count,0);//li
//!!!!				printf("%d",operand1_char);
					quadruple_second=apply_count;
				}
				else if(result_term>0){
					if(exp_type<2){
						exp_type=term_type;
					}
//!!!!				printf("t%d",result_term);
					quadruple_second=result_term;
				}
				else if(result_term==-2){
					exp_type=term_type;
//!!!!				printf("t%d",result_array);
					quadruple_second=result_array;
				}
//!!!!			printf(" ");
				//��� 
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				quadruple_result=apply_count;
				add_quadruple(act,quadruple_first,quadruple_second,quadruple_result);
				add_quadruple(27,quadruple_first,quadruple_second,quadruple_result);
				result_exp=apply_count;						
				Connector=0;
				sign=1;
				
			}
			if(Connector!=0){
				if(Connector==11){
//!!!!				printf("ADD ");
					act=1;
					//������1 
					int k=0;
//!!!!				printf("t%d ",result_exp);
					quadruple_first=result_exp;
					//������2 
					if(result_term==-1){
						exp_type=term_type;
						apply(0);
						I=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
					//?	printf("load %d t%d",addr,apply_count);
						if(I>0){
							add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
						}
						else{
							add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load
						}
						for(k=0;k<strlen(TokenCopy);k++){
//!!!!						printf("%c",TokenCopy[k]);
						}
						quadruple_second=apply_count;
					}
					else if(result_term==-3){
						exp_type=3;
						apply(0);
					//?	printf("load %d t%d",addr,apply_count);
						add_quadruple(16,operand1_integer,apply_count,0);//li
//!!!!					printf("%d",operand1_integer);
						quadruple_second=apply_count;
					}
					else if(result_term==-4){
						if(exp_type<2){
							exp_type=2;
						}
						apply(0);
					//?	printf("load %d t%d",addr,apply_count);
						add_quadruple(16,operand1_char,apply_count,0);//li
//!!!!					printf("%d",operand1_char);
						quadruple_second=apply_count;
					}
					else if(result_term==-5){
						if(exp_type<2){
							exp_type=term_type;
						}
						apply(0);
					//?	printf("load %d t%d",addr,apply_count);
						add_quadruple(22,operand1_fun,apply_count,0);//li
//!!!!					printf("%d",operand1_char);
						quadruple_second=apply_count;
					}
					else if(result_term>0){
//!!!!					printf("t%d",result_term);
						if(exp_type<2){
							exp_type=term_type;
						}
						quadruple_second=result_term;
					}
					else if(result_term==-2){
						exp_type=term_type;
//!!!!					printf("t%d",result_array);
						quadruple_second=result_array;
					}
//!!!!				printf(" ");
					//��� 
//!!!!				printf("t%d\n",result_exp);
					quadruple_result=result_exp;
					add_quadruple(act,quadruple_first,quadruple_second,quadruple_result);
					add_quadruple(27,quadruple_first,quadruple_second,quadruple_result);
					Connector=0;					
				}
				else if(Connector==10){
//!!!!				printf("SUB ");
					act=2;
					//������1 
					int k=0;
					if(sign==0){
//!!!!					printf("0 ");
						quadruple_first=0;
					}
					else{
//!!!!					printf("t%d ",result_exp);
						quadruple_first=result_exp;
					}
					//������2 
					if(result_term==-1){
						exp_type=term_type;
						apply(0);
						I=Statement_SymbolTable3_v(TokenCopy,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
					//?	printf("load %d t%d",addr,apply_count);
						if(I>0){
							add_quadruple(15,SymbolTable[I].addr,apply_count,0);//load
						}
						else{
							add_quadruple(26,SymbolTable[-I].addr,apply_count,0);//load $gp
						}
						for(k=0;k<strlen(TokenCopy);k++){
//!!!!						printf("%c",TokenCopy[k]);
						}		
						quadruple_second=apply_count;				
					}
					else if(result_term==-3){
						exp_type=3;
						apply(0);
						//?	printf("load %d t%d",addr,apply_count);
						add_quadruple(16,operand1_integer,apply_count,0);//li
//!!!!					printf("%d",operand1_integer);
						quadruple_second=apply_count;
					}
					else if(result_term==-4){
						if(exp_type<2){
							exp_type=2;
						}						 
						apply(0);
						//?	printf("load %d t%d",addr,apply_count);
						add_quadruple(16,operand1_char,apply_count,0);//li
//!!!!					printf("%d",operand1_char);
						quadruple_second=apply_count;
					}
					else if(result_term==-5){
						if(exp_type<2){
							exp_type=term_type;
						}						 
						apply(0);
						//?	printf("load %d t%d",addr,apply_count);
						add_quadruple(22,operand1_fun,apply_count,0);//li
//!!!!					printf("%d",operand1_char);
						quadruple_second=apply_count;
					}
					else if(result_term>0){
//!!!!					printf("t%d",result_term);
						if(exp_type<2){
							exp_type=term_type;
						}
						quadruple_second=result_term;
					}
					else if(result_term==-2){
						exp_type=term_type;
//!!!!					printf("t%d",result_array);
						quadruple_second=result_array;
					}
//!!!!				printf(" ");
					//��� 
					if(sign==0){
						apply(0);
//!!!!					printf("t%d\n",apply_count);
						result_exp=apply_count;
						quadruple_result=apply_count;
					} 
					else{
//!!!!					printf("t%d\n",result_exp);
						quadruple_result=result_exp;
					}
					add_quadruple(act,quadruple_first,quadruple_second,quadruple_result);	
					add_quadruple(27,quadruple_first,quadruple_second,quadruple_result);
					Connector=0;
					sign=1;
				}
			}
			if(Sym==11|Sym==10){
				type_is_char=3;
				Connector=Sym;
				Sym=getsym();
			} 
			else{
//!				printf("This is Expression���ʽ\n");
				return result_exp;//����Ŀǰ�����ŵļĴ��� ֻ����һ��apply() ���Կ��Է���apply_count 
			}
		} 
	}
	
}

int label=0;
void apply_label(){
	label++;
}

int Condition(int condition_type,int label_loop){//����  condition_type==1 ������䣨����������ʱ��ת��  condition_type==2ѭ����䣨��������ʱ��ת�� 
	int exp1=0;
	int exp2=0;
	int re_op=0;
	int label_condition=0;
	exp1=Expression();
	if (Sym==15){
//!		printf("This is Condition���������ʽ\n");
		if(condition_type==1){
			apply_label();
			label_condition=label;
//!!!!		printf("Beq t%d 0 LABEL%d\n",exp1,label);
	//		apply(0);
	//		add_quadruple(16,1,apply_count,0);
			add_quadruple(10,exp1,0,label_condition);
		}
		else if(condition_type==2){
//!!!!		printf("Bne t%d 0 LABEL%d\n",exp1,label_loop);
	//		apply(0);
	//		add_quadruple(16,1,apply_count,0);
			add_quadruple(9,exp1,0,label_loop);
		}
		return label_condition; 
	} 
	else if(Sym>=25&&Sym<=30){		
		re_op=RelationOperator();
		exp2=Expression();
		if(re_op==25){
			if(condition_type==1){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);//�ر����� ��ת�ǲ�����ʱ��ת 
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count); 
				apply_label();
				label_condition=label;
//!!!!			printf("BGEZ t%d LABEL%d\n",apply_count,label);
				add_quadruple(12,apply_count,0,label_condition);
			}
			else if(condition_type==2){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);//�ر����� ��ת������ʱ��ת 
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count); 
//!!!!			printf("BLTZ t%d LABEL%d\n",apply_count,label_loop);
				add_quadruple(14,apply_count,0,label_loop);
			}
			
		}
		else if(re_op==26){
			if(condition_type==1){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count); 
				apply_label();
				label_condition=label;
//!!!			printf("BGTZ t%d LABEL%d\n",apply_count,label_condition);
				add_quadruple(11,apply_count,0,label_condition); 	
			}
			else if(condition_type==2){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count);
//!!!!			printf("BLEZ t%d LABEL%d\n",apply_count,label_loop);
				add_quadruple(13,apply_count,0,label_loop); 
			}
			
		}
		else if(re_op==27){
			if(condition_type==1){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);//�ر����� ��ת�ǲ�����ʱ��ת 
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count);
				apply_label();
				label_condition=label;
//!!!!			printf("BLEZ t%d LABEL%d\n",apply_count,label);
				add_quadruple(13,apply_count,0,label_condition); 
			}
			else if(condition_type==2){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);//�ر����� ��ת�ǲ�����ʱ��ת 
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count);
//!!!!			printf("BGTZ t%d LABEL%d\n",apply_count,label_loop);
				add_quadruple(11,apply_count,0,label_loop); 
			}			
		}
		else if(re_op==28){
			if(condition_type==1){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count);
				apply_label();
				label_condition=label;
//!!!!			printf("BLTZ t%d LABEL%d\n",apply_count,label);
				add_quadruple(14,apply_count,0,label_condition); 
			}
			else if(condition_type==2){
//!!!!			printf("SUB t%d t%d ",exp1,exp2);
				apply(0);
//!!!!			printf("t%d\n",apply_count);
				add_quadruple(2,exp1,exp2,apply_count);
//!!!!			printf("BGEZ t%d LABEL%d\n",apply_count,label_loop);
				add_quadruple(12,apply_count,0,label_loop); 
			}
			
		}
		else if(re_op==29){
			if(condition_type==1){
				apply_label();
				label_condition=label;
//!!!!			printf("BEQ t%d t%d LABEL%d\n",exp1,exp2,label);
				add_quadruple(10,exp1,exp2,label_condition);
			}
			else if(condition_type==2){
//!!!!			printf("BNE t%d t%d LABEL%d\n",exp1,exp2,label_loop);
				add_quadruple(9,exp1,exp2,label_loop);
			}
		}
		else if(re_op==30){
			if(condition_type==1){
				apply_label();
				label_condition=label;
//!!!!			printf("BNE t%d t%d LABEL%d\n",exp1,exp2,label_condition);
				add_quadruple(9,exp1,exp2,label_condition);
			}
			else{
//!!!!			printf("BEQ t%d t%d LABEL%d\n",exp1,exp2,label_loop);
				add_quadruple(10,exp1,exp2,label_loop);
			}
		}
//!		printf("This is Condition���������ʽ ��ϵ����� ���ʽ\n");
		return label_condition; 				
	} 
	else{
		error(11);
	}	
}

void ConditionalStatement();
void LoopStatement();
void CaseStatement();
void AssignmentStatement();
void PrintStatement();
void ReadStatement();
void ReturnStatement();
void StatementCOLUMN();
void Statement(int label_condition,int sign_label){//��� 
	if(Sym==5){
		ConditionalStatement();
		if(sign_label==1){
			add_quadruple(17,label_condition,0,0);
		}
	}
	else if(Sym==4){
		LoopStatement();
		if(sign_label==1){
			add_quadruple(17,label_condition,0,0);
		}
	}
	else if(Sym==2){
		CaseStatement();
		if(sign_label==1){
			add_quadruple(17,label_condition,0,0);
		}
	}
	else if(Sym==16){
		StatementCOLUMN();
		if(sign_label==1){
			add_quadruple(17,label_condition,0,0);
		}
	}
	else if(Sym==8){
		strcpy(TokenCopy,token2);
		Sym=getsym();
		if(Sym==14){
			Statement_SymbolTable3_fun(TokenCopy,LEVEL,2);
			ReturnValueFunctionCallStatement();
			if(Sym==32){
				Sym=getsym();
//!				printf("This is Statement���\n");
				if(sign_label==1){
					add_quadruple(17,label_condition,0,0);
				}
				return; 
			}
			else{
				error(9);
			}
		}
		else if(Sym==31|Sym==33){
			AssignmentStatement();
			if(Sym==32){
				Sym=getsym();
//!				printf("This is Statement���\n");
				if(sign_label==1){
					add_quadruple(17,label_condition,0,0);
				}
				return; 
			}
			else{
				error(9);
			}
		}
	}
	else if(Sym==19){
		ReadStatement();
		if(Sym==32){
			Sym=getsym();
//!			printf("This is Statement���\n");
			if(sign_label==1){
				add_quadruple(17,label_condition,0,0);
			}
			return; 
		}
		else{
			error(9);
		}
	}
	else if(Sym==20){
		PrintStatement();
		if(Sym==32){
			Sym=getsym();
//!			printf("This is Statement���\n");
			if(sign_label==1){
				add_quadruple(17,label_condition,0,0);
			}
			return; 
		}
		else{
			error(9);
		}
	}
	else if(Sym==32){
		Sym=getsym();
//!		printf("This is Statement��䣺�����\n");
		if(sign_label==1){
			add_quadruple(17,label_condition,0,0);
		}
		return; 
	}
	else if(Sym==21){
		ReturnStatement();
		if(Sym==32){
			Sym=getsym();
//!			printf("This is Statement���\n");
			if(sign_label==1){
				add_quadruple(17,label_condition,0,0);
			}
			return; 
		}
		else{
			error(9);
		}
	}
	else{
		error(10);
	} 
	
}
 
int result_condition=0;
void ConditionalStatement(){//������� 
	if(Sym==5){
		Sym=getsym();		
		if(Sym==14){
			Sym=getsym();
			int label_condition=Condition(1,0);			
			if(Sym==15){
				Sym=getsym();
				Statement(label_condition,1);
//!				printf("This is ConditionalStatement�������\n");
//!!!!			printf("LABEL%d:\n",label_condition);
//				add_quadruple(17,label_condition,0,0);
				label_condition=0;
				return; 				
			} 
			else{
				error(11);
			}
		}
		else{
			error(12);
		}		
	}
	else{
		error(13);
	}
}

void LoopStatement(){//ѭ�����
	if(Sym==4){
		apply_label();
		int label_loop=label;
//!!!!	printf("LABEL%d:\n",label_loop);
		add_quadruple(17,label_loop,0,0);
		Sym=getsym();
		Statement(0,0);
		if(Sym==1){
			Sym=getsym();
			if(Sym==14){
				Sym=getsym();
				Condition(2,label_loop);
				if(Sym==15){
					Sym=getsym();
//!					printf("This is LoopStatementѭ�����\n");
					return;
				}
				else{
					error(11);
				}
			}
			else{
				error(12);
			}
		}
		else{
			error(14);
		}
	}
	else{
		error(15);
	}	
} 

int Constant(){//���� 

	if(Sym==37){
		Sym=getsym();
//!		printf("This is Constant����\n");
		return Char2;
	}
	else{
		return Integer();
	}
	
}

int label_switch=0;
void CaseSubstatement(int result_exp,int label_switch){//�������� 
	int result_constant=0;
	if(Sym==3){
		Sym=getsym();
		result_constant=Constant();
		apply_label(); 
		int label_case=label;
//!!!!	printf("BNE %d t%d LABEL%d\n",result_constant,result_exp,label_case);		
		apply(0); 
		add_quadruple(16,result_constant,apply_count,0);
		add_quadruple(9,result_exp,apply_count,label_case);
		if(Sym==36){
			Sym=getsym();
			Statement(0,0);
//!!!!		printf("J LABEL%d\n",label_switch);
			add_quadruple(6,label_switch,0,0);
//!!!!		printf("LABEL%d:\n",label_case);
			add_quadruple(17,label_case,0,0);
//!			printf("This is CaseSubstatement��������\n");
			return;			
		}
		else{
			error(16);
			return;
		}
	}
	else{
		error(17);
		return;
	}
} 

void CaseTable(int result_exp,int label_switch){//����� 
	if(Sym==3){
		while(Sym==3){
			CaseSubstatement(result_exp,label_switch);		
		}
//!		printf("This is CaseTable�����\n");
		add_quadruple(17,label_switch,0,0);
		return;	
	}
	else{
		error(17);
	}
} 

void CaseStatement(){//������ 
	int result_exp=0; 	
	if(Sym==2){
		Sym=getsym();
		if(Sym==14){
			Sym=getsym();
			result_exp=Expression();
			if(Sym==15){
				Sym=getsym();
				if(Sym==16){
					Sym=getsym();
					apply_label();
					label_switch=label; 
					CaseTable(result_exp,label_switch);
//!!!!				printf("LABEL%d:\n",label_switch);
//					add_quadruple(17,label_switch,0,0); 
					label_switch=0;
					if(Sym==17){
						Sym=getsym();
//!						printf("This is CaseStatement������\n");
						return;
					}
					else{
						error(18);
					}
				}
				else{
					error(19);
				}
			}
			else{
				error(11);
			}
		}
		else{
			error(12);
		}
	}
	else{
		error(20);
	}
} 

void StatementColumn(){//����� 
	if (Sym==17){
//!		printf("This is StatementColumn����У��� \n");
		return; 
	}
	else if(Sym==5|Sym==4|Sym==2|Sym==16|Sym==8|Sym==19|Sym==20|Sym==32|Sym==21){
		while(Sym==5|Sym==4|Sym==2|Sym==16|Sym==8|Sym==19|Sym==20|Sym==32|Sym==21){
			Statement(0,0);
		}
//!		printf("This is StatementColumn����� \n");
		return; 
	}
	else{
		error(10);
	}
}
 
void StatementCOLUMN(){//{�����} 
	if(Sym==16){
		Sym=getsym();
		StatementColumn();
		if(Sym==17){
			Sym=getsym();
//!			printf("This is StatementCOLUMN{�����} \n");
			return;
		}
		else{
			error(18);
		}
	}
	else{
		error(19);
	}	
}

void ReturnValueFunctionCallStatement(){//�з���ֵ�����������&�޷���ֵ���� 
	if(Sym==14){
		int i=Statement_SymbolTable3_fun(TokenCopy,LEVEL,2);
		Sym=getsym(); 
		ValueParameterTable(i);
		int t_fun=SymbolTable[i].type;
		if(Sym==15){
			Sym=getsym();
//!!!		printf("JAL ");
			int k=0;
			for(k=0;k<strlen(TokenCopy);k++){
//!!!!			printf("%c",TokenCopy[k]);
			}
			add_quadruple(7,i,0,0);
//!!!!		printf("_begin\n");
			
//!			printf("This is ReturnValueFunctionCallStatement�з���ֵ�����������\n");
			
			
			return ;
			
		}
		else{
			error(11);
		}
	}
	else{
		error(12);
	}
} 

void AssignmentStatement(){//��ֵ��� 
	int result_exp=0;
	int addr;
	int I=0;
	int type1=0;
	int kind1=0;
	exp_type=0;
	if(Sym==31){
		char TokenLeft[100]={};
		strcpy(TokenLeft,TokenCopy);
		I=Statement_SymbolTable3_v(TokenLeft,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
		if(I>0){
			kind1=SymbolTable[I].kind;
			type1=SymbolTable[I].type;
			addr=SymbolTable[I].addr;
		}
		else{
			kind1=SymbolTable[I].kind;
			type1=SymbolTable[-I].type;
			addr=SymbolTable[-I].addr;
		}
		if(kind1==10){
			printf("������� �������ܱ���ֵ����%d��\n",line);
		}
		Sym=getsym();
		result_exp=Expression();
//		exp_type=Expression_typecheck(); 
		if(type1==2&(exp_type==1|exp_type==3)){
//!!!!!!!!!!printf("Error!������� ���ܰ�һ��intֵ����char ��%d��\n",line);
		}
//!		printf("This is AssignmentStatement��ֵ��䣺��ʶ��=���ʽ \n");
//!!!!	printf("MOVE ");		
		int k=0;
		
		for(k=0;k<strlen(TokenLeft);k++){			
//!!!!		printf("%c",TokenCopy[k]);
		}		
//!!!!	printf(" -1 t%d\n",result_exp);//
		add_quadruple(5,addr,0,result_exp);
		return;
	} 
	else if(Sym==33){
		int emmm=Statement_SymbolTable3_fun(fun_name,LEVEL-1,2);
		I=Statement_SymbolTable3_v(TokenCopy,LEVEL,3,emmm);
		if(I>0){
			addr=SymbolTable[I].addr;
			type1=SymbolTable[I].type;	
		}
		else if(I<0){
			addr=SymbolTable[-I].addr;	
			type1=SymbolTable[-I].type;
		}
		
		Sym=getsym();
		result_exp=Expression();
		if(Sym==34){
			Sym=getsym();
			if(Sym==31){
				Sym=getsym();
				int result_exp2=0;
				result_exp2=Expression();
//				exp_type=Expression_typecheck();
				if(type1==2&&(exp_type==3|exp_type==1)){
//					printf("Error!������� �ѷǷ���intֵ����char ��%d��\n",line);
				}
//				printf("MOVE ");
				int k=0;
				for(k=0;k<strlen(TokenCopy);k++){
//					printf("%c",TokenCopy[k]);
				}	
//				printf(" %d %d\n",result_exp2,result_exp);	
				apply(result_exp);
				add_quadruple(5,addr,result_exp,result_exp2);
//!				printf("This is AssignmentStatement��ֵ��䣺��ʶ��[���ʽ]=���ʽ \n");
				return;
			}
			else{
				error(21);
			}
		}
		else{
			error(2);
		} 
	}
	else{
		error(22);
	}
}

void ReadStatement(){//����� 
	if(Sym==19){
		Sym=getsym();
		if(Sym==14){
			Sym=getsym();
			int i=0;
			while(1){
				if(Sym==8){
					i=Statement_SymbolTable3_v(token2,LEVEL,1,Statement_SymbolTable3_fun(fun_name,LEVEL-1,2));
					if(i<0){
						add_quadruple(23,SymbolTable[-i].addr,SymbolTable[-i].type,0);
					}
					else{
						add_quadruple(23,SymbolTable[i].addr,SymbolTable[i].type,0);
					}
					Sym=getsym();
					if(Sym==13){
						Sym=getsym();
					}
					else{
						break;
					} 
				}
				else{
					error(4);
					break;
				} 
			}
			if(Sym==15){
				Sym=getsym();
//!				printf("This is ReadStatement�����\n");
				return;
			}
		}
		else{
			error(12);
		}
	}
	else{
		error(23);
	}
}

void PrintStatement(){//д��� 
	int exp_result=0;
	exp_type=0;
	int ii=0;
	if(Sym==20){
		Sym=getsym();
		if(Sym==14){
			Sym=getsym();
			if(Sym==35){
				ii=check_String_Table(token);
				Sym=getsym();
				if(Sym==15){					
					Sym=getsym();					
					add_quadruple(24,3,ii,0);
//!					printf("This is PrintStatementд��䣺printf(�ַ���)\n");
					return;
				}
				else if(Sym==13){
					Sym=getsym();
					add_quadruple(24,3,ii,0);
					type_is_char=2;
					exp_result=Expression();
//					exp_type=Expression_typecheck();					
					if(Sym==15){
						Sym=getsym();						
						add_quadruple(24,1,exp_result,type_is_char);						
//!						printf("This is PrintStatementд��䣺printf(�ַ���,���ʽ)\n");
						return;
					}
					else{
						error(11);
					} 
				}
				else{
					error(11);
				}
				
			}
			else{
				type_is_char=2;
				exp_result=Expression();
//				exp_type=Expression_typecheck();
				if(Sym==15){
					Sym=getsym();
					add_quadruple(24,1,exp_result,type_is_char);
//!					printf("This is PrintStatementд��䣺printf(���ʽ)\n");
					return;
				}
				else{
					error(11);
				}
			}
		}
		else{
			error(12);
		}
	}
	else{
		error(24);
		return;
	}
}

void ReturnStatement(){//������� 
	int result_exp; 
	int return_type=0;
	exp_type=0;
	if(Sym==21){
		Sym=getsym();
		if(Sym==32){
			add_quadruple(8,0,0,0);
//!			printf("This is ReturnStatement������䣺�� \n");
			return;
		}
		else if(Sym==14){
			Sym=getsym();
			result_exp=Expression();
//			exp_type=Expression_typecheck();
			if(Sym==15){
				Sym=getsym();
				add_quadruple(21,result_exp,0,0);
				add_quadruple(8,0,0,0);
//!				printf("This is ReturnStatement������䣺(���ʽ) \n");
				return_type=exp_type;
				if(exp_type==3){
					return_type=1;
				} 
				if(return_type==SymbolTable[Statement_SymbolTable3_fun(fun_name,LEVEL,2)].type){
					result_return=result_exp;				
					return ;
				}
				else{
					printf("Error!������� ����ֵ�ͺ������Ͳ�һ�� ��%d��\n",line);
					return ; 
				}
				
			}
			else{
				error(11); 
			}
			
		}
		else {
			error(12);
		}
	}
	else{
		error(25);
	}
}

void ConstantDeclaration();
void VariableDeclaration();
void FunctionReturnValueDeclaration();
void FunctionReturnVoidDeclaration();
void CompoundStatement();
char Stringmain[100]={};
void Procedure(){//���� 
	int mark=0; 
	while(1){
		if(Sym==18&&mark==0){
			ConstantDeclaration();
		} 
		else if(Sym==6|Sym==7){//����˵��&�з���ֵ�������� 
			if(Sym==6){
				TYPE=1;
			}
			else{
				TYPE=2;
			}
			Sym=getsym();
			if(Sym==8){	
				strcpy(TokenCopy,token2);				
				Sym=getsym();
				if((Sym==13|Sym==33|Sym==32)&&mark<=1){
					VariableDeclaration();
					mark=1;
				}
				else if(Sym==14){
					FunctionReturnValueDeclaration();
					mark=2;
				}
				else{
					error(26);
					KIND=0;
					break;
				}
			} 
			else{
				error(4);
				break;
			}
		}
		else if(Sym==22){
			TYPE=0;
			Sym=getsym();
			if(Sym==8){
				FunctionReturnVoidDeclaration();
			}
			else if(Sym==23){
				break;
			} 
			else{
				error(29);
				break;
			}
		} 
		else{
			error(28);
			break;
		}
	}
	if(Sym==23){
//!!!!	printf("main_begin:\n");
		fun_space=1004;
		LEVEL=0; 
		clear_apply();
		Declaration_SymbolTable_fun(token2,LEVEL,2,0,0,0);
		strcpy(TokenCopy,token2);
		strcpy(Stringmain,token2);
		strcpy(fun_name,token2);
		int i=Statement_SymbolTable3_fun(TokenCopy,0,2); 
	    add_head_quadruple(7,i,0,0);
		add_quadruple(18,i,0,0); 
		Sym=getsym();
		if(Sym==14){
			Sym=getsym();
			if(Sym==15){
				Sym=getsym();
				if(Sym==16){
					LEVEL++;
					Sym=getsym();
					CompoundStatement();
					if(Sym==17){
//!!!!					printf("main_end:\n");
						
						Sym=getsym();
						SymbolTable[i].addr=fun_space+apply_count_2;
						add_quadruple(19,i,0,0); 
//!						printf("This is Procedure���� \n");
						return;
					}
					else{
						error(18);
					}
				}
				else{
					error(19);
				}
			}
			else{
				error(11);
			} 
		}
		else{
			error(12);
		}
	}
	else{
		error(27);
	}
	
	
}

void ConstantDeclaration(){//��������
	KIND=10; 
	int i=0; 
	if(Sym==18){
		Sym=getsym();
		if(Sym==6){
			TYPE=1;
			Sym=getsym();
			
			int int_result=0; 
			while(1){
				if(Sym==8){
					if(fun_name[0]!='!'){
						Declaration_SymbolTable_v(token2,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
					} 
					else{
						Declaration_SymbolTable_v(token2,LEVEL,KIND,TYPE,fun_space++,0);
					}
				
					strcpy(TokenCopy,token2);
					Sym=getsym();
					if(Sym==31){
						Sym=getsym();
						int_result=Integer();
						if(fun_name[0]!='!'){
							i=Statement_SymbolTable3_v(TokenCopy,LEVEL,KIND,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
						}
						else{
							i=Statement_SymbolTable3_v(TokenCopy,LEVEL,KIND,-1);
						}
						apply(0);
	//					add_quadruple(16,int_result,apply_count,0);
						if(i>0){
							add_quadruple(16,int_result,apply_count,0);
							add_quadruple(25,SymbolTable[i].addr,apply_count,SymbolTable[i].lev);						
						} 
						else{
							add_quadruple_2(16,int_result,apply_count,0);
							add_quadruple_2(25,SymbolTable[-i].addr,apply_count,SymbolTable[i].lev);
						}						
						if(Sym==13){
							Sym=getsym();
						}
						else{
							break;
						}
					}
					else{
						error(21);
						break;
					}
					
				}
				else{
					error(4);
					break;
				}
			}
			if(Sym==32){
				Sym=getsym();
//!				printf("This is ConstantDeclaration����������int \n");
				return;
			}
			else{
				error(9);
			}
		}
		else if(Sym==7){
			TYPE=2;
			Sym=getsym();
			while(1){
				if(Sym==8){
					if(fun_name[0]!='!'){
						Declaration_SymbolTable_v(token2,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
					} 
					else{
						Declaration_SymbolTable_v(token2,LEVEL,KIND,TYPE,fun_space++,0);
					}
					
					strcpy(TokenCopy,token2);
					Sym=getsym();
					
					if(Sym==31){
						Sym=getsym();
						if(Sym==37){
							if(fun_name[0]!='!'){
								i=Statement_SymbolTable3_v(TokenCopy,LEVEL,KIND,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
							}
							else{
								i=Statement_SymbolTable3_v(TokenCopy,LEVEL,KIND,-1);
							}
							apply(0);
	//						add_quadruple(16,token[0],apply_count,0);
							if(i>0){
								add_quadruple(16,Char2,apply_count,0);
								add_quadruple(25,SymbolTable[i].addr,apply_count,SymbolTable[i].lev);
							} 
							else{
								add_quadruple_2(16,Char2,apply_count,0);
								add_quadruple_2(25,SymbolTable[-i].addr,apply_count,SymbolTable[i].lev);
							}	
							Sym=getsym();
							if(Sym==13){
								Sym=getsym();
							}
							else{
								break;
							}
						}
						else{
							error(30);
							break;
						}
						
					}
					else{
						error(21);
						break;
					}
					
				}
				else{
					error(4);
					break;
				}
			}
			if(Sym==32){
				Sym=getsym();
//!				printf("This is ConstantDeclaration����������char \n");
				return;
			}
			else{
				error(9);
			}
		}
		else{
			TYPE=0;
			error(1);
		}
	}
	else{
		error(31);
	}
}

void VariableDeclaration(){//�������� 
	if(Sym==33){
		KIND=3;
		if(fun_name[0]!='!'){
			Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
		} 
		else{
			Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space,0);
		}
		
		Sym=getsym();
		if(Sym==9){//���鶨�岻����0 
			fun_space+=num;
			Sym=getsym();
			if(Sym==34){
				Sym=getsym();
//!				printf("This is VariableDeclaration������������ʶ��[�޷�������] \n");
				if(Sym==13){
					Sym=getsym();
				} 
				else if(Sym==32){
					Sym=getsym();
//!					printf("This is VariableDeclaration������������ʶ��[�޷�������] \n");
					return;
				}
				else{
					error(9);
				}
			}
			else{
				error(2);
			}
		}
		else{
			error(7);
		}
	}
	else if(Sym==13){
		KIND=1;
		if(fun_name[0]!='!'){
			Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
		} 
		else{
			Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,0);
		}
		
//!	    printf("This is VariableDeclaration������������ʶ�� \n");
		Sym=getsym();
	}
	else if(Sym==32){
		KIND=1;
		if(fun_name[0]!='!'){
			Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
		} 
		else{
			Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,0);
		}
		
		Sym=getsym();
//!		printf("This is VariableDeclaration������������ʶ�� \n");
		return;
	}
	else{
		KIND=0;
		error(32);
	}
	while(1){
		if(Sym==8){
			strcpy(TokenCopy,token2);
			Sym=getsym();
			if(Sym==33){
				KIND=3;
				if(fun_name[0]!='!'){
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
				} 
				else{
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space,0);
				}				
				Sym=getsym();
				if(Sym==9){//���鶨�岻�������0 
					fun_space+=num;
					Sym=getsym();
					if(Sym==34){
						Sym=getsym();
						if(Sym==13){
//!							printf("This is VariableDeclaration������������ʶ��[�޷�������] \n");
							Sym=getsym();
						} 
						else if(Sym==32){
							Sym=getsym();
//!							printf("This is VariableDeclaration������������ʶ��[�޷�������] \n");
							return;
						}
						else{
							error(9);
						}
					}
					else{
						error(2);
					}
				}
				else{
					error(7);
				}
			}
			else if(Sym==13){
				KIND=1;
//!				printf("This is VariableDeclaration������������ʶ�� \n");
				if(fun_name[0]!='!'){
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
				} 
				else{
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,0);
				}		
				
				Sym=getsym();
			}
			else if(Sym==32){
				KIND=1;
				if(fun_name[0]!='!'){
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
				} 
				else{
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,0);
				}
				Sym=getsym();
//!				printf("This is VariableDeclaration������������ʶ�� \n");
				return;
			}
			else{
				KIND=1;
				if(fun_name[0]!='!'){
				Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
				} 
				else{
				Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,0);
				}
				//i=10; i�Ծɴ�����ű� 
				KIND=0;
				error(32);
			}
		}
		else{
			error(4);
			return;
		}
	}
	
}

int ParameterTable(){//������ 	
	KIND=4;
	if(Sym==15){
//!		printf("This is ParameterTable�������� \n");
		return 0;
	}
	int para_num=0;
	while(1){
		TypeIdentifier();
		if(Sym==8){
			Declaration_SymbolTable_v(token2,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
//!!!!		printf("Parameter ");
			para_num++;
			int k=0;
			for(k=0;k<strlen(token);k++){
//!!!!			printf("%c",token[k]);
			}
//!!!!		printf("\n");
			Sym=getsym();
			if(Sym==13){
				Sym=getsym();
			}
			else{
//!				printf("This is ParameterTable�������ǿ� \n");
				return para_num;
			}
		}
		else{
			error(4);
			break;
		} 
	}	
	
}

void CompoundStatement(){//������� 
	int mark=0;
	while(1){
		if(Sym==18&&mark==0){
			ConstantDeclaration();
		} 
		else if(Sym==6|Sym==7){//����˵��
			if(Sym==6){
				TYPE=1;
			}
			else{
				TYPE=2;
			}
			Sym=getsym();
			if(Sym==8){				
				strcpy(TokenCopy,token2);				
				Sym=getsym();
				if(Sym==13|Sym==33|Sym==32){
					VariableDeclaration();
					mark=1;
				}
				else {
					KIND=1;
					if(fun_name[0]!='!'){
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,Statement_SymbolTable3_fun(fun_name,LEVEL,2));
					} 
					else{
					Declaration_SymbolTable_v(TokenCopy,LEVEL,KIND,TYPE,fun_space++,0);
					}
					//i=10; i�Ծɴ�����ű� 
					KIND=0;
					error(32);
				}
			} 
			else{
				error(4);
			} 
		} 
		else if(Sym==17|Sym==5|Sym==4|Sym==2|Sym==16|Sym==8|Sym==19|Sym==20|Sym==32|Sym==21){
			break;
		} 
		else{
			error(33);
			break;
		}
	}
	StatementColumn();
}

void FunctionReturnValueDeclaration(){//�з���ֵ��������
	fun_space=1004;
	clear_apply();
	int para_num=0;	
	if(Sym==14){
		KIND=2;
		Declaration_SymbolTable_fun(TokenCopy,LEVEL,KIND,TYPE,0,0);
		LEVEL++;
		Sym=getsym();		
		strcpy(fun_name,TokenCopy);
		int i=Statement_SymbolTable3_fun(TokenCopy,LEVEL,2);
		int k=0;
		for(k=0;k<strlen(TokenCopy);k++){
//!!!!		printf("%c",TokenCopy[k]);
		}
		add_quadruple(18,i,0,0);
//!!!!	printf("_begin:\n");
		para_num=ParameterTable();
		if(Sym==15){
			Sym=getsym();
			if(Sym==16){
				Sym=getsym();
				CompoundStatement();
				if(Sym==17){
					Sym=getsym();
					SymbolTable[i].addr=fun_space+apply_count_2;
					SymbolTable[i].para_num=para_num;
//!					printf("This is FunctionReturnValueDeclaration�з���ֵ�������� \n");
					LEVEL--;
					for(k=0;k<strlen(fun_name);k++){
//!!!!					printf("%c",fun_name[k]);
					}
//!!!!				printf("_end:\n");
					add_quadruple(19,i,0,0);
//!!!!				printf("JR $31\n");
					add_quadruple(8,0,0,0);
					return;
				}
				else{
					error(18);
				}
			}
			else{
				error(19);
			}
		}
		else{
			error(11);
		}		
	}
	else{
		KIND=0;
		error(12);
	}

}

void FunctionReturnVoidDeclaration(){//�޷���ֵ��������
	fun_space=1004;
	clear_apply();
	int para_num=0;	
	if(Sym==8){
		KIND=2; 
		Declaration_SymbolTable_fun(token2,LEVEL,KIND,TYPE,0,0);
		LEVEL++;
		strcpy(fun_name,token2);
		int i=Statement_SymbolTable3_fun(token2,LEVEL,2);
		Sym=getsym();
		if(Sym==14){
			Sym=getsym();			
			int k=0;
			for(k=0;k<strlen(fun_name);k++){
//!!!!			printf("%c",fun_name[k]);
			}
//!!!!		printf("_begin:\n");
			add_quadruple(18,i,0,0);
			para_num=ParameterTable();
			if(Sym==15){
				Sym=getsym();
				if(Sym==16){
					Sym=getsym();
					CompoundStatement();
					if(Sym==17){
						Sym=getsym();
						SymbolTable[i].addr=fun_space+apply_count_2;
						SymbolTable[i].para_num=para_num;
//!						printf("This is FunctionReturnVoidDeclaration�޷���ֵ�������� \n");
						LEVEL--;
						for(k=0;k<strlen(fun_name);k++){
//!!!!						printf("%c",fun_name[k]);
						}
//!!!!					printf("_end:\n");
						add_quadruple(19,i,0,0);
//!!!!					printf("J $31\n");
						add_quadruple(8,0,0,0);
						return;
					}
					else{
						error(18);
					}
				}
				else{
					error(19);
				}
			}
			else{
				error(11);
			}		
		}
		else{
			error(12);
		}
	} 
	else{
		KIND=0;
		error(4);
	}
	LEVEL--;
	
}

//-----------------------------------���ű�----------------------------------- 


int length=0;
void Declaration_SymbolTable_v(char Token[100],int level,int kind,int type,int space,int i){//�������ֶ�����ʶ�� -���� 
	int mark=0;
	while(SymbolTable[i].lev==level){
		if(strcmp(SymbolTable[i].Name,Token)==0){
			printf("Error! �ظ����� ���ű����%d",line);
			int k=0;
			for(k=0;k<strlen(Token);k++){
				printf("%c",Token[k]);
			}
			printf("\n");
			mark=1;
			break;
		} 		
		i++;
	}
	if(mark==0){
		strcpy(SymbolTable[length].Name,Token);
		SymbolTable[length+1].Name[0]=0;
		SymbolTable[length].lev=level;
		SymbolTable[length].kind=kind;
		SymbolTable[length].type=type;
		SymbolTable[length].addr=space;
		
		length++;
	}
}

void Declaration_SymbolTable_fun(char Token[100],int level,int kind,int type,int space,int para_num){//�������ֶ�����ʶ�� -���� 
	int mark=0;
	int i=0;
	while(SymbolTable[i].Name[0]!=0){
		if(strcmp(SymbolTable[i].Name,Token)==0&&SymbolTable[i].kind==kind){
			printf("Error! �ظ����� ���ű����%d",line);
			int k=0;
			for(k=0;k<strlen(Token);k++){
				printf("%c",Token[k]);
			}
			printf("\n");
			mark=1;
			break;
		} 		
		i++;
	}
	if(mark==0){
		strcpy(SymbolTable[length].Name,Token);
		SymbolTable[length+1].Name[0]=0;
		SymbolTable[length].lev=level;
		SymbolTable[length].kind=kind;
		SymbolTable[length].type=type;
		SymbolTable[length].addr=space;
		SymbolTable[length].para_num=para_num;
		length++;
	}
}

int Statement_SymbolTable3_v(char Token[100],int level,int kind,int i){//��䲿�ֶ�����ʶ��-���� 
	int mark2=0;
	int j=i;
		i+=1; 
		while(SymbolTable[i].lev==level){//NULL 
			if(strcmp(SymbolTable[i].Name,Token)==0&&(SymbolTable[i].kind==kind|(SymbolTable[i].kind==4&&kind==1)|(SymbolTable[i].kind==10&&kind==1))){				
				if(level==0){
					return -i;
				}
				else{
					return i;
				}				
				mark2=1;
				break;
			} 		
			i++;
		}
		
	
	
		j=0; 
		while(SymbolTable[j].lev==0){//NULL 
			if(strcmp(SymbolTable[j].Name,Token)==0&&(SymbolTable[j].kind==kind|(SymbolTable[j].kind==4&&kind==1)|(SymbolTable[j].kind==10&&kind==1))){				
				return -j;
				mark2=1;
				break;
			} 		
			j++;
		}
	if(mark2==0){	
		printf("Error! δ����ı��� ���ű���� ��%d��",line);
		int k=0;
		for(k=0;k<strlen(Token);k++){
			printf("%c",Token[k]);
		}
		printf("\n");
	}	
}

int Statement_SymbolTable3_fun(char Token[100],int level,int kind){//��䲿�ֶ�����ʶ��-���� 
	int mark2=0;
	
		int i=0;
		while(SymbolTable[i].Name[0]!='\0'){//NULL 
			if(strcmp(SymbolTable[i].Name,Token)==0&&(SymbolTable[i].kind==kind|(SymbolTable[i].kind==4&&kind==1))){				
				return i;
				mark2=1;
				break;
			} 		
			i++;
		}
		
	
	if(mark2==0){
		printf("Error! δ����ĺ��� ���ű���� ��%d��",line);
		int k=0;
		for(k=0;k<strlen(Token);k++){
			printf("%c",Token[k]);
		}
		printf("\n");
	}	
}


int Statement_SymbolTable_Addr(char Token[100],int level,int kind){//�����м���� ��䲿�ֶ�����ʶ�� main
	int mark2=0;
	
	int i=0;
	while(SymbolTable[i].Name[0]!='0'){//NULL 
		if(strcmp(SymbolTable[i].Name,Token)==0&&(SymbolTable[i].kind==kind|(SymbolTable[i].kind==4&&kind==1))){				
			return SymbolTable[i].addr;
			mark2=1;
			break;
		} 		
		i++;
	}
		
	
	if(mark2==0){
		printf("Error! δ����ı��� ���ű���� ��%d��",line);
		int k=0;
		for(k=0;k<strlen(Token);k++){
			printf("%c",Token[k]);
		}
		printf("\n");
	}	
}


/*
int Statement_SymbolTable(char Token[100],int level,int kind){//���й����� ��䲿�ֶ�����ʶ�� 
	int mark2=0;
	while(level>=0){
		int i=0;
		for(i=0;i<1000;i++){
			if(SymbolTable_run[i].lev==level){
				break;
			}
		}
		int mark=0;
		while(SymbolTable_run[i].lev==level){
			if(strcmp(SymbolTable_run[i].Name,Token)==0&&(SymbolTable_run[i].kind==kind|(SymbolTable_run[i].kind==4&&kind==1))){				
				return SymbolTable_run[i].addr;
				mark=1;
				mark2=1;
				break;
			} 		
			i++;
		}
		if(mark==0){
			level--;
		}
	}
	if(mark2==0){
		printf("Error! δ����ı��� ���ű����");
		int k=0;
		for(k=0;k<strlen(Token);k++){
			printf("%c",Token[k]);
		}
		printf("\n");
	}	
}
*/

void print_middle(FILE* fp3){
	int k;
	if(head2!=NULL){
		for(p=head2;p->next!=head2;p=p->next){
		if(p->action==16){
			fprintf(fp3,"t%d lw %d\n",p->second,p->first);

		}
		
	}
		if(p->action==16){
			fprintf(fp3,"t%d lw %d\n",p->second,p->first);

		}
	}
	
	if(head!=NULL){
		for(p=head;p->next!=head;p=p->next){
		if(p->action==1){
			fprintf(fp3,"t%d=t%d+t%d\n",p->result,p->first,p->second);
		}
		else if(p->action==2){
			fprintf(fp3,"t%d=t%d-t%d\n",p->result,p->first,p->second);
		}
		else if(p->action==3){
			fprintf(fp3,"t%d=t%d*t%d\n",p->result,p->first,p->second);
		}
		else if(p->action==4){
			fprintf(fp3,"t%d=t%d/t%d\n",p->result,p->first,p->second);
		}
		else if(p->action==5){
			if(p->second==0){
				if(p->first>1000){
					fprintf(fp3,"addr%d=t%d\n",p->first-1000,p->result);
				}
				else{
					fprintf(fp3,"addr%d=t%d\n",p->first,p->result);
				}
				
			}
			else{
				if(p->first>1000){
					fprintf(fp3,"addr%d[t%d]=t%d\n",p->first-1000,p->second,p->result);
				}
				else{
					fprintf(fp3,"addr%d[t%d]=t%d\n",p->first,p->second,p->result);
				}
			}
			
		}
		else if(p->action==6){
			fprintf(fp3,"J label%d\n",p->first);

		}
		else if(p->action==7){
			fprintf(fp3,"GOTO");
		
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				fprintf(fp3,"%c",SymbolTable[p->first].Name[k]);
			}
			fprintf(fp3,"\n");
		}
		else if(p->action==8){
			fprintf(fp3,"GOTO $31 \n");
		}
		else if(p->action==9){
			fprintf(fp3,"t%d==t%d\n",p->first,p->second);
			fprintf(fp3,"BNZ label%d \n",p->result);
		}
		else if(p->action==10){
			fprintf(fp3,"t%d==t%d\n",p->first,p->second);
			fprintf(fp3,"BZ label%d \n",p->result);
		}
		else if(p->action==11){
			fprintf(fp3,"t%d<t%d\n",p->first,p->second);
			fprintf(fp3,"BZ label%d \n",p->result);
		}
		else if(p->action==12){
			fprintf(fp3,"t%d<=t%d\n",p->first,p->second);
			fprintf(fp3,"BZ label%d \n",p->result);
		}
		else if(p->action==13){
			fprintf(fp3,"t%d>=t%d\n",p->first,p->second);
			fprintf(fp3,"BZ label%d \n",p->result);
		}
		else if(p->action==14){
			fprintf(fp3,"t%d>t%d\n",p->first,p->second);
			fprintf(fp3,"BZ label%d \n",p->result);
		}
		else if(p->action==15){
			if(p->result==0){
				if(p->first>1000){
				fprintf(fp3,"addr%d lw t%d\n",p->first-1000,p->second);
				}
				else{
					fprintf(fp3,"addr%d lw t%d\n",p->first,p->second);
				}
			}
			else{
				if(p->first>1000){
				fprintf(fp3,"addr%d[t%d] lw t%d\n",p->first-1000,p->result,p->second);
				}
				else{
					fprintf(fp3,"addr%d[t%d] lw t%d\n",p->first,p->result,p->second);
				}
			}

		}		
		else if(p->action==16){
			fprintf(fp3,"t%d li %d\n",p->second,p->first);
		}
		else if(p->action==17){
			fprintf(fp3,"label%d:\n",p->first);
		}
		else if(p->action==18){			
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				fprintf(fp3,"%c",SymbolTable[p->first].Name[k]);
			}
			fprintf(fp3,"_begin\n");
		}
		else if(p->action==19){			
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				fprintf(fp3,"%c",SymbolTable[p->first].Name[k]);
			}
			fprintf(fp3,"_end\n");
		}
		else if(p->action==20){
			fprintf(fp3,"push t%d\n",p->first);
		}
		else if(p->action==21){
			fprintf(fp3,"ret t%d\n",p->first);
		}
		else if(p->action==23){
			if(p->first>1000){
				fprintf(fp3,"scanf addr%d\n",p->first-1000);
			}
			else{
				fprintf(fp3,"scanf addr%d\n",p->first);
			}
			
		}
		else if(p->action==24){
			if(p->first==3){
				fprintf(fp3,"printf str%d\n",p->second);
			}
			else{
				fprintf(fp3,"printf t%d\n",p->second);
			}
			
		}
		else if(p->action==26){
			if(p->result==0){
				if(p->first>1000){
				fprintf(fp3,"addr%d lw t%d\n",p->first-1000,p->second);
				}
				else{
					fprintf(fp3,"addr%d lw t%d\n",p->first,p->second);
				}
			}
			else{
				if(p->first>1000){
				fprintf(fp3,"addr%d[t%d] lw t%d\n",p->first-1000,p->result,p->second);
				}
				else{
					fprintf(fp3,"addr%d[t%d] lw t%d\n",p->first,p->result,p->second);
				}
			}

		}
	}
	
	if(p->action==19){			
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				fprintf(fp3,"%c",SymbolTable[p->first].Name[k]);
			}
			fprintf(fp3,"_end\n");
		}
		
	}
	
}

int main(){
	int printsign=0;//����̨������� 
	
	char filepath[100];
	gets(filepath); 
	fp=fopen(filepath,"r");
	if(fp==0){
		printf("�Ƿ���·��\n");
		return 0; 
	}
	
//	fp=fopen("a.txt","r");
	FILE* fp2;
	FILE* fp3;
	fp2=fopen("bb-new.txt","w");
	fp3=fopen("middle.txt","w");
		 
	Sym=getsym(); 
	Procedure();
	print_middle(fp3);
	int i;
	int k;
	int funspace2=0;
	if(printsign){
		printf(".data\n");
	} 	
	fprintf(fp2,".data\n");
	register_table_count=0;
	for(i=0;i<String_count;i++){
		if(printsign){
			printf("str%d: .asciiz \"",i);
		}
		fprintf(fp2,"str%d: .asciiz \"",i);
		for(k=0;k<strlen(StringTable[i]);k++){
			if(printsign){
				printf("%c",StringTable[i][k]);
			}
			fprintf(fp2,"%c",StringTable[i][k]);
		}
		if(printsign){
			printf("\"\n");
		}
		fprintf(fp2,"\"\n");
	}
	if(printsign){
		printf(".text\n");
	}
	fprintf(fp2,".text\n");
	if(head2!=NULL){
		for(p=head2;p->next!=head2;p=p->next){
			if(p->action==16){
	//			printf("LI t%d t%d\n",p->first,p->second);			
				if(check_register(p->second)==-1){
					apply_register(p->second);
				} 	
				if(printsign){			
					printf("li $t%d %d\n",check_register(p->second),p->first);
				}
				fprintf(fp2,"li $t%d %d\n",check_register(p->second),p->first);
			}
			else if(p->action==25){
				if(check_register(p->second)==-1){
					apply_register(p->second);
					if(printsign){
						printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
					}
					fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				if(p->result==0){
					if(printsign){
						printf("sw $t%d -%d($gp)\n",check_register(p->second),(p->first)*4);
					}
					fprintf(fp2,"sw $t%d -%d($gp)\n",check_register(p->second),(p->first)*4);
				}
				else if(p->result==1){
					if(printsign){
						printf("sw $t%d -%d($sp)\n",check_register(p->second),(p->first-1000)*4);
					}
					fprintf(fp2,"sw $t%d -%d($sp)\n",check_register(p->second),(p->first-1000)*4);
				
				}			
			}
		}
	}	
	if(p->action==16){
//			printf("LI t%d t%d\n",p->first,p->second);			
			if(check_register(p->second)==-1){
				apply_register(p->second);
			}
			if(printsign){
				printf("li $t%d %d\n",check_register(p->second),p->first);
			}
			fprintf(fp2,"li $t%d %d\n",check_register(p->second),p->first);
		}
		else if(p->action==25){
			if(check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}
			if(p->result==0){
				if(printsign){
					printf("sw $t%d -%d($gp)\n",check_register(p->second),(p->first)*4);
				}
				fprintf(fp2,"sw $t%d -%d($gp)\n",check_register(p->second),(p->first)*4);
			}
			else if(p->result==1){
				if(printsign){
					printf("sw $t%d -%d($sp)\n",check_register(p->second),(p->first-1000)*4);
				}
				fprintf(fp2,"sw $t%d -%d($sp)\n",check_register(p->second),(p->first-1000)*4);
			
			}			
		}
	for(p=head;p->next!=head;p=p->next){
		if(p->action==1){
//			printf("ADD t%d t%d t%d\n",p->first,p->second,p->result);
			//������������ֵ�Ƿ��ڼĴ����� 	
			if(check_register(p->result)==-1){
				apply_register(p->result);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
			}		
			if(p->first!=0&&check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				} 
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}			
			if(printsign){		
				printf("add ");
			} 
			fprintf(fp2,"add ");
			//��� 
			if(printsign){
				printf("$t%d ",check_register(p->result));
			}
			fprintf(fp2,"$t%d ",check_register(p->result));
			
			//��һ���Ĵ��� 
			if(p->first==0){
				if(printsign){
					printf("$0 ");
				}
				fprintf(fp2,"$0 ");
			} 
			else{	
				if(printsign){			
					printf("$t%d ",check_register(p->first));
				}
				fprintf(fp2,"$t%d ",check_register(p->first));			
			}
			//�ڶ����Ĵ��� 
			if(printsign){
				printf("$t%d \n",check_register(p->second));
			}
			fprintf(fp2,"$t%d \n",check_register(p->second));
			//��������浽�ڴ��� 			
		}
		else if(p->action==2){
//			printf("SUB t%d t%d t%d\n",p->first,p->second,p->result);
			//������������ֵ�Ƿ��ڼĴ����� 		
			if(check_register(p->result)==-1){
				apply_register(p->result);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
			}	
			if(p->first!=0&&check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}	
			if(printsign){			
				printf("sub ");	
			}
			fprintf(fp2,"sub ");		
			//��� 
			if(printsign){			
				printf("$t%d ",check_register(p->result));
			}
			fprintf(fp2,"$t%d ",check_register(p->result));		
			//��һ���Ĵ��� 
			if(p->first==0){
				if(printsign){
					printf("$0 ");
				}
				fprintf(fp2,"$0 ");
			} 
			else{
				if(check_register(p->first)==-1){
					printf("what?\n");
				}	
				if(printsign){			
					printf("$t%d ",check_register(p->first));	
				}
				fprintf(fp2,"$t%d ",check_register(p->first));			
			}
			//�ڶ����Ĵ��� 
			if(printsign){
				printf("$t%d \n",check_register(p->second));
			}
			fprintf(fp2,"$t%d \n",check_register(p->second));
			//��������浽�ڴ��� 
			
		}
		else if(p->action==3){
//			printf("MULT t%d t%d t%d\n",p->first,p->second,p->result);
        	//������������ֵ�Ƿ��ڼĴ����� 		
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}
			if(printsign){
				printf("mult ");
			}
			fprintf(fp2,"mult ");			
			//��һ���Ĵ��� 
			if(printsign){				
				printf("$t%d ",check_register(p->first));
			}
			fprintf(fp2,"$t%d ",check_register(p->first));
			//�ڶ����Ĵ��� 
			if(printsign){
				printf("$t%d \n",check_register(p->second));	
			}
			fprintf(fp2,"$t%d \n",check_register(p->second));
			//��� 	
			if(check_register(p->result)==-1){
				apply_register(p->result);
			}		
			if(printsign){
				printf("mflo $t%d \n",check_register(p->result));
			}
			fprintf(fp2,"mflo $t%d \n",check_register(p->result));
			//��������浽�ڴ��� 
			
		}
		else if(p->action==4){
//			printf("DIV t%d t%d t%d\n",p->first,p->second,p->result);
			//������������ֵ�Ƿ��ڼĴ����� 		
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(check_register(p->second)==-1){
				apply_register(p->second);
				if(check_temp_table(p->second)==-1){
					printf("what?\n");
				}
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}
			if(printsign){
				printf("div ");	
			}
			fprintf(fp2,"div ");						
			//��һ���Ĵ��� 	
			if(printsign){						
				printf("$t%d ",check_register(p->first));
			}
			fprintf(fp2,"$t%d ",check_register(p->first));							
			//�ڶ����Ĵ��� 
			if(printsign){
				printf("$t%d \n",check_register(p->second));
			}
			fprintf(fp2,"$t%d \n",check_register(p->second));				
			//��� 	
			if(check_register(p->result)==-1){
				apply_register(p->result);
			}		
			if(printsign){
				printf("mflo $t%d \n",check_register(p->result));
			}
			fprintf(fp2,"mflo $t%d \n",check_register(p->result));
			//��������浽�ڴ��� 
			
		}
		else if(p->action==5){
//			printf("MOVE t%d t%d\n",p->first,p->result);
			if(check_register(p->result)==-1){
				apply_register(p->result);
	
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
				//ֻ�ܴ�$sp��ȡ�����ʽ����õ��Ľ�� 
				
			}
			if(p->second!=0&&check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				//��$sp���ҵ������±�� �����ܴ�$gp�� 
			}
			if(p->second==0){
				if(p->first>1000){
					if(printsign){
						printf("sw $t%d -%d($sp) \n",check_register(p->result),(p->first-1000)*4);
					}
					fprintf(fp2,"sw $t%d -%d($sp) \n",check_register(p->result),(p->first-1000)*4);
				
				}
				else{
					if(printsign){
						printf("sw $t%d -%d($gp) \n",check_register(p->result),(p->first)*4);
					}
					fprintf(fp2,"sw $t%d -%d($gp) \n",check_register(p->result),(p->first)*4);
				}
				
			}
			else if(p->second!=0){
				if(p->first>1000){
					if(printsign){
						printf("li $s1 %d\n",p->first-1000);
					}
					fprintf(fp2,"li $s1 %d\n",p->first-1000);
					if(printsign){
						printf("add $s1 $s1 $t%d\n",check_register(p->second)); 
					}
					fprintf(fp2,"add $s1 $s1 $t%d\n",check_register(p->second)); 
					if(printsign){
						printf("li $s2 4\n");
					}
					fprintf(fp2,"li $s2 4\n");
					if(printsign){
						printf("mult $s1 $s2\n");
					}
					fprintf(fp2,"mult $s1 $s2\n");
					if(printsign){
						printf("mflo $s3\n");
					}
					fprintf(fp2,"mflo $s3\n");
					if(printsign){
						printf("sub $s3 $sp $s3 \n");
					}
					fprintf(fp2,"sub $s3 $sp $s3 \n");
					if(check_register(p->result)==-1){
						apply_register(p->result);
						
							if(printsign){
								printf("lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
							}
							fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
						
						
					}
					if(printsign){
						printf("sw $t%d 0($s3) \n",check_register(p->result));
					}
					fprintf(fp2,"sw $t%d 0($s3) \n",check_register(p->result));
				}
				else{
					if(printsign){
						printf("li $s1 %d\n",p->first);
					}
					fprintf(fp2,"li $s1 %d\n",p->first);
					if(printsign){
						printf("add $s1 $s1 $t%d\n",check_register(p->second)); 
					}
					fprintf(fp2,"add $s1 $s1 $t%d\n",check_register(p->second)); 
					if(printsign){
						printf("li $s2 4\n");
					}
					fprintf(fp2,"li $s2 4\n");
					if(printsign){
						printf("mult $s1 $s2\n");
					}
					fprintf(fp2,"mult $s1 $s2\n");
					if(printsign){
						printf("mflo $s3\n");
					}
					fprintf(fp2,"mflo $s3\n");
					if(printsign){
						printf("sub $s3 $gp $s3 \n");
					}
					fprintf(fp2,"sub $s3 $gp $s3 \n");
					if(check_register(p->result)==-1){
						apply_register(p->result);
						
							if(printsign){
								printf("lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
							}
							fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
						
						
					}
					if(printsign){
						printf("sw $t%d 0($s3) \n",check_register(p->result));
					}
					fprintf(fp2,"sw $t%d 0($s3) \n",check_register(p->result));
				}
	//			printf("sw $t%d -(%d+$t%d)*4($sp) \n",check_register(p->result),p->first-1000,check_register(p->second));		
	//			fprintf(fp2,"sw $t%d -(%d+$t%d)*4($sp) \n",check_register(p->result),p->first-1000,check_register(p->second));
				
			}
			
		}
		else if(p->action==6){
//			printf("J t%d\n",p->first);
			if(printsign){
				printf("j label%d\n",p->first);
			}
			fprintf(fp2,"j label%d\n",p->first);	
		}
		else if(p->action==7){
//			printf("JAL t%d\n",p->first);
			if(strcmp(SymbolTable[p->first].Name,Stringmain)!=0){
				if(printsign){
					printf("sw $sp -8($fp) \n");
				}
				fprintf(fp2,"sw $sp -8($fp) \n");
				if(printsign){
					printf("addi $s7 $fp %d\n",SymbolTable[p->first].para_num*4);
				} 
				fprintf(fp2,"addi $s7 $fp %d\n",SymbolTable[p->first].para_num*4);
				if(printsign){
					printf("sw $s7 0($fp)\n");
				} 
				fprintf(fp2,"sw $s7 0($fp)\n");
				if(printsign){
					printf("move $sp $fp \n");	
				} 
				fprintf(fp2,"move $sp $fp \n");	
				
			}
						
			if(printsign){						
				printf("jal ");
			} 
			fprintf(fp2,"jal ");
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				if(printsign){
					printf("%c",SymbolTable[p->first].Name[k]);
				} 
				fprintf(fp2,"%c",SymbolTable[p->first].Name[k]);
			}
			if(printsign){
				printf("_begin\n");
			} 
			fprintf(fp2,"_begin\n");		
			if(strcmp(SymbolTable[p->first].Name,Stringmain)==0){
				if(printsign){
					printf("jal main_end\n");
				} 
				fprintf(fp2,"jal main_end\n");
			}
		}
		else if(p->action==8){
			if(printsign){
				printf("lw $31 -4($sp)\n");
			} 
			fprintf(fp2,"lw $31 -4($sp)\n");
			if(printsign){
				printf("lw $fp 0($sp)\n");
			} 
			fprintf(fp2,"lw $fp 0($sp)\n");
			if(printsign){
				printf("lw $sp -8($sp)\n");
			} 
			fprintf(fp2,"lw $sp -8($sp)\n");
			if(printsign){
				printf("jr $31\n");
			}
			fprintf(fp2,"jr $31\n");
		}
		else if(p->action==9){ 
//			printf("BNE t%d t%d t%d\n",p->first,p->second,p->result);
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(p->second!=0&&check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}
			if(p->second!=0){
				if(printsign){
					printf("bne $t%d $t%d label%d\n",check_register(p->first),check_register(p->second),p->result);	
				}
				fprintf(fp2,"bne $t%d $t%d label%d\n",check_register(p->first),check_register(p->second),p->result);
			}	
			else if(p->second==0){
				if(printsign){
					printf("bne $t%d $0 label%d\n",check_register(p->first),p->result);	
				}
				fprintf(fp2,"bne $t%d $0 label%d\n",check_register(p->first),p->result);
			}	
					
		}
		else if(p->action==10){
//			printf("BEQ t%d t%d t%d\n",p->first,p->second,p->result);
			
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(p->second!=0&&check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}
			if(p->second!=0){
				if(printsign){
					printf("beq $t%d $t%d label%d\n",check_register(p->first),check_register(p->second),p->result);
				}
				fprintf(fp2,"beq $t%d $t%d label%d\n",check_register(p->first),check_register(p->second),p->result);
			}
			else{
				if(printsign){
					printf("beq $t%d $0 label%d\n",check_register(p->first),p->result);
				}
				fprintf(fp2,"beq $t%d $0 label%d\n",check_register(p->first),p->result);
			}	
		}
		else if(p->action==11){
//			printf("BGTZ t%d t%d t%d\n",p->first,p->second,p->result);
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}	
			if(printsign){
				printf("bgtz $t%d label%d\n",check_register(p->first),p->result);
			}
			fprintf(fp2,"bgtz $t%d label%d\n",check_register(p->first),p->result);
		}
		else if(p->action==12){
//			printf("BGEZ t%d t%d t%d\n",p->first,p->second,p->result);
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp)\n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp)\n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(printsign){
				printf("bgez $t%d label%d\n",check_register(p->first),p->result);		
			}
			fprintf(fp2,"bgez $t%d label%d\n",check_register(p->first),p->result);	
		}
		else if(p->action==13){
//			printf("BLEZ t%d t%d t%d\n",p->first,p->second,p->result);
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(printsign){
				printf("blez $t%d label%d\n",check_register(p->first),p->result);	
			}
			fprintf(fp2,"blez $t%d label%d\n",check_register(p->first),p->result);	
		}
		else if(p->action==14){
//			printf("BLTZ t%d t%d t%d\n",p->first,p->second,p->result);
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(printsign){
				printf("bltz $t%d label%d\n",check_register(p->first),p->result);	
			}	
			fprintf(fp2,"bltz $t%d label%d\n",check_register(p->first),p->result);
		}
		else if(p->action==15){
//			printf("LOAD t%d t%d\n",p->first,p->second);
			if(check_register(p->second)==-1){
				apply_register(p->second);
			}
			if(p->result!=0){
				if(check_register(p->second)==-1){
					apply_register(p->second);
				}		
				if(printsign){		
					printf("li $s1 %d\n",p->first-1000);
				} 
				fprintf(fp2,"li $s1 %d\n",p->first-1000);
				if(printsign){
					printf("add $s1 $s1 $t%d\n",check_register(p->result)); 
				}
				fprintf(fp2,"add $s1 $s1 $t%d\n",check_register(p->result)); 
				if(printsign){
					printf("li $s2 4\n");
				}
				fprintf(fp2,"li $s2 4\n");
				if(printsign){
					printf("mult $s1 $s2\n");
				}
				fprintf(fp2,"mult $s1 $s2\n");
				if(printsign){
					printf("mflo $s3\n");
				}
				fprintf(fp2,"mflo $s3\n");
				if(printsign){
					printf("sub $s3 $sp $s3\n");
				}
				fprintf(fp2,"sub $s3 $sp $s3\n");
				if(printsign){
					printf("lw $t%d 0($s3) \n",check_register(p->second));
				}
				fprintf(fp2,"lw $t%d 0($s3) \n",check_register(p->second));
				if(printsign){
					printf("sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
//				printf("lw $t%d -(%d+$t%d)*4($sp) \n",check_register(p->second),p->first-1000,check_register(p->result));
//				fprintf(fp2,"lw $t%d -(%d+$t%d)*4($sp) \n",check_register(p->second),p->first-1000,check_register(p->result));
				
			}
			else{	
				if(check_register(p->second)==-1){
					apply_register(p->second);
				}	
				if(printsign){						
					printf("lw $t%d -%d($sp) \n",check_register(p->second),(p->first-1000)*4);	
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),(p->first-1000)*4);	
				if(printsign){
					printf("sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);				
			}
					
		}
		else if(p->action==16){
//			printf("LI t%d t%d\n",p->first,p->second);			
			if(check_register(p->second)==-1){
				apply_register(p->second);
			}
			if(printsign){
				printf("li $t%d %d\n",check_register(p->second),p->first);	
			}
			fprintf(fp2,"li $t%d %d\n",check_register(p->second),p->first);
		}
		else if(p->action==17){
			if(printsign){
				printf("label%d:\n",p->first);
			}
			fprintf(fp2,"label%d:\n",p->first);		
		}
		else if(p->action==18){
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				if(printsign){
					printf("%c",SymbolTable[p->first].Name[k]);
				}
				fprintf(fp2,"%c",SymbolTable[p->first].Name[k]);
			}
			if(printsign){
				printf("_begin:\n");
			}
			fprintf(fp2,"_begin:\n");
			funspace2=SymbolTable[p->first].addr-1000;
			if(printsign){
				printf("sw $31 -4($sp)\n");	
			}
			fprintf(fp2,"sw $31 -4($sp)\n");
			if(printsign){
				printf("sub $fp $sp %d\n",funspace2*4);
			}
			fprintf(fp2,"sub $fp $sp %d\n",funspace2*4);
			//get para
			if(printsign){
				printf("lw $s4 0($sp)\n");
			}
			fprintf(fp2,"lw $s4 0($sp)\n");
			
			int iii=0;
			for(iii=0;iii<SymbolTable[p->first].para_num;iii++){
				if(printsign){
					printf("lw $s5 0($s4)\n");
				}
				fprintf(fp2,"lw $s5 0($s4)\n");
				if(printsign){
					printf("sub $s6 $sp 16\n");
				}
				fprintf(fp2,"sub $s6 $sp 16\n");
				if(printsign){
					printf("sub $s6 $s6 %d\n",iii*4);
				}
				fprintf(fp2,"sub $s6 $s6 %d\n",iii*4);
				if(printsign){	
					printf("sw $s5 0($s6)\n");
				}
				fprintf(fp2,"sw $s5 0($s6)\n");
				if(printsign){
					printf("sub $s4 $s4 4\n");
				}
				fprintf(fp2,"sub $s4 $s4 4\n");
			}
		}
		else if(p->action==19){
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				if(printsign){
					printf("%c",SymbolTable[p->first].Name[k]);
				}
				fprintf(fp2,"%c",SymbolTable[p->first].Name[k]);
			}
			if(printsign){
				printf("_end:\n");
			}
			fprintf(fp2,"_end:\n");
		}
		else if(p->action==20){
//			printf("PUSH t%d\n",p->first);
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(printsign){
				printf("sw $t%d 0($fp) \n",check_register(p->first)); 
			}
			fprintf(fp2,"sw $t%d 0($fp) \n",check_register(p->first)); 
			if(printsign){
				printf("sub $fp $fp 4\n");
			}
			fprintf(fp2,"sub $fp $fp 4\n");
		}
		else if(p->action==21){
//			return value save to $v0
			if(check_register(p->first)==-1){
				apply_register(p->first);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->first),check_temp_table(p->first)*4);
			}
			if(printsign){
				printf("move $v0 $t%d \n",check_register(p->first));
			}
			fprintf(fp2,"move $v0 $t%d \n",check_register(p->first));
		}
		else if(p->action==22){
//			get value from $v0
			
			if(check_register(p->second)==-1){
				apply_register(p->second);				
			}
			if(printsign){
				printf("move $t%d $v0 \n",check_register(p->second));
			}
			fprintf(fp2,"move $t%d $v0 \n",check_register(p->second));
			if(printsign){
				printf("sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}
			fprintf(fp2,"sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
		}
		else if(p->action==23){
//			read a1
			int syscall;
			if(p->second==1){
				syscall=5;
			}
			else if(p->second==2){
				syscall=12;
			}
			if(printsign){
				printf("li $v0 %d \nsyscall \n",syscall);
			}
			fprintf(fp2,"li $v0 %d \nsyscall \n",syscall);
			if(p->first<1000){
				if(printsign){
					printf("sw $v0 -%d($gp) \n",(p->first)*4); 
				}
				fprintf(fp2,"sw $v0 -%d($gp)  \n",(p->first)*4); 
			}
			else{
				if(printsign){
					printf("sw $v0 -%d($sp) \n",(p->first-1000)*4); 
				}
				fprintf(fp2,"sw $v0 -%d($sp)  \n",(p->first-1000)*4); 
			}
			
		}
		else if(p->action==24){
//			print a1
			int syscall;
			if(p->first==1){
				if(p->result==1||p->result==3){
					syscall=1;
				}
				else if(p->result==2){
					syscall=11;
				}
				if(check_register(p->second)==-1){
					apply_register(p->second);
					if(printsign){
						printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
					}
					fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				if(printsign){
					printf("move $a0 $t%d\n",check_register(p->second));
				}
				fprintf(fp2,"move $a0 $t%d\n",check_register(p->second));
				if(printsign){
					printf("li $v0 %d\nsyscall \n",syscall); 
				}
				fprintf(fp2,"li $v0 %d\nsyscall \n",syscall); 
			}
			else{
				syscall=4;
				if(printsign){
					printf("li $v0 %d\n",syscall);
				}
				fprintf(fp2,"li $v0 %d\n",syscall);
				if(printsign){
					printf("la $a0 str%d\nsyscall \n",p->second);
				}
				fprintf(fp2,"la $a0 str%d\nsyscall \n",p->second);
			}
			
		}
		else if(p->action==25){
			if(check_register(p->second)==-1){
				apply_register(p->second);
				if(printsign){
					printf("lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"lw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
			}
			if(p->result==0){
				if(printsign){
					printf("sw $t%d -%d($gp)\n",check_register(p->second),(p->first)*4);
				}
				fprintf(fp2,"sw $t%d -%d($gp)\n",check_register(p->second),(p->first)*4);
			}
			else if(p->result==1){
				if(printsign){
					printf("sw $t%d -%d($sp)\n",check_register(p->second),(p->first-1000)*4);
				}
				fprintf(fp2,"sw $t%d -%d($sp)\n",check_register(p->second),(p->first-1000)*4);			
			}			
		}
		else if(p->action==26){
			if(check_register(p->second)==-1){
				apply_register(p->second);
			}
			if(p->result!=0){
				if(check_register(p->result)==-1){
					apply_register(p->result);
				}	
				if(printsign){			
					printf("li $s1 %d\n",p->first);
				}
				fprintf(fp2,"li $s1 %d\n",p->first);
				if(printsign){
					printf("add $s1 $s1 $t%d\n",check_register(p->result)); 
				}
				fprintf(fp2,"add $s1 $s1 $t%d\n",check_register(p->result));
				if(printsign){ 
					printf("li $s2 4\n");
				}
				fprintf(fp2,"li $s2 4\n");
				if(printsign){
					printf("mult $s1 $s2\n");
				}
				fprintf(fp2,"mult $s1 $s2\n");
				if(printsign){
					printf("mflo $s3\n");
				}
				fprintf(fp2,"mflo $s3\n");
				if(printsign){
					printf("sub $s3 $gp $s3\n");
				}
				fprintf(fp2,"sub $s3 $gp $s3\n");
				if(printsign){
					printf("lw $t%d 0($s3) \n",check_register(p->second));
				}
				fprintf(fp2,"lw $t%d 0($s3) \n",check_register(p->second));
				if(printsign){
					printf("sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
				}
				fprintf(fp2,"sw $t%d -%d($sp) \n",check_register(p->second),check_temp_table(p->second)*4);
//				printf("lw $t%d -(%d+$t%d)*4($sp) \n",check_register(p->second),p->first-1000,check_register(p->result));
//				fprintf(fp2,"lw $t%d -(%d+$t%d)*4($sp) \n",check_register(p->second),p->first-1000,check_register(p->result));
				
			}
			else{	
				if(check_register(p->second)==-1){
					apply_register(p->second);
				}				
				if(printsign){			
					printf("lw $t%d -%d($gp) \n",check_register(p->second),(p->first)*4);	
				}
				fprintf(fp2,"lw $t%d -%d($gp) \n",check_register(p->second),(p->first)*4);	
				if(printsign){
					printf("sw $t%d -%d($sp) \n",check_register(p->second),Temp_table[check_temp_table(p->second)].addr*4);
				}
				fprintf(fp2,"sw $t%d -%d($sp) \n",check_register(p->second),Temp_table[check_temp_table(p->second)].addr*4);				
			}
			
						
		}
		else if(p->action==27){	
			if(check_temp_table(p->result)==-1){
				check_temp_table(p->result); 
				printf("what?\n");
			}		
			if(printsign){
				printf("sw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);
			}
			fprintf(fp2,"sw $t%d -%d($sp) \n",check_register(p->result),check_temp_table(p->result)*4);				
		}
	}
	if(p->action==19){
			for(k=0;k<strlen(SymbolTable[p->first].Name);k++){
				if(printsign){
					printf("%c",SymbolTable[p->first].Name[k]);
				}
				fprintf(fp2,"%c",SymbolTable[p->first].Name[k]);
			}
			if(printsign){
				printf("_end:\n");
			}
			fprintf(fp2,"_end:\n");
		}
	return 0;
}

//ǰ���������� 1++0���� 1+0��ȷ 1+-1
//�ļ���β���ж� 
//�ַ����ı�����:���������ַ�  �ַ��������ޣ�ʲô�����ᷢ��strcatֻ�Ḵ��tokenʣ�ಿ�ֵ�token�� 
//˫���ţ��ַ��� �����ţ��ַ� 
//�������� 

//�﷨������ 

//3797 �� add_temp_table ������ô�죿
//  

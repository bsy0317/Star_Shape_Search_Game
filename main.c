#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>

void draw(int sx,int sy,int x,int y);
int gotoxy(int x,int y);
void size(int *x , int *y);
void print_score(int score, int life);


int main(void){
	
	int start_x = 5;
	int start_y = 2;
	int x = 60,xx=0;
	int y = 10,yy=0;
	int tmp= 0;
	int game_count;
	int game_delay = 500; //0.3초 
	int score = 50;
	int life = 3;
	int menu=0;
	char username[256];
	system("mode con:cols=120 lines=30"); //콘솔창 크기 설정 
	
	while(menu != 1)
	{
	do{
		system("CLS");
		printf("2017748047 배명건 기말과제\n"); 
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		printf("   1. 게    임   시  작 \n");
		printf("   2. 종    료 \n"); 
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		printf("> ");
		scanf("%d",&menu);
	} 
	while(menu < 1 || menu > 2);
	switch(menu){
		case 2:
			exit(-1);
			break;
	}
	}
	
	
	
	system("CLS");
	size(&xx,&yy);
	xx -= 35;
	yy -= 2;
	gotoxy(xx/2,yy/2);
	printf("별이 몇번 반짝이는지 맞추어 보시오.\n");
	gotoxy(xx/2,(yy/2)+1);
	printf("아무키나 누르면 시작 합니다.");
	getch();
	
	while(life > 0)
	{
		size(&xx,&yy);
		system("CLS");
	for(tmp=3; tmp>=0; tmp--){
		gotoxy((xx/2)-19,(yy/2)-1);
		printf("%d 초후 시작 합니다.",tmp);
		Sleep(1000);
		system("CLS"); 
	}
	system("CLS");
	gotoxy(x/2-5,start_y-1);
	printf("< 점수: %d  생명: %d >",score,life);
	draw(start_x,start_y,x,y);
	gotoxy(start_x,y+4);
	printf("별은 몇번(5~25 번) 반짝였을까요? ");
	srand((unsigned)time(NULL));
	game_count = (rand()%20)+5;
	for(tmp=0; tmp<game_count; tmp++){
		xx= (rand()%(x-2))+start_x+1;
		yy= (rand()%(y-2))+start_y+1;
		gotoxy(xx,yy);
		printf("★");
		Sleep(game_delay);
		gotoxy(xx,yy);
		printf(" ");
	}
	
	gotoxy(start_x+34,y+4);
	scanf("%d",&tmp); //정답 입력받음 
	if(tmp == game_count){
		gotoxy(start_x,y+5);
		printf("정답 입니다!");
		score += 50;
		game_delay -= 80;
		//life++; 
		Sleep(1000);
		print_score(score, life);
	}
	else{
		gotoxy(start_x,y+5);
		printf("오답 입니다!\n");
		gotoxy(start_x,y+6);
		printf("정답은 %d 입니다.",game_count);
		gotoxy(start_x,y+7);
		Sleep(1000);
		life--;
		score -= 5;
		print_score(score, life);
	}
	}
	
	if(life <= 0){
		size(&xx,&yy);
		system("CLS");
		gotoxy(xx/2-19,yy/2);
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		gotoxy(xx/2-19,yy/2+1);
		printf("          게임 오버\n",score);
		gotoxy(xx/2-19,yy/2+2); 
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		Sleep(2000);
	}
	return 0;
}
void draw(int sx,int sy,int x,int y){
	int tmp,tmpp;
	gotoxy(sx,sy);
	for(tmp=0; tmp<x; tmp++){
		printf("=");
	}
	
	for(tmp=0; tmp<y; tmp++){
		gotoxy(sx-1,(sy+1)+tmp);
		printf("|\n");
	}
	
	for(tmp=0; tmp<y; tmp++){
		gotoxy(sx+x,(sy+1)+tmp);
		printf("|\n");
	}
	
	gotoxy(sx,(sy+1)+y);
	for(tmp=0; tmp<x; tmp++){
		printf("=");
	}
	
}

void print_score(int score, int life){
	int xx,yy;
	size(&xx,&yy);
	xx -= 46;
	yy -= 1;
	system("CLS");
	gotoxy(xx/2,yy/2);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(xx/2,yy/2+1);
	printf("         점수: %5d 점\n",score);
	gotoxy(xx/2,yy/2+2);
	printf("         생명: %5d 개\n",life);
	gotoxy(xx/2,yy/2+3); 
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	Sleep(2000);
}
int gotoxy(int x,int y){
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

void size(int *x , int *y){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}



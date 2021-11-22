#include <unistd.h>
#include <curses.h>
#include <string.h>

int main(void){
  initscr();
  start_color(); 
  init_pair(1, COLOR_YELLOW,  COLOR_BLACK);
  attrset(COLOR_PAIR(1));
  curs_set(0); 
  int rand();
  char *beer_z = " |            |";
  char *blank1 =  " |            |";
  char *blank2 =  " |      |     |";
  char *blank3 =  " |          | |";
  char *blank4 =  " | |          |";

  char *glass_up= "                ";
  char *glass_mp= " |            | ";
  char *glass_dp= " |            ||";
  char *glass_z = " |            |｣";
  char *glass_bt= " |____________| ";

  int dir = +1;
  int pos = 45;

  int ground = 1;
  char *awa_up= " @@@@@@@@@@@@@@ ";
  char *awa_up2= " @@@@@@@@@@@@@@ ";
  char *awa_mp= " |@@@@@@@@@@@@| ";
  char *awa_mp2= "@@|@@@@@@@@@@@@|@@";
  char *awa_dp= " |____________||";
  char *awa_dp2= "@@@|            ||@@@";
  char *awa_dp3= "@@@@|            ||@@@@";
  char *awa_dp4= "@@@@@|            ||@@@@@";
  char *awa_z = " |____________|｣";
  char *awa_z2 = "@@@@@@|            |｣@@@@@@";
  char *awa_bt= " |____________| ";
  char *awa_bt2= "@@@@@@@|            |@@@@@@@@@@";

  char *afure1= "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  char *afure2= "                                                                           ";
  initscr();
  clear();

  while(1){
    if(ground<48){
    move(ground, pos);
    addstr(beer_z);
    }
    move(43, pos);
    if(ground==46){
	addstr(awa_up);
    }
    else if(ground>=47){
	    move(43, pos);
	    addstr(awa_up2);
    }
    else{
	addstr(glass_up);
    }

    move(44, pos);
    if(ground>=45 &&ground<48){
	addstr(awa_mp);
    }
    else if(ground>=48){
	    move(44, pos-1);
	    addstr(awa_mp2);
    }
    else{
	addstr(glass_mp);
    }

    move(45, pos);
    if(ground==44){
	addstr(awa_dp);
    }
    else if(ground>=49){
	    move(45, pos-2);
	    addstr(awa_dp2);
    }
    else{
	addstr(glass_dp);
    }

    move(46, pos);
    if(ground==43){
    	addstr(awa_dp);
    }
    else if(ground>=50){
	    move(46, pos-3);
	    addstr(awa_dp3);
    }
    else{
    	addstr(glass_dp);
    }

    move(47, pos);
    if(ground==42){
    	addstr(awa_dp);
    }
    else if(ground>=51){
	    move(47, pos-4);
	    addstr(awa_dp4);
    }
    else{
    	addstr(glass_dp);
    }

    move(48, pos);
    if(ground==41){
    	addstr(awa_z);
    }
    else if(ground>=52){
	    move(48, pos-5);
	    addstr(awa_z2);
    }
    else{
	addstr(glass_z);
    }

    move(49, pos);
    if(ground==40){
    	addstr(awa_bt);
    }
    else if(ground>=53){
	    move(49, pos-6);
	    addstr(awa_bt2);
    }
    else{
    	addstr(glass_bt);
    }
    refresh();

    if(ground >= 53)
      break;

    usleep(100000);
    if(ground>=1){
    move(rand()%ground+1, pos);
    addstr(blank1);
    move(rand()%ground+1, pos);
    addstr(blank2);
    move(rand()%ground+1, pos);
    addstr(blank3);
    move(rand()%ground+1, pos);
    addstr(blank4);
    }
    ground += dir;
  }
  ground=56;
    while(1){
	move(ground, 0);
	addstr(afure1);
	move(ground, 45);
	addstr(afure1);
	move(ground+1, 0);
	addstr(afure2);
	move(ground+1, 45);
	addstr(afure2);
	
	ground-=dir;
	if(ground==0){
		break;
	}
	refresh();
    	usleep(80000);
    }
  endwin();
}


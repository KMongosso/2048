#include "direction.hh"

void up(nombres_t ** screen){
	int temp,max;

	for(int j=1;j<4;j++){
		max=10;
		for(int i=0;i<4;i++){
			if(screen[i][j].val!=0){
				temp=j;
				while(temp!=0 && screen[i][temp-1].val==0){
					screen[i][temp-1].val=screen[i][temp].val;
					screen[i][temp].val=0;
					temp--;
				}

				if(temp!=0 && max!=temp-1 && screen[i][temp].val==screen[i][temp-1].val){
					screen[i][temp-1].val=screen[i][temp].val+screen[i][temp-1].val;
					screen[i][temp].val=0;
					max=temp;
				}
					
			}
		}
	}

	
}

void left(nombres_t ** screen){
	int temp,max;

	for(int j=0;j<4;j++){
		for(int i=1;i<4;i++){
			max=10;
			if(screen[i][j].val!=0){
				temp=i;
				while(temp!=0 && screen[temp-1][j].val==0){
					screen[temp-1][j].val=screen[temp][j].val;
					screen[temp][j].val=0;
					temp--;
				}

				if(temp!=0 && max!=temp-1 && screen[temp][j].val==screen[temp-1][j].val){
					screen[temp-1][j].val=screen[temp][j].val+screen[temp-1][j].val;
					screen[temp][j].val=0;
					max=temp;
				}
					
			}
		}
	}

	
}

void right(nombres_t ** screen){
	int temp,max;

	for(int j=0;j<4;j++){
		for(int i=2;i>=0;i--){
			max=10;
			if(screen[i][j].val!=0){
				temp=i;
				while(temp!=3 && screen[temp+1][j].val==0){
					screen[temp+1][j].val=screen[temp][j].val;
					screen[temp][j].val=0;
					temp++;
				}

				if(temp!=3 && max!=temp+1 && screen[temp][j].val==screen[temp+1][j].val){
					screen[temp+1][j].val=screen[temp][j].val+screen[temp+1][j].val;
					screen[temp][j].val=0;
					max=temp;
				}
					
			}
		}
	}

	
}

void down(nombres_t ** screen){
	int temp,max;
	
	for(int j=2;j>=0;j--){
		max=10;
		for(int i=0;i<4;i++){
			if(screen[i][j].val!=0){
				temp=j;
				while(temp!=3 && screen[i][temp+1].val==0){
					screen[i][temp+1].val=screen[i][temp].val;
					screen[i][temp].val=0;
					temp++;
				}

				if(temp!=3 && max!=temp+1 && screen[i][temp].val==screen[i][temp+1].val){
					screen[i][temp+1].val=screen[i][temp].val+screen[i][temp+1].val;
					screen[i][temp].val=0;
					max=temp;
				}
					
			}
		}
	}	

	
}


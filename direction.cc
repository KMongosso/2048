#include "direction.hh"

void up(int ** screen){
	int temp,max;

	for(int j=1;j<4;j++){
		max=10;
		for(int i=0;i<4;i++){
			if(screen[i][j]!=0){
				temp=j;
				while(temp!=0 && screen[i][temp-1]==0){
					screen[i][temp-1]=screen[i][temp];
					screen[i][temp]=0;
					temp--;
				}

				if(temp!=0 && max!=temp-1 && screen[i][temp]==screen[i][temp-1]){
					screen[i][temp-1]=screen[i][temp]+screen[i][temp-1];
					screen[i][temp]=0;
					max=temp;
				}
					
			}
		}
	}

	
}

void left(int ** screen){
	int temp,max;

	for(int j=0;j<4;j++){
		for(int i=1;i<4;i++){
			max=10;
			if(screen[i][j]!=0){
				temp=i;
				while(temp!=0 && screen[temp-1][j]==0){
					screen[temp-1][j]=screen[temp][j];
					screen[temp][j]=0;
					temp--;
				}

				if(temp!=0 && max!=temp-1 && screen[temp][j]==screen[temp-1][j]){
					screen[temp-1][j]=screen[temp][j]+screen[temp-1][j];
					screen[temp][j]=0;
					max=temp;
				}
					
			}
		}
	}

	
}

void right(int ** screen){
	int temp,max;

	for(int j=0;j<4;j++){
		for(int i=2;i>=0;i--){
			max=10;
			if(screen[i][j]!=0){
				temp=i;
				while(temp!=3 && screen[temp+1][j]==0){
					screen[temp+1][j]=screen[temp][j];
					screen[temp][j]=0;
					temp++;
				}

				if(temp!=3 && max!=temp+1 && screen[temp][j]==screen[temp+1][j]){
					screen[temp+1][j]=screen[temp][j]+screen[temp+1][j];
					screen[temp][j]=0;
					max=temp;
				}
					
			}
		}
	}

	
}

void down(int ** screen){
	int temp,max;
	
	for(int j=2;j>=0;j--){
		max=10;
		for(int i=0;i<4;i++){
			if(screen[i][j]!=0){
				temp=j;
				while(temp!=3 && screen[i][temp+1]==0){
					screen[i][temp+1]=screen[i][temp];
					screen[i][temp]=0;
					temp++;
				}

				if(temp!=3 && max!=temp+1 && screen[i][temp]==screen[i][temp+1]){
					screen[i][temp+1]=screen[i][temp]+screen[i][temp+1];
					screen[i][temp]=0;
					max=temp;
				}
					
			}
		}
	}	

	
}


/*
两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。判断比赛名单。
*/
#include <stdio.h>
int main(){
	int i,j,k; //a,b,c
	for(i='X';i<='Z';i++){
		for(j='X';j<='Z';j++){
			for(k='X';k<='Z';k++){
				if(i=='X'||j==i||k=='X'||k=='Z'||j==k||i==k){
					continue;
				}
				printf("A对%c,B对%c,C对%c",i,j,k);
			}
		}
	}
	
 
	return 0;
}

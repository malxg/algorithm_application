/*
����ƹ����ӽ��б������������ˡ��׶�Ϊa,b,c���ˣ��Ҷ�Ϊx,y,z���ˡ��жϱ���������
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
				printf("A��%c,B��%c,C��%c",i,j,k);
			}
		}
	}
	
 
	return 0;
}

#include <cstdio>

int main(){
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int col, row;
	col = n;
	if(col % 2 == 1)//jishu
	{
		row = (col +1 )/2; 
	}else{
		row = col / 2;
	}
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			if(i == 0 || i == row - 1){
				printf("%c", c);
			}
			else {
				if(j == 0 || j == col - 1) printf("%c", c);
				else printf(" ");
			}
			if(i < row - 1 && j == col - 1) printf("\n");
			
		}
	}
	return 0;
}
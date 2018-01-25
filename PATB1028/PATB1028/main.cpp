#include <cstdio>
#include <string.h>

class person {
public:
	char name[10];
	int yy, mm, dd;

	person(){
		strcpy(name," ");
		yy = 0;
		mm = 0;
		dd = 0;
	}

	void init(char n[10], int y, int m, int d){
		strcpy(name, n);
		yy = y;
		mm = m;
		dd = d;
	}
	void operator = (person b){
		strcpy(name, b.name);
		yy = b.yy;
		mm = b.mm;
		dd = b.dd;
	}
	bool lessEqual(person b){//num less
	if(yy != b.yy) return yy <= b.yy;
	else if(mm != b.mm)  return mm <= b.mm;
	else return dd <= b.dd;
}

	bool moreEqual( person b){//num more
	if(yy != b.yy) return yy >= b.yy;
	else if(mm != b.mm)  return mm >= b.mm;
	else return dd >= b.dd;
	}
};
//oldest最老的人yest最年轻的人。左右边界



int main(){
	int n, count =0;
	person oldest, youngest, left, right, temp;
	scanf("%d", &n);
	left.init("n", 1814, 9, 6);
	right.init("n", 2014, 9, 6);
	youngest.init("n", 1814, 9, 6);
	oldest.init("n", 2014, 9, 6);

	for(int i = 0; i < n; i ++){
		scanf("%s %d/%d/%d", &temp.name, &temp.yy, &temp.mm, &temp.dd);
		if( right.moreEqual(temp)&& left.lessEqual( temp )){
			count ++;
			if(temp.lessEqual( oldest)){
				oldest = temp;
			}
			if(temp.moreEqual( youngest)){
				youngest = temp;
			}
		}
	}
	if(count == 0) printf("0\n");
	else printf("%d %s %s\n", count, oldest.name, youngest.name);
	return 0;
}
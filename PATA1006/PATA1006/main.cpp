#include <cstdio>

struct pNode{
	char id[20];
	int hh, mm, ss;
};
pNode temp, ans1, ans2;
bool great(pNode a, pNode b){
	if(a.hh != b.hh) return a.hh > b.hh;
	if(a.mm != b.mm) return a.mm > b.mm;
	return a.ss > b.ss;
}
int main(){
	int n;
	scanf("%d", &n);
	ans1.hh = 24, ans1.mm = 60, ans1.ss = 60;
	ans2.hh = 0, ans2.mm = 0, ans2.ss = 0;
	for(int i = 0; i < n; i ++){
		scanf("%s %d:%d:%d", &temp.id, &temp.hh, &temp.mm,&temp.ss);
		if(great(temp, ans1) == false) ans1 = temp;
		scanf("%d:%d:%d",&temp.hh, &temp.mm, &temp.ss);
		if(great(temp, ans2) == true) ans2 = temp;//Ô½À´Ô½³Ù
	}
	printf("%s %s", ans1.id, ans2.id);
	return 0;
}
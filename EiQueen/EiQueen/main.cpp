#include <cstdio>
#include <algorithm>

const int maxn = 1010;
int P[maxn];//��i�лʺ���к�
bool ht[maxn] = {false};//��x�з���û
int cnt = 0;
int n = 8;
void gP(int index){
	if(index == n + 1){
		cnt ++;
		return;
	}
	for(int x = 1; x <= n; x ++){
		//x�ǻ�û�� ׼����һ��
		if(ht[x] == false){
			bool flag = true;//�ܲ��ܷ���
			for(int pre = 1; pre < index; pre ++){
				if(abs(index - pre) == abs(x - P[pre])){
					//index,pre�����к� x,P[pre]�����к�
					//GG ���x�Ų�����
					flag = false;
					break;
				}
			}//������
			if(flag){
					P[index] = x;
					ht[x] = true;
					gP(index + 1);
					ht[x] = false;
				}
		}
	}
}
int main(){

	gP(1);
	printf("%d", cnt);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int s[n]={0};// s[i]:�Ե�i������β������Ӷκ�
	int flag=0;// ��¼�����ĸ����� 
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<0) flag++;
	}
	 
	if(flag==n) cout<<0;//��������������Ϊ����ʱ�������Ӷκ�Ϊ0��
	else{
		s[0]=a[0];
		for(int i=1;i<n;i++){
			if(s[i-1]<=0) s[i]=a[i];
			else s[i]=s[i-1]+a[i];
		}
	int max=s[0];
	for(int i=0;i<n;i++){
		if(max<s[i]) max=s[i];
		
	}
	cout<<max;	
			
	}
	
	
}


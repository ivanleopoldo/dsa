#include <stdio.h>

int insert(int set, int data);
void show(int set);
int check(int set, int data);
int removenum(int set, int data);
int intersection(int set1, int set2);
int setunion(int set1, int set2);

void main(){
	unsigned int x = 0, b = 0;
	int y[5] = {1, 2, 5, 5, 7};
	int l[5] = {1, 5, 7, 8, 9};
	int z;
	
	for(z = 0; z<5; z++){
		x = insert(x, y[z]);
		b = insert(b, l[z]);	
	}
	show(x);
	x = removenum(x, 5);
	show(x);
}

int insert(int set, int data){
	return set | (1<<data);
}

void show(int set){
	int x = set, y;
	for(y=0;y<32;y++){
		if(x%2==0){
			printf("0");
		} else {
			printf("1");
		}
		x = x>>1;
	}
	printf("\n");
}

int check(int set, int data){
	int temp = set;
	temp ^= (1<<data);
	if(temp<set){
		return 1;
	} else {
		return 0;
	}
}

int removenum(int set, int data){
	return set & ~(1<<data);
}

int intersection(int set1, int set2){
	return set1 & set2;
}

int setunion(int set1, int set2){
	return set1 | set2;
}



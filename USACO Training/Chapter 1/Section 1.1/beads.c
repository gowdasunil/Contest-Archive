/*
    ID: frceped1
    LANG: C
    TASK: beads
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("beads.in", "r", stdin); freopen("beads.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXBEADS 350

char beads[MAXBEADS*2];
int beadNum;

int main(void){
	int i;
	openFiles();
	scanf("%d", &beadNum);
	for (i = 0; i < beadNum; i++){
		do {
			scanf("%c", &beads[i]);
		} while (beads[i] != 'w' && beads[i] != 'b' && beads[i] != 'r');
		beads[i+beadNum] = beads[i];
	}
	int max = 0;
	for (i = beadNum / 2 - 1; i <= beadNum + beadNum / 2; i++){
		int j = i;
		int new = 0;
		char curr = beads[j];
		int loops = 0;
		if (beads[j] == 'w'){
			while (j >= 0 && i - j < beadNum && (curr = beads[j]) == 'w')
				j--;
		}
		for (j = i; j >= 0 && i - j < beadNum; j--){
			if (curr == beads[j] || beads[j] == 'w') new++, loops++;
			else break;
		}
		curr = beads[i+1];
		j = i + 1;
		if (curr == 'w'){
			while (j < beadNum * 2 && j - i - (beadNum % 2 || !(loops % 2) ? 0 : 1) <= beadNum - loops && (curr = beads[j]) == 'w')
				j++;
		}
		for (j = i+1; j < beadNum * 2 && j - i - (beadNum % 2 || !(loops % 2) ? 0 : 1) <= beadNum - loops; j++){
			if (curr == beads[j] || beads[j] == 'w') new++;
			else break;
		}
		if (new > max) max = new;
	}
	printf("%d\n", max);
	return 0;
}


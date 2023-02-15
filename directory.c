#include<sys/types.h>
#include<stdio.h>
#include<dirent.h>

void printingDirectory(char *path){
	DIR *new;
	struct dirent *current;
	new = opendir(path);
	if(new==NULL) {
		printf("There is no such directory\n");
	}
	else {
		while((current = readdir(new))!=NULL) {
			if(current->d_name[0]!='.') {
				printf("%s\n", current->d_name);
			}
		}
	}
	closedir(new);
	return;
}
int main() {
	printingDirectory("/");
	return 0;
}

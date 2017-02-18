#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

char restaurant_array[100][100];
int exist_file = 1;

int readRestaurant(){
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	
	fp = fopen("restaurant.txt","r+");
	if (fp == NULL){
        fp = fopen("restaurant.txt" ,"a");
        exist_file = 0;
	}
	else{
		int i = 0;
		while ((read = getline(&line, &len, fp)) != -1) {
					strcpy(restaurant_array[i],line);
				 	printf("Retrieved line of length %zu :\n", read);
				  	printf("%s", line);
					i += 1;
		}
	}
	fclose(fp);

	return 0;
}
int ra_length(){
	int i;
	int result = 0;
	for( i = 0; i < 100; i++){
		if(strcmp(restaurant_array[i], "") != 0){
			result += 1;
		}
	}
	return result;
}
int add_restaurant(char rest_name[100]){
	int i;
	for(i = 0; i < 100; i++){
		if(strcmp(restaurant_array[i],"") == 0){
			strcpy(restaurant_array[i], rest_name);
			printf("You add %s succefully!\n", rest_name);
			break;
		}
	}
	return 0;
}


int show_restaurant(){
	int i;
	//printf("%lu\n", sizeof(&restaurant_array));
	for(i = 0; i < 100; i++){
		if(strcmp(restaurant_array[i], "") != 0){
			printf("%s\n", restaurant_array[i]);
		}
	}
	return 0;
}

int random_restaurant(){
	int size = ra_length();
	printf("the length is %d\n", size);
	srand(time(NULL));
	int r = rand() % size;
	printf("random number is %d\n", r);
	printf("today our choice is  %s \n", restaurant_array[r]);
	sleep(2);
	return 0;
}

int main(){

	const int k = 1;
	
	char name[50];
	printf("Hello, I am the restaurant random choicer, what's your name? :D \n");
	scanf("%s",name);

	readRestaurant();
	if(exist_file == 0){
		printf("Hello %s ! You have no restaurant now, would you like to add a restaurant?\n1.Yes\n2.No\n", name);
		char add_restaurant_choice[1];
		scanf("%s",add_restaurant_choice);
		int num_add_restaurant_choice =  atoi(add_restaurant_choice);
		if(num_add_restaurant_choice == 1){
			printf("please enter the restaurant:\n");
			char restaurant_name[100];
			scanf("%s",restaurant_name);
			add_restaurant(restaurant_name);
		}
		else{
			printf("R.I.P\n");
		}
		
		exist_file = 1;
	}
	else{
		printf("Hello %s! What would you want today?\n1.just random a restaurant for me\n2.show me all the restaurant\n3.add a restaurant\n",name);
		char choice[1];
		scanf("%s",choice);
		int num_choice =  atoi(choice);


		if(num_choice == 1){
			random_restaurant();
		}
		else if(num_choice == 2){
			show_restaurant();
		}
		else if(num_choice == 3){
			char new_restuarant[100];
			printf("%s\n", "please enter a new restaurant:");
			scanf("%s", new_restuarant);
			add_restaurant(new_restuarant);
		}
	}

	while(k){
		printf("What would you want again?\n1.just random a restaurant for me\n2.show me all the restaurant\n3.add a restaurant\n");
		char choice[1];
		scanf("%s",choice);
		int num_choice =  atoi(choice);
		if(num_choice == 1){
			random_restaurant();
		}
		else if(num_choice == 2){
			show_restaurant();
		}
		else if(num_choice == 3){
			char new_restuarant[100];
			printf("%s\n", "please enter a new restaurant:");
			scanf("%s", new_restuarant);
			add_restaurant(new_restuarant);
		}
		sleep(2);
	}
}

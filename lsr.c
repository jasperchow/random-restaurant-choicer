#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

char restaurant_array[100][100];

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

// int file_exist (char *filename)
// {
//   struct stat   buffer;   
//   return (stat (filename, &buffer) == 0);
// }

int show_restaurant(){
	int i;
	printf("%lu\n", sizeof(&restaurant_array));
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
	strcpy(restaurant_array[0],"碳烤居");
	strcpy(restaurant_array[1],"新香港");
	strcpy(restaurant_array[2],"云南米线");
	strcpy(restaurant_array[3],"九龙");
	strcpy(restaurant_array[4],"新香港");
	strcpy(restaurant_array[5],"得装");
	strcpy(restaurant_array[6],"缘味米线");
	strcpy(restaurant_array[7],"kinton拉面");
	strcpy(restaurant_array[8],"charadise");
	strcpy(restaurant_array[9],"嘿小面");

	char name[50];
	printf("Hello, I am the restaurant random choicer, what's your name? :D \n");
	scanf("%s",name);
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

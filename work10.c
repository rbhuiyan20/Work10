#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct penguin {
	char *name; 
	double weight;
	struct penguin *next; // pointer to next node
};

void print_penguin(struct penguin *p){
	// prints penguins
	printf("Penguin named %s weighs: %.2f \n",p->name, p->weight);
}

struct penguin * make_penguin(char* c, double i){
	// makes a struct f
	struct penguin *f;
	// allocates memory
	f = malloc(sizeof(struct penguin));
	
	// sets the name and weight of the penguin to the paremeter values
	f->name = c;
	f->weight =i;
	return f;
}

// takes a pointer to node struct and prints all of the data
void print_list(struct penguin *z){
	while(z){
		//prints whats at the head
		print_penguin(z);
		printf("\n");
		//goes to next penguin in the list
		z = z->next;
	}
}

//takes pointer to already existing list and puts penguin at the front
struct penguin * insert_front(struct penguin *f, char *name, double weight){
	struct penguin *z = make_penguin(name,weight);
	// next element in list is f (parameter). 
	z->next = f;
	// f is now in front
	return z;	
}

// takes pointer to list as parameter
struct penguin * free_list(struct penguin *z){
	
	struct penguin *front;
	// while linked list isnt empty
	while (z){
		// copies the next elements into front, removes the tail of z, and then puts back the copied elements till we get to the head
		front = z->next;
		free(z);
		z = front;
	}
	// returns pointer to the beginning of the list
	return front;
}

int main(){
	srand(time(NULL));
	// (rand() % 11) + 30 makes random numbers between 30 and 40
    double weight = (rand() % 11) + 30 ;
    struct penguin *line = make_penguin("Amir", weight);
	printf("---------------------------Just amir:\n");
	printf("\n");
	print_list(line);
	
	
	
    weight = (rand() % 11) + 30 ;
    line = insert_front(line,"Rohan", weight);
	printf("---------------------------Amir with Rohan on line:\n");
	printf("\n");
	print_list(line);
	
	
    weight = (rand() % 11) + 30 ;
    line = insert_front(line,"Ehsan", weight);
	printf("---------------------------All 3 penguins in the list:\n");
    print_list(line);
	printf("\n");
    free(line);
    return 0;
	
	
	
}



/* Implementation of trie data_structure in C*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

void readLine(char *buff, int size) {
		if(fgets(buff, size, stdin) == NULL)
			buff[0] = 0;

		buff = strrchr(buff, '\n');
		if(buff != NULL)
			*buff = 0;
}

int main(int argc, char const *argv[]) {
		trie *head = create_trie();
		char word[16];
		int c;
		while(1)
		{
				printf("1_Insert a node\n");
				printf("2_Search a node\n");
				printf("3_Delete a node\n");
				printf("4_View the trie\n");
				printf("5_Exit\n");
				readLine(word, sizeof word);
				c = atoi(word);

				if(c > 0 && c < 4)
				{
					printf("Word?\n");
					readLine(word, sizeof word);
				}

				switch  (c)
				{
				case (1):
				{
						insertNode(head,word);
						break;
				}
				case (2):
				{
						search(head,word)!=NULL ? printf("%s found\n",word) : printf("Not found\n");
						break;
				}
				case (3):
				{
						delete(head,word);
						break;
				}
				case (4):
				{
						printAllWords(head,word,0);
						break;
				}
				case (5):
						return 0;
				default:
						printf("Enter valid choice\n");
				}
		}
		return 0;
}

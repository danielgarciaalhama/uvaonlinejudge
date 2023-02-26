/*
When we are facing a problem represented by trees, the first approach usually is implementing a tree structure. This problem could be resolved using that approach, but creating the objects and accessing to the data could be more expensive than needed. 

To resolve this problem we have, for each tree, the leafs, the cases (m and the vva) and the order to process the cases (x1,x2 ..xn). For each case we only have to calculate the index of the leaf that will be the result.

Check the comments into the source code for more info.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {


	int n, m, index, indexIncrement,treeNumber = 1;
	string aux, terminalNodes;
	
	/* We'll use aux as an auxiliar variable twice:
	 -For reading the variables (x1,x2...xn)
	 -For reading and process the vvas
	 For the purpose of the code this is fine, but in real life situations we must avoid using this kind of names,
	 and this kind of reuses. It could generate some misunderstandings.
	*/
	
	
	cin >> n;
	while (n != 0) {
		
		cout << "S-Tree #" << treeNumber++ << ":" << endl;


		/* Process the variables order (x1, x2...xn). We can just ignore the first char (x). With this vector we
		will know the order to process the items into the vvas:*/
		vector <int> order(n);
		for (int i = 0; i < n; i++) {
			cin >> aux;
			order[i] = int((aux[1] - '0') - 1);		
		}
	
	
		cin >> terminalNodes >> m;
		
		// Process the m vva
		for (; m > 0; --m) {

			cin >> aux;

			/* We start calculating the index pointing it to the "middle" of the leafs (since the number of leafs
			will be always pair, there will be no middle leaf). The increment (or decrement) of the index in each iteration
			will be the half of the index (we are going down to the tree, always pointing to the next node with index).
			This calculation is done using the shift command.
			It can also be done as --> index=n/2; indexIncrement=index/2; 
			or --> index=n*0.5; indexIncrement=index*0.5;
			But usually shift command is faster than that. */
			index = 1<<(n-1);
			indexIncrement = index >> 1;

			for (int i = 0; i < n-1; i++) {
				/*We process each digit of the vva (except last, special case). 
				It will increase or decrease the index (going right or left)*/
				index += (aux[order[i]] == '1' ? indexIncrement : 0-indexIncrement);	
				indexIncrement >>= 1;
			}
			
			/* For the last vva we only have to decrease the index in case is 0 (index is pointing to the leaf
			into the right*/
			if (aux[order[n-1]] == '0') --index;

			/*We just have to print the valid leaf, without use any kind of tree structure:*/
			cout << terminalNodes[index];
		}	
		cout << endl << endl;
		cin >> n;
	}

}



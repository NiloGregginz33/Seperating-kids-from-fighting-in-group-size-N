#include <iostream>  
#include <algorithm>
#include <cmath>
#include <array>
#include <map>

using namespace std;

//Original Print function for end code
void print_arr(int arr[], int num){
for (int z = 0; z < num; z++){
cout << "(" << arr[z] << ")";
}
}
void arrange(int arr2[], int num, int arr3[]){
	int a;
	int b;
	int d;
	for (int w = 1; w < num+1; w++){
	a = arr2[w-1];
	b = arr2[w+1];
	d = a*b;
	arr3[w-1]=d;
}
}
void Mapcreation(map<int, unsigned long long> &temp_map, int cap);
void Mapdeclaration (int cap){
	map<int, unsigned long long>  my_map;
	Mapcreation(my_map, cap);
}
void Mapcreation(map<int, unsigned long long> &temp_map, int cap){
	for(int w = 0; w < cap+1; w++){
		temp_map.insert(pair<int, unsigned long long>(w, 1));
	}
}
int check(map<int, unsigned long long> &temp_map,int arr[],  int arr3[], int num, int cap, int total)
{
	int checc = 0;
	int a;
	int b;
	int c;
	for(int w = 0; w < num; w++){
		a = arr3[w];
		b = arr[w];
		if (temp_map[a]%b != 0){
		checc++;
	}
		else {
			break;
		}
}
		if (checc == num){
			total++;
			cout << "Solution";
			cout << ": ";
			for (int z = 0; z < num; z++){
			c = arr3[z];
			temp_map[c]=arr[z]*temp_map[c];	
		}
		print_arr(arr, num);
		cout << endl;
	}
	checc = 0;
	return total;
			}
			
int main (){
int num;
int count;
int cap;
int black;
int y = 0;
cout << "Input for permutations:";
cin >> num;
int numb;
int i;
int total = 0;
numb = num + 2;
map<int, unsigned long long> my_map;
//Creating an array of that size with prime elements 
int arr[num]{};
	for(int z = 1;z<=100;z++){		 
        count = 0;
        for(i=2;i<=z/2;i++){
            if(z%i==0){
                count++;
                break;
            }
        }
        while (count==0 && z!= 1 && y < num+1){
        	if (y != num+1){
        		arr[y]=z;
        		y++;
        }
        	else{
        		
        		black = z;
		}
        		break;
		}
	}
		sort (arr,arr+num);
cout << "The " << "possible permutations with "<< num << " prime elements" << endl;
//create map cap
cap = arr[num-1]*arr[num-2];
cout << "cap: " << arr[num-1]*arr[num-2] << endl;
//create base map 
Mapcreation(my_map, cap);
//reduce possible computations
int arr2[numb]{};
int arr3[numb]{};
do {
	//adds 1's to either side of original array for a previous function to produce sensible numbers
	for (int e = 0; e < num; e++){
		arr2[e+1]=arr[e];
		arr2[num+1]=1;
		arr2[0]=1;
}
	arrange(arr2, num, arr3);
	check(my_map, arr, arr3, num, cap, total);
}
while (next_permutation(arr,arr+num));


return 0;
}















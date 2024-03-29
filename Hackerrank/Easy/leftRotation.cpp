/*

Arrays: Left Rotation

A left rotation operation on an array shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed 
on array [1, 2, 3, 4, 5], then the array would become [3, 4, 5, 1, 2].

Given an array a of n integers and a number, d, perform d left rotations on the array. Return the updated array to be printed as a single line 
of space-separated integers.

*/

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> aux;

    for(unsigned int i = (d % a.size()); i < a.size(); i++){
        aux.push_back(a[i]);
    }

    for(unsigned int i = 0; i < (d % a.size()); i++){
        aux.push_back(a[i]);
    }

    return aux;
}

int hourglassSum(vector<vector<int>> arr) {
    priority_queue<int> hourglass;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            hourglass.push(arr[i][j] + arr[i][j+1] + arr[i][j+2]
                                         + arr[i+1][j+1] +
                               arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]); 
        }
    }

    return hourglass.top();
}

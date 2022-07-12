// void countSort(vector<int> &array){
//     // int max = *max_element(array.begin(), array.end());
//     // int min = *min_element(array.begin(), array.end());
//     int max=0,min=1000000001;
//     for(int i=0;i<array.size();i++){
//         if(array[i]>max) max=array[i];
//         if(array[i]<min) min=array[i];
//     }
//     int range = max-min + 1;

//     vector<int> count(range), output(array.size());

//     for (int i=0;i<array.size();i++){
//         count[array[i]-min]++;
//     }
  
//     for (int i=1;i<count.size();i++){
//         count[i] += count[i-1];
//     }
  
//     for (int i=array.size()-1;i>=0;i--){
//         int pos=count[array[i]-min]-1;
//         output[pos] = array[i];
//         count[array[i]-min]--;
//     }
  
//     for (int i=0;i<array.size();i++){
//         array[i] = output[i];
//     }
// }
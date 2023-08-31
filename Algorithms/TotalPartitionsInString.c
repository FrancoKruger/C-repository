int partitionString(char * s){
int arr[26] = {0};
int start = 0;
int count = 1;
for(int i=0; s[i] != '\0'; i++){
    for(int j = start; j < i; j++){
        if(s[j] == s[i]){
            count++;
            start = i;
        }
    }
}
return count;
}

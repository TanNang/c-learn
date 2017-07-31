// 冒泡排序
void bubble_sort(int *arr, int len){
    for(int i=0; i<len-1; i++){
        int sorted = 1;
        for(int j=0; j<len-1-i; j++){
            if(arr[j] > arr[j+1]){
                sorted = 0;
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if(sorted){
            break;
        }
    }
}

// 选择排序
void select_sort(int *arr, int len){
    for(int i=0; i<len-1; i++){
        int min_index = i;
        for(int j=i+1; j<len; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            int tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}

// 插入排序
void insert_sort(int *arr, int len){
    for(int i=1; i<len; i++){
        int j = 0;
        while(arr[j] < arr[i] && j < i){
            j++;
        }
        if(j != i){
            int tmp = arr[i];
            for(int k=i; k>j; k--){
                arr[k] = arr[k-1];
            }
            arr[j] = tmp;
        }
    }
}
